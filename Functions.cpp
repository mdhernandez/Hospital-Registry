//Author: Michael Hernandez
//BCS 230 Capstone Project: Midterm draft
//Date last modified: May 7, 2016

#include <string>
#include<iostream>
#include<fstream>
#include "Functions.h"


void Department::readFromFile(std::ifstream& inFile) {
	deptName = readCharArrayFromFiletoString(inFile); 
	inFile >> ID;
	inFile.ignore();
}

void Department::printToFile(std::ofstream& outFile) {
	outFile << deptName << "," << ID;
}

void Department::setDeptName(std::string departmentN) {
	deptName = departmentN;
}

void Department::setDeptID(int departmentID) {
	ID = departmentID;
}

int Department::getDeptID() const {
	return ID;
}

std::string Department::getDeptName() const {
	return deptName;
}

void Department::printDepartment() const {//tentative
	std::cout << "Department Name: " << deptName << std::endl;
	std::cout << "Department ID: " << ID << std::endl;
}

void listAllDepartments(Department departmentObject[], int numOfDepts) {
	
	if (numOfDepts == 0) {
		std::cout << "There are no departments listed in the registry." << std::endl << std::endl;
	}
	else {
		departmentBubbleSort(departmentObject, numOfDepts);
		for (int i = 0; i < numOfDepts; i++) {
			departmentObject[i].printDepartment();
			std::cout << std::endl;
		}
	}
}

Department::Department() {
	deptName = "";
	ID = 0;
}

void Staff::setStaffID(int sID) {
	staffID = sID;
}

void Staff::setStaffType(char sType) {
	staffType = sType;
}

int Staff::getStaffID() const {
	return staffID;
}

void Staff::printStaff() const{
	std::string jobType = "";
	switch (staffType) {
	case 'D':
		jobType = "Doctor";
		break;
	case 'N':
		jobType = "Nurse";
		break;
	case 'A':
		jobType = "Administrator";
	}

	std::cout << "Name: " << jobType << " " << getFirstName() << " " << getLastName() << std::endl;
	std::cout << "Staff ID: " << staffID << std::endl;
	std::cout << "Department ID: " << staffDept.getDeptID() << std::endl;
	std::cout << "Gender: " << getGender() << std::endl;
	std::cout << "Birthday: " << getBirthMonth() << "/" << getBirthDay() << "/"
		<< getBirthYear() << std::endl;

	int numberOfPhones;

	if (staffContact.getPhoneNoAmount() > 1)
		numberOfPhones = staffContact.getPhoneNoAmount();
	else
		numberOfPhones = 1;



	std::cout << "Phone Number: ";

	for (int i = 0; i < numberOfPhones; i++) {
		std::cout << staffContact.phoneNo[i] << std::endl;
	}
	int numberOfEmails;

	if (staffContact.getEmailAmount() > 1)
		numberOfEmails = staffContact.getEmailAmount();
	else
		numberOfEmails = 1;

	std::cout << "E-mail: ";
	for (int i = 0; i < numberOfEmails; i++) {
		std::cout << staffContact.email[i] << std::endl;
	}
}

void listAllStaff(Staff staffObject[], int numOfStaff) {
	if (numOfStaff == 0) {
		std::cout << "There are no staff members listed in the registry." << std::endl << std::endl;
	}
	else {
		staffBubbleSort(staffObject, numOfStaff);

		for (int i = 0; i < numOfStaff; i++) {
			staffObject[i].printStaff();
			std::cout << std::endl;
		}
	}
}

void Staff::readFromFile(std::ifstream& inFile) {
	char c;//removes commas
	char gender;
	int birthD, birthM, birthY;
	int departmentID;
	if (inFile.good()) {
		inFile >> staffType >> c;
		setFirstName (readCharArrayFromFiletoString(inFile));
		setLastName (readCharArrayFromFiletoString(inFile));
		inFile >> staffID >> c >> departmentID >> c >> birthM >> c
			>> birthD >> c >> birthY >> c
			>> gender >> c;
		staffContact.phoneNo[0] = readCharArrayFromFiletoString(inFile);
		getline(inFile, staffContact.email[0]);
		
		staffDept.setDeptID(departmentID);
		setBirthDay(birthD);
		setBirthMonth(birthM);
		setBirthYear(birthY);
		setGender(gender);
	}
}

void Staff::printToFile(std::ofstream& outFile) {
	
	outFile << staffType << ",";
	outFile << getFirstName() << "," << getLastName() << ",";
	outFile << staffID << ",";
	outFile << staffDept.getDeptID() << ",";//department ID
	outFile << getBirthMonth() << "/" << getBirthDay() << "/"
		<< getBirthYear() << ",";
	outFile << getGender() << ",";
	outFile << staffContact.phoneNo[0] << ",";
	outFile << staffContact.email[0];
}

char Staff::getStaffType() const {
	return staffType;
}

Staff::Staff(int id, int deptID, char gen, int sDay, int sMonth, int sYear, int sEmailAm, int sPhoneAmount, std::string sEmail, std::string sPhoneNo, char sStaffType) {
	staffID = id;
	staffDept.setDeptID(deptID);
	setGender(gen);
	setBirthDay(sDay);
	setBirthMonth(sMonth);
	setBirthYear(sYear);
	staffContact.setNumOfEmail(sEmailAm);
	staffContact.setNumofPhones(sPhoneAmount);
	staffContact.setAnEmail(sEmail, 0);
	staffContact.setANumber(sPhoneNo, 0);
	staffType = sStaffType;
}

