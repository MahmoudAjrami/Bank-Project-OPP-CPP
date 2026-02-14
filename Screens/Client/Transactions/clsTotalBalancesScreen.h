#pragma once

#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsUtil.h"

using namespace std;

class clsTotalBalancesScreen : protected clsScreen
{

private:
    
    static void _PrintClientRecordLine(clsBankClient Client)
    {
        cout << "| " << left << setw(15) << Client.AccountNumber();
        cout << "| " << left << setw(40) << Client.FullName();
        cout << "| " << left << setw(12) << Client.AccountBalance;

    }

public:
    // ÒÈØ íÇ ãÍãæÏ æÇÌåÉ ÇáØÈÇÚÉ ãÇíáÉ :-(
    static void ShowClientBalances()
    {


        vector <clsBankClient> vClients = clsBankClient::GetClientsList();
        
        string Title = "List Balances Screen";
        string SubTitle = "\n\t\t\t\t\t\t    Client List (" + to_string(vClients.size()) + ") Client(s).\n";
        
        _DrawScreenHeader(Title, SubTitle);

        cout << "\n________________________________________________________________________________________________\n\n";

        cout << "| " << left << setw(15) << "AccountNumber";
        cout << "| " << left << setw(40) << "Client Name";
        cout << "| " << left << setw(12) << "Balance";

        cout << "\n________________________________________________________________________________________________\n\n";

        double TotalBalances = clsBankClient::GetClientsBalances();


        if (vClients.size() == 0)
        {
            cout << "\t\t\t No Clients Available In the System!";
        }
        else
        {
            for (clsBankClient& Client : vClients)
            {
                _PrintClientRecordLine(Client);
                cout << endl;
            }
            cout << "\n________________________________________________________________________________________________\n";

            cout << "\n\t\t\t\t Total Balances = " << TotalBalances << endl;
            cout << "\n\t\t\t\t( " << clsUtil::NumberToText(TotalBalances) << ") " << endl;
        }


    }
};

