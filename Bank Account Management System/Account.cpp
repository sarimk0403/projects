#include "Account.h"
using namespace std;

//Constructors

Account::Account(){
    
    Name = "e";
    Year = 0;
    Pin = 0;
    Amount = 0;
    
}

Account::Account(const string NameIn, const int YearIn, const int PinIn, const float AmountIn){
    Name = NameIn;
    Year = YearIn;
    Pin = PinIn;
    Amount = AmountIn;
}

Account::Account(const Account & copy) {
    Name = copy.Name;
    Year = copy.Year;
    Pin = copy.Pin;
    Amount = copy.Amount;
    
}

Account::~Account(){
    
}

// Utility methods
void Account::print() const{
    cout << Name << "," << Year << "," << Pin << "," << Amount << endl;
    
}

//Getters
string Account::getName() const{
    return Name;
}

int Account::getYear() const{
    return Year;
}

int Account::getPin() const{
    return Pin;
}

float Account::getAmount() const{
    return Amount;
}

// Setters
void Account::setName(const string NameIn){
    Name = NameIn;
}
void Account::setYear(const int YearIn){
    Year = YearIn;

}
void Account::setPin(const int PinIn){
    Pin = PinIn;

}
void Account::setAmount(const float AmountIn){
    Amount = AmountIn;

}


