/*
	File: NetRecursionDriver.cpp
	Author: Dalton Brooks
	Project: Program 4
	Due Date: 4/19/
*/
#include<string>
#include<iostream>
#include "Network.h"
using namespace std;

const string file = "network.txt";

const int arrSize = 11;

int main() {
	cout << "Welcome to the Network." << endl;
	Network net = Network();
	node arr[arrSize];
	net.buildNetwork(arr, arrSize, file);
	int start = 0;
	int end = 0;
	bool found = false;
	while (!(start < 0) || !(end < 0)){
		net.printNodes(arr, arrSize);
		cout << "Choose a Starting Node between 0 and " << (arrSize - 1) << ". \nEnter anything else to quit." << endl;
		cin >> start;
		if (start < 0 || start > arrSize-1)
			break;
		cout << "Choose a Ending Node between 0 and " << (arrSize - 1) << ". \nEnter anything else to quit." << endl;
		cin >> end;
		if (end < 0 || end > arrSize-1)
			break;
		cout << "Finding path: \n";
		found = net.findPath(arr, start, end);
		if (found == false) {
			cout << "No path found." << endl;
		}
		net.reset(arr, arrSize);
	}
		cout << "Goodbye." << endl;
	return 0;
}
