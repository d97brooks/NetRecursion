/*
File: Network.h
Author: Dalton Brooks
Project: Program 4
Due Date: 4/19/
*/
#pragma once
#include<iostream>
#include<string>
using namespace std;
const int startingSize = 4;

typedef int elementType;
struct node;
struct node
{
	elementType position;
	int adjacenices[startingSize];
	int numOfAdj = 0;
	bool visited = false;
};

class Network
{

public:
	Network();
	/*virtual ~Network();*/
	bool buildNetwork(node nodes[], int size, string filename);
	bool findPath(node nodes[], int position, int find);
	void reset(node nodes[], int size);
	void Network::printNodes(node nodes[], int size);
};
