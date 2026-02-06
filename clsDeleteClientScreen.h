#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

using namespace std;

class clsDeleteClientScreen : protected clsScreen
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


    static void show_delete_client_screen()
    {

        if (!check_access_rights(clsUser::en_permissions::edelete_client_info))
        {
            return;//this will exit the function and it will not continue
        }
        _draw_screen_header("\t Delete Client Screen");

        string account_number = "";

        cout << "\nenter the account Number: ";
        account_number = clsInputValidate::read_string();
        while (!clsBankClient::is_client_exsist(account_number))
        {   
            cout << "\nAccount number is not found, choose another one: ";
            account_number = clsInputValidate::read_string();
        }

        clsBankClient client1 = clsBankClient::find(account_number);
        _print_client(client1);

        cout << "\nAre you sure you want to delete this client y/n?";
        char answer = 'n';
        cin >> answer;

        if (toupper(answer) == 'Y')
        {
            if (client1.Delete())
            {
                cout << "\nClient Deleted Successfully :-)";
                _print_client(client1);
            }
            else
                cout << "\nError, Client Was not Deleted";
        }

    }
};

