#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"

using namespace std;

class clsTransactionsScreen : protected clsScreen
{

private:

    enum en_transactions_menue_options {
        edeposit = 1, ewithdraw = 2,
        etotal_balances = 3, emain_menue = 4
    };

    static short _read_transactions_menue_option()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 4]? ";
        short choice = clsInputValidate::read_short_number_between(1, 4, "Enter a Number between 1 to 4? ");
        return choice;

    }

    static void _show_deposit_screen()
    {
        clsDepositScreen::show_deposit_screen();
    }

    static void _show_withdraw_screen()
    {
        clsWithdrawScreen::show_withdraw_screen();
    }

    static void _show_total_balances_screen()
    {
        cout << "\n Total Balances Screen will be here.\n";
    }

    static void _go_back_to_transactions_menue()
    {
        cout << "\n\nPress any key to go back to Transactions Menue...";
        system("pause>0");
        show_transactions_menue();
    }

    static void _perform_transactions_menue_option(en_transactions_menue_options transactions_menue_option)
    {
        switch (transactions_menue_option)
        {
        case clsTransactionsScreen::edeposit:
            system("cls");
            _show_deposit_screen();
            _go_back_to_transactions_menue();
            break;
        case clsTransactionsScreen::ewithdraw:
            system("cls");
            _show_withdraw_screen();
            _go_back_to_transactions_menue();
            break;
        case clsTransactionsScreen::etotal_balances:
            system("cls");
            _show_total_balances_screen();
            _go_back_to_transactions_menue();
            break;
        default:
            break;
        }
    }


public:

    static void show_transactions_menue()
    {
        system("cls");
        _draw_screen_header("\t  Transactions Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Transactions Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
        cout << setw(37) << left << "" << "\t[4] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";


        _perform_transactions_menue_option((en_transactions_menue_options)_read_transactions_menue_option());
    }
};

