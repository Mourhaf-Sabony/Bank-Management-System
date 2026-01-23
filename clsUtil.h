#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "clsDate.h"

using namespace std;

class clsUtil
{
public:


	enum en_char_type { smal_letter = 1, capital_letter = 2, digit = 3, mix_chars = 4, special_character = 5 };

	//problem 19
	static void Srand()
	{
		//Seeds the random number generator in C++, called only once
		srand((unsigned)time(NULL));
	}

	static int random_number(int from, int to)
	{
		int rand_number = rand() % (to - from + 1) + from;
		return rand_number;
	}

	//problem 20 
	static char get_random_character(en_char_type char_type)
	{
		if (char_type == mix_chars)
		{
			char_type = (en_char_type)random_number(1, 3);
		}

		switch (char_type)
		{
		case en_char_type::smal_letter:
			return char(random_number(97, 122));
		case en_char_type::capital_letter:
			return char(random_number(65, 90));
		case en_char_type::special_character:
			return char(random_number(33, 47));
		case en_char_type::digit:
			return char(random_number(48, 57));
		default:
			return char(random_number(65, 90));
		}
	}


	//problem 21
	static string generate_word(en_char_type char_type, short length)
	{
		string word = "";
		for (int i = 0; i < length; i++)
		{
			word += get_random_character(char_type);
		}
		return word;
	}

	static string generate_key(en_char_type char_type)
	{
		string key;
		key += generate_word(char_type, 4) + "-";
		key += generate_word(char_type, 4) + "-";
		key += generate_word(char_type, 4) + "-";
		key += generate_word(char_type, 4);
		return key;
	}

	static void generate_keys(en_char_type char_type, short number_of_keys)
	{
		for (int i = 1; i <= number_of_keys; i++)
		{
			cout << "key [" << i << "] = " << generate_key(char_type) << endl;
		}
	}

	//problem 14/4
	static void swap(int& A, int& B)
	{
		int Temp;
		Temp = A;
		A = B;
		B = Temp;
	}

	static void swap(double& A, double& B)
	{
		double Temp;
		Temp = A;
		A = B;
		B = Temp;
	}

	static void swap(bool& A, bool& B)
	{
		bool Temp;
		Temp = A;
		A = B;
		B = Temp;
	}

	static void swap(char& A, char& B)
	{
		char Temp;
		Temp = A;
		A = B;
		B = Temp;
	}

	static void swap(string& A, string& B)
	{
		string Temp;
		Temp = A;
		A = B;
		B = Temp;
	}

	static void swap(clsDate& A, clsDate& B)
	{
		clsDate::swap_dates(A, B);
	}

	//problem 31
	static void shuffle_array(int array[], int array_length)
	{
		for (int i = 0; i < array_length; i++)
		{
			swap(array[random_number(1, array_length) - 1], array[random_number(1, array_length) - 1]);
		}
	}

	static void shuffle_array(string array[], int array_length)
	{
		for (int i = 0; i < array_length; i++)
		{
			swap(array[random_number(1, array_length) - 1], array[random_number(1, array_length) - 1]);
		}
	}

	//problem 23 ***
	static void fill_array_with_random_numbers(int array[], int array_length, int from, int to)
	{

		for (int i = 0; i < array_length; i++)
		{

			array[i] = random_number(from, to);
		}

	}

	static void fill_array_with_random_words(string array[], int array_length, en_char_type char_type, int word_length)
	{
		for (int i = 0; i < array_length; i++)
		{
			array[i] = generate_word(char_type, word_length);
		}

	}

	//problem 33
	static void fill_array_with_keys(string keys[], short number_of_keys, en_char_type char_type)
	{
		for (int i = 0; i < number_of_keys; i++)
		{
			keys[i] = generate_key(char_type);
		}
	}

	//
	static string tabs(short number_of_tabs)
	{
		string tabs = "";
		for (short i = 1; i <= number_of_tabs; i++)
		{
			tabs += "\t";
		}
		return tabs;
	}

	//problem 18

	static string encryption_text(string text, short key)
	{

		for (int i = 0; i < text.length(); i++)
		{
			text[i] = char(text[i] + key);
		}

		return text;
	}

	static string decryption_text(string text, short key)
	{

		for (int i = 0; i < text.length(); i++)
		{
			text[i] = char(text[i] - key);
		}

		return text;
	}




};

