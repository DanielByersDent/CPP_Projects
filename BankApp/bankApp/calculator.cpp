#include <iostream>
//#include <math.h>


using namespace std;

class calculator {
	

public: calculator() { // Constructor
	

}

public: void compoundCal(double deposit, double invest, double interest, double years) {

	double balance = 0.0;
	double interestedEarn = 0.0;


	interestedEarn = (invest + deposit) * ((interest / 100) / 12);
	balance = invest + deposit + interestedEarn;
	cout << "Your current balance is " << balance << endl;



}
public: void growthCal(double deposit, double invest, double interest, double years) {
	double balance = 0.0;
	double interestedEarn = 0.0;
	double totalInter = 0.0;


	cout << endl;
	cout << endl;
	cout << endl;
	if (deposit == 0) {//-----------Shows the balance with without ddditional any monthly deposits and its growth with compound interest

		cout << "------- Balance Without Additional Monthly Deposit-----------" << endl;
		cout << "-------------------------------------------------------------" << endl;
		cout << " Year          Year End Balance      Year End Earned Interest" << endl;
		cout << "-------------------------------------------------------------" << endl;
		for (int i = 1; i <= (12 * years); i++) {
			if (i == 1) {
				interestedEarn = (invest + deposit) * ((interest / 100) / 12);
				balance = invest + deposit + interestedEarn;
				totalInter = interestedEarn; // end of year earned interest
			}

			else {
				interestedEarn = (balance + deposit) * ((interest / 100) / 12);// interest earned at end of year with compound interest
				balance = balance + deposit + interestedEarn;  // total balance at the end of the year
				totalInter = totalInter + interestedEarn;// end of year earned interest
				if (i % 12 == 0) {
					cout << i / 12 << "                      " << balance << "                 " << totalInter << endl; // print out of balance for menu
				}
			}
		}
		cout << endl;
		cout << endl;

	}
	else { //-----------Shows the balance with additional monthly deposits and its growth with compound interest

		cout << "------- Balance With Additional Monthly Deposit-----------" << endl;
		cout << "-------------------------------------------------------------" << endl;
		cout << " Year          Year End Balance      Year End Earned Interest" << endl;
		cout << "-------------------------------------------------------------" << endl;
		for (int i = 1; i <= (12 * years); i++) {
			if (i == 1) {
				interestedEarn = (invest + deposit) * ((interest / 100) / 12); // interest earned at end of year with compound interest 
				balance = invest + deposit + interestedEarn; // total balance at the end of the year
				totalInter = interestedEarn; 
			}

			else {
				interestedEarn = (balance + deposit) * ((interest / 100) / 12);
				balance = balance + deposit + interestedEarn;
				totalInter = totalInter + interestedEarn;
				if (i % 12 == 0) {
					cout << i / 12 << "                      " << balance << "                 " << totalInter << endl; // print out of balance for menu
				}
			}
		}
		cout << endl;
		cout << endl;

	}
}

public:  void showValues(double mInvestmentAmount, double mDeposit, double aInterest, double nYears) { // shows the current values
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "********************************" << endl;
	cout << "***********Data Input **********" << endl;
	cout << "Initial Investment: " << mInvestmentAmount << endl;
	cout << "Monthly Desposit: " << mDeposit << endl;
	cout << "Annual Interest: " << aInterest << endl;
	cout << "Number of years: " << nYears << endl;
	cout << endl;
	cout << endl;
	cout << endl;
}

};