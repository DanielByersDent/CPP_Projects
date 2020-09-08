// banking_app.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "calculator.cpp"

using namespace std;

int main()
{

	double mDeposit = 0.0; // monthly despot
	double mInvestmentAmount = 0.0; // monthly investment amount
	double aInterest = 0.0; // annual interests 
	double nYears = 0.0; // number of years 
	int showValues = 5; // shows currrent values that user entered
	int showBalance = 7; // show current balance
	int exit = 9; // exits program

	calculator newCal = calculator{};
	do {
		cout << "********************************" << endl;
		cout << "***********Data Input **********" << endl;
		//-----------------------------------------------------------------------------
		// -------------------------------------"Initial Investment ----------------------
		cout << "Initial Investment: " << endl;
		cin >> mInvestmentAmount;
		// ---------------------------Data Validation for Initital Investment-------------
		for (int i = 0; i < 100 && cin.fail(); i++)
		{
			cout << "ERROR: \"initial investment\" must be a number." << endl << endl;
			cin.clear(); // clear isostream
			cin.ignore(); //ingores previous  input 
			cout << "Initial Investment: " << endl;
			cin >> mInvestmentAmount;
		}

		//-----------------------------------------------------------------------------
		// ------------------------------------- Monthly Desposit----------------------
		cout << "Monthly Desposit: " << endl;
		cin >> mDeposit;
		// ---------------------------Data Validation for Monthly Desposit-------------
		for (int i = 0; i < 100 && cin.fail(); i++)
		{
			cout << "ERROR: \"monthly desposit\" must be a number." << endl << endl;
			cin.clear(); // clear isostream
			cin.ignore(); //ingores previous input 
			cout << "Monthly Desposit: " << endl;
			cin >> mDeposit;
		}
		//-----------------------------------------------------------------------------
		// ------------------------------------- Annual Interest----------------------
		cout << "Annual Interest: " << endl;
		cin >> aInterest;
		// ---------------------------Data Validation for Annual Interest-------------
		for (int i = 0; i < 100 && cin.fail(); i++)
		{
			cout << "ERROR: \"annual interest\" must be a number." << endl << endl;
			cin.clear(); // clear isostream
			cin.ignore(); //ingores previous  input 
			cout << "Annual Interest: " << endl;
			cin >> aInterest;
		}
		//------------------------------------------------------------------
		//-----------------------------Number of Years---------------------
		cout << "Number of years: " << endl;
		cin >> nYears;

		//-----------------------------User Input validation Number of Years----------------
		for (int i = 0; i < 100 && cin.fail(); i++)
		{
			cout << "ERROR: \"number of years\" must be a number." << endl << endl;
			cin.clear(); // clear isostream
			cin.ignore(); //ingores previous  input 
			cout << "Number of years: " << endl;
			cin >> nYears;
		}
		//----------------------------Gathering the values that were input-------------

		cout << "To show current values press 0" << endl;
		cin >> showValues; // create a if statements for showValues
		if (showValues == 0) {
			newCal.showValues(mInvestmentAmount, mDeposit, aInterest, nYears);
		}
		//---------------------------gettting there current balance
		cout << "To show current balance press 1" << endl;
		cin >> showBalance; // create if statements for showValues
		if (showBalance == 1) {
			newCal.compoundCal(mDeposit, mInvestmentAmount, aInterest, nYears); // gettig the compoundCal method from calculator 
		}
		newCal.growthCal(mDeposit, mInvestmentAmount, aInterest, nYears); // gettig the growthCal method from calculator 

		cout << "Press 2 to exit or press any other key to continue" << endl;
		cin >> exit;
	} while (!(exit == 2)); // exiting while loop
}