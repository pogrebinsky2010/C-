#include <stdlib.h>
#include "image.h"
#include "PNMreader.h"
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
 
PNMreader::PNMreader(char *file)
{
	
    _file = new char[256];
    strcpy(_file, file);
}

void PNMreader::Execute()
{
  Pixel* buffer;
	char some[3];	
	int pixSize;
 	int width, height;  
        FILE *pFile = fopen(_file, "r");
	if(!pFile)
		{
			 printf("file did not open properly!");
		}



   	fscanf(pFile, "%s\n%d %d\n%d\n", some , &width, &height, &pixSize);
   

    buffer = (Pixel*)malloc(width * height * sizeof(Pixel));
	
      outputImg.SetSize(width, height);
    
	fread(buffer, sizeof(Pixel), (width * height), pFile);
   
    outputImg.setBuffer(buffer);
    

	fclose(pFile);
 
}
const char *PNMreader::SourceName()
{
	return "PNMreader";
}

