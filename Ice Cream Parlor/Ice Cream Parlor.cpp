//including iostream for input output, fstream for fille input output, iomanip for outputting in a good format with setw.
#include <iostream>
#include <fstream>
#include <iomanip>
#include "Orders.h"
#include "Stock.h"
#include "StockOrder.h"
using namespace std;

//declaring functions
void menu();

void menu() {
    cout << "1. Ice Cream Menu." << endl << "2. Stock Menu." << endl << "3. Check Finished Stock." << endl << "4. Exit Program." << endl;
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        system("cls");
        ordermenu();
    case 2:
        system("cls");
        stockmenu();
    case 3:
        system("cls");
        stockordermenu();
    case 4:
        exit(0);
    default:
        break;
    }
}


int main() {
    //opening the file in main, to make sure it exists if there is no file
    ifstream fin;
    ofstream fout;
    fin.open("Orders.txt");

    //exception handling, to make sure the file exists
    try {
        if (fin.fail()) {
            throw runtime_error("File not Found, restart program");
        }
    }
    catch (runtime_error& e) {

        //if file does not exist, a file is created with the appropriate Tables made for inputs to be given.
        cout << "Exception Handling: " << e.what() << endl;
        fout.open("Orders.txt");
        fout << setw(8) << "OrderID" << setw(17) << "Flavor" << setw(8) << "Type" << setw(17) << "Toppings" << setw(19) << endl;
        fout.close();
        exit(0);
    }
    fin.close();
    //opening the menu directly
    menu();
}