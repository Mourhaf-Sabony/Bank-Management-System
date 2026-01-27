#pragma once
#include <iostream>
#include"clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"

using namespace std;
class clsUpdateUserScreen : protected clsScreen
{

private:

	static void _read_user_info(clsUser& user)
	{
		cout << "\nEnter First Name: ";
		user.set_first_name(clsInputValidate::read_string());


		cout << "\nEnter LastName: ";
		user.set_last_name(clsInputValidate::read_string());

		cout << "\nEnter Email: ";
		user.set_email(clsInputValidate::read_string());

		cout << "\nEnter Phone: ";
		user.set_phone(clsInputValidate::read_string());

		cout << "\nEnter Password: ";
		user.set_password(clsInputValidate::read_string());

		cout << "\nEnter Permission: ";
		user.set_permission(_read_permissions_to_set());

	}


	static int _read_permissions_to_set()
	{
		int permissions = 0;
		char answer = 'n';

		cout << "\nDo you want to give full access? y/n? \n";
		cin >> answer;

		if (toupper(answer) == 'Y')
		{
			return -1;
		}


		cout << "\ndo you want to give access to : \n";

		cout << "\nShow Client List? y/n? \n";
		cin >> answer;
		if (toupper(answer) == 'Y')
		{
			permissions |= clsUser::eshow_client_list;
		}

		cout << "\nAdd New Client? y/n? \n";
		cin >> answer;
		if (toupper(answer) == 'Y')
		{
			permissions |= clsUser::eadd_new_client;
		}

		cout << "\nDelete Client? y/n? \n";
		cin >> answer;
		if (toupper(answer) == 'Y')
		{
			permissions |= clsUser::edelete_client_info;
		}

		cout << "\nUpdate Client? y/n? \n";
		cin >> answer;
		if (toupper(answer) == 'Y')
		{
			permissions |= clsUser::eupdate_client_info;
		}

		cout << "\nFind client? y/n? \n";
		cin >> answer;
		if (toupper(answer) == 'Y')
		{
			permissions |= clsUser::efind_client;
		}

		cout << "\nTransactions? y/n? \n";
		cin >> answer;
		if (toupper(answer) == 'Y')
		{
			permissions |= clsUser::etransactions;
		}

		cout << "\nManage Users? y/n? \n";
		cin >> answer;
		if (toupper(answer) == 'Y')
		{
			permissions |= clsUser::emanage_users;
		}

		return permissions;
	}


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

	static void show_update_user_screen()
	{
		_draw_screen_header("\t Update User Screen");
		string user_name = "";

		cout << "\nenter user User Name: ";
		user_name = clsInputValidate::read_string();
		while (!clsUser::is_user_exsist(user_name))
		{
			cout << "\nUser Name is not found, choose another one: ";
			user_name = clsInputValidate::read_string();
		}

		clsUser user1 = clsUser::find(user_name);
		_print_user(user1);

		cout << "\nAre you sure you want to update this user y/n?";

		char answer = 'n';
		cin >> answer;

		if (toupper(answer) == 'Y')
		{
			cout << "\n\nUpdate user Info: ";
			cout << "\n________________________\n";

			_read_user_info(user1);

			clsUser::ensave_result save_result = user1.save();

			switch (save_result)
			{
			case clsUser::svfaild_empty_object:
				cout << "\nError, account was not saved becuase it's empty\n";
				break;
			case clsUser::svsucceded:
				cout << "\nAccount Updated Successfully :-) \n";
				_print_user(user1);
				break;
			default:
				break;
			}
		}
	}
};

