#include "read.h"

using namespace std;

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