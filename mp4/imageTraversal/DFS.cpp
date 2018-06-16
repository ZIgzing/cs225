#include <iterator>
#include <cmath>
#include <list>
#include <stack>

#include "../cs225/PNG.h"
#include "../Point.h"

#include "ImageTraversal.h"
#include "DFS.h"

/**
 * Initializes a depth-first ImageTraversal on a given `png` image,
 * starting at `start`, and with a given `tolerance`.
 */
DFS::DFS(const PNG & png, const Point & start, double tolerance) {
  /** @todo [Part 1] */
  orgImage_ = png; // creating a copy of our original image
  tolerance_ = tolerance; // setting the tolerance to 0
  imageStart_ = start;
  imageStart_.x = start.x;
  imageStart_.y = start.y;
  myStack_.push(start); // pushing in our first point
}

/**
 * Returns an iterator for the traversal starting at the first point.
 */
ImageTraversal::Iterator DFS::begin() {
  /** @todo [Part 1] */
  return ImageTraversal::Iterator();//imageStart_, orgImage_, itptr, tolerance_);
}

/**
 * Returns an iterator for the traversal one past the end of the traversal.
 */
ImageTraversal::Iterator DFS::end() {
  /** @todo [Part 1] */
  return ImageTraversal::Iterator(); //imageStart_, orgImage_, itptr, tolerance_);
}

/**
 * Adds a Point for the traversal to visit at some point in the future.
 */
void DFS::add(const Point & point) {
  /** @todo [Part 1] */
  myStack_.push(point);
  return;

}

/**imageStart_
 * Removes and returns the current Point in the traversal.
 */
Point DFS::pop() {
  /** @todo [Part 1] */
  Point currentPop;
  currentPop = myStack_.top();
  myStack_.pop();
  return currentPop;
}

/**imageStart_
 * Returns the current Point in the traversal.
 */
Point DFS::peek() const {
  /** @todo [Part 1] */
  // while(myStack_.empty()){
  //   return start_;
  return Point(0,0);
}

/**
 * Returns true if the traversal is empty.
 */
bool DFS::empty() const {
  /** @todo [Part 1] */
  if(myStack_.empty()){
  return true;
  }
  else{
    return false;
  }
}
