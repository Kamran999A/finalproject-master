#pragma once
#include <iostream>
#include <string>
#include <list>
#include <iomanip>
#include <algorithm>
#include <Windows.h>
#include <fstream>
#include "Menu.h"
#include "Ingredient.h"
#include "Meal.h"
#include "Restaurant.h"
using namespace std;

void start() {

	Admin a("admin", "admin", 77, "+994502625522", "admin", "admin");
	Admin a1("Kamran", "Aliyev", 23, "+994502625522", "admin", "admin");
	string username;
	string password;
	Client c;
	Stock s;
	Kitchen k;
	Restaurant r("Nusaibin's Tastes", "Nusaibin Kurdistan", "NUSAIBIN City", 7);

	int ingredientID;
	string ingredientName;
	int ingredientCount;
	double ingredientFat;
	double ingredientProtein;
	double ingredientCarbohydrates;
	int ingredientKcal;
	double ingredientPrice;

	int mealID;
	string mealName;
	string mealCategory;
	double mealRating;
	double mealPrice;
	double mealTax;

	int count = 0;
	string str;

	s.writeDataToFileIngredient();
	k.writeDataToFileMeal();
	//cout << s.getDataFromFileIngredient("Ingredient.txt");
	//cout << k.getDataFromFileMeal("Meal.txt");
	//Sleep(10000);

FirstMenu:
	k.clearOrders();
	s.clearOrderIngredients();
	system("cls");
	printMenu(r);
	char operation1;
	cin >> operation1;

	int goBack;
	switch (operation1)
	{
	ClientMenu:
	case '1':
		cin >> c;
		system("cls");
		cout << "WELCOME  " << c.getName() << " HEWAL! You can choose any catagory and look dishes." << endl;
	ShowCategories:
		printCategories();
		int operation2;
		cin >> operation2;
		switch (operation2)
		{
		case 1:
			system("cls");
			k.showByCategorySalad();
			printClientMenu();
			int operationSalad;
			cin >> operationSalad;
			switch (operationSalad)
			{
			OrderSalad:
			case 1:
				cout << "Enter the ID of meal :  ";
				cin >> mealID;
				k.order(mealID);
				char operationAddIngredientSalad;
				cout << "Do you want to add any ingredient ? (y/n): "; cin >> operationAddIngredientSalad;
			AddIngredientToOrderSalad:
				system("cls");
				if (operationAddIngredientSalad == 'y')
				{
					system("cls");
					s.show();
					cout << "Enter the ID of ingredient : ";
					cin >> ingredientID;
					s.addIngredientToOrder(ingredientID);
					cout << endl;
					cout << "Do you want to add more ?(y/n)"; cin >> operationAddIngredientSalad;
					if (operationAddIngredientSalad == 'y') goto AddIngredientToOrderSalad;
					else if (operationAddIngredientSalad == 'n') goto AddIngredientToOrderSalad;
					else { cout << "Invalid choice !" << endl; goto AddIngredientToOrderSalad; }
				}
				else if (operationAddIngredientSalad == 'n')
				{
				AdditionalOrderSalad:
					char operationAddMealSalad;
					cout << "Do you want to add more dishes ? (y/n): "; cin >> operationAddMealSalad;
					if (operationAddMealSalad == 'y')
					{
						system("cls");
						goto ShowCategories;
					}
					else if (operationAddMealSalad == 'n') {
						system("cls");
						goto NoAdditionalOrderSalad;
					}
					else
					{
						cout << "Invalid choice !" << endl;
						system("cls");
						k.showByCategorySalad();
						goto OrderSalad;
					}
				NoAdditionalOrderSalad:
					system("cls");
					cout << "Order : \n"; k.showOrders();
					cout << endl << endl;
					s.showOrderedIngredients();
					cout << "\nSum Price : " << k.getMealsPrice() + finalPrice;
					cout << "\n\nTo continue Press 1 " << endl;
					int goForward;
					cin >> goForward;
					if (goForward == 1)
					{
						printEatingMeal();
						cin >> goForward;
						if (goForward == 1) {
							system("cls");
							cout << "Thanks for choosing us !!! :)" << endl;
							k.increaseRating(mealID);
							Sleep(3000);
							goto FirstMenu;
						}
						else if (goForward == 2) {
							system("cls");
							cout << "Hope next time would like  !!! :)" << endl;
							k.decreaseRating(mealID);
							Sleep(3000);
							goto FirstMenu;
						}
						else {
							system("cls");
							goto NoAdditionalOrderSalad;
						}
					}
					else {
						cout << "Invalid choice !!!" << endl;
						Sleep(1500);
						system("cls");
						goto NoAdditionalOrderSalad;
					}
				}
				else
				{
					cout << "Invalid choice !" << endl;
					goto OrderSalad;
				}
				break;
			SortingMenuForSalad:
			case 2:
				system("cls");
				printSortedMenuForClientMeal();
				int operationSaladSort;
				cin >> operationSaladSort;
				system("cls");
				switch (operationSaladSort)
				{
				case 1:
					system("cls");
					k.sortByNameSalad("Asc");
					k.showSalads();
					cout << "\nFor order PRESS  1\nFor back PRESS  0" << endl;
					cin >> operationSalad;
					if (operationSalad == 1)
					{
						goto OrderSalad;
						system("cls");
					}
					else if (operationSalad == 0) {
						system("cls");
						goto SortingMenuForSalad;
					}
					else {
						cout << "Invalid choice !" << endl;
						Sleep(1500);
						system("cls");
						goto SortingMenuForSalad;
					}
					break;
				case 2:
					system("cls");
					k.sortByNameSalad("Desc");
					k.showSalads();
					cout << "\nFor order PRESS  1\nFor back PRESS  0" << endl;
					cin >> operationSalad;
					if (operationSalad == 1)
					{
						goto OrderSalad;
						system("cls");
					}
					else if (operationSalad == 0) {
						system("cls");
						goto SortingMenuForSalad;
					}
					else {
						cout << "Invalid choice !" << endl;
						Sleep(1500);
						system("cls");
						goto SortingMenuForSalad;
					}
					break;
				case 3:
					system("cls");
					k.sortByRatingSalad("Asc");
					k.showSalads();
					cout << "\nFor order PRESS  1\nFor back PRESS  0" << endl;
					cin >> operationSalad;
					if (operationSalad == 1)
					{
						goto OrderSalad;
						system("cls");
					}
					else if (operationSalad == 0) {
						system("cls");
						goto SortingMenuForSalad;
					}
					else {
						cout << "Invalid choice !" << endl;
						Sleep(1500);
						system("cls");
						goto SortingMenuForSalad;
					}
					break;
				case 4:
					system("cls");
					k.sortByRatingSalad("Desc");
					k.showSalads();
					cout << "\nFor order PRESS  1\nFor back PRESS  0" << endl;
					cin >> operationSalad;
					if (operationSalad == 1)
					{
						goto OrderSalad;
						system("cls");
					}
					else if (operationSalad == 0) {
						system("cls");
						goto SortingMenuForSalad;
					}
					else {
						cout << "Invalid choice !" << endl;
						Sleep(1500);
						system("cls");
						goto SortingMenuForSalad;
					}
					break;
				case 5:
					system("cls");
					k.sortByPriceSalad("Asc");
					k.showSalads();
					cout << "\nFor order PRESS  1\nFor back PRESS  0" << endl;
					cin >> operationSalad;
					if (operationSalad == 1)
					{
						goto OrderSalad;
						system("cls");
					}
					else if (operationSalad == 0) {
						system("cls");
						goto SortingMenuForSalad;
					}
					else {
						cout << "Invalid choice !" << endl;
						Sleep(1500);
						system("cls");
						goto SortingMenuForSalad;
					}
					break;
				case 6:
					system("cls");
					k.sortByPriceSalad("Desc");
					k.showSalads();
					cout << "\nFor order PRESS  1\nFor back PRESS  0" << endl;
					cin >> operationSalad;
					if (operationSalad == 1)
					{
						goto OrderSalad;
						system("cls");
					}
					else if (operationSalad == 0) {
						system("cls");
						goto SortingMenuForSalad;
					}
					else {
						cout << "Invalid choice !" << endl;
						Sleep(1500);
						system("cls");
						goto SortingMenuForSalad;
					}
					break;
				case 0:
					system("cls");
					goto ShowCategories;
					break;
				default:
					cout << "Please enter correct choice !" << endl;
					goto SortingMenuForSalad;
					break;
				}
			case 0:
				system("cls");
				goto ShowCategories;
				break;
			default:
				cout << "Invalid choice !!!!" << endl;
				Sleep(1500);
				system("cls");
				goto ShowCategories;
				break;
			}
			break;
		case 2:
			system("cls");
			k.showByCategoryMainDish();
			printClientMenu();
			int operationMainDish;
			cin >> operationMainDish;
			switch (operationMainDish)
			{
			OrderMainDish:
			case 1:
				cout << "Enter the ID of meal :  "; // ----> Sifarish vermek!!!!!!!
				cin >> mealID;
				k.order(mealID);
				char operationAddIngredientMainDish;
				cout << "Do you want to add any ingredient ? (y/n): "; cin >> operationAddIngredientMainDish;
			AddIngredientToOrderMainDish:
				system("cls");
				if (operationAddIngredientMainDish == 'y')
				{
					system("cls");
					s.show();
					cout << "Enter the ID of ingredient : ";
					cin >> ingredientID;
					s.addIngredientToOrder(ingredientID);
					cout << endl;
					cout << "Do you want to add more ?(y/n)"; cin >> operationAddIngredientMainDish;
					if (operationAddIngredientMainDish == 'y') goto AddIngredientToOrderMainDish;
					else if (operationAddIngredientMainDish == 'n') goto AddIngredientToOrderMainDish;
					else { cout << "Invalid choice !" << endl; goto AddIngredientToOrderMainDish; }
				}
				else if (operationAddIngredientMainDish == 'n')
				{
				AdditionalOrderMainDish:
					char operationAddMealMainDish;
					cout << "Do you want to add more dishes ? (y/n): "; cin >> operationAddMealMainDish;
					if (operationAddMealMainDish == 'y')
					{
						system("cls");
						goto ShowCategories;
					}
					else if (operationAddMealMainDish == 'n') {
						system("cls");
						goto NoAdditionalOrderMainDish;
					}
					else
					{
						cout << "Invalid choice !" << endl;
						system("cls");
						k.showByCategorySalad();
						goto OrderSalad;
					}
				NoAdditionalOrderMainDish:
					system("cls");
					cout << "Order : \n"; k.showOrders();
					cout << endl << endl;
					s.showOrderedIngredients();
					cout << "\nSum Price : " << k.getMealsPrice() + finalPrice;
					int goForward;
					cout << "\n\nFor continue PRESS 1 " << endl;
					cin >> goForward;
					if (goForward == 1) {
						printEatingMeal();
						cin >> goForward;
						if (goForward == 1) {
							system("cls");
							cout << "Thanks for choosing us !!! :)!" << endl;
							k.increaseRating(mealID);
							Sleep(3000);
							goto FirstMenu;
						}
						else if (goForward == 2) {
							system("cls");
							cout << "Hope next time would like  !!! :)!" << endl;
							k.decreaseRating(mealID);
							Sleep(3000);
							goto FirstMenu;
						}
						else {
							system("cls");
							goto NoAdditionalOrderMainDish;
						}
					}
					else {
						cout << "Invalid choice !!!" << endl;
						Sleep(1500);
						system("cls");
						goto NoAdditionalOrderSalad;
					}
				}
				else
				{
					cout << "Invalid choice !" << endl;
					goto OrderMainDish;
				}
				break;
			SortingMenuForMainDish:
			case 2:
				system("cls");
				printSortedMenuForClientMeal();
				int operationMainDishSort;
				cin >> operationMainDishSort;
				system("cls");
				switch (operationMainDishSort)
				{
				case 1:
					system("cls");
					k.sortByNameMainDish("Asc");
					k.showMainDishes();
					cout << "\nFor order PRESS  1\nFor back PRESS  0" << endl;
					cin >> operationMainDish;
					if (operationMainDish == 1)
					{
						goto OrderMainDish;
						system("cls");
					}
					else if (operationMainDish == 0) {
						system("cls");
						goto SortingMenuForMainDish;
					}
					else {
						cout << "Invalid choice !" << endl;
						Sleep(1500);
						system("cls");
						goto SortingMenuForMainDish;
					}
					break;
				case 2:
					system("cls");
					k.sortByNameMainDish("Desc");
					k.showMainDishes();
					cout << "\nFor order PRESS  1\nFor back PRESS  0" << endl;
					cin >> operationMainDish;
					if (operationMainDish == 1)
					{
						goto OrderMainDish;
						system("cls");
					}
					else if (operationMainDish == 0) {
						system("cls");
						goto SortingMenuForMainDish;
					}
					else {
						cout << "Invalid choice !" << endl;
						Sleep(1500);
						system("cls");
						goto SortingMenuForMainDish;
					}
					break;
				case 3:
					system("cls");
					k.sortByRatingMainDish("Asc");
					k.showMainDishes();
					cout << "\nFor order PRESS  1\nFor back PRESS  0" << endl;
					cin >> operationMainDish;
					if (operationMainDish == 1)
					{
						goto OrderMainDish;
						system("cls");
					}
					else if (operationMainDish == 0) {
						system("cls");
						goto SortingMenuForMainDish;
					}
					else {
						cout << "Invalid choice !" << endl;
						Sleep(1500);
						system("cls");
						goto SortingMenuForMainDish;
					}
					break;
				case 4:
					system("cls");
					k.sortByRatingMainDish("Desc");
					k.showMainDishes();
					cout << "\nFor order PRESS  1\nFor back PRESS  0" << endl;
					cin >> operationMainDish;
					if (operationMainDish == 1)
					{
						goto OrderMainDish;
						system("cls");
					}
					else if (operationMainDish == 0) {
						system("cls");
						goto SortingMenuForMainDish;
					}
					else {
						cout << "Invalid choice !" << endl;
						Sleep(1500);
						system("cls");
						goto SortingMenuForMainDish;
					}
					break;
				case 5:
					system("cls");
					k.sortByPriceMainDish("Asc");
					k.showMainDishes();
					cout << "\nFor order PRESS  1\nFor back PRESS  0" << endl;
					cin >> operationMainDish;
					if (operationMainDish == 1)
					{
						goto OrderMainDish;
						system("cls");
					}
					else if (operationMainDish == 0) {
						system("cls");
						goto SortingMenuForMainDish;
					}
					else {
						cout << "Invalid choice !" << endl;
						Sleep(1500);
						system("cls");
						goto SortingMenuForMainDish;
					}
					break;
				case 6:
					system("cls");
					k.sortByPriceMainDish("Desc");
					k.showMainDishes();
					cout << "\nFor order PRESS  1\nFor back PRESS  0" << endl;
					cin >> operationMainDish;
					if (operationMainDish == 1)
					{
						goto OrderMainDish;
						system("cls");
					}
					else if (operationMainDish == 0) {
						system("cls");
						goto SortingMenuForMainDish;
					}
					else {
						cout << "Invalid choice !" << endl;
						Sleep(1500);
						system("cls");
						goto SortingMenuForMainDish;
					}
					break;
				case 0:
					system("cls");
					goto ShowCategories;
					break;
				default:
					cout << "Please enter correct choice !" << endl;
					goto SortingMenuForMainDish;
					break;
				}
			case 0:
				system("cls");
				goto ShowCategories;
				break;
			default:
				cout << "Invalid choice !!!!" << endl;
				Sleep(1500);
				system("cls");
				goto ShowCategories;
				break;
			}
			break;
		case 3:
			system("cls");
			k.showByCategoryFastFood();
			printClientMenu();
			int operationFastFood;
			cin >> operationFastFood;
			switch (operationFastFood)
			{
			OrderFastFood:
			case 1:
				cout << "Enter the ID of meal :  "; // ----> Sifarish vermek!!!!!!!
				cin >> mealID;
				k.order(mealID);
				char operationAddIngredientFastFood;
				cout << "Do you want to add any ingredient ? (y/n): "; cin >> operationAddIngredientFastFood;
			AddIngredientToOrderFastFood:
				system("cls");
				if (operationAddIngredientFastFood == 'y')
				{
					system("cls");
					s.show();
					cout << "Enter the ID of ingredient : ";
					cin >> ingredientID;
					s.addIngredientToOrder(ingredientID);
					cout << endl;
					cout << "Do you want to add more ?(y/n)"; cin >> operationAddIngredientFastFood;
					if (operationAddIngredientFastFood == 'y') goto AddIngredientToOrderFastFood;
					else if (operationAddIngredientFastFood == 'n') goto AddIngredientToOrderFastFood;
					else { cout << "Invalid choice !" << endl; goto AddIngredientToOrderFastFood; }
				}
				else if (operationAddIngredientFastFood == 'n')
				{
				AdditionalOrderFastFood:
					char operationAddMealFastFood;
					cout << "Do you want to add more dishes ? (y/n): "; cin >> operationAddMealFastFood;
					if (operationAddMealFastFood == 'y')
					{
						system("cls");
						goto ShowCategories;
					}
					else if (operationAddMealFastFood == 'n') {
						system("cls");
						goto NoAdditionalOrderFastFood;
					}
					else
					{
						cout << "Invalid choice !" << endl;
						system("cls");
						k.showByCategorySalad();
						goto OrderSalad;
					}
				NoAdditionalOrderFastFood:
					system("cls");
					cout << "Order : \n"; k.showOrders();
					cout << endl << endl;
					s.showOrderedIngredients();
					cout << "\nSum Price : " << k.getMealsPrice() + finalPrice;
					int goForward;
					cout << "\n\nFor continue PRESS 1 " << endl;
					cin >> goForward;
					if (goForward == 1) {

						printEatingMeal();
						cin >> goForward;
						if (goForward == 1) {
							system("cls");
							cout << "Thanks for choosing us !!! :)!" << endl;
							k.increaseRating(mealID);
							Sleep(3000);
							goto FirstMenu;
						}
						else if (goForward == 2) {
							system("cls");
							cout << "Hope next time would like  !!! :)!" << endl;
							k.decreaseRating(mealID);
							Sleep(3000);
							goto FirstMenu;
						}
						else {
							system("cls");
							goto NoAdditionalOrderFastFood;
						}
					}
					else {
						cout << "Invalid choice !!!" << endl;
						Sleep(1500);
						system("cls");
						goto NoAdditionalOrderSalad;
					}
				}
				else
				{
					cout << "Invalid choice !" << endl;
					goto OrderFastFood;
				}
				break;
			SortingMenuForFastFood:
			case 2:
				printSortedMenuForClientMeal();
				int operationFastFoodSort;
				cin >> operationFastFoodSort;
				system("cls");
				switch (operationFastFoodSort)
				{
				case 1:
					system("cls");
					k.sortByNameFastFood("Asc");
					k.showFastFoods();
					cout << "\nFor order PRESS  1\nFor back PRESS  0" << endl;
					cin >> operationFastFood;
					if (operationFastFood == 1)
					{
						goto OrderFastFood;
						system("cls");
					}
					else if (operationFastFood == 0) {
						system("cls");
						goto SortingMenuForFastFood;
					}
					else {
						cout << "Invalid choice !" << endl;
						Sleep(1500);
						system("cls");
						goto SortingMenuForFastFood;
					}
					break;
				case 2:
					system("cls");
					k.sortByNameFastFood("Desc");
					k.showFastFoods();
					cout << "\nFor order PRESS  1\nFor back PRESS  0" << endl;
					cin >> operationFastFood;
					if (operationFastFood == 1)
					{
						goto OrderFastFood;
						system("cls");
					}
					else if (operationFastFood == 0) {
						system("cls");
						goto SortingMenuForFastFood;
					}
					else {
						cout << "Invalid choice !" << endl;
						Sleep(1500);
						system("cls");
						goto SortingMenuForFastFood;
					}
					break;
				case 3:
					system("cls");
					k.sortByRatingFastFood("Asc");
					k.showFastFoods();
					cout << "\nFor order PRESS  1\nFor back PRESS  0" << endl;
					cin >> operationFastFood;
					if (operationFastFood == 1)
					{
						goto OrderFastFood;
						system("cls");
					}
					else if (operationFastFood == 0) {
						system("cls");
						goto SortingMenuForFastFood;
					}
					else {
						cout << "Invalid choice !" << endl;
						Sleep(1500);
						system("cls");
						goto SortingMenuForFastFood;
					}
					break;
				case 4:
					system("cls");
					k.sortByRatingFastFood("Desc");
					k.showFastFoods();
					cout << "\nFor order PRESS  1\nFor back PRESS  0" << endl;
					cin >> operationFastFood;
					if (operationFastFood == 1)
					{
						goto OrderFastFood;
						system("cls");
					}
					else if (operationFastFood == 0) {
						system("cls");
						goto SortingMenuForFastFood;
					}
					else {
						cout << "Invalid choice !" << endl;
						Sleep(1500);
						system("cls");
						goto SortingMenuForFastFood;
					}
					break;
				case 5:
					system("cls");
					k.sortByPriceFastFood("Asc");
					k.showFastFoods();
					cout << "\nFor order PRESS  1\nFor back PRESS  0" << endl;
					cin >> operationFastFood;
					if (operationFastFood == 1)
					{
						goto OrderFastFood;
						system("cls");
					}
					else if (operationFastFood == 0) {
						system("cls");
						goto SortingMenuForFastFood;
					}
					else {
						cout << "Invalid choice !" << endl;
						Sleep(1500);
						system("cls");
						goto SortingMenuForFastFood;
					}
					break;
				case 6:
					system("cls");
					k.sortByPriceFastFood("Desc");
					k.showFastFoods();
					cout << "\nFor order PRESS  1\nFor back PRESS  0" << endl;
					cin >> operationFastFood;
					if (operationFastFood == 1)
					{
						goto OrderFastFood;
						system("cls");
					}
					else if (operationFastFood == 0) {
						system("cls");
						goto SortingMenuForFastFood;
					}
					else {
						cout << "Invalid choice !" << endl;
						Sleep(1500);
						system("cls");
						goto SortingMenuForFastFood;
					}
					break;
				default:
					cout << "Please enter correct choice !" << endl;
					goto SortingMenuForFastFood;
					break;
				}
			case 0:
				system("cls");
				goto ShowCategories;
				break;
			default:
				cout << "Invalid choice !!!!" << endl;
				Sleep(1500);
				system("cls");
				goto ShowCategories;
				break;
			}
			break;

		case 4:
			system("cls");
			k.showByCategoryDessert();
			printClientMenu();
			int operationDessert;
			cin >> operationDessert;
			switch (operationDessert)
			{
			OrderDessert:
			case 1:
				cout << "Enter the ID of meal :  "; // ----> Sifarish vermek!!!!!!!
				cin >> mealID;
				k.order(mealID);
				char operationAddIngredientDessert;
				cout << "Do you want to add any ingredient ? (y/n): "; cin >> operationAddIngredientDessert;
			AddIngredientToOrderDessert:
				system("cls");
				if (operationAddIngredientDessert == 'y')
				{
					system("cls");
					s.show();
					cout << "Enter the ID of ingredient : ";
					cin >> ingredientID;
					s.addIngredientToOrder(ingredientID);
					cout << endl;
					cout << "Do you want to add more ?(y/n)"; cin >> operationAddIngredientDessert;
					if (operationAddIngredientDessert == 'y') goto AddIngredientToOrderDessert;
					else if (operationAddIngredientDessert == 'n') goto AddIngredientToOrderDessert;
					else { cout << "Invalid choice !" << endl; goto AddIngredientToOrderDessert; }
				}
				else if (operationAddIngredientDessert == 'n')
				{
				AdditionalOrderDessert:
					char operationAddMealDessert;
					cout << "Do you want to add more dishes ? (y/n): "; cin >> operationAddMealDessert;
					if (operationAddMealDessert == 'y')
					{
						system("cls");
						goto ShowCategories;
					}
					else if (operationAddMealDessert == 'n') {
						system("cls");
						goto NoAdditionalOrderDessert;
					}
					else
					{
						cout << "Invalid choice !" << endl;
						system("cls");
						k.showByCategorySalad();
						goto OrderSalad;
					}
				NoAdditionalOrderDessert:
					system("cls");
					cout << "Order : \n"; k.showOrders();
					cout << endl << endl;
					s.showOrderedIngredients();
					cout << "\nSum Price : " << k.getMealsPrice() + finalPrice;
					int goForward;
					cout << "\n\nFor continue PRESS 1 " << endl;
					cin >> goForward;
					if (goForward == 1) {

						printEatingMeal();
						cin >> goForward;
						if (goForward == 1) {
							system("cls");
							cout << "Thanks for choosing us !!! :)!" << endl;
							k.increaseRating(mealID);
							Sleep(3000);
							goto FirstMenu;
						}
						else if (goForward == 2) {
							system("cls");
							cout << "Hope next time would like  !!! :)!" << endl;
							k.decreaseRating(mealID);
							Sleep(3000);
							goto FirstMenu;
						}
						else {
							system("cls");
							goto NoAdditionalOrderDessert;
						}
					}
					else {
						cout << "Invalid choice !!!" << endl;
						Sleep(1500);
						system("cls");
						goto NoAdditionalOrderSalad;
					}
				}
				else
				{
					cout << "Invalid choice !" << endl;
					goto OrderDessert;
				}
				break;
			SortingMenuForDessert:
			case 2:
				printSortedMenuForClientMeal();
				int operationDessertSort;
				cin >> operationDessertSort;
				system("cls");
				switch (operationDessertSort)
				{
				case 1:
					system("cls");
					k.sortByNameDessert("Asc");
					k.showDesserts();
					cout << "\nFor order PRESS  1\nFor back PRESS  0" << endl;
					cin >> operationDessert;
					if (operationDessert == 1)
					{
						goto OrderDessert;
						system("cls");
					}
					else if (operationDessert == 0) {
						system("cls");
						goto SortingMenuForDessert;
					}
					else {
						cout << "Invalid choice !" << endl;
						Sleep(1500);
						system("cls");
						goto SortingMenuForDessert;
					}
					break;
				case 2:
					system("cls");
					k.sortByNameDessert("Desc");
					k.showDesserts();
					cout << "\nFor order PRESS  1\nFor back PRESS  0" << endl;
					cin >> operationDessert;
					if (operationDessert == 1)
					{
						goto OrderDessert;
						system("cls");
					}
					else if (operationDessert == 0) {
						system("cls");
						goto SortingMenuForDessert;
					}
					else {
						cout << "Invalid choice !" << endl;
						Sleep(1500);
						system("cls");
						goto SortingMenuForDessert;
					}
					break;
				case 3:
					system("cls");
					k.sortByRatingDessert("Asc");
					k.showDesserts();
					cout << "\nFor order PRESS  1\nFor back PRESS  0" << endl;
					cin >> operationDessert;
					if (operationDessert == 1)
					{
						goto OrderDessert;
						system("cls");
					}
					else if (operationDessert == 0) {
						system("cls");
						goto SortingMenuForDessert;
					}
					else {
						cout << "Invalid choice !" << endl;
						Sleep(1500);
						system("cls");
						goto SortingMenuForDessert;
					}
					break;
				case 4:
					system("cls");
					k.sortByRatingDessert("Desc");
					k.showDesserts();
					cout << "\nFor order PRESS  1\nFor back PRESS  0" << endl;
					cin >> operationDessert;
					if (operationDessert == 1)
					{
						goto OrderDessert;
						system("cls");
					}
					else if (operationDessert == 0) {
						system("cls");
						goto SortingMenuForDessert;
					}
					else {
						cout << "Invalid choice !" << endl;
						Sleep(1500);
						system("cls");
						goto SortingMenuForDessert;
					}
					break;
				case 5:
					system("cls");
					k.sortByPriceDessert("Asc");
					k.showDesserts();
					cout << "\nFor order PRESS  1\nFor back PRESS  0" << endl;
					cin >> operationDessert;
					if (operationDessert == 1)
					{
						goto OrderDessert;
						system("cls");
					}
					else if (operationDessert == 0) {
						system("cls");
						goto SortingMenuForDessert;
					}
					else {
						cout << "Invalid choice !" << endl;
						Sleep(1500);
						system("cls");
						goto SortingMenuForDessert;
					}
					break;
				case 6:
					system("cls");
					k.sortByPriceDessert("Desc");
					k.showDesserts();
					cout << "\nFor order PRESS  1\nFor back PRESS  0" << endl;
					cin >> operationDessert;
					if (operationDessert == 1)
					{
						goto OrderDessert;
						system("cls");
					}
					else if (operationDessert == 0) {
						system("cls");
						goto SortingMenuForDessert;
					}
					else {
						cout << "Invalid choice !" << endl;
						Sleep(1500);
						system("cls");
						goto SortingMenuForDessert;
					}
					break;
				case 0:
					system("cls");
					goto ShowCategories;
					break;
				default:
					cout << "Please enter correct choice !" << endl;
					goto SortingMenuForDessert;
					break;
				}
			case 0:
				system("cls");
				goto ShowCategories;
				break;
			default:
				cout << "Invalid choice !!!!" << endl;
				Sleep(1500);
				system("cls");
				goto ShowCategories;
				break;
			}
			break;
		CategoryAllDishes:
		case 5:
			system("cls");
			k.show();
			printClientMenu();
			int operationAllDishes;
			cin >> operationAllDishes;
			switch (operationAllDishes)
			{
			OrderDish:
			case 1:
				cout << "Enter the ID of meal :  "; // ----> Sifarish vermek!!!!!!!
				cin >> mealID;
				k.order(mealID);
				char operationAddIngredientDish;
				cout << "Do you want to add any ingredient ? (y/n): "; cin >> operationAddIngredientDish;
			AddIngredientToOrderDish:
				system("cls");
				if (operationAddIngredientDish == 'y')
				{
					system("cls");
					s.show();
					cout << "Enter the ID of ingredient : ";
					cin >> ingredientID;
					s.addIngredientToOrder(ingredientID);
					cout << endl;
					cout << "Do you want to add more ?(y/n)"; cin >> operationAddIngredientDish;
					if (operationAddIngredientDish == 'y') goto AddIngredientToOrderDish;
					else if (operationAddIngredientDish == 'n') goto AddIngredientToOrderDish;
					else { cout << "Invalid choice !" << endl; goto AddIngredientToOrderDish; }
				}
				else if (operationAddIngredientDish == 'n')
				{
				AdditionalOrderDish:
					char operationAddMealDish;
					cout << "Do you want to add more dishes ? (y/n): "; cin >> operationAddMealDish;
					if (operationAddMealDish == 'y')
					{
						system("cls");
						goto ShowCategories;
					}
					else if (operationAddMealDish == 'n') {
						system("cls");
						goto NoAdditionalOrderDish;
					}
					else
					{
						cout << "Invalid choice !" << endl;
						system("cls");
						k.showByCategorySalad();
						goto OrderSalad;
					}
				NoAdditionalOrderDish:
					system("cls");
					cout << "Order : \n"; k.showOrders();
					cout << endl << endl;
					s.showOrderedIngredients();
					cout << "\nSum Price : " << k.getMealsPrice() + finalPrice;
					int goForward;
					cout << "\n\nFor continue PRESS 1 " << endl;
					cin >> goForward;
					if (goForward == 1) {

						printEatingMeal();
						cin >> goForward;
						if (goForward == 1) {
							system("cls");
							cout << "Thanks for choosing us !!! :)!" << endl;
							k.increaseRating(mealID);
							Sleep(3000);
							goto FirstMenu;
						}
						else if (goForward == 2) {
							system("cls");
							cout << "Hope next time would like  !!! :)!" << endl;
							k.decreaseRating(mealID);
							Sleep(3000);
							goto FirstMenu;
						}
						else {
							system("cls");
							goto NoAdditionalOrderDish;
						}
					}
					else {
						cout << "Invalid choice !!!" << endl;
						Sleep(1500);
						system("cls");
						goto NoAdditionalOrderSalad;
					}
				}
				else
				{
					cout << "Invalid choice !" << endl;
					goto OrderDish;
				}
				break;
			SortingMenuForDish:
			case 2:
				printSortedMenuForClientMeal();
				int operationDishSort;
				cin >> operationDishSort;
				system("cls");
				switch (operationDishSort)
				{
				case 1:
					system("cls");
					k.sortByName("Asc");
					k.show();
					cout << "\nFor order PRESS  1\nFor back PRESS  0" << endl;
					cin >> operationAllDishes;
					if (operationAllDishes == 1)
					{
						goto OrderDish;
						system("cls");
					}
					else if (operationAllDishes == 0) {
						system("cls");
						goto SortingMenuForDish;
					}
					else {
						cout << "Invalid choice !" << endl;
						Sleep(1500);
						system("cls");
						goto SortingMenuForDish;
					}
					break;
				case 2:
					system("cls");
					k.sortByName("Desc");
					k.show();
					cout << "\nFor order PRESS  1\nFor back PRESS  0" << endl;
					cin >> operationAllDishes;
					if (operationAllDishes == 1)
					{
						goto OrderDish;
						system("cls");
					}
					else if (operationAllDishes == 0) {
						system("cls");
						goto SortingMenuForDish;
					}
					else {
						cout << "Invalid choice !" << endl;
						Sleep(1500);
						system("cls");
						goto SortingMenuForDish;
					}
					break;
				case 3:
					system("cls");
					k.sortByRating("Asc");
					k.show();
					cout << "\nFor order PRESS  1\nFor back PRESS  0" << endl;
					cin >> operationAllDishes;
					if (operationAllDishes == 1)
					{
						goto OrderDish;
						system("cls");
					}
					else if (operationAllDishes == 0) {
						system("cls");
						goto SortingMenuForDish;
					}
					else {
						cout << "Invalid choice !" << endl;
						Sleep(1500);
						system("cls");
						goto SortingMenuForDish;
					}
					break;
				case 4:
					system("cls");
					k.sortByRating("Desc");
					k.show();
					cout << "\nFor order PRESS  1\nFor back PRESS  0" << endl;
					cin >> operationAllDishes;
					if (operationAllDishes == 1)
					{
						goto OrderDish;
						system("cls");
					}
					else if (operationAllDishes == 0) {
						system("cls");
						goto SortingMenuForDish;
					}
					else {
						cout << "Invalid choice !" << endl;
						Sleep(1500);
						system("cls");
						goto SortingMenuForDish;
					}
					break;
				case 5:
					system("cls");
					k.sortByPrice("Asc");
					k.show();
					cout << "\nFor order PRESS  1\nFor back PRESS  0" << endl;
					cin >> operationAllDishes;
					if (operationAllDishes == 1)
					{
						goto OrderDish;
						system("cls");
					}
					else if (operationAllDishes == 0) {
						system("cls");
						goto SortingMenuForDish;
					}
					else {
						cout << "Invalid choice !" << endl;
						Sleep(1500);
						system("cls");
						goto SortingMenuForDish;
					}
					break;
				case 6:
					system("cls");
					k.sortByPrice("Desc");
					k.show();
					cout << "\nFor order PRESS  1\nFor back PRESS  0" << endl;
					cin >> operationAllDishes;
					if (operationAllDishes == 1)
					{
						goto OrderDish;
						system("cls");
					}
					else if (operationAllDishes == 0) {
						system("cls");
						goto SortingMenuForDish;
					}
					else {
						cout << "Invalid choice !" << endl;
						Sleep(1500);
						system("cls");
						goto SortingMenuForDish;
					}
					break;
				case 0:
					system("cls");
					goto ShowCategories;
					break;
				default:
					cout << "Please enter correct choice !" << endl;
					goto SortingMenuForDish;
					break;
				}
			case 0:
				system("cls");
				goto ShowCategories;
				break;
			default:
				cout << "Invalid choice !" << endl;
				Sleep(1500);
				system("cls");
				goto ShowCategories;
				break;
			}
			break;
		case 0:
			system("cls");
			goto FirstMenu;
			break;
		default:
			cout << "Invalid choice !" << endl;
			Sleep(1500);
			system("cls");
			goto ShowCategories;
			break;
		}
		break;
	AdminMenu:
	case '2':
		system("cls");


		cout << setw(20) << right << char(201); for (int i = 0; i < 45; i++)cout << char(205); cout << char(187) << endl;
		cout << setw(20) << right << char(186) << "Please enter username and password ! \t " << char(186) << endl;
		cout << setw(20) << right << char(200); for (int i = 0; i < 45; i++)cout << char(205); cout << char(188) << endl;
		

		cout << setw(20) << right << char(201); for (int i = 0; i < 72; i++)cout << char(205); cout << char(187) << endl;
		cout << setw(20) << right << char(186) << "If you entered your datas 3 time wrong, you would forwarded to main menu" << char(186) << endl;
		cout << setw(20) << right << char(200); for (int i = 0; i < 72; i++)cout << char(205); cout << char(188) << endl;

		cout << setw(20) << right << char(201); for (int i = 0; i < 18; i++)cout << char(205); cout << char(187) << endl;
		cout << setw(20) << right << char(186) << "username:         " << char(186) << endl;
		cout << setw(20) << right << char(200); for (int i = 0; i < 18; i++)cout << char(205); cout << char(188) << endl;
		cin >> username;
		cout << setw(20) << right << char(201); for (int i = 0; i < 18; i++)cout << char(205); cout << char(187) << endl;
		cout << setw(20) << right << char(186) << "password:         " << char(186) << endl;
		cout << setw(20) << right << char(200); for (int i = 0; i < 18; i++)cout << char(205); cout << char(188) << endl;
		 cin >> password;
		if (a1.signIN(username, password) != 0) {
			cout << "Welcome " << a1.getName() << " Hewal ! You can look Stock and Kitchen ." << endl;
		AdminSignInMenu:
			printAdminMenu();
			int operationAdmin;
			cin >> operationAdmin;
			switch (operationAdmin)
			{
			StockMenu:
			case 1:
				system("cls");
				printStockMenu();
				int operationStock;
				cin >> operationStock;
				switch (operationStock)
				{
				StockShow:
				case 1:
					s.show();
					cout << "Press 0 for go to back "; cin >> goBack;
					if (goBack == 0) {
						goto StockMenu;
					}
					else {
						cout << "Invalid choice " << endl;
						goto StockShow;
					}
					break;
				case 2:
					system("cls");
					getline(cin, str);
					cout << "Enter ingridient's name : "; getline(cin, ingredientName);
					cout << "Enter ingridient's count : "; cin >> ingredientCount;
					cout << "Enter ingridient's fat percent : "; cin >> ingredientFat;
					cout << "Enter ingridient's protein : "; cin >> ingredientProtein;
					cout << "Enter ingridient's carbohydrat : "; cin >> ingredientCarbohydrates;
					cout << "Enter ingridient's kkcal: "; cin >> ingredientKcal;
					cout << "Enter ingridient's price : "; cin >> ingredientPrice;
					s.addIngredient(ingredientName, ingredientCount, ingredientFat, ingredientProtein, ingredientCarbohydrates, ingredientKcal, ingredientPrice);
					cout << "Ingridients succesfully added . Do you want to see : (y/n)";
					char operationStockAdd;
					cin >> operationStockAdd;
					if (operationStockAdd == 'y') {
						s.show();
						Sleep(5000);
						goto StockMenu;
					}
					else if (operationStockAdd == 'n') {
						goto StockMenu;
					}
					else
					{
						cout << "Invalid choice !!!." << endl;
						Sleep(500);
						goto StockMenu;
					}
					break;
				case 3:
					system("cls");
					printStockDeleteMenu();
					int operationStockDelete;
					cin >> operationStockDelete;
					if (operationStockDelete == 1) {
						s.show();
						cout << "Enter ingridient's ID : "; cin >> ingredientID;
						s.deleteIngredientByID(ingredientID);
						system("cls");
						cout << "\nIngridient succesfully deleted \n" << endl;
						s.show();
						Sleep(5000);
						goto StockMenu;
					}
					else if (operationStockDelete == 2) {
						s.show();
						getline(cin, str);
						cout << "Enter ingridient's name :"; getline(cin, ingredientName);
						s.deleteIngredientByName(ingredientName);
						system("cls");
						cout << "\nIngridient succesfully deleted \n" << endl;
						s.show();
						Sleep(5000);
						goto StockMenu;
					}
					else if (operationStockDelete == 3) {
						system("cls");
						s.deleteAllIngredient();
						cout << "All  stock succesfully deleted .\nAfter deletion stock  :" << endl;
						s.show();
					}
					else if (operationStockDelete == 0) {
						goto StockMenu;
					}
					else
					{
						cout << "Please enter correct choice !" << endl;
						Sleep(1000);
						goto StockMenu;
					}
					break;
				SortedMenuForIngredient:
				case 4:
					printSortedMenuForIngredient();
					int operationStockSortedMenu;
					cin >> operationStockSortedMenu;
					switch (operationStockSortedMenu)
					{
					case 1:
						s.sortByName("Asc");
						s.show();
						cout << "Press 0 for go to back " << endl; cin >> goBack;
						if (goBack == 0) {
							goto StockMenu;
						}
						else {
							cout << "Invalid choice " << endl;
							goto SortedMenuForIngredient;
						}
						break;
					case 2:
						s.sortByName("Desc");
						s.show();
						cout << "Press 0 for go to back " << endl; cin >> goBack;
						if (goBack == 0) {
							goto StockMenu;
						}
						else {
							cout << "Invalid choice " << endl;
							goto SortedMenuForIngredient;
						}
						break;
					case 3:
						printAscOrDesc();
						cin >> operationStockSortedMenu;
						if (operationStockSortedMenu == 1) s.sortByCount("Asc");
						else if (operationStockSortedMenu == 2)	s.sortByCount("Desc");
						else cout << "Please enter correct choice !" << endl;
						s.show();
						cout << "Press 0 for go to back " << endl; cin >> goBack;
						if (goBack == 0) {
							goto StockMenu;
						}
						else {
							cout << "Invalid choice " << endl;
							goto SortedMenuForIngredient;
						}
						break;
					case 4:
						printAscOrDesc();
						cin >> operationStockSortedMenu;
						if (operationStockSortedMenu == 1) s.sortByFat("Asc");
						else if (operationStockSortedMenu == 2)	s.sortByFat("Desc");
						else cout << "Please enter correct choice !" << endl;
						s.show();
						cout << "Press 0 for go to back " << endl; cin >> goBack;
						if (goBack == 0) {
							goto StockMenu;
						}
						else {
							cout << "Invalid choice " << endl;
							goto SortedMenuForIngredient;
						}
						break;
					case 5:
						printAscOrDesc();
						cin >> operationStockSortedMenu;
						if (operationStockSortedMenu == 1) s.sortByProtein("Asc");
						else if (operationStockSortedMenu == 2)	s.sortByProtein("Desc");
						else cout << "Please enter correct choice !" << endl;
						s.show();
						cout << "Press 0 for go to back " << endl; cin >> goBack;
						if (goBack == 0) {
							goto StockMenu;
						}
						else {
							cout << "Invalid choice " << endl;
							goto SortedMenuForIngredient;
						}
						break;
					case 6:
						printAscOrDesc();
						cin >> operationStockSortedMenu;
						if (operationStockSortedMenu == 1) s.sortByCarbohydrates("Asc");
						else if (operationStockSortedMenu == 2)	s.sortByCarbohydrates("Desc");
						else cout << "Please enter correct choice !" << endl;
						s.show();
						cout << "Press 0 for go to back " << endl; cin >> goBack;
						if (goBack == 0) {
							goto StockMenu;
						}
						else {
							cout << "Invalid choice " << endl;
							goto SortedMenuForIngredient;
						}
						break;
					case 7:
						printAscOrDesc();
						cin >> operationStockSortedMenu;
						if (operationStockSortedMenu == 1) s.sortByKcal("Asc");
						else if (operationStockSortedMenu == 2)	s.sortByKcal("Desc");
						else cout << "Please enter correct choice !" << endl;
						s.show();
						cout << "Press 0 for go to back " << endl; cin >> goBack;
						if (goBack == 0) {
							goto StockMenu;
						}
						else {
							cout << "Invalid choice " << endl;
							goto SortedMenuForIngredient;
						}
						break;
					case 8:
						printAscOrDesc();
						cin >> operationStockSortedMenu;
						if (operationStockSortedMenu == 1) s.sortByPrice("Asc");
						else if (operationStockSortedMenu == 2)	s.sortByPrice("Desc");
						else cout << "Please enter correct choice !" << endl;
						s.show();
						cout << "Press 0 for go to back " << endl; cin >> goBack;
						if (goBack == 0) {
							goto StockMenu;
						}
						else {
							cout << "Invalid choice " << endl;
							goto SortedMenuForIngredient;
						}
						break;
					case 0:
						goto StockMenu;
						break;
					default:
						break;
					}
					break;
				IncreaseCountOfIngredient:
				case 5:
					system("cls");
					s.show();
					cout << "For increase count  Enter the ID of ingredient : ";
					cin >> ingredientID;
					cout << "Enter count : ";
					cin >> ingredientCount;
					s.increaseCount(ingredientID, ingredientCount);
					s.show();
					cout << "If you want increase additionally  1 \nFor back PRESS 0 " << endl;
					int operationIncreaseIngredient;
					cin >> operationIncreaseIngredient;
					if (operationIncreaseIngredient == 1)
					{
						system("cls");
						goto IncreaseCountOfIngredient;
					}
					else if (operationIncreaseIngredient == 0) {
						system("cls");
						goto StockMenu;
					}
					else {
						cout << "Enter correctly !" << endl;
						goto StockMenu;
					}
					break;
				case 0:
					system("cls");
					goto FirstMenu;
					break;
				default:
					break;
				}
				break;
			KitchenMenu:
			case 2:
				system("cls");
				printKitchenMenu();
				int operationKitchen;
				cin >> operationKitchen;
				switch (operationKitchen)
				{
				Kitchen1:
				case 1:
					//Order e baxmag
					system("cls");
					cout << "Daily order : \n"; k.showOrdersForAdmin();
					cout << endl << endl;
					s.showOrderedIngredientsForAdmin();
					r.setBudget(k.showIncome() + s.showIngredientIncome());
					cout << "\nDaily profit: $" << r.getBudget() << endl;
					cout << "Press 0 for go to back "; cin >> goBack;
					if (goBack == 0) {
						goto KitchenMenu;
					}
					else {
						cout << "Invalid choice " << endl;
						goto KitchenShow;
					}
					break;
				KitchenShow:
				case 2:
					//Yemeklere baxmaq
					k.show();
					cout << "Press 0 for go to back "; cin >> goBack;
					if (goBack == 0) {
						goto KitchenMenu;
					}
					else {
						cout << "Invalid choice " << endl;
						goto KitchenShow;
					}
					break;
				Kitchen4:
				case 3:
					//Yemek elave etmek
					system("cls");
					getline(cin, str);
					cout << "Enter Meal's name : "; getline(cin, mealName);
					cout << "Enter Meal's catagory : "; getline(cin, mealCategory);
					cout << "Enter Meal's rating : "; cin >> mealRating;
					cout << "Enter Meal's price : "; cin >> mealPrice;
					cout << "Enter Meal's tax : "; cin >> mealTax;
					k.addMeal(mealName, mealCategory, mealRating, mealPrice, mealTax);
					cout << "Meal succesfully added . Do you want to see : (y/n)";
					char operationMealAdd;
					cin >> operationMealAdd;
					if (operationMealAdd == 'y') {
						k.show();
						Sleep(5000);
						goto KitchenMenu;
					}
					else if (operationMealAdd == 'n') {
						goto KitchenMenu;
					}
					else
					{
						cout << "Invalid choice !!!." << endl;
						Sleep(500);
						goto KitchenMenu;
					}
					break;
				Kitchen5:
				case 4:
					//Yemek silmek
					system("cls");
					printKitchenDeleteMenu();
					int operationKitchenDelete;
					cin >> operationKitchenDelete;
					k.show();
					if (operationKitchenDelete == 1) {
						cout << "Enter meals ID: "; cin >> mealID;
						k.deleteMealByID(mealID);
						system("cls");
						cout << "\nMeal succesfully deleted\n" << endl;
						k.show();
						cout << "Press 0 for go to back "; cin >> goBack;
						if (goBack == 0) {
							goto KitchenMenu;
						}
						else {
							cout << "Invalid choice " << endl;
							goto KitchenMenu;
						}
					}
					else if (operationKitchenDelete == 2) {
						cout << "Enter Meal's name :"; cin >> mealName;
						k.deleteMealByName(mealName);
						system("cls");
						cout << "\nMeal succesfully deleted\n" << endl;
						k.show();
						cout << "Press 0 for go to back "; cin >> goBack;
						if (goBack == 0) {
							goto KitchenMenu;
						}
						else {
							cout << "Invalid choice " << endl;
							goto KitchenMenu;
						}
					}
					else if (operationKitchenDelete == 3) {
						system("cls");
						k.deleteAllMeals();
						cout << "All meals succesfully deleted .\nAfter deletion of kitchen :" << endl;
						k.show();
						cout << "Press 0 for go to back "; cin >> goBack;
						if (goBack == 0) {
							goto KitchenMenu;
						}
						else {
							cout << "Invalid choice " << endl;
							goto KitchenMenu;
						}
					}
					else if (operationKitchenDelete == 0) {
						goto KitchenMenu;
					}
					else
					{
						cout << "Please enter correct choice !" << endl;
						Sleep(1000);
						goto KitchenMenu;
					}
					break;
				Kitchen6:
				case 5:
					//Yemeklere For correction 
					k.show();
					cout << "For correction  Enter the ID of meal :  "; cin >> mealID;
					getline(cin, str);
					cout << "For correction   Enter Meal's name : "; getline(cin, mealName);
					cout << "For correction   Enter Meal's catagory : "; getline(cin, mealCategory);
					cout << "For correction   Enter Meal's rating : "; cin >> mealRating;
					cout << "For correction   Enter Meal's price : "; cin >> mealPrice;
					cout << "For correction   Enter Meal's tax : "; cin >> mealTax;
					k.updateMeal(mealID, mealName, mealCategory, mealRating, mealPrice, mealTax);
					k.show();
					cout << "Press 0 for go to back "; cin >> goBack;
					if (goBack == 0) {
						goto KitchenMenu;
					}
					else {
						cout << "Invalid choice " << endl;
						goto KitchenMenu;
					}
					break;
				Kitchen7:
				case 6:
					//Stocka baxmaq
					s.show();
					cout << "Press 0 for go to back "; cin >> goBack;
					if (goBack == 0) {
						system("cls");
						goto AdminSignInMenu;
					}
					else {
						cout << "Invalid choice " << endl;
						goto KitchenShow;
					}
					break;
				SortedMenuForMeal:
				case 7:
					//Yemeklerin sortlashdirilmis siyahisi
					system("cls");
					printSortedMenuForMeal();
					int operationStockMealMenu;
					cin >> operationStockMealMenu;
					switch (operationStockMealMenu)
					{
					case 1:
						k.sortByName("Asc");
						k.show();
						cout << "Press 0 for go to back "; cin >> goBack;
						if (goBack == 0) {
							goto SortedMenuForMeal;
						}
						else {
							cout << "Invalid choice " << endl;
							goto SortedMenuForMeal;
						}
						break;
					case 2:
						k.sortByName("Desc");
						k.show();
						cout << "Press 0 for go to back "; cin >> goBack;
						if (goBack == 0) {
							goto SortedMenuForMeal;
						}
						else {
							cout << "Invalid choice " << endl;
							goto SortedMenuForMeal;
						}
						break;
					case 3:
						printAscOrDesc();
						cin >> operationStockMealMenu;
						if (operationStockMealMenu == 1) k.sortByRating("Asc");
						else if (operationStockMealMenu == 2)	k.sortByRating("Desc");
						else cout << "Please enter correct choice !" << endl;
						k.show();
						cout << "Press 0 for go to back "; cin >> goBack;
						if (goBack == 0) {
							goto SortedMenuForMeal;
						}
						else {
							cout << "Invalid choice " << endl;
							goto SortedMenuForMeal;
						}
						break;
					case 4:
						printAscOrDesc();
						cin >> operationStockMealMenu;
						if (operationStockMealMenu == 1) k.sortByPrice("Asc");
						else if (operationStockMealMenu == 2)	k.sortByPrice("Desc");
						else cout << "Please enter correct choice !" << endl;
						k.show();
						cout << "Press 0 for go to back "; cin >> goBack;
						if (goBack == 0) {
							goto SortedMenuForMeal;
						}
						else {
							cout << "Invalid choice " << endl;
							goto SortedMenuForMeal;
						}
						break;
					case 0:
						goto KitchenMenu;
						break;
					default:
						break;
					}
					break;
				case 8:
					cout << "==================Nottifications==================" << endl;
					cout << "Table number : " << c.getTableNo() << endl;
					cout << "Order : " << endl;
					k.nottForOrdersMeal();
					s.nottForOrdersIngredient();
					cout << "Press 0 for go to back "; cin >> goBack;
					if (goBack == 0) {
						system("cls");
						goto AdminSignInMenu;
					}
					else {
						cout << "Invalid choice " << endl;
						goto KitchenShow;
					}
					break;
				case 0:
					//Geri donmek
					system("cls");
					goto FirstMenu;
					break;
				default:
					break;
				}
				break;
			case 3:


			case 0:
				system("cls");
				goto FirstMenu;
				break;
			default:
				cout << "Invalid choice !" << endl;
				Sleep(1000);
				system("cls");
				goto AdminSignInMenu;
				break;
			}
		}
		else
		{
			count++;
			if (count < 3)
			{
				cout << 3 - count << " Chance left ." << endl;
				Sleep(1000);
				goto AdminMenu;
			}
			else {
				system("cls");
				goto FirstMenu;
			}
		}
		break;
	default:
		cout << "Invalid choice !" << endl;
		Sleep(1500);
		system("cls");
		goto FirstMenu;
		break;
	}


}
