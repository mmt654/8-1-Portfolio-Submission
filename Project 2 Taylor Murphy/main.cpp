#include <iostream>
#include "savings.h"

using namespace std;
int main() {
    while (1) {
        cout << "*************************************" << endl; //Print heading
        cout << "*************Data Input**************" << endl;
        cout << "Initial Investment Amount: " << endl;
        cout << "Monthly Deposit: " << endl;
        cout << "Annual Interest: " << endl;
        cout << "Number of years: " << endl;

        //system("PAUSE");

        system("read -p 'Press Enter to continue . . .' var");
        cout << endl;

        //Get the inputs from user

        cout << "*************************************" << endl;
        cout << "*************Data Input**************" << endl;
        cout << "Initial Investment Amount: $";

        double investment, monthlyDeposit, interestRate;
        int years;

        cin >> investment;
        cout << "Monthly Deposit: $";
        cin >> monthlyDeposit;
        cout << "Annual Interest: %";
        cin >> interestRate;
        cout << "Number of years: ";
        cin >> years;

        system("read -p 'Press Enter to continue . . .' var");

        Savings mySavings = Savings(investment, monthlyDeposit, interestRate, years);
        cout << endl;

        mySavings.reportNoMonthlyDeposits();
        cout << endl;

        if (monthlyDeposit > 0) {
            mySavings.reportWithMonthlyDeposits(); //call monthly deposit report
        }

        cout << endl << "Do you want to try another? (y/n): "; //Get the user choice
        string choice;
        cin >> choice;

        if (choice != "y") {
            break;
        }

        cout << endl;
    }
    return 0;
}