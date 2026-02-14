#pragma once

#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogScreen.h"


using namespace std;

class clsTransactionsScreen : protected clsScreen
{

private:
	enum enTransactionsMenuOptions
	{
		eDeposit = 1, eWithdraw = 2, eTotalBalances = 3, eTransfer = 4,
		eTransferLog = 5 ,eShowMainMenu = 6
	};

	static short _ReadTransactionsMenuOption()
	{
		cout << setw(37) << left << "\t\t\t\t\tChoose What do you want to do? [1 to 6]? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter a Number Between 1 and 6!");
		return Choice;
	}

	static void _ShowDepositScreen()
	{
		//cout << "Deposit Screen will be here...\n";
		clsDepositScreen::ShowDepositScreen();
	}

	static void _ShowWithdrawScreen()
	{
		//cout << "Withdraw Screen will be here...\n";
		clsWithdrawScreen::ShowWithDrawScreen();
	}

	static void _ShowTotalBalancesScreen()
	{
		//cout << "TotalBalances Screen will be here...\n";
		clsTotalBalancesScreen::ShowClientBalances();
	}

	static void _ShowTransferScreen()
	{
		//cout << "Transfer Screen will be here...\n";
		clsTransferScreen::ShowTransferScreen();

	}

	static void _ShowTransferLogScreen()
	{
		//cout << "Transfer Log Screen will be here...\n";
		clsTransferLogScreen::ShowTransferLogScreen();
	}

	static void _GoBackToTransactionMenu()
	{
		cout << "\nPress any key to go back to Transaction Menu...\n";
		system("pause>0");
		ShowTransactionsMenu();

	}

	
	static void _PerformTransactionsMenuOption(enTransactionsMenuOptions TransactionMenuOption)
	{
		switch (TransactionMenuOption)
		{
		case clsTransactionsScreen::eDeposit:
			system("cls");
			_ShowDepositScreen();
			_GoBackToTransactionMenu();
			break;
		
		case clsTransactionsScreen::eWithdraw:
			system("cls");
			_ShowWithdrawScreen();
			_GoBackToTransactionMenu();
			break;
		
		case clsTransactionsScreen::eTotalBalances:
			system("cls");
			_ShowTotalBalancesScreen();
			_GoBackToTransactionMenu();
			break;

		case clsTransactionsScreen::eTransfer:
			system("cls");
			_ShowTransferScreen();
			_GoBackToTransactionMenu();
			break;

		case clsTransactionsScreen::eTransferLog:
			system("cls");
			_ShowTransferLogScreen();
			_GoBackToTransactionMenu();
			break;

		case clsTransactionsScreen::eShowMainMenu:
			// Main Menu Will Handle it :-)
			break;
		}
	}

public:
	static void ShowTransactionsMenu()
	{
		system("cls");

		if (!CheckAccessRights(clsUser::enPermissions::pTransactions))
		{
			return;
		}

		_DrawScreenHeader("Transaction Screen");
		cout << setw(37) << left << "" << "=====================================================\n";
		cout << setw(37) << left << "" << "\t\t\tTransaction Menu\n";
		cout << setw(37) << left << "" << "=====================================================\n";
		cout << setw(37) << left << "" << "\t[1] Deposit.\n";
		cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
		cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
		cout << setw(37) << left << "" << "\t[4] Transfer.\n";
		cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menu.\n";
		cout << setw(37) << left << "" << "=====================================================\n";

		_PerformTransactionsMenuOption((enTransactionsMenuOptions)_ReadTransactionsMenuOption());
	}

};

