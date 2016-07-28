#ifndef SINK_H
#define SINK_H
#include <image.h>
#include <stdio.h>
class Sink
{
	public:
		virtual const char *SinkName()=0;
		void SetInput(Image*);
		void SetInput2(Image*);
		Sink();	
	protected:
		Image *img1;
		Image *img2;
};

#endif
