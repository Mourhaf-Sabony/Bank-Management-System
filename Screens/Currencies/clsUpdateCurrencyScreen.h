#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrency.h"

using namespace std;
class clsUpdateCurrencyScreen : protected clsScreen
{
private:

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

public:

	static void show_update_rate_screen()
	{
		_draw_screen_header("\t Update currency Screen");

		string currency_code = "";

		cout << "\nEnter Currency code: ";
		currency_code = clsInputValidate::read_string();

		while (!clsCurrency::is_currency_exist(currency_code))
		{
			cout << "\nCurrency is not found, choose another one: ";
			currency_code = clsInputValidate::read_string();
		}

		clsCurrency currency = clsCurrency::find_by_code(currency_code);
		_print_currency(currency);

		cout << "\nAre you sure you want to update the rate of this currency y/n?";

		char answer = 'n';
		cin >> answer;

		if (toupper(answer) == 'Y')
		{
			cout << "\n\nUpdate Currency Rate: ";
			cout << "\n________________________\n";

			cout << "\nEnter New Rate: ";
			float new_rate = clsInputValidate::read_number<float>();

			currency.update_rate(new_rate);

			cout << "\nCurrency Rate Updated Successfully :-) \n";

			_print_currency(currency);
		}
	}
};

