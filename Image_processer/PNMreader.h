#ifndef PNMREADER_H
#define PNMREADER_H

#include "source.h"



class PNMreader : public Source
{ 
    private:
	char* _file;
	
	
    public:
	PNMreader(char*);
	void Execute();
	
	const char* SourceName();
	virtual ~PNMreader(){delete [] _file;};
   
};

#endif
