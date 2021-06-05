#pragma once
#include <iostream>
#include <string>
using namespace std;


class Person {
private:
	string name;
	string surname;
	int age;
	string phoneNumber;
public:
	Person() :name(""), surname(""), age(0), phoneNumber("") {}
	Person(const string& name, const string& surname, const int& age, const string& phoneNumber)
	{
		setName(name);
		setSurname(surname);
		setAge(age);
		setPhoneNumber(phoneNumber);
	}

	string getName()const {
		return name;
	}
	void setName(const string& name) {
		if (!name.empty()) this->name = name;
	}
	string getSurname()const {
		return surname;
	}
	void setSurname(const string& surname) {
		if (!surname.empty()) this->surname = surname;
	}
	int getAge()const {
		return age;
	}
	void setAge(const int& age) {
		if (age != 0) this->age = age;
	}
	string getPhoneNumber()const {
		return phoneNumber;
	}
	void setPhoneNumber(const string& phoneNumber) {
		if (!phoneNumber.empty()) this->phoneNumber = phoneNumber;
	}

	virtual ~Person() = 0 {}

};

class Admin :public Person {
	string username;
	string password;
public:
	Admin() :username(""), password("") {}
	Admin(const string& name, const string& surname, const int& age, const string& phoneNumber, const string& username, const string& password) :Person(name, surname, age, phoneNumber) {
		setUsername(username);
		setPassword(password);
	}

	string getUsername()const {
		return username;
	}
	void setUsername(const string& username) {
		if (!username.empty()) this->username = username;
	}
	string getPassword()const {
		return password;
	}
	void setPassword(const string& password) {
		if (!password.empty()) this->password = password;
	}

	bool signIN(const string& username, const string& password) {
		if (this->username == username)
		{
			if (this->password == password)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		return 0;
	}


};

class Client :public Person {
	string tableNo;
	double budget;
public:
	Client() :tableNo(""), budget(0) {}
	Client(const string& name, const string& surname, const int& age, const string& phoneNumber, const string& tableNo, const double& budget) :Person(name, surname, age, phoneNumber) {
		setTableNo(tableNo);
		setBudget(budget);
	}

	string getTableNo()const {
		return tableNo;
	}
	void setTableNo(const string& tableNo) {
		if (!tableNo.empty()) this->tableNo = tableNo;
	}
	double getBudget()const {
		return budget;
	}
	void setBudget(const double& budget) {
		if (budget > 0)this->budget = budget;
	}
	void table();

