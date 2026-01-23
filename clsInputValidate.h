#pragma once
#include <iostream>
#include "clsDate.h"
#include "clsPeriod.h"


using namespace std;

class clsInputValidate
{
public:

	static bool is_number_between(short number, short from, short to)
	{
		return (number >= from) && (number <= to) ? true : false;
	}

	static bool is_number_between(int number, int from, int to)
	{
		return (number >= from) && (number <= to) ? true : false;
	}

	static bool is_number_between(double number, double from, double to)
	{
		return (number >= from) && (number <= to) ? true : false;
	}

	static bool is_number_between(float number, float from, float to)
	{
		return (number >= from) && (number <= to) ? true : false;
	}

	static bool is_date_between(clsDate date, clsDate date_from, clsDate date_to)
	{
		if (clsDate::is_date1_before_date2(date_to, date_from))
		{
			clsDate::swap_dates(date_from, date_to);
		}

		return clsPeriod::is_date_in_period(clsPeriod(date_from, date_to), date);
	}

	static int read_int_number(string error_massege = "Invalid Number, Enter again")
	{
		int number = 0;
		while (!(cin >> number))
		{
			cin.clear();
			cin.ignore(numeric_limits <streamsize>::max(), '\n');
			cout << error_massege << endl;
		}
		return number;
	}

	static double read_dbl_number(string error_massege = "Invalid Number, Enter again")
	{
		double number = 0.0;
		while (!(cin >> number))
		{
			cin.clear();
			cin.ignore(numeric_limits <streamsize>::max(), '\n');
			cout << error_massege << endl;
		}
		return number;
	}

	static int read_int_number_between(int from, int to, string error_massege = "Number is not within range, Enter again:")
	{
		int number = read_int_number();
		while (!is_number_between(number, from, to))
		{
			cout << error_massege << endl;
			number = read_int_number();
		}
		return number;
	}

	static double read_dbl_number_between(double from, double to, string error_massege = "Number is not within range, Enter again:")
	{
		double number = read_dbl_number();
		while (!is_number_between(number, from, to))
		{
			cout << error_massege << endl;
			number = read_dbl_number();
		}
		return number;
	}

	static bool is_validate_date(clsDate date) {
		return clsDate::is_validate_date(date);
	}

};

