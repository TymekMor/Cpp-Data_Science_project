#include "options.h"

bool is_numeric(const string& s) {
	return !s.empty() && find_if(s.begin(),
		s.end(), [](char c) { return !isdigit(c); }) == s.end();
}

int getRandomInt(int lowerBound, int upperBound) {
	random_device rd;  
	mt19937 engine(rd()); 
	uniform_int_distribution<int> distr(lowerBound, upperBound);
	return distr(engine);
}

string clear_string(string str) {
	string new_str = "";
	for (int i = 0; i < str.length(); i++) {
		if (isalpha(str[i]))
			new_str += str[i];
	}
	return new_str;
}

void mean_salary(vector<SalaryRecord>& records, string job_title) {
	float salaries = 0;
	float salaries_reported = 0;
	int counter = 0;
	for (auto& record : records) {
		if (record.job_title() == job_title) {
			salaries += record.salary();
			salaries_reported += record.salaries_reported();
			counter++;
		}
	}
	if (salaries_reported == 0) {
		cout << "Couldnt find such job title" << endl;
		return;
	}
	cout << "Mean salary for: " << job_title << " is: " << salaries / counter  << " $" << endl;
	cout << "Salaries of " << job_title << " reported: " << salaries_reported << endl;
}


void jobs_in_location(vector<SalaryRecord>& records, string location) {

	set<string> jobsFound;
	for (auto& record : records) {
		if (record.location() == location) {
			jobsFound.insert(record.job_title());
		}
	}
	if (jobsFound.size() == 0)
	{
		cout << "Couldnt find such location" << endl;
		return;
	}
	else {
		cout << "Jobs found in: " << location << endl;
		for (auto& job : jobsFound)
			cout << job << endl;
	}
}


void random_locations(vector<SalaryRecord>& records) {
	set<string> locations;
	cout <<"5 Random locations: " << endl << endl;
	int counter = 0;
	while (locations.size() < 5 && counter != records.size()) {
		counter++;
		int random = getRandomInt(0, records.size() -1);
		locations.insert(clear_string(records[random].location()));
	}
	
	for (auto& location : locations) {
		cout << location << endl;
	}
	cout << endl;
}

void random_companies(vector<SalaryRecord>& records) {
	set<string> companies;
	cout << endl <<"5 Random companies: " << endl << endl;
	int counter = 0;
	while (companies.size() < 5 && counter != records.size()) {
		counter++;
		int random = getRandomInt(0, records.size() - 1);
		companies.insert(clear_string(records[random].company()));
	}

	for (auto& company : companies) {
		cout << company << endl;
	}
	cout << endl;
}

void jobs_in_company(vector<SalaryRecord>& records, string company) {

	set<string> jobsFound;
	for (auto& record : records) {
		if (record.company() == company) {
			jobsFound.insert(record.job_title());
		}
	}
	if (jobsFound.size() == 0)
	{
		cout << "Couldnt find such company" << endl;
		return;
	}
	else {
		cout << "Jobs found in: " << company << endl;
		for (auto& job : jobsFound)
			cout << job << endl;
	}
}
 
void jobs_in_salary_range(vector<SalaryRecord>& records, float min, float max) {
	set<string> jobsFound;
	for (auto& record : records) {
		if (record.salary() >= min && record.salary() <= max) {
			jobsFound.insert(record.job_title());
		}
	}
	if (jobsFound.size() == 0)
	{
		cout << "Couldnt find jobs in such salary range" << endl;
		return;
	}
	else {
		cout << "Jobs found in salary range: " << min << " - " << max << endl;
		for (auto& job : jobsFound)
			cout << job << endl;
	}
}

void jobs_in_jobsTXT(vector<string>& records)
{
	cout << "Search for: ";
	string job_title;
	getline(cin >> ws, job_title);

	set<string> jobsFound;
	for (auto& record : records) {
		if (record.find(job_title) != string::npos) {
			jobsFound.insert(record);
		}
	}
	if (jobsFound.size() == 0)
	{
		cout << "Couldnt find such job title" << endl;
		return;
	}
	else {
		cout << "Jobs found: " << job_title << endl;
		for (auto& job : jobsFound)
			cout << job << endl;
	}
}

void jobs_in_salary_range_in_location(vector<SalaryRecord>& records, float min, float max, string location) {
	set<string> jobsFound;
	for (auto& record : records) {
		if (record.salary() >= min && record.salary() <= max && record.location() == location) {
			jobsFound.insert(record.job_title());
		}
	}
	if (jobsFound.size() == 0)
	{
		cout << "Couldnt find jobs in such salary range" << endl;
		return;
	}
	else {
		cout << "Jobs found in salary range: " << min << " - " << max << " in location: " << location << endl;
		for (auto& job : jobsFound)
			cout << job << endl;
	}
}

int get_option() {

	cout << "Choose option: " << endl;
	cout << "1. Find jobs in a salary range ( $ )" << endl;
	cout << "2. Find jobs in a salary range in a location ( $ )" << endl;
	cout << "3. View jobs in a location" << endl;
	cout << "4. View jobs in a company" << endl;
	cout << "5. Search for job titles" << endl;
	cout << "6. Find mean of yearly salaries reported for a job title" << endl;
	cout << "7. Show 5 random locations" << endl;
	cout << "8. Show 5 random companies" << endl;
	cout << "9. Exit" << endl;
	string option;
	cin >> option;
	while (!is_numeric(option) || stoi(option) < 1 || stoi(option) > 9) {
		cout << "Please enter a number ( 1-9 ): ";
		cin >> option;
	}
	return stoi(option);
}

