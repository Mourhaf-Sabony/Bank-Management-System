#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsCurrency.h"

using namespace std;
class clsListCurrenciesScreen : protected clsScreen
{

private:


    static void _print_currency_record_line(clsCurrency currency)
    {

        cout << setw(8) << left << "" << "| " << setw(30) << left << currency.get_country();
        cout << "| " << setw(8) << left << currency.get_currency_code();
        cout << "| " << setw(45) << left << currency.get_currency_name();
        cout << "| " << setw(10) << left << currency.get_rate();
    }

public:

    static void show_currencies_list()
    {

        vector <clsCurrency> vcurrencies = clsCurrency::get_currencies_list();

        string title = "\t  Currencies List Screen";
        string subtitle = "\t    (" + to_string(vcurrencies.size()) + ") Currency.";

        _draw_screen_header(title, subtitle);


        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
        cout << "| " << left << setw(8) << "code";
        cout << "| " << left << setw(45) << "Name";
        cout << "| " << left << setw(10) << "Rates/(1$)";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vcurrencies.size() == 0)
            cout << "\t\t\t\tNo Currencies Available In the System!";
        else
        {
            for (clsCurrency& C : vcurrencies)
            {
                _print_currency_record_line(C);
                cout << endl;
            }
        }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }
};

