#pragma once
#include <iostream>
#include <fstream>
#include <ctime>
#include <string>

using namespace std;

//FINSHED
class Log
{
public:
	Log() = default;

	Log(string input)
	{
            string output = "Logger | ";
            output.append(input);
            ofstream out;
            ifstream in;
            in.open("log.dat");
            out.open("log.dat", ios::app);

            if (in.is_open())
            {
                out << output.append("\n");
            }

            in.close();
            out.close();
	}


	void showLog()
    {
        ifstream in;
        string str;
        in.open("log.dat");
        if (in.is_open())
        {
            while (in.good())
            {
                getline(in, str);
                std::cout << str << endl;
            }
        }
    }

    static void addLog(string input)
    {
        string output = "Logger | ";
        output.append(input);
        ofstream out;
        ifstream in;
        in.open("log.dat");
        out.open("log.dat", ios::app);

        if (in.is_open())
        {
            out << output.append("\n");
        }

        in.close();
        out.close();
    }
};