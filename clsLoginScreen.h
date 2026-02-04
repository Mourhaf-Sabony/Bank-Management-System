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

	static bool _login()
	{
		bool login_faild = false;
		string user_name, password;
		short faild_login_count = 0;

		do
		{


			if (login_faild)
			{
				faild_login_count++;
				cout << "\nInvalaid Username&Password!\n";
				cout << "You have " << (3 - faild_login_count) << " Trial(s) to login\n\n";
			}

			if (faild_login_count == 3)
			{
				cout << "\nYour are Locked after 3 faild trails\n";
				return false;
			}

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



	static bool show_login_screen()
	{
		system("cls");
		_draw_screen_header("\t  Login Screen");
		return _login();
	}

};

