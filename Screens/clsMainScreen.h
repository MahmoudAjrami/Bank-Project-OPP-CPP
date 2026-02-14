#pragma once
#include <iostream>
#include <iomanip>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsMangeUsersScreen.h"
#include "clsLoginRegisterScreen.h"
#include "clsCurrencyExchangeMainScreen.h"
#include "Global.h"


using namespace std;

class clsMainScreen : protected clsScreen
{

private:

	enum enMainMenuOptions
	{
		eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
		eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenu = 6,
		eManageUsers = 7, eLoginRegister = 8, eCurrencyExchange = 9, eExit = 10
	};

	static short _ReadMainMenuOption()
	{
		cout << setw(37) << left << "\t\t\t\t\tChoose What do you want to do? [1 to 10]? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 10, "Enter a Number Between 1 and 10!");
		return Choice;
	}

	static void _ShowAllClientsScreen()
	{
		//cout << "\nClient List Screen Will be here...\n";
		clsClientListScreen::ShowClientsList();
	}

	static void _ShowAddNewClientsScreen()
	{
		//cout << "\nAdd New Clients Screen Will be here...\n";
		clsAddNewClientScreen::ShowAddNewClientScreen();
	}

	static void _ShowDeleteClientScreen()
	{
		//cout << "\nDelete Client Screen Will be here...\n";
		clsDeleteClientScreen::ShowDeleteClientScreen();
	}

	static void _ShowUpdateClientMenu()
	{
		//cout << "\nUpdate Client Menu Will be here...\n";
		clsUpdateClientScreen::ShowUpdateClientScreen();
	}

	static void _ShowFindClientScreen()
	{
		//cout << "\nFind Client Screen Will be here...\n";
		clsFindClientScreen::ShowFindClientScreen();
	}

	static void _ShowTransactionsMenu()
	{
		//cout << "\nTransactions Menu Screen Will be here...\n";
		clsTransactionsScreen::ShowTransactionsMenu();
	}

	static void _ShowManageUsersMenu()
	{
		//cout << "\nManage Users Menu Will be here...\n";
		clsMangeUsersScreen::ShowManageUsersScreen();
	}

	static void _ShowLoginRegisterScreen()
	{
		//cout << "\nRegister Login Screen Will be here...\n";
		clsLoginRegisterScreen::ShowLoginRegisterScreen();
	}

	static void _ShowCurrencyExchangeScreen()
	{
		//cout << "\nRegister Login Screen Will be here...\n";
		clsCurrencyExchangeMainScreen::ShowCurrenciesMenu();
	}

	static void _GoBackToMainMenu()
	{
		cout << "\nPress any key to go back to Main Menu...\n";
		system("pause>0");
		ShowMainMenu();
		
	}

	static void _Logout()
	{
		CurrentUser = clsUser::Find("","");

		//then it will go back to main function.
	}

	static void _PerformMainMenuOption(enMainMenuOptions MainMenuOption)
	{
		switch (MainMenuOption)
		{
		case clsMainScreen::eListClients:
			system("cls");
			_ShowAllClientsScreen();
			_GoBackToMainMenu();
			break;

		case clsMainScreen::eAddNewClient:
			system("cls");
			_ShowAddNewClientsScreen();
			_GoBackToMainMenu();
			break;

		case clsMainScreen::eDeleteClient:
			system("cls");
			_ShowDeleteClientScreen();
			_GoBackToMainMenu();
			break;

		case clsMainScreen::eUpdateClient:
			system("cls");
			_ShowUpdateClientMenu();
			_GoBackToMainMenu();
			break;

		case clsMainScreen::eFindClient:
			system("cls");
			_ShowFindClientScreen();
			_GoBackToMainMenu();
			break;

		case clsMainScreen::eShowTransactionsMenu:
			system("cls");
			_ShowTransactionsMenu();
			_GoBackToMainMenu();
			break;

		case clsMainScreen::eManageUsers:
			system("cls");
			_ShowManageUsersMenu();
			_GoBackToMainMenu();
			break;

		case clsMainScreen::eLoginRegister:
			system("cls");
			_ShowLoginRegisterScreen();
			_GoBackToMainMenu();
			break;
		
		case clsMainScreen::eCurrencyExchange:
			system("cls");
			_ShowCurrencyExchangeScreen();
			_GoBackToMainMenu();
			break;

		case clsMainScreen::eExit:
			system("cls");
			_Logout();
			break;
		}

	}

public:

	static void ShowMainMenu()
	{
		system("cls");
		_DrawScreenHeader("Main Screen");
		cout << setw(37) << left << "" << "=====================================================\n";
		cout << setw(37) << left << "" << "\t\t\tMain Menu\n";
		cout << setw(37) << left << "" << "=====================================================\n";
		cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
		cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
		cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
		cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
		cout << setw(37) << left << "" << "\t[5] Find Client.\n";
		cout << setw(37) << left << "" << "\t[6] Transactions.\n";
		cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
		cout << setw(37) << left << "" << "\t[8] Login Register.\n";
		cout << setw(37) << left << "" << "\t[9] CurrencyExchange.\n";
		cout << setw(37) << left << "" << "\t[10] Logout.\n";
		cout << setw(37) << left << "" << "=====================================================\n";

		_PerformMainMenuOption((enMainMenuOptions)_ReadMainMenuOption());
	}

};

