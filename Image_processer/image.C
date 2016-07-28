#ifndef IMAGE_C
#define IMAGE_C
#include <image.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "PNMreader.h"


using namespace std;

Image::Image()
{
  height = 0;
  width = 0;
  buffer = NULL;
}
void Image::SetSource(Source * _src)
{
	src = _src;
}
void Image::Update()
{
	
	    src->Update();
	
}
Image::Image(int w, int h)
{
  height = h;
  width = w;
  buffer = (Pixel*)malloc(width * height * sizeof(Pixel));
}

Image::Image(Image &image)
{
  this->height= image.height;
  this->height= image.width;
  this->buffer = (Pixel *)malloc(sizeof(Pixel)*image.height*image.width);

  int i;
  int totalPixels = image.width * image.height;
  for(i = 0; i < totalPixels; i++)
     {
	   buffer[i] = image.buffer[i];
     }

}

void Image::SetSize(int w, int h)
{
	free(buffer);
	buffer = (Pixel*)malloc(w * h * sizeof(Pixel));
  this->width =w;
  this->height = h;

}
int Image::getWidth()
{
	return width;
}
int Image::getHeight()
{
	return height;
}
Pixel* Image::getBuffer()
{
	return buffer;

}
void Image::setBuffer(Pixel* buf)
{
	if(buffer!=NULL)
	{
		free(buffer);
	}
	buffer = buf;
}
#endif
