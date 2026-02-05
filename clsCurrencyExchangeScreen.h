#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsListCurrenciesScreen.h"

using namespace std;
class clsCurrencyExchangeScreen : protected clsScreen
{
private:

    enum encurrency_exchange_options {
        elist_currencies = 1, efind_currency = 2, eupdate_rate = 3, ecurrency_calculator = 4, emain_menue = 5
    };

    static short _read_currency_exchange_option()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5] ";
        short choice = clsInputValidate::read_short_number_between(1, 5, "Enter number between 1 to 5?");
        return choice;
    }

    static void _go_back_to_currencies_menue()
    {
        cout << setw(37) << left << "" << "\n\tPress Any key to go back to Currencies Menue...\n";
        system("pause>0");
        show_currencies_menue();
    }

    static void _show_list_currencies_screen()
    {
        clsListCurrenciesScreen::show_currencies_list();
    }

    static void _show_find_currency_screen()
    {
        cout << "Find Currency Will Be Here.....\n";
    }

    static void _show_update_rate_screen()
    {
        cout << "Update Rate Will Be Here.....\n";
    }

    static void _show_currecny_calculator_screen()
    {
        cout << "Currency Calculator Will Be Here.....\n";
    }



    static void _perform_currency_exhange_option(encurrency_exchange_options currency_exchange_option)
    {
        switch (currency_exchange_option)
        {
        case clsCurrencyExchangeScreen::elist_currencies:
            system("cls");
            _show_list_currencies_screen();
            _go_back_to_currencies_menue();
            break;
        case clsCurrencyExchangeScreen::efind_currency:
            system("cls");
            _show_find_currency_screen();
            _go_back_to_currencies_menue();
            break;
        case clsCurrencyExchangeScreen::eupdate_rate:
            system("cls");
            _show_update_rate_screen();
            _go_back_to_currencies_menue();
            break;
        case clsCurrencyExchangeScreen::ecurrency_calculator:
            system("cls");
            _show_currecny_calculator_screen();
            _go_back_to_currencies_menue();
            break;
        default:
            break;
        }
    }

public:


    static void show_currencies_menue()
    {
        if (!check_access_rights(clsUser::en_permissions::ecurrency_exchange))
        {
            return;//this will exit the function and it will not continue
        }
        system("cls");
        _draw_screen_header("\tCurrency Exchange Main Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\tCurrency exchange Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _perform_currency_exhange_option((encurrency_exchange_options)_read_currency_exchange_option());

    }
};

