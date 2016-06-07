#pragma once
#include <string>
#include<iostream>
#include<fstream>

using namespace std;

class Department {
	char name[100];
	int ID;

public:
	void readFromFile(ifstream);
	void printDepartment() const;
	Department();
};