#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "clsPerson.h"
#include "clsString.h"

using namespace std;

class clsBankClient : public clsPerson
{
private:

	enum enmode { empty_mode = 0, update_mode = 1, add_new_mode = 2 }; 
	enmode _mode;

	string _account_number;
	string _pin_code;
	float _account_balance;
	bool _marked_for_delete = false;

	static clsBankClient _convert_line_to_client_object(string line)
	{
		vector <string> vclient_data = clsString::split(line,"#//#");

		return clsBankClient(enmode::update_mode, vclient_data[0], vclient_data[1], vclient_data[2], vclient_data[3], vclient_data[4], vclient_data[5], stof(vclient_data[6]));
	}

	static string _convert_client_object_to_line(clsBankClient client, string seperator = "#//#")
	{
		string client_record = "";
		client_record += client.get_first_name() + seperator;
		client_record += client.get_last_name() + seperator;
		client_record += client.get_email() + seperator;
		client_record += client.get_phone() + seperator;
		client_record += client.get_account_number() + seperator;
		client_record += client.get_pin_code() + seperator;
		client_record += to_string(client.get_account_balance()) ;

		return client_record;

	}

	static vector <clsBankClient> _load_client_data_from_file()
	{
		vector <clsBankClient> vclients;

		fstream myfile;

		myfile.open("clients.txt", ios::in);

		if (myfile.is_open())
		{
			string line;
			while (getline(myfile,line))
			{
				clsBankClient client = _convert_line_to_client_object(line);
				vclients.push_back(client);
			}
			myfile.close();
		}
		
		return vclients;
	}

	static void _save_client_data_to_file(vector <clsBankClient> vclients)
	{
		fstream myfile;

		myfile.open("clients.txt", ios::out); //overwrite

		if (myfile.is_open())
		{
			string line;
			for (clsBankClient& C : vclients)
			{
				if (C.get_marked_for_deleted() == false)
				{
					//we only write records that are not marked for deleted.
					line = _convert_client_object_to_line(C);
					myfile << line << endl;
				}
			}
			myfile.close();
		}
	}

	 void _update()
	{
		 vector <clsBankClient> _vclients = _load_client_data_from_file();

		 for (clsBankClient& C : _vclients)
		 {
			 if (C.get_account_number() == get_account_number())
			 {
				 C = *this;
				 break;
			 }
		 }
		 _save_client_data_to_file(_vclients);
	}

	 void _add_new()
	 {
		 _add_data_line_to_file(_convert_client_object_to_line(*this));
	 }

	 void _add_data_line_to_file(string line)
	 {
		 fstream myfile;

		 myfile.open("clients.txt", ios::out | ios::app);
		 if (myfile.is_open())
		 {
			 myfile << line << endl;
			 myfile.close();
		 }
	 }

	static clsBankClient _get_empty_client_object()
	{
		return clsBankClient(enmode::empty_mode, "", "", "", "", "", "", 0.0);
	}


	string _prepare_transfer_log_record(clsBankClient destination_client, double amount,string user_name, string seperator = "#//#")
	{
		string transfer_log_record = "";

		transfer_log_record += clsDate::get_system_date_time_string() + seperator;
		transfer_log_record += get_account_number() + seperator;
		transfer_log_record += destination_client.get_account_number() + seperator;
		transfer_log_record += to_string(amount) + seperator;
		transfer_log_record += to_string(get_account_balance()) + seperator;
		transfer_log_record += to_string(destination_client.get_account_balance()) + seperator;
		transfer_log_record += user_name;

		return transfer_log_record;
	}


	void _register_transfer_log(clsBankClient destination_client, double amount,string user_name)
	{
		string stline = _prepare_transfer_log_record(destination_client, amount, user_name);

		fstream myfile;

		myfile.open("TransferLog.txt", ios::out | ios::app);
		if (myfile.is_open())
		{
			myfile << stline << endl;
			myfile.close();
		}
	}

	struct sttransfer_log_record;
	static sttransfer_log_record _convert_transfer_login_line_to_record(string line, string seperator = "#//#")
	{
		sttransfer_log_record transfer_log_record;


		vector <string> vtransfer_log_line = clsString::split(line, seperator);
		transfer_log_record.date_time = vtransfer_log_line[0];
		transfer_log_record.source_account_number = vtransfer_log_line[1];
		transfer_log_record.destination_account_number = vtransfer_log_line[2];
		transfer_log_record.amount = stod(vtransfer_log_line[3]);
		transfer_log_record.src_balance_after = stod(vtransfer_log_line[4]);
		transfer_log_record.dest_balance_after = stod(vtransfer_log_line[5]);
		transfer_log_record.user_name = vtransfer_log_line[6];

		return transfer_log_record;
	}



public:

