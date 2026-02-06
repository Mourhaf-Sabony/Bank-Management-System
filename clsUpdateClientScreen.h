#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"

using namespace std;

class clsUpdateClientScreen : protected clsScreen
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
        client.set_account_balance(clsInputValidate::read_number<float>());
    }

public:

    static void show_update_client_screen()
    {
        if (!check_access_rights(clsUser::en_permissions::eupdate_client_info))
        {
            return;//this will exit the function and it will not continue
        }
        _draw_screen_header("\t Update Client Screen");
        string account_number = "";

        cout << "\nenter Client Account Number: ";
        account_number = clsInputValidate::read_string();
        while (!clsBankClient::is_client_exsist(account_number))
        {
            cout << "\nAccount number is not found, choose another one: ";
            account_number = clsInputValidate::read_string();
        }

        clsBankClient client1 = clsBankClient::find(account_number);
        _print_client(client1);

        cout << "\nAre you sure you want to update this client y/n?";

        char answer = 'n';
        cin >> answer;

        if (toupper(answer) == 'Y')
        {
            cout << "\n\nUpdate client Info: ";
            cout << "\n________________________\n";

            _read_client_info(client1);

            clsBankClient::ensave_result save_result = client1.save();

            switch (save_result)
            {
            case clsBankClient::svfaild_empty_object:
                cout << "\nError, account was not saved becuase it's empty\n";
                break;
            case clsBankClient::svsucceded:
                cout << "\nAccount Updated Successfully :-) \n";
                break;
            default:
                break;
            }

        }
        

    }


};
