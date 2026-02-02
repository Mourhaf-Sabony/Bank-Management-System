#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsMainScreen.h"
#include "Global.h"


using namespace std;
class clsLoginScreen : protected clsScreen
{
private:

	static void _login()
	{
		bool login_faild = false;

		string user_name, password;

		do
		{
			if (login_faild)
				cout << "\nInvalaid Username&Password!\n\n";

			cout << "\nEnter User Name: ";
			user_name = clsInputValidate::read_string();

			cout << "\nEnter Password: ";
			password = clsInputValidate::read_string();

			current_user = clsUser::find(user_name, password);

			login_faild = current_user.is_empty();

		} while (login_faild);

		clsMainScreen::show_main_menue();
	}
public:
	static void show_login_screen()
	{
		system("cls");
		_draw_screen_header("\t Login Screen");
		_login();
	}

};