void Patient::setID(int patientIdent) {
	patientID = patientIdent;
}

void Patient::setBirthday(int pbirthDay, int pbirthMonth, int pbirthYear) {
	setBirthDay (pbirthDay);
	setBirthMonth (pbirthMonth);
	setBirthYear (pbirthYear);
}

int Patient::getPatientID() const {
	return patientID;
}

void Patient::printPatientInfo() const{//List All 

	std::cout << "Name: " << getFirstName() << " " << getLastName() << std::endl;
	std::cout << "Patient ID: " << patientID << std::endl;
	std::cout << "Gender: " << getGender() << std::endl;
	std::cout << "Birthday: " << getBirthMonth() << "/" << getBirthDay() << "/"
		<< getBirthYear() << std::endl;
	std::cout << "Phone Number: "<< patientContact.phoneNo << std::endl;
	std::cout << "Email: " << patientContact.email << std::endl;
	std::cout << "Address: " << patientContact.patientAddress.addNo << " " << patientContact.patientAddress.streetName << std::endl;
	std::cout << patientContact.patientAddress.cityName << ", " << patientContact.patientAddress.stateName << " "
		<< patientContact.patientAddress.zipCode << std::endl;
}

void listAllPatients(Patient patientObject[], int numOfPatients) {
	if (numOfPatients == 0) {
		std::cout << "There are no patients listed in the registry." << std::endl << std::endl;
	}
	else {
		patientBubbleSort(patientObject, numOfPatients);

		for (int i = 0; i < numOfPatients; i++) {
			patientObject[i].printPatientInfo();
			std::cout << std::endl;
		}
	}
}

Patient::Patient(int pID, int sID, char pGender, int pDay, int pMonth, int pYear, std::string pFirst, std::string pLast, std::string pEmail, std::string pPhoneNo, int pAddressNo, std::string pStreetName, std::string pCityName, std::string pStateName, int pZipCode)
	:Person(pGender, pMonth, pDay, pYear, pFirst, pLast)
{
	patientID = pID;
	attendingStaffID = sID;
	patientContact.email = pEmail;
	patientContact.phoneNo = pPhoneNo;
	patientContact.patientAddress.addNo = pAddressNo;
	patientContact.patientAddress.cityName = pCityName;
	patientContact.patientAddress.streetName = pStreetName;
	patientContact.patientAddress.stateName = pStateName;
	patientContact.patientAddress.zipCode = pZipCode;
}

void Patient::readFromFile(std::ifstream& inFile) {
	char c;//eliminates commas
	char gender;
	int birthDay, birthMonth, birthYear;
	if (inFile.good()) {
		setFirstName(readCharArrayFromFiletoString(inFile));
		setLastName(readCharArrayFromFiletoString(inFile));
		inFile >> patientID >> c >> attendingStaffID >> c >> birthMonth >> c >> birthDay;
		inFile >> c >> birthYear >> c >> gender >> c >> patientContact.patientAddress.addNo >> c;
		
		patientContact.patientAddress.streetName = readCharArrayFromFiletoString(inFile);
		patientContact.patientAddress.cityName = readCharArrayFromFiletoString(inFile);
		patientContact.patientAddress.stateName = readCharArrayFromFiletoString(inFile);
		inFile >> patientContact.patientAddress.zipCode >> c;
		patientContact.phoneNo = readCharArrayFromFiletoString(inFile);
		getline(inFile, patientContact.email);

		setBirthMonth(birthMonth);
		setBirthDay(birthDay);
		setBirthYear(birthYear);
		setGender(gender);
	}
}

void Patient::printToFile(std::ofstream& outFile) {
	outFile << getFirstName() << "," << getLastName() << ",";
	outFile << patientID << ",";
	outFile << getAttendingID() << ",";
	outFile << getBirthMonth() << "/" << getBirthDay() << "/"
		<< getBirthYear()<< ",";
	outFile << getGender() << ",";
	outFile << patientContact.patientAddress.addNo << "," << patientContact.patientAddress.streetName << ",";
	outFile << patientContact.patientAddress.cityName << "," << patientContact.patientAddress.stateName << ","
		<< patientContact.patientAddress.zipCode << ",";
	outFile << patientContact.phoneNo << ",";
	outFile << patientContact.email;
}

void Patient::setAddress(int houseNum, std::string street, std::string city, std::string stateInit, int zipNum) {
	patientContact.patientAddress.addNo = houseNum;
	patientContact.patientAddress.streetName = street;
	patientContact.patientAddress.cityName = city;
	patientContact.patientAddress.stateName = stateInit;
	patientContact.patientAddress.zipCode = zipNum;
}

void Patient::setPhoneNum(std::string phone) {
	patientContact.phoneNo = phone;
}

void Patient::setEmail(std::string pEmail) {
	patientContact.email = pEmail;
}

void Patient::setPatientContactInfo(PatientContactInfo newPatientContact) {
	patientContact = newPatientContact;
}

void Person::setFirstName(std::string personFirstName) {
	firstName = personFirstName;
}

void Person::setLastName(std::string personLastName) {
	lastName = personLastName;
}

void Person::setGender(char personGender) {
	gender = personGender;
}

void Person::setBirthDay(int bDay){
	birthD.day = bDay;
}

