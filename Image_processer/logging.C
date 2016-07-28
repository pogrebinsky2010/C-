#include "logging.h"
#include <stdio.h>
#include <fstream>
#include <iostream>


FILE* Logger::logger = fopen("logger", "w");


DataFlowException::DataFlowException(const char *type, const char *error)
{
	sprintf(msg, "%s: %s" ,type, error);
	Logger::LogEvent(msg);
}
void Logger::LogEvent(const char *event)
{
    
	fprintf(logger, "%s\n", event);
	
}
void Logger::Finalize()
{
	fclose(logger);
}

