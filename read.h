#ifndef READ_H
#define READ_H

#include "class.h"
using namespace std;

vector<SalaryRecord> read_csv(const string& filename);
vector<string> read_txt(const string& filename);


#endif