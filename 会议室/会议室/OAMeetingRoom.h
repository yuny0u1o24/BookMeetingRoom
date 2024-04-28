#pragma once
#include "OAUser.h"
#include "OADataCenter.h"

class OAUser;

class OAMeetingRoom
{
	friend class OADataCenter;
private:
	int _mid;	// 编号
	int _capacity; // 容量
	OAUser* _user; // 是谁在占用这个会议室
	
public:
	OAMeetingRoom();
	OAMeetingRoom(int mid, int capacity);

	int mid();
	int capacity();
	OAUser* user();
};

