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
	cout << "��������Ҫ��ӵ��û���";
	cin >> username;
	cout << "��������Ҫ��ӵ�����: ";
	cin >> password;
	cout << "����������û��Ĳ���: ";
	cin >> department;

	if (admin.addUser(username, password, department))
	{
		cout << "Done." << endl;
	}
	else
	{
		cout << "ʧ��, ����û��Ѿ�����" << endl;
	}
}

void showAdminDeleteUserPage(OAAdmin& admin)
{
	system("cls");
	string username;
	cout << "��������Ҫɾ�����û�: " << endl;
	cin >> username;
	if (admin.deleteUser(username))
	{
		cout << "ɾ���ɹ�" << endl;
	}
	else
	{
		cout << "ɾ��ʧ��" << endl;
	}
}

void showAdminListUsers(OAAdmin& admin)
{
	admin.OAAdmin::showAllUsers();
}

// ��ӻ�����
void showAdminAddMeetingRoomPage(OAAdmin& admin)
{
	system("cls");
	int mid, capacity;
	cout << "��������Ҫ��ӵĻ����ұ��: ";
	mid = OAUtils::inputNumber();
	cout << "��������Ҫ��ӵĻ���������: ";
	capacity = OAUtils::inputNumber();

	if (admin.addMeetingRoom(mid, capacity))
	{
		cout << "��ӳɹ�!" << endl;
	}
	else
	{
		cout << "���ʧ��!�������Ѵ��ڣ�" << endl;
	}	
}

// ɾ�������ҽ���
void showAdminDeleteMeeingRoomPage(OAAdmin& admin)
{
	system("cls");
	cout << "��������Ҫɾ���Ļ�����: ";
	int mid = OAUtils::inputNumber();

	if (admin.deleteMeeintRoom(mid))
	{
		cout << "ɾ���ɹ�" << endl;
	}
	else
	{
		cout << "ɾ��ʧ��" << endl;
	}

}


// ��ʾ����Ա��������
void showAdminMainPage(OAAdmin& admin)
{
	while (1)
	{
		system("cls");
		cout << "����,����Ա:" << admin.username() << "����." << endl;
		cout << "--------------------" << endl;
		cout << "1.���һ����ͨ�û�" << endl;
		cout << "2.ɾ��һ����ͨ�û�" << endl;
		cout << "3.�о�������ͨ�û�" << endl;
		cout << "4.���һ��������" << endl;
		cout << "5.ɾ��һ��������" << endl;
		cout << "6.�о����л�����" << endl;
		cout << "7.���û�����״̬" << endl;
		cout << "8.�˳���½״̬." << endl;
		cout << "--------------------" << endl;
		cout << "���������: ";
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
	cout << "�˳���½." << endl;
}


// �û�Ԥ�������ҵĽ���
void showUserBookMeetingRoomPage(OAUser& user)
{
	system("cls");
	cout << "��������ҪԤ���Ļ�����: ";
	int mid = OAUtils::inputNumber();

	// Ԥ���������߼�
	int res = user.bookMeetingRoom(mid);
	if (res == BOOK_SUCCESS)
	{
		cout << "Ԥ���ɹ�!" << endl;
	}
	else if (res == MEETING_ROOM_BOOKED)
	{
		cout << "�������Ѿ���Ԥ��!" << endl;
	}
	else if (res == MEETING_ROOM_NOT_FOUND)
	{
		cout << "�����Ҳ�����!" << endl;
	}
}


// ȡ��Ԥ���Ļ����ҽ���
void showUserCancelBookMeetingRoot(OAUser& user)
{
	system("cls");
	cout << "��������Ҫȡ���Ļ�����: " << endl;
	int mid = OAUtils::inputNumber();

	int res = user.cancelBookMeetingRoom(mid);
	if (res == CANCEL_MEETING_SUCCESS)
	{
		cout << "ȡ��Ԥ���ɹ�! " << endl;
	}
	else if (res == CANCEL_MEETING_FAIL)
	{
		cout << "ȡ��ʧ��!û��Ԥ��!" << endl;
	}
	else if (res == CANCEL_MEETING_NOT_FOUNT)
	{
		cout << "��������Ҳ�����!" << endl;
	}


}


void showUserMainPage(OAUser& user)
{
	while (1)
	{
		system("cls");
		cout << "��ӭ" << user.department() << "��" << user.username() << endl;
		cout << "---------------------" << endl;
		cout << "1.Ԥ��������" << endl;
		cout << "2.ȡ��Ԥ��" << endl;
		cout << "3.�о������Ѿ�Ԥ���Ļ�����" << endl;
		cout << "4.�˳���¼" << endl;
		cout << "���������Ĳ���: ";
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
	cout << "�ټ�" << endl;
}


// ��ʾ��½���� flag��ʾ���
// 1: ����Ա��¼
// 0: �û�����¼
void showLogin(int flag)
{
	system("pause");
	if (flag == FLAG_ADMIN)
	{
		cout << "����Ա��½" << endl;
	}
	else
	{
		cout << "��ͨ�û���¼" << endl;
	}
	cout << "---------------------" << endl;
	string username, password;
	cout << "�������û���: ";
	cin >> username;
	cout << "����������: ";
	cin >> password;

	// ����Ա�û���¼ʵ��
	OADataCenter& dataCenter = OADataCenter::getInstance();
	if (flag == FLAG_ADMIN)
	{
		OAAdmin& admin = dataCenter.loginAdmin(username, password);
		if (&admin == &(OAAdmin::ERROR_ADMIN))
		{
			cout << "��½ʧ��!" << endl;
		}
		else 
		{
			cout << "��½�ɹ�!���ù���Ա:" << admin.username() <<endl; 
			showAdminMainPage(admin);
		}
	}
	else
	{
		OAUser& user = dataCenter.loginUser(username, password);
		if (&user == &(OAUser::ERROR_USER))
		{
			cout << "��¼ʧ��!" << endl;
		}
		else
		{
			cout << "��½�ɹ�, ��ӭ: " << user.username() << endl; 
			showUserMainPage(user);
		}
	}
}

void OASystemUI::displayMainPage()
{
	bool flag = 1;
	while (flag)
	{
		cout << "��ӭʹ��OA������Ԥ��ϵͳ" << endl;
		cout << "---------------------" << endl;
		cout << "1������Ա��¼" << endl;
		cout << "2����ͨ�û���¼" << endl;
		cout << "3���˳�ϵͳ" << endl;
		cout << "����������ѡ��: ";
		 
		// ���û����п���̨������ѡ��
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
	cout << "��ӭ�´�ʹ��" << endl;
}