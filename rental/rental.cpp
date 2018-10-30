#include <iostream>
#include <string>
using namespace std;

int odomStart = -1;
int odomEnd = 9999999;
int totalMiles = -1;
int rentalDays = 0;
string name = "";
string luxury = "z";
int monNum = -1;
//get rid of this later
double price = 0;

void calculatePrice() {
	//price from luxury or not
	if (luxury.compare("n") == 0) {
		price = 33 * rentalDays;
	}
	else if (luxury.compare("y") == 0) {
		price = 61 * rentalDays;
	}
	//price dependant on miles
	//for if it's under 100 miles
	if (totalMiles <= 100) {
		price += totalMiles * .27;
	}
	//if the miles is over 100 and equal to or less than 400 
	else if (totalMiles <= 400) {
		//tests for if it's in the winter months
		if (monNum == 12 || monNum == 1 || monNum == 2 || monNum == 3) {
			//winter
			price += 100 * .27 + (totalMiles - 100)*.27;
		}
		else {
			//other seasons
			price += 100 * .27 + (totalMiles - 100)*.21;
		}
	}
	else {
		price += 100 * .27;
		//tests for winter months again 
		if (monNum == 12 || monNum == 1 || monNum == 2 || monNum == 3) {
			price += 300 * .27;
		}
		else {
			//other seasons 
			price += 300 * .21;
		}
		//the rest that's over 400 miles 
		price += (totalMiles - 400)*.19;
	}
}

int main() {
	//takes all the inputs
	cout << "Odometer at start: ";
	cin >> odomStart;

	cout << "Odometer at end: ";
	cin >> odomEnd;

	cout << "Rental days: ";
	cin >> rentalDays;

	cout << "Customer name: ";
	cin.ignore();
	getline(cin, name);

	cout << "Luxury car ? (y / n) : ";
	getline(cin, luxury);

	cout << "Month (1=Jan, 2=Feb, etc.): ";
	cin >> monNum;

	//sets the precision of outputs to 2 decimal places
	cout.setf(ios::fixed);
	cout.precision(2);

	//calculates the total amount of miles using math
	totalMiles = odomEnd - odomStart;
	//calculates the total price using the function calculatePrice() created earlier
	calculatePrice();
	cout << "---" << endl;
	//error messages and price output 
	if (odomStart < 0) {
		cout << "The starting odometer reading must be nonnegative.";
	}
	else if (odomEnd < odomStart) {
		cout << "The final odometer reading must be at least as large as the starting reading.";
	}
    else if (rentalDays <= 0) {
		cout << "The number of rental days must be positive.";
	}
	else if (name.compare("") == 0) {
		cout << "You must enter a customer name.";
	}
	else if (!(luxury.compare("y") == 0 || luxury.compare("n") == 0)) {
		cout << "You must enter y or n.";
	}
	else if (monNum < 1 || monNum>12) {
		cout << "The month number must be in the range 1 through 12.";
	}
	else {
		cout << "The rental charge for " << name << " is $" << price << endl;
	}
}
