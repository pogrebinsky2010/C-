#include <iostream>

//Talaba Pogrebinsky lab4prob1b

using namespace std;

int main()
{
    const int BASE_RATE = 100;
    int newRate, age;

    string gender;
    cout << "Please enter age: " << endl;
    cin >> age;
    cout << "Please enter gender (m or f): " << endl;
    cin >> gender;

    if(gender == "f" && age > 25 )
        newRate = BASE_RATE;
    else if (gender == "f" && age <= 25)
        newRate = (BASE_RATE * .05) + BASE_RATE;
    else if (gender == "m" && age > 25)
         newRate = (BASE_RATE * .07) + BASE_RATE;
    else if ( gender == "m" && age <= 25)
        newRate = (BASE_RATE * .10) + BASE_RATE;
    else
        cout << "Please enter in the correct format" << endl;
    cout << " your insurance rate is: " << newRate;



    return 0;
}
