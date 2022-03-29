// #include <iostream>
// #include <string>
// #include "Row.hpp"
// #include "Row.cpp"
// #include "Page.hpp"
// #include "Page.cpp"
// #include "Notebook.hpp"
// #include "Notebook.cpp"
// using namespace std;

// int main(){
//     int page=0;
//     int row=0;
//     int column=0;
//     int length=0;
//     string sentence;
//     ariel::Notebook notebook;

//     char action = 'g';
//     while (action!='D'){
//         cout << "PLEASE ENTER W-write , R-read , E-erase , S-show , D-end" << endl;
//         cin >> action;
//         switch (action) {
//             case 'W':
//                 cout << "Writing" << endl;
//                 cout << "PLEASE ENTER page row column sentence" << endl;
//                 cin >> page >> row >> column >> sentence;
//                 try{
//                     notebook.write(page, row, column, ariel::Direction::Horizontal, sentence);
//                 }
//                 catch(...){
//                     action = 'D';
//                 }
//                 break;
//             case 'R':
//                 cout << "Reading" << endl;
//                 cout << "PLEASE ENTER page row column length" << endl;
//                 cin >> page >> row >> column >> length;
//                 try{
//                     cout << notebook.read(page, row, column, ariel::Direction::Horizontal, length) << endl;
//                 }
//                 catch(...){
//                     action = 'D';
//                 }
//                 break;
//             case 'E':
//                 cout << "Erasing" << endl;
//                 cout << "PLEASE ENTER page row column length" << endl;
//                 cin >> page >> row >> column >> length;
//                 try{
//                     notebook.erase(page, row, column, ariel::Direction::Horizontal, length);
//                 }
//                 catch(...){
//                     action = 'D';
//                 }
//                 break;
//             case 'S':
//                 cout << "Showing" << endl;
//                 cout << "PLEASE ENTER page" << endl;
//                 cin >> page;
//                 try{
//                     notebook.show(page);
//                 }
//                 catch(...){
//                     action = 'D';
//                 }
//                 break;
//             case 'D':
//                 cout << "ends trial" << endl;
//                 return 0;
//         }
//     }
//     return 0;
// }