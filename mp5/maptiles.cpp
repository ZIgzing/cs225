/**
 * @file maptiles.cpp
 * Code for the maptiles function.
 */

#include <iostream>
#include <map>
#include "maptiles.h"

using namespace std;

MosaicCanvas* mapTiles(SourceImage const& theSource,
                       vector<TileImage> const& theTiles)
{
  vector<Point<3> > mozaicPixels;
  map<Point<3>, TileImage> tileMap;
  MosaicCanvas * finalImage = new MosaicCanvas(theSource.getRows(), theSource.getColumns());
  HSLAPixel ourHSLA;
  for(size_t i = 0; i < theTiles.size() ; i++){
    ourHSLA = theTiles[i].getAverageColor();
    mozaicPixels.push_back(Point<3>(ourHSLA.h, ourHSLA.s, ourHSLA.l, ourHSLA.a));
    tileMap[Point<3>(ourHSLA.h, ourHSLA.s, ourHSLA.l, ourHSLA.a)] = theTiles[i];
  }
  KDTree<3> ourKDTree(mozaicPixels);
  size_t ourRow = theSource.getRows();
  size_t ourColumn = theSource.getColumns();
  for(size_t x = 0 ; x < ourRow ; x++){
    for(size_t y = 0; y < ourColumn; y++){
      HSLAPixel newHSLA = theSource.getRegionColor(x, y); // getting the average color of the neighbors
      Point<3> pointResult = Point<3>((double)newHSLA.h,(double)newHSLA.s, (double)newHSLA.l);
      pointResult = ourKDTree.findNearestNeighbor(pointResult);
      finalImage->setTile(x, y, tileMap.find(pointResult)->second);
    }
  }
  return finalImage;
}
