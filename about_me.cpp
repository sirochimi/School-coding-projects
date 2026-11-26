#include <iostream>
#include <string>
using namespace std;
int main(){
    string name, course, hobby, reason, expectation, definition, food, job;
    cout << "What is your name? "; getline(cin,name); if(name.empty()) cout << "You didn't enter a name!\n";
    cout << "What course are you doing? "; getline(cin,course);
    cout << "What is your hobby? "; getline(cin,hobby);
    cout << "Why did you choose this course? "; getline(cin,reason);
    cout << "What do you expect to learn in programming? "; getline(cin,expectation);
    cout << "What is programming? "; getline(cin,definition);
    cout << "What is your favourite food? "; getline(cin,food);
    cout << "What is your dream job? "; getline(cin,job);
    cout << "\n======== YOUR PROFILE ========\nName: " << name << "\nCourse: " << course << "\nHobby: " << hobby << "\nReason: " << reason << "\nExpectation: " << expectation << "\nProgramming is: " << definition << "\nFavourite food: " << food << "\nDream job: " << job << "\n==============================\nGreat job, " << name << "! You are on your way to becoming a programmer!\n";
}
