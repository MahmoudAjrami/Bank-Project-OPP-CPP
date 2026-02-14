#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "clsPerson.h"
#include "clsString.h"
#include "clsDate.h"
#include "clsUtil.h"

using namespace std;

class clsUser : public clsPerson
{

private:
	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
	enMode _Mode;
	string _UserName;
	string _Password;
	int _Permissions;

	bool _MarkedForDelete = false;

	struct stLoginRegisterRecord;

	static clsUser _ConvertLineToUserObject(string Line, string Seperator = "#//#")
	{
		vector <string> vUsersData;
		vUsersData = clsString::Split(Line, Seperator);
		
		return clsUser(enMode::UpdateMode, vUsersData[0], vUsersData[1], vUsersData[2], vUsersData[3], vUsersData[4],
			clsUtil::DecryptText(vUsersData[5]), stoi(vUsersData[6]));
	}

	static clsUser _GetEmptyUserObject()
	{
		return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}
	   
	static vector <clsUser> _LoadUsersDataFromFile()
	{
		vector <clsUser> vUsers;
		fstream MyFile;
		MyFile.open("Data/Users.txt", ios::in);

		while (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLineToUserObject(Line);
				vUsers.push_back(User);
				
			}

			MyFile.close();
		}
		return vUsers;
	}

	static string _ConvertUserObjectToLine(clsUser User, string Seperator = "#//#")
	{

		string stClientRecord = "";
		stClientRecord += User.FirstName + Seperator;
		stClientRecord += User.LastName + Seperator;
		stClientRecord += User.Email + Seperator;
		stClientRecord += User.Phone + Seperator;
		stClientRecord += User.UserName + Seperator;
		// here we encrypt store the encrypted Password not the real one.
		stClientRecord += clsUtil::EncryptText(User.Password) + Seperator;
		stClientRecord += to_string(User.Permissions);

		return stClientRecord;
	}

	static void _SaveUsersDataToFile(vector <clsUser> vClients)
	{
		fstream MyFile;
		MyFile.open("Data/Users.txt", ios::out); // overwrite

		string DataLine;

		if (MyFile.is_open())
		{
			for (clsUser& Client : vClients)
			{
				if (Client.MarkedForDelete() == false)
				{
					DataLine = _ConvertUserObjectToLine(Client);
					MyFile << DataLine << endl;
				}
			}

			MyFile.close();
		}
	}

	void _Update()
	{
		vector <clsUser> _vUsers;
		_vUsers = _LoadUsersDataFromFile();

		for (clsUser& User : _vUsers)
		{
			if (User.UserName == UserName)
			{
				User = *this;
				break;
			}
		}

		_SaveUsersDataToFile(_vUsers);
	}

	void _AddDataLineToFile(string stDataLine)
	{

		fstream MyFile;
		MyFile.open("Data/Users.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << stDataLine << endl;

			MyFile.close();
		}

	}
	
	void _AddNew()
	{
		_AddDataLineToFile(_ConvertUserObjectToLine(*this));
	}
	
	string _PrepareLogInRecord(string Seperator = "#//#")
	{
		string LoginRecord = "";
		LoginRecord += clsDate::GetSystemDateTimeString() + Seperator;
		LoginRecord += UserName + Seperator;
		LoginRecord += clsUtil::EncryptText(Password) + Seperator;
		LoginRecord += to_string(Permissions);

		return LoginRecord;
	}

	static stLoginRegisterRecord _ConvertLoginRegisterLineToRecord(string Line, string Seperator = "#//#")
	{
		stLoginRegisterRecord LoginRegisterRecord;

		vector <string> vLoginRegisterLine = clsString::Split(Line, Seperator);
		LoginRegisterRecord.DateTime = vLoginRegisterLine[0];
		LoginRegisterRecord.UserName = vLoginRegisterLine[1];
		LoginRegisterRecord.Password = clsUtil::DecryptText(vLoginRegisterLine[2]);
		LoginRegisterRecord.Permissions = stoi(vLoginRegisterLine[3]);

		return LoginRegisterRecord;
	}

