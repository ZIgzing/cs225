#include "StickerSheet.h"
#include <cstdlib>
#include <iostream>
#include "Image.h"
#include "cs225/PNG.h"

using namespace std;

StickerSheet::StickerSheet(const Image &picture, unsigned max){
    max_ = max; // setting the input max value into the private variable
    baseImage_ = picture; // creating a base image on the stack , but not on the heap
    index_= 0;
    stickerImages_ = new Image*[max]; // pointer and pointer to an array
    x_ = new unsigned[max]; // array that is containing the x position, and the y position.
    y_ = new unsigned[max]; // array that is containing the y position
    for( int i = 0 ; i < max ; i++){
        *(stickerImages_ + i) = NULL;
        *(x_ + i) = 0;
        *(y_ + i) = 0;
    }

}
StickerSheet::~StickerSheet(){
    this->clear(); // calling the clear helper function.
}


StickerSheet::StickerSheet(const StickerSheet &other){
    copy(other); // copying the other object
}
const StickerSheet& StickerSheet::operator=(const StickerSheet & other){
    if(*this != other){
          this->clear(); // clearing arrays in the heap and setting the max back to 0.
          this->copy(other); // copying the other object
    }
    return *this; // returning the address of the object.

}
void StickerSheet::changeMaxStickers(unsigned max){
      Image **newSticker = new Image*[max]; // creating another array on heap that stores the new max amount
      if (max > max_){
          for( int i = 0; i < max_; i++){
              newSticker[i] = stickerImages_[i]; //break image pointer vs image
          }
            for( int i = max_ ; i < max ; i++){
                newSticker[i] = NULL;
                clear();
            }
                                            // let's point the original array to the new assigning
        }
      else {
              for(int i = 0; i < max ; i++){
              newSticker[i] = stickerImages_[i];            // delete here
            }
              for(int i = max ; i < max_ ; i++){
                delete [] stickerImages_[i] ; // deletes the spaces of the original that has nothing
              }
              clear();
      }
      delete [] stickerImages_;
      stickerImages_ = newSticker; // stickerimages point to the newsticker
      max_ = max; // set new max ;
}

int StickerSheet::addSticker(Image &sticker, unsigned x, unsigned y){
              for( index_ = 0 ; index_ < max_; index_++){
                  if(stickerImages_[index_] == NULL){
                            y_[index_] = y;
                      return index_;} // this i that has been returned should be our number of index
                  else{
                      return -1;
                      }
              }
}

bool StickerSheet::translate(unsigned index, unsigned x, unsigned y){
    if(index >= max_ || stickerImages_[index] == NULL){
      return false ; // returning false if it does not contain a sicker
    }
    else{
      x_[index] = x; // setting the new x coordinate
      y_[index] = y; // setting the new y coordinate
    }
    }


// if contain sticker, return true
// if does not contain sticker return false ;
void StickerSheet::removeSticker(unsigned index){
  if(index >= max_ || stickerImages_[index] == NULL){
        return;
  }
  else{
        delete [] stickerImages_[index];
        stickerImages_[index] = NULL;
      }
}

Image * StickerSheet::getSticker(unsigned index) const{
    if( stickerImages_[index] == NULL || index >= max_){
        return NULL;
    }
    else {
        return stickerImages_[index]; // returns the pointer to the sticker on the stickersheet at the index location
    }
}

Image StickerSheet::render() const{
Image a;
     a = baseImage_;
     unsigned baseWidth = a.width();
     unsigned baseHeight = a.height();
     for( int i = 0; i < index_ ;  i++){
       unsigned x = x_[i];
       unsigned y = y_[i];
       if(x > baseWidth){
         a.resize(x+(x-baseWidth),y);
       }
       else if( y > baseHeight){
         a.resize(x,y+(y-baseHeight));
       }
       else if ( x > baseWidth && y > baseHeight){
         a.resize(x+(x-baseWidth),y+(y-baseHeight));
       }
             for( int i = 0 ; i < stickerImages_[index_]->width() ; i++){
               for( int j = 0 ; j < stickerImages_[index_]->height() ; j++){
                  HSLAPixel *basePixels = a.getPixel(x+i,y+j);
                     HSLAPixel * stickerPixels = stickerImages_[index_]->getPixel(i,j);
                       basePixels->h = stickerPixels->h;
                       basePixels->s = stickerPixels->s;
                       basePixels->l = stickerPixels->l;
                       basePixels->a = stickerPixels->a;
           }
}
}
return a;
}

void StickerSheet::copy(const StickerSheet &other){
  *stickerImages_ = new Image[max_] ;
  x_ = new unsigned[max_];
  y_ = new unsigned[max_]; // creates an array that stores the sticker in the heap
  baseImage_ = other.baseImage_; // copying the backgroudn image
  index_ = other.index_;
  for( int i = 0 ; i < max_ ; i++){
      stickerImages_[i] = NULL;
      *(x_+ i)= 0;
      *(y_+ i) = 0; // should dereference or no
  }
  for(int i = 0 ; i < max_ ; i++){
      stickerImages_[i] = other.stickerImages_[i] ; // this equals new image make dep copy
      this->x_[i] = other.x_[i];
      this->x_[i] = other.y_[i];
    // copy the background image;
  }
}

void StickerSheet::clear(){
      for( int i = 0 ; i < max_ ;  i++){
        if(stickerImages_ != NULL){
          delete [] stickerImages_[i];
                (stickerImages_[i]) = NULL;
}
  if(x_ != NULL){
      delete x_; // deletes the x
      x_ = NULL; //
    }
  if(x_ != NULL){
      delete y_;
      y_ = NULL;
    }
      delete stickerImages_ ; // we must delete the stickerImages addresses on the heap that contained the pointers.
      stickerImages_ = NULL;
    this->max_ = 0;
}
}
