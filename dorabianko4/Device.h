#pragma once
#include <string>

using namespace std;
class Device
{
	string id;
	string type;
	bool state;
	string* spec;

public:

	Device() : id("NULL"), type("Device"), state(false) { spec = new string[5]; for (int i = 0; i < 5; i++) { spec[i] = "0"; } }

	Device(string id, string type, bool state) : id(id), type(type), state(state) { spec = new string[5]; for (int i = 0; i < 5; i++) { spec[i] = "0"; } }

	Device(string id, string type, bool state, string*specPass) : id(id), type(type), state(state), spec(spec) { spec = new string[5]; for (int i = 0; i < 5; i++) {spec[i] = specPass[i]; } }

	string getId() const
	{
		return id;
	}

	void setId(const string id)
	{
		this->id = id;
	}

	string getType() const
	{
		return type;
	}

	void setType(const string& type)
	{
		this->type = type;
	}

	bool isState() const
	{
		return state;
	}

	void setState(bool state)
	{
		this->state = state;
	}

	string* getSpec() const
	{
		return spec;
	}

	void setSpec(string* specPass)
	{
		for (int i = 0; i < 5; i++) { spec[i] = specPass[i]; }
	}
};

