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
#include <list>
#include "anomaly_detection_util.h" 

using namespace std;

class TimeSeries {


	map<string, vector<float>> ts;
	vector<string> atts;
	int dataRowSize;
public:


	TimeSeries(const char* CSVfileName, char** l, int size) {
		ifstream in(CSVfileName);
		string head;
		in >> head;
		string att;
		stringstream hss(head);
		if (!in.is_open())printf("opening failed");//changed
		/*while (getline(hss, att, ',')) {
			vector<float> v;
			ts[att] = v;
			atts.push_back(att);
		}*/
		int k = 0;
		while (k < size) {
			vector <float> v;
			ts[l[k]] = v;
			atts.push_back(l[k]);
			k++;
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
		//cout<<"timeseries created"<<endl;
	}

	const vector<float>& getAttributeData(string name)const {
		/*for (int i = 0; i < v.size(); i++) {
			cout << v.at(i) << endl;
		}*/
		return ts.at(name);
	}

	const vector<string>& gettAttributes()const {
		return atts;
	}

	int getRowSize()const {
		return dataRowSize;
	}

	const float givesFloatTs(int line, const char* att) {
		return getAttributeData(att).at(line);
	}

	vector<Point*> floatsToPoints(vector <float> x, vector <float> y) {
		vector<Point*> points_vector;
		//creating a vector of pointers to points to send to lin_reg
		int s = x.size();
		for (int i = 0; i < s; i++) {
			Point* p = new Point(x[i], y[i]);
			points_vector.push_back(p);
		}
		return points_vector;
	}

	void find_lin_reg(float &a,float &b, const char* attA, const char* attB) {
		vector<float> v1 = getAttributeData(attA);
		vector<float> v2 = getAttributeData(attB);
		vector<Point*> pointv = floatsToPoints(v1, v2);
		Line l = linear_reg(pointv.data(), v1.size());
		a = l.a;
		b = l.b;
	}


	~TimeSeries() {

	}
};

#endif /* TIMESERIES_H_ */


extern "C" _declspec(dllexport) void* Create(const char* CSVfileName, char** l,int size) {
	return (void*) new TimeSeries(CSVfileName, l, size);
}

extern "C" _declspec(dllexport) float givesFloatTs(TimeSeries* obj, int line, const char* att) {
	return obj->givesFloatTs(line, att);
}

extern "C" __declspec(dllexport) void DisplayHelloFromDLL(){
		printf("Hello from DLL Dina is sooo awesome and Tzvi maybe is too!!!\n");
}


extern "C" __declspec(dllexport) int getRowSize(TimeSeries* ts) {
	return ts->getRowSize();
}


extern "C" __declspec(dllexport) void findLinReg(TimeSeries * ts, float& a, float& b, const char* attA, const char* attB) {
	return ts->find_lin_reg(a, b, attA, attB);
}

//#endif /* TIMESERIES_H_ */

