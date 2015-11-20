// Talaba Pogrebinsky lab 5a//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

int main()
{
   unsigned seed;
   int number, guess, count,second_count;

   count = 0;
   second_count = 1;
   seed = time(0);
   srand(seed);
   number = rand() % 100 + 1;
   cout << "Guess a number between 1 and 100: ";
   cin>> guess;
   count = 0;

   if(guess <= 0 || guess > 100)
   {
       cout<< "please enter a number in between 1 and 100: ";
       cin>> guess;
   }

    {
        while(guess != numbers)
    {

        if(guess <= 0 || guess > 100)
        {
            cout<< "please enter a number in between 1 and 100: ";
            cin>> guess;
        }
        else if(guess < number)
        {
            cout<<" Too Low";
            count++;
            cout<< " Guess again: ";
            cin>> guess;
        }
        else if(guess > number)
        {
        cout<<" Too High";
        count++;
        cout<< "Guess again: ";
        cin>> guess;
        }

    }
   }




   while(guess == number && second_count < 2)
   {
     if (count <= 7)
     {
           cout << "congratulations!! you guessed correctly";
           second_count++;
           cout << "(it took you "<< count << " tries)";
     }

     else if(count > 7 && second_count < 2)
        cout << "took you long enough!!!! XP (it took you "<< count << " tries)";

        second_count++;
   }
   }




