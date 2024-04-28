#include "OADataCenter.h"
#include "OAUtils.h"

OADataCenter OADataCenter::_instance = OADataCenter();

OADataCenter::OADataCenter()
{
	admins.push_back(OAAdmin("admin", "admin"));
	users.push_back(OAUser("张三", "123123", "行政部"));
	users.push_back(OAUser("李四", "123456", "人力资源"));

	rooms.push_back(OAMeetingRoom(1, 10));
	rooms.push_back(OAMeetingRoom(2, 6));
	rooms.push_back(OAMeetingRoom(3, 4));

	OAUser* user = new OAUser("yunyou","123456", "abc");
	OAMeetingRoom r(4, 12);
	r._user = user;
	rooms.push_back(r);
}

OADataCenter& OADataCenter::getInstance()
{
	return _instance;
}

OAAdmin& OADataCenter::loginAdmin(string username, string password)
{
	for (OAAdmin& admin : admins)
	{
		if (admin._username == username && admin._password == password)
		{
			return admin;
		}
	}
	return OAAdmin::ERROR_ADMIN;
}

OAUser& OADataCenter::loginUser(string username, string password)
{
	for (OAUser& user : users)
	{
		if (user._username == username && user._password == password)
		{
			return user;
		}
	}
	return OAUser::ERROR_USER;
}

bool OADataCenter::addUser(string username, string password, string department)
{
	// 检查用户是否存在
	for (OAUser& user : users)
	{
		if (user._username == username)
		{
			return false;
		}
	}
	// 添加用户
	users.push_back(OAUser(username, password, department));


	return true;
}

bool OADataCenter::deleteUser(string username)
{
	auto it = users.begin();
	for (; it != users.end(); it++)
	{
		if (it->username() == username)
		{
			break;
		}
	}
	// 判断是否找到了用户
	if (it == users.end())
	{
		return false; // 没有找到
	}
	users.erase(it);
	return true;
}

bool OADataCenter::addMeetingRoom(int mid, int capacity)
{
	// 检查会议室是否存在
	for (OAMeetingRoom& room : rooms)
	{
		if (room._mid == mid)
		{
			return false;
		}
		rooms.push_back(OAMeetingRoom(mid, capacity));
		return true;
	}
}

bool OADataCenter::deleteMeetingRoom(int mid)
{
	vector<OAMeetingRoom>::iterator it = rooms.begin();
	for (; it != rooms.end(); it++)
	{
		if (it->_mid == mid)
		{
			break;
		}
	}

	if (it == rooms.end())
	{
		return false;
	}
	// 存在
	rooms.erase(it);
	return true;
}

void OADataCenter::clearRoomStatus()
{
	for (OAMeetingRoom& room : rooms)
	{
		room._user = &OAUser::ERROR_USER;
	}
}

vector<OAUser> OADataCenter::getUsers()
{
	vector<OAUser> users_bak(users);
	return users_bak;
}

vector<OAMeetingRoom> OADataCenter::getRooms()
{
	return vector<OAMeetingRoom>(rooms);
}

int OADataCenter::bookMeetingRoom(OAUser& user, int mid)
{
	// 通过mid找到指定的会议室
	auto it = rooms.begin();
	for (; it != rooms.end(); it++)
	{
		if (it->_mid == mid)
		{
			break;
		}
	}
	// 判断会议室是否存在
	if (it == rooms.end())
	{
		return MEETING_ROOM_NOT_FOUND;
	}

	// 判断会议室是否已经被预定了
	if (it->_user != &OAUser::ERROR_USER)
	{
		return MEETING_ROOM_BOOKED;
	}

	// 预定会议室
	it->_user = &user;
	return BOOK_SUCCESS;

}

int OADataCenter::cancelBookMeetingRoom(OAUser& user, int mid)
{
	// 找会议室
	// 通过mid找到指定的会议室
	auto it = rooms.begin();
	for (; it != rooms.end(); it++)
	{
		if (it->_mid == mid)
		{
			break;
		}
	}
	// 判断会议室是否存在
	if (it == rooms.end())
	{
		return CANCEL_MEETING_NOT_FOUNT;
	}


	// 判断这个会议室是否是当前用户所预定的
	if (it->_user != &user)
	{
		return CANCEL_MEETING_FAIL;
	}
	// 取消预定
	it->_user = &(OAUser::ERROR_USER);

	return CANCEL_MEETING_SUCCESS;
}