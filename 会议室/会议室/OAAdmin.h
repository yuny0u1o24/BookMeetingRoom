#pragma once
#include <string>
#include "OADataCenter.h"
using namespace std;


class OAAdmin
{
	friend class OADataCenter;
private:
	string _username;
	string _password;

public:
	OAAdmin();
	OAAdmin(string username, string password);

	static OAAdmin ERROR_ADMIN; // ¥ÌŒÛ”√ªß

	string username();

	bool addUser(string username, string password, string department);
	bool deleteUser(string username);
	void showAllUsers();

	bool addMeetingRoom(int mid, int capacity);
	bool deleteMeeintRoom(int mid);
	void clearMeeingRoomStatus();
	void showAllMetingRooms();
	 

};

