#include "PanCakeSort.h"


PanCakeSort::PanCakeSort()
{
}

PanCakeSort::~PanCakeSort()
{
}

void PanCakeSort::flip(int arr[], int i)
{
	int temp, start = 0;
	while (start < i)
	{
		temp = arr[start];
		arr[start] = arr[i];
		arr[i] = temp;
		start++;
		i--;
	}
}
int PanCakeSort::findMax(int arr[], int n)
{
	int max = 0;
	int positionMax = 0;

	for (int i = 0; i < n; ++i) {
		if (arr[i] >= max)
		{
			max = arr[i];
			positionMax = i;
		}
	}
	return positionMax;
}


vector<int> PanCakeSort::pancakeSort(int* arr, int n)
{
	int i = 0;
	vector <int> output;
	for (int curr_size = n; curr_size > 1; curr_size--)
	{
		//Find max value in sub-array
		int positionMax = findMax(arr, curr_size);
		if (positionMax != curr_size - 1)
		{
			//Flip array follow guide
			flip(arr, positionMax);
			flip(arr, curr_size - 1);

			// Do not print index when positionMax  = 0
			if (positionMax != 0){
				output.push_back(n - positionMax);
			}
			output.push_back(n - curr_size + 1);
		}
	}
	output.push_back(0);

	return output;
}
int* PanCakeSort::readDatafromFile(string line, int *arr)
{
	cout << "Read data from File" << endl;
	int i = 0;
	stringstream stream(line);
	int output[100];
	int numberofInt = 0;
	while (stream >> output[i])
	{
		numberofInt++;
		i++;
	}
	for (int k = 0; k < numberofInt; k++)
	{
		arr[k] = output[k];
	}
	return arr;
}
void PanCakeSort::writeDataToFile(vector<int> output, string outFileName, string line)
{
	ofstream  outFile;
	outFile.open(outFileName.c_str(), ios::app);
	cout << "Write data to File" << endl;
	if (outFile.is_open())
	{
		// Write original stack on one line
		outFile << line << endl;

		// Write sequence of flips
		for (int i = 0; i < output.size(); i++)
		{
			outFile << output.at(i) << " ";
		}
		outFile << endl;
		outFile.close();
	}
}