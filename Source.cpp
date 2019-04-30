#include<iostream>
#include<string>

using namespace std;

const int s = 1;
double grades[s];
string names[s];
bool run = true, loop = true;
enum Grade { A = 90, B = 80, C = 70, D = 60, F = 50 };
string letter;

void stats(){
    double sum=0.0, average, highest=0, lowest=101;
    for (int a = 0; a < s; a++) {
        sum += grades[a];
        average = sum / (a+1);
        if (grades[a] < lowest){
            lowest = grades[a];}
        if (grades[a] > highest){
            highest = grades[a];}
    }
    cout<<"Class average = " << average <<endl;
    cout<<"Class highest = " << highest <<endl;
    cout<<"Class lowest = " << lowest <<endl;
    cout<<endl;
}

void gradeFinder(){
    string SearchName;
    bool SearchCheck=false;
    cout<<"Please input the name of the student you would like to search (Case sensitive)"<<endl;
    cin>>SearchName;
    for (int a = 0; a < s; a++) {
        if (SearchName == names[a]){
            cout<< names[a]<< "'s grade is " << grades[a] <<endl;
            SearchCheck=true;
            break;
        }
    }
    if (SearchCheck == false)
        cout<<"We could not find the student you were looking for"<<endl;
    cout<<endl;
}

void classList(){
    cout<<"Here is a list of all the students registered:"<<endl;
    for (int a = 0; a < s; a++) {
        cout<<names[a]<<endl;
    }
    cout<<endl;
}

void classGrades(){
    cout<<"Here is a list of all the students registered and their grade:"<<endl;
    for (int a = 0; a < s; a++) {
        cout<<names[a]<<": "<< grades[a]<<endl;
    }
    cout<<endl;
}

void gradeScale(){
    cout<<"Which letter would you like to see the requirements for? (A/B/C/D/F)"<<endl;
    cin>>letter;
if(letter == "A"){
    Grade number;
    number = A;
    cout << "To recieve a(n) "<<letter<<" you need at least a(n) " << number;
    cout<<endl;
    cout<<endl;
}
if(letter == "B"){
    Grade number;
    number = B;
    cout << "To recieve a(n) "<<letter<<" you need at least a(n) " << number;
    cout<<endl;
    cout<<endl;
}
if(letter == "C"){
    Grade number;
    number = C;
    cout << "To recieve a(n) "<<letter<<" you need at least a(n) " << number;
    cout<<endl;
    cout<<endl;
}
if(letter == "D"){
    Grade number;
    number = D;
    cout << "To recieve a(n) "<<letter<<" you need at least a(n) " << number;
    cout<<endl;
    cout<<endl;
}
if(letter == "F"){
    Grade number;
    number = F;
    cout << "To recieve a(n) "<<letter<<" you need at least a(n) " << number;
    cout<<endl;
    cout<<endl;
}
}

int main() {

    int grade, choice, prgm;
    string name, answer;

    while (loop) {
        cout << "Welcome to the Teacher Program! Press 1 to continue" << endl << endl;
        cout << "1) The Teacher Program" << endl << endl;
        cin >> prgm;
        cout << "\n\n";
        if (prgm == 1) {
            for (int a = 0; a < s; a++) {

                cout << "Input name" << "\n\n";
                cin >> name;
                cout << endl;
                names[a] = name;

                cout << "Input grade" << "\n\n";
                cin >> grade;
                cout << endl;
                grades[a] = grade;
            }
            while (run) {
                cout << "Which application would you like to use?" << "\n\n";
                cout << "1) Class Stats" << "\n\n";
                cout << "2) Grade Finder" << "\n\n";
                cout << "3) Class List" << "\n\n";
                cout << "4) Class list with grades" << "\n\n";
                cout << "5) Display Grade Scale" << "\n\n";
                cin >> choice;
                cout << "\n\n";
                if (choice == 1) {
                    stats();
                }
                if (choice == 2) {
                    gradeFinder();
                }
                if (choice == 3) {
                    classList();
                }
                if (choice == 4) {
                    classGrades();
                }
                if (choice == 5) {
                    gradeScale();
                }
                run = true;
                cout << "Would you like to run another application?" << endl;
                cin >> answer;
                cout << "\n\n";
                if (answer == "No" || answer == "no" || answer == "NO") {
                    run = false;
                    loop=false;
                }
            }
        }
        else {
            return 0;
        }
    }

    system("pause");
    return 0;
}

class student {
private:
    string name, firstName, lastName;
    int grade;
public:
    void setFirstName(string nameOne){
        firstName = nameOne;
    }

    void setLastName(string nameTwo){
        lastName = nameTwo;
    }

    void setName(){
        name = firstName + " " + lastName;
    }

    void setGrade(int studentGrade){
        grade = studentGrade;
    }

    string getName(){
        return name;
    }

    string getFirstName(){
        return firstName;
    }

    string getLastName() {
        return lastName;
    }

    int getGrade(){
        return grade;
    }
};

class teacher{
private:
    string userName, password;
public:
    void setUserName(string teacherUserName){
        userName = teacherUserName;
    }

    void setPassword(string teacherPassword){
        password = teacherPassword;
    }

    string getUserName(){
        return userName;
    }

    string getPassword(){
        return password;
    }

};

