#pragma once
#include <fstream>
#include <vector>
#include "Administrator.h"
#include "User.h"
#include "Device.h"
#include "Log.h"
using namespace std;

class DATABASE
{
private:
	float airTemperature;
	float waterTemperature;;
	std::vector<Administrator> administrators;
	std::vector<Device> devices;
	std::vector<User> users;


public:

	DATABASE()
	{
		airTemperature = 0;
		waterTemperature = 0;
		loadAdministrator();
		loadUser();
		loadDevice();
	}

	DATABASE(float airTemperature, float waterTemperature)
	{
		this->airTemperature = airTemperature;
		this->waterTemperature = waterTemperature;
	}

	~DATABASE()
	{
		airTemperature = 0;
		waterTemperature = 0;
	}

	/*

		ADMINISTRATORS FUNCTIONS

	*/

	bool addAdministartor(Administrator adminToAdd) {
		if (sizeAdministrator() <= 0) {
			administrators.push_back(adminToAdd);
			return true;
		}
		else {
			for (int i = 0; i < sizeAdministrator(); i++) {
				if (getAdministartor(i).getUserLogin() == adminToAdd.getUserLogin()) {
					return false;
				}
			}
			administrators.push_back(adminToAdd);
			return true;
		}
		return false;
	}

	bool superAddAdministartor(Administrator adminToAdd) {
		loadAdministrator();
		Log log;
		if (addAdministartor(adminToAdd)) {
			saveAdministrator();
			log.addLog("Administrator has been added.");
			return true;
		}
		saveAdministrator();
		return false;
	}

	bool removeAdministartor(int index) {
		if (administrators.size() > 0 && inRangeAdministartor(index)) {
			administrators.erase(administrators.begin() + index);
			return true;
		}
		return false;
	}

	bool superRemoveAdministartor(int index) {
		Log log;
		loadAdministrator();
		if (removeAdministartor(index)) {
			saveAdministrator();
			log.addLog("Administrator has been removed.");
			return true;
		}
		saveAdministrator();
		return false;
	}

	bool modifyAdministartor(int index, string userName, string userSurname, string userLogin, string userPassword) {
		if (administrators.size() > 0 && inRangeAdministartor(index)) {
			administrators.at(index).setUserName(userName);
			administrators.at(index).setUserSurname(userSurname);
			administrators.at(index).setUserLogin(userLogin);
			administrators.at(index).setUserPassword(userPassword);
			return true;
		}
		return false;
		//przyklad
		//DATABASE.modifyAdministartor(0, "julian", DATABASE.getAdministartor(0).getUserSurname(), DATABASE.getAdministartor(0).getUserLogin(), DATABASE.getAdministartor(0).getUserPassword());
	}

	bool superModifyAdministartor(int index, string userName, string userSurname, string userLogin, string userPassword) {
		Log log;
		loadAdministrator();
		if (modifyAdministartor(index, userName, userSurname, userLogin, userPassword)) {
			saveAdministrator();
			log.addLog("Administrator has been modified.");
			return true;
		}
		saveAdministrator();
		return false;
	}

	bool inRangeAdministartor(int index) {
		if (sizeAdministrator() > 0 && index >= 0 && index < sizeAdministrator()) {
			return true;
		}
		return false;
	}

	Administrator getAdministartor(int index) {
		if (inRangeAdministartor(index)) {
			return administrators.at(index);
		}
		return Administrator("NULL","NULL","NULL","NULL");
	}

	int sizeAdministrator() {
		int size;
		size = administrators.size();
		return size;
	}

	bool saveAdministrator() {

		if (true) {
			ofstream myfile;
			int i = 0;
			myfile.open("administrators.dat");
			if (myfile.is_open())
			{
				for (int i = 0; i < sizeAdministrator(); i++) {
					myfile << i << ";" << stringFormatAdministrator(i) << endl;
				}
			}
			myfile.close();
			return true;
		}
		return false;
	}

	bool loadAdministrator() {

		if (true) {
			ifstream myfile;
			string line;
			int i = 0;
			vector<Administrator> vector;
			myfile.open("administrators.dat");
			while (getline(myfile, line))
			{
				addAdministartor(Administrator(getLinePartition(line)[1], getLinePartition(line)[2], getLinePartition(line)[3], getLinePartition(line)[4]));
			}
			myfile.close();
		}
		return false;
	}

	string stringFormatAdministrator(int index) {
		string str = "";
		str.append(getAdministartor(index).getUserName());
		str.append(";");
		str.append(getAdministartor(index).getUserSurname());
		str.append(";");
		str.append(getAdministartor(index).getUserLogin());
		str.append(";");
		str.append(getAdministartor(index).getUserPassword());
		str.append(";#");
		return str;
	}

