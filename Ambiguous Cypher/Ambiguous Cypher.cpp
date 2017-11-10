// Ambiguous Cypher.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define NCases 100

using namespace std;

const char alphabet[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
					'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };

string decipher(string const&);

int _tmain(int argc, _TCHAR* argv[])
{
	system("del S_OUTPUT.OUT");
	system("del L_OUTPUT.OUT");

	//reading input file
	ifstream l_readIFile("A_LARGE.IN");
	ifstream s_readIFile("A_SMALL.IN");
	int temp;
	string l_str_temp[NCases];
	string s_str_temp[NCases];
	if (l_readIFile && s_readIFile){
		l_readIFile >> temp;
		s_readIFile >> temp;
		for (int i = 0; i < NCases; i++) l_readIFile >> l_str_temp[i];
		for (int i = 0; i < NCases; i++) s_readIFile >> s_str_temp[i];
	}
	else cout << "Could not open input file" << endl;

	ofstream l_writeOutput("L_OUTPUT.OUT", ios::app);
	ofstream s_writeOutput("S_OUTPUT.OUT", ios::app);
	for (int i = 0; i < NCases; i++){
		string l_str = decipher(l_str_temp[i]);
		string s_str = decipher(s_str_temp[i]);
		cout << "Case #" << i + 1 << ": " << s_str << "--->" << l_str << endl;
		l_writeOutput << "Case #" << i + 1 << ": " << l_str << endl;
		s_writeOutput << "Case #" << i + 1 << ": " << s_str << endl;
	}
	return 0;
}
int get_index(char c){
	for (int i = 0; i < 26; i++){
		if (alphabet[i] == c) return i;
	}
}
char get_char_from_index(int index){
	return alphabet[index];
}
string form_word(vector<char> t_str){
	string rep = "";
	for (int i = 0; i < t_str.size(); i++) rep += t_str[i];
	return rep;
}
string build_string(string str){
	int size = str.size();
	int temp;
	vector<char> t_word;
	for (int i = 0; i < size; i++) t_word.push_back('#');

	t_word[1] = str[0];
	t_word[size - 2] = str[size - 1];

	for (int index = size - 2; index >= 2; index -= 2){
		temp = get_index(str[index - 1]) - get_index(t_word[index]) + 26;
		t_word[index - 2] = get_char_from_index(temp % 26);
	}
	for (int index = 1; index <= size - 2; index += 2){
		temp = get_index(str[index + 1]) - get_index(t_word[index]) + 26;
		t_word[index + 2] = get_char_from_index(temp % 26);
	}
	return form_word(t_word);
}
string decipher(string const& str){
	if (str.size() % 2 == 1) return "AMBIGUOUS";
	return build_string(str);
}