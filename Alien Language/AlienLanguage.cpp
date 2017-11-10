/////////////////////////////////////////////////////
// SMALL DATA - WORKING
// LARGE DATA - WORKING
/////////////////////////////////////////////////////

#include "stdafx.h"
#define L 15
#define D 5000
#define N 500


using namespace std;
void getTokens(string[L], string[N][L]);
bool checkLetters(char, int, string[D], int);
int count(string[L]);
int countL(string[L]);

string knownWords[D];

int _tmain(int argc, _TCHAR* argv[]){
	system("del s_knownwords.dic");
	system("del s_cases.list");
	system("del s_output.out");

	string testCases[N];
	string patternTokens[N][L];

	ofstream writeDataOnly("s_knownwords.dic", ios::app);
	ofstream writeCases("s_cases.list", ios::app);
	//reading input file
	string tempLine;
	ifstream readIFile("s_alienlanguage.in");
	int l, d, n;
	if (readIFile){
		readIFile >> l;
		readIFile >> d;
		readIFile >> n;

		//getting allien known words
		int i = 0;
		while (i < D){
			readIFile >> knownWords[i];
			writeDataOnly << knownWords[i] << endl;
			i++;
		}
		//getting all cases
		int j = 0;
		while (j < N){
			readIFile >> testCases[j];
			writeCases << testCases[j] << endl;
			j++;
		}
	}
	else cout << "Could not open input file" << endl;

	//Getting tokens from all cases
	getTokens(testCases, patternTokens);

	ofstream writeOFile("s_output.out", ios::app);
	writeCases << tempLine << endl;

	int oNumbers[N];
	for (int i = 0; i < N; i++){
		oNumbers[i] = +count(patternTokens[i]);
		writeOFile << "Case #" << i + 1 << ": " << oNumbers[i] << endl;
	}
	cout << endl;
	for (int i = 0; i < N; i++){
		cout << "Case #" << i + 1 << ": " << oNumbers[i] << endl;
	}
	return 0;
}
bool checkLetters(char token, int index, string dico[D], int thLetter){
	bool r = false;
	for (int i = 0; i < thLetter; i++){
		if (token == dico[i][index]) r = true;
		else r = false;
	}
	return r;
}
void getTokens(string testcase[N], string patternTokens[N][L]){
	for (int i = 0; i < N; i++){
		int k = 0;
		for (int j = 0; j < testcase[i].size(); j++){
			if (testcase[i][j] != '('){
				patternTokens[i][k] = testcase[i][j];
				k++;
			}
			else{
				string tempToken;
				j++;
				while (testcase[i][j] != ')'){
					tempToken = tempToken + testcase[i][j];
					j++;
				}
				patternTokens[i][k] = tempToken;
				k++;
			}
		}

	}
}
int count(string tokens[L]){
	int number = 0;
	char mot[L];
	for (int th = 1; th <= D; th++){
		for (int i = 0; i < tokens[0].size(); i++){
			mot[0] = tokens[0][i];
			if (checkLetters(mot[0], 0, knownWords, th)){
				for (int j = 0; j < tokens[1].size(); j++){
					mot[1] = tokens[1][j];
					if (checkLetters(mot[1], 1, knownWords, th)){
						for (int k = 0; k < tokens[2].size(); k++){
							mot[2] = tokens[2][k];
							if (checkLetters(mot[2], 2, knownWords, th)){
								for (int l = 0; l < tokens[3].size(); l++){
									mot[3] = tokens[3][l];
									if (checkLetters(mot[3], 3, knownWords, th)){
										for (int m = 0; m < tokens[4].size(); m++){
											mot[4] = tokens[4][m];
											if (checkLetters(mot[4], 4, knownWords, th)){
												for (int n = 0; n < tokens[5].size(); n++){
													mot[5] = tokens[5][n];
													if (checkLetters(mot[5], 5, knownWords, th)){
														for (int o = 0; o < tokens[6].size(); o++){
															mot[6] = tokens[6][o];
															if (checkLetters(mot[6], 6, knownWords, th)){
																for (int p = 0; p < tokens[7].size(); p++){
																	mot[7] = tokens[7][p];
																	if (checkLetters(mot[7], 7, knownWords, th)){
																		for (int q = 0; q < tokens[8].size(); q++){
																			mot[8] = tokens[8][q];
																			if (checkLetters(mot[8], 8, knownWords, th)){
																				for (int r = 0; r < tokens[9].size(); r++){
																					mot[9] = tokens[9][r];
																					string str = "";
																					str = str + mot[0] + mot[1] + mot[2] + mot[3] + mot[4] + mot[5] + mot[6] + mot[7] + mot[8] + mot[9];
																					if (checkLetters(mot[9], 9, knownWords, th)){
																						number++;
																						cout << "found ---> " << str << endl;
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return number;
}
int countL(string tokens[L]){
	int number = 0;
	char mot[L];
	for (int th = 1; th <= D; th++){
		for (int i = 0; i < tokens[0].size(); i++){
			mot[0] = tokens[0][i];
			if (checkLetters(mot[0], 0, knownWords, th)){
				for (int j = 0; j < tokens[1].size(); j++){
					mot[1] = tokens[1][j];
					if (checkLetters(mot[1], 1, knownWords, th)){
						for (int k = 0; k < tokens[2].size(); k++){
							mot[2] = tokens[2][k];
							if (checkLetters(mot[2], 2, knownWords, th)){
								for (int l = 0; l < tokens[3].size(); l++){
									mot[3] = tokens[3][l];
									if (checkLetters(mot[3], 3, knownWords, th)){
										for (int m = 0; m < tokens[4].size(); m++){
											mot[4] = tokens[4][m];
											if (checkLetters(mot[4], 4, knownWords, th)){
												for (int n = 0; n < tokens[5].size(); n++){
													mot[5] = tokens[5][n];
													if (checkLetters(mot[5], 5, knownWords, th)){
														for (int o = 0; o < tokens[6].size(); o++){
															mot[6] = tokens[6][o];
															if (checkLetters(mot[6], 6, knownWords, th)){
																for (int p = 0; p < tokens[7].size(); p++){
																	mot[7] = tokens[7][p];
																	if (checkLetters(mot[7], 7, knownWords, th)){
																		for (int q = 0; q < tokens[8].size(); q++){
																			mot[8] = tokens[8][q];
																			if (checkLetters(mot[8], 8, knownWords, th)){
																				for (int r = 0; r < tokens[9].size(); r++){
																					mot[9] = tokens[9][r];
																					if (checkLetters(mot[9], 9, knownWords, th)){
																						for (int r = 0; r < tokens[10].size(); r++){
																							mot[10] = tokens[10][r];
																							if (checkLetters(mot[10], 10, knownWords, th)){
																								for (int r = 0; r < tokens[11].size(); r++){
																									mot[11] = tokens[11][r];
																									if (checkLetters(mot[11], 11, knownWords, th)){
																										for (int r = 0; r < tokens[12].size(); r++){
																											mot[12] = tokens[12][r];
																											if (checkLetters(mot[12], 12, knownWords, th)){
																												for (int r = 0; r < tokens[13].size(); r++){
																													mot[13] = tokens[13][r];
																													if (checkLetters(mot[13], 13, knownWords, th)){
																														for (int r = 0; r < tokens[14].size(); r++){
																															mot[14] = tokens[14][r];
																															string str = "";
																															str = str + mot[0] + mot[1] + mot[2] + mot[3] + mot[4] + mot[5] + mot[6] + mot[7] + mot[8] + mot[9] + mot[10] + mot[11] + mot[12] + mot[13] + mot[14];
																															if (checkLetters(mot[14], 14, knownWords, th)){
																																number++;
																																cout << "found ---> " << str << endl;
																															}
																														}
																													}
																												}
																											}
																										}
																									}
																								}
																							}
																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return number;
}