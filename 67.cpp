// This program uses a loop to raise a number to a power.

#include <iostream>
#include <math.h>
using namespace std;

int main() {
  int num, bigNum, power, count;

  cout << "Enter an integer: ";
  cin >> num;
  cout << "What power do you want it raised to ? ";
  cin >> power;
  bigNum = pow(num, power);
  while (count++ < power){
    bigNum *= num;
  }
  cout << "The result is " << bigNum << endl;

return 0;
}
