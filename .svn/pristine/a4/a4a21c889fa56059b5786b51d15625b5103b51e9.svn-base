#ifndef IMAGETRAVERSAL_H
#define IMAGETRAVERSAL_H

#include <iterator>
#include <set>
#include <map>
#include <vector>
#include "../cs225/HSLAPixel.h"
#include "../cs225/PNG.h"
#include "../Point.h"

using namespace cs225;

/**
 * A base class for traversal algorithms on images.
 *
 * Each derived class must maintain an ordering of points on an image,
 * through calls to the virtual member functions `add` and `pop`.
 *
 * A derived class provides a traversal by returning instances of
 * ImageTraversal::Iterator.
 */
class ImageTraversal {
public:
  //ImageTraversal();
  /**
   * A forward iterator through an ImageTraversal.
   */
  // imagetraversal iterator ( pass hslapixel pointer, point, )
  class Iterator : std::iterator<std::forward_iterator_tag, Point> {
  public:
    Iterator(Point startPoint, PNG png, ImageTraversal *itptr, double tolerance ); // this iterator should give ass to both bfs and dfs
    Iterator();
    Iterator & operator++();
    Point operator*();
    bool operator!=(const Iterator &other);
    ImageTraversal* itptr;
  private:
    Point *iter_;// we will traverse the pixels using this poiter.
    Point start_;
    double tolerance_;
    PNG orgImage_;

  };


  virtual Iterator begin() = 0;
  virtual Iterator end() = 0;

  virtual void add(const Point & t) = 0;
  virtual Point pop() = 0;
  virtual Point peek() const = 0;
  virtual bool empty() const = 0;

private:
  static double calculateDelta(const HSLAPixel & p1, const HSLAPixel & p2);
};




#endif
