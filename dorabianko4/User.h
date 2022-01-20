#pragma once
#include <string>

#include "Log.h"
using namespace std;

class User
{
	string userName;
	string userSurname;
	string userLogin;
	string userPassword;

public:
	User() : userName(""), userSurname(""), userLogin(""), userPassword("") {}
	User(string userName, string userSurname, string userLogin, string userPassword): userName(userName),userSurname(userSurname),userLogin(userLogin),userPassword(userPassword){}

	string getUserName() const
	{
		return userName;
	}

	void setUserName(const string& userName)
	{
		this->userName = userName;
	}

	string getUserSurname() const
	{
		return userSurname;
	}

	void setUserSurname(const string& userSurname)
	{
		this->userSurname = userSurname;
	}

	string getUserLogin() const
	{
		return userLogin;
	}

	void setUserLogin(const string& userLogin)
	{
		this->userLogin = userLogin;
	}

	string getUserPassword() const
	{
		return userPassword;
	}

	void setUserPassword(const string& userPassword)
	{
		this->userPassword = userPassword;
	}

	void sendLog(string x = "test call")
	{
		string str = "User     ";
		str.append("login = ");
		str.append(userLogin);
		str.append(" | ");
		str.append(x);
		Log logger(str);
	}
};

