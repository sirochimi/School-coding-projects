#include <iostream>
#include <string>
using namespace std;

int main () {
    string Name;
    string Course;

    cout<<"What is your name?"<<endl;
    getline(cin,Name);
    cout<<"Hello, "<<Name<<"What course do you do?"<<endl;
    getline(cin, Course);
    if (Course == "BBIT") {cout<<"Wrong grade calculator, please send me money"<<endl;
                            return 0;
                        }
    int score1;
    int score2;
    int score3;
    const int MAX_SCORE=100;
    int totalscore;
    double averagescore;
    cout<<Name<<" Please enter score 1"<<endl;
    cin>>score1;
    if (score1 >MAX_SCORE) {cout<<Name<<", Please enter a valid score"<<endl;}
    cout<<Name<<" Please enter score 2"<<endl;
    cin>>score2;
    if (score2 >MAX_SCORE) {cout<<Name<<", Please enter a valid score"<<endl;}
    cout<<Name<<" Please enter score 3"<<endl;
    cin>>score3;
    if (score3 >MAX_SCORE) {cout<<Name<<", Please enter a valid score"<<endl;}
    totalscore=score1+score2+score3;
    averagescore=totalscore/3.0;

    string grade;
    string remark;
    if (averagescore >= 90)         grade = "A";
    else if (averagescore >= 75)    grade="A-";
    else if (averagescore >= 65)    grade="B+";
    else if (averagescore >= 50)    grade = "B";
    else grade = "Im too tired to write the rest";
    
    switch (grade){
        case "A":
            remark = "Great job Keep it up";
            break;
        case "A-":
        case "B+":
            remark = "Good job but Aim for A";
            break;
        case "B":
            remark = "You tried but try harder !";
            break:
        default:
            remark = "Im sorry man, I'm tired";
    }       
    cout<<Name<<endl;
    cout<<totalscore<<endl;
    cout<<averagescore<<endl;
    cout<<grade<< remark;
    return 0;
}   