void Person::setBirthMonth(int bMonth) {
	birthD.month = bMonth;
}

void Person::setBirthYear(int bYear) {
	birthD.year = bYear;
}

int Person::getBirthDay()const {
	return birthD.day;
}

int Person::getBirthMonth()const {
	return birthD.month;
}

int Person::getBirthYear() const {
	return birthD.year;
}

char Person::getGender() const {
	return gender;
}

std::string Person::getFirstName() const {
	return firstName;
}

std::string Person::getLastName() const {
	return lastName;
}

void displayFirstMenu() {
	std::cout << "1. Department menu" << std::endl;
	std::cout << "2. Staff menu" << std::endl;
	std::cout << "3. Patient menu" << std::endl;
	std::cout << "4. Exit" << std::endl;
}

void welcomeScreen() {
	std::cout << "Welcome to the hospital menu program!" << std::endl << std::endl;
	std::cout << "The purpose of this program is to store and present information about your hospital." << std::endl;
	std::cout << "Below is the main menu, Enter 1-3 to select one of the options to be taken to a different section of the program." << std::endl
		<<"To exit the program from the main menu Enter the number 4" << std::endl << std::endl;
}

void menuSelection(int theChoice){
	switch (theChoice) {
	case 1:
		displayDeptSubMenu();
		break;
	case 2:
		displayStaffSubMenu();
		break;
	case 3:
		displayPatientSubMenu();
		break;
	default:
		std::cout << "Invalid Selection. Try again." << std::endl;
		break;
	}
}

void displayDeptSubMenu() {
	std::cout << "1. List all departments" << std::endl;
	std::cout << "2. Add a department" << std::endl;
	std::cout << "3. Search for a department" << std::endl;
	std::cout << "4. Edit a department's information" << std::endl;
	std::cout << "6. Return to main menu" << std::endl;
}

void displayStaffSubMenu() {
	std::cout << "1. List all employees" << std::endl;
	std::cout << "2. Add an employee" << std::endl;
	std::cout << "3. Search for an employee" << std::endl;
	std::cout << "4. Edit an employee's information" << std::endl;
	std::cout << "6. Return to main menu" << std::endl;
}

void displayPatientSubMenu() {
	std::cout << "1. List all patients" << std::endl;
	std::cout << "2. Add a patient" << std::endl;
	std::cout << "3. Search for a patient" << std::endl;
	std::cout << "4. Edit a patient's information" << std::endl;
	std::cout << "6. Return to main menu" << std::endl;
}

void subMenusFunction(int choice, int subchoice, Department departmentObject[], Staff staffObject[], Patient patientObject[], int &numOfDepts, int &numOfStaff, int &numOfPatients){
	int newSearchID;
	int idForPrint = 0;
	
	
	switch (choice) {
	case 1:
		switch (subchoice) {
		case 1:
			listAllDepartments(departmentObject, numOfDepts);
			break;
		case 2:
			addADepartment(departmentObject, numOfDepts);
			std::cout << std::endl;
			break;
		case 3: {
			std::cout << "Enter department ID: ";
			std::cin >> newSearchID;
			std::cout << std::endl;
			bool isFound = searchDept(departmentObject, numOfDepts, idForPrint, newSearchID);
			if (isFound) {
				departmentObject[idForPrint].printDepartment();
				std::cout << std::endl;
			}
			else {
				std::cout << "Department not found." << std::endl << std::endl;
			}
			break;
		}

		case 4:
			std::cout << "Enter the department ID or the department you wish to edit: ";
			std::cin >> newSearchID;
			std::cout << std::endl;

			editDepartment(departmentObject, numOfDepts, newSearchID);
			break;
		default:
			std::cout << "Invalid Selection. Please try again." << std::endl << std::endl;
		}
		break;
	case 2:
		switch (subchoice) {
		case 1:
			listAllStaff(staffObject, numOfStaff);
			break;
		case 2:
			addAStaffMember(staffObject, departmentObject, numOfStaff, numOfDepts);
			std::cout << std::endl;
			break;
		case 3: {
			std::cout << "Enter staff member ID: ";
			std::cin >> newSearchID;
			std::cout << std::endl;

			bool isFound = searchStaffMember(staffObject, numOfStaff, idForPrint, newSearchID);
			if (isFound) {
				staffObject[idForPrint].printStaff();
				std::cout << std::endl;
				int newDeptIndex = staffObject[idForPrint].staffDept.getDeptID();
				bool isDeptFound = searchDept(departmentObject, numOfDepts, idForPrint, newDeptIndex);
				if (isDeptFound) {
					std::cout << "Department Information:" << std::endl << std::endl;
					departmentObject[idForPrint].printDepartment();
					std::cout << std::endl;
				}
			}
			else {
				std::cout << "Staff member not found." << std::endl << std::endl;
			}
			break;
		}

		case 4:
			std::cout << "Enter the Staff ID of the staff member whose information you wish to edit: ";
			std::cin >> newSearchID;
			std::cout << std::endl;

			editStaffMember(staffObject, numOfStaff, newSearchID, departmentObject, numOfDepts);
			break;
			
		default:
			std::cout << "Invalid selection. Please try again." << std::endl << std::endl;
			break;
		}
		break;
	case 3:
		switch (subchoice) {
		case 1:
			listAllPatients(patientObject, numOfPatients);
			break;
		case 2:
			addAPatient(patientObject, staffObject, numOfPatients, numOfStaff);
			std::cout << std::endl;
			break;
		case 3: {
			std::cout << "Enter Patient ID: ";
			std::cin >> newSearchID;
			std::cout << std::endl;

			bool isFound = searchPatient(patientObject, numOfPatients, idForPrint, newSearchID);
			if (isFound) {
				patientObject[idForPrint].printPatientInfo();
				std::cout << std::endl;
				int newDoctorID = patientObject[idForPrint].getAttendingID();
				bool isDoctorFound = searchStaffMember(staffObject, numOfStaff, idForPrint, newDoctorID);
				if (isDoctorFound) {
					std::cout << "Attending Staff Member Information: " << std::endl << std::endl;
					staffObject[idForPrint].printStaff();
					std::cout << std::endl;
				}
			}
			else {
				std::cout << "Patient not found." << std::endl << std::endl;
			}

			break;
		}
		case 4:
			std::cout << "Enter the ID of the patient whose information you wish to edit: ";
			std::cin >> newSearchID;
			std::cout << std::endl;

			editPatient(patientObject, numOfPatients, newSearchID, staffObject, numOfStaff);
			break;
		default:
			std::cout << "Invalid selection. Please try again." << std::endl << std::endl;
		}
		break;
	}

}

