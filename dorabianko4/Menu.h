#pragma once
#include "DATABASE.h"
class Menu
{
	DATABASE DATABASE;
	bool isAdminActive;

public:

	Menu()
	{
		isAdminActive = false;
		mainMenu();

	}

	bool start()
	{
		addDevice();
		return false;
	}

	bool end()
	{
		int x;
		cin >> x;
		return false;
	}

	bool addDevice()
	{
		string spec[5] = { "0","0","0","0","0" };

		string id;
		cout << "Enter device id:" << endl;
		cin >> id;
		string type;
		cout << "Enter device type:" << endl;
		cin >> type;
		bool state;
		cout << "Enter device state:" << endl;
		cin >> state;
																																	
		if(type == "Device")
		{
			
		}
		else if (type == "Gate")
		{

		}
		else if (type == "AirConditioning")
		{
			string  airTemperature;
			cout << "Enter air temperature:" << endl;
			cin >> airTemperature;
			spec[0] = airTemperature;
		}
		else if (type == "Camera")
		{
			string  cameraNumber;
			cout << "Enter camera number:" << endl;
			cin >> cameraNumber;
			spec[0] = cameraNumber;
		}
		else if (type == "Fridge")
		{
			string fridgeTemperature;
			string freezerTemperature;
			cout << "Enter fridge temperature:" << endl;
			cin >> fridgeTemperature;
			spec[0] = fridgeTemperature;
			cout << "Enter freezer temperature:" << endl;
			cin >> freezerTemperature;
			spec[1] = freezerTemperature;
		}
		else if (type == "Furnace")
		{
			string waterTemperature;
			string airTemperature;
			cout << "Enter water temperature:" << endl;
			cin >> waterTemperature;
			spec[0] = waterTemperature;
			cout << "Enter air temperature:" << endl;
			cin >> airTemperature;
			spec[1] = airTemperature;
		}
		else if (type == "Lighting")
		{
			string  roomId;
			cout << "Enter room id:" << endl;
			cin >> roomId;
			spec[0] = roomId;
		}
		else if (type == "Oven")
		{
			string temperature;
			string time;
			string selectMode;
			cout << "Enter temperature:" << endl;
			cin >> temperature;
			spec[0] = temperature;
			cout << "Enter time:" << endl;
			cin >> time;
			spec[1] = time;
			cout << "Enter selectMode:" << endl;
			cin >> selectMode;
			spec[2] = selectMode;
		}
		else if (type == "RollerBlinds")
		{
			string  roomId;
			cout << "Enter room id:" << endl;
			cin >> roomId;
			spec[0] = roomId;
		}
		else
		{
			
		}

		if(true)
		{
			DATABASE.superAddDevice(Device(id, type, state, spec));
			return true;
		}
		return false;
	}

	bool removeDevice()
	{
		int index;
		cout << "Enter index: ";
		cin >> index;
		return DATABASE.superRemoveDevice(index);
	}

	bool deviceList()
	{
		for (int i = 0 ; i < DATABASE.sizeDevice(); i++)
		{
			cout << i << "). " << "id = " << DATABASE.getDevice(i).getId() << " type = " << DATABASE.getDevice(i).getType() << " state = " << DATABASE.getDevice(i).isState();
			if (DATABASE.getDevice(i).getType() == "Device")
			{
				
			}
			else if (DATABASE.getDevice(i).getType() == "Gate")
			{
				
			}
			else if(DATABASE.getDevice(i).getType() == "AirConditioning")
			{
				cout << " airTemperature = " << DATABASE.getDevice(i).getSpec()[0];
			}
			else if (DATABASE.getDevice(i).getType() == "Camera")
			{
				cout << " cameraNumber = " << DATABASE.getDevice(i).getSpec()[0];
			}
			else if (DATABASE.getDevice(i).getType() == "Fridge")
			{
				cout << " fridgeTemperature = " << DATABASE.getDevice(i).getSpec()[0] << " freezerTemperature = " << DATABASE.getDevice(i).getSpec()[1];
			}
			else if (DATABASE.getDevice(i).getType() == "Furnace")
			{
				cout << " waterTemperature = " << DATABASE.getDevice(i).getSpec()[0] << " airTemperature = " << DATABASE.getDevice(i).getSpec()[1];
			}
			else if (DATABASE.getDevice(i).getType() == "Lighting")
			{
				cout << " roomId = " << DATABASE.getDevice(i).getSpec()[0];
			}
			else if (DATABASE.getDevice(i).getType() == "Oven")
			{
				cout << " temperature = " << DATABASE.getDevice(i).getSpec()[0] << " time = " << DATABASE.getDevice(i).getSpec()[1] << " selectMode = " << DATABASE.getDevice(i).getSpec()[2];
			}
			else if (DATABASE.getDevice(i).getType() == "RollerBlinds")
			{
				cout << " roomId = " << DATABASE.getDevice(i).getSpec()[0];
			}
			else
			{
				
			}

			cout << endl;
		}
		return false;
	}

