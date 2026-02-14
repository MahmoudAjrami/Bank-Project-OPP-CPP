#pragma once
#include <iostream>
#include <iomanip>
#include "clsMainScreen.h"
#include "clsUser.h"
#include "Global.h"

class clsLoginScreen : protected clsScreen
{

private:

	static bool _LoginScreen()
	{
		bool LoginFailed = false;
		short FailedLoginCount = 0;

		string Username, Password;
		do
		{
			if (LoginFailed)
			{
				FailedLoginCount++;
				cout << "\nInvalid Username/Password!";
				cout << "\nYou have " << (3 - FailedLoginCount) << " Trial(s) to login.\n";

				if (FailedLoginCount == 3)
				{
					cout << "\nYou are Locked after 3 Failed Trials\n\n";
					return false;
				}
			}

			cout << "\nEnter Username? ";
			cin >> Username;

			cout << "Enter Password? ";
			cin >> Password;

			CurrentUser = clsUser::Find("user1", "0000");

			LoginFailed = CurrentUser.IsEmpty();

		} while (LoginFailed);

		CurrentUser.RegisterLogIn();
		clsMainScreen::ShowMainMenu();
		return true;
	}

public:

	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("Login Screen");
		return _LoginScreen();
	}
};

