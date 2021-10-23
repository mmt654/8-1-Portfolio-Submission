#include <iomanip>
#include <iostream>
#include "savings.h"

using namespace std;

Savings::Savings(double investment, double monthDeposit, double rate, int years) { //Constructor

    this->initDeposit = investment;
    this->monthlyDeposit = monthDeposit;
    this->interestRate = rate;
    this->numYears = years;
}


Savings::~Savings() { //Destructor
}


void Savings::reportNoMonthlyDeposits() { //Prints report with no monthly deposit

    cout << "   Balance and Interest without additional Monthly Deposits" << endl; //Print heading
    cout << "==========================================================================" << endl;

    cout << setw(10) << "Year" << setw(20) << "Year End Balance" << setw(35) << "Year End Earned Interest Rate" << endl; //Print table heading
    cout << "--------------------------------------------------------------------------" << endl;


    int currentYear = 1; //Repeated for years and calculates interest
    double yearEndBal = this->initDeposit;
    while (currentYear <= this->numYears) {
        double interestEarned = yearEndBal * this->interestRate / 100; //Calculate interest

        yearEndBal = yearEndBal + interestEarned;

        cout << right << setw(10) << currentYear << fixed << setprecision(2)  //Print the results for each year
            << setw(20) << yearEndBal
            << setw(35) << interestEarned << endl;

        currentYear++; // Increments year
    }
}

void Savings::reportWithMonthlyDeposits() { //Prints report with monthly deposit

    cout << "   Balance and Interest without additional Monthly Deposits" << endl; //Print heading
    cout << "==========================================================================" << endl;


    cout << setw(10) << "Year" << setw(20) << "Year End Balance" << setw(35) << "Year End Earned Interest Rate" << endl; //Print table heading
    cout << "--------------------------------------------------------------------------" << endl;


    int currentYear = 1; //Iterate for given years and calculate interest earned
    double yearEndBal = this->initDeposit;
    while (currentYear <= this->numYears) {
        int month = 1; //calulate interest monthly and find compoud interest
        double interestEarned = 0.0;
        double monthEndBal = yearEndBal;
        while (month <= 12) {
            monthEndBal = monthEndBal + this->monthlyDeposit; //Add monthly deposit

            double monthlyInterest = monthEndBal * this->interestRate / (100 * 12); //Calculate monthly interest, interest rate is for annual. so divide the rate by 12

            interestEarned = interestEarned + monthlyInterest; //Add the monthly interest to yearly interest earned
            monthEndBal = monthEndBal + monthlyInterest; // add the interest to monthend balance
            month++; //Increments Month
        }
        yearEndBal = monthEndBal; //After 12 months
        cout << right << setw(10) << currentYear << fixed << setprecision(2) << setw(20) << yearEndBal << setw(35) << interestEarned << endl; //Print the results

        currentYear++; // Increments year
    }
}