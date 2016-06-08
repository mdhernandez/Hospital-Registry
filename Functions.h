//Author: Michael Hernandez
//BCS 230 Capstone Project: Midterm draft
//Date last modified: May 7, 2016
#pragma once

struct BirthDate {
	int day;//stores birth day
	int month;// stores birth month
	int year;//stores birth year
};//struct to store birth dates

class Person {
private:
	char gender;//stores gender as a character
	BirthDate birthD;//stores birthDate which is a struct of three integers listed above
	std::string firstName;//stores first name of a person
	std::string lastName;//stores last name of a person

public:
	void setGender(char);// sets gender variable
	void setFirstName(std::string);//sets firstName variable
	void setLastName(std::string);//sets lastName variable
	void setBirthDay(int);// sets birthD.day variable
	void setBirthMonth(int);//sets birthD.month variable
	void setBirthYear(int);//sets birthD.year variable
	char getGender() const;//returns gender variable
	std::string getFirstName() const;//returns firstName variable
	std::string getLastName() const;//returns lastName variable
	int getBirthDay() const;//returns birthD.day variable
	int getBirthMonth() const;//returns birthD.month variable
	int getBirthYear() const;//returns birthD.year variable
	Person(char = 'M', int = 1, int = 1, int = 1990, std::string = "first", std::string = "last");//default constructor with default parameters
};//class to store and manipulate personal information

class StaffContactInfo {
private:
	int phoneNoAmount;//stores the amount of phone numbers to be stored for a staff member
	int emailAmount;//stores the amount of e-mail addresses to be stored for a staff member

public:
	std::string *email;//stores e-mail address as a string for a staff member
	std::string *phoneNo;//stores phone number as a string for a staff member
	void setNumOfEmail(int);//sets the value of emailAmount
	void setNumofPhones(int);//sets the value of phoneNoAmount
	void setANumber(std::string, int);//sets a number in the phoneNo dynamic array
	void setAnEmail(std::string, int);//sets a number in the email dynamic array
	int getPhoneNoAmount() const;//returns phoneNoAmount
	int getEmailAmount() const;//returns emailAmount
	const StaffContactInfo& operator= (const StaffContactInfo&);//overloads assignment operator
	StaffContactInfo(const StaffContactInfo&);//copy constructor
	StaffContactInfo(int = 1, int = 1);//default constructor with default parameters
	~StaffContactInfo();//destructor
};//struct to store contact information about staff members

struct HomeAddressInfo {
	int addNo;//stores address number as an integer
	std::string streetName;// stores street name as a string
	std::string cityName;//stores city name as a string
	std::string stateName;//stores state name as a string
	int zipCode;//stores zip code as an integer
};//struct to store address info

struct PatientContactInfo {
	std::string email;//stores e-mail address of a patient
	std::string phoneNo;//stores phone number of a patient
	HomeAddressInfo patientAddress;// stores address information for a patient
};//struct to store contact information about patients

class Department {
private:
	std::string deptName;//stores name of a department
	int ID;//stores ID of a department

public:
	void setDeptName(std::string);//sets deptName
	void setDeptID(int);// sets ID
	std::string getDeptName() const;//returns deptName
	int getDeptID() const;//returns ID
	void readFromFile(std::ifstream&);//reads data about a department from a file
	void printToFile(std::ofstream&);//prints data about a department to an output file
	void printDepartment() const;//prints data about a department to the screen
	Department();//default constructor for Department
};

class Staff
	:public Person
{
private:
	char staffType;//stores the type of staff member as a character (D, N, or A)
	int staffID;//stores the ID number for a staff member

public:
	Department staffDept;//composition
	StaffContactInfo staffContact;//struct to store contact information of a staff member
	void setStaffID(int);//sets staffID
	void setStaffType(char);//sets staffType
	void readFromFile(std::ifstream&);//reads info about a staff member from a file
	void printToFile(std::ofstream&);//prints info about a staff member to an output file
	int getStaffID() const;//returns staffID
	char getStaffType() const; //returns staffType
	void printStaff() const;//prints information about a staff member to the screen
	Staff(int = 0, int = 0, char = 'M', int = 1, int = 1, int = 1990, int = 1, int = 1, std::string = "", std::string = "", char = 'A');//default constructor with default parameters for Staff
};

