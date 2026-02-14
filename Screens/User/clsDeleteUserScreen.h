#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "clsPerson.h"
#include "clsString.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"

using namespace std;

class clsDeleteUserScreen : protected clsScreen
{

private:
    static void _PrintUser(clsUser User)
    {

        cout << "\nUser Card:";
        cout << "\n________________";
        cout << "\nFirstName: " << User.FirstName;
        cout << "\nLastName: " << User.LastName;
        cout << "\nFull Name: " << User.FullName();
        cout << "\nEmail: " << User.Email;
        cout << "\nPhone: " << User.Phone;
        cout << "\nUsername: " << User.UserName;
        cout << "\nPassword: " << User.Password;
        cout << "\nPermissions: " << User.Permissions;
        cout << "\n________________\n";
                
    }

public:
	
	static void ShowDeleteUserScreen()
	{
		
		_DrawScreenHeader("Delete User Screen");

        string UserName = "";

        cout << "\nPlease Enter UserName: ";
        UserName = clsInputValidate::ReadString();
        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nUser not found, choose another one: ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser User = clsUser::Find(UserName);
        _PrintUser(User);

        cout << "\nAre you sure you want to delete this User? y/n? ";
        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            if (User.Delete())
            {
                cout << "\n User Deleted Successfully :-)\n";
                _PrintUser(User);
            }
            else
            {
                cout << "\nError User was not Deleted!";
            }
            
        }
	}

};

