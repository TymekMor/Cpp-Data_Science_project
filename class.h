#pragma once

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>

using namespace std;

class SalaryRecord {

private:
	string Company;
	string Job_title;
	int Salaries_reported;
	string Location;
	float Salary;

public:
	// Constructor
	SalaryRecord();
	SalaryRecord(const string& company, const string& job_title,
		int salaries_reported, const string& location, float salary);


	// Getters
	const string& company() const;
	const string& job_title() const;
	int salaries_reported() const;
	const string& location() const;
	float salary() const;

	// Setters
	void set_company(const string& company);
	void set_job_title(const string& job_title);
	void set_salaries_reported(int salaries_reported);
	void set_location(const string& location);
	void set_salary(float salary);

	void display() const;
};
