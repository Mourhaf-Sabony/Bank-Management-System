#pragma once
#include <iostream>
#include <string>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

using namespace std;
class clsCurrencyCalculatorScreen : protected clsScreen
{
private:

	static void _print_currency(clsCurrency currency, string title = "Currency Card:")
	{
		cout << "\n" << title << "\n";
		cout << "\n___________________";
		cout << "\nCountry    : " << currency.get_country();
		cout << "\ncode       : " << currency.get_currency_code();
		cout << "\nName       : " << currency.get_currency_name();
		cout << "\nRate(1$) = : " << currency.get_rate();
		cout << "\n___________________\n";

	}

	static clsCurrency _get_currency(string massege)
	{
		string currency_code = "";

		cout << massege << endl;
		currency_code = clsInputValidate::read_string();

		while (!clsCurrency::is_currency_exist(currency_code))
		{
			cout << "\nCurrency is not found, choose another one: ";
			currency_code = clsInputValidate::read_string();
		}

		clsCurrency currency = clsCurrency::find_by_code(currency_code);

		return currency;
	}

	static void _print_result_of_calculate(float amount, clsCurrency currency_from, clsCurrency currency_to)
	{
		if (currency_to.get_currency_code() == "USD")
		{
			_print_currency(currency_from, "Convert From:");

			cout << fixed << setprecision(2) << "\n" << amount << " " << currency_from.get_currency_code() << " = " << currency_from.convert_to_other_currency(amount, currency_to) << " " << currency_to.get_currency_code();
		}
		else if (currency_from.get_currency_code() == "USD")
		{
			_print_currency(currency_to, "Convert To:");

			cout << fixed << setprecision(2) << "\n" << amount << " " << currency_from.get_currency_code() << " = " << currency_from.convert_to_other_currency(amount, currency_to) << " " << currency_to.get_currency_code();
		}
		else
		{
			_print_currency(currency_from, "Convert From:");


			cout << fixed << setprecision(2) << "\n" << amount << " " << currency_from.get_currency_code() << " = " << currency_from.conver_to_usd(amount) << " USD";

			_print_currency(currency_to, "Convert USD To:");


			cout << fixed << setprecision(2) << "\n" << amount << " " << currency_from.get_currency_code() << " = " << currency_from.convert_to_other_currency(amount, currency_to) << " " << currency_to.get_currency_code();

		}
	}
public:

	static void show_currency_caculator_screen()
	{

		char answer = 'Y';
		while (toupper(answer) == 'Y')
		{
			system("cls");
			_draw_screen_header("\t Currency Calculator Screen");

			clsCurrency currency_form = _get_currency("\nEnter Currency1 code: ");
			clsCurrency currency_to = _get_currency("\nEnter Currency2 code: ");

			cout << "\nEnter Amount to Exchange: ";
			float amount = clsInputValidate::read_float_number();

			_print_result_of_calculate(amount, currency_form, currency_to);

			cout << "\n\nDo you want to perform another calculation? y/n?";
			cin >> answer;
		}

	}

};

