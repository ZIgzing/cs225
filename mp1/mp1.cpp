#include <string>
#include <iostream>
#include <cmath>
#include <cstdlib>

#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"
#include "mp1.h"

using namespace std;
using namespace cs225;


void rotate(std::string inputFile, std::string outputFile) {

  PNG * ImageBefore = new PNG();
  ImageBefore->readFromFile(inputFile);
  PNG * ImageAfter = new PNG(ImageBefore->width(), ImageBefore->height());
  for (unsigned int x = 0 ; x < ImageAfter->width() ; x++){
  for (unsigned int y = 0 ; y < ImageAfter->height() ; y++ ){
    XAfter = ImageBefore->width()-x - 1 ;
    *(ImageAfter->getPixel(Xafter,y)) = *(ImageBefore->getPixel(x,y));

  }
  }

  ImageAfter->outputFile(outputFile);
}