	bool modifyDevice()
	{
		string spec[5] = { "0","0","0","0","0" };

		int index;
		cout << "Enter device index, that you want to change: ";
		cin >> index;
		if(DATABASE.inRangeDevice(index))
		{
			string id;
			cout << "Enter new id: ";
			cin >> id;
			bool state;
			cout << "Enter new state: ";
			cin >> state;
			if (DATABASE.getDevice(index).getType() == "Device")
			{
				DATABASE.superModifyDevice(index, id, "Device", state, spec);
			}
			else if (DATABASE.getDevice(index).getType() == "Gate")
			{
				DATABASE.superModifyDevice(index, id, "Gate", state, spec);
			}
			else if (DATABASE.getDevice(index).getType() == "AirConditioning")
			{
				string option;
				cout << "Enter new air temperature: ";
				cin >> option;
				spec[0] = option;
				DATABASE.superModifyDevice(index, id, "AirConditioning", state, spec);
			}
			else if (DATABASE.getDevice(index).getType() == "Camera")
			{
				string option;
				cout << "Enter new camera number: ";
				cin >> option;
				spec[0] = option;
				DATABASE.superModifyDevice(index, id, "Camera", state, spec);
			}
			else if (DATABASE.getDevice(index).getType() == "Fridge")
			{
				string option1;
				cout << "Enter new fridge temperature: ";
				cin >> option1;
				spec[0] = option1;
				string option2;
				cout << "Enter new freezer temperature: ";
				cin >> option2;
				spec[1] = option2;
				DATABASE.superModifyDevice(index, id, "Fridge", state, spec);
			}
			else if (DATABASE.getDevice(index).getType() == "Furnace")
			{
				string option1;
				cout << "Enter new water temperature: ";
				cin >> option1;
				spec[0] = option1;
				string option2;
				cout << "Enter new air temperature: ";
				cin >> option2;
				spec[1] = option2;
				DATABASE.superModifyDevice(index, id, "Furnace", state, spec);
			}
			else if (DATABASE.getDevice(index).getType() == "Lighting")
			{
				string option;
				cout << "Enter new room Id: ";
				cin >> option;
				spec[0] = option;
				DATABASE.superModifyDevice(index, id, "Lighting", state, spec);
			}
			else if (DATABASE.getDevice(index).getType() == "Oven")
			{
				string option1;
				cout << "Enter new water temperature: ";
				cin >> option1;
				spec[0] = option1;
				string option2;
				cout << "Enter new time: ";
				cin >> option2;
				spec[1] = option2;
				string option3;
				cout << "Enter new select mode: ";
				cin >> option3;
				spec[2] = option3;
				DATABASE.superModifyDevice(index, id, "Oven", state, spec);
			}
			else if (DATABASE.getDevice(index).getType() == "RollerBlinds")
			{
				string option;
				cout << "Enter new room Id: ";
				cin >> option;
				spec[0] = option;
				DATABASE.superModifyDevice(index, id, "RollerBlinds", state, spec);
			}
			else
			{
				
			}
			return true;
		}
		return false;
	}

	bool login()
	{
		Log log;
		string login;
		cout << "Enter login :";
		cin >> login;
		string password;
		cout << "Enter password :";
		cin >> password;

		if(DATABASE.isValidLogin(login,password))
		{
			isAdminActive = DATABASE.checkAdminLogin(login, password);
			string str = "User ";
			str.append(login);
			str.append(" logged in.");
			log.addLog(str);
			return true;
		}
		return false;
	}

	bool userList()
	{
		for ( int i = 0 ;i < DATABASE.sizeUser(); i++)
		{
			cout << i << "). userName = " << DATABASE.getUser(i).getUserName() << " userSurname = " << DATABASE.getUser(i).getUserSurname() << " userLogin = " << DATABASE.getUser(i).getUserLogin();
			cout << endl;
		}
		return true;
	}

	bool administatotsList()
	{
		for (int i = 0; i < DATABASE.sizeAdministrator(); i++)
		{
			cout << i << "). userName = " << DATABASE.getUser(i).getUserName() << " userSurname = " << DATABASE.getUser(i).getUserSurname() << " userLogin = " << DATABASE.getUser(i).getUserLogin();
			cout << endl;
		}
		return true;
	}

	bool registeR()
	{
		string userName;
		cout << "Enter name: ";
		cin >> userName;
		string userSurname;
		cout << "Enter surname: ";
		cin >> userSurname;
		string login;
		cout << "Enter login: ";
		cin >> login;
		string password;
		cout << "Enter password: ";
		cin >> password;
		if (checkString(login) && checkString(password) && checkString(userName) && checkString(userSurname));
		{
			return DATABASE.superAddUser(User(userName, userSurname, login, password));
		}
		return false;
	}

	bool modifyUser()
	{
		int index;
		cout << "Enter index: ";
		cin >> index;
		string userName;
		cout << "Enter new name: ";
		cin >> userName;
		string userSurname;
		cout << "Enter new surname: ";
		cin >> userSurname;
		string password;
		cout << "Enter new password: ";
		cin >> password;
		return DATABASE.superModifyUser(index, userName, userSurname, DATABASE.getUser(index).getUserLogin(),password);
	}

