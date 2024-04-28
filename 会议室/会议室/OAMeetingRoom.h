#pragma once
#include "OAUser.h"
#include "OADataCenter.h"

class OAUser;

class OAMeetingRoom
{
	friend class OADataCenter;
private:
	int _mid;	// ���
	int _capacity; // ����
	OAUser* _user; // ��˭��ռ�����������
	
public:
	OAMeetingRoom();
	OAMeetingRoom(int mid, int capacity);

	int mid();
	int capacity();
	OAUser* user();
};

