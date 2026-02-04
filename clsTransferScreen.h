#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "Global.h"

using namespace std;
class clsTransferScreen : protected clsScreen
{
private:


    static void _print_client(clsBankClient client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFull Name   : " << client.get_full_name();
        cout << "\nAcc. Number : " << client.get_account_number();
        cout << "\nBalance     : " << client.get_account_balance();
        cout << "\n___________________\n";

    }

public:

    static void _show_transfer_screen()
    {
        _draw_screen_header("\t  Transfer Screen");

        cout << "\nEnter Account Number to Transfer From: ";
        string account_number1 = clsInputValidate::read_string();

        while (!clsBankClient::is_client_exsist(account_number1))
        {
            cout << "\nClient with [" << account_number1 << "] does not exist.Enter again:";
            account_number1 = clsInputValidate::read_string();
        }

        clsBankClient source_client = clsBankClient::find(account_number1);

        _print_client(source_client);


        cout << "\nEnter Account Number to Transfer To: ";
        string account_number2 = clsInputValidate::read_string();

        while (!clsBankClient::is_client_exsist(account_number2))
        {
            cout << "\nClient with [" << account_number2 << "] does not exist.Enter again\n";
            account_number2 = clsInputValidate::read_string();
        }

        clsBankClient destination_client = clsBankClient::find(account_number2);

        _print_client(destination_client);

        cout << "\nEnter Transfer Amount?";
        double amount = clsInputValidate::read_dbl_number("enter a number?");

        while (amount > source_client.get_account_balance())
        {
            cout << "\nAmount Exceeds the available Balance, Enter another Amount? ";
            amount = clsInputValidate::read_dbl_number("enter a number?");
        }

        char answer = 'n';
        cout << "\nAre you sure you want to perform this transaction? y/n?";
        cin >> answer;

        if (toupper(answer) == 'Y')
        {
            if (source_client.transfer(amount, destination_client, current_user.get_user_name()))
            {
                cout << "\nAmount Withdrew Successfully.\n";
            }
            else
                cout << "\nTransfer Faild\n";

            _print_client(source_client);
            _print_client(destination_client);
        }
        else
            cout << "\nOPeration was cancelled.\n";
    }
};

