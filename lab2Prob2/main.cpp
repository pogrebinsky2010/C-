//Talaba Pogrebinsky lab2 prob16

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>
#include <ctime>

using namespace std;

int main()
{
    int firstNum, secondNum, total, firstDispNum, secondDispNum, inputNum;
    string display;

    unsigned seed;


    seed = time(NULL);
    srand(seed);


    firstNum = rand() % 11 + 1;
    secondNum = rand() % 11 + 1;


// Getting the bigger number on top
    if (firstNum > secondNum)
    {
        firstDispNum = firstNum;
    }

    else
    {
        firstDispNum = secondNum;
    }


   /* if (secondNum > firstNum)
    {
        secondDispNum = firstNum;
    }

    else
    {
        secondDispNum = secondNum;
    } */
//Displaying
    total = firstNum + secondNum;
    cout << " " << firstDispNum << "\n"<< "+" << secondDispNum << "\n" << " = ";
    cin >> inputNum;

    if (inputNum == total)
        display = "Congratulations! That is correct";
    else display = "Sorry that is not correct please try again...";

        cout << "\n\n" << display;
        cout << "\n\n";

}
