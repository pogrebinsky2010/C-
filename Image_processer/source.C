#include "source.h"
#include <stdio.h>
#include <logging.h>
#include "iostream"

using namespace std;
Source::Source()
{
	outputImg.SetSource(this);	
}

Image* Source::GetOutput() 
{
  return &outputImg;
}

void Source::Update()
{
	char msg[128];
	sprintf(msg,"%s:about to execute",SourceName());

	Logger::LogEvent(msg);
    
	Execute();
	char msg2[128];
	sprintf(msg2,"%s:done executing ",SourceName());
	Logger::LogEvent(msg2);
}


