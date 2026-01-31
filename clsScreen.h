#pragma once

#include <iostream>
#include "clsUser.h"
#include "clsDate.h"
#include "Global.h"

using namespace std;

class clsScreen
{
protected:
	
	static void _DrawScreenHeader(string Title, string SubTitle = "")
	{
		cout << "\t\t\t\t\t___________________________________________\n";
		cout << "\n\t\t\t\t\t\t\t " << Title << endl;

		if (SubTitle != "")
		{
			cout << "\n\t\t\t\t\t\t\t " << SubTitle << endl;
		}

		cout << "\t\t\t\t\t___________________________________________\n";
		
		cout << "\n\t\t\t\t\t User: " << CurrentUser.UserName << endl;
		cout << "\t\t\t\t\t Date: " << clsDate::DateToString(clsDate::clsDate())<< endl << endl;
		
	}

	
	static bool CheckAccessRights(clsUser::enPermissions Permission)
	{
		if (!CurrentUser.CheckAccessPermission(Permission))
		{
			cout << "\t\t\t\t\t________________________________________________________\n";
			cout << "\n\n\t\t\t\t\t\t  Access Denied! Contact Your Admin\n";
			cout << "\n\t\t\t\t\t________________________________________________________\n";
			return false;
		}
		else
		{
			return true;
		}
	}
	
	

};

