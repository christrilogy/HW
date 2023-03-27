#include <iostream>
#include <termios.h>
#include <stdio.h>
#include <math.h>
#include <iomanip>
using namespace std;




static struct termios old, current;

/* Initialize new terminal i/o settings */
void initTermios(int echo) 
{
  tcgetattr(0, &old); /* grab old terminal i/o settings */
  current = old; /* make new settings same as old settings */
  current.c_lflag &= ~ICANON; /* disable buffered i/o */
  if (echo) {
      current.c_lflag |= ECHO; /* set echo mode */
  } else {
      current.c_lflag &= ~ECHO; /* set no echo mode */
  }
  tcsetattr(0, TCSANOW, &current); /* use these new terminal i/o settings now */
}

/* Restore old terminal i/o settings */
void resetTermios(void) 
{
  tcsetattr(0, TCSANOW, &old);
}

/* Read 1 character - echo defines echo mode */
char getch_(int echo) 
{
  char ch;
  initTermios(echo);
  ch = getchar();
  resetTermios();
  return ch;
}

/* Read 1 character without echo */
char getch(void) 
{
  return getch_(0);
}

/* Read 1 character with echo */
char getche(void) 
{
  return getch_(1);
}


int main()
{
    int days = 0;
    // double pennies = 0.01; Not needed.
    double total = 0.0;
    // If you don't initialise variables it will cause a crash or undefined behaviour.
    // double fixed;
    // double showpoint;

    while (days < 1)    // This prevents negative or 0 day contracts.
    {
        // You need to use the full name to cout or that abomination of a command using namespace std
        cout << "For how many days will the pay double?";
        cin >> days;
    }
    cout << endl << "Day    Total Pay\n";
    cout << "------------------------\n";

    // looping from 0 while less than days is more "normal".
    for (int count = 0; count < days;  count++)
    {
        double payForTheDay = (pow(2, count));
        cout << count << "\t\t$\t" << payForTheDay << endl;
        total += payForTheDay;  // You need to increment the total.
    }
    // Not sure what this is about
    // std::cout << std::setprecision(2) << fixed << showpoint;
    cout << "--------------------------------\n";
    cout << "Total  $\t" << total << endl;

  
    getch();
    return 0;
}
