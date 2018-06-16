#ifndef STICKERSHEET_H
#define STICKERSHEET_H
#include <iostream>
#include <cstdlib>
#include "Image.h"

using namespace std;

class StickerSheet : public Image{
    private:
      Image baseImage_;
      Image **stickerImages_; // stickers that will go to the base pic
      unsigned max_; // max count of the stickers
      unsigned *x_; // our array for the x coordinates
      unsigned *y_; // our array for the y cooridnate
      unsigned index_;


    //  unsigned x;
    //  unsigned y;
    // unsgined index = 0;

    public:
        StickerSheet(const Image &picture, unsigned max); // initializes sticker sheet with a base picture and the ability to hold the max number of stickers with indicies 0 through max -1
        ~StickerSheet(); // Frees all spaces that was dynamically allocated by the stickersheet
        StickerSheet(const StickerSheet &other); // makes Stickersheet independence of the source, use rule of three
        const StickerSheet& operator=(const StickerSheet &other); // assignement operator , use rule of three
        void changeMaxStickers(unsigned max); // modifies the number of sticker that can be stored on the stickersheet
        int addSticker(Image &sticker, unsigned x, unsigned y);// adds sticker to stickersheet  top top left of the sicker (x,y) on the stickersheet
        bool translate(unsigned index, unsigned x, unsigned y);// changes x and y  coordinates of the  IMAGE in the specified layer
        void removeSticker(unsigned index);//Removes the sticker at the given zero-based layer index.
        Image* getSticker(unsigned index) const;//Returns a pointer to the sticker at the specified index, not a copy of it.
        Image render() const;
        void copy(const StickerSheet &other);
        void clear();

};

#endif
