#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <filters.h>
#include <iostream>
#include "logging.h"

using namespace std;
void Filter::Execute(){}

void Filter::Update()
{
	if(img1!=NULL)
	{	
    		char msg[128];
		
		sprintf(msg,"%s:about to update input1",SinkName());
		Logger::LogEvent(msg);
		

		img1->Update();	

        sprintf(msg,"%s:done updating input 1",SinkName());
		Logger::LogEvent(msg);
		
	}
	if(img2!=NULL)
	{
    		char msg[128];
		
		sprintf(msg,"%s:about to update input2",SinkName());
		Logger::LogEvent(msg);
		

		img2->Update();	

		
		sprintf(msg,"%s:done updating input2",SinkName());
		Logger::LogEvent(msg);
		
	}
		
	char msg[128];	
	sprintf(msg,"%s:about to execute",SourceName());
	Logger::LogEvent(msg);
	Execute();

	sprintf(msg,"%s:done executing",SourceName());
	Logger::LogEvent(msg);
	
}

void Shrinker::Execute()
{
	Pixel* inputBuffer;
	Pixel* outputBuffer;

	int outputWidth = outputImg.getWidth();
	int outputHeight = outputImg.getHeight();
	int inputWidth  = img1->getWidth();
	int inputHeight = img1->getHeight();
	int i,j;
	int totalPixels = inputWidth * inputHeight;
	int halfPixels = totalPixels/2;
	int halfHeight = inputHeight/2;
	int halfWidth = inputWidth/2;

 	outputImg.SetSize(halfWidth, halfHeight);
 
	inputBuffer = img1->getBuffer();
	outputBuffer = outputImg.getBuffer();

	for(i=0; i<halfHeight; i++)
   	{
   		for(j=0;j<halfWidth; j++)
	{
	int outputIndex = i * halfWidth + j;
	int inputIndex  = 4 * i * halfWidth + 2 * j;

        outputBuffer[outputIndex]= inputBuffer[inputIndex];
       
       }
    }
}

void TBConcat::Execute()
{

	Pixel* topBuffer; 
	Pixel* bottomBuffer; 
	Pixel* outputBuffer;

	int topInputWidth = img1-> getWidth();
	int topInputHeight = img1-> getHeight();
	int bottomInputHeight = img2-> getHeight();
	int bottomInputWidth = img2 -> getWidth();

	if(topInputWidth != bottomInputWidth)
	{
		char msg[128];
		sprintf(msg, "%s: widths must match: %d, %d", SinkName(),img1->getWidth(), img2->getWidth());
		DataFlowException e(SinkName(),msg);
		throw e;
	}
	
	

	int outputWidth = topInputWidth;
	int outputHeight = topInputHeight + bottomInputHeight;
	int i,j;
	int outputIndex;
	int inputIndex;

	outputImg.SetSize(outputWidth,outputHeight);
	topBuffer = img1->getBuffer();
	bottomBuffer = img2->getBuffer();
	outputBuffer = outputImg.getBuffer();

	for(i=0; i< outputHeight; i++)
	{
 		for(j=0; j< outputWidth; j++)
    		{
			if(i < topInputHeight)
			{
                   	   outputBuffer[i * outputWidth + j] = topBuffer[i * topInputWidth + j];
			}
			else
			{
                    	   outputBuffer[i * outputWidth + j] = bottomBuffer[(i-topInputHeight) * bottomInputWidth + j]; 
			}
		}

	} 

}

void LRConcat::Execute()
{


 	if(img2 == NULL)
	{
		char msg[1024];
		sprintf(msg, "%s: image 2 is NULL", SinkName());
		DataFlowException e(SinkName(),msg);
		throw e;
		
	}

	if(img1->getHeight() != img2->getHeight())
	{
		char msg[128];
		sprintf(msg, "%s: heights must match: %d, %d", SinkName(),img1->getHeight(), img2->getHeight());
		DataFlowException e(SinkName(),msg);
		throw e;
	}
	
	Pixel *outputBuffer;
	Pixel *rightBuffer;
	Pixel *leftBuffer;
	int leftInputWidth = img1->getWidth();
	int leftInputHeight = img1->getHeight();
	int rightInputWidth = img2->getWidth();
	int rightInputHeight = img2->getHeight();

	

	int outputWidth = (leftInputWidth+rightInputWidth);
	int outputHeight = rightInputHeight;

	outputImg.SetSize(outputWidth,outputHeight);
	leftBuffer = img1->getBuffer();
	rightBuffer = img2->getBuffer();
	outputBuffer = outputImg.getBuffer();




int i,j;

for(i=0; i< outputWidth; i++)
{
  for(j=0; j< outputHeight; j++)
    {
               if(i< leftInputWidth)
                   {
                      outputBuffer[j * outputWidth + i].Red   = leftBuffer[j * leftInputWidth + i].Red;
		      outputBuffer[j * outputWidth + i].Green = leftBuffer[j * leftInputWidth + i].Green;
		      outputBuffer[j * outputWidth + i].Blue  = leftBuffer[j * leftInputWidth + i].Blue;
		      
                   }
		else{
    			 outputBuffer[j * outputWidth + i].Red   = rightBuffer[j * rightInputWidth +(i-leftInputWidth)].Red;
    			 outputBuffer[j * outputWidth + i].Green = rightBuffer[j * rightInputWidth +(i-leftInputWidth)].Green;
   		         outputBuffer[j * outputWidth + i].Blue  = rightBuffer[j * rightInputWidth +(i-leftInputWidth)].Blue; 
		    }
		}
      
    }

  }
void Blender::SetFactor(float factor)
{
	_factor = factor;
}
 
void Blender::Execute()
{
    if(_factor>1 || _factor <0)
    {
        char msg[128];
        sprintf(msg,"%s: Invalid factor for Blender: %f", SinkName(), _factor);
        DataFlowException e(SinkName(), msg);
        throw e;
    }


    float lessThenFactor = 1 - _factor;
    Pixel *outputBuffer;
    Pixel *input1Buffer;
    Pixel *input2Buffer;

    int i,j;
    int index;
    int outputWidth = img1->getWidth();
    int outputHeight = img1->getHeight();

    outputImg.SetSize(outputWidth, outputHeight);
  
    outputBuffer = outputImg.getBuffer();
    input1Buffer = img1->getBuffer();
    input2Buffer = img2->getBuffer();

   for(i=0; i<outputHeight; i++)
      {
	for(j=0; j<outputWidth; j++)
            {
            index = i*outputWidth+j;
            outputBuffer[index].Red = (input1Buffer[index].Red *_factor)+(input2Buffer[index].Red *lessThenFactor);
            outputBuffer[index].Green =(input1Buffer[index].Green *_factor)+(input2Buffer[index].Green *lessThenFactor);
            outputBuffer[index].Blue = (input1Buffer[index].Blue *_factor)+(input2Buffer[index].Blue *lessThenFactor);   
            }

      }
}

