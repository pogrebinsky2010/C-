#ifndef PNM_WRITER_H
#define PNM_WRITER_H
#include <sink.h>
#include <iostream>
using namespace std;
class PNMwriter : public Sink
{

	public:
		PNMwriter(){}
		void Write(char *filename);
		const char *SinkName();
			
};

#endif
