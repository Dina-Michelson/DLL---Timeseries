// MathLibrary.cpp : Defines the exported functions for the DLL.
#include "pch.h" // use stdafx.h in Visual Studio 2017 and earlier
#include <iostream>
#include <stdio.h>
#include "timeseries.h"
using namespace std;

/*extern "C"
{
    __declspec(dllexport) void DisplayHelloFromDLL()
    {
        printf("Hello from DLL Dina is sooo awesome and Tzvi maybe is too!\n");
    }
}

extern "C"
{
    __declspec(dllexport) void AddingFromDll()
    {
        cout << "please enter a number between 1 and 10" << endl;
        int num;
        cin >> num;
        int sol = 5 + num;
        printf("%d + 5 = %d\n", num, sol);
    }
}*/

//#include "timeseries.h"
//#include <fstream>
//#include <map>
//#include <iostream>
//#include <string>
//#include <vector>
//#include <sstream> 
//
//using namespace std;
//
//
//TimeSeries::TimeSeries(const char* CSVfileName) {
//	
//	fstream content;
//	content.open(CSVfileName);
//
//	
//	//if file isn't proper
//	//if (!content.is_open())  throw runtime_error("content not found");
//	if (!content.is_open())  printf("content not found");
//	printf("half way");
//	std::string nextline, catagory, val;
//	
//	if (content.good()) {
//		
//		getline(content, nextline);
//		stringstream firstline(nextline);
//		//initializing the catagory vector
//		while (getline(firstline, catagory, ',')) {
//			categories.push_back(catagory);
//		}
//		//inserting keys and values into the map
//		int size = categories.size();
//		
//		for (int i = 0; i < size; i++) {
//			this->ContentMap.insert({ categories[i], std::vector<float> {} });
//		}
//		//printf("half way");
//		//filling the float vectors 
//		while (std::getline(content, nextline)) {
//			std::stringstream line;
//			line.str(nextline);
//			int i = 0;
//			while (getline(line, val, ',')) {
//				try { ContentMap[categories[i]].push_back(stof(val)); }
//				catch (exception c) { cout << "illegal conversion attempt" << endl; }
//				i++;
//			}
//		}
//		
//		/*for (auto it = ContentMap.begin(); it != ContentMap.end(); ++it) {
//			cout << it->first << " : ";
//			std::vector<float> inVect = it->second;
//			for (unsigned j = 0; j < inVect.size(); j++) {
//				cout << inVect[j] << " ";
//			}
//			cout << endl;
//		}*/
//	}
//
//}
////getter for the map
//map<string, vector<float>> TimeSeries::getMap() const {
//	return this->ContentMap;
//}
//
////getter for the catagory vector
//vector<string> TimeSeries::getcategories() const {
//	return this->categories;
//}*/
//
//extern "C" _declspec(dllexport) void* Create(const char* CSVfileName) {
//	return (void*) new TimeSeries(CSVfileName);
//}






