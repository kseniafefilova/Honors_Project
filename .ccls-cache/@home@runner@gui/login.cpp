// #include<iostream>
// #include<fstream>
// #include<string.h>
// using namespace std;

// void login();
// void registration();
// void forgot();

// int main() {
//     int choice;
//     cout << "Press 1 to LOGIN" << endl;
//     cout << "Press 2 to REGISTER" << endl;
//     cout << "Press 3 if you FORGOT your password" << endl;
//     cout << "Please, enter your choice: " << endl;
//     cin >> choice;

//     switch(choice) {
//         case 1:
//             login();
//             break;
//         case 2:
//             registration();
//             break;
//         case 3:
//             forgot();
//             break;
//         default:
//         system("cls");
//             cout << "Please, select from the options given above" << endl;
//     }
// }

// void login() {
//     int count;
//     string userName, password, name, pass;
//     system("cls");
//     cout << "Please, enter the username: " << endl;
//     cin >> userName;
//     cout << "Please, enter the password: " << endl;
//     cin >> password;

//     ifstream input("records.txt");
//     while(input >> name >> pass) {
//         if(name == userName && pass == password) {
//             count = 1;
//             system("cls");
//         }
//     }
//     input.close();
//     if(count == 1) {
//         cout << userName << "\n Your LOGIN is successful. Thanks for logging
//         in." << endl; main();
//     }
//     else {
//         cout << "LOGIN error! Please, check your username and password." <<
//         endl; main();
//     }
// }

// void registration() {
//     int count;
//     string rUserName, rPassword, rName, rPass;
//     system("cls");
//     cout << "Enter the username: " << endl;
//     cin >> rUserName;
//     cout << "Enter the password: " << endl;
//     cin >>rPassword;

//     ofstream f1("records.txt", ios::app);
//     f1 << rUserName << " " << rPassword << endl;
//     system("cls");
//     main();
// }
// void forgot() {
//     int option;
//     system("cls");
//     cout << "Press 1 to search your id by username" << endl;
//     cout << "Press 2 to go back to the main menu" << endl;
//     cout << "Enter your choice: ";
//     cin >> option;
//     switch(option) {
//         case 1:
//         {
//             int count = 0;
//             string sUserName, sName, sPass;
//             cout << "Enter the username: " << endl;
//             cin >> sUserName;

//             ifstream f2("records.txt");
//             while(f2>>sName>>sPass) {
//                 if(sName == sUserName) {
//                     count = 1;
//                 }
//             }
//             f2.close();
//             if(count == 1){
//                 cout << "Your account is found!";
//                 cout << "Your password is: " << sPass;
//                 main();
//             }
//             else{
//                 cout << "Sorry, your account is not found!" << endl;
//                 main();
//             }
//             break;
//         }
//         case 2:
//         {
//             main();
//         }
//         default:
//             cout << "Wrong choice! Please, try again." << endl;
//             forgot();
//     }
// }