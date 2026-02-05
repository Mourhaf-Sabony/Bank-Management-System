#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"

using namespace std;
class clsFindCurrencyScreen : protected clsScreen
{
private:

	enum enfind_currency_option { ecode = 1, ecountry = 2 };


	static short _read_find_currency_option()
	{
		cout << "Find By: [1] Code or [2] Country ?";
		short choice = clsInputValidate::read_short_number_between(1, 2, "Enter [1] Code or [2] Country ?");
		return choice;
	}

	static void _print_currency(clsCurrency currency)
	{
		cout << "\nCurrency Card:";
		cout << "\n___________________";
		cout << "\nCountry    : " << currency.get_country();
		cout << "\ncode       : " << currency.get_currency_code();
		cout << "\nName       : " << currency.get_currency_name();
		cout << "\nRate(1$) = : " << currency.get_rate();
		cout << "\n___________________\n";

	}

	static void _show_result(clsCurrency currency)
	{

		if (!currency.is_empty())
		{
			cout << "\nCurrency Found :-)\n";
			_print_currency(currency);
		}
		else
			cout << "\nCurrency Was not Found :-(\n";


	}


public:

	static void show_find_currency_screen()
	{
		_draw_screen_header("\t Find Currency Screen");

		enfind_currency_option choice = (enfind_currency_option)_read_find_currency_option();

		if (choice == enfind_currency_option::ecode)
		{
			cout << "\nEnter Currency Code: ";
			string currency_code = clsInputValidate::read_string();
			clsCurrency currency = clsCurrency::find_by_code(currency_code);
			_show_result(currency);
		}
		else if (choice == enfind_currency_option::ecountry)
		{
			cout << "\nEnter Country Name: ";
			string country = clsInputValidate::read_string();
			clsCurrency currency = clsCurrency::find_by_country(country);
			_show_result(currency);
		}

	}
};

