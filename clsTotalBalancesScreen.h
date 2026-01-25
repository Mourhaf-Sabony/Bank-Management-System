#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsUtil.h"

using namespace std;
class clsTotalBalancesScreen : protected clsScreen
{
private:

    static void print_client_record_balance_line(clsBankClient client)
    {
        cout << setw(25) << left << "" << "| " << setw(15) << left << client.get_account_number();
        cout << "| " << setw(40) << left << client.get_full_name();
        cout << "| " << setw(12) << left << client.get_account_balance();
    }

public:


    static void show_total_balances()
    {
        vector <clsBankClient> vclients = clsBankClient::get_client_list();

        string title = "\t  Balances List Screen";
        string sub_title = "\t    (" + to_string(vclients.size()) + ") Client(s).";

        _draw_screen_header(title, sub_title);

        cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
        cout << "__________________________\n" << endl;

        cout << setw(25) << left << "" << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(40) << "Client Name";
        cout << "| " << left << setw(12) << "Balance";
        cout << setw(25) << left << "" << "\t\t_______________________________________________________";
        cout << "__________________________\n" << endl;

        double total_balances = clsBankClient::total_balances();

        if (vclients.size() == 0)
        {
            cout << "\t\t\t\tNo Clients Available In the System!";
        }
        else
        {
            for (clsBankClient& C : vclients)
            {
                print_client_record_balance_line(C);
                cout << endl;
            }
        }
        cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
        cout << "__________________________\n" << endl;

        cout << setw(8) << left << "" << "\t\t\t\t\t\t    Total Balances = " << total_balances << endl;
        cout << setw(8) << left << "" << "\t\t\t\t  ( " << clsUtil::number_to_text(total_balances) << ")";
    }


};

