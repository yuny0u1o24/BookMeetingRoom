#include <iostream>
#include "OAAdmin.h"
#include "OADataCenter.h"


OAAdmin::OAAdmin()
{
}

OAAdmin::OAAdmin(string username, string password)
{
	_username = username;
	_password = password;
}

string OAAdmin::username()
{
	return _username;
}

bool OAAdmin::addUser(string username, string password, string department)
{
	return OADataCenter::getInstance().addUser(username, password, department);
}

bool OAAdmin::deleteUser(string username)
{
	return OADataCenter::getInstance().deleteUser(username);
}

void OAAdmin::showAllUsers()
{
	vector<OAUser>users = OADataCenter::getInstance().getUsers();
	system("cls");
	for (OAUser& u : users)
	{
		cout << "用户名: " << u.username() << " 部门: " << u.department() << endl;
	}
}


bool OAAdmin::addMeetingRoom(int mid, int capacity)
{
	return OADataCenter::getInstance().addMeetingRoom(mid, capacity);
}

bool OAAdmin::deleteMeeintRoom(int mid)
{
	return OADataCenter::getInstance().deleteMeetingRoom(mid);
}

void OAAdmin::clearMeeingRoomStatus()
{
	OADataCenter::getInstance().clearRoomStatus();
}

void OAAdmin::showAllMetingRooms()
{
	// 获取到所有的会议室
	vector<OAMeetingRoom> rooms = OADataCenter::getInstance().getRooms();
	// 遍历每一个会议室
	for (OAMeetingRoom& m : rooms)
	{
		cout << "会议室编号: " << m.mid() << ", 容量: " << m.capacity();
		if ((m.user()) == &(OAUser::ERROR_USER))
		{
			cout << "可预订." << endl;
		}
		else
		{
			cout << ", 这个会议室已经被" << m.user()->department() << "的" << m.user()->username() << "占用了" << endl;
		}
	}
}

OAAdmin OAAdmin::ERROR_ADMIN = OAAdmin(); // 错误用户