	/*

		USERS FUNCTIONS

	*/

	bool addUser(User userToAdd) {
		if (sizeUser() <= 0) {
			users.push_back(userToAdd);
			return true;
		}
		else {
			for (int i = 0; i < sizeUser(); i++) {
				if (getUser(i).getUserLogin() == userToAdd.getUserLogin()) {
					return false;
				}
			}
			users.push_back(userToAdd);
			return true;
		}
		return false;
	}

	bool superAddUser(User userToAdd) {
		Log log;
		loadUser();
		if (addUser(userToAdd)) {
			saveUser();
			log.addLog("User has been added.");
			return true;
		}
		saveUser();
		return false;
	}

	bool removeUser(int index) {
		if (users.size() > 0 && inRangeUser(index)) {
			users.erase(users.begin() + index);
			return true;
		}
		return false;
	}

	bool superRemoveUser(int index) {
		Log log;
		loadUser();
		if (removeUser(index)) {
			saveUser();
			log.addLog("User has been removed.");
			return true;
		}
		saveUser();
		return false;
	}

	bool modifyUser(int index, string userName, string userSurname, string userLogin, string userPassword) {
		
		if (users.size() > 0 && inRangeUser(index)) {
			users.at(index).setUserName(userName);
			users.at(index).setUserSurname(userSurname);
			users.at(index).setUserLogin(userLogin);
			users.at(index).setUserPassword(userPassword);
			return true;
		}
		return false;
	}

	bool superModifyUser(int index, string userName, string userSurname, string userLogin, string userPassword) {
		Log log;
		loadUser();
		if (modifyUser(index, userName, userSurname, userLogin, userPassword)) {
			saveUser();
			log.addLog("User has been modified.");
			return true;
		}
		saveUser();
		return false;
	}

	bool inRangeUser(int index) {
		if (sizeUser() > 0 && index >= 0 && index < sizeUser()) {
			return true;
		}
		return false;
	}

	User getUser(int index) {
		if (inRangeUser(index)) {
			return users.at(index);
		}
		return User("NULL", "NULL", "NULL", "NULL");
	}

	int sizeUser() {
		int size;
		size = users.size();
		return size;
	}

	bool saveUser() {

		if (true) {
			ofstream myfile;
			int i = 0;
			myfile.open("users.dat");
			if (myfile.is_open())
			{
				for (int i = 0; i < sizeUser(); i++) {
					myfile << i << ";" << stringFormatUser(i) << endl;
				}
			}
			myfile.close();
			return true;
		}
		return false;
	}

	bool loadUser() {

		if (true) {
			ifstream myfile;
			string line;
			int i = 0;
			vector<User> vector;
			myfile.open("users.dat");
			while (getline(myfile, line))
			{
				addUser(User(getLinePartition(line)[1], getLinePartition(line)[2], getLinePartition(line)[3], getLinePartition(line)[4]));
			}
			myfile.close();
		}
		return false;
	}

	string stringFormatUser(int index) {
		string str = "";
		str.append(getUser(index).getUserName());
		str.append(";");
		str.append(getUser(index).getUserSurname());
		str.append(";");
		str.append(getUser(index).getUserLogin());
		str.append(";");
		str.append(getUser(index).getUserPassword());
		str.append(";#");
		return str;
	}

	/*

		DEVICES FUNCTIONS

	*/

	bool addDevice(Device deviceToAdd) {
		if (sizeDevice() <= 0) {
			devices.push_back(deviceToAdd);
			return true;
		}
		else {
			for (int i = 0; i < sizeDevice(); i++) {
				if (getDevice(i).getId() == deviceToAdd.getId()) {
					return false;
				}
			}
			devices.push_back(deviceToAdd);
			return true;
		}
		return false;
	}

	bool superAddDevice(Device deviceToAdd) {
		Log log;
		loadDevice();
		if (addDevice(deviceToAdd)) {
			saveDevice();
			log.addLog("Device has been added.");
			return true;
		}
		saveDevice();
		return false;
	}

	bool removeDevice(int index) {
		if (devices.size() > 0 && inRangeDevice(index)) {
			devices.erase(devices.begin() + index);
			return true;
		}
		return false;
	}

	bool superRemoveDevice(int index) {
		Log log;
		loadDevice();
		if (removeDevice(index)) {
			saveDevice();
			log.addLog("Device has been removed.");
			return true;
		}
		saveDevice();
		return false;
	}

	bool modifyDevice(int index, string id, string type, bool state, string* spec) {
		if (sizeDevice() > 0 && inRangeDevice(index)) {
			devices.at(index).setId(id);
			devices.at(index).setType(type);
			devices.at(index).setState(state);
			devices.at(index).setSpec(spec);
			return true;
		}
		return false;
	}

