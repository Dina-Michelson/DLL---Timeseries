/*
 * timeseries.h
 *
 *  Created on: 26 срхїз 2020
 *      Author: Eli
 */

#ifndef TIMESERIES_H_
#define TIMESERIES_H_
#include <iostream>
#include <string.h>
#include <fstream>
#include<map>
#include <vector>
#include <string.h>
#include <sstream>
//#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

class TimeSeries {


	map<string, vector<float>> ts;
	vector<string> atts;
	size_t dataRowSize;
public:


	TimeSeries(const char* CSVfileName) {
		ifstream in(CSVfileName);
		string head;
		in >> head;
		string att;
		stringstream hss(head);
		if (!in.is_open())printf("opening failed");//changed
		while (getline(hss, att, ',')) {
			vector<float> v;
			ts[att] = v;
			atts.push_back(att);
		}
		while (!in.eof()) {
			
			string line;
			in >> line;
			string val;
			stringstream lss(line);
			int i = 0;
			while (getline(lss, val, ',')) {
				ts[atts[i]].push_back(stof(val));
				i++;
			}
		}
		
		in.close();

		dataRowSize = ts[atts[0]].size();
		cout<<"timeseries created"<<endl;
	}

	const vector<float>& getAttributeData(string name)const {
		return ts.at(name);
	}

	const vector<string>& gettAttributes()const {
		return atts;
	}

	size_t getRowSize()const {
		return dataRowSize;
	}

	~TimeSeries() {

	}
};

//#ifndef TIMESERIES_H_
//#define TIMESERIES_H_
//
//#include <vector>
//#include <map>
//#include <string>
//
//using namespace std;
//
//class TimeSeries {
//private:
//	vector <string> categories;
//	map<string, vector<float>> ContentMap;
//public:
//
//	TimeSeries(const char* CSVfileName);
//	map<string, vector<float>> getMap() const;
//	vector<string> getcategories() const;
//
//};



#endif /* TIMESERIES_H_ */


extern "C" _declspec(dllexport) void* Create(const char* CSVfileName) {
	return (void*) new TimeSeries(CSVfileName);
}

//#endif /* TIMESERIES_H_ */

