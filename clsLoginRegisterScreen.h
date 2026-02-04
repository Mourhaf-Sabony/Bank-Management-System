#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"

using namespace std;
class clsLoginRegisterScreen : protected clsScreen
{
private:


    static void _print_login_register_record_line(clsUser::stlogin_register_record login_register_record)
    {
        cout << setw(8) << left << "" << "| " << setw(35) << left << login_register_record.date_time;
        cout << "| " << setw(20) << left << login_register_record.user_name;
        cout << "| " << setw(20) << left << login_register_record.password;
        cout << "| " << setw(10) << left << login_register_record.permissions;
    }

public:

    static void show_login_register_screen()
    {
        vector <clsUser::stlogin_register_record> vlogin_register_record = clsUser::get_login_register_list();

        string title = "\t  Login Register List Screen";
        string subtitle = "\t    (" + to_string(vlogin_register_record.size()) + ") Record(s).";

        _draw_screen_header(title, subtitle);


        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(35) << "Date/Time";
        cout << "| " << left << setw(20) << "UserName";
        cout << "| " << left << setw(20) << "Password";
        cout << "| " << left << setw(10) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vlogin_register_record.size() == 0)
            cout << "\t\t\t\tNo Login Register Available In the System!";
        else
        {
            for (clsUser::stlogin_register_record& C : vlogin_register_record)
            {
                _print_login_register_record_line(C);
                cout << endl;
            }
        }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
    }

};

