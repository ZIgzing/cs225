#include "Image.h"
#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"
#include <cstdlib>
#include <cmath>
#include <iostream>

using namespace std;
using namespace cs225;

void Image::lighten(){
  for(unsigned int x=0 ; x < this->width() ; x++){
    for(unsigned int y=0; y< this->height() ; y++){
      HSLAPixel * Pixel = this->getPixel(x,y);
          if(Pixel->l + 0.1 > 1.0){
              Pixel->l = 1;
          }
          else {
            Pixel->l = Pixel->l + 0.1;
          }
}
}
}
void Image::lighten(double amount){
  for(unsigned int x=0 ; x < this->width() ; x++){
    for(unsigned int y=0; y< this->height() ; y++){
      HSLAPixel * Pixel = this->getPixel(x,y);
          if(Pixel->l + amount > 1){
            Pixel->l = 1;
          }
          else{
            Pixel->l = Pixel->l + amount;
          }

}
}
}

void Image::darken(){
  for(unsigned int x=0 ; x < this->width() ; x++){
    for(unsigned int y=0; y< this->height() ; y++){
      HSLAPixel * Pixel = this->getPixel(x,y);
          if(Pixel->l - 0.1 < 0){
            Pixel->l = 0;
          }
          else{
            Pixel->l = Pixel->l - 0.1;
          }
}
}
}
void Image::darken(double amount){
  for(unsigned int x=0 ; x < this->width() ; x++){
    for(unsigned int y=0; y< this->height() ; y++){
      HSLAPixel * Pixel = this->getPixel(x,y);
          if(Pixel->l - amount < 0){
            Pixel->l = 0;
          }
          else{
            Pixel->l = Pixel->l - amount;
          }
}
}
}
void Image::saturate(){
  for(unsigned int x=0 ; x < this->width() ; x++){
    for(unsigned int y=0; y< this->height() ; y++){
      HSLAPixel * Pixel = this->getPixel(x,y);
          if(Pixel->s + 0.1 > 1){
            Pixel->s = 1;
          }
          else {
            Pixel->s = Pixel->s + 0.1;
          }
}
}
}
void Image::saturate(double amount){
  for(unsigned int x=0 ; x < this->width() ; x++){
    for(unsigned int y=0; y< this->height() ; y++){
      HSLAPixel * Pixel = this->getPixel(x,y);
          if(Pixel->s + amount > 1){
            Pixel->s =1;
          }
          else{
            Pixel->s = Pixel->s + amount;
          }
}
}
}
void Image::desaturate(){
  for(unsigned int x=0 ; x < this->width() ; x++){
    for(unsigned int y=0; y< this->height() ; y++){
      HSLAPixel * Pixel = this->getPixel(x,y);
        if(Pixel->s - 0.1 < 0){
          Pixel->s = 0;
        }
        else{
          Pixel->s = Pixel->s - 0.1;
        }
}
}
}
void Image::desaturate(double amount){
  for(unsigned int x=0 ; x < this->width() ; x++){
    for(unsigned int y=0; y< this->height() ; y++){
      HSLAPixel * Pixel = this->getPixel(x,y);
          if(Pixel->s - amount < 0){
            Pixel->s = 0;
          }
          else{
            Pixel->s = Pixel->s - amount;
          }
}
}
}
void Image::grayscale(){
  for (unsigned x = 0; x < this->width(); x++) {
    for (unsigned y = 0; y < this->height(); y++) {
      HSLAPixel *Pixel = this->getPixel(x, y);
        Pixel->s = 0;
}
}
}

void Image::rotateColor(double degrees){
  for (unsigned x = 0; x < this->width(); x++) {
    for (unsigned y = 0; y < this->height(); y++) {
      HSLAPixel *Pixel = this->getPixel(x, y);
      int Rem = (int)degrees % 360;
      if(Pixel->h + Rem > 360){
          Pixel->h = 0 + (Pixel->h + Rem)-360;
      }
      else if(Pixel->h + Rem < 0 )
      {
          Pixel->h = 360 + (Pixel->h + Rem);
      }
      else {Pixel->h = Pixel->h + Rem;}
}
}
}

void Image::illinify(){
    for (unsigned x = 0; x < this->width(); x++) {
      for (unsigned y = 0; y < this->height(); y++){
      			HSLAPixel *Pixel = this->getPixel(x, y);
			           if (Pixel->h < 113.5 || Pixel->h > 293.5)
				              Pixel->h = 11;
			           else Pixel->h = 216;
		}
	}
}
void Image::scale(double factor){
    Image NewImage = *this;
    unsigned int NewWidth = this->width()*factor;
    unsigned int NewHeight = this->height()*factor;
    this->resize(NewWidth,NewHeight);
    for(unsigned x=0; x < NewWidth ; x++){
      for(unsigned y=0; y < NewHeight ; y++){
        *(this->getPixel(x,y)) = *(NewImage.getPixel(x/factor,y/factor));
      }
    }

}

void Image::scale(unsigned w, unsigned h){
    Image NewImage = *this;
    double Wratio = (double)w/this->width();
    double Hratio = (double)h/this->height();
    this->resize(w,h);
    for(unsigned x=0; x < w ; x++){
      for(unsigned y=0; y < h ; y++){
        *(this->getPixel(x,y)) = *(NewImage.getPixel(x/Wratio,y/Hratio));
      }
    }

}
