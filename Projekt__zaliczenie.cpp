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
    SalaryRecord()
        : Company(""),
        Job_title(""),
        Salaries_reported(0),
        Location(""),
        Salary(0.0) {}

    SalaryRecord(const string& company, const string& job_title,
        int salaries_reported, const string& location, float salary)
        : Company(company),
        Job_title(job_title),
        Salaries_reported(salaries_reported),
        Location(location),
        Salary(salary) {}

    // Getters
    const string& company() const { return Company; }
    const string& job_title() const { return Job_title; }
    int salaries_reported() const { return Salaries_reported; }
    const string& location() const { return Location; }
    float salary() const { return Salary; }
    //Setters
    void set_company(const string& company) { Company = company; }
    void set_job_title(const string& job_title) { Job_title = job_title; }
    void set_salaries_reported(int salaries_reported) {
        Salaries_reported = salaries_reported;
    }
    void set_location(const string& location) { Location = location; }
    // Salary is converted from Indian Rupee to American dollar due to readabillity
    void set_salary(float salary) { Salary = salary*0.012; }

    void display() const {
    cout << "Company: " << Company << " ";
    cout << "Job Title: " << Job_title << " ";
    cout << "Salaries Reported: " << Salaries_reported << " ";
    cout << "Location: " << Location << " ";
    cout << "Salary: " << Salary << endl;
  }
};




vector<SalaryRecord> read_csv(const string& filename) {
    vector<SalaryRecord> records;

    // Open the file
    ifstream file(filename);

    // Check if the file was opened successfully
    if (!file.is_open()) {
       cerr << "Error: Failed to open file." << endl;
        return records;
    }

    // Read the file line by line
    string line;
	bool first_line = true;
    while (getline(file, line)) {
        // Split the line into fields
        if (first_line) {
            first_line = false;
            continue;
        }
        
        stringstream stream(line);
        string field;
        vector<string> fields;
        while (getline(stream, field, ',')) {
            fields.push_back(field);
        }

        // Check that the line has the expected number of fields
        if (fields.size() != 6) {
            //cerr << "Error: Invalid number of fields on line: " << line << endl;
            continue;
        }

        // Extract the fields

        SalaryRecord record;

        // Create a SalaryRecord object
        if (filename == "DataSet2.csv")
        {
            
            record.set_company(fields[1]);
            record.set_job_title(fields[2]);
            record.set_salaries_reported(stoi(fields[4]));
            record.set_salary(stof(fields[3]));
            record.set_location(fields[5]);
        }
        else {
            record.set_company(fields[1]);
            record.set_job_title(fields[2]);
            record.set_salaries_reported(stoi(fields[3]));
            record.set_salary(stof(fields[5]));
            record.set_location(fields[4]);
        }
        

        // Add the record to the vector
        records.push_back(record);
    }

    // Close the file
    file.close();

    return records;
}

vector<string> read_txt(const string& filename)
{
    ifstream file(filename);

    string line;

    vector<string> jobs;

    while (getline(file, line)) {
        jobs.push_back(line);
    }
    return jobs;
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
	cout << "Mean salary for: " << job_title << " is: " << salaries / counter << endl;
	cout << "Salaries of " << job_title << " reported: "<< salaries_reported << endl;
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
// funtction to find jobs in a salary range     
void jobs_in_salary_range(vector<SalaryRecord>& records, float min = 0, float max = 99999999) {
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
// function that checks if input is numeric without spaces
bool is_numeric(const string& s) {
	return !s.empty() && find_if(s.begin(),
		s.end(), [](char c) { return !isdigit(c); }) == s.end();
}
// function that checks if input is float without spaces
bool is_float(const string& s) {
	return !s.empty() && find_if(s.begin(),
		s.end(), [](char c) { return !isdigit(c) && c != '.'; }) == s.end();
}
//function that searches for job_title names even without full name of the job
void jobs_in_jobsTXT(vector<string>& records) 
{
	cout << "Search for: ";
	string job_title;   
	cin >> job_title;
    
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



void jobs_in_salary_range_in_location(vector<SalaryRecord>& records, float min = 0, float max = 99999999, string location = "") {
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
    

int main() {
    vector<SalaryRecord> records = read_csv("DataSet1.csv");
    vector<SalaryRecord> records2 = read_csv("DataSet2.csv");
    records.insert(records.end(), records2.begin(), records2.end());
    // make options to choose from for end user
    
    int operating = 1;
    while (operating)
    {
        cout << "Choose option: " << endl;
        cout << "1. Find jobs in a salary range" << endl;
        cout << "2. Find jobs in a salary range in a location" << endl;
        cout << "3. Find jobs in a location" << endl;
        cout << "4. Find jobs in a company" << endl;
        cout << "5. Find jobs in a job_title" << endl;
        cout << "6. Find mean of salaries reported for a job_title" << endl;
        cout << "7. Exit" << endl;
        int option;
        cin >> option;

        // switch case to choose option
        switch (option)
        {
        case 1:
        {
            cout << "Enter min salary: ";
            float min;
            cin >> min;
            cout << "Enter max salary: ";
            float max;
            cin >> max;
            jobs_in_salary_range(records, min, max);
            break;
        }
        case 2:
        {
            cout << "Enter min salary: ";
            float min;
            cin >> min;
            cout << "Enter max salary: ";
            float max;
            cin >> max;
            cout << "Enter location: ";
            string location;
            cin >> location;
            jobs_in_salary_range_in_location(records, min, max, location);
            break;
        }
        case 3:
        {
            cout << "Enter location: ";
            string location;
            cin >> location;
            jobs_in_location(records, location);
            break;
        }
        case 4:
        {
            cout << "Enter company: ";
            string company;
            getline(cin >> ws, company);
            jobs_in_company(records, company);
            break;
        }
        case 5:
        {
            vector<string> jobs = read_txt("jobs.txt");
            jobs_in_jobsTXT(jobs);
            break;
        }
        case 6:
        {
            cout << "Enter job title: ";
            string job_title;
            getline(cin >> ws, job_title);
            mean_salary(records, job_title);
            break;
        }
        case 7:
        {
            cout << "Exiting..." << endl;
            operating = 0;
            break;
        }
        default:
            cout << "Invalid option" << endl;
            operating = 0;
            break;
        }
    }
    return 0;
    
}