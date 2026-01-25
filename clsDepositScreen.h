#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

using namespace std;
class clsDepositScreen : protected clsScreen
{

private:

    static void _print_client(clsBankClient client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << client.get_first_name();
        cout << "\nLastName    : " << client.get_last_name();
        cout << "\nFull Name   : " << client.get_full_name();
        cout << "\nEmail       : " << client.get_email();
        cout << "\nPhone       : " << client.get_phone();
        cout << "\nAcc. Number : " << client.get_account_number();
        cout << "\nPassword    : " << client.get_pin_code();
        cout << "\nBalance     : " << client.get_account_balance();
        cout << "\n___________________\n";

    }

public:

    static void show_deposit_screen()
    {
        _draw_screen_header("\t  Deposit Screen");
        cout << "\nenter Account number:";
        string account_number = clsInputValidate::read_string();

        while (!clsBankClient::is_client_exsist(account_number))
        {
            cout << "\nClient with [" << account_number << "] does not exist.\n";
            account_number = clsInputValidate::read_string();
        }

        clsBankClient client1 = clsBankClient::find(account_number);

        _print_client(client1);

        cout << "\nenter deposit amount?";
        double amount = clsInputValidate::read_dbl_number("enter a number?");

        char answer = 'n';
        cout << "\nAre you sure you want to perform this transaction? ";
        cin >> answer;

        if (toupper(answer) == 'Y')
        {
            client1.deposit(amount);
            cout << "\nAmount Deposited Successfully.\n";
            cout << "\nNew Balance Is: " << client1.get_account_balance();
        }
        else
            cout << "\nOPeration was cancelled.\n";
    }
};

