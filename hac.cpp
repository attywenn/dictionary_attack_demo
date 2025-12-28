/*
SHORT C++ EXAMPLE OF
HOW A DICTIONARY ATTACK IN PASSWORDS
WORKS
*/

#include <iostream>
#define max_arr 3
using namespace std;

/*
ASSUMING "pogiako" is your password, which is a very common password
*/
string password = "pogiako"; // your example password 

// this is the so called "dictionary" of passwords by hackers, that may contain your password
string pw_arr[max_arr] = {}; // dictionary of passwords sample through array

void input_passwords () {
    cout << "+++ ADD PASSWORDS IN DICTIONARY +++" <<endl;
    for (int i = 0; i < max_arr; i++) {
        cout << "Enter password: " <<endl;
        cin>>pw_arr[i];
    }
    cout<<"All goods!"<<endl;
}

void view_dictionary () {
    cout<<"=== LIST OF PASSWORDS ==="<<endl;
    for (int i = 0; i < max_arr; i++) {
        cout<<pw_arr[i]<<endl;
    }
}

// now, i created a function for brute force attack
void dictionary_attack (string pw, bool &isLog) { 
    for (int i = 0; i < max_arr; i++) { //since the array has 3 elements, we have to increment the loop until 3
        if (pw == pw_arr[i]) { // condition if parameter "pw" is matched with any passwords in the dictionary
            cout<<"HACKED, I FOUND YOUR PASSWORD AT LINE "<<i+1<<endl; // OUTPUTTING "HACKED" if your password is in the dictionary
            isLog = 1; // forcing the login
            break;
        }
    }
    if (!isLog) cout<<"password has not found in the dictionary"<<endl; // condition if password is not inside the dictionary
}


/*
function for user's login and
a basic function call for 
dictionary attack, just for demonstration
only
*/
void enter_pw () {
    string pw;
    bool isLogged = 0;
    int attempt = 3;
    do {
        cout<<endl;
        cout<<"Enter your password: "; cin >> pw;

        if (pw == password) {
            isLogged = 1;
            cout << "Successfully logged in!"<<endl;
            break;
        } else {
            attempt-=1;
            cout <<"Password incorrect"<<endl;
        }

        if (attempt == 0) break;
    } while (1);

    char yn;
    cout<<endl;
    cout <<"dictionary attack?(y/n): "; cin >> yn;

    if (yn == 'y') {
        dictionary_attack(password, isLogged);
    }
}

int mainMenu () {
    int choice;

    do {
        cout<<" === main menu === "<<endl;
        cout<<"1. Add passwords"<<endl
            <<"2. View passwords"<<endl
            <<"3. User login" <<endl
            <<"0. Exit"<<endl;
        cout<<"Choice: "; cin>>choice;
        switch (choice) {
            case 1: 
                input_passwords();
                break;
            case 2:
                view_dictionary();
                break;
            case 3:
                enter_pw();
                break;
            case 0:
                return 0;
            default:
                cout<<"INVALID"<<endl;
        }
    } while (1);
    return 0;
}

int main () {
    mainMenu();

    return 0;
}