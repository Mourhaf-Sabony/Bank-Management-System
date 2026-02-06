#pragma once
#include <iostream>
#include "clsUser.h"
#include "Global.h"
#include "clsDate.h"

using namespace std;

class clsScreen
{
protected:

	static void _draw_screen_header(string title, string sub_title = "")
	{
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << title;
        if (sub_title != "")
        {
            cout << "\n\t\t\t\t\t  " << sub_title;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";
        cout << "\t\t\t\t\tUser: " << current_user.get_user_name() << endl;
        cout << "\t\t\t\t\tDate: " << clsDate::date_to_string(clsDate()) << endl;
	}

    static bool check_access_rights(clsUser::en_permissions permission)
    {
        if (!current_user.check_access_permission(permission))
        {
            cout << "\t\t\t\t\t______________________________________";
            cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
            cout << "\n\t\t\t\t\t______________________________________\n\n";
            return false;
        }
        else
            return true;
    }
};

