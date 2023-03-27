// This program uses a loop to raise a number to a power.

#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
  int speed, time, distance, 
  hour = 1;
cout << "What is the speed of the vehicle in mph? " << endl;
  cin >> speed;
cout << "How many hours has it traveled? " <<endl;
  cin >> time;
cout << "Hour distance traveled" << endl;
    cout << "----------------------------------------------" << endl;

  
 while (hour < 4){
      distance = speed * time;
   cout << hour << setw(8) << distance << endl;
    hour++;
   
 }
   
    

return 0;
}
