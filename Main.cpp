//Author: Michael Hernandez
//BCS 230 Capstone Project: Midterm draft
//Date last modified: May 7, 2016

#include<iostream>
#include<fstream>
#include<string>
#include "Functions.h"


int main() {
	const int MAX_SIZE = 100;//stores maximum size for the department, staff, and patient arrays
	int choice, subchoice;//used to store user choices in the main menu and submenus
	std::ifstream inFiled, inFilep, inFiles;//used to perform operations on input files
	std::ofstream outFileD, outFileP, outFileS;//used to perform operations on output files

	Department departmentList[MAX_SIZE];//stores information on up to the MAX_SIZE of departments
	Staff staffList[MAX_SIZE];//stores information on up to the MAX_SIZE of staff members
	Patient patientList[MAX_SIZE];//stores information on up to the MAX_SIZE of patients
	int numOfDepartments = 0;//keeps track of the number of departments stored in departmentList for use in the program
	int numOfStaff = 0;//keeps track of the number of staff members stored in staffList for use in the program
	int numOfPatients = 0;//keeps track of the number of staff members stored in patientList for use in the program
	
	inFileOperations(inFiled, inFiles, inFilep, departmentList, staffList, patientList, numOfDepartments, numOfStaff, numOfPatients, MAX_SIZE);// infile operations

	welcomeScreen();//displays welcome screen for program
	displayFirstMenu();//displays the main menu for the first time
	std::cin >> choice;//takes in user choice for the first time

	while (choice != 4) {
		std::cout << std::endl;//formatting
		menuSelection(choice);
		if (choice < 4 && choice > 0)
			std::cin >> subchoice;
		std::cout << std::endl;//formatting
		while(subchoice != 6){
			subMenusFunction(choice, subchoice, departmentList, staffList, patientList, numOfDepartments, numOfStaff, numOfPatients);
			menuSelection(choice);
			std::cin >> subchoice;
		}
		displayFirstMenu();
		std::cin >> choice;
		
	} //main menu loop with nested submenus

	outFileOperations(outFileD, outFileS, outFileP, departmentList, staffList, patientList, numOfDepartments, numOfStaff, numOfPatients);//outfile operations

	std::cout << "Thank you for using the program! Goodbye!" << std::endl;//closing message
	
	return 0;
}
