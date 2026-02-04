#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"

using namespace std;
class clsTransferLogScreen : protected clsScreen
{
private:

    static void _print_transfer_log_record_line(clsBankClient::sttransfer_log_record transfer_log_record)
    {
        cout << setw(8) << left << "" << "| " << setw(25) << left << transfer_log_record.date_time;
        cout << "| " << setw(10) << left << transfer_log_record.source_account_number;
        cout << "| " << setw(10) << left << transfer_log_record.destination_account_number;
        cout << "| " << setw(10) << left << transfer_log_record.amount;
        cout << "| " << setw(10) << left << transfer_log_record.src_balance_after;
        cout << "| " << setw(10) << left << transfer_log_record.dest_balance_after;
        cout << "| " << setw(10) << left << transfer_log_record.user_name;
    }

public:

    static void show_transfer_log_screen()
    {

        vector <clsBankClient::sttransfer_log_record> vtransfer_log_record = clsBankClient::get_transfer_log_list();

        string title = "\t  Transfer Log List Screen";
        string subtitle = "\t    (" + to_string(vtransfer_log_record.size()) + ") Record(s).";

        _draw_screen_header(title, subtitle);


        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(25) << "Date/Time";
        cout << "| " << left << setw(10) << "s.Acct";
        cout << "| " << left << setw(10) << "d.Acct";
        cout << "| " << left << setw(10) << "Amount";
        cout << "| " << left << setw(10) << "s.Balance";
        cout << "| " << left << setw(10) << "d.Balance";
        cout << "| " << left << setw(10) << "User";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vtransfer_log_record.size() == 0)
            cout << "\t\t\t\tNo Transfer Log Available In the System!";
        else
        {
            for (clsBankClient::sttransfer_log_record& C : vtransfer_log_record)
            {
                _print_transfer_log_record_line(C);
                cout << endl;
            }
        }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
    }
};

