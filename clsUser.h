#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "clsPerson.h"
#include "clsString.h"
#include "clsUtil.h"

using namespace std;
class clsUser : public clsPerson
{

private:


	enum enmode { empty_mode = 0, update_mode = 1, add_new_mode = 2 };
	enmode _mode;

	string _user_name;
	string _password;
	int _permissions;
	bool _marked_for_delete = false;

	static clsUser _convert_line_to_user_object(string line)
	{
		vector <string> vuser_data = clsString::split(line, "#//#");

		return clsUser(enmode::update_mode, vuser_data[0], vuser_data[1], vuser_data[2], vuser_data[3], vuser_data[4], vuser_data[5], stoi(vuser_data[6]));
	}

	static string _convert_user_object_to_line(clsUser user, string seperator = "#//#")
	{
		string user_record = "";
		user_record += user.get_first_name() + seperator;
		user_record += user.get_last_name() + seperator;
		user_record += user.get_email() + seperator;
		user_record += user.get_phone() + seperator;
		user_record += user.get_user_name() + seperator;
		user_record += user.get_password() + seperator;
		user_record += to_string(user.get_permission());

		return user_record;

	}

	static vector <clsUser> _load_user_data_from_file()
	{
		vector <clsUser> vusers;

		fstream myfile;

		myfile.open("Users.txt", ios::in); //read Mode

		if (myfile.is_open())
		{
			string line;
			while (getline(myfile, line))
			{
				clsUser user = _convert_line_to_user_object(line);
				vusers.push_back(user);
			}
			myfile.close();
		}

		return vusers;
	}

	static void _save_user_data_to_file(vector <clsUser> vusers)
	{
		fstream myfile;

		myfile.open("Users.txt", ios::out); //overwrite

		if (myfile.is_open())
		{
			string line;
			for (clsUser& C : vusers)
			{
				if (C.get_marked_for_deleted() == false)
				{
					//we only write records that are not marked for deleted.
					line = _convert_user_object_to_line(C);
					myfile << line << endl;
				}
			}
			myfile.close();
		}
	}

	void _update()
	{
		vector <clsUser> vusers = _load_user_data_from_file();

		for (clsUser& C : vusers)
		{
			if (C.get_user_name() == get_user_name())
			{
				C = *this;
				break;
			}
		}
		_save_user_data_to_file(vusers);
	}

	void _add_new()
	{
		_add_data_line_to_file(_convert_user_object_to_line(*this));
	}

	void _add_data_line_to_file(string line)
	{
		fstream myfile;

		myfile.open("Users.txt", ios::out | ios::app);
		if (myfile.is_open())
		{
			myfile << line << endl;
			myfile.close();
		}
	}

	static clsUser _get_empty_user_object()
	{
		return clsUser(enmode::empty_mode, "", "", "", "", "", "", 0);
	}


	string _prepare_login_record(string seperator = "#//#")
	{
		string login_record = "";

		login_record += clsDate::get_system_date_time_string() + seperator;
		login_record += _user_name + seperator;
		login_record += _password + seperator;
		login_record += to_string(_permissions);

		return login_record;

	}



public:

	enum en_permissions {
		eall = -1, eshow_client_list = 1, eadd_new_client = 2, edelete_client_info = 4,
		eupdate_client_info = 8, efind_client = 16, etransactions = 32, emanage_users = 64
	};

	//The Constructor
	clsUser(enmode mode, string first_name, string last_name, string email, string phone, string user_name, string password, int permissions)
		:clsPerson(first_name, last_name, email, phone)
	{
		_mode = mode;
		_user_name = user_name;
		_password = password;
		_permissions = permissions;
	}

	//setter and getter properties
	bool is_empty()
	{
		return (_mode == enmode::empty_mode);
	}

	bool get_marked_for_deleted()
	{
		return _marked_for_delete;
	}

	void set_user_name(string user_name)
	{
		_user_name = user_name;
	}
	string get_user_name()
	{
		return _user_name;
	}

	void set_password(string password)
	{
		_password = password;
	}
	string get_password()
	{
		return _password;
	}

	void set_permission(int permission)
	{
		_permissions = permission;
	}
	int get_permission()
	{
		return _permissions;
	}


	//find user method
	static clsUser find(string user_name)
	{
		fstream myfile;

		myfile.open("Users.txt", ios::in);

		if (myfile.is_open())
		{
			string line;
			while (getline(myfile, line))
			{
				clsUser user = _convert_line_to_user_object(line);
				if (user.get_user_name() == user_name)
				{
					myfile.close();
					return user;
				}
			}
			myfile.close();
		}

		return _get_empty_user_object();

	}

	static clsUser find(string user_name, string password)
	{
		fstream myfile;

		myfile.open("Users.txt", ios::in);

		if (myfile.is_open())
		{
			string line;
			while (getline(myfile, line))
			{
				clsUser user = _convert_line_to_user_object(line);
				if (user.get_user_name() == user_name && user._password == password)
				{
					myfile.close();
					return user;
				}
			}
			myfile.close();
		}

		return _get_empty_user_object();

	}

	static bool is_user_exsist(string user_name)
	{
		clsUser user = find(user_name);

		return (!user.is_empty());
	}

	static clsUser get_add_new_user_object(string user_name)
	{
		return clsUser(enmode::add_new_mode, "", "", "", "", user_name, "", 0);
	}

	bool Delete()
	{
		vector <clsUser> vusers = _load_user_data_from_file();

		for (clsUser& C : vusers)
		{
			if (C.get_user_name() == _user_name)
			{
				C._marked_for_delete = true;
				break;
			}
		}

		_save_user_data_to_file(vusers);
		*this = _get_empty_user_object();
		return true;
	}


	static vector <clsUser> get_user_list()
	{
		return _load_user_data_from_file();
	}


	enum ensave_result { svfaild_empty_object = 0, svsucceded = 1, svfaild_user_exists = 2 };

	ensave_result save()
	{
		switch (_mode)
		{
		case clsUser::empty_mode:
			return ensave_result::svfaild_empty_object;
		case clsUser::update_mode:

			_update();
			return ensave_result::svsucceded;
		case clsUser::add_new_mode:
			if (clsUser::is_user_exsist(_user_name))
				return ensave_result::svfaild_user_exists;
			else
			{
				_add_new();
				_mode = enmode::update_mode;
				return ensave_result::svsucceded;
			}
		}
	}


	bool check_access_permission(en_permissions permisssion)
	{
		if (this->get_permission() == en_permissions::eall)
			return true;

		if ((this->get_permission() & permisssion) == permisssion)
			return true;
		else
			return false;
	}

	void register_login()
	{
		string stline = _prepare_login_record();

		fstream myfile;

		myfile.open("LoginRegister.txt", ios::out | ios::app);
		if (myfile.is_open())
		{
			myfile << stline << endl;
			myfile.close();
		}
	}

};

