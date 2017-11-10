/////////////////////////////////////////////////////
// SMALL DATA - WORKING
// LARGE DATA - WORKING
/////////////////////////////////////////////////////

#include "stdafx.h"

//#define NCases 1000 //large data
#define NCases 10 //small data

using namespace std;

void writeData();
BigInteger smallestScalarProduct(vector<int>, vector<int>);

int _tmain(int argc, _TCHAR* argv[]){
	system("del l_only.data");
	system("del l_output.out");

	int vSize[NCases];
	//arrays of all vector input
	vector<vector<int>> v1;
	vector<vector<int>> v2;

	//Witting data - success!
	writeData();

	//Getting cases - success!
	ifstream readDataFile("l_only.data");
	if (readDataFile){
		for (int i = 0; i < NCases; i++){
			readDataFile >> vSize[i];
			int val;
			vector<int> vTemp1;
			for (int k = 0; k < vSize[i]; k++){
				readDataFile >> val;
				vTemp1.push_back(val);
			}
			vector<int> vTemp2;
			for (int l = 0; l < vSize[i]; l++){
				readDataFile >> val;
				vTemp2.push_back(val);
			}
			//pushing the temp arrays BigIntegero the array of vector
			v1.push_back(vTemp1);
			v2.push_back(vTemp2);
		}
	}
	else cout << "Could not read data" << endl;

	//Generating output file
	BigInteger nOutput[NCases];
	ofstream writeOutput("l_output.out", ios::app);
	for (int i = 0; i < NCases; i++){
		nOutput[i] = smallestScalarProduct(v1[i], v2[i]);
		writeOutput << "Case #" << i + 1 << ": " << nOutput[i] << endl;
		cout << "Case #" << i + 1 << ": " << nOutput[i] << endl;
	}
	return 0;
}
//functions
BigInteger scalarProduct(vector<int> v1, vector<int> v2){
	BigInteger sc = 0;
	int lastIndex = v1.size() - 1;
	//for (BigInteger i = 0; i <= v1.size(); i++) sc += (v1[i] * v2[i]);	//normal scalar product
	for (int i = 0; i <= lastIndex; i++) sc += (v1[i] * v2[lastIndex - i]);
	return sc;
}
BigInteger smallestScalarProduct(vector<int> sV1, vector<int> sV2){
	sort(sV1.begin(), sV1.end());
	sort(sV2.begin(), sV2.end());
	return scalarProduct(sV1, sV2);
}
void writeData(){
	ifstream readIFile("l_mScalarProduct.in");
	if (readIFile){
		ofstream writeData("l_only.data", ios::app);
		//for (BigInteger i = 0; i < 5; i++){ //for small data
		for (int i = 0; i < 3; i++){ //for large data
				readIFile.seekg(1, ios::cur);
		}
		string line;
		while (getline(readIFile, line)){
			writeData << line << endl;
		}
	}
	else cout << "Could not read input file" << endl;
}