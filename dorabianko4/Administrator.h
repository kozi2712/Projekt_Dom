#pragma once
#include "User.h"
class Administrator :
    public User
{
public:
	Administrator() : User()
	{
	}

	Administrator(string userName, string userSurname, string userLogin, string userPassword) : User(userName, userSurname, userLogin, userPassword)
	{
	}

public:

	void editUser(User& user, string userName, string userSurname, string userLogin, string userPassword)
	{
		user.setUserName(userName);
		user.setUserSurname(userSurname);
		user.setUserLogin(userLogin);
		user.setUserPassword(userPassword);
	}

	void sendLog(string x = "test call")
	{
		string str = "Administrator     ";
		str.append("login = ");
		str.append(getUserLogin());
		str.append(" | ");
		str.append(x);
		Log logger(str);
	}
};

