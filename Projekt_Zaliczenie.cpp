#include "options.h"

int main() {
    cout << "Dataset consists of salaries for Data Scientists, Machine Learning Engineers, Data Analysts, and Data Engineers in various cities across India (2022)." <<endl;
    vector<SalaryRecord> records = read_csv("DataSet1.csv");
	if (records.size() == 0) {
		return 1;
	}
    vector<SalaryRecord> records2 = read_csv("DataSet2.csv");
	if (records.size() == 0) {
		return 1;
	}
    
    records.insert(records.end(), records2.begin(), records2.end());
	
    int operating = 1;
    while (operating)
    {
            int option = get_option();  
            
        switch (option)
        {
        case 1:
        {
            cout << "Enter min salary: ( $ ) ";
            string min;
            cin >> min;
            while (!is_numeric(min))
            {
				cout << "Enter min salary: ( $ ) ";
                cin >> min;
            }
            float minin = stof(min);
			cout << "Enter max salary: ( $ ) ";
            string max;
            cin >> max;
            while (!is_numeric(max))
            {
                cout << "Enter max salary: ( $ ) ";
                cin >> max;
            }
			float maxin = stof(max);
            jobs_in_salary_range(records, minin, maxin);
            break;
        }
        case 2:
        {
            cout << "Enter min salary: ( $ ) ";
            string min;
            cin >> min;
            while (!is_numeric(min))
            {
                cout << "Enter min salary: ( $ ) ";
                cin >> min;
            }
            float minin = stof(min);
            cout << "Enter max salary: ( $ ) ";
            string max;
            cin >> max;
            while (!is_numeric(max))
            {
                cout << "Enter max salary: ( $ ) ";
                cin >> max;
            }
            float maxin = stof(max);
			cout << "Enter loaction: ";
            string location;
            cin >> location;
            jobs_in_salary_range_in_location(records, minin, maxin, location);
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
            random_locations(records);
            break;
		}
        case 8:
        {
			random_companies(records);
			break;
        }
        case 9:
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
