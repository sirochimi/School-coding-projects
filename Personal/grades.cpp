#include <iostream>
#include <string>
using namespace std;

int main() {
    string StudentName;
    cout << "What is your name?"<<endl;
    getline(std::cin, StudentName);

    int score1, score2, score3;
    double average;
    int totalscore;
    cout << StudentName << "Please enter your score1" << endl;
    cin >> score1;
    cout << StudentName << "Please enter your score2" << endl;
    cin >> score2;
    cout << StudentName << "Please enter your score3" << endl;
    cin >> score3;
    totalscore = score1 + score2 + score3;
    average = totalscore / 3.0;

    cout << StudentName << "Here are your marks " << endl;
    cout << "Total Marks " << totalscore << endl;
    cout << "Average " << average << endl;
    return 0;
}
