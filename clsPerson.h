#pragma once
#include <iostream>
#include <string>
#include "InterfaceComunication.h"

using namespace std;

class clsPerson : public InterfaceComunication
{
private:
	string _FirstName;
	string _LastName;
	string _Email;
	string _Phone;

public:
	clsPerson(string FirstName, string LastName, string Email, string Phone)
	{
		_FirstName = FirstName;
		_LastName = LastName;
		_Email = Email;
		_Phone = Phone;
	}

	// Propert Set
	void SetFirstName(string FirstName)
	{
		_FirstName = FirstName;
	}

	// Propert Get
	string GetFirstName()
	{
		return _FirstName;
	}

	_declspec(property(get = GetFirstName, put = SetFirstName)) string FirstName;

	// Propert Set
	void SetLastName(string LastName)
	{
		_LastName = LastName;
	}

	// Propert Get
	string GetLastName()
	{
		return _LastName;
	}

	_declspec(property(get = GetLastName, put = SetLastName)) string LastName;

	// Propert Set
	void SetEmail(string Email)
	{
		_Email = Email;
	}

	// Propert Get
	string GetEmail()
	{
		return _Email;
	}

	_declspec(property(get = GetEmail, put = SetEmail)) string Email;

	// Propert Set
	void SetPhone(string Phone)
	{
		_Phone = Phone;
	}

	// Propert Get
	string GetPhone()
	{
		return _Phone;
	}

	_declspec(property(get = GetPhone, put = SetPhone)) string Phone;

	string FullName()
	{
		return _FirstName + " " + _LastName;
	}

	void SendEmail(string Title, string Body)
	{

	}

	void SendFax(string Title, string Body)
	{

	}

	void SendSMS(string Title, string Body)
	{

	}

};