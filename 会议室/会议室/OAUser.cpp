#include "OAUser.h"
#include <iostream>
using namespace std;

OAUser OAUser::ERROR_USER = OAUser();


OAUser::OAUser()
{
}

OAUser::OAUser(string username, string password, string department)
{
	_username = username;
	_password = password;
	_department = department;
}

string OAUser::username()
{
	return _username;
}

string OAUser::department()
{
	return _department;
}

int OAUser::bookMeetingRoom(int mid)
{
	return OADataCenter::getInstance().bookMeetingRoom(*this, mid);
}

int OAUser::cancelBookMeetingRoom(int mid)
{
	return OADataCenter::getInstance().cancelBookMeetingRoom(*this, mid);
}

void OAUser::showAllBookedMeetingRooms()
{
	vector<OAMeetingRoom> rooms = OADataCenter::getInstance().getRooms();

	for (OAMeetingRoom& r : rooms)
	{
		if (r.user() == this)
		{
			cout << "�����ҵı��: " << r.mid() << ", ����������" << r.capacity() 
				 << "," << this->department() << "��" << this->_username 
				 << "��Ԥ��!" << endl;
		}
	}
}