std::string readCharArrayFromFiletoString(std::ifstream& inFile) {
	char c;
	int characterCount = 0;
	char name[100];

	while (inFile.get(c)) {

		if (c == ',')
			break;
		name[characterCount] = c;
		characterCount++;
	}
	std::string nameChar(name, characterCount);
	return nameChar;
}

void addADepartment(Department departmentObject[], int &departmentSize) {
	std::string deptName;
	int deptID;
	

	std::cout << "Enter the following information about the department you want to add." << std::endl;
	std::cout << "Name: ";
	std::cin.ignore();
	getline(std::cin, deptName);
	departmentObject[departmentSize].setDeptName(deptName);
	std::cout << std::endl;

	std::cout << "ID: ";
	std::cin >> deptID;
	departmentObject[departmentSize].setDeptID(deptID);

	departmentSize++;
}

void addAStaffMember(Staff staffObject[], Department departmentObject[], int &staffSize, int numOfDepartments) {
	int newStaffID;
	int newDeptID;
	char newStaffType;
	
	std::cout << "Enter the following information about the staff member you wish to add." << std::endl;
	
	std::cout << "Staff ID: ";
	std::cin >> newStaffID;
	std::cout << std::endl;

	staffObject[staffSize].setStaffID(newStaffID);

	std::cout << "Staff Type(enter A for administrator, D for doctor, or N for nurse): ";
	std::cin >> newStaffType;
	std::cout << std::endl;

	std::cout << "Department ID: ";
	std::cin >> newDeptID;
	std::cout << std::endl;

	staffObject[staffSize].staffDept.setDeptID(newDeptID);

	while (!doesDeptIdExist(departmentObject, staffObject[staffSize].staffDept.getDeptID(), numOfDepartments)) {
		std::cout << "Invalid Department ID. Please reenter an existing Department ID: ";
		std::cin >> newDeptID;
		std::cout << std::endl;
		staffObject[staffSize].staffDept.setDeptID(newDeptID);
	}
	std::string fName;
	std::cout << "First Name: ";
	std::cin >> fName;
	std::cout << std::endl;

	std::string lName;
	std::cout << "Last Name: ";
	std::cin >> lName;
	std::cout << std::endl;

	char gender;
	std::cout << "Gender (M or F): ";
	std::cin >> gender;
	std::cout << std::endl;

	int bDay, bMonth, bYear;

	std::cout << "Birthday (month day year) seperated by spaces: ";
	std::cin >> bMonth >> bDay >> bYear;
	std::cout << std::endl;

	std::cout << "How many phone numbers would you like to store?: ";
	int phoneNumAmount;
	std::cin >> phoneNumAmount;

	staffObject[staffSize].staffContact.setNumofPhones(phoneNumAmount);

	std::string newNumber = "";
	std::cin.ignore();

	for (int i = 0; i < staffObject[staffSize].staffContact.getPhoneNoAmount(); i++) {
		if(i == 0)
			std::cout << "Enter Phone number: ";
		else {
			std::cout << "Enter Phone number #" << i + 1 << ": ";
		}

		
		getline(std::cin, newNumber);
		std::cout << std::endl;

		staffObject[staffSize].staffContact.setANumber(newNumber, i);
	}
	std::cout << "How many E-mail addresses would you like to store?: ";
	int howManyEmail;
	std::cin >> howManyEmail;

	staffObject[staffSize].staffContact.setNumOfEmail(howManyEmail);
	std::string newEmail = "";
	std::cin.ignore();
	for (int i = 0; i < staffObject[staffSize].staffContact.getEmailAmount(); i++) {
		
		if(i == 0)
			std::cout << "E-mail: ";
		else {
			std::cout << "E-mail #" << i + 1 << ": ";
		}
		
		getline(std::cin, newEmail);
		std::cout << std::endl;
		staffObject[staffSize].staffContact.setAnEmail(newEmail, i);
	} 

	staffObject[staffSize].setStaffType(newStaffType);
	staffObject[staffSize].setFirstName(fName);
	staffObject[staffSize].setLastName(lName);
	staffObject[staffSize].setGender(gender);
	staffObject[staffSize].setBirthDay(bDay);
	staffObject[staffSize].setBirthMonth(bMonth);
	staffObject[staffSize].setBirthYear(bYear);
	staffSize++;
}

