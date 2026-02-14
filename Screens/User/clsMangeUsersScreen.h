#pragma once

#include <iostream>
#include <iomanip>
#include "clsScreen.h"
//#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsListUsersScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"

using namespace std;

class clsMangeUsersScreen : protected clsScreen
{
private:
	enum enManageUsersMenuOptions {
		eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3,
		eUpdateUser = 4, eFindUser = 5, eMainMenu = 6
	};

	static short _ReadManageUsersMenuOption()
	{
		cout << setw(37) << left << "\t\t\t\t\tChoose What do you want to do? [1 to 6]? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter a Number Between 1 and 6!");
		return Choice;
	}

	static void _ShowListUsersScreen()
	{
		//cout << "List Users Screen Will Be here...\n";
		clsListUsersScreen::ShowListUsersScreen();
	}

	static void _ShowAddNewUserScreen()
	{
		//cout << "Add New User Screen Will Be here...\n";
		clsAddNewUserScreen::ShowAddNewUsersScreen();
	}

	static void _ShowDeleteUserScreen()
	{
		//cout << "Delete User Screen Will Be here...\n";
		clsDeleteUserScreen::ShowDeleteUserScreen();
	}

	static void _ShowUpdateUserScreen()
	{
		//cout << "Update Users Screen Will Be here...\n";
		clsUpdateUserScreen::ShowUpdateUserScreen();
	}

	static void _ShowFindUserScreen()
	{
		//cout << "Find Users Screen Will Be here...\n";
		clsFindUserScreen::ShowFindUserScreen();
	}

	static void _GoBackToManageUsersMenuOption()
	{
		cout << "\nPress any key to go back to Mange User Menu...\n";
		system("pause>0");
		ShowManageUsersScreen();
	}

	static void _PerformTransactionsMenuOption(enManageUsersMenuOptions ManageUsersMenuOption)
	{
		switch (ManageUsersMenuOption)
		{
		case clsMangeUsersScreen::eListUsers:
			system("cls");
			_ShowListUsersScreen();
			_GoBackToManageUsersMenuOption();
			break;

		case clsMangeUsersScreen::eAddNewUser:
			system("cls");
			_ShowAddNewUserScreen();
			_GoBackToManageUsersMenuOption();
			break;

		case clsMangeUsersScreen::eDeleteUser:
			system("cls");
			_ShowDeleteUserScreen();
			_GoBackToManageUsersMenuOption();
			break;

		case clsMangeUsersScreen::eUpdateUser:
			system("cls");
			_ShowUpdateUserScreen();
			_GoBackToManageUsersMenuOption();
			break;

		case clsMangeUsersScreen::eFindUser:
			system("cls");
			_ShowFindUserScreen();
			_GoBackToManageUsersMenuOption();
			break;

		case clsMangeUsersScreen::eMainMenu:
			break;

		}
	}


public:
	static void ShowManageUsersScreen()
	{
		system("cls");

		if (!CheckAccessRights(clsUser::enPermissions::pManageUsers))
		{
			return;
		}

		_DrawScreenHeader("Manage Users Screen");
		cout << setw(37) << left << "" << "=====================================================\n";
		cout << setw(37) << left << "" << "\t\t\tManage Users Menu\n";
		cout << setw(37) << left << "" << "=====================================================\n";
		cout << setw(37) << left << "" << "\t[1] List Users.\n";
		cout << setw(37) << left << "" << "\t[2] Add New User.\n";
		cout << setw(37) << left << "" << "\t[3] Delete User.\n";
		cout << setw(37) << left << "" << "\t[4] Update User.\n";
		cout << setw(37) << left << "" << "\t[5] Find User.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menu.\n";
		cout << setw(37) << left << "" << "=====================================================\n";

		_PerformTransactionsMenuOption((enManageUsersMenuOptions)_ReadManageUsersMenuOption());
	}

};

