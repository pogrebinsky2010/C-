#ifndef IMAGE_H
#define IMAGE_H
#include <stdio.h>
#include <stdlib.h>


struct Pixel
{
 unsigned char Red, Green, Blue;
};
class Source;

class Image {

 	private:
	    int width;
	    int height;	
	    Pixel *buffer;	
		Source* src;

	public:
	    Image();
	    Image(int w, int h);
	    Image(Image &); 
       
	    int getWidth();
	    int getHeight();
	    Pixel* getBuffer();
	    void setWidth(int);
	    void setHeight(int);
	    void SetSize(int w , int h);
	    void setBuffer(Pixel* buf);
	    virtual void Update();
	    void SetSource(Source*);
	   virtual ~Image(){if(buffer !=NULL)free(buffer);};
};




#endif