void addAPatient(Patient patientObject[], Staff staffObject[], int &patientIndex, int numOfStaff) {
	
	Person newPatient;
	PatientContactInfo newPatientContact;
	int newPatientID;
	int patientAttendingStaffID;

	std::cout << "Enter the following information about the patient you wish to add." << std::endl;

	std::string fName;
	std::cout << "First Name: ";
	std::cin >> fName;
	std::cout << std::endl;

	std::string lName;
	std::cout << "Last Name: ";
	std::cin >> lName;
	std::cout << std::endl;

	std::cout << "Patient ID: ";
	std::cin >> newPatientID;
	std::cout << std::endl;
	
	std::cout << "Doctor ID: ";
	std::cin >> patientAttendingStaffID;
	std::cout << std::endl;

	patientObject[patientIndex].setAttendingID(patientAttendingStaffID);

	while (!doesStaffMemberExist(staffObject, patientObject[patientIndex].getAttendingID(), numOfStaff)) {
		std::cout << "There is no doctor with that ID. Please enter the ID of an existing doctor: ";
		std::cin >> patientAttendingStaffID;
		std::cout << std::endl;
		patientObject[patientIndex].setAttendingID(patientAttendingStaffID);
		
	}

	char gender;

	std::cout << "Gender(M or F): ";
	std::cin >> gender;
	std::cout << std::endl;

	std::cout << "Phone Number: ";
	std::cin >> newPatientContact.phoneNo;
	std::cout << std::endl;

	std::cout << "E-mail: ";
	std::cin >> newPatientContact.email;
	std::cout << std::endl;

	int bDay, bMonth, bYear;

	std::cout << "Birth Date(month day year) seperated by spaces: ";
	std::cin >> bMonth >> bDay >> bYear;
	std::cout << std::endl;

	std::cout << "Address Number: ";
	std::cin >> newPatientContact.patientAddress.addNo;
	std::cout << std::endl;

	std::cout << "Street Name: ";
	std::cin.ignore();
	getline(std::cin, newPatientContact.patientAddress.streetName);
	std::cout << std::endl;

	std::cout << "City Name: ";
	getline(std::cin, newPatientContact.patientAddress.cityName);
	std::cout << std::endl;

	std::cout << "State Initials: ";
	getline(std::cin, newPatientContact.patientAddress.stateName);
	std::cout << std::endl;

	std::cout << "Zip Code: ";
	std::cin >> newPatientContact.patientAddress.zipCode;
	std::cout << std::endl;
	
	patientObject[patientIndex].setGender(gender);
	patientObject[patientIndex].setFirstName(fName);
	patientObject[patientIndex].setLastName(lName);
	patientObject[patientIndex].setPatientContactInfo(newPatientContact);
	patientObject[patientIndex].setID(newPatientID);
	patientObject[patientIndex].setBirthDay(bDay);
	patientObject[patientIndex].setBirthMonth(bMonth);
	patientObject[patientIndex].setBirthYear(bYear);
	patientIndex++;
}

bool doesDeptIdExist(Department departmentObject[], int thisDeptId, int numOfDepartments){
	bool deptExist = false;
	
	for (int i = 0; i < numOfDepartments; i++) {
		int newDeptId = departmentObject[i].getDeptID();
		if (thisDeptId == newDeptId) {
			deptExist = true;
			break;
		}
	}

	return deptExist;
}

bool doesStaffMemberExist(Staff staffObject[], int thisStaffId, int numOfStaff) {
	bool staffExist = false;
	for (int i = 0; i < numOfStaff; i++) {
		int newStaffId = staffObject[i].getStaffID();
		if (thisStaffId == newStaffId && staffObject[i].getStaffType() == 'D') {
			staffExist = true;
			break;
		}
	}
	return staffExist;
}

bool searchDept(Department departmentObject[], int numOfDepts, int &foundIndex, int searchID) {
	bool found = false;

	for (int i = 0; i < numOfDepts; i++) {
		int newDeptID = departmentObject[i].getDeptID();
		if (searchID == newDeptID) {
			found = true;
			foundIndex = i;
			break;
		}
	}
	return found;
}

bool searchStaffMember(Staff staffObject[], int numOfStaff, int &foundIndex, int searchID) {
	
	bool found = false;

	for (int i = 0; i < numOfStaff; i++) {
		int newStaffID = staffObject[i].getStaffID();
		if (searchID == newStaffID) {
			found = true;
			foundIndex = i;
			break;
		}
	}
	return found;

}

bool searchPatient(Patient patientObject[], int numOfPatients, int &foundIndex, int searchID) {
	bool found = false;

	for (int i = 0; i < numOfPatients; i++) {
		int newPatientID = patientObject[i].getPatientID();
		if (searchID == newPatientID) {
			found = true;
			foundIndex = i;
			break;
		}
	}
	return found;
}

void printAllDepartmentsToFile(Department departmentObject[], int numOfDepartments, std::ofstream& outFile) {
	for (int i = 0; i < numOfDepartments; i++) {
		departmentObject[i].printToFile(outFile);
		outFile << std::endl;
	}
}

void printAllStaffToFile(Staff staffObject[], int numOfStaff, std::ofstream& outFile) {
	for (int i = 0; i < numOfStaff; i++) {
		staffObject[i].printToFile(outFile);
		outFile << std::endl;
	}
}