	bool removeUser()
	{
		int index;
		cout << "Enter index: ";
		cin >> index;
		return DATABASE.superRemoveUser(index);
	}

	void mainMenu()
	{
		bool quit = false;
		int option = NULL;
		while (!quit)
		{
			switch (option)
			{
			case 1:
				if(login())
				{
					mainOptions();
				}
				option = NULL;
				break;
			case 2:
				registeR();
				option = NULL;
				break;
			case 3:
				quit = true;
				option = NULL;
				break;

			default:
				system("cls");
	
				cout << "1. Login" << endl;
				cout << "2. Register" << endl;
				cout << "3. Exit" << endl;
				cout << endl;
				cout << "Enter option: ";
				cin >> option;
				system("cls");
				break;
			}
		}
	}

	void mainOptions()
	{
		bool quit = false;
		int option = NULL;
		while (!quit)
		{
			switch (option)
			{
			case 1:
				deviceMenu();
				option = NULL;
				break;
			case 2:
				userMenu();
				option = NULL;
				break;
			case 3:
				administratorMenu();
				option = NULL;
				break;
			case 4:
				quit = true;
				option = NULL;
				break;

			default:
				system("cls");

				cout << "1. Devices" << endl;
				cout << "2. Users" << endl;
				cout << "3. Admins" << endl;
				cout << "4. Exit" << endl;
				cout << endl;
				cout << "Enter option: ";
				cin >> option;
				system("cls");
				break;
			}
		}
	}

	void deviceMenu()
	{
		bool quit = false;
		int option = NULL;
		while (!quit)
		{
			switch (option)
			{
			case 1:
				deviceList();
				addDevice();
				option = NULL;
				break;
			case 2:
				deviceList();
				removeDevice();
				option = NULL;
				break;
			case 3:
				deviceList();
				modifyDevice();
				option = NULL;
				break;
			case 4:
				listDevicesGG();
				option = NULL;
				break;
			case 5:
				quit = true;
				option = NULL;
				break;

			default:
				system("cls");
				cout << "1. Add" << endl;
				cout << "2. Remove" << endl;
				cout << "3. Modify" << endl;
				cout << "4. List" << endl;
				cout << "5. Exit" << endl;
				cout << endl;
				cout << "Enter option: ";
				cin >> option;
				system("cls");
				break;
			}
		}
	}

	void listDevicesGG()
	{
		bool quit = false;
		int option = NULL;
		while (!quit)
		{
			switch (option)
			{
			case 1:
				quit = true;
				option = NULL;
				break;

			default:
				system("cls");
				deviceList();
				cout << "1. Exit" << endl;
				cout << "Enter option: ";
				cin >> option;
				system("cls");
				break;
			}
		}
	}

	void listUsersGG()
	{
		bool quit = false;
		int option = NULL;
		while (!quit)
		{
			switch (option)
			{
			case 1:
				quit = true;
				option = NULL;
				break;

			default:
				system("cls");
				userList();
				cout << "1. Exit" << endl;
				cout << "Enter option: ";
				cin >> option;
				system("cls");
				break;
			}
		}
	}

	void userMenu()
	{
		bool quit = false;
		int option = NULL;
		while (!quit)
		{
			switch (option)
			{
			case 1:
				if(isAdminActive)
				{
					registeR();
				}
				option = NULL;
				break;
			case 2:
				if (isAdminActive)
				{
					userList();
					removeUser();
				}
				option = NULL;
				break;
			case 3:
				if (isAdminActive)
				{
					userList();
					modifyUser();
				}
				option = NULL;
				break;
			case 4:
				listUsersGG();
				option = NULL;
				break;
			case 5:
				quit = true;
				option = NULL;
				break;

			default:
				system("cls");
				cout << "1. Add" << endl;
				cout << "2. Remove" << endl;
				cout << "3. Modify" << endl;
				cout << "4. List" << endl;
				cout << "5. Exit" << endl;
				cout << endl;
				cout << "Enter option: ";
				cin >> option;
				system("cls");
				break;
			}
		}
	}

	void administratorMenu()
	{
		bool quit = false;
		int option = NULL;
		while (!quit)
		{
			switch (option)
			{
			case 1:
				if (isAdminActive)
				{
					listAdminsGG();
				}
				option = NULL;
				break;
			case 2:
				quit = true;
				option = NULL;
				break;

			default:
				system("cls");
				cout << "1. List" << endl;
				cout << "2. Exit" << endl;
				cout << endl;
				cout << "Enter option: ";
				cin >> option;
				system("cls");
				break;
			}
		}
	}
	void listAdminsGG()
	{
		bool quit = false;
		int option = NULL;
		while (!quit)
		{
			switch (option)
			{
			case 1:
				quit = true;
				option = NULL;
				break;

			default:
				system("cls");
				administatotsList();
				cout << "1. Exit" << endl;
				cout << "Enter option: ";
				cin >> option;
				system("cls");
				break;
			}
		}
	}

	bool checkString(string str) {
		string x = "";
		for (int i = 0; i < str.length(); i++) {
			x = str.substr(i, 1);
			if (x == "#" || x == " " || x == ";") {
				return false;
			}
		}
		return true;
	}
};