	friend istream& operator>>(istream& in, Client& client);


};

void Client::table() {
	cout << setw(8) << right << char(201); for (int i = 0; i < 19; i++)cout << char(205); cout << char(187)
		<< setw(16) << right << char(201); for (int i = 0; i < 19; i++)cout << char(205); cout << char(187)
		<< setw(16) << right << char(201); for (int i = 0; i < 19; i++)cout << char(205); cout << char(187) << endl;
	cout << setw(8) << right << char(186) << "Table - 1 * IS FULL" << char(186)
		<< setw(16) << right << char(186) << "Table - 2 * IS FULL" << char(186)
		<< setw(16) << right << char(186) << "Table - 3 * IS FREE" << char(186) << endl;
	cout << setw(8) << right << char(200); for (int i = 0; i < 19; i++)cout << char(205); cout << char(188)
		<< setw(16) << right << char(200); for (int i = 0; i < 19; i++)cout << char(205); cout << char(188)
		<< setw(16) << right << char(200); for (int i = 0; i < 19; i++)cout << char(205); cout << char(188) << endl;



	cout << setw(8) << right << char(201); for (int i = 0; i < 19; i++)cout << char(205); cout << char(187)
		<< setw(16) << right << char(201); for (int i = 0; i < 19; i++)cout << char(205); cout << char(187)
		<< setw(16) << right << char(201); for (int i = 0; i < 19; i++)cout << char(205); cout << char(187) << endl;
	cout << setw(8) << right << char(186) << "Table - 5 * IS FREE" << char(186)
		<< setw(16) << right << char(186) << "Table - 6 * IS FREE" << char(186)
		<< setw(16) << right << char(186) << "Table - 7 * IS FREE" << char(186) << endl;
	cout << setw(8) << right << char(200); for (int i = 0; i < 19; i++)cout << char(205); cout << char(188)
		<< setw(16) << right << char(200); for (int i = 0; i < 19; i++)cout << char(205); cout << char(188)
		<< setw(16) << right << char(200); for (int i = 0; i < 19; i++)cout << char(205); cout << char(188) << endl;



	cout << setw(8) << right << char(201); for (int i = 0; i < 19; i++)cout << char(205); cout << char(187)
		<< setw(16) << right << char(201); for (int i = 0; i < 19; i++)cout << char(205); cout << char(187)
		<< setw(16) << right << char(201); for (int i = 0; i < 19; i++)cout << char(205); cout << char(187) << endl;
	cout << setw(8) << right << char(186) << "Table - 8 * IS FREE" << char(186)
		<< setw(16) << right << char(186) << "Table - 9 * IS FREE" << char(186)
		<< setw(16) << right << char(186) << "Table -10 * IS FULL" << char(186) << endl;
	cout << setw(8) << right << char(200); for (int i = 0; i < 19; i++)cout << char(205); cout << char(188)
		<< setw(16) << right << char(200); for (int i = 0; i < 19; i++)cout << char(205); cout << char(188)
		<< setw(16) << right << char(200); for (int i = 0; i < 19; i++)cout << char(205); cout << char(188) << endl;



	cout << setw(8) << right << char(201); for (int i = 0; i < 19; i++)cout << char(205); cout << char(187)
		<< setw(16) << right << char(201); for (int i = 0; i < 19; i++)cout << char(205); cout << char(187)
		<< setw(16) << right << char(201); for (int i = 0; i < 19; i++)cout << char(205); cout << char(187) << endl;
	cout << setw(8) << right << char(186) << "Table -11 * IS FULL" << char(186)
		<< setw(16) << right << char(186) << "Table -12 * IS FULL" << char(186)
		<< setw(16) << right << char(186) << "Table -13 * IS FULL" << char(186) << endl;
	cout << setw(8) << right << char(200); for (int i = 0; i < 19; i++)cout << char(205); cout << char(188)
		<< setw(16) << right << char(200); for (int i = 0; i < 19; i++)cout << char(205); cout << char(188)
		<< setw(16) << right << char(200); for (int i = 0; i < 19; i++)cout << char(205); cout << char(188) << endl;



	cout << setw(8) << right << char(201); for (int i = 0; i < 19; i++)cout << char(205); cout << char(187)
		<< setw(16) << right << char(201); for (int i = 0; i < 19; i++)cout << char(205); cout << char(187)
		<< setw(16) << right << char(201); for (int i = 0; i < 19; i++)cout << char(205); cout << char(187) << endl;
	cout << setw(8) << right << char(186) << "Table -14 * IS FULL" << char(186)
		<< setw(16) << right << char(186) << "Table -15 * IS FULL" << char(186)
		<< setw(16) << right << char(186) << "Table -16 * IS FREE" << char(186) << endl;
	cout << setw(8) << right << char(200); for (int i = 0; i < 19; i++)cout << char(205); cout << char(188)
		<< setw(16) << right << char(200); for (int i = 0; i < 19; i++)cout << char(205); cout << char(188)
		<< setw(16) << right << char(200); for (int i = 0; i < 19; i++)cout << char(205); cout << char(188) << endl;



}


istream& operator>>(istream& in, Client& client) {
	string name;
	labbel:
	system("cls");
	cout << setw(36) << right << char(219 ); for (int i = 0; i < 22; i++)cout << char(219); cout << char(219) << endl;
	cout << setw(36) << right << char(219 ) << "Enter your name : "<< char(219)<< char(219)<< char(219)<< char(219)<< char(219) << endl;
	cout << setw(36) << right << char(219 ); for (int i = 0; i < 22; i++)cout << char(219); cout << char(219) << endl;
	in >> name;
	client.setName(name);
	string surname;
	cout << setw(36) << right << char(219); for (int i = 0; i < 22; i++)cout << char(219); cout << char(219) << endl;
	cout << setw(36) << right << char(219) << "Enter your surname : " << char(219)<< char(219) << endl;
	cout << setw(36) << right << char(219); for (int i = 0; i < 22; i++)cout << char(219); cout << char(219) << endl;
	in >> surname;
	client.setSurname(surname);
	string tableNo;

	cout << endl;
	cout << endl;
	cout << endl;
	
	cout << endl;
	cout << endl;

	client.table();
	cout << "Enter your table (Only NUmber Of Table ex: 3) : "; in >> tableNo;

	if (tableNo >= "3" && tableNo <= "9" || tableNo == "16") {
		client.setTableNo(tableNo);
	}
	else {
		cout << " Incorrect Enter " << endl;
		Sleep(1000);
		goto labbel;
	}

	return in;
}


