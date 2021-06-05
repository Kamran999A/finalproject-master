#pragma once
#include <iostream>
#include <Windows.h>
using namespace std;

void printSortedMenuForMeal() {
	cout << "1. A-Z Sorting " << endl;
	cout << "2. Z-A Sorting " << endl;
	cout << "3. For rating Sorting " << endl;
	cout << "4. For price  Sorting " << endl;
	cout << "0. For back " << endl;

}
void printSortedMenuForClientMeal() {
	cout << "1. A-Z Sorting " << endl;
	cout << "2. Z-A Sorting " << endl;
	cout << "3. For rating Sorting (Increase )" << endl;
	cout << "4. For rating Sorting (Decrease )" << endl;
	cout << "5. For price  Sorting (Increase )" << endl;
	cout << "6. For price  Sorting (Decrease )" << endl;
	cout << "0. For back " << endl;
}
void printSortedMenuForIngredient() {

	cout << "1. A-Z Sorting " << endl;
	cout << "2. Z-A Sorting " << endl;
	cout << "3. For count Sorting " << endl;
	cout << "4. For fat  Sorting " << endl;
	cout << "5. For protein Sorting " << endl;
	cout << "6. For carbonhydrat Sorting " << endl;
	cout << "7. For kkcal  Sorting " << endl;
	cout << "8. For price  Sorting " << endl;
	cout << "0. For back " << endl;

}
void printCategories() {
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << setw(55) << right << char(201); for (int i = 0; i < 9; i++)cout << char(205); cout << char(187) << endl;
	cout << setw(55) << right << char(186) << "1. Salads" << char(186) << endl;
	cout << setw(55) << right << char(200); for (int i = 0; i < 9; i++)cout << char(205); cout << char(188) << endl;

	cout << setw(55) << right << char(201); for (int i = 0; i < 16; i++)cout << char(205); cout << char(187) << endl;
	cout << setw(55) << right << char(186) << "2. Main Dishes  " << char(186) << endl;
	cout << setw(55) << right << char(200); for (int i = 0; i < 16; i++)cout << char(205); cout << char(188) << endl;

	cout << setw(55) << right << char(201); for (int i = 0; i < 14; i++)cout << char(205); cout << char(187) << endl;
	cout << setw(55) << right << char(186) << "3. Fast Food  " << char(186) << endl;
	cout << setw(55) << right << char(200); for (int i = 0; i < 14; i++)cout << char(205); cout << char(188) << endl;

	cout << setw(55) << right << char(201); for (int i = 0; i < 11; i++)cout << char(205); cout << char(187) << endl;
	cout << setw(55) << right << char(186) << "4. Desserts" << char(186) << endl;
	cout << setw(55) << right << char(200); for (int i = 0; i < 11; i++)cout << char(205); cout << char(188) << endl;

	cout << setw(55) << right << char(201); for (int i = 0; i < 15; i++)cout << char(205); cout << char(187) << endl;
	cout << setw(55) << right << char(186) << "5. All dishes  " << char(186) << endl;
	cout << setw(55) << right << char(200); for (int i = 0; i < 15; i++)cout << char(205); cout << char(188) << endl;

	cout << setw(55) << right << char(201); for (int i = 0; i < 15; i++)cout << char(205); cout << char(187) << endl;
	cout << setw(55) << right << char(186) << "0. For back    " << char(186) << endl;
	cout << setw(55) << right << char(200); for (int i = 0; i < 15; i++)cout << char(205); cout << char(188) << endl;
}
void printAscOrDesc() {
	cout << setw(55) << right << char(201); for (int i = 0; i < 15; i++)cout << char(205); cout << char(187) << endl;
	cout << setw(55) << right << char(186) << "1. Increase" << char(186) << endl;
	cout << setw(55) << right << char(200); for (int i = 0; i < 15; i++)cout << char(205); cout << char(188) << endl;

	cout << setw(55) << right << char(201); for (int i = 0; i < 15; i++)cout << char(205); cout << char(187) << endl;
	cout << setw(55) << right << char(186) << "2. Decrease"  << char(186) << endl;
	cout << setw(55) << right << char(200); for (int i = 0; i < 15; i++)cout << char(205); cout << char(188) << endl;
}
void printAdminMenu() {

	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << setw(55) << right << char(201); for (int i = 0; i < 16; i++)cout << char(205); cout << char(187) << endl;
	cout << setw(55) << right << char(186) << "1. Stock        " << char(186) << endl;
	cout << setw(55) << right << char(200); for (int i = 0; i < 16; i++)cout << char(205); cout << char(188) << endl;

	cout << setw(55) << right << char(201); for (int i = 0; i < 16; i++)cout << char(205); cout << char(187) << endl;
	cout << setw(55) << right << char(186) << "2. Kitchen      " << char(186) << endl;
	cout << setw(55) << right << char(200); for (int i = 0; i < 16; i++)cout << char(205); cout << char(188) << endl;

	cout << setw(55) << right << char(201); for (int i = 0; i < 16; i++)cout << char(205); cout << char(187) << endl;
	cout << setw(55) << right << char(186) << "3. Notification " << char(186) << endl;
	cout << setw(55) << right << char(200); for (int i = 0; i < 16; i++)cout << char(205); cout << char(188) << endl;

	cout << setw(55) << right << char(201); for (int i = 0; i < 16; i++)cout << char(205); cout << char(187) << endl;
	cout << setw(55) << right << char(186) << "0. For back     " << char(186) << endl;
	cout << setw(55) << right << char(200); for (int i = 0; i < 16; i++)cout << char(205); cout << char(188) << endl;
}
void printClientMenu() {
	cout << endl;
	cout << endl;
	cout << endl;
	cout << setw(55) << right << char(201); for (int i = 0; i < 36; i++)cout << char(205); cout << char(187) << endl;
	cout << setw(55) << right << char(186) << "For ordering please press  1	   " << char(186) << endl;
	cout << setw(55) << right << char(200); for (int i = 0; i < 36; i++)cout << char(205); cout << char(188) << endl;
	cout << endl;cout << endl;
	cout << setw(55) << right << char(201); for (int i = 0; i < 36; i++)cout << char(205); cout << char(187) << endl;
	cout << setw(55) << right << char(186) << "For sorted menu please press  2	   " << char(186) << endl;
	cout << setw(55) << right << char(200); for (int i = 0; i < 36; i++)cout << char(205); cout << char(188) << endl;
	cout << endl;cout << endl;
	cout << setw(55) << right << char(201); for (int i = 0; i < 36; i++)cout << char(205); cout << char(187) << endl;
	cout << setw(55) << right << char(186) << "For going to back please press 0	   " << char(186) << endl;
	cout << setw(55) << right << char(200); for (int i = 0; i < 36; i++)cout << char(205); cout << char(188) << endl;
	cout << endl;
	cout << endl;
	
}
void printStockMenu() {

	cout << endl;
	cout << setw(20) << right << char(201); for (int i = 0; i < 80; i++)cout << char(205); cout << char(187) << endl;
	cout << setw(20) << right << char(186) << "This is stock  of restaurant .You can do this operations . \t\t            " << char(186) << endl;
	cout << setw(20) << right << char(200); for (int i = 0; i < 80; i++)cout << char(205); cout << char(188) << endl;
	cout << endl;
	cout << endl;

	cout << setw(55) << right << char(201); for (int i = 0; i < 36; i++)cout << char(205); cout << char(187) << endl;
	cout << setw(55) << right << char(186) << "1. Looking at ingridients	   " << char(186) << endl;
	cout << setw(55) << right << char(200); for (int i = 0; i < 36; i++)cout << char(205); cout << char(188) << endl;
	cout << endl;
	cout << setw(55) << right << char(201); for (int i = 0; i < 36; i++)cout << char(205); cout << char(187) << endl;
	cout << setw(55) << right << char(186) << "2. Adding ingridients	           " << char(186) << endl;
	cout << setw(55) << right << char(200); for (int i = 0; i < 36; i++)cout << char(205); cout << char(188) << endl;
	cout << endl;
	cout << setw(55) << right << char(201); for (int i = 0; i < 36; i++)cout << char(205); cout << char(187) << endl;
	cout << setw(55) << right << char(186) << "3. Deleting ingridients	           " << char(186) << endl;
	cout << setw(55) << right << char(200); for (int i = 0; i < 36; i++)cout << char(205); cout << char(188) << endl;
	cout << endl;
	cout << setw(55) << right << char(201); for (int i = 0; i < 36; i++)cout << char(205); cout << char(187) << endl;
	cout << setw(55) << right << char(186) << "4. Sorted ingridients' list	   " << char(186) << endl;
	cout << setw(55) << right << char(200); for (int i = 0; i < 36; i++)cout << char(205); cout << char(188) << endl;
	cout << endl;
	cout << setw(55) << right << char(201); for (int i = 0; i < 36; i++)cout << char(205); cout << char(187) << endl;
	cout << setw(55) << right << char(186) << "5. Increase ingridients' count      " << char(186) << endl;
	cout << setw(55) << right << char(200); for (int i = 0; i < 36; i++)cout << char(205); cout << char(188) << endl;
	cout << endl;
	cout << setw(55) << right << char(201); for (int i = 0; i < 36; i++)cout << char(205); cout << char(187) << endl;
	cout << setw(55) << right << char(186) << "0. For back		           " << char(186) << endl;
	cout << setw(55) << right << char(200); for (int i = 0; i < 36; i++)cout << char(205); cout << char(188) << endl;
	cout << endl;

}
void printStockDeleteMenu() {
	cout << "1. Deleting for ID " << endl;
	cout << "2. Deleting for name " << endl;
	cout << "3. Deleting all stock  " << endl;
	cout << "0. For back " << endl;
}
void printKitchenMenu() {

	cout <<  endl;
	cout << setw(20) << right << char(201); for (int i = 0; i < 80; i++)cout << char(205); cout << char(187) << endl;
	cout << setw(20) << right << char(186) << "This is kitchen of restaurant .You can do this operations . \t            " << char(186) << endl;
	cout << setw(20) << right << char(200); for (int i = 0; i < 80; i++)cout << char(205); cout << char(188) << endl;
	cout <<  endl;
	cout <<  endl;

	cout << setw(55) << right << char(201); for (int i = 0; i < 36; i++)cout << char(205); cout << char(187) << endl;
	cout << setw(55) << right << char(186) << "1. Looking at orders		   " << char(186) << endl;
	cout << setw(55) << right << char(200); for (int i = 0; i < 36; i++)cout << char(205); cout << char(188) << endl;
	cout << endl;
	cout << setw(55) << right << char(201); for (int i = 0; i < 36; i++)cout << char(205); cout << char(187) << endl;
	cout << setw(55) << right << char(186) << "2. Looking at meals		   " << char(186) << endl;
	cout << setw(55) << right << char(200); for (int i = 0; i < 36; i++)cout << char(205); cout << char(188) << endl;
	cout << endl;
	cout << setw(55) << right << char(201); for (int i = 0; i < 36; i++)cout << char(205); cout << char(187) << endl;
	cout << setw(55) << right << char(186) << "3. Adding meal		           " << char(186) << endl;
	cout << setw(55) << right << char(200); for (int i = 0; i < 36; i++)cout << char(205); cout << char(188) << endl;
	cout << endl;
	cout << setw(55) << right << char(201); for (int i = 0; i < 36; i++)cout << char(205); cout << char(187) << endl;
	cout << setw(55) << right << char(186) << "4. Deleting meal		           " << char(186) << endl;
	cout << setw(55) << right << char(200); for (int i = 0; i < 36; i++)cout << char(205); cout << char(188) << endl;
	cout << endl;
	cout << setw(55) << right << char(201); for (int i = 0; i < 36; i++)cout << char(205); cout << char(187) << endl;
	cout << setw(55) << right << char(186) << "5. Update meals		           " << char(186) << endl;
	cout << setw(55) << right << char(200); for (int i = 0; i < 36; i++)cout << char(205); cout << char(188) << endl;
	cout << endl;
	cout << setw(55) << right << char(201); for (int i = 0; i < 36; i++)cout << char(205); cout << char(187) << endl;
	cout << setw(55) << right << char(186) << "6. Looking stock			   " << char(186) << endl;
	cout << setw(55) << right << char(200); for (int i = 0; i < 36; i++)cout << char(205); cout << char(188) << endl;
	cout << endl;
	cout << setw(55) << right << char(201); for (int i = 0; i < 36; i++)cout << char(205); cout << char(187) << endl;
	cout << setw(55) << right << char(186) << "7. Sorted list of meals             " << char(186) << endl;
	cout << setw(55) << right << char(200); for (int i = 0; i < 36; i++)cout << char(205); cout << char(188) << endl;
	cout << endl;
	cout << setw(55) << right << char(201); for (int i = 0; i < 36; i++)cout << char(205); cout << char(187) << endl;
	cout << setw(55) << right << char(186) << "0. For back		           " << char(186) << endl;
	cout << setw(55) << right << char(200); for (int i = 0; i < 36; i++)cout << char(205); cout << char(188) << endl;
	cout << endl;

}
void printKitchenDeleteMenu() {
	cout << "1. Deleting for ID " << endl;
	cout << "2. Deleting for name " << endl;
	cout << "3. Deleting all meals " << endl;
	cout << "0. For back " << endl;
}
void printEatingMeal() {
	for (size_t i = 10; i > 0; i--)
	{
		system("cls");
		cout << "Table is cleaning ... " << i << " seconds remaining" << endl;
		Sleep(1000);
	}
	cout << "Bona petit ." << endl;
	cout << "Did you like HEWAL  ?" << endl;
	cout << "1. Yes " << endl;
	cout << "2. No " << endl;
}