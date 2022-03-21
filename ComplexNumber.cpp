#include <iostream>
#include <iomanip>
using namespace std;

#pragma once

class ComplexNumber
{
private:
  int realPart;
  int imaginaryPart;
  int imaginaryPower;
public:
  ComplexNumber(int, int, int);
  int getRealPart();
  int getImaginaryPart();
  int getImaginaryPower();
  ComplexNumber getConjugation();
  void setRealPart(int);
  void setImaginaryPart(int);
  void setImaginaryPower(int);
  void simplify();
  friend istream& operator>>(istream&, ComplexNumber&);
  friend ostream& operator<<(ostream&, ComplexNumber);
  friend ComplexNumber operator+(const ComplexNumber, const ComplexNumber);
  friend ComplexNumber operator-(const ComplexNumber, const ComplexNumber);
  friend ComplexNumber operator*(const ComplexNumber, const ComplexNumber);
  // friend ComplexNumber operator/(const ComplexNumber, const ComplexNumber);
};

ComplexNumber::ComplexNumber(int realPart = 0, int imaginaryPart = 0, int imaginaryPower = 1)
{
  this->realPart = realPart;
  this->imaginaryPart = imaginaryPart;
  this->imaginaryPower = imaginaryPower;
  this->simplify();
}

int ComplexNumber::getRealPart() 
{
  return this->realPart;
}

int ComplexNumber::getImaginaryPart()
{
  return this->imaginaryPart;
}

int ComplexNumber::getImaginaryPower()
{
  return this->imaginaryPower;
}

ComplexNumber ComplexNumber::getConjugation()
{
  return ComplexNumber(this->realPart, -this->imaginaryPart, this->imaginaryPower);
}

void ComplexNumber::setRealPart(int realPart)
{
  this->realPart = realPart;
}

void ComplexNumber::setImaginaryPart(int imaginaryPart)
{
  this->imaginaryPart = imaginaryPart;
}

void ComplexNumber::setImaginaryPower(int imaginaryPower)
{
  this->imaginaryPower = imaginaryPower;
}

void ComplexNumber::simplify()
{
  if(this->imaginaryPower == 1) return;
  
  if(this->imaginaryPower == 0) 
  {
    this->realPart += this->imaginaryPart;
    this->imaginaryPart = 0;
    return;
  }
  
  if(this->imaginaryPower == 2)
  {
    this->realPart -= this->imaginaryPart;
    this->imaginaryPart = 0;
    return;
  }
  
  if(this->imaginaryPower % 2 == 0)
    this->imaginaryPower = (this->imaginaryPower / 2) % 2 == 0 ? 0 : 2;
  else {
    this->imaginaryPart = (this->imaginaryPower / 2) % 2 == 0 ?  this->imaginaryPart : -this->imaginaryPart;
    this->imaginaryPower = 1;
  }
  simplify();
}

istream& operator>>(istream& is, ComplexNumber& number)
{
  cout << "Enter real part: ";
  is >> number.realPart;
  cout << "Enter imaginary part: ";
  is >> number.imaginaryPart;
  cout << "Enter imaginary power: ";
  is >> number.imaginaryPower;
  number.simplify();
  return is;
}

ostream& operator<<(ostream& os, ComplexNumber number)
{
  os << noshowpos << number.realPart;
  if(number.imaginaryPart != 0)
    os << showpos << number.imaginaryPart << "i";
  return os;
}

ComplexNumber operator+(const ComplexNumber a, const ComplexNumber b)
{
  return ComplexNumber(a.realPart + b.realPart, a.imaginaryPart + b.imaginaryPart);
}

ComplexNumber operator-(const ComplexNumber a, const ComplexNumber b)
{
  return ComplexNumber(a.realPart - b.realPart, a.imaginaryPart - b.imaginaryPart);
}

ComplexNumber operator*(const ComplexNumber a, const ComplexNumber b)
{
  int newRealPart = a.realPart * b.realPart - a.imaginaryPart * b.imaginaryPart;
  int newImaginaryPart = a.realPart * b.imaginaryPart + b.realPart * a.imaginaryPart;
  return ComplexNumber(newRealPart, newImaginaryPart);
}

// ComplexNumber operator/(const ComplexNumber a, const ComplexNumber b)
// {
//   ComplexNumber 
// }