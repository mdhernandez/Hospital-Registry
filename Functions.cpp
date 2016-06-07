//Author: Michael Hernandez
//BCS 230 Capstone Project: Midterm draft
//Date last modified: May 7, 2016

#include <string>
#include<iostream>
#include<fstream>
#include "Functions.h"

using namespace std;

void Department::readFromFile(ifstream& inFile) {
	deptName = readCharArrayFromFiletoString(inFile); 
	inFile >> ID;
	inFile.ignore();
}

void Department::printToFile(ofstream& outFile) {
	outFile << deptName << "," << ID;
}

void Department::setDeptName(string departmentN) {
	deptName = departmentN;
}

void Department::setDeptID(int departmentID) {
	ID = departmentID;
}

int Department::getDeptID() const {
	return ID;
}

string Department::getDeptName() const {
	return deptName;
}

void Department::printDepartment() const {//tentative
	cout << "Department Name: " << deptName << endl;
	cout << "Department ID: " << ID << endl;
}

void listAllDepartments(Department departmentObject[], int numOfDepts) {
	
	if (numOfDepts == 0) {
		cout << "There are no departments listed in the registry." << endl << endl;
	}
	else {
		departmentBubbleSort(departmentObject, numOfDepts);
		for (int i = 0; i < numOfDepts; i++) {
			departmentObject[i].printDepartment();
			cout << endl;
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
	string jobType = "";
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

	cout << "Name: " << jobType << " " << getFirstName() << " " << getLastName() << endl;
	cout << "Staff ID: " << staffID << endl;
	cout << "Department ID: " << staffDept.getDeptID() << endl;
	cout << "Gender: " << getGender() << endl;
	cout << "Birthday: " << getBirthMonth() << "/" << getBirthDay() << "/"
		<< getBirthYear() << endl;

	int numberOfPhones;

	if (staffContact.getPhoneNoAmount() > 1)
		numberOfPhones = staffContact.getPhoneNoAmount();
	else
		numberOfPhones = 1;



	cout << "Phone Number: ";

	for (int i = 0; i < numberOfPhones; i++) {
		cout << staffContact.phoneNo[i] << endl;
	}
	int numberOfEmails;

	if (staffContact.getEmailAmount() > 1)
		numberOfEmails = staffContact.getEmailAmount();
	else
		numberOfEmails = 1;

	cout << "E-mail: ";
	for (int i = 0; i < numberOfEmails; i++) {
		cout << staffContact.email[i] << endl;
	}
}

void listAllStaff(Staff staffObject[], int numOfStaff) {
	if (numOfStaff == 0) {
		cout << "There are no staff members listed in the registry." << endl << endl;
	}
	else {
		staffBubbleSort(staffObject, numOfStaff);

		for (int i = 0; i < numOfStaff; i++) {
			staffObject[i].printStaff();
			cout << endl;
		}
	}
}

void Staff::readFromFile(ifstream& inFile) {
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

void Staff::printToFile(ofstream& outFile) {
	
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

Staff::Staff(int id, int deptID, char gen, int sDay, int sMonth, int sYear, int sEmailAm, int sPhoneAmount, string sEmail, string sPhoneNo, char sStaffType) {
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

	cout << "Name: " << getFirstName() << " " << getLastName() << endl;
	cout << "Patient ID: " << patientID << endl;
	cout << "Gender: " << getGender() << endl;
	cout << "Birthday: " << getBirthMonth() << "/" << getBirthDay() << "/"
		<< getBirthYear() << endl;
	cout << "Phone Number: "<< patientContact.phoneNo << endl;
	cout << "Email: " << patientContact.email << endl;
	cout << "Address: " << patientContact.patientAddress.addNo << " " << patientContact.patientAddress.streetName << endl;
	cout << patientContact.patientAddress.cityName << ", " << patientContact.patientAddress.stateName << " " 
		<< patientContact.patientAddress.zipCode << endl;
}

void listAllPatients(Patient patientObject[], int numOfPatients) {
	if (numOfPatients == 0) {
		cout << "There are no patients listed in the registry." << endl << endl;
	}
	else {
		patientBubbleSort(patientObject, numOfPatients);

		for (int i = 0; i < numOfPatients; i++) {
			patientObject[i].printPatientInfo();
			cout << endl;
		}
	}
}

Patient::Patient(int pID, int sID, char pGender, int pDay, int pMonth, int pYear, string pFirst, string pLast, string pEmail, string pPhoneNo, int pAddressNo, string pStreetName, string pCityName, string pStateName, int pZipCode)
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

void Patient::readFromFile(ifstream& inFile) {
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

void Patient::printToFile(ofstream& outFile) {
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

void Patient::setAddress(int houseNum, string street, string city, string stateInit, int zipNum) {
	patientContact.patientAddress.addNo = houseNum;
	patientContact.patientAddress.streetName = street;
	patientContact.patientAddress.cityName = city;
	patientContact.patientAddress.stateName = stateInit;
	patientContact.patientAddress.zipCode = zipNum;
}

void Patient::setPhoneNum(string phone) {
	patientContact.phoneNo = phone;
}

void Patient::setEmail(string pEmail) {
	patientContact.email = pEmail;
}

void Patient::setPatientContactInfo(PatientContactInfo newPatientContact) {
	patientContact = newPatientContact;
}

void Person::setFirstName(string personFirstName) {
	firstName = personFirstName;
}

void Person::setLastName(string personLastName) {
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

string Person::getFirstName() const {
	return firstName;
}

string Person::getLastName() const {
	return lastName;
}

void displayFirstMenu() {
	cout << "1. Department menu" << endl;
	cout << "2. Staff menu" << endl;
	cout << "3. Patient menu" << endl;
	cout << "4. Exit" << endl;
}

void welcomeScreen() {
	cout << "Welcome to the hospital menu program!" << endl << endl;
	cout << "The purpose of this program is to store and present information about your hospital." << endl;
	cout << "Below is the main menu, Enter 1-3 to select one of the options to be taken to a different section of the program." << endl
		<<"To exit the program from the main menu Enter the number 4" << endl << endl;
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
		cout << "Invalid Selection. Try again." << endl;
		break;
	}
}

void displayDeptSubMenu() {
	cout << "1. List all departments" << endl;
	cout << "2. Add a department" << endl;
	cout << "3. Search for a department" << endl;
	cout << "4. Edit a department's information" << endl;
	cout << "6. Return to main menu" << endl;
}

void displayStaffSubMenu() {
	cout << "1. List all employees" << endl;
	cout << "2. Add an employee" << endl;
	cout << "3. Search for an employee" << endl;
	cout << "4. Edit an employee's information" << endl;
	cout << "6. Return to main menu" << endl;
}

void displayPatientSubMenu() {
	cout << "1. List all patients" << endl;
	cout << "2. Add a patient" << endl;
	cout << "3. Search for a patient" << endl;
	cout << "4. Edit a patient's information" << endl;
	cout << "6. Return to main menu" << endl;
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
			cout << endl;
			break;
		case 3: {
			cout << "Enter department ID: ";
			cin >> newSearchID;
			cout << endl;
			bool isFound = searchDept(departmentObject, numOfDepts, idForPrint, newSearchID);
			if (isFound) {
				departmentObject[idForPrint].printDepartment();
				cout << endl;
			}
			else {
				cout << "Department not found." << endl << endl;
			}
			break;
		}

		case 4:
			cout << "Enter the department ID or the department you wish to edit: ";
			cin >> newSearchID;
			cout << endl;

			editDepartment(departmentObject, numOfDepts, newSearchID);
			break;
		default:
			cout << "Invalid Selection. Please try again." << endl << endl;
		}
		break;
	case 2:
		switch (subchoice) {
		case 1:
			listAllStaff(staffObject, numOfStaff);
			break;
		case 2:
			addAStaffMember(staffObject, departmentObject, numOfStaff, numOfDepts);
			cout << endl;
			break;
		case 3: {
			cout << "Enter staff member ID: ";
			cin >> newSearchID;
			cout << endl;

			bool isFound = searchStaffMember(staffObject, numOfStaff, idForPrint, newSearchID);
			if (isFound) {
				staffObject[idForPrint].printStaff();
				cout << endl;
				int newDeptIndex = staffObject[idForPrint].staffDept.getDeptID();
				bool isDeptFound = searchDept(departmentObject, numOfDepts, idForPrint, newDeptIndex);
				if (isDeptFound) {
					cout << "Department Information:" << endl << endl;
					departmentObject[idForPrint].printDepartment();
					cout << endl;
				}
			}
			else {
				cout << "Staff member not found." << endl << endl;
			}
			break;
		}

		case 4:
			cout << "Enter the Staff ID of the staff member whose information you wish to edit: ";
			cin >> newSearchID;
			cout << endl;

			editStaffMember(staffObject, numOfStaff, newSearchID, departmentObject, numOfDepts);
			break;
			
		default:
			cout << "Invalid selection. Please try again." << endl << endl;
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
			cout << endl;
			break;
		case 3: {
			cout << "Enter Patient ID: ";
			cin >> newSearchID;
			cout << endl;

			bool isFound = searchPatient(patientObject, numOfPatients, idForPrint, newSearchID);
			if (isFound) {
				patientObject[idForPrint].printPatientInfo();
				cout << endl;
				int newDoctorID = patientObject[idForPrint].getAttendingID();
				bool isDoctorFound = searchStaffMember(staffObject, numOfStaff, idForPrint, newDoctorID);
				if (isDoctorFound) {
					cout << "Attending Staff Member Information: " << endl << endl;
					staffObject[idForPrint].printStaff();
					cout << endl;
				}
			}
			else {
				cout << "Patient not found." << endl << endl;
			}

			break;
		}
		case 4:
			cout << "Enter the ID of the patient whose information you wish to edit: ";
			cin >> newSearchID;
			cout << endl;

			editPatient(patientObject, numOfPatients, newSearchID, staffObject, numOfStaff);
			break;
		default:
			cout << "Invalid selection. Please try again." << endl << endl;
		}
		break;
	}

}

string readCharArrayFromFiletoString(ifstream& inFile) {
	char c;
	int characterCount = 0;
	char name[100];

	while (inFile.get(c)) {

		if (c == ',')
			break;
		name[characterCount] = c;
		characterCount++;
	}
	string nameChar(name, characterCount);
	return nameChar;
}

void addADepartment(Department departmentObject[], int &departmentSize) {
	string deptName;
	int deptID;
	

	cout << "Enter the following information about the department you want to add." << endl;
	cout << "Name: ";
	cin.ignore();
	getline(cin, deptName);
	departmentObject[departmentSize].setDeptName(deptName);
	cout << endl;

	cout << "ID: ";
	cin >> deptID;
	departmentObject[departmentSize].setDeptID(deptID);

	departmentSize++;
}

void addAStaffMember(Staff staffObject[], Department departmentObject[], int &staffSize, int numOfDepartments) {
	int newStaffID;
	int newDeptID;
	char newStaffType;
	
	cout << "Enter the following information about the staff member you wish to add." << endl;
	
	cout << "Staff ID: ";
	cin >> newStaffID;
	cout << endl;

	staffObject[staffSize].setStaffID(newStaffID);

	cout << "Staff Type(enter A for administrator, D for doctor, or N for nurse): ";
	cin >> newStaffType;
	cout << endl;

	cout << "Department ID: ";
	cin >> newDeptID;
	cout << endl;

	staffObject[staffSize].staffDept.setDeptID(newDeptID);

	while (!doesDeptIdExist(departmentObject, staffObject[staffSize].staffDept.getDeptID(), numOfDepartments)) {
		cout << "Invalid Department ID. Please reenter an existing Department ID: ";
		cin >> newDeptID;
		cout << endl;
		staffObject[staffSize].staffDept.setDeptID(newDeptID);
	}
	string fName;
	cout << "First Name: ";
	cin >> fName;
	cout << endl;

	string lName;
	cout << "Last Name: ";
	cin >> lName;
	cout << endl;

	char gender;
	cout << "Gender (M or F): ";
	cin >> gender;
	cout << endl;

	int bDay, bMonth, bYear;

	cout << "Birthday (month day year) seperated by spaces: "; 
	cin >> bMonth >> bDay >> bYear;
	cout << endl;

	cout << "How many phone numbers would you like to store?: ";
	int phoneNumAmount;
	cin >> phoneNumAmount;

	staffObject[staffSize].staffContact.setNumofPhones(phoneNumAmount);

	string newNumber = "";
	cin.ignore();

	for (int i = 0; i < staffObject[staffSize].staffContact.getPhoneNoAmount(); i++) {
		if(i == 0)
			cout << "Enter Phone number: ";
		else {
			cout << "Enter Phone number #" << i + 1 << ": ";
		}

		
		getline(cin, newNumber);
		cout << endl;

		staffObject[staffSize].staffContact.setANumber(newNumber, i);
	}
	cout << "How many E-mail addresses would you like to store?: ";
	int howManyEmail;
	cin >> howManyEmail;

	staffObject[staffSize].staffContact.setNumOfEmail(howManyEmail);
	string newEmail = "";
	cin.ignore();
	for (int i = 0; i < staffObject[staffSize].staffContact.getEmailAmount(); i++) {
		
		if(i == 0)
		cout << "E-mail: ";
		else {
			cout << "E-mail #" << i + 1 << ": ";
		}
		
		getline(cin, newEmail);
		cout << endl;
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

	cout << "Enter the following information about the patient you wish to add." << endl;

	string fName;
	cout << "First Name: ";
	cin >> fName;
	cout << endl;

	string lName;
	cout << "Last Name: ";
	cin >> lName;
	cout << endl;

	cout << "Patient ID: ";
	cin >> newPatientID;
	cout << endl;
	
	cout << "Doctor ID: ";
	cin >> patientAttendingStaffID;
	cout << endl;

	patientObject[patientIndex].setAttendingID(patientAttendingStaffID);

	while (!doesStaffMemberExist(staffObject, patientObject[patientIndex].getAttendingID(), numOfStaff)) {
		cout << "There is no doctor with that ID. Please enter the ID of an existing doctor: ";
		cin >> patientAttendingStaffID;
		cout << endl;
		patientObject[patientIndex].setAttendingID(patientAttendingStaffID);
		
	}

	char gender;

	cout << "Gender(M or F): ";
	cin >> gender;
	cout << endl;

	cout << "Phone Number: ";
	cin >> newPatientContact.phoneNo;
	cout << endl;

	cout << "E-mail: ";
	cin >> newPatientContact.email;
	cout << endl;

	int bDay, bMonth, bYear;

	cout << "Birth Date(month day year) seperated by spaces: ";
	cin >> bMonth >> bDay >> bYear;
	cout << endl;

	cout << "Address Number: ";
	cin >> newPatientContact.patientAddress.addNo;
	cout << endl;

	cout << "Street Name: ";
	cin.ignore();
	getline(cin, newPatientContact.patientAddress.streetName);
	cout << endl;

	cout << "City Name: ";
	getline(cin, newPatientContact.patientAddress.cityName);
	cout << endl;

	cout << "State Initials: ";
	getline(cin, newPatientContact.patientAddress.stateName);
	cout << endl;

	cout << "Zip Code: ";
	cin >> newPatientContact.patientAddress.zipCode;
	cout << endl;
	
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

void printAllDepartmentsToFile(Department departmentObject[], int numOfDepartments, ofstream& outFile) {
	for (int i = 0; i < numOfDepartments; i++) {
		departmentObject[i].printToFile(outFile);
		outFile << endl;
	}
}

void printAllStaffToFile(Staff staffObject[], int numOfStaff, ofstream& outFile) {
	for (int i = 0; i < numOfStaff; i++) {
		staffObject[i].printToFile(outFile);
		outFile << endl;
	}
}

void printAllPatientsToFile(Patient patientObject[], int numOfPatients, ofstream& outFile) {
	for (int i = 0; i < numOfPatients; i++) {
		patientObject[i].printToFile(outFile);
		outFile << endl;
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
		string newName = "";
		int newID = 0;

		cout << "Select the option that corresponds to what you want to edit about this department:" << endl;
		cout << "1) Department Name" << endl << "2) Department ID" << endl;
		cin >> deptChoice;
		cout << endl;

		switch (deptChoice) {
		case 1:
			
			cout << "Enter the new name for this department: ";
			cin >> newName;
			cout << endl;

			departmentObject[departmentIndex].setDeptName(newName);
			break;

		case 2:

			cout << "Enter the new ID number for this department: ";
			cin >> newID;
			cout << endl;

			departmentObject[departmentIndex].setDeptID(newID);
			break;

		default:
			cout << "Invalid Selection." << endl;
		}

	}

	else {
		cout << "Department does not exist." << endl;
	}
}

void editStaffMember(Staff staffObject[], int numOfStaff, int searchID, Department deptObject[], int numOfDepartments) {
	int staffIndex = 0;
	
	bool foundStaffMember = searchStaffMember(staffObject, numOfStaff, staffIndex, searchID);

	if (foundStaffMember) {
		int staffChoice;
		string newInfo = "";
		int newID = 0;
		int day = 1, month = 1, year = 1;
		char newIdentifier = ' ';

		cout << "Select the option that corresponds to the information you want to edit" << endl;
		cout << "1) First Name" << endl << "2) Last Name" << endl << "3) Staff ID" << endl << "4) Staff Type"
			<< endl << "5) Gender" << endl << "6) Birthday" << endl << "7) Phone Number" << endl
			<< "8) E-mail" << endl << "9) Department ID" << endl;
		cin >> staffChoice;
		cout << endl;
		switch(staffChoice){
		case 1:
			cout << "Enter the first name of this staff member: ";
			cin >> newInfo;
			cout << endl;

			staffObject[staffIndex].setFirstName(newInfo);
			break;

		case 2:
			cout << "Enter the last name of this staff member: ";
			cin >> newInfo;
			cout << endl;

			staffObject[staffIndex].setLastName(newInfo);
			break;
		case 3:
			cout << "Enter new Staff ID: ";
			cin >> newID;
			cout << endl;

			staffObject[staffIndex].setStaffID(newID);
			break;
		case 4:
			cout << "Enter A if the staff member is an administrator, N if the staff member is a nurse or D if the staff member is a doctor: ";
			cin >> newIdentifier;
			cout << endl;

			staffObject[staffIndex].setStaffType(newIdentifier);
			break;

		case 5:
			cout << "Enter M if the staff member is a male or enter F if the staff member is a female: ";
			cin >> newIdentifier;
			cout << endl;

			staffObject[staffIndex].setGender(newIdentifier);
			break;

		case 6:
			cout << "Enter the birthday (month day year) of the staff member, be sure to seperate each number with a space: ";
			cin >> month >> day >> year;
			cout << endl;

			staffObject[staffIndex].setBirthMonth(month);
			staffObject[staffIndex].setBirthDay(day);
			staffObject[staffIndex].setBirthYear(year);
			break;

		case 7: {
			cout << "How many phone numbers would you like to store for this staff member?: ";
			int staffPhoneNumAm;
			cin >> staffPhoneNumAm;

			staffObject[staffIndex].staffContact.setNumofPhones(staffPhoneNumAm);

			cin.ignore();

			for (int i = 0; i < staffPhoneNumAm; i++) {
				if (i == 0)
					cout << "Enter new phone number: ";
				else
					cout << "Enter phone number #" << i + 1 << ": ";
				
				getline(cin, newInfo);
				cout << endl;

				staffObject[staffIndex].staffContact.setANumber(newInfo, i);
			}
			break;
		}
		case 8: {
			cout << "How many E-mails would you like to store for this staff member?: ";
			int newEmailNum;
			cin >> newEmailNum;
			cout << endl;
			staffObject[staffIndex].staffContact.setNumOfEmail(newEmailNum);

			cin.ignore();

			for (int i = 0; i < newEmailNum; i++) {
				
				if (i == 0)
					cout << "Enter E-mail: ";

				else
					cout << "Enter E-mail #" << i + 1 << ": ";
				
				
				getline(cin, newInfo);
				cout << endl;

				staffObject[staffIndex].staffContact.setAnEmail(newInfo, i);
			}
			break;
		}
		case 9: {
			int tempDeptID;
			cout << "Enter Department ID: ";
			cin >> tempDeptID;
			while (!doesDeptIdExist(deptObject, tempDeptID, numOfDepartments)) {
				cout << "That department does not exist.\nPlease enter an existing department: ";
				cin >> tempDeptID;
				cout << endl;
			}
			staffObject[staffIndex].staffDept.setDeptID(tempDeptID);
			break;
		}

			
		default:
			cout << "Invalid Selection." << endl;
		}

		

	}
	else {
		cout << "Staff member not found." << endl;
	}
}

void editPatient(Patient patientObject[], int numOfPatients, int searchID, Staff staffObject[], int numOfStaff) {
	int patientIndex = 0;

	bool foundPatient = searchPatient(patientObject, numOfPatients, patientIndex, searchID);

	if (foundPatient){
		int patientChoice;
		string newInfo = "";
		string newStreet = "", newCity = "", newState = "";
		int newHouse = 0, newZip = 0;
		PatientContactInfo newPatientContact;
		char newIdentifier = ' ';
		int day = 1, month = 1, year = 1;
		int newID = 0;
		cout << "Select the option that corresponds to the information you want to edit" << endl;
		cout << "1) First Name" << endl << "2) Last Name" << endl << "3) Patient ID" << endl << "4) Home Address"
			<< endl << "5) Gender" << endl << "6) Birthday" << endl << "7) Phone Number" << endl
			<< "8) E-mail" << endl << "9) Doctor ID" << endl;
		cin >> patientChoice;
		cout << endl;

		switch (patientChoice) {
		case 1:
			cout << "Enter the patient's first name: ";
			cin >> newInfo;
			cout << endl;

			patientObject[patientIndex].setFirstName(newInfo);
			break;

		case 2:
			cout << "Enter the patient's last name: ";
			cin >> newInfo;
			cout << endl;

			patientObject[patientIndex].setLastName(newInfo);
			break;
		case 3:
			cout << "Enter the patient's new ID number: ";
			cin >> newID;
			cout << endl;

			patientObject[patientIndex].setID(newID);
			break;
		case 4:
			cout << "Enter the following information regarding the patient's home address: " << endl;

			cout << "House Number: ";
			cin >> newHouse;
			cout << endl;

			cout << "Street Name: ";
			cin.ignore();
			getline(cin, newStreet);
			cout << endl;

			cout << "City Name: ";
			getline(cin, newCity);
			cout << endl;

			cout << "State Initials: ";
			getline(cin, newState);
			cout << endl;

			cout << "Zip code: ";
			cin >> newZip;
			cout << endl;

			patientObject[patientIndex].setAddress(newHouse, newStreet, newCity, newState, newZip);
			break;
			
		case 5:
			cout << "Enter the patient's gender(M for male or F for female): ";
			cin >> newIdentifier;
			cout << endl;

			patientObject[patientIndex].setGender(newIdentifier);
			break;
		case 6:
			cout << "Enter the birthday (month day year) of the patient, be sure to seperate each number with a space: ";
			cin >> month >> day >> year;
			cout << endl;

			patientObject[patientIndex].setBirthDay(day);
			patientObject[patientIndex].setBirthMonth(month);
			patientObject[patientIndex].setBirthYear(year);
			break;
		case 7:
			cout << "Enter the patient's phone number: ";
			cin >> newInfo;
			cout << endl;

			patientObject[patientIndex].setPhoneNum(newInfo);
			break;
		case 8:
			cout << "Enter the patient's E-mail: ";
			cin >> newInfo;
			cout << endl;

			patientObject[patientIndex].setEmail(newInfo);
			break;
		case 9: {
			int tempStaffID;
			cout << "Enter the ID of the Attending Doctor: ";
			cin >> tempStaffID;
			cout << endl;

			while(!doesStaffMemberExist(staffObject, tempStaffID, numOfStaff)){
				cout << "There is no Doctor with that ID.\nPlease enter the ID of the Attending Doctor: ";
				cin >> tempStaffID;
				cout << endl;
			}
			patientObject[patientIndex].setAttendingID(tempStaffID);
			break;
		}
		default:
			cout << "Invalid Selection." << endl;
		}
	}

	else {
		cout << "Patient not found." << endl;
	}
}

StaffContactInfo::StaffContactInfo(int thePhone, int theEmail) {
	emailAmount = theEmail;
	phoneNoAmount = thePhone;
	
	email = new string[theEmail];
	phoneNo = new string[thePhone];
}

StaffContactInfo::~StaffContactInfo() {
	delete[] phoneNo;
	delete[] email;
}

void StaffContactInfo::setNumOfEmail(int numOfEmail) {
	emailAmount = numOfEmail;
	email = new string[numOfEmail];
}

void StaffContactInfo::setNumofPhones(int phoneNumbers) {
	phoneNoAmount = phoneNumbers;
	phoneNo = new string[phoneNumbers];
}

int StaffContactInfo::getPhoneNoAmount() const {
	return phoneNoAmount;
}

void StaffContactInfo::setANumber(string newPNum, int phoneIndex) {
	phoneNo[phoneIndex] = newPNum;
}

int StaffContactInfo::getEmailAmount()  const{
	return emailAmount;
}

void StaffContactInfo::setAnEmail(string newEmail, int emailIndex) {
	email[emailIndex] = newEmail;
}

StaffContactInfo::StaffContactInfo(const StaffContactInfo& otherObject) {
	emailAmount = otherObject.emailAmount;
	phoneNoAmount = otherObject.phoneNoAmount;
	phoneNo = new string[phoneNoAmount];

	for (int i = 0; i < phoneNoAmount; i++) {
		phoneNo[i] = otherObject.phoneNo[i];
	}

	email = new string[emailAmount];

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

		email = new string[emailAmount];
		phoneNo = new string[phoneNoAmount];

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

Person::Person(char pGender, int pBmonth, int pBday, int pByear, string pfName, string plName) {
	gender = pGender;
	birthD.day = pBday;
	birthD.month = pBmonth;
	birthD.year = pByear;
	firstName = pfName;
	lastName = plName;
}

void outFileOperations(ofstream& outFile1, ofstream& outFile2, ofstream& outFile3, Department dList[], Staff sList[], Patient pList[], int deptNum, int staffNum, int patNum) {
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

void inFileOperations(ifstream& dInFile, ifstream& sInFile, ifstream& pInFile, Department dList[], Staff sList[], Patient pList[], int& deptNum, int& staffNum, int& patNum, int maximum) {
	dInFile.open("departments.txt");
	sInFile.open("staff.txt");
	pInFile.open("patients.txt");

	while (dInFile.good()) {
		if (dInFile.peek() == ifstream::traits_type::eof())
			break;
		if (deptNum >= maximum)
			break;
		dList[deptNum].readFromFile(dInFile);
		deptNum++;
	}

	while (sInFile.good()) {
		if (sInFile.peek() == ifstream::traits_type::eof())
			break;
		if (staffNum >= maximum)
			break;
		sList[staffNum].readFromFile(sInFile);
		staffNum++;
	}

	while (pInFile.good()) {
		if (pInFile.peek() == ifstream::traits_type::eof())
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