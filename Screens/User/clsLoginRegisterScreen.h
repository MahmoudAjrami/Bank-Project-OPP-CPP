#pragma once

#include <iostream>
#include <fstream>
#include <iomanip>
#include "clsUser.h"
#include "clsScreen.h"

using namespace std;

class clsLoginRegisterScreen : protected clsScreen
{

private:

	static void _PrintLoginRegisterRecordLine(clsUser::stLoginRegisterRecord Record)
	{
        cout << setw(8) << left << "" << "| " << left << setw(35) << Record.DateTime;
        cout << "| " << left << setw(20) << Record.UserName;
        cout << "| " << left << setw(20) << Record.Password;
        cout << "| " << left << setw(10) << Record.Permissions;
	}

public:
	static void ShowLoginRegisterScreen()
	{
        if (!CheckAccessRights(clsUser::enPermissions::pLoginRegister))
        {
            return;
        }


        vector <clsUser::stLoginRegisterRecord> vLoginRegisterRecord = clsUser::GetLoginRegisterList();
        string Title = "Login Register List Screen";
        string SubTitle = "(" + to_string(vLoginRegisterRecord.size()) + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle);
        
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(35) << "Date/Time";
        cout << "| " << left << setw(20) << "UserName";
        cout << "| " << left << setw(20) << "Password";
        cout << "| " << left << setw(10) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vLoginRegisterRecord.size() == 0)
            cout << "\t\t\t\tNo Logins Available In the System!";
        else

            for (clsUser::stLoginRegisterRecord Record : vLoginRegisterRecord)
            {

                _PrintLoginRegisterRecordLine(Record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
    }
	
};

