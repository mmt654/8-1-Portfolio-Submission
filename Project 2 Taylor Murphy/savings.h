#ifndef SAVINGS_H_
#define SAVINGS_H_

class Savings {
public:
    Savings(double investment, double monthDeposit, double rate, int years);
    virtual ~Savings();
    void reportNoMonthlyDeposits();
    void reportWithMonthlyDeposits();

private:
    double initDeposit;
    double monthlyDeposit;
    double interestRate;
    int numYears;
};

#endif