	struct sttransfer_log_record {
		string date_time;
		string source_account_number;
		string destination_account_number;
		double amount;
		double src_balance_after;
		double dest_balance_after;
		string user_name;
	};

	//The constructor
	clsBankClient(enmode mode, string first_name, string last_name, string email, string phone, string account_number, string pin_code, float account_balance)
		: clsPerson(first_name, last_name, email, phone)
	{
		_mode = mode;
		_account_number = account_number;
		_pin_code = pin_code;
		_account_balance = account_balance;
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

	string get_account_number()
	{
		return _account_number;
	}

	void set_pin_code(string pin_code)
	{
		_pin_code = pin_code;
	}
	string get_pin_code()
	{
		return _pin_code;
	}

	void set_account_balance(float account_balance)
	{
		_account_balance = account_balance;
	}
	float get_account_balance()
	{
		return _account_balance;
	}

	//find client method
	static clsBankClient find(string account_number)
	{
		fstream myfile;

		myfile.open("clients.txt", ios::in);

		if (myfile.is_open())
		{
			string line;
			while (getline(myfile,line))
			{
				clsBankClient client = _convert_line_to_client_object(line);
				if (client.get_account_number() == account_number)
				{
					myfile.close();
					return client;
				}
			}
			myfile.close();
		}

		return _get_empty_client_object();

	}
	
	static clsBankClient find(string account_number,string pin_code)
	{
		fstream myfile;

		myfile.open("clients.txt", ios::in);

		if (myfile.is_open())
		{
			string line;
			while (getline(myfile,line))
			{
				clsBankClient client = _convert_line_to_client_object(line);
				if (client.get_account_number() == account_number && client.get_pin_code() == pin_code)
				{
					myfile.close();
					return client;
				}
			}
			myfile.close();
		}

		return _get_empty_client_object();

	}

	static bool is_client_exsist(string account_number)
	{
		clsBankClient client = find(account_number);

		return (!client.is_empty());
	}

	static clsBankClient get_add_new_client_object(string account_number)
	{
		return clsBankClient(enmode::add_new_mode, "", "", "", "", account_number, "", 0.0);
	}
	
	bool Delete()
	{
		vector <clsBankClient> vclients = _load_client_data_from_file();

		for (clsBankClient& C : vclients)
		{
			if (C.get_account_number() == _account_number)
			{
				C._marked_for_delete = true;
				break;
			}
		}

		_save_client_data_to_file(vclients);
		*this = _get_empty_client_object();
		return true;
	}

	enum ensave_result{svfaild_empty_object = 0,svsucceded = 1,svfaild_account_number_exists = 2};

	ensave_result save()
	{
		switch (_mode)
		{
		case clsBankClient::empty_mode:
			return ensave_result::svfaild_empty_object;
		case clsBankClient::update_mode:

			_update();
			return ensave_result::svsucceded;
		case clsBankClient::add_new_mode:
			if (clsBankClient::is_client_exsist(_account_number))
				return ensave_result::svfaild_account_number_exists;
			else
			{
				_add_new();
				_mode = enmode::update_mode;
				return ensave_result::svsucceded;
			}
		}
	}

	static vector <clsBankClient> get_client_list()
	{
		return _load_client_data_from_file();
	}

	static double total_balances()
	{
		double total_balances = 0.0;
		vector <clsBankClient> vclients = _load_client_data_from_file();

		for (clsBankClient& C : vclients)
		{
			total_balances += C.get_account_balance();
		}

		return total_balances;
	}

	//transaction choice
	void deposit(double amount)
	{
		_account_balance += amount;
		save();
	}

	bool withdraw(double amount)
	{
		if (amount > _account_balance)
		{
			return false;
		}
		else
		{
			_account_balance -= amount;
			save();
			return true;
		}
	}

	bool transfer(double amount, clsBankClient& destination_client,string user_name)
	{
		if (amount > _account_balance)
		{
			return false;
		}

		withdraw(amount);
		destination_client.deposit(amount);
		_register_transfer_log(destination_client, amount, user_name);
		return true;
	}


	static vector <sttransfer_log_record> get_transfer_log_list()
	{
		vector <sttransfer_log_record> vtransfer_log_record;

		fstream myfile;

		myfile.open("TransferLog.txt", ios::in); //read Mode

		if (myfile.is_open())
		{
			string line;
			sttransfer_log_record transfer_record;
			while (getline(myfile, line))
			{
				transfer_record = _convert_transfer_login_line_to_record(line);
				vtransfer_log_record.push_back(transfer_record);
			}
			myfile.close();
		}

		return vtransfer_log_record;
	}
};

