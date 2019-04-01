#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>	//used for checking spaces 

#include "Deque.h"

using namespace std;

void is_palindrome(string &s_word, int &i_word_count, int &i_palindrome_count);

int main() {

	cout << "Palindrome searcher using Deque." << endl;
	cout << "Warning one letter words while are palidromes are skipped " << endl << endl;

	string s_filename;
	cout << "Please enter filemane of file to check for palindromes: ";
	cin >> s_filename;

	//openning a file
	ifstream file;
	file.open(s_filename, fstream::in);

	//output in formation
	cout << endl << "Palindromes: " << endl;

	string s_word;
	int i_word_count = 0;
	int i_palindrome_count = 0;

	while (file >> s_word) {

		i_word_count++;

		s_word.erase(remove_if(s_word.begin(), s_word.end(), ispunct), s_word.end());	// removing punctuation from words
		if (s_word.length() == 1)continue;	//comment to disable one letter word skipping

		if (all_of(s_word.begin(), s_word.end(), isspace))continue; //skipping strings only with spaces
		//if (all_of(s_word.begin(), s_word.end(), isdigit))continue; //skipping strings only with numbers CAN BE DISABLED BY UNCOMMENTING PALINDROMIC NUMBERS AND ALL
		if (s_word.length() == 0)continue;	//skipping empty strings just in case

		is_palindrome(s_word, i_word_count, i_palindrome_count);

	}

	system("pause");
	file.close();
	return 0;
}

//functions---------------------------------------------------------------------------

void is_palindrome(string &s_word, int &i_word_count, int &i_palindrome_count) {	//passing by reffrence to use less that 250mb of memory does it work?

	const char* arrc_word = s_word.c_str();
	int i_word_lenght = s_word.length();
	deque c_DQ(100);

	for (int i = 0; i < i_word_lenght; i++) {
		c_DQ.add(arrc_word[i]);
	}

	char front, end;

	while ((c_DQ.size() != 0 && i_word_lenght % 2 == 0) || (c_DQ.size() != 1 && i_word_lenght % 2 == 1)) {

		front = c_DQ.remove_front();
		end = c_DQ.remove_end();

		if (front != end)return;

	}
	i_palindrome_count++;

	cout << i_palindrome_count << ".\t" << s_word << "\t\t\tWord nr." << i_word_count << endl;

	//delete c_DQ; // does delete delete stuff from memory? like wtf 166mb in release mode 
	//ask this shit
}