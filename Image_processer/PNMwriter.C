#include "PNMwriter.h"
#include "stdio.h"
#include <iostream>

using namespace std;

void PNMwriter::Write(char* output)
{
  int w, h;
  
   FILE *pFile  = fopen(output, "w");

   w = img1->getWidth();
   h =img1->getHeight();
   fprintf(pFile, "P6\n%d %d\n255\n", w, h);
   fwrite(img1->getBuffer(), sizeof(Pixel), (w *h), pFile);

     fclose(pFile);
}
const char *PNMwriter::SinkName()
{
    return "PNMwriter";
}


