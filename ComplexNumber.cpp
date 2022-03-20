#include <iostream>
#include <iomanip>
using namespace std;

#pragma once

class ComplexNumber
{
private:
  int realPart;
  int imaginaryPart;
public:
  ComplexNumber(int, int);
  int getRealPart();
  int getImaginaryPart();
  void setRealPart(int);
  void setImaginaryPart(int);
  friend istream& operator>>(istream&, ComplexNumber&);
  friend ostream& operator<<(ostream&, ComplexNumber);
};

ComplexNumber::ComplexNumber(int realPart = 0, int imaginaryPart = 0)
{
  this->realPart = realPart;
  this->imaginaryPart = imaginaryPart;
}

int ComplexNumber::getRealPart() 
{
  return this->realPart;
}

int ComplexNumber::getImaginaryPart()
{
  return this->imaginaryPart;
}

void ComplexNumber::setRealPart(int realPart)
{
  this->realPart = realPart;
}

void ComplexNumber::setImaginaryPart(int imaginaryPart)
{
  this->imaginaryPart = imaginaryPart;
}

istream& operator>>(istream& is, ComplexNumber& number)
{
  cout << "Enter real part: ";
  is >> number.realPart;
  cout << "Enter imaginary part: ";
  is >> number.imaginaryPart;
  return is;
}

ostream& operator<<(ostream& os, ComplexNumber number)
{
  os << noshowpos << number.realPart << showpos << number.imaginaryPart << "i";
  return os;
}