void printAllPatientsToFile(Patient patientObject[], int numOfPatients, std::ofstream& outFile) {
	for (int i = 0; i < numOfPatients; i++) {
		patientObject[i].printToFile(outFile);
		outFile << std::endl;
	}
}

void departmentBubbleSort(Department departmentObject[], int numOfDepartments) {
	bool isSwapped = true;
	int l = 0;
	Department tempDept;
	while (isSwapped) {
		isSwapped = false;
		l++;
		for (int i = 0; i < numOfDepartments - l; i++) {
			if (departmentObject[i].getDeptID() > departmentObject[i + 1].getDeptID()) {
				tempDept = departmentObject[i];
				departmentObject[i] = departmentObject[i + 1];
				departmentObject[i + 1] = tempDept;
				isSwapped = true;
			}
		}
	}
}

void staffBubbleSort(Staff staffObject[], int numOfStaff) {
	bool isSwapped = true;
	int l = 0;
	Staff tempStaff;
	while (isSwapped) {
		isSwapped = false;
		l++;
		for (int i = 0; i < numOfStaff - l; i++) {
			if (staffObject[i].getStaffID() > staffObject[i + 1].getStaffID()) {
				
				tempStaff = staffObject[i];
				
				staffObject[i] = staffObject[i + 1];
				
				staffObject[i + 1] = tempStaff;
			
				isSwapped = true;
			}
		}
	}
}

void patientBubbleSort(Patient patientObject[], int numOfPatients) {
	bool isSwapped = true;
	int l = 0;
	Patient tempStorage;
	while (isSwapped) {
		isSwapped = false;
		l++;
		for (int i = 0; i < numOfPatients - l; i++) {
			if (patientObject[i].getPatientID() > patientObject[i + 1].getPatientID()) {
				tempStorage = patientObject[i];
				patientObject[i] = patientObject[i + 1];
				patientObject[i + 1] = tempStorage;
				isSwapped = true;
			}
		}
	}

}

void editDepartment(Department departmentObject[], int numOfDepts, int searchID) {
	int departmentIndex = 0;

	bool foundDepartment = searchDept(departmentObject, numOfDepts, departmentIndex, searchID);

	if (foundDepartment) {
		int deptChoice;
		std::string newName = "";
		int newID = 0;

		std::cout << "Select the option that corresponds to what you want to edit about this department:" << std::endl;
		std::cout << "1) Department Name" << std::endl << "2) Department ID" << std::endl;
		std::cin >> deptChoice;
		std::cout << std::endl;

		switch (deptChoice) {
		case 1:
			
			std::cout << "Enter the new name for this department: ";
			std::cin >> newName;
			std::cout << std::endl;

			departmentObject[departmentIndex].setDeptName(newName);
			break;

		case 2:

			std::cout << "Enter the new ID number for this department: ";
			std::cin >> newID;
			std::cout << std::endl;

			departmentObject[departmentIndex].setDeptID(newID);
			break;

		default:
			std::cout << "Invalid Selection." << std::endl;
		}

	}

	else {
		std::cout << "Department does not exist." << std::endl;
	}
}

