#include "class.h"


SalaryRecord::SalaryRecord()
	: Company(""),
	Job_title(""),
	Salaries_reported(0),
	Location(""),
	Salary(0.0) {}

SalaryRecord::SalaryRecord(const string& company, const string& job_title,
	int salaries_reported, const string& location, float salary)
	: Company(company),
	Job_title(job_title),
	Salaries_reported(salaries_reported),
	Location(location),
	Salary(salary) {}

const string& SalaryRecord::company() const { return Company; }

const string& SalaryRecord::job_title() const { return Job_title; }

int SalaryRecord::salaries_reported() const { return Salaries_reported; }

const string& SalaryRecord::location() const { return Location; }

float SalaryRecord::salary() const { return Salary; }

void SalaryRecord::set_company(const string& company) { Company = company; }

void SalaryRecord::set_job_title(const string& job_title) { Job_title = job_title; }

void SalaryRecord::set_salaries_reported(int salaries_reported) { Salaries_reported = salaries_reported; }

void SalaryRecord::set_location(const string& location) { Location = location; }

void SalaryRecord::set_salary(float salary) { Salary = salary * 0.012; }

void SalaryRecord::display() const {
	cout << "Company: " << Company << " ";
	cout << "Job Title: " << Job_title << " ";
	cout << "Salaries Reported: " << Salaries_reported << " ";
	cout << "Location: " << Location << " ";
	cout << "Salary: " << Salary << endl;
}