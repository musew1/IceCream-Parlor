#pragma once

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void menu();
void ordermenu();

struct Orders
{
    string orderid;
    string flavor;
    string type;
    string toppings;
};

Orders orders;

void addorder() {
    ofstream fout;
    //initializing variables for the choice in the switch statement.
    int flavorchoice, typechoice, toppingschoice;

    //system("cls") clears the screen output to make the code cleaner
    system("cls");
    //outputting and inputting the Order ID
    cout << "Enter Order ID" << endl;
    cin >> orders.orderid;

    // taking all the inputs for the variables, while outputting a menu for the choice.
    system("cls");
    cout << "Enter Flavor" << endl << "1. Vanilla" << endl << "2. Chocolate" << endl
        << "3. Strawberry" << endl << "4. Mango" << endl << "5. Pista" << endl;
    cin >> flavorchoice;

    system("cls");
    cout << "Enter Type" << endl << "1. Cone" << endl << "2. Cup" << endl;
    cin >> typechoice;

    system("cls");
    cout << "Enter Toppings" << endl << "1. Chocolate Sauce" << endl << "2. Strawberry Sauce" << endl
        << "3. Sprinkles" << endl << "4. Chocolate Chip" << endl;
    cin >> toppingschoice;
    system("cls");


    //using switch statements to make sure the right variable is selected
    switch (flavorchoice)
    {//initializing variable in each case, with break at the end to not run the other cases.
    case 1:
        orders.flavor = "Vanilla";
        break;
    case 2:
        orders.flavor = "Chocolate";
        break;
    case 3:
        orders.flavor = "Strawberry";
        break;
    case 4:
        orders.flavor = "Mango";
        break;
    case 5:
        orders.flavor = "Pista";
        break;
        //if wrong input is given for the choice of output, then default is run, where the code exits.
    default:
        cout << "Invalid Input";
        exit(0);
    }

    switch (typechoice)
    {
    case 1:
        orders.type = "Cone";
        break;
    case 2:
        orders.type = "Cup";
        break;
    default:
        cout << "Invalid Input";
        exit(0);
    }

    switch (toppingschoice)
    {
    case 1:
        orders.toppings = "ChocolateSauce";
        break;
    case 2:
        orders.toppings = "StrawberrySauce";
        break;
    case 3:
        orders.toppings = "Sprinkles";
        break;
    case 4:
        orders.toppings = "ChocolateChips";
        break;
    default:
        cout << "Invalid Input";
        exit(0);

    }

    //opening the file, and outputting with the ios append to make sure file stays same
    fout.open("Orders.txt", ios::app);
    //using setw to output in same width on each line
    fout << setw(8) << orders.orderid << setw(17) << orders.flavor << setw(8) << orders.type << setw(17) << orders.toppings << setw(19) << endl;
    fout.close();
    ordermenu();
}

void vieworders() {
    //opening file for ouputting
    ifstream fin;
    system("cls");
    fin.open("Orders.txt");
    // using loop to take the input from the file in one line, and outputting it all into one line
    while (fin >> orders.orderid >> orders.flavor >> orders.type >> orders.toppings)
    {
        cout << setw(8) << orders.orderid << setw(17) << orders.flavor << setw(8) << orders.type << setw(17) << orders.toppings << setw(19) << endl;
    }
    fin.close();

    //going back to the menu
    cout << endl;
    ordermenu();

}

void findorder() {

    //taking the input for what to find in the file
    string idin;
    system("cls");
    cout << "Enter your Order ID." << endl;
    cin >> idin;
    ifstream fin;


    //opening the file and searching for the correct ID with a while loop
    fin.open("Orders.txt");
    //using while to input multiple variables all from the same line
    while (fin >> orders.orderid >> orders.flavor >> orders.type >> orders.toppings)
    {
        //using if statement to output the searched term onto screen else showing match is not found
        if (orders.orderid == idin)
        {
            //ouputting the format of the table along with the taken inputs
            system("cls");
            cout << "Match has been found:" << endl << setw(8) << "OrderID" << setw(17) << "Flavor" << setw(8) << "Type" << setw(17) << "Toppings" << setw(19) << endl << setw(8) << orders.orderid << setw(17) << orders.flavor << setw(8) << orders.type << setw(17) << orders.toppings;
        }
        else
        {
            cout << "Match not found";
        }
    }

    fin.close();
    //sending the code back to the menu with proper spacing
    cout << endl << endl;
    ordermenu();
}

