#pragma once

#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"

using namespace std;

class clsTransferScreen : protected clsScreen
{

private:

	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n-------------------\n";
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n-------------------\n";

	}

	static string _ReadAccountNumber()
	{
		string AccountNumber;
		cout << "\nPlease Enter Account Number To Transfer Form: ";
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number is not found, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}
		return AccountNumber;
	}

	static float _ReadAmount(clsBankClient SourceClient)
	{
		float Amount;

		cout << "\nEnter Transfer Amount? ";

		Amount = clsInputValidate::ReadFloatNumber();

		while (Amount > SourceClient.AccountBalance)
		{
			cout << "\nAmount Exceeds The Available Balance, Enter Another one: ";
			Amount = clsInputValidate::ReadDblNumber();
		}
		return Amount;
	}

public:
	static void ShowTransferScreen()
	{
		system("cls");
		
		_DrawScreenHeader("Transfer Screen");

		clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber());

		_PrintClient(SourceClient);

		clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber());

		_PrintClient(DestinationClient);

		float Amount = _ReadAmount(SourceClient);

		cout << "\nAre You Sure You Want To Perform This Operation? y/n? ";
		char Answer = 'n';
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			if (SourceClient.Transfer(Amount, DestinationClient, CurrentUser.UserName))
			{
				cout << "\nTransfer Done Successfully\n";
			}
			else
			{
				cout << "\nTransfer Failed \n";
			}
		}

		_PrintClient(SourceClient);
		_PrintClient(DestinationClient);
		
	}
};

