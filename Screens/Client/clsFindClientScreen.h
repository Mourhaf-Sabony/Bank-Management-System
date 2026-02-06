#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

using namespace std;
class clsFindClientScreen : protected clsScreen
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

    static void show_find_client_screen()
    {
        if (!check_access_rights(clsUser::en_permissions::efind_client))
        {
            return;//this will exit the function and it will not continue
        }
        _draw_screen_header("\t Find Cient Screen");


        string account_number = "";

        cout << "\nenter the account Number: ";
        account_number = clsInputValidate::read_string();
        while (!clsBankClient::is_client_exsist(account_number))
        {
            cout << "\nAccount number is not found, choose another one: ";
            account_number = clsInputValidate::read_string();
        }

        clsBankClient client1 = clsBankClient::find(account_number);

        if (!client1.is_empty())
            cout << "\nClient Found :-)\n";
        else
            cout << "\nCient Was not Found :-(\n";

        _print_client(client1);
    }
};

