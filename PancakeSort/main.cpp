#include "PanCakeSort.h"

int main()
{
	string inFileName = "D:/input.txt";
	string outFileName = "D:/Output.txt";
	ifstream inFile;
	inFile.open(inFileName.c_str());
	PanCakeSort m_instance;
	if (inFile.is_open())
	{
		string line;
		vector<int> output;
		while (!inFile.eof()){

			getline(inFile, line);
			int n = 30; // Number of values per line
			int arr[30];

			m_instance.readDatafromFile(line, arr); //Read data from file ("D:/input.txt") line by line to array
			output = m_instance.pancakeSort(arr, n); //Get value of flip
			m_instance.writeDataToFile(output, outFileName, line); // Write data to File ""D:/Output.txt
		}
		inFile.close();
	}
	else {
		cerr << "Can't find input file " << inFileName << endl;
	}
	return 0;
}