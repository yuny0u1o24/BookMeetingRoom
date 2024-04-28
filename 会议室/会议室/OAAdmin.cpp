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
		cout << "�û���: " << u.username() << " ����: " << u.department() << endl;
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
	// ��ȡ�����еĻ�����
	vector<OAMeetingRoom> rooms = OADataCenter::getInstance().getRooms();
	// ����ÿһ��������
	for (OAMeetingRoom& m : rooms)
	{
		cout << "�����ұ��: " << m.mid() << ", ����: " << m.capacity();
		if ((m.user()) == &(OAUser::ERROR_USER))
		{
			cout << "��Ԥ��." << endl;
		}
		else
		{
			cout << ", ����������Ѿ���" << m.user()->department() << "��" << m.user()->username() << "ռ����" << endl;
		}
	}
}

OAAdmin OAAdmin::ERROR_ADMIN = OAAdmin(); // �����û�
