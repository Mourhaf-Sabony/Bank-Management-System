#pragma once
#pragma warning(disable: 4996)

#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include "clsString.h"

using namespace std;

class clsDate
{
private:
	short _year;
	short _month;
	short _day;
public:
	clsDate()
	{
		clsDate date = get_system_date();
		_day = date._day;
		_month = date._month;
		_year = date._year;
	}
	clsDate(string date)
	{
		vector <string> v_date = clsString::split(date, "/");


		_day = stoi(v_date[0]);
		_month = stoi(v_date[1]);
		_year = stoi(v_date[2]);
	}
	clsDate(short day, short month, short year)
	{
		_day = day;
		_month = month;
		_year = year;
	}
	clsDate(short number_of_days, short year)
	{
		clsDate date = get_date_from_day_order_of_year(number_of_days, year);
		_day = date._day;
		_month = date._month;
		_year = date._year;
	}

	void set_day(short day)
	{
		_day = day;
	}
	short get_day()
	{
		return _day;
	}

	void set_month(short month)
	{
		_month = month;
	}
	short get_month()
	{
		return _month;
	}

	void set_year(short year)
	{
		_year = year;
	}
	short get_year()
	{
		return _year;
	}

	void print()
	{
		cout << date_to_string() << endl;
	}


	//problem 3 ttt
	static bool is_leap_year(short year)
	{
		return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
	}
	bool is_leap_year()
	{
		return is_leap_year(_year);
	}

	//problem 4 ttt
	static short number_of_days_in_year(short year)
	{
		return is_leap_year(year) ? 366 : 365;
	}
	short number_of_days_in_year()
	{
		return number_of_days_in_year(_year);
	}

	static short number_of_hours_in_year(short year)
	{
		return number_of_days_in_year(year) * 24;
	}
	short  number_of_hours_in_year()
	{
		return  number_of_hours_in_year(_year);
	}

	static int number_of_minute_in_year(short year)
	{
		return number_of_hours_in_year(year) * 60;
	}
	int  number_of_minute_in_year()
	{
		return  number_of_minute_in_year(_year);
	}

	static int number_of_seconds_in_year(short year)
	{
		return number_of_minute_in_year(year) * 60;
	}
	int  number_of_seconds_in_year()
	{
		return  number_of_seconds_in_year(_year);
	}

	//problem 5 ttt
	static short number_of_days_in_month(short year, short month)
	{
		if (month < 1 || month > 12)
			return 0;

		int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

		return month == 2 ? (is_leap_year(year) ? 29 : 28) : days[month - 1];
	}
	short number_of_days_in_month()
	{
		return number_of_days_in_month(_year, _month);
	}

	static short number_of_hours_in_month(short year, short month)
	{
		return number_of_days_in_month(year, month) * 24;
	}
	short number_of_hours_in_month()
	{
		return number_of_hours_in_month(_year, _month);
	}

	static int number_of_minute_in_month(short year, short month)
	{
		return number_of_hours_in_month(year, month) * 60;
	}
	int number_of_minute_in_month()
	{
		return number_of_minute_in_month(_year, _month);
	}

	static int number_of_seconds_in_month(short year, short month)
	{
		return number_of_minute_in_month(year, month) * 60;
	}
	int number_of_seconds_in_month()
	{
		return number_of_seconds_in_month(_year, _month);
	}


	//problem 7 ttt
	static short get_day_order(short day, short month, short year)
	{
		short a = (14 - month) / 12;
		short y = year - a;
		short m = month + 12 * a - 2;

		return  (day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m / 12)) % 7;
	}
	static short get_day_order(clsDate date)
	{
		return get_day_order(date._day, date._month, date._year);
	}
	short get_day_order()
	{
		return get_day_order(*this);
	}

	static string get_day_name(clsDate date)
	{
		short order = get_day_order(date);

		string day[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };

		return day[order];
	}
	string get_day_name()
	{
		return get_day_name(*this);
	}

	//problem 8 ttt

	static string month_name(short month_number)
	{
		string arr[] = { "","Jan","Feb","Mar","Apr","May","Jun"
		,"Jul","Aug","Sep","Oct","Nov","Dec" };

		return arr[month_number];
	}
	string month_name()
	{
		return month_name(_month);
	}

	static void print_month_calendar(short year, short month)
	{
		short days_number = number_of_days_in_month(year, month);

		short order_of_month = get_day_order(1, month, year);

		cout << "\n  _______________" << month_name(month) << "_______________" << endl;
		cout << "\n  Sun  Mon  Tue  Wed  Thu  Fri  Sat" << endl;

		short i;
		for (i = 0; i < order_of_month; i++)
			cout << "     ";

		for (short j = 1; j <= days_number; j++)
		{
			printf("%5d", j);
			if (++i == 7)
			{
				i = 0;
				cout << "\n";
			}

		}

		cout << "\n  _________________________________";
	}
	void print_month_calendar()
	{
		return print_month_calendar(_year, _month);
	}

	//problem 9 ttt
	static void print_year_calender(short year)
	{
		cout << "\n  _________________________________\n";
		cout << "\n\t  Calendar - " << year;
		cout << "\n  _________________________________\n";

		for (short i = 1; i <= 12; i++)
		{
			print_month_calendar(year, i);
		}
	}
	void print_year_calender()
	{
		return print_year_calender(_year);
	}

	//problem 10 ttt
	static short number_of_days_from_the_beginning_of_year(short year, short month, short day)
	{
		short total_of_days = 0;

		for (short i = 1; i < month; i++)
		{
			total_of_days += number_of_days_in_month(year, i);
		}

		total_of_days += day;

		return total_of_days;
	}
	short number_of_days_from_the_beginning_of_year()
	{
		return number_of_days_from_the_beginning_of_year(_year, _month, _day);
	}

	//problem 11 ttt
	static clsDate get_date_from_day_order_of_year(short total_of_days, short year)
	{
		clsDate date;
		date._year = year;
		for (short i = 1; i <= 12; i++)
		{
			if (number_of_days_in_month(year, i) >= total_of_days)
			{
				date._day = total_of_days;
				date._month = i;
				return date;
			}
			total_of_days -= number_of_days_in_month(year, i);
		}
	}

	//problem 13 ttt
	static bool is_date1_before_date2(clsDate date1, clsDate date2)
	{
		return date1._year < date2._year ? true : (date1._year == date2._year ? (date1._month < date2._month ? true : (date1._month == date2._month ? (date1._day < date2._day) : false)) : false);
	}
	bool is_date_befor_date2(clsDate date2)
	{
		return is_date1_before_date2(*this, date2);
	}

	//problem 14 ttt
	static bool is_date1_equals_date2(clsDate date1, clsDate date2)
	{
		return date1._year == date2._year ? (date1._month == date2._month ? (date1._day == date2._day ? true : false) : false) : false;
	}
	bool is_date_equals_date2(clsDate date2)
	{
		return is_date1_equals_date2(*this, date2);
	}

	//problem 15 ttt
	static bool is_last_day_in_month(clsDate date)
	{
		return date._day == number_of_days_in_month(date._year, date._month);
	}
	bool is_last_day_in_month()
	{
		return is_last_day_in_month(*this);
	}

	static bool is_last_month_in_year(short month)
	{
		return month == 12;
	}
	bool is_last_month_in_year()
	{
		return is_last_month_in_year(_month);
	}

	//problem 16 ttt
	static clsDate add_one_day(clsDate &date)
	{
		if (is_last_day_in_month(date))
		{
			if (is_last_month_in_year(date._month))
			{
				date._day = 1;
				date._month = 1;
				date._year++;
			}
			else
			{
				date._day = 1;
				date._month++;
			}
		}
		else
			date._day++;

		return date;
	}
	void add_one_day()
	{
		add_one_day(*this);
	}

	//problem 18 ttt
	static clsDate get_system_date()
	{

		time_t t = time(0);
		tm* now = localtime(&t);

		short year, month,day;

		year = now->tm_year + 1900;
		month = now->tm_mon + 1;
		day = now->tm_mday;

		return clsDate(day,month,year);
	}

	static int your_age_in_days(clsDate date1)
	{
		clsDate date2 = get_system_date();
		return get_difference_in_days(date1, date2, true);
	}

	//problem 19 ttt
	static void swap_dates(clsDate& date1, clsDate& date2)
	{
		clsDate temp;

		temp = date1;
		date1 = date2;
		date2 = temp;
	}

	static int get_difference_in_days(clsDate date1, clsDate date2, bool including_end_day = false)
	{
		int days = 0;
		short swap_value = 1;

		if (!is_date1_before_date2(date1, date2))
		{
			swap_dates(date1, date2);
			swap_value = -1;
		}


		while (is_date1_before_date2(date1, date2))
		{
			days++;
			date1 = add_one_day(date1);
		}



		return including_end_day ? ++days * swap_value : days * swap_value;
	}
	int get_difference_in_days(clsDate date2, bool including_end_day = false)
	{
		return get_difference_in_days(*this, date2, including_end_day);
	}

	//problem 20 to 32 ttt
	static clsDate increase_date_by_x_days(clsDate &date, short number_of_days)
	{
		for (short i = 1; i <= number_of_days; i++)
		{
			date = add_one_day(date);
		}

		return date;
	}
	void increase_date_by_x_days(short number_of_days)
	{
		increase_date_by_x_days(*this, number_of_days);
	}

	static clsDate increase_date_by_one_week(clsDate &date)
	{

		for (short i = 1; i <= 7; i++)
		{
			date = add_one_day(date);
		}

		return date;
	}
	void increase_date_by_one_week()
	{
		increase_date_by_one_week(*this);
	}

	static clsDate increase_date_by_x_weeks(clsDate &date, short number_of_weeks)
	{
		for (short i = 1; i <= number_of_weeks; i++)
		{
			date = increase_date_by_one_week(date);
		}

		return date;
	}
	void increase_date_by_x_weeks(short number_of_weeks)
	{
		increase_date_by_x_weeks(*this, number_of_weeks);
	}

	static clsDate increase_date_by_one_month(clsDate &date)
	{
		if (date._month == 12)
		{
			date._month = 1;
			date._year++;
		}
		else
			date._month++;

		short number_of_days_in_current_month = number_of_days_in_month(date._year, date._month);

		if (date._day > number_of_days_in_current_month)
		{
			date._day = number_of_days_in_current_month;
		}

		return date;
	}
	void increase_date_by_one_month()
	{
		increase_date_by_one_month(*this);
	}

	static clsDate increase_date_by_x_months(clsDate &date, short number_of_months)
	{
		for (short i = 1; i <= number_of_months; i++)
		{
			date = increase_date_by_one_month(date);
		}

		return date;
	}
	void increase_date_by_x_months(short number_of_months)
	{
		increase_date_by_x_months(*this, number_of_months);
	}

	static clsDate increase_date_by_one_year(clsDate &date)
	{
		date._year++;

		if (!is_leap_year(date._year) && (date._month == 2) && (date._day == 29))
		{
			date._day = 28;
		}

		return date;
	}
	void increase_date_by_one_year()
	{
		increase_date_by_one_year(*this);
	}

	static clsDate increase_date_by_x_years(clsDate &date, short number_of_years)
	{
		date._year += number_of_years;

		return date;
	}
	void increase_date_by_x_years(short number_of_years)
	{
		increase_date_by_x_years(*this, number_of_years);
	}

	static clsDate increase_date_by_one_decade(clsDate &date)
	{
		date._year += 10;

		return date;
	}
	void increase_date_by_one_decade()
	{
		increase_date_by_one_decade(*this);
	}

	static clsDate increase_date_by_x_decades(clsDate &date, short number_of_decades)
	{
		date._year += number_of_decades * 10;

		return date;
	}
	void increase_date_by_x_decades(short number_of_decades)
	{
		increase_date_by_x_decades(*this, number_of_decades);
	}

	static clsDate increase_date_by_one_century(clsDate &date)
	{
		date._year += 100;

		return date;
	}
	void increase_date_by_one_century()
	{
		increase_date_by_one_century(*this);
	}

	static clsDate increase_date_by_one_millennium(clsDate &date)
	{
		date._year += 1000;
		return date;
	}
	void increase_date_by_one_millennium()
	{
		increase_date_by_one_millennium(*this);
	}

	//problem 33 to 46 ttt
	static clsDate decrease_date_by_one_day(clsDate &date)
	{
		if (date._day == 1)
		{
			if (date._month == 1)
			{
				date._day = 31;
				date._month = 12;
				date._year--;
			}
			else
			{
				date._month--;
				date._day = number_of_days_in_month(date._year, date._month);
			}
		}
		else
		{
			date._day--;
		}

		return date;
	}
	void decrease_date_by_one_day()
	{
		decrease_date_by_one_day(*this);
	}

	static clsDate decrease_date_by_x_days(clsDate &date, short number_of_days)
	{
		for (short i = 1; i <= number_of_days; i++)
		{
			date = decrease_date_by_one_day(date);
		}

		return date;
	}
	void decrease_date_by_x_days(short number_of_days)
	{
		decrease_date_by_x_days(*this, number_of_days);
	}

	static clsDate decrease_date_by_one_week(clsDate &date)
	{
		date = decrease_date_by_x_days(date, 7);

		return date;
	}
	void decrease_date_by_one_week()
	{
		decrease_date_by_one_week(*this);
	}

	static clsDate decrease_date_by_x_weeks(clsDate &date, short number_of_weeks)
	{
		for (short i = 1; i <= number_of_weeks; i++)
		{
			date = decrease_date_by_one_week(date);
		}

		return date;
	}
	void decrease_date_by_x_weeks(short number_of_weeks)
	{
		decrease_date_by_x_weeks(*this, number_of_weeks);
	}

	static clsDate decrease_date_by_one_month(clsDate &date)
	{
		if (date._month == 1)
		{
			date._month = 12;
			date._year--;
		}
		else
		{
			date._month--;
		}

		short number_of_days_in_current_month = number_of_days_in_month(date._year, date._month);

		if (date._day > number_of_days_in_current_month)
		{
			date._day = number_of_days_in_current_month;
		}

		return date;
	}
	void decrease_date_by_one_month()
	{
		decrease_date_by_one_month(*this);
	}

	static clsDate decrease_date_by_x_months(clsDate &date, short number_of_months)
	{
		for (short i = 1; i <= number_of_months; i++)
		{
			date = decrease_date_by_one_month(date);
		}

		return date;
	}
	void decrease_date_by_x_months(short number_of_months)
	{
		decrease_date_by_x_months(*this, number_of_months);
	}

	static clsDate decrease_date_by_one_year(clsDate &date)
	{
		date._year--;

		if (!is_leap_year(date._year) && (date._month == 2) && (date._day == 29))
		{
			date._day = 28;
		}

		return date;
	}
	void decrease_date_by_one_year()
	{
		decrease_date_by_one_year(*this);
	}

	static clsDate decrease_date_by_x_years(clsDate &date, short number_of_years)
	{
		date._year -= number_of_years;

		if (!is_leap_year(date._year) && (date._month == 2) && (date._day == 29))
		{
			date._day = 28;
		}

		return date;
	}
	void decrease_date_by_x_years(short number_of_years)
	{
		decrease_date_by_x_years(*this, number_of_years);
	}

	static clsDate decrease_date_by_one_decade(clsDate &date)
	{
		date._year -= 10;

		return date;
	}
	void decrease_date_by_one_decade()
	{
		decrease_date_by_one_decade(*this);
	}

	static clsDate decrease_date_by_x_decades_faster(clsDate &date, short number_of_decades)
	{
		date._year -= number_of_decades * 10;

		return date;
	}
	void decrease_date_by_x_decades_faster(short number_of_decades)
	{
		decrease_date_by_x_decades_faster(*this, number_of_decades);
	}

	static clsDate decrease_date_by_one_century(clsDate &date)
	{
		date._year -= 100;

		return date;
	}
	void decrease_date_by_one_century()
	{
		decrease_date_by_one_century(*this);
	}

	static clsDate decrease_date_by_one_millennium(clsDate &date)
	{
		date._year -= 1000;
		return date;
	}
	void decrease_date_by_one_millennium()
	{
		decrease_date_by_one_millennium(*this);
	}

	//problem 47 to 53 ttt
	static bool is_end_of_week(clsDate date)
	{
		return get_day_order(date) == 6;
	}
	bool is_end_of_week()
	{
		return is_end_of_week(*this);
	}

	static bool is_week_end(clsDate date)
	{
		short order_of_day = get_day_order(date);

		return (order_of_day == 5 || order_of_day == 6);
	}
	bool is_week_end()
	{
		return is_week_end(*this);
	}

	static bool is_business_day(clsDate date)
	{
		return !is_week_end(date);
	}
	bool is_business_day()
	{
		return is_business_day(*this);
	}

	static short days_until_the_end_of_week(clsDate date)
	{
		return 6 - get_day_order(date);
	}
	short days_until_the_end_of_week()
	{
		return days_until_the_end_of_week(*this);
	}

	static short days_until_the_end_of_month(clsDate date)
	{
		clsDate date2;
		date2._day = number_of_days_in_month(date._year, date._month);
		date2._month = date._month;
		date2._year = date._year;

		return get_difference_in_days(date, date2, true);
	}
	short days_until_the_end_of_month()
	{
		return days_until_the_end_of_month(*this);
	}

	static short days_until_the_end_of_year(clsDate date)
	{
		clsDate date2;
		date2._day = 31;
		date2._month = 12;
		date2._year = date._year;

		return get_difference_in_days(date, date2, true);
	}
	short days_until_the_end_of_year()
	{
		return days_until_the_end_of_year(*this);
	}

	//extra ttt
	static short calculate_business_day(clsDate date_from, clsDate date_to)
	{
		short business_days = 0;
		while (is_date1_before_date2(date_from,date_to))
		{
			if (is_business_day(date_from))
				business_days++;

			date_from = add_one_day(date_from);
		}

		return business_days;
	}
	short calculate_business_day(clsDate date_to)
	{
		return calculate_business_day(*this, date_to);
	}

	//problem 54 ttt
	static short calculate_vacation_days(clsDate date_from, clsDate date_to)
	{
		return calculate_business_day(date_from,date_to);
	}
	short calculate_vacation_days(clsDate date_to)
	{
		return calculate_vacation_days(*this, date_to);
	}

	//problem 55 ttt
	static clsDate calculate_date_after_vacation(clsDate date_from, short vacation_days)
	{
		clsDate date_to = date_from;
		short counter = 0;

		while (counter != vacation_days)
		{
			if (is_business_day(date_to))
			{
				counter++;
				date_to = add_one_day(date_to);
			}
			else
			{
				date_to = add_one_day(date_to);
			}
		}

		return date_to;
	}
	

	//problem 57

	enum en_date_compare { before = -1, equal = 0, after = 1 };

	static en_date_compare compare_dates(clsDate date1, clsDate date2)
	{
		if (is_date1_before_date2(date1, date2))
			return en_date_compare::before;
		else if (is_date1_equals_date2(date1, date2))
			return en_date_compare::equal;
		else
			return en_date_compare::after;
	}
	en_date_compare compare_dates(clsDate date2)
	{
		return compare_dates(*this, date2);
	}

	//problem 62 ttt

	static bool is_validate_date(clsDate date)
	{
		if (date._month < 1 || date._month > 12)
			return false;

		if (date._day < 1 || date._day > 31)
			return false;

		if (date._month == 2)
		{
			if (is_leap_year(date._year))
			{
				if (date._day > 29)
					return false;
			}
			else
			{
				if (date._day > 28)
					return false;
			}
		}

		if (date._day > number_of_days_in_month(date._year, date._month))
			return false;

		return true;
	}
	bool is_validate_date()
	{
		return is_validate_date(*this);
	}

	//problem 63 and 64 ttt second

	static clsDate string_to_date(string s1, string seperator = "/")
	{

		vector <string> v_date = clsString::split(s1, seperator);

		clsDate date;

		date._day = stoi(v_date[0]);
		date._month = stoi(v_date[1]);
		date._year = stoi(v_date[2]);

		return date;
	}

	static string date_to_string(clsDate date, string seperator = "/")
	{
		string date_string = "";

		date_string += to_string(date._day) + seperator;
		date_string += to_string(date._month) + seperator;
		date_string += to_string(date._year);

		return date_string;
	}
	string date_to_string(string seperator = "/")
	{
		return date_to_string(*this, seperator);
	}

	//problem 65
	static string format_date(clsDate date, string format = "dd/mm/yyyy")
	{
		string date_after_format = "";

		date_after_format = clsString::replace_word(format, "dd", to_string(date._day));
		date_after_format = clsString::replace_word(date_after_format, "mm", to_string(date._month));
		date_after_format = clsString::replace_word(date_after_format, "yyyy", to_string(date._year));

		return date_after_format;

	}
	string format_date(string format = "dd/mm/yyyy")
	{
		return format_date(*this, format);
	}

	static string get_system_date_time_string()
	{
		//system datetime string
		time_t t = time(0);
		tm* now = localtime(&t);

		short Day, Month, Year, Hour, Minute, Second;

		Year = now->tm_year + 1900;
		Month = now->tm_mon + 1;
		Day = now->tm_mday;
		Hour = now->tm_hour;
		Minute = now->tm_min;
		Second = now->tm_sec;

		return (to_string(Day) + "/" + to_string(Month) + "/"
			+ to_string(Year) + " - "
			+ to_string(Hour) + ":" + to_string(Minute)
			+ ":" + to_string(Second));
	}


};

