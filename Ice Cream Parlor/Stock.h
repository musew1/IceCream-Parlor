#pragma once

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void stockmenu();

//initializing the array for stock keeping
const int col = 4;
const int row = 20;
struct Stock {
    int ID;
    int Total;
    int Available;
    int Sold;
};
Stock s[20];

void addstock() {
    //going through a loop to find an empty index value as it's made sure that index can't be 0
    for (int i = 0; i < row; i++) {
        if (s[i].ID == 0) {
            cout << "Enter the Stock ID" << endl;
            cin >> s[i].ID;
            system("cls");
            while (s[i].ID == 0)
            {
                cout << "ID CANNOT BE 0, ENTER AGAIN";
                cin >> s[i].ID;
            }
            cout << "Enter the Total Stock" << endl;
            cin >> s[i].Total;
            system("cls");

            cout << "Enter the Sold Stock" << endl;
            cin >> s[i].Sold;
            system("cls");

            s[i].Available = s[i].Total - s[i].Sold;
            system("cls");

            break;
        }
    }
    //opening a file and adding all the new values into it
    ofstream fout;
    fout.open("Stock.txt");
    for (int i = 0; i < row; i++)
    {


        fout << s[i].ID << endl;
        fout << s[i].Total << endl;
        fout << s[i].Available << endl;
        fout << s[i].Sold << endl;


    }
    fout.close();

    //return to menu
    stockmenu();

}

void viewstock() {
    //showing the table
    cout << setw(7) << "ID" << setw(7) << "Total" << setw(7) << "Available" << setw(7) << "Sold" << endl;

    //looping through the program to output every single value with an endl in the outside loop to switch lines
    for (int i = 0; i < row; i++)
    {
        {

            cout << setw(7) << s[i].ID;
            cout << setw(7) << s[i].Total;
            cout << setw(7) << s[i].Available;
            cout << setw(7) << s[i].Sold;

        }
        cout << endl;
    }

    stockmenu();
}

void findstock() {
    int ID;
    cout << "Enter the ID you want to view" << endl;
    cin >> ID;

    //looping until the input ID is found in the index box
    for (int i = 0; i < row; i++)
    {
        if (s[i].ID == ID)
        {
            cout << setw(7) << "ID" << setw(7) << "Total" << setw(7) << "Available" << setw(7) << "Sold" << endl;
            cout << setw(7) << s[i].ID << setw(7) << s[i].Total << setw(7) << s[i].Available << setw(7) << s[i].Sold << endl;
        }
    }
    stockmenu();
}



void editstock() {
    int ID;
    cout << "Enter the ID you want to Edit" << endl;
    cin >> ID;
    //combining the find and add functions by using ID to find the correct index and then changing the values of the specified locations
    for (int i = 0; i < row; i++)
    {
        if (s[i].ID == ID)
        {
            cout << "Enter the Stock ID" << endl;
            cin >> s[i].ID;
            system("cls");
            while (s[i].ID == 0)
            {
                cout << "ID CANNOT BE 0, ENTER AGAIN";
                cin >> s[i].ID;
            }
            cout << "Enter the Total Stock" << endl;
            cin >> s[i].Total;
            system("cls");

            cout << "Enter the Sold Stock" << endl;
            cin >> s[i].Sold;
            system("cls");

            s[i].Available = s[i].Total - s[i].Sold;
            system("cls");

            cout << setw(7) << "ID" << setw(7) << "Total" << setw(7) << "Available" << setw(7) << "Sold" << endl;
            cout << setw(7) << s[i].ID << setw(7) << s[i].Total << setw(7) << s[i].Available << setw(7) << s[i].Sold << endl;
        }
    }
    //outputting the newly edited array into a file
    ofstream fout;
    fout.open("Stock.txt");
    for (int i = 0; i < row; i++)
    {

        fout << s[i].ID << endl;
        fout << s[i].Total << endl;
        fout << s[i].Available << endl;
        fout << s[i].Sold << endl;

    }
    fout.close();

    stockmenu();
}



void stockmenu() {

    //making sure the file exists
    ofstream fout;
    ifstream fin;

    fin.open("Stock.txt");
    try {
        if (fin.fail()) {
            throw runtime_error("File not Found, restart program");
        }
    }
    catch (runtime_error& e) {

        //if file does not exist, a file is created with the appropriate Tables made for inputs to be given.
        cout << "Exception Handling: " << e.what() << endl;
        fout.open("Stock.txt");
        for (int i = 0; i < (col * row); i++)
        {
            fout << "0" << endl;
        }
        fout.close();
        exit(0);
    }
    fin.close();


    //inputting the choice for the menu
    int choice;
    cout << "        STOCK MENU" << endl;
    cout << "Input 1 to add new stock" << endl << "Input 2 to view all stock" <<
        endl << "Input 3 to find stock" << endl << "Input 4 to edit stock" <<
        endl << "Input 5 to return to selection menu." << endl;
    cin >> choice;

    //taking input from the file to the array
    fin.open("Stock.txt");
    for (int i = 0; i < row; i++)
    {

        fin >> s[i].ID;
        fin >> s[i].Total;
        fin >> s[i].Available;
        fin >> s[i].Sold;

    }
    fin.close();

    //switch statement that calls the appropriate function that is asked for.
    switch (choice)
    {
    case 1:
        system("cls");
        addstock();
        break;
    case 2:
        system("cls");
        viewstock();
        break;
    case 3:
        system("cls");
        findstock();
        break;
    case 4:
        system("cls");
        editstock();
        break;
    case 5:
        system("cls");
        menu();
        exit(0);
    default:
        cout << "Invalid Input" << endl;
        break;
    }
}