void editStaffMember(Staff staffObject[], int numOfStaff, int searchID, Department deptObject[], int numOfDepartments) {
	int staffIndex = 0;
	
	bool foundStaffMember = searchStaffMember(staffObject, numOfStaff, staffIndex, searchID);

	if (foundStaffMember) {
		int staffChoice;
		std::string newInfo = "";
		int newID = 0;
		int day = 1, month = 1, year = 1;
		char newIdentifier = ' ';

		std::cout << "Select the option that corresponds to the information you want to edit" << std::endl;
		std::cout << "1) First Name" << std::endl << "2) Last Name" << std::endl << "3) Staff ID" << std::endl << "4) Staff Type"
			<< std::endl << "5) Gender" << std::endl << "6) Birthday" << std::endl << "7) Phone Number" << std::endl
			<< "8) E-mail" << std::endl << "9) Department ID" << std::endl;
		std::cin >> staffChoice;
		std::cout << std::endl;
		switch(staffChoice){
		case 1:
			std::cout << "Enter the first name of this staff member: ";
			std::cin >> newInfo;
			std::cout << std::endl;

			staffObject[staffIndex].setFirstName(newInfo);
			break;

		case 2:
			std::cout << "Enter the last name of this staff member: ";
			std::cin >> newInfo;
			std::cout << std::endl;

			staffObject[staffIndex].setLastName(newInfo);
			break;
		case 3:
			std::cout << "Enter new Staff ID: ";
			std::cin >> newID;
			std::cout << std::endl;

			staffObject[staffIndex].setStaffID(newID);
			break;
		case 4:
			std::cout << "Enter A if the staff member is an administrator, N if the staff member is a nurse or D if the staff member is a doctor: ";
			std::cin >> newIdentifier;
			std::cout << std::endl;

			staffObject[staffIndex].setStaffType(newIdentifier);
			break;

		case 5:
			std::cout << "Enter M if the staff member is a male or enter F if the staff member is a female: ";
			std::cin >> newIdentifier;
			std::cout << std::endl;

			staffObject[staffIndex].setGender(newIdentifier);
			break;

		case 6:
			std::cout << "Enter the birthday (month day year) of the staff member, be sure to seperate each number with a space: ";
			std::cin >> month >> day >> year;
			std::cout << std::endl;

			staffObject[staffIndex].setBirthMonth(month);
			staffObject[staffIndex].setBirthDay(day);
			staffObject[staffIndex].setBirthYear(year);
			break;

		case 7: {
			std::cout << "How many phone numbers would you like to store for this staff member?: ";
			int staffPhoneNumAm;
			std::cin >> staffPhoneNumAm;

			staffObject[staffIndex].staffContact.setNumofPhones(staffPhoneNumAm);

			std::cin.ignore();

			for (int i = 0; i < staffPhoneNumAm; i++) {
				if (i == 0)
					std::cout << "Enter new phone number: ";
				else
					std::cout << "Enter phone number #" << i + 1 << ": ";
				
				getline(std::cin, newInfo);
				std::cout << std::endl;

				staffObject[staffIndex].staffContact.setANumber(newInfo, i);
			}
			break;
		}
		case 8: {
			std::cout << "How many E-mails would you like to store for this staff member?: ";
			int newEmailNum;
			std::cin >> newEmailNum;
			std::cout << std::endl;
			staffObject[staffIndex].staffContact.setNumOfEmail(newEmailNum);

			std::cin.ignore();

			for (int i = 0; i < newEmailNum; i++) {
				
				if (i == 0)
					std::cout << "Enter E-mail: ";

				else
					std::cout << "Enter E-mail #" << i + 1 << ": ";
				
				
				getline(std::cin, newInfo);
				std::cout << std::endl;

				staffObject[staffIndex].staffContact.setAnEmail(newInfo, i);
			}
			break;
		}
		case 9: {
			int tempDeptID;
			std::cout << "Enter Department ID: ";
			std::cin >> tempDeptID;
			while (!doesDeptIdExist(deptObject, tempDeptID, numOfDepartments)) {
				std::cout << "That department does not exist.\nPlease enter an existing department: ";
				std::cin >> tempDeptID;
				std::cout << std::endl;
			}
			staffObject[staffIndex].staffDept.setDeptID(tempDeptID);
			break;
		}

			
		default:
			std::cout << "Invalid Selection." << std::endl;
		}

		

	}
	else {
		std::cout << "Staff member not found." << std::endl;
	}
}

void editPatient(Patient patientObject[], int numOfPatients, int searchID, Staff staffObject[], int numOfStaff) {
	int patientIndex = 0;

	bool foundPatient = searchPatient(patientObject, numOfPatients, patientIndex, searchID);

	if (foundPatient){
		int patientChoice;
		std::string newInfo = "";
		std::string newStreet = "", newCity = "", newState = "";
		int newHouse = 0, newZip = 0;
		PatientContactInfo newPatientContact;
		char newIdentifier = ' ';
		int day = 1, month = 1, year = 1;
		int newID = 0;
		std::cout << "Select the option that corresponds to the information you want to edit" << std::endl;
		std::cout << "1) First Name" << std::endl << "2) Last Name" << std::endl << "3) Patient ID" << std::endl << "4) Home Address"
			<< std::endl << "5) Gender" << std::endl << "6) Birthday" << std::endl << "7) Phone Number" << std::endl
			<< "8) E-mail" << std::endl << "9) Doctor ID" << std::endl;
		std::cin >> patientChoice;
		std::cout << std::endl;

		switch (patientChoice) {
		case 1:
			std::cout << "Enter the patient's first name: ";
			std::cin >> newInfo;
			std::cout << std::endl;

			patientObject[patientIndex].setFirstName(newInfo);
			break;

		case 2:
			std::cout << "Enter the patient's last name: ";
			std::cin >> newInfo;
			std::cout << std::endl;

			patientObject[patientIndex].setLastName(newInfo);
			break;
		case 3:
			std::cout << "Enter the patient's new ID number: ";
			std::cin >> newID;
			std::cout << std::endl;

			patientObject[patientIndex].setID(newID);
			break;
		case 4:
			std::cout << "Enter the following information regarding the patient's home address: " << std::endl;

			std::cout << "House Number: ";
			std::cin >> newHouse;
			std::cout << std::endl;

			std::cout << "Street Name: ";
			std::cin.ignore();
			getline(std::cin, newStreet);
			std::cout << std::endl;

			std::cout << "City Name: ";
			getline(std::cin, newCity);
			std::cout << std::endl;

			std::cout << "State Initials: ";
			getline(std::cin, newState);
			std::cout << std::endl;

			std::cout << "Zip code: ";
			std::cin >> newZip;
			std::cout << std::endl;

			patientObject[patientIndex].setAddress(newHouse, newStreet, newCity, newState, newZip);
			break;
			
		case 5:
			std::cout << "Enter the patient's gender(M for male or F for female): ";
			std::cin >> newIdentifier;
			std::cout << std::endl;

			patientObject[patientIndex].setGender(newIdentifier);
			break;
		case 6:
			std::cout << "Enter the birthday (month day year) of the patient, be sure to seperate each number with a space: ";
			std::cin >> month >> day >> year;
			std::cout << std::endl;

			patientObject[patientIndex].setBirthDay(day);
			patientObject[patientIndex].setBirthMonth(month);
			patientObject[patientIndex].setBirthYear(year);
			break;
		case 7:
			std::cout << "Enter the patient's phone number: ";
			std::cin >> newInfo;
			std::cout << std::endl;

			patientObject[patientIndex].setPhoneNum(newInfo);
			break;
		case 8:
			std::cout << "Enter the patient's E-mail: ";
			std::cin >> newInfo;
			std::cout << std::endl;

			patientObject[patientIndex].setEmail(newInfo);
			break;
		case 9: {
			int tempStaffID;
			std::cout << "Enter the ID of the Attending Doctor: ";
			std::cin >> tempStaffID;
			std::cout << std::endl;

			while(!doesStaffMemberExist(staffObject, tempStaffID, numOfStaff)){
				std::cout << "There is no Doctor with that ID.\nPlease enter the ID of the Attending Doctor: ";
				std::cin >> tempStaffID;
				std::cout << std::endl;
			}
			patientObject[patientIndex].setAttendingID(tempStaffID);
			break;
		}
		default:
			std::cout << "Invalid Selection." << std::endl;
		}
	}

	else {
		std::cout << "Patient not found." << std::endl;
	}
}

