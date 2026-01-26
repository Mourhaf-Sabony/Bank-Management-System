#pragma once
#include <iostream>
#include <iomanip>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsManageUsersScreen.h"


using namespace std;


class clsMainScreen : protected clsScreen
{
private:


    enum enmain_menue_options {
        eshow_client_list = 1, eadd_new_client = 2,
        edelete_client_info = 3, eupdate_client_info = 4,
        efind_client = 5, etransactions = 6, emanage_users = 7, eexit = 8
    };

    static short _read_main_menue_option()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 8] ";
        short choice = clsInputValidate::read_short_number_between(1, 8, "Enter number between 1 to 8?");
        return choice;
    }

    static void _go_back_to_main_menue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

        system("pause>0");
        show_main_menue();
    }

    static void _show_all_clients_screen()
    {
        clsClientListScreen::show_client_list();
    }

    static void _show_add_new_clients_screen()
    {
        clsAddNewClientScreen::add_new_client();
    }

    static void _show_delete_clients_screen()
    {
        clsDeleteClientScreen::show_delete_client_screen();
    }

    static void _show_update_clients_screen()
    {
        clsUpdateClientScreen::show_update_client_screen();
    }

    static void _show_find_clients_screen()
    {
        clsFindClientScreen::show_find_client_screen();
    }

    static void _show_transactions_menue()
    {
        clsTransactionsScreen::show_transactions_menue();
    }

    static void _show_manage_users_menue()
    {
        clsManageUsersScreen::show_manage_user_menue();
    }

    static void _show_end_screen()
    {
        cout << "\nEnd Screen Will be here...\n";
    }

    static void _perform_main_menue_option(enmain_menue_options main_menue_option)
    {
        switch (main_menue_option)
        {
        case clsMainScreen::eshow_client_list:
            system("cls");
            _show_all_clients_screen();
            _go_back_to_main_menue();
            break;
        case clsMainScreen::eadd_new_client:
            system("cls");
            _show_add_new_clients_screen();
            _go_back_to_main_menue();
            break;
        case clsMainScreen::edelete_client_info:
            system("cls");
            _show_delete_clients_screen();
            _go_back_to_main_menue();
            break;
        case clsMainScreen::eupdate_client_info:
            system("cls");
            _show_update_clients_screen();
            _go_back_to_main_menue();
            break;
        case clsMainScreen::efind_client:
            system("cls");
            _show_find_clients_screen();
            _go_back_to_main_menue();
            break;
        case clsMainScreen::etransactions:
            system("cls");
            _show_transactions_menue();
            _go_back_to_main_menue();
            break;
        case clsMainScreen::emanage_users:
            system("cls");
            _show_manage_users_menue();
            _go_back_to_main_menue();
            break;
        case clsMainScreen::eexit:
            system("cls");
            _show_end_screen();
            //logout
            break;
        }
    }


public:

    static void show_main_menue()
    {
        system("cls");
        _draw_screen_header("\t\tMain Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _perform_main_menue_option((enmain_menue_options)_read_main_menue_option());
    }

};

