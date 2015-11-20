#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <stdalign.h>

using namespace std;

int main()
{


    const int HEX_NUM = 0x7a;
    const int DEC_NUM = 65;
    const char LETTER = 'l';

    char decConversion = HEX_NUM;
    char hexConversion = DEC_NUM;






    cout << "the decimal form of decimal is "<< dec << DEC_NUM << endl;
    cout << "the decimal form of hex number is "<< dec << HEX_NUM << endl;
    cout << "the decimal form of letter is " << dec << static_cast<int>(LETTER) <<endl;

    cout << "the letter form of letter is "<< LETTER << endl;
    cout << "the letter form of decimal is "<< decConversion << endl;
    cout << "the letter form of hex is "<< hexConversion <<endl;

     cout << "the hex form of the Decimal is " << hex << DEC_NUM << endl;
    cout << "the hex form of the hex number is " << hex << HEX_NUM << endl;
    cout << "the hex form of letter is " << hex << static_cast<int>(LETTER) <<endl;





}
