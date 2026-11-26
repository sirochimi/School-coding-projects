// Week 10 Activity 4: parse records and catch malformed numeric fields.
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>
#include <iomanip>
#include <cctype>
using namespace std;
int score(const string& text) {
    size_t pos; int value = stoi(text, &pos);
    while (pos < text.size() && isspace(static_cast<unsigned char>(text[pos]))) ++pos;
    if (pos != text.size()) throw invalid_argument("trailing score data");
    return value;
}
int main() {
    ifstream file("students.csv");
    if (!file) { cerr << "Error: Could not find students.csv!\n"; return 1; }
    string line; cout << "--- Processing Student Records ---\n";
    while (getline(file,line)) {
        if (!line.empty() && line.back()=='\r') line.pop_back();
        if (line.empty()) continue;
        try {
            stringstream ss(line); string name, a, b, c;
            if (!getline(ss,name,',') || !getline(ss,a,',') || !getline(ss,b,',') || !getline(ss,c) || name.empty() || c.find(',') != string::npos)
                throw invalid_argument("bad fields");
            double avg = (static_cast<double>(score(a)) + score(b) + score(c)) / 3.0;
            cout << name << " -> Average: " << fixed << setprecision(2) << avg << '\n';
        } catch (const exception&) { cout << "WARNING: Skipping malformed record.\n"; }
    }
    if (file.bad()) { cerr << "Read error.\n"; return 1; }
    cout << "\n--- Processing Complete ---\n";
}
