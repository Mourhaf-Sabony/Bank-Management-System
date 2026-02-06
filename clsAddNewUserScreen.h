#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"

using namespace std;

class clsAddNewUserScreen: protected clsScreen
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
		
		cout << "\nLogin Register? y/n? \n";
		cin >> answer;
		if (toupper(answer) == 'Y')
		{
			permissions |= clsUser::elogin_register;
		}

		cout << "\nCurrency Exchange? y/n? \n";
		cin >> answer;
		if (toupper(answer) == 'Y')
		{
			permissions |= clsUser::ecurrency_exchange;
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

	static void _show_add_new_user_screen()
	{
		_draw_screen_header("\t Add New User Screen");
		string user_name = "";
		cout << "\nenter User Name: ";
		user_name = clsInputValidate::read_string();

		while (clsUser::is_user_exsist(user_name))
		{
			cout << "\nUserNamw Is Already Used, Choose another one: ";
			user_name = clsInputValidate::read_string();
		}

		clsUser new_user = clsUser::get_add_new_user_object(user_name);

		_read_user_info(new_user);

		clsUser::ensave_result save_result;

		save_result = new_user.save();

		switch (save_result)
		{
		case  clsUser::svsucceded:
		{
			cout << "\nUser Addeded Successfully :-)\n";
			_print_user(new_user);
			break;
		}
		case clsUser::svfaild_empty_object:
		{
			cout << "\nError User was not saved because it's Empty";
			break;

		}
		case clsUser::svfaild_user_exists:
		{
			cout << "\nError User was not saved because UserName is used!\n";
			break;

		}
		}
	}
};

