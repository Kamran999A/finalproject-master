#pragma once
#include <iostream>
#include <string>
#include <list>
#include <iomanip>
#include <windows.h>
#include "AdminClient.h"
using namespace std;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
class Restaurant {
	string name;
	string address;
	string city;
	double budget;
	list<Admin> admins;
public:
	Restaurant() :name(""), address(""), city(""), budget(0) {}
	Restaurant(const string& name, const string& address, const string& city, const double& budget) {
		setName(name);
		setAddress(address);
		setCity(city);
		setBudget(budget);
	}
	string getName()const {
		return name;
	}
	void setName(const string& name) {
		if (!name.empty()) this->name = name;
	}
	string getAddress()const {
		return address;
	}
	void setAddress(const string& address) {
		if (!address.empty()) this->address = address;
	}
	string getCity()const {
		return city;
	}
	void setCity(const string& city) {
		if (!city.empty()) this->city = city;
	}
	double getBudget()const {
		return budget;
	}
	void setBudget(const double& budget) {
		if (budget > 0) this->budget = budget;
	}

	friend ostream& operator<<(ostream& out, const Restaurant& restaurant);
};

ostream& operator<<(ostream& out, const Restaurant& restaurant) {
	out << "\t\t\t\t\t\t\t\t\t\tWelcome to " << restaurant.getName() << endl;
	out << "\t\t\t\t\t\t\t\t\t\tAddress: " << restaurant.getAddress() << endl;
	out << "\t\t\t\t\t\t\t\t\t\tCity: " << restaurant.getCity() << endl;
	out << "\t\t\t\t\t\t\t\t\t\tBudget: " << restaurant.getBudget() << endl;
	return out;
}

void printMenu(const Restaurant& r) {
	system("color  4E");

	cout << setw(79) << right << char(201); for (int i = 0; i < 28; i++)cout << char(205); cout << char(187) << endl;
	cout << setw(79) << right << char(186) << "Welcome to " << r.getName() << char(186) << endl;
	cout << setw(79) << right << char(186) << "Address:  " << r.getAddress() << char(186) << endl;
	cout << setw(79) << right << char(186) << "City:      " << r.getCity() <<"\t   "<< char(186) << endl;
	cout << setw(79) << right << char(200); for (int i = 0; i < 28; i++)cout << char(205); cout << char(188) << endl;
	
	cout << setw(8) << right << char(201); for (int i = 0; i < 76; i++)cout << char(205); cout << char(187) << endl;
	cout << setw(8) << right << char(186) << "Are you Admin or Client ? Choose 1 for Client 2 for Admin ." << r.getName() << char(186) << endl;
	cout << setw(8) << right << char(200); for (int i = 0; i < 76; i++)cout << char(205); cout << char(188) << endl;
	

	cout << setw(20) << right << char(201); for (int i = 0; i < 9; i++)cout << char(205); cout << char(187) << endl;
	cout << setw(20) << right << char(186) << "1. Client" << char(186) << endl;
	cout << setw(20) << right << char(200); for (int i = 0; i < 9; i++)cout << char(205); cout << char(188) << endl;
	
	cout << setw(20) << right << char(201); for (int i = 0; i < 8; i++)cout << char(205); cout << char(187) << endl;
	cout << setw(20) << right << char(186) << "2. Admin" << char(186) << endl;
	cout << setw(20) << right << char(200); for (int i = 0; i < 8; i++)cout << char(205); cout << char(188) << endl;

}