	bool superModifyDevice(int index, string id, string type, bool state, string* spec) {
		Log log;
		loadDevice();
		if (modifyDevice(index, id, type, state, spec)) {
			saveDevice();
			log.addLog("Device has been modified.");
			return true;
		}
		saveDevice();
		return false;
	}

	bool inRangeDevice(int index) {
		if (sizeDevice() > 0 && index >= 0 && index < sizeDevice()) {
			return true;
		}
		return false;
	}

	Device getDevice(int index) {
		if (inRangeDevice(index)) {
			return devices.at(index);
		}
		return Device("NULL",NULL,false);
	}

	int sizeDevice() {
		int size;
		size = devices.size();
		return size;
	}

	bool saveDevice() {
		if (true) {
			ofstream myfile;
			int i = 0;
			myfile.open("devices.dat");
			if (myfile.is_open())
			{
				for (int i = 0; i < sizeDevice(); i++) {
					myfile << i << ";" << stringFormatDevice(i) << endl;
				}
			}
			myfile.close();
			return true;
		}
		return false;
	}

	bool loadDevice() {

		if (true) {
			ifstream myfile;
			string line;
			int i = 0;
			vector<Device> vector;
			myfile.open("devices.dat");
			while (getline(myfile, line))
			{
				string spec[5] = { getLinePartition(line)[4], getLinePartition(line)[5], getLinePartition(line)[6], getLinePartition(line)[7], getLinePartition(line)[8] };
				addDevice(Device(getLinePartition(line)[1], getLinePartition(line)[2], stringToBool(getLinePartition(line)[3]),spec));
			}
			myfile.close();
		}
		return false;
	}

	string stringFormatDevice(int index) {
		string str = "";
		str.append(getDevice(index).getId());
		str.append(";");
		str.append(getDevice(index).getType());
		str.append(";");
		str.append(boolToString(getDevice(index).isState()));
		str.append(";");
		str.append(getDevice(index).getSpec()[0]);
		str.append(";");
		str.append(getDevice(index).getSpec()[1]);
		str.append(";");
		str.append(getDevice(index).getSpec()[2]);
		str.append(";");
		str.append(getDevice(index).getSpec()[3]);
		str.append(";");
		str.append(getDevice(index).getSpec()[4]);
		str.append(";#");
		return str;
	}

	/*
		MULTI FUNCTIONS

		|
		|
		v

	*/

	string* getLinePartition(string line) {
		string* ret = new string[20];
		int x1 = 1;
		int p = 0;
		int wordNumber = 0;
		while (line.substr(x1, 1) != "#") {
			if (line.substr(x1, 1) == ";") {
				if (wordNumber == 0) {
					//cout << line.substr(0, x1) << " ";
					ret[wordNumber] = line.substr(0, x1);
					p = x1;
					wordNumber++;
				}
				else {
					//cout << line.substr(p+1, x1 - p - 1) << " ";
					ret[wordNumber] = line.substr(p + 1, x1 - p - 1);
					p = x1;
					wordNumber++;
				}
			}
			x1++;
		}
		return ret;
	}

	int fileSize(string fileName) {
		int size = 0;
		ifstream myfile;
		string line;
		int i = 0;
		myfile.open("administrators.dat");
		while (getline(myfile, line))
		{
			size++;
		}
		return size;
	}

	bool stringToBool(string str) {
		if (str != "0") {
			return true;
		}
		return false;
	}

	string boolToString(bool state) {
		if (state) {
			return "1";
		}
		return "0";
	}

	string integerToString(int num) {
		return to_string(num);
	}

	int stringToInteger(string str)
	{
		int num = 0;
		for (int i = 0; i < str.length(); i++) {
			num = num * 10 + (str[i] - '0');
		}
		return num;
	}

	float getAirTemperature() const
	{
		return airTemperature;
	}

	void setAirTemperature(float airTemperature)
	{
		this->airTemperature = airTemperature;
	}

	float getWaterTemperature() const
	{
		return waterTemperature;
	}

	void setWaterTemperature(float waterTemperature)
	{
		this->waterTemperature = waterTemperature;
	}

	bool isValidLogin(string login, string password)
	{
		for (int i = 0; i < sizeUser(); i++)
		{
			if (getUser(i).getUserLogin() == login)
			{
				if (getUser(i).getUserPassword() == password)
				{
					return true;
				}
			}
		}
		return false;
	}

	bool checkAdminLogin(string login, string password)
	{
		for (int i = 0; i < sizeAdministrator(); i++)
		{
			if (getAdministartor(i).getUserLogin() == login)
			{
				if (getAdministartor(i).getUserPassword() == password)
				{
					return true;
				}
			}
		}
		return false;
	}

};

