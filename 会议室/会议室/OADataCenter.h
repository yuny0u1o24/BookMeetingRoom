#pragma once
#include <vector>
#include "OAAdmin.h"
#include "OAUser.h"
#include "OAMeetingRoom.h"
using namespace std;

class OAAdmin;
class OAUser;
class OAMeetingRoom;

class OADataCenter
{
private:
	vector<OAUser> users;
	vector<OAAdmin> admins;
	vector<OAMeetingRoom> rooms;

	OADataCenter();
	static OADataCenter _instance;

public:
	// 返回一个全局唯一的对象 单例设计模式
	static OADataCenter& getInstance();
	OAAdmin& loginAdmin(string username, string password);
	OAUser& loginUser(string username, string password);

	// 添加用户，返回值表示是否添加成功
	bool addUser(string name, string password, string department); 
	// 删除用户
	bool deleteUser(string username);

	// 添加会议室，返回时表是否是添加成功
	bool addMeetingRoom(int mid, int capacity);
	// 删除会议室
	bool deleteMeetingRoom(int mid);

	// 清除所有会议室的状态
	void clearRoomStatus();

	// 预定会议室
	int bookMeetingRoom(OAUser& user, int mid);
	// 取消预定会议室
	int cancelBookMeetingRoom(OAUser&user, int mid);


	 

	vector<OAUser> getUsers();
	vector<OAMeetingRoom> getRooms();
	 
};

