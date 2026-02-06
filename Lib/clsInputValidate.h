#pragma once
#include <iostream>
#include "clsDate.h"
#include "clsPeriod.h"


using namespace std;
 

class clsInputValidate
{
public:

	template <typename Type>
	static bool is_number_between(Type number, Type from, Type to)
	{
		return ((number >= from) && (number <= to));
	}

	template <typename Type>
	static Type read_number(string error_massege = "Invalid Number, Enter again")
	{
		Type number = 0;
		while (!(cin >> number))
		{
			cin.clear();
			cin.ignore(numeric_limits <streamsize>::max(), '\n');
			cout << error_massege << endl;
		}
		return number;
	}
	
	template <typename Type>
	static Type read_number_between(Type from, Type to, string error_massege = "Number is not within range, Enter again:")
	{
		Type number = read_number<Type>();
		while (!is_number_between(number,from,to))
		{
			cout << error_massege << endl;
			number = read_number<Type>();
		}
		return number;
	}

	static bool is_date_between(clsDate date, clsDate date_from, clsDate date_to)
	{
		if (clsDate::is_date1_before_date2(date_to,date_from))
		{
			clsDate::swap_dates(date_from, date_to);
		}

		return clsPeriod::is_date_in_period(clsPeriod(date_from, date_to), date);
	}

	static bool is_validate_date(clsDate date) {
		return clsDate::is_validate_date(date);
	}

	static string read_string()
	{
		string s1 = "";
		getline(cin >> ws, s1);
		return s1;
	}
	
};

