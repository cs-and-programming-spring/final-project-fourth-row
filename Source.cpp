#include<iostream>
#include<string>

using namespace std;

const int s = 1;
double grades[s];
string names[s];
bool run = true, loop = true;
enum Grade { A = 90, B = 80, C = 70, D = 60, F = 50 };
string letter;

/**
 * The teacher class holds the credentials for the teacher that is using the program
 * @param userName - private string that holds the set username for the teacher
 * @param password - private string that holds the set password for the teacher
 */
class Teacher{
private:
    string userName, password, inputUserName, inputPassword;
    bool correctLogin;
public:
    Teacher(){
        correctLogin = false;
    }
    // Function isLoginCorrect verifies whether or not the user entered login credentials match those set
    // @param correctLogin - a boolean that is used to grant access to the rest of the program if the login is correct
    bool isLoginCorrect(){
        return correctLogin;
    }
    // Function setUserName is used to set the username of the teacher
    // @param teacherUserName is a string that will be set equal to the username of the teacher
    void setUserName(string teacherUserName){
        userName = teacherUserName;
    }
    // Function setPassword is used to set the password for the teacher
    // @param teacherPassword is a string that will be set equal to the username of the teacher
    void setPassword(string teacherPassword){
        password = teacherPassword;
    }

    // Function getUserName returns the set username of the teacher
    string getUserName(){
        return userName;
    }
    // Function getPassword returns the set password of the teacher
    string getPassword(){
        return password;
    }
    /**
     * The login function is used to ensure the security of the program
     * By using strings the function references the username and password set at the beginning of the program to act as
     * a login screen
     * @param matchUsername - string that checks the initially set username
     * @param matchPassword - string that checks the initially set password
     */
    void login(string matchUsername, string matchPassword){
        cout<< "Please enter user name: ";
        cin >> inputUserName;
        cout << "Please enter password: ";
        cin >> inputPassword;
        if(inputUserName == matchUsername && inputPassword == matchPassword){
            correctLogin = true;
        }else{
            correctLogin = false;
            cout << "Either the username or password was incorrect." << endl;
            login(getUserName(), getPassword());
        }
    }

};

/**
 * The student class holds the name of the student as well as the first and last name of the student as separate strings
 * @param name - string holding the first and last name of the student
 * @param firstName - string holding the first name of the student
 * @param lastName - string holding the last name of the student
 * @param grade - int holding the number grade of the strudent
 */

class Student {
private:
    string name, firstName, lastName;
    int grade;
public:
    Student(){
    }
    // Function setFirstName is used to set the first name of a student
    // @param nameOne - string set to hold the first name of the student before it is set to equal string firstName
    void setFirstName(string nameOne){
        firstName = nameOne;
    }
    // Function setLastName is used to set the last name of a student
    // @param nameTwo - string set to hold the last name of the student before it is set to equal string lastName
    void setLastName(string nameTwo){
        lastName = nameTwo;
    }
    // Function setName is used to combine the strings of first name and last name into the full name of a student
    // @param firstName - the first name of the student
    // @param lastName - the last name of the student
    // @param name - string holding the newly combined full name of a student
    string setName(){
        name = firstName + " " + lastName;
        return name;
    }
    // Function setGrade assigns a number grade to a student
    // @param studentGrade sets an integer to the student grade
    void setGrade(int studentGrade){
        grade = studentGrade;
    }
    // Function getName returns the name of a student
    string getName(){
        return name;
    }
    // Function getFirstName returns only the first name of the student
    string getFirstName(){
        return firstName;
    }
    // Function getLastName returns only the last name of the student
    string getLastName() {
        return lastName;
    }
    // Function getGrade returns the number grade of the student
    double getGrade(){
        return grade;
    }
};

/**
 * The stats function takes the grades input for the classroom and will return the class average as well as the
 * highest and lowest grades in the class
 * @param sum - the total of all grades
 * @param average - the average of the grades
 * @param highest - the double which holds the value for the highest grade in the class
 * @param lowest - the double which holds the lowest grade in the class
 * @param grades - the array that holds the class grades
 */
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
/**
 * The grade finder function uses search strings to search for and find a student by name
 * @param names - the array in which the names of the students in the classroom are stored
 * @param grades - the array in which the students grades are stored
 * @param SearchCheck - a boolean used to check whether or not a match for the name searched has been found
 * @param SearchName - the user input to be searched for in the array names
 */
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
/**
 * The classList function returns a list of all the students in a class
 * @param names - the array in which the students names are stored
 */
void classList(){
    cout<<"Here is a list of all the students registered:"<<endl;
    for (int a = 0; a < s; a++) {
        cout<<names[a]<<endl;
    }
    cout<<endl;
}
/**
 * The classGrades function returns a list of all of the students in the class with their respective grades
 * @param names - the array in which the students names are stored
 * @param grades - the array in which the students grades are stored
 */
void classGrades(){
    cout<<"Here is a list of all the students registered and their grade:"<<endl;
    for (int a = 0; a < s; a++) {
        cout<<names[a]<<": "<< grades[a]<<endl;
    }
    cout<<endl;
}
/**
 * The gradeScale function is used to see what the requirements are to earn a letter grade (A/B/C/D/F)
 * gradeScale uses enumeration to achieve this
 * @param letter - the user input that will return the grade requirement needed to earn the input letter grade
 * @param
 */
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
/**
 * The main of this program is where the menu is located and runs from
 * @param prgm - prgm is the name given to the user input
 * the user input is the number that decides which function is run from the menu
 * after the selected function is run the menu will ask if the user would like to use another function
 * if the user input is yes, the menu will run once again from the beginning
 * if the user input is no, the program will exit
 * @param grade - the grade input for the student
 * @param name - the name input for the student
 * @param choice - the choice input is the first step of the program that allows the teacher to input the names and
 * grades of students
 * @param answer - the user input that decides if the user would like to continue using the program or if they would
 * like it to close
 * @param firstName - the string that holds only the first name of a student
 * @param lastName - the string that holds only the last name of a student
 *
 */

int main() {

    int grade, choice, prgm;
    string name, firstName, lastName, answer, username, password;
    Teacher userTeacher;
    cout << "Please enter a username to be used: ";
    cin >> username;
    userTeacher.setUserName(username);
    cout << "Please enter a password to be used: ";
    cin >> password;
    userTeacher.setPassword(password);
    cout << "Now log in." <<endl;
    userTeacher.login(userTeacher.getUserName(), userTeacher.getPassword());
    if(userTeacher.isLoginCorrect()) {
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
                        loop = false;
                    }
                }
            } else {
                return 0;
            }
        }
    }

    system("pause");
    return 0;
}
