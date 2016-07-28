#include <sink.h>

void Sink::SetInput(Image *_img1)
{	
	img1 = _img1;
   
}
void Sink::SetInput2( Image *_img2)
{
	img2 = _img2;
    
}
Sink::Sink()
{
    img1 = NULL;
    img2 = NULL;
}



