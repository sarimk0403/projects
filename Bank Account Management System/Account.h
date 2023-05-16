#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <fstream>
#include <iostream>
using namespace std;

class Account
{
    
    public:
    
    
    Account();
    Account(const string NameIn, const int YearIn, const int PinIn, const float AmountIn);
    Account(const Account & copy);
    ~Account();
    
    
    //Getters
    string getName() const;
    int getYear() const;
    int getPin() const;
    float getAmount() const;

    
    //Setters
    void setName(const string NameIn);
    void setYear(const int YearIn);
    void setPin(const int PinIn);
    void setAmount(const float AmountIn);
    
    //Utility methods
    
    void print() const;
    
    private:
    
    string Name;
    int Year;
    int Pin;
    float Amount;
   
};

#endif
