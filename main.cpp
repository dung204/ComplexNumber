#include <iostream>
#include "ComplexNumber.cpp"
using namespace std;

int main() 
{
  ComplexNumber a(2, -6, 21);
  ComplexNumber b(-55, 7, 14);
  cout << "(" << a << ") / (" << b << ") = " << a / b << endl;
  return 0;
}
