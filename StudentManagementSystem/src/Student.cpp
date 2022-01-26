/*
 * Student.cpp
 *
 *  Created on: 26 Jan 2022
 *      Author: Irene Hogan
 */

#include "Student.h"
#include <fstream>
#include <string>

Student::Student(){
	this->age = 0;
	this->firstName = "undefined";
	this->surname = "undefined";
	this->courseName = "undefined";
	this->attendance = -1.0;
}

Student::~Student(){

}
void Student::createNewStudent(){

	cout<<"First Name:	"<<endl;
	cin>>this->firstName;
	cout<<"Surname:	"<<endl;
	cin>>this->surname;
	cout<<"Age:		"<<endl;
	cin >>this->age;
	cout<<"Course:		"<<endl;
	getline(cin,courseName);
	double attendance;
	cout<<"Attendance Percentage:	"<<endl;
	cin>>attendance;
	if(!(attendance <=100)&&!(attendance >=0)) {
		attendance = 0.0;
	}
	this->attendance = attendance;
	saveStudent();
}

void Student::saveStudent(){
	ofstream myFile(this->firstName+ this->surname+".txt");

	myFile<<this->firstName<<"\n";
	myFile<<this->surname<<"\n";
	myFile<<this->age<<"\n";
	myFile<<this->courseName<<"\n";
	myFile<<this->attendance<<"\n";

	myFile.close();
}


void Student::loadStudent(){
	cout<<"Find Student:"<<endl;
	string firstName;
	string surname;
	cout<< "Student first name:		";
	cin>>firstName;
	cout<<"Student Surname:		";
	cin>>surname;
	ifstream myFile(firstName +surname+".txt");
	if(myFile){
		string age;
		string attendance;
		while(myFile>>this->firstName>>this->surname>>age
				>>this->courseName>>attendance){
			this->age = stoi(age);
			string::size_type sz;
			this->attendance= stod(attendance, &sz);
		}
	} else{
		cout<<"Student not found."<<endl;;
	}
	myFile.close();
}

void Student::changeStudentFirstName(){
	cout<<"Current first name:	"<< this->firstName<<endl;
	cout<<"New first name:		";
	cin>>this->firstName;
	saveStudent();
}

void Student::changeStudentSurname(){
	cout<<"Current surname:	"<< this->surname<<endl;
	cout<<"New surname:		";
	cin>>this->surname;
	saveStudent();
}

void Student::changeAge(){
	cout<<"Current age:	"<< this->age<<endl;
	cout<<"New age:		";
	cin>>this->age;
	saveStudent();
}
void Student::changeGrades(){

}
void Student::changeAttendance(){
	int attendance;
	cout<<"Current attendance:	"<< this->attendance<<endl;
	cout<<"New attendance:		";
	cin>>attendance;
	if((attendance <=100)&&(attendance >=0)) {
			this->attendance = attendance;
		}

	saveStudent();
}

void Student::viewStudent(){
	loadStudent();
	cout<<"Find student:"<<endl;
	bool menu = true;
	int option;
	do{
		cout<<endl<<endl;
		cout<<"1)	View Name"<<endl;
		cout<<"2)	View Age"<<endl;
		cout<<"3)	View Grades"<<endl;
		cout<<"4)	view Attendance"<<endl;
		cout<<"5)	exit"<<endl;
		cout<<"Enter a number:	";
		cin>>option;
		switch(option){
		case 1:
			cout<<"Student Name:	" + this->firstName + " " + this->surname<<endl;
			break;
		case 2:
			cout<<"Student Age:	"<< this->age<<endl;
			break;
		case 3:
			break;
		case 4:
			cout<<"Student attendance:		"<< this->attendance << "%"<<endl;
			break;
		case 5:
			menu = false;
			break;
		}
	}while(menu);
}

void Student::editStudent(){

	loadStudent();
	cout<<"Find student:"<<endl;
	bool menu = true;
	int option;
	do{
		cout<<endl<<endl;
		cout<<"1)	Change First Name"<<endl;
		cout<<"2)	Change Surname"<<endl;
		cout<<"3)	Change Age"<<endl;
		cout<<"4)	Change Grades"<<endl;
		cout<<"5)	Change Attendance"<<endl;
		cout<<"6)	exit"<<endl;
		cout<<"Enter a number:	";
		cin>>option;
		switch(option){
		case 1:
			changeStudentFirstName();
			break;
		case 2:
			changeStudentSurname();
			break;
		case 3:
			changeAge();
			break;
		case 4:
			changeGrades();
			break;
		case 5:
			changeAttendance();
			break;
		case 6:
			menu = false;
			break;
		}
	}while(menu);

}
