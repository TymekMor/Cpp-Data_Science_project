#ifndef OPTIONS_H
#define OPTIONS_H
#include "read.h"
#include <random>
void mean_salary(vector<SalaryRecord>& records, string job_title);
void jobs_in_location(vector<SalaryRecord>& records, string location);
void random_locations(vector<SalaryRecord>& records);
void random_companies(vector<SalaryRecord>& records);
void jobs_in_company(vector<SalaryRecord>& records, string company);   
void jobs_in_salary_range(vector<SalaryRecord>& records, float min = 0, float max = 99999999);
void jobs_in_jobsTXT(vector<string>& records);
void jobs_in_salary_range_in_location(vector<SalaryRecord>& records, float min = 0, float max = 99999999, string location = "");
bool is_numeric(const string& s);
int	get_option();
string clear_string(string str);
int getRandomInt(int lowerBound, int upperBound);

#endif