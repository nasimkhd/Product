/*
	==================================================
	Workshop #6 (Part-1):
	==================================================
	Name   : Nasim Khodapanah
	ID     : 131929200
	Email  : nkhodapanah@myseneca.ca
	Section: NGG 
*/

#define _CRT_SECURE_NO_WARNINGS

// System Libraries
#include <stdio.h>

// User Libraries
#include "w6p1.h"

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)

int getIntPositive(int *number) {
	int num = 0;
	while (num < 1) {
		scanf("%d", &num);
		if (num < 1)
			printf("ERROR: Enter a positive value: ");
	}
	if (number != NULL)
		*number = num;
	return num;
}


// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)

double getDoublePositive(double *number) {
	double num = 0;
	while (num < 1) {
		scanf("%lf", &num);
		if (num < 1)
			printf("ERROR: Enter a positive value: ");
	}
	if (number != 0)
		*number = num;
	return num;
}


// 3. Opening Message (include the number of products that need entering)

void openingMessage(const int num_of_products) {
	//printf("========================== =");
	//printf("Starting Main Program Logic");
	//printf("========================== =");
	printf("Cat Food Cost Analysis\n");
	printf("======================\n\n");
	printf("Enter the details for %d dry food bags of product data for analysis.\n", num_of_products);
	printf("NOTE: A 'serving' is 64g\n");
	return;
}

// 4. Get user input for the details of cat food product

CatFoodInfo getCatFoodInfo(int sku) {
	CatFoodInfo food;
	food.sku = sku;

	double price = 0.0;
	printf("PRICE         : $"); 
	while (price <= 0)
		price = getDoublePositive(NULL);
	food.price = price;

	printf("WEIGHT (LBS)  : ");
	double weight = 0.0;
	while (weight <= 0.0)
		weight = getDoublePositive(NULL);
	food.product_weight_pounds = weight;

	printf("CALORIES/SERV.: ");
	int calories = 0;
	while (calories <= 0)
		calories = getIntPositive(NULL);
	food.cal_per_serving = calories;
	return food;
}
// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("\nSKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(int sku, double *price, double* product_weight_pounds,
	                    int cal_per_serving ) {
	printf("%07d %10.2lf %10.1lf %8d\n", sku, *price, *product_weight_pounds,
		cal_per_serving);
}

// 7. Logic entry point

void start() {
	setbuf(stdout, NULL);
	CatFoodInfo food[MAX_NUM_PRODUCTS];
	openingMessage(MAX_NUM_PRODUCTS);
	int i, sku;
	for (i = 0; i < MAX_NUM_PRODUCTS; i++) {
		printf("\nCat Food Product #%d", i + 1);
		printf("\n--------------------\n");
		printf("SKU           : ");
		sku = 0;
		while (sku <= 0)
			sku = getIntPositive(NULL); 
		food[i] = getCatFoodInfo(sku);
	}
	displayCatFoodHeader();
	for (i = 0; i < MAX_NUM_PRODUCTS; i++) 
		displayCatFoodData(food[i].sku, &food[i].price, &food[i].product_weight_pounds, 
			food[i].cal_per_serving);
	printf("test is over - goodbye\n");
	return;
	
}
