//Tslsba Pogrebinsky lab6

#include <iostream>

using namespace std;

int main()
{


    int  numOfSticks, totalNumOfSticks=11,playerDecider, cOunt=0;
    bool isEven;


    cout<< "NIM GAME! instructions: Game objective- take away the remaining sticks; Rules: each player can only take between 1 and 3 sticks.";
    cout<< "  The game currently looks like this: ";
    cout<<endl;
    for(int i = 0; i < totalNumOfSticks; i++)
    {
        cout<<"|";
    }



    while(totalNumOfSticks >= 1)

    {
        cout << endl << "how many sticks would you like to take away? ";
        cin >> numOfSticks;


        while(numOfSticks < 0 || numOfSticks > 3)
        {
            cout<<"Please enter a number between 1-3: ";
            cin>>numOfSticks;

        }

        if(numOfSticks > 0 && numOfSticks < 4)
        {


            while(totalNumOfSticks < numOfSticks)
                {
                    cout << "error you can not take more sticks then left, please enter a new number: " << endl;
                    cin >> numOfSticks;

                }


           totalNumOfSticks -= numOfSticks;
           cOunt++;
        }
            if(totalNumOfSticks != 0)
             {
                 if(cOunt % 2 == 0)
                   {
                        isEven = true;
                   }
                 else
                   {
                        isEven = false;
                   }

                if (isEven == false)
                {
                    cout << " Now thier is " << totalNumOfSticks << " left, player TWO make your next move... ";
                }
                else
                {
                    cout << " Now thier is " << totalNumOfSticks << " left, player ONE make your next move... ";
                }
            }

           for( int i = 0; i < totalNumOfSticks; i++)
                {
                    cout<<"|";
                }
        }


     if(cOunt % 2 == 0)
    {
        isEven = true;
    }
    else
    {
        isEven = false;
    }


    while(totalNumOfSticks == 0 && isEven == true)

    {
       cout<< "Player TWO: YOU WIN!";
       return 0;
    }
    while(totalNumOfSticks == 0 && isEven == false)
    {
        cout<<"Player ONE: YOU WIN!";
        return 0;
    }


}





