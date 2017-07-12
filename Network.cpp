/*
File: Network.cpp
Author: Dalton Brooks
Project: Program 4
Due Date: 4/19/
*/
#include "Network.h"
#include<string>
#include<iostream>
#include<fstream>

using namespace std;


Network::Network(){

}

bool Network::buildNetwork(node arr[], int size, string file) {
	
	ifstream net;
	
	net.open(file);
	if (!net.is_open()) {
		cout << "file failed to open.";
		return false;
	}
	for (int i = 0; i < size; i++)
	{
		arr[i].position = i;
		int adj = 0;
		int temp = -1;
		net >> temp;
		while (temp != -1) {
			arr[i].adjacenices[adj] = temp;
			adj++;
			net >> temp;
		}
		arr[i].numOfAdj = adj;
	}
	return true;
}
bool Network::findPath(node nodes[], int position, int find) {

	nodes[position].visited = true;

	if (nodes[position].position == nodes[find].position) {
		cout << "** node#" << find << " found!\n";
		return true;
	}
	if ((nodes[position].numOfAdj == 1) && (nodes[nodes[position].adjacenices[0]].visited == true)) {
		return false;
	}



	for (int i = 0; i < nodes[position].numOfAdj; i++) {
		if ((nodes[nodes[position].adjacenices[i]].visited == false) && (nodes[find].visited == false)) {
			findPath(nodes, nodes[position].adjacenices[i], find);
		}
	}
	if (nodes[find].visited == true) {
		cout << "** node#" << position << " on path! **" << endl;
		return true;
	}
	else{
		return false;
	}
}
void Network::reset(node nodes[], int size) {
	for (int i = 0; i < size; i++)
	{
		nodes[i].visited = false;
	}
}
void Network::printNodes(node nodes[], int size) {
	for (int i = 0; i < size; i++)
	{
		cout << "Node " << i << ": ";
		for (int j = 0; j < nodes[i].numOfAdj; j++)
		{
			cout << nodes[i].adjacenices[j] << " ";
		}
		cout << endl;
	}
}
