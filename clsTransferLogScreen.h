#pragma once

#include <iostream>
#include <iomanip>
#include <fstream>
#include "clsBankClient.h"
#include "clsScreen.h"

using namespace std;

class clsTransferLogScreen : protected clsScreen
{

private:

	static void _PrintTransferLogRecordLine(clsBankClient::stTransferLogRecord TransferLogRecord)
	{
        cout << setw(8) << left << "" << "| " << setw(22) << left << TransferLogRecord.DateTime;
        cout << "| " << left << setw(8) << TransferLogRecord.SourceAccountNumber;
        cout << "| " << left << setw(8) << TransferLogRecord.DestinationAccountNumber;
        cout << "| " << left << setw(8) << TransferLogRecord.Amount;
        cout << "| " << left << setw(10) << TransferLogRecord.srcBalanceAfter;
        cout << "| " << left << setw(10) << TransferLogRecord.destBalanceAfter;
        cout << "| " << left << setw(15) << TransferLogRecord.UserName;
	}

public:

    static void ShowTransferLogScreen()
    {
        vector <clsBankClient::stTransferLogRecord> vTransferLogRecord = clsBankClient::GetTransferLogList();
        string Title = "Transfer Log List Screen";
        string SubTitle = "(" + to_string(vTransferLogRecord.size()) + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle);


        cout << setw(10) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(22) << "Date-Time";
        cout << "| " << left << setw(8) << "S. Acct";
        cout << "| " << left << setw(8) << "D. Acct";
        cout << "| " << left << setw(8) << "Amount";
        cout << "| " << left << setw(10) << "S.Balance";
        cout << "| " << left << setw(10) << "D.Balance";
        cout << "| " << left << setw(15) << "User";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vTransferLogRecord.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else

            for (clsBankClient::stTransferLogRecord Record : vTransferLogRecord)
            {

                _PrintTransferLogRecordLine(Record);
                cout << endl;
            }

        cout << setw(10) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
    }
};

