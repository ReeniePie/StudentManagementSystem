/*
 * Student.h
 *
 *  Created on: 26 Jan 2022
 *      Author: Irene Hogan
 */

#ifndef STUDENT_H_
#define STUDENT_H_
#include <iostream>
#include "Course.h"

using namespace std;

class Student {
private:
	string firstName;
	string surname;
	int age;
	double attendance;
	string courseName;
	void changeStudentFirstName();
	void changeStudentSurname();
	void changeAge();
	void changeGrades();
	void changeAttendance();

	void saveStudent();

public:
	Student();
	void createNewStudent();
	void loadStudent();
	void editStudent();
	void viewStudent();
	~Student();



};

#endif /* STUDENT_H_ */
