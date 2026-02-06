#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsUser.h"

using namespace std;
class clsListUsersScreen : protected clsScreen
{
private:

	static void _print_user_record_line(clsUser user)
	{

		cout << setw(8) << left << "" << "| " << setw(12) << left << user.get_user_name();
		cout << "| " << setw(25) << left << user.get_full_name();
		cout << "| " << setw(12) << left << user.get_phone();
		cout << "| " << setw(20) << left << user.get_email();
		cout << "| " << setw(10) << left << user.get_password();
		cout << "| " << setw(12) << left << user.get_permission();
	}

public:

	static void show_users_list()
	{
		vector <clsUser> vusers = clsUser::get_user_list();


		string title = "\t  User List Screen";
		string sub_title = "\t    (" + to_string(vusers.size()) + ") User(s).";

		_draw_screen_header(title, sub_title);


		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "______________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(12) << "UserName";
		cout << "| " << left << setw(25) << "Full Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(20) << "Email";
		cout << "| " << left << setw(10) << "Password";
		cout << "| " << left << setw(12) << "Permissions";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "______________________________________________\n" << endl;

		if (vusers.size() == 0)
			cout << "\t\t\t\tNo Users Available In the System!";
		else

			for (clsUser User : vusers)
			{

				_print_user_record_line(User);
				cout << endl;
			}

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "______________________________________________\n" << endl;
	}
};

