#include "OASystemUI.h"
#include "OAUtils.h"
#include "OADataCenter.h"
#include "OAUser.h"
#include <iostream>
#include <windows.h>

#define FLAG_ADMIN 1
#define FLAG_USER 0
using namespace std;


void showAdminAddUserPage(OAAdmin& admin)
{
	system("cls");
	string username;
	string password;
	string department;
	cout << "请输入需要添加的用户名";
	cin >> username;
	cout << "请输入需要添加的密码: ";
	cin >> password;
	cout << "请输入这个用户的部门: ";
	cin >> department;

	if (admin.addUser(username, password, department))
	{
		cout << "Done." << endl;
	}
	else
	{
		cout << "失败, 这个用户已经存在" << endl;
	}
}

void showAdminDeleteUserPage(OAAdmin& admin)
{
	system("cls");
	string username;
	cout << "请输入需要删除的用户: " << endl;
	cin >> username;
	if (admin.deleteUser(username))
	{
		cout << "删除成功" << endl;
	}
	else
	{
		cout << "删除失败" << endl;
	}
}

void showAdminListUsers(OAAdmin& admin)
{
	admin.OAAdmin::showAllUsers();
}

// 添加会议室
void showAdminAddMeetingRoomPage(OAAdmin& admin)
{
	system("cls");
	int mid, capacity;
	cout << "请输入需要添加的会议室编号: ";
	mid = OAUtils::inputNumber();
	cout << "请输入需要添加的会议室容量: ";
	capacity = OAUtils::inputNumber();

	if (admin.addMeetingRoom(mid, capacity))
	{
		cout << "添加成功!" << endl;
	}
	else
	{
		cout << "添加失败!会议室已存在！" << endl;
	}	
}

// 删除会议室界面
void showAdminDeleteMeeingRoomPage(OAAdmin& admin)
{
	system("cls");
	cout << "请输入需要删除的会议室: ";
	int mid = OAUtils::inputNumber();

	if (admin.deleteMeeintRoom(mid))
	{
		cout << "删除成功" << endl;
	}
	else
	{
		cout << "删除失败" << endl;
	}

}


// 显示管理员的主界面
void showAdminMainPage(OAAdmin& admin)
{
	while (1)
	{
		system("cls");
		cout << "您好,管理员:" << admin.username() << "先生." << endl;
		cout << "--------------------" << endl;
		cout << "1.添加一个普通用户" << endl;
		cout << "2.删除一个普通用户" << endl;
		cout << "3.列举所有普通用户" << endl;
		cout << "4.添加一个会议室" << endl;
		cout << "5.删除一个会议室" << endl;
		cout << "6.列举所有会议室" << endl;
		cout << "7.重置会议室状态" << endl;
		cout << "8.退出登陆状态." << endl;
		cout << "--------------------" << endl;
		cout << "请输入操作: ";
		int c = OAUtils::inputNumber();
		switch (c)
		{
			case 1:
				showAdminAddUserPage(admin);
				break;
			case 2:
				showAdminDeleteUserPage(admin);
				break;
			case 3:
				showAdminListUsers(admin);
				break;
			case 4:
				showAdminAddMeetingRoomPage(admin);
				break;
			case 5:
				showAdminDeleteMeeingRoomPage(admin);
				break;
			case 6:
			{
				system("cls");
				admin.showAllMetingRooms();
				break; 
			}
			case 7:
				admin.clearMeeingRoomStatus();
				break;
			case 8:
				goto end;
				break;
		}
		system("pause");
	}
end:
	cout << "退出登陆." << endl;
}


// 用户预定会议室的界面
void showUserBookMeetingRoomPage(OAUser& user)
{
	system("cls");
	cout << "请输入您要预定的会议室: ";
	int mid = OAUtils::inputNumber();

	// 预定会议室逻辑
	int res = user.bookMeetingRoom(mid);
	if (res == BOOK_SUCCESS)
	{
		cout << "预定成功!" << endl;
	}
	else if (res == MEETING_ROOM_BOOKED)
	{
		cout << "会议室已经被预定!" << endl;
	}
	else if (res == MEETING_ROOM_NOT_FOUND)
	{
		cout << "会议室不存在!" << endl;
	}
}


