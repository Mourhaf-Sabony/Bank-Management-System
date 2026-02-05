#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "clsString.h"

using namespace std;
class clsCurrency
{
private:

	enum enmode { empty_mode = 0, update_mode = 1 };
	enmode _mode;

	string _country;
	string _currency_code;
	string _currency_name;
	float _rate;

	string _convert_currency_object_to_line(clsCurrency currency, string seperator = "#//#")
	{
		string currency_record = "";
		currency_record += currency.get_country() + seperator;
		currency_record += currency.get_currency_code() + seperator;
		currency_record += currency.get_currency_name() + seperator;
		currency_record += to_string(currency.get_rate());

		return currency_record;
	}

	static clsCurrency _convert_line_to_currency_object(string line, string seperator = "#//#")
	{
		vector <string> vcurrency_data = clsString::split(line, seperator);

		return clsCurrency(enmode::update_mode, vcurrency_data[0], vcurrency_data[1], vcurrency_data[2], stof(vcurrency_data[3]));
	}

	static vector <clsCurrency> _load_currencys_data_from_file()
	{
		vector <clsCurrency> vcurrencys;

		fstream myfile;

		myfile.open("Currencies.txt", ios::in);//read mode

		if (myfile.is_open())
		{
			string line;

			while (getline(myfile, line))
			{
				clsCurrency currency = _convert_line_to_currency_object(line);
				vcurrencys.push_back(currency);
			}
			myfile.close();
		}

		return vcurrencys;
	}

	void _save_currency_data_to_file(vector <clsCurrency> vcurrencys)
	{
		fstream myfile;
		myfile.open("Currencies.txt", ios::out);//overwirte

		if (myfile.is_open())
		{
			string line;

			for (clsCurrency& C : vcurrencys)
			{
				line = _convert_currency_object_to_line(C);
				myfile << line << endl;
			}
			myfile.close();
		}
	}

	void _update()
	{
		vector <clsCurrency> vcurrencys = _load_currencys_data_from_file();

		for (clsCurrency& C : vcurrencys)
		{
			if (C.get_currency_code() == _currency_code)
			{
				C = *this;
				break;
			}
		}

		_save_currency_data_to_file(vcurrencys);

	}

	static clsCurrency _get_empty_currency_object()
	{
		return clsCurrency(enmode::empty_mode, "", "", "", 0.0);
	}

public:

	clsCurrency(enmode mode, string country, string country_code, string currency_name, float rate)
	{
		_mode = mode;
		_country = country;
		_currency_code = country_code;
		_currency_name = currency_name;
		_rate = rate;
	}

	bool is_empty()
	{
		return (_mode == enmode::empty_mode);
	}

	string get_country()
	{
		return _country;
	}

	string get_currency_code()
	{
		return _currency_code;
	}

	string get_currency_name()
	{
		return _currency_name;
	}

	void update_rate(float new_rate)
	{
		_rate = new_rate;
		_update();
	}

	float get_rate()
	{
		return _rate;
	}

	static clsCurrency find_by_code(string currency_code)
	{
		currency_code = clsString::upper_all(currency_code);

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string line;
			while (getline(MyFile, line))
			{
				clsCurrency Currency = _convert_line_to_currency_object(line);
				if (Currency.get_currency_code() == currency_code)
				{
					MyFile.close();
					return Currency;
				}
			}

			MyFile.close();

		}

		return _get_empty_currency_object();
	}

	static clsCurrency find_by_country(string country)
	{
		country = clsString::upper_all(country);

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string line;
			while (getline(MyFile, line))
			{
				clsCurrency Currency = _convert_line_to_currency_object(line);
				if (clsString::upper_all(Currency.get_country()) == country)
				{
					MyFile.close();
					return Currency;
				}
			}

			MyFile.close();

		}

		return _get_empty_currency_object();
	}

	static bool is_currency_exist(string currency_code)
	{
		clsCurrency c = find_by_code(currency_code);
		return (!c.is_empty());
	}

	static vector <clsCurrency> get_currencies_list()
	{
		return _load_currencys_data_from_file();
	}

	float conver_to_usd(float amount)
	{
		return float(amount / get_rate());
	}

	float convert_to_other_currency(float amount, clsCurrency currecny_to)
	{
		return  (currecny_to.get_rate() * float(amount / get_rate()));
	}

};

