#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

class PanCakeSort
{
public:
	PanCakeSort();
	~PanCakeSort();

	void flip(int arr[], int i);
	int findMax(int arr[], int n);
	vector<int> pancakeSort(int* arr, int n);
	int* readDatafromFile(string line, int *arr);
	void writeDataToFile(vector<int> output, string outFileName, string line);
};

