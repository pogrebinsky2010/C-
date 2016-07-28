#ifndef SOURCE_H
#define SOURCE_H
#include "image.h"
//#include "filters.h"
//#include "sink.h"

class Source 
{
 	protected:
	   	Image outputImg;
		virtual void Execute()=0;
		virtual const char *SourceName() = 0;
	
		
	public:
		Image *GetOutput(); 
        	Source();
       		virtual void Update();
		
	   
};

#endif
