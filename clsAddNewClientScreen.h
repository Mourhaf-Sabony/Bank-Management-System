#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

using namespace std;

class clsAddNewClientScreen : protected clsScreen
{
private:


    static void _read_client_info(clsBankClient& client)
    {
        cout << "\nenter the first name: ";
        client.set_first_name(clsInputValidate::read_string());

        cout << "\nenter the last name: ";
        client.set_last_name(clsInputValidate::read_string());

        cout << "\nenter the email: ";
        client.set_email(clsInputValidate::read_string());

        cout << "\nenter the phone: ";
        client.set_phone(clsInputValidate::read_string());

        cout << "\nenter the PinCode: ";
        client.set_pin_code(clsInputValidate::read_string());

        cout << "\nenter the account balance: ";
        client.set_account_balance(clsInputValidate::read_float_number());
    }


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


    static void add_new_client()
    {
        _draw_screen_header("\t  Add New Client Screen");


        string account_number = "";
        cout << "\nenter Client account number:";
        account_number = clsInputValidate::read_string();
        while (clsBankClient::is_client_exsist(account_number))
        {
            cout << "\nAccount number is already used, choose another one: ";
            account_number = clsInputValidate::read_string();
        }

        clsBankClient new_client = clsBankClient::get_add_new_client_object(account_number);

        _read_client_info(new_client);

        clsBankClient::ensave_result save_result = new_client.save();

        switch (save_result)
        {
        case clsBankClient::svfaild_empty_object:
            cout << "\nError, account was not saved becuase it's empty\n";
            break;
        case clsBankClient::svfaild_account_number_exists:
            cout << "\nError account was not saved because account number is used!";
        case clsBankClient::svsucceded:
            cout << "\nAccount Added Successfully :-) \n";
            _print_client(new_client);
            break;
        }

    }


};

