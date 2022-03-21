#include <iostream>
#include "ComplexNumber.cpp"
using namespace std;

int main() 
{
  ComplexNumber a(2, -6, 21);
  cout << "(" << a << ")" << " * (" << a.getConjugation() << ") = " << a * a.getConjugation() << endl;
  return 0;
}