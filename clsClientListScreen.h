#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"

using namespace std;

class clsClientListScreen : protected clsScreen
{
private:

    static void _print_client_record_line(clsBankClient client)
    {

        cout << setw(8) << left << "" << "| " << setw(15) << left << client.get_account_number();
        cout << "| " << setw(20) << left << client.get_full_name();
        cout << "| " << setw(12) << left << client.get_phone();
        cout << "| " << setw(20) << left << client.get_email();
        cout << "| " << setw(10) << left << client.get_pin_code();
        cout << "| " << setw(12) << left << client.get_account_balance();
    }

public:

    static void show_client_list()
    {

        if (!check_access_rights(clsUser::en_permissions::eshow_client_list))
        {
            return;//this will exit the function and it will not continue
        }
        vector <clsBankClient> vclients = clsBankClient::get_client_list();

        string title = "\t  Client List Screen";
        string subtitle = "\t    (" + to_string(vclients.size()) + ") Client(s).";

        _draw_screen_header(title, subtitle);


        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(20) << "Client Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Pin Code";
        cout << "| " << left << setw(12) << "Balance";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vclients.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else
        {
            for (clsBankClient& C : vclients)
            {
                _print_client_record_line(C);
                cout << endl;
            }
        }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }
};

