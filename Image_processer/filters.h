#ifndef FILTERS_H
#define FILTERS_H
#include <image.h>
#include <source.h>
#include <sink.h>


class Filter : public Source, public Sink
{
	public:
		Filter(){}
	protected:
		
		virtual void Update();
        virtual void Execute();
		virtual const char *FilterName()  = 0;
    const char *SourceName(){return FilterName();};
    const char *SinkName(){return FilterName();};
    
    
};

class Shrinker : public Filter
{
	public:
		Shrinker(){}
		void Execute();
		
		const char * FilterName(){ return "Shrinker";};
	private:
		 
		
	

};
class LRConcat : public Filter
{
	public:
		LRConcat(){}
		void Execute();
    const char *FilterName() { return "LRConcat";};
		
	
};
class TBConcat : public Filter
{
	public:
		TBConcat(){}
		void Execute();
    const char *FilterName(){return "TBConcat";};
		
		
};
class Blender : public Filter
{
	public:
		Blender(){}
		void Execute();
   const char *FilterName(){return "Blender";};

		
		void SetFactor(float);
	private:
		
		float _factor;
	
};

#endif