void deleteorder() {

    //initializing variables and opening files for input and output
    string idin;
    system("cls");
    cout << "Enter your Order ID." << endl;
    cin >> idin;
    ifstream fin;
    ofstream fout;
    //opening two different files one for input, one for output
    fin.open("Orders.txt");
    fout.open("Orders2.txt");

    //inputting each line into the while loop, and then if the correct ID is found, then that line is skipped otherwise else statement is run which outputs the line that's been input
    while (fin >> orders.orderid >> orders.flavor >> orders.type >> orders.toppings)
    {
        if (orders.orderid == idin)
        {
            continue;
        }
        else {
            fout << setw(8) << orders.orderid << setw(17) << orders.flavor << setw(8) << orders.type << setw(17) << orders.toppings << endl;
        }
    }

    //files are closed
    fin.close();
    fout.close();


    //remove deletes the file, and rename changes the file of the edited file to original file to keep code in order//
    bool temp;
    remove("Orders.txt");
    temp = rename("Orders2.txt", "Orders.txt");


    //screen is cleared, and back to the menu
    system("cls");
    ordermenu();

}


void editorder() {

    //inputting variables for choices, and strings of outputs
    string idin;
    int  choice, flavorchoice, typechoice, toppingschoice;
    system("cls");
    cout << "Enter your Order ID that you wish to update." << endl;
    cin >> idin;
    ifstream fin;
    ofstream fout;


    //opening two files, one for output, one for input.
    fin.open("Orders.txt");
    fout.open("Orders2.txt");

    //input is taken one line at a time
    while (fin >> orders.orderid >> orders.flavor >> orders.type >> orders.toppings)
    {
        //if the correct id is found, the line is stored and user is asked what to change from the record using cout and cin.
        if (orders.orderid == idin)
        {
            cout << "What entity do you wish to update?" << endl << "1. Flavor" << endl << "2. Type" << endl << "3. Toppings" << endl;
            cin >> choice;
            //switch is run to go through all the options and input into the appropriate variable replacing the original value with the edited one.
            switch (choice)
            {
            case 1:
                system("cls");
                cout << "Enter Flavor" << endl << "1. Vanilla" << endl << "2. Chocolate" << endl
                    << "3. Strawberry" << endl << "4. Mango" << endl << "5. Pista" << endl;
                cin >> flavorchoice;

                switch (flavorchoice)
                {
                case 1:
                    orders.flavor = "Vanilla";
                    break;
                case 2:
                    orders.flavor = "Chocolate";
                    break;
                case 3:
                    orders.flavor = "Strawberry";
                    break;
                case 4:
                    orders.flavor = "Mango";
                    break;
                case 5:
                    orders.flavor = "Pista";
                    break;
                default:
                    break;
                }

                break;
            case 2:
                system("cls");
                cout << "Enter Type" << endl << "1. Cone" << endl << "2. Cup" << endl;
                cin >> typechoice;

                switch (typechoice)
                {
                case 1:
                    orders.type = "Cone";
                    break;
                case 2:
                    orders.type = "Cup";
                    break;
                default:
                    break;
                }

                break;
            case 3:
                system("cls");
                cout << "Enter Toppings" << endl << "1. Chocolate Sauce" << endl << "2. Strawberry Sauce" << endl
                    << "3. Sprinkles" << endl << "4. Chocolate Chip" << endl;
                cin >> toppingschoice;

                switch (toppingschoice)
                {
                case 1:
                    orders.toppings = "ChocolateSauce";
                    break;
                case 2:
                    orders.toppings = "StrawberrySauce";
                    break;
                case 3:
                    orders.toppings = "Sprinkles";
                    break;
                case 4:
                    orders.toppings = "ChocolateChips";
                    break;
                default:
                    break;
                }

                break;
            default:
                break;
            }

            //the edited line is then output into the file
            fout << setw(8) << orders.orderid << setw(17) << orders.flavor << setw(8) << orders.type << setw(17) << orders.toppings << endl;
            //continued to the next iteration
            continue;

        }
        //directly outputting the line as is, if there is no match found.
        else {
            fout << setw(8) << orders.orderid << setw(17) << orders.flavor << setw(8) << orders.type << setw(17) << orders.toppings << endl;
        }
    }

    //closing both files.
    fin.close();
    fout.close();

    //deleting the file and renaming the newly edited file to the original file's name
    bool temp;
    remove("Orders.txt");
    temp = rename("Orders2.txt", "Orders.txt");

    //screen is cleared and sent back to the menu
    system("cls");
    ordermenu();
}

void ordermenu() {
    //inputting the choice for the menu
    int choice;
    cout << "     ICE CREAM ORDER MENU" << endl;
    cout << "Input 1 to add new order" << endl << "Input 2 to view all previous orders" <<
        endl << "Input 3 to find an order" << endl << "Input 4 to delete an order" <<
        endl << "Input 5 to edit an order" << endl << "Input 6 to return to selection menu." << endl;
    cin >> choice;

    //switch statement that calls the appropriate function that is asked for.
    switch (choice)
    {
    case 1:
        addorder();
        break;
    case 2:
        vieworders();
        break;
    case 3:
        findorder();
        break;
    case 4:
        deleteorder();
        break;
    case 5:
        editorder();
        break;
    case 6:
        system("cls");
        menu();
        break;
    default:
        cout << "Invalid Input" << endl;
        break;
    }
}