class Patient
	:public Person
{
private:
	int patientID;//stores patient ID
	int attendingStaffID;//stores the ID of the attending physician for a Patient
	PatientContactInfo patientContact;//struct that stores contact information for a patient

public:
	void setID(int);//sets patientID
	void setAttendingID(int);//sets attendingStaffID
	int getAttendingID() const;//returns attendingStaffID
	void setAddress(int, std::string, std::string, std::string, int);//sets the address fields of patientContact
	void setEmail(std::string);//sets the e-mail of patientContact
	void setPhoneNum(std::string);//set the phone number of patientContact
	void readFromFile(std::ifstream&);//reads info about a patient from a file
	void printToFile(std::ofstream&);//outputs info about a patient onto an output file in CSV format
	void setBirthday(int, int, int);//set a patient's birthday (for editing a patient's info)
	int getPatientID() const;//returns patientID
	void setPatientContactInfo(PatientContactInfo);//sets all variables in a patient's patientContact
	void printPatientInfo() const;//prints information about a patient
	Patient(int = 0, int = 0, char = 'M', int = 1, int = 1, int = 1990, std::string = "", std::string = "", std::string = "", std::string = "",
		int = 001, std::string = "", std::string = "", std::string = "", int = 11111);//default constructor using default parameters
};

void welcomeScreen(); //Displays welcome screen, used at beginning of program
void displayFirstMenu();// Displays the opening menu for the program
void displayDeptSubMenu();//Displays the menu of options when a user selects Department menu in the first menu
void displayStaffSubMenu();//Displays the menu of options when a user selects Staff menu in the first menu
void displayPatientSubMenu();//Displays the menu of options when a user selects Patient menu in the first menu
void menuSelection(int);//Determines which sub-menu to display based on the user's choice in the first menu
std::string readCharArrayFromFiletoString(std::ifstream&);//Function used to read characters (including spaces) from a file with CSVs and return it as a string
void addADepartment(Department[], int&);//main function used to add a department to an array of type Department
void addAStaffMember(Staff[], Department[], int&, int);//main function used to add a staff member to an array of type Staff
void addAPatient(Patient[], Staff[], int&, int);//main function used to add a patient to an array of type Patient
void listAllDepartments(Department[], int);//main function used to list all departments in an array of type Department
void listAllStaff(Staff[], int);//main function used to list all staff members in an array of type Staff
void listAllPatients(Patient[], int);//main function used to list all patients in an array of type Patient
bool doesDeptIdExist(Department[], int, int );//similar to searchDept, but doesn't return an index (used only for checking if a department exists)
bool doesStaffMemberExist(Staff[], int, int);//checks if a staff member exists and is a doctor (used for adding patient function)
bool searchDept(Department[], int, int&, int);//returns true (and returns the array index where the ID is found) if a Department ID is found, false if it is not
bool searchStaffMember(Staff[], int, int&, int);//returns true (and returns the array index where the ID is found) if a staff member ID is found, false if it is not
bool searchPatient(Patient[], int, int&, int);//returns true (and returns the array index where the ID is found) if a patient ID is found, false if it is not
void subMenusFunction(int, int, Department[], Staff[],
	Patient[], int&, int&, int&);//main function responsible for all submenu choices
void printAllPatientsToFile(Patient[], int, std::ofstream&);//prints all patients to an output file
void printAllStaffToFile(Staff[], int, std::ofstream&);//prints all staff members to an output file
void printAllDepartmentsToFile(Department[], int, std::ofstream&);//prints all departments to an output file
void departmentBubbleSort(Department[], int);//applies the bubblesort algorithm to an array of type Department
void staffBubbleSort(Staff[], int);//applies the bubblesort algorithm to an array of type Staff
void patientBubbleSort(Patient[], int);//applies the bubblesort algorithm to an array of type Patient
void editDepartment(Department[], int, int);//main function used in the edit option in the department submenu
void editStaffMember(Staff[], int, int, Department[], int);//main function used in the edit option in the staff submenu
void editPatient(Patient[], int, int, Staff[], int);//main function used in the edit option in the patient submenu
void outFileOperations(std::ofstream&, std::ofstream&, std::ofstream&, Department[], Staff[], Patient[], int, int, int);//performs all ofstream functions in the program
void inFileOperations(std::ifstream&, std::ifstream&, std::ifstream&, Department[], Staff[], Patient[], int&, int&, int&, int);//performs all ifstream functions in the program
