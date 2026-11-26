#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;
int main(){
    string name, course; int scores[4], total=0;
    cout << "Student name: "; getline(cin,name); cout << "Course: "; getline(cin,course);
    for (int i=0; i<4; ++i) { cout << "Test " << i+1 << " (0-100): "; if (!(cin >> scores[i]) || scores[i]<0 || scores[i]>100) { cerr << "Invalid score.\n"; return 1; } total += scores[i]; }
    double avg=total/4.0; char grade = avg>=90?'A':avg>=80?'B':avg>=70?'C':avg>=60?'D':'F';
    cout << "Name: " << name << "\nCourse: " << course << "\nTotal: " << total << "/400\nAverage: " << fixed << setprecision(2) << avg << "\nPercentage: " << avg << "%\nGrade: " << grade << "\nHighest: " << *max_element(scores,scores+4) << '\n';
}
