#include <iostream>
#include <limits>
#include <string>
using namespace std;
int main() {
    int n, counts[5] = {}; cout << "How many students? ";
    if (!(cin >> n) || n <= 0) { cerr << "Enter a positive number.\n"; return 1; }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int i = 0; i < n; ++i) {
        string name; double score;
        cout << "Student name: "; getline(cin, name);
        cout << "Score (0-100): ";
        if (!(cin >> score) || score < 0 || score > 100) { cerr << "Invalid score.\n"; return 1; }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        int grade = score >= 90 ? 0 : score >= 80 ? 1 : score >= 70 ? 2 : score >= 60 ? 3 : 4;
        ++counts[grade]; char letter = "ABCDF"[grade]; char mod = ' ';
        if (grade == 0) mod = score >= 97 ? '+' : score < 93 ? '-' : ' ';
        else if (grade < 4) { int digit = static_cast<int>(score) % 10; mod = digit >= 7 ? '+' : digit <= 2 ? '-' : ' '; }
        const char *messages[] = {"Excellent work!", "Good job!", "Satisfactory.", "Needs improvement.", "Please seek help."};
        cout << name << ": " << letter; if (mod != ' ') cout << mod; cout << " - " << messages[grade] << '\n';
    }
    cout << "Grade summary:\n"; for (int i=0; i<5; ++i) cout << "ABCDF"[i] << ": " << counts[i] << '\n';
}
