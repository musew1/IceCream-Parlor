#pragma once

#include <iostream>
#include <fstream>
using namespace std;
ifstream fin;
ofstream fout;

void checkendstock();
void addstockorder();
void viewstockorder();

struct StockOrder {
    int stockID;
    int Total;
    int Available;
    int Sold;

    int orderid;
    string flavor;
    string type;
    string toppings;
};

struct prices {
    int Vanilla = 10;
    int Chocolate = 17;
    int Strawberry = 12;
    int Mango = 15;
    int Pista = 20;
};

StockOrder a;
prices b;

void checkendstock() {

    cout << "The following stock has run out and needs to be restocked:" << endl;
    cout << setw(7) << "ID" << setw(7) << "Total" << setw(7) << "Available" << setw(7) << "Sold" << endl;
    fin.open("Stock.txt");
    while (fin >> a.stockID >> a.Total >> a.Available >> a.Sold)
    {
        if (a.Available <= 0 and a.stockID > 0) {
            cout << setw(7) << a.stockID << setw(7) << a.Total << setw(7) << a.Available << setw(7) << a.Sold << endl;
        }
    }
    cout << endl << endl;
    fin.close();
}


void stockordermenu() {

    //inputting the choice for the menu
    int choice;
    cout << "     ADD NEW STOCK MENU" << endl;
    cout << "Input 1 to add new stock order" << endl << "Input 2 to view all stock orders" <<
        endl << "Input 3 to return to selection menu." << endl;
    cin >> choice;

    //switch statement that calls the appropriate function that is asked for.
    switch (choice)
    {
    case 1:
        system("cls");
        addstockorder();
        break;
    case 2:
        system("cls");
        viewstockorder();
        break;
    case 3:
        system("cls");
        menu();
        break;
    default:
        cout << "Invalid Input" << endl;
        break;
    }
}

void addstockorder() {
    checkendstock();
    int temp;
    cout << "Enter the stock ID" << endl;
    cin >> temp;

    fin.open("Stock.txt");
    while (fin >> a.stockID >> a.Total >> a.Available >> a.Sold)
    {
        if (a.Available <= 0 and a.stockID == temp) {
            break;
        }
    }
    fin.close();

    fin.open("Orders.txt");

    string waste;
    fin >> waste >> waste >> waste >> waste;
    while (fin >> a.orderid >> a.flavor >> a.type >> a.toppings) {
        if (a.orderid == temp)
        {
            break;
        }
    }
    fin.close();

    int price = 0;
    if (a.flavor == "Vanilla") { price += b.Vanilla; }
    if (a.flavor == "Chocolate") { price += b.Chocolate; }
    if (a.flavor == "Strawberry") { price += b.Strawberry; }
    if (a.flavor == "Mango") { price += b.Mango; }
    if (a.flavor == "Pista") { price += b.Pista; }

    int orderamount;
    cout << "How many orders?" << endl;
    cin >> orderamount;
    cout << endl;

    price = price * orderamount;


    fout.open("StockOrders.txt", ios::app);
    fout << a.stockID << endl << a.flavor << endl << orderamount << endl << price << endl;
    fout.close();

    cout << setw(3) << "ID" << setw(15) << "Flavor" << setw(20) << "Amount Ordered" << setw(20) << "Total Price" << endl;
    cout << setw(3) << a.stockID << setw(15) << a.flavor << setw(20) << orderamount << setw(20) << price << endl;

}

void viewstockorder() {
    fin.open("StockOrders.txt");
    int orderamount, price;
    cout << setw(3) << "ID" << setw(15) << "Flavor" << setw(20) << "Amount Ordered" << setw(20) << "Total Price" << endl;
    while (fin >> a.stockID >> a.flavor >> orderamount >> price)
    {   
        cout << setw(3) << a.stockID << setw(15) << a.flavor << setw(20) << orderamount << setw(20) << price << endl;
    }
    fin.close();
}