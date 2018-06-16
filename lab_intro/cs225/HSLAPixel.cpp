#include "HSLAPixel.h"


namespace cs225{

HSLAPixel::HSLAPixel(double hue, double saturation, double luminance){
	h = hue; 
	s = saturation; 
	l = luminance ; 
}

HSLAPixel::HSLAPixel(double hue, double saturation, double luminance, double alpha){
	h = hue;
	s = saturation;
	l = luminance;
	a = alpha;
}

HSLAPixel::HSLAPixel()
{
	h  = 0 ; 
	s = 0 ;
	l = 1 ;
	a = 1 ;   
} 

}