public:

	enum enPermissions {
		eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4,
		pUpdateClients = 8, pFindClient = 16, pTransactions = 32, pManageUsers = 64, pLoginRegister = 128
	};

	struct stLoginRegisterRecord
	{
		string DateTime;
		string UserName;
		string Password;
		int Permissions;
	};

	clsUser(enMode Mode, string FirstName, string LastName,
		string Email, string Phone, string UserName, string Password,
		int Permissions) :
		clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_UserName = UserName;
		_Password = Password;
		_Permissions = Permissions;
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}
		
	bool MarkedForDelete()
	{
		return _MarkedForDelete;
	}

	// Property UserName
	void SetUserName(string UserName)
	{
		_UserName = UserName;
	}

	string GetUserName()
	{
		return _UserName;
	}

	_declspec(property(get = GetUserName, put = SetUserName)) string UserName;

	// Property Password
	void SetPassword(string Password)
	{
		_Password = Password;
	}

	string GetPassword()
	{
		return _Password;
	}

	_declspec(property(get = GetPassword, put = SetPassword)) string Password;

	// Property Permissions
	void SetPermissions(int Permissions)
	{
		_Permissions = Permissions;
	}

	int GetPermissions()
	{
		return _Permissions;
	}

	_declspec(property(get = GetPermissions, put = SetPermissions)) int Permissions;

	static clsUser Find(string UserName)
	{
		fstream MyFile;
		MyFile.open("Data/Users.txt", ios::in); // read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLineToUserObject(Line);
				if (User.UserName == UserName)
				{
					MyFile.close();
					return User;
				}
			}

			MyFile.close();
		}

		return _GetEmptyUserObject();
	}

	static clsUser Find(string UserName, string Password)
	{

		fstream MyFile;
		MyFile.open("Data/Users.txt", ios::in); // read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLineToUserObject(Line);
				if (User.UserName == UserName && User.Password == Password)
				{
					MyFile.close();
					return User;
				}
			}

			MyFile.close();
		}

		return _GetEmptyUserObject();
	}

	enum enSaveResult { svFailedEmptyObject = 0, svSucceeded = 1, svFaildedUserNameExists = 2 };

	enSaveResult Save()
	{
		switch (_Mode)
		{
		case enMode::EmptyMode:
			if (IsEmpty())
			{
				return enSaveResult::svFailedEmptyObject;
			}

		case enMode::UpdateMode:
			_Update();
			return enSaveResult::svSucceeded;
			
		case enMode::AddNewMode:
			if (clsUser::IsUserExist(_UserName))
			{
				return enSaveResult::svFaildedUserNameExists;
			}
			else
			{
				_AddNew();
				// we need to set mode to update after add new
				_Mode = enMode::UpdateMode;
				return enSaveResult::svSucceeded;
			}
		}
	}

	static bool IsUserExist(string UserName)
	{
		clsUser User = clsUser::Find(UserName);

		return(!User.IsEmpty());
	}

	static clsUser GetAddNewUser(string UserName)
	{
		return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
	}

	bool Delete()
	{
		vector <clsUser> vUsers = _LoadUsersDataFromFile();

		for (clsUser& User : vUsers)
		{
			if (User.UserName == _UserName)
			{
				User._MarkedForDelete = true;
				break;
			}
		}

		_SaveUsersDataToFile(vUsers);

		*this = _GetEmptyUserObject();

		return true;
	}

	static vector <clsUser> GetUsersList()
	{
		vector <clsUser> vUsers = _LoadUsersDataFromFile();
		return vUsers;
	}

	bool CheckAccessPermission(enPermissions Permission)
	{
		if (this->Permissions == enPermissions::eAll)
			return true;

		if ((Permission & this->Permissions) == Permission)
			return true;
		else
			return false;
	}
	
	void RegisterLogIn()
	{
		string stDataLine = _PrepareLogInRecord();

		fstream MyFile;
		MyFile.open("Data/LoginRegister.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << stDataLine << endl;
			MyFile.close();
		}
	}

	static vector <clsUser::stLoginRegisterRecord> GetLoginRegisterList()
	{
		vector <clsUser::stLoginRegisterRecord> vLoginRegisterRecord;
		fstream MyFile;

		MyFile.open("Data/LoginRegister.txt", ios::in); //read mode

		if (MyFile.is_open())
		{
			string Line;

			stLoginRegisterRecord LoginRegisterRecord;
		
			while (getline(MyFile, Line))
			{
				LoginRegisterRecord = _ConvertLoginRegisterLineToRecord(Line);
				vLoginRegisterRecord.push_back(LoginRegisterRecord);
			}

			MyFile.close();
		}
		
		return vLoginRegisterRecord;
	}

};

