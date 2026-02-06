#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"

using namespace std;
class clsDeleteUserScreen: protected clsScreen
{
private:
    

    static void _print_user(clsUser user)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << user.get_first_name();
        cout << "\nLastName    : " << user.get_last_name();
        cout << "\nFull Name   : " << user.get_full_name();
        cout << "\nEmail       : " << user.get_email();
        cout << "\nPhone       : " << user.get_phone();
        cout << "\nUser Name   : " << user.get_user_name();
        cout << "\nPassword    : " << user.get_password();
        cout << "\nPermissions : " << user.get_permission();
        cout << "\n___________________\n";

    }

public:

	static void show_delete_user_screen()
	{
		_draw_screen_header("\t Delete User Screen");

        string user_name = "";

        cout << "\nenter the UserName: ";
        user_name = clsInputValidate::read_string();
        while (!clsUser::is_user_exsist(user_name))
        {
            cout << "\nUser Name is not found, choose another one: ";
            user_name = clsInputValidate::read_string();
        }

        clsUser user1 = clsUser::find(user_name);
        _print_user(user1);

        cout << "\nAre you sure you want to delete this user y/n?";
        char answer = 'n';
        cin >> answer;

        if (toupper(answer) == 'Y')
        {
            if (user1.Delete())
            {
                cout << "\nUser Deleted Successfully :-)";
                _print_user(user1);
            }
            else
                cout << "\nError, User Was not Deleted";
        }

	}
};