StaffContactInfo::StaffContactInfo(int thePhone, int theEmail) {
	emailAmount = theEmail;
	phoneNoAmount = thePhone;
	
	email = new std::string[theEmail];
	phoneNo = new std::string[thePhone];
}

StaffContactInfo::~StaffContactInfo() {
	delete[] phoneNo;
	delete[] email;
}

void StaffContactInfo::setNumOfEmail(int numOfEmail) {
	emailAmount = numOfEmail;
	email = new std::string[numOfEmail];
}

void StaffContactInfo::setNumofPhones(int phoneNumbers) {
	phoneNoAmount = phoneNumbers;
	phoneNo = new std::string[phoneNumbers];
}

int StaffContactInfo::getPhoneNoAmount() const {
	return phoneNoAmount;
}

void StaffContactInfo::setANumber(std::string newPNum, int phoneIndex) {
	phoneNo[phoneIndex] = newPNum;
}

int StaffContactInfo::getEmailAmount()  const{
	return emailAmount;
}

void StaffContactInfo::setAnEmail(std::string newEmail, int emailIndex) {
	email[emailIndex] = newEmail;
}

StaffContactInfo::StaffContactInfo(const StaffContactInfo& otherObject) {
	emailAmount = otherObject.emailAmount;
	phoneNoAmount = otherObject.phoneNoAmount;
	phoneNo = new std::string[phoneNoAmount];

	for (int i = 0; i < phoneNoAmount; i++) {
		phoneNo[i] = otherObject.phoneNo[i];
	}

	email = new std::string[emailAmount];

	for (int i = 0; i < emailAmount; i++) {
		email[i] = otherObject.email[i];
	}
}

const StaffContactInfo& StaffContactInfo::operator= (const StaffContactInfo& myObject) {
	if (this != &myObject) {
		delete[] email;
		delete[] phoneNo;
		emailAmount = myObject.emailAmount;
		phoneNoAmount = myObject.phoneNoAmount;

		email = new std::string[emailAmount];
		phoneNo = new std::string[phoneNoAmount];

		for (int i = 0; i < emailAmount; i++)
			email[i] = myObject.email[i];
		for (int l = 0; l < phoneNoAmount; l++)
			phoneNo[l] = myObject.phoneNo[l];
	}

	return *this;
}

void Patient::setAttendingID(int pAttend){
	attendingStaffID = pAttend;
}

int Patient::getAttendingID() const {
	return attendingStaffID;
}

Person::Person(char pGender, int pBmonth, int pBday, int pByear, std::string pfName, std::string plName) {
	gender = pGender;
	birthD.day = pBday;
	birthD.month = pBmonth;
	birthD.year = pByear;
	firstName = pfName;
	lastName = plName;
}

void outFileOperations(std::ofstream& outFile1, std::ofstream& outFile2, std::ofstream& outFile3, Department dList[], Staff sList[], Patient pList[], int deptNum, int staffNum, int patNum) {
	outFile1.open("updated_departments.txt");
	outFile2.open("updated_staff.txt");
	outFile3.open("updated_patients.txt");
	

	printAllDepartmentsToFile(dList, deptNum, outFile1);
	printAllStaffToFile(sList, staffNum, outFile2);
	printAllPatientsToFile(pList, patNum, outFile3);
	
	outFile1.close();
	outFile2.close();
	outFile3.close();
}

void inFileOperations(std::ifstream& dInFile, std::ifstream& sInFile, std::ifstream& pInFile, Department dList[], Staff sList[], Patient pList[], int& deptNum, int& staffNum, int& patNum, int maximum) {
	dInFile.open("departments.txt");
	sInFile.open("staff.txt");
	pInFile.open("patients.txt");

	while (dInFile.good()) {
		if (dInFile.peek() == std::ifstream::traits_type::eof())
			break;
		if (deptNum >= maximum)
			break;
		dList[deptNum].readFromFile(dInFile);
		deptNum++;
	}

	while (sInFile.good()) {
		if (sInFile.peek() == std::ifstream::traits_type::eof())
			break;
		if (staffNum >= maximum)
			break;
		sList[staffNum].readFromFile(sInFile);
		staffNum++;
	}

	while (pInFile.good()) {
		if (pInFile.peek() == std::ifstream::traits_type::eof())
			break;
		if (patNum >= maximum)
			break;
		pList[patNum].readFromFile(pInFile);
		patNum++;
	}

	dInFile.close();
	sInFile.close();
	pInFile.close();
}
