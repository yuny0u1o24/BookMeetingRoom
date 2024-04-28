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
	// ����һ��ȫ��Ψһ�Ķ��� �������ģʽ
	static OADataCenter& getInstance();
	OAAdmin& loginAdmin(string username, string password);
	OAUser& loginUser(string username, string password);

	// ����û�������ֵ��ʾ�Ƿ���ӳɹ�
	bool addUser(string name, string password, string department); 
	// ɾ���û�
	bool deleteUser(string username);

	// ��ӻ����ң�����ʱ���Ƿ�����ӳɹ�
	bool addMeetingRoom(int mid, int capacity);
	// ɾ��������
	bool deleteMeetingRoom(int mid);

	// ������л����ҵ�״̬
	void clearRoomStatus();

	// Ԥ��������
	int bookMeetingRoom(OAUser& user, int mid);
	// ȡ��Ԥ��������
	int cancelBookMeetingRoom(OAUser&user, int mid);


	 

	vector<OAUser> getUsers();
	vector<OAMeetingRoom> getRooms();
	 
};

