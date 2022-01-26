//============================================================================
// Name        : StudentManagementSystem.cpp
// Author      : Irene Hogan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include "Student.h"
using namespace std;

int main() {


	bool menu = true;
	int option;
	do{
		cout<<"1)	Add new student"<<endl;
		cout<<"2)	View student"<<endl;
		cout<<"3)	Edit student"<<endl;
		cout<<"4)	Exit"<<endl;
		cout<<"Enter a number:		";
		cin>>option;
		if(option == 1){
			Student student;
			student.createNewStudent();
		} else if (option == 2){
			Student student;
			student.viewStudent();
		} else if (option == 3){
			Student student;
			student.editStudent();
		} else if (option == 4){
			menu = false;
		}

	}while(menu);

	return 0;
}