// 取消预定的会议室界面
void showUserCancelBookMeetingRoot(OAUser& user)
{
	system("cls");
	cout << "请输入您要取消的会议室: " << endl;
	int mid = OAUtils::inputNumber();

	int res = user.cancelBookMeetingRoom(mid);
	if (res == CANCEL_MEETING_SUCCESS)
	{
		cout << "取消预定成功! " << endl;
	}
	else if (res == CANCEL_MEETING_FAIL)
	{
		cout << "取消失败!没有预定!" << endl;
	}
	else if (res == CANCEL_MEETING_NOT_FOUNT)
	{
		cout << "这个会议室不存在!" << endl;
	}


}


void showUserMainPage(OAUser& user)
{
	while (1)
	{
		system("cls");
		cout << "欢迎" << user.department() << "的" << user.username() << endl;
		cout << "---------------------" << endl;
		cout << "1.预定会议室" << endl;
		cout << "2.取消预定" << endl;
		cout << "3.列举所有已经预定的会议室" << endl;
		cout << "4.退出登录" << endl;
		cout << "请输入您的操作: ";
		int c = OAUtils::inputNumber();

		switch (c)
		{
			case 1:
				showUserBookMeetingRoomPage(user);
				break;
			case 2:
				showUserCancelBookMeetingRoot(user);
					break;
			case 3:
				system("cls ");
				user.showAllBookedMeetingRooms();
				break;
			case 4:
				goto end;
		}
		system("pause");

	}
end:
	cout << "再见" << endl;
}


// 显示登陆界面 flag表示身份
// 1: 管理员登录
// 0: 用户名登录
void showLogin(int flag)
{
	system("pause");
	if (flag == FLAG_ADMIN)
	{
		cout << "管理员登陆" << endl;
	}
	else
	{
		cout << "普通用户登录" << endl;
	}
	cout << "---------------------" << endl;
	string username, password;
	cout << "请输入用户名: ";
	cin >> username;
	cout << "请输入密码: ";
	cin >> password;

	// 管理员用户登录实现
	OADataCenter& dataCenter = OADataCenter::getInstance();
	if (flag == FLAG_ADMIN)
	{
		OAAdmin& admin = dataCenter.loginAdmin(username, password);
		if (&admin == &(OAAdmin::ERROR_ADMIN))
		{
			cout << "登陆失败!" << endl;
		}
		else 
		{
			cout << "登陆成功!您好管理员:" << admin.username() <<endl; 
			showAdminMainPage(admin);
		}
	}
	else
	{
		OAUser& user = dataCenter.loginUser(username, password);
		if (&user == &(OAUser::ERROR_USER))
		{
			cout << "登录失败!" << endl;
		}
		else
		{
			cout << "登陆成功, 欢迎: " << user.username() << endl; 
			showUserMainPage(user);
		}
	}
}

void OASystemUI::displayMainPage()
{
	bool flag = 1;
	while (flag)
	{
		cout << "欢迎使用OA会议室预订系统" << endl;
		cout << "---------------------" << endl;
		cout << "1、管理员登录" << endl;
		cout << "2、普通用户登录" << endl;
		cout << "3、退出系统" << endl;
		cout << "请输入您的选择: ";
		 
		// 让用户进行控制台的输入选择
		int choice = OAUtils::inputNumber();
		
		switch (choice)
		{
			case 1:
				showLogin(FLAG_ADMIN);
				break;
			case 2:
				showLogin(FLAG_USER);
				break;
			case 3:
				goto end;
				break;
		}
		system("pause");
		system("cls");
	}

end:
	cout << "欢迎下次使用" << endl;
}