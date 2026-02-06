#pragma once

#include <iostream>
#include <vector>

using namespace std;

class clsString
{
private:
	string _value;
public:
	clsString()
	{
		_value = "";
	}
	clsString(string value)
	{
		_value = value;
	}

	void set_value(string value)
	{
		_value = value;
	}

	string get_value()
	{
		return _value;
	}

	// ttt
	static short length(string s1)
	{
		return s1.length();
	}
	short length()
	{
		return _value.length();
	}

	//problem 23/7
	static void print_first_letter_of_each_word(string s1)
	{
		bool is_first_letter = true;

		cout << "First letters of this string: \n";
		for (int i = 0; i < s1.length(); i++)
		{
			if (s1[i] != ' ' && is_first_letter)
				cout << s1[i] << endl;

			is_first_letter = (s1[i] == ' ' ? true : false);
		}
	}
	void print_first_letter_of_each_word()
	{
		print_first_letter_of_each_word(_value);
	}

	//problem 24/7 ttt
	static string upper_first_letter_of_each_word(string s1)
	{
		bool is_first_letter = true;

		for (int i = 0; i < s1.length(); i++)
		{
			if (s1[i] != ' ' && is_first_letter)
				s1[i] = toupper(s1[i]);

			is_first_letter = (s1[i] == ' ' ? true : false);
		}

		return s1;
	}
	void upper_first_letter_of_each_word()
	{
		_value =  upper_first_letter_of_each_word(_value);
	}

	//problem 25/7 ttt
	static string lower_first_letter_of_each_word(string s1)
	{
		bool is_first_letter = true;

		for (int i = 0; i < s1.length(); i++)
		{
			if (s1[i] != ' ' && is_first_letter)
				s1[i] = tolower(s1[i]);

			is_first_letter = (s1[i] == ' ' ? true : false);
		}

		return s1;
	}
	void lower_first_letter_of_each_word()
	{
		_value =  lower_first_letter_of_each_word(_value);
	}

	//problem 26/7 ttt
	static string upper_all(string s1)
	{
		for (int i = 0; i < s1.length(); i++)
		{
			s1[i] = toupper(s1[i]);
		}

		return s1;
	}
	void upper_all()
	{
		_value = upper_all(_value);
	}

	static string lower_all(string s1)
	{
		for (int i = 0; i < s1.length(); i++)
		{
			s1[i] = tolower(s1[i]);
		}

		return s1;
	}
	void lower_all()
	{
		_value = lower_all(_value);
	}

	//problem 28/7 ttt
	static char invert_letter_case(char ch1)
	{
		return (isupper(ch1) ? tolower(ch1) : toupper(ch1));
	}

	static string invert_all_letter_case(string s1)
	{
		for (int i = 0; i < s1.length(); i++)
		{
			s1[i] = invert_letter_case(s1[i]);
		}
		return s1;
	}
	void invert_all_letter_case()
	{
		_value = invert_all_letter_case(_value);
	}

	//problem 29/7 ttt
	static short count_capital_letter(string s1)
	{
		short counter = 0;
		for (short i = 0; i < s1.length(); i++)
		{
			if (isupper(s1[i]))
				counter++;
		}
		return counter;
	}
	short count_capital_letter()
	{
		return count_capital_letter(_value);
	}

	static short count_small_letter(string s1)
	{
		short counter = 0;
		for (short i = 0; i < s1.length(); i++)
		{
			if (islower(s1[i]))
				counter++;
		}
		return counter;
	}
	short count_small_letter()
	{
		return count_small_letter(_value);
	}

	//problem 31/7 ttt
	static short count_specific_letter(string s1, char ch1,bool match_case = true)
	{
		short counter = 0;
		for (short i = 0; i < s1.length(); i++)
		{
			if (match_case)
			{
				if (s1[i] == ch1)
					counter++;
			}
			else
			{
				if (s1[i] == ch1 || invert_letter_case(s1[i]) == ch1)
					counter++;
			}

		}
		return counter;
	}
	short count_specific_letter(char ch1, bool match_case = true)
	{
		return count_specific_letter(_value,ch1,match_case);
	}

	//problem 33/7 ttt
	static bool is_vowel(char ch1)
	{
		char Ch1 = tolower(ch1);

		return (Ch1 == 'a' || Ch1 == 'e' || Ch1 == 'i' || Ch1 == 'o' || Ch1 == 'u');
	}

	static short count_vowel(string s1)
	{
		short counter = 0;
		for (short i = 0; i < s1.length(); i++)
		{
			if (is_vowel(s1[i]))
				counter++;
		}

		return counter;
	}
	short count_vowel()
	{
		return count_vowel(_value);
	}

	//problem 34/7 ttt
	static string add_all_vowels(string s1)
	{
		string vowels_string = "";
		for (short i = 0; i < s1.length(); i++)
		{
			if (is_vowel(s1[i]))
			{
				vowels_string += s1[i];
				vowels_string += "  ";

			}

		}

		return vowels_string;
	}
	string add_all_vowels()
	{
		return add_all_vowels(_value);
	}

	//problem 35/7 ttt
	static void print_each_word(string s1)
	{
		string delim = " ";

		short position = 0;

		string word = "";

		cout << "Your string words are:  \n";
		while ((position = s1.find(delim)) != std::string::npos)
		{
			word = s1.substr(0, position);
			if (word != "")
			{
				cout << word << endl;
			}

			s1.erase(0, position + delim.length());
		}

		if (s1 != "")
		{
			cout << s1 << endl;
		}

	}
	void print_each_word()
	{
		return print_each_word(_value);
	}

	//problem 36/7  ttt
	static short count_words(string s1)
	{
		string delim = " ";

		short position = 0;

		string word = "";

		short counter = 0;

		cout << "The number of words in your string is: ";
		while ((position = s1.find(delim)) != std::string::npos)
		{
			word = s1.substr(0, position);
			if (word != "")
			{
				counter++;
			}

			s1.erase(0, position + delim.length());
		}

		if (s1 != "")
		{
			counter++;
		}

		return counter;

	}
	short count_words()
	{
		return count_words(_value);
	}

	//problem 37/7 ttt
	static vector <string> split(string s1, string delim)
	{
		vector <string> v_name;
		short position = 0;
		string word = "";
		while ((position = s1.find(delim)) != std::string::npos)
		{
			word = s1.substr(0, position);
			if (word != "")
			{
				v_name.push_back(word);
			}

			s1.erase(0, (position + delim.length()));
		}

		if (s1 != "")
		{
			v_name.push_back(s1);
		}

		return v_name;
	}
	vector <string> split(string delim)
	{
		return split(_value,delim);
	}

	//problem 38/7 ttt
	static string tirm_left(string s1)
	{
		for (short i = 0; i < s1.length(); i++)
		{
			if (s1[i] != ' ')
			{
				return s1.substr(i, s1.length() - i);
			}
		}
		return "";
	}
	void tirm_left()
	{
		_value = tirm_left(_value);
	}

	static string tirm_right(string s1)
	{
		for (short i = s1.length() - 1; i >= 0; i--)
		{
			if (s1[i] != ' ')
			{
				return s1.substr(0, i + 1);
			}
		}
		return "";
	}
	void tirm_right()
	{
		_value = tirm_right(_value);
	}

	static string tirm(string s1)
	{
		return tirm_left(tirm_right(s1));
	}
	void tirm()
	{
		_value = tirm(_value);
	}

	//problem 39/7 ttt
	static string join_stirng(vector <string> vstring, string delim)
	{
		string s1 = "";
		for (string& word : vstring)
		{
			s1 += word;
			s1 += delim;
		}
		return s1.substr(0, s1.length() - delim.length());
	}

	//problem 40/7 ttt
	static string join_stirng(string array[], short array_length, string delim)
	{
		string s1 = "";
		for (int i = 0; i < array_length; i++)
		{
			s1 += array[i] + delim;
		}

		return s1.substr(0, s1.length() - delim.length());
	}


	//problem 41/7 ttt
	static string reverse_word(string s1)
	{
		vector <string> v_name = split(s1, " ");
		string s2 = "";

		vector <string>::iterator it = v_name.end();

		while (it != v_name.begin())
		{
			--it;
			s2 += *it + " ";
		}

		return s2.substr(0, s2.length() - 1);

	}
	void reverse_word()
	{
		_value = reverse_word(_value);
	}

	//problem 42/7 ttt
	static string replace_word(string s1, string string_to_replace, string replace_to)
	{

		short position = s1.find(string_to_replace);
		while (position != std::string::npos)
		{
			s1 = s1.replace(position, string_to_replace.length(), replace_to);
			position = s1.find(string_to_replace);
		}

		return s1;
	}
	string replace_word(string string_to_replace, string replace_to)
	{
		return replace_word(_value, string_to_replace, replace_to);
	}

	//problem 44/7 ttt
	static string remove_punctuations(string s1)
	{
		string s2 = "";
		for (short i = 0; i < s1.length(); i++)
		{
			if (!ispunct(s1[i]))
				s2 += s1[i];
		}
		return s2;
	}
	void remove_punctuations()
	{
		_value = remove_punctuations(_value);
	}

};


