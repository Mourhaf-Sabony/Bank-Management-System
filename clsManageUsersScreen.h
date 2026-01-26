#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"

using namespace std;
class clsManageUsersScreen : protected clsScreen
{
private:

    enum en_manage_users_menue_options {
        elist_users = 1, eadd_new_user = 2, edelete_user = 3,
        eupdate_user = 4, efind_user = 5, emain_menueee = 6
    };


    static short _read_manage_user_menue_option()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short choice = clsInputValidate::read_short_number_between(1, 6, "enter number between 1 to 6");
        return choice;
    }

    static void _show_list_users_screen()
    {
        cout << "\nList User Screen Will Be Here.\n";
    }

    static void _show_add_new_user_screen()
    {
        cout << "\nAdd new User Screen Will Be Here.\n";
    }

    static void _show_delete_user_screen()
    {
        cout << "\nDelete User Screen Will Be Here.\n";
    }

    static void _show_update_user_screen()
    {
        cout << "\nUpdate User Screen Will Be Here.\n";
    }

    static void _show_find_user_screen()
    {
        cout << "\nFind User Screen Will Be Here.\n";
    }


    static void _go_back_to_manage_user_menue()
    {
        cout << "\n\nPress any key to go back to Manage Users Menue...";
        system("pause>0");
        show_manage_user_menue();
    }

    static void _perform_manage_user_menue_option(en_manage_users_menue_options manage_user_menue_optoin)
    {
        switch (manage_user_menue_optoin)
        {
        case clsManageUsersScreen::elist_users:
            system("cls");
            _show_list_users_screen();
            _go_back_to_manage_user_menue();
            break;
        case clsManageUsersScreen::eadd_new_user:
            system("cls");
            _show_add_new_user_screen();
            _go_back_to_manage_user_menue();
            break;
        case clsManageUsersScreen::edelete_user:
            system("cls");
            _show_delete_user_screen();
            _go_back_to_manage_user_menue();
            break;
        case clsManageUsersScreen::eupdate_user:
            system("cls");
            _show_update_user_screen();
            _go_back_to_manage_user_menue();
            break;
        case clsManageUsersScreen::efind_user:
            system("cls");
            _show_find_user_screen();
            _go_back_to_manage_user_menue();
            break;
        default:
            //go back to main menue
            break;
        }
    }

public:

    static void show_manage_user_menue()
    {
        system("cls");
        _draw_screen_header("\t Manage Users Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Manage Users Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Users.\n";
        cout << setw(37) << left << "" << "\t[2] Add New User.\n";
        cout << setw(37) << left << "" << "\t[3] Delete User.\n";
        cout << setw(37) << left << "" << "\t[4] Update User.\n";
        cout << setw(37) << left << "" << "\t[5] Find User.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";


        _perform_manage_user_menue_option((en_manage_users_menue_options)_read_manage_user_menue_option());
    }
};

