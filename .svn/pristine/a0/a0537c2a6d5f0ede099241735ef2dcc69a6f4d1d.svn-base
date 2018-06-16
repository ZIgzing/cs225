#include <math.h>
#include <stdio.h>
#include <iostream>
#include <cstdlib>

using namespace std;

/**
 * @file kdtree.cpp
 * Implementation of KDTree class.
 */
template <int Dim>
bool KDTree<Dim>::smallerDimVal(const Point<Dim>& first,
                                const Point<Dim>& second, int curDim) const
{
    /**
     * @todo Implement this function!
     */
    if(first[curDim] < second[curDim]){
      return true;
    }
    else if(first[curDim] == second[curDim]){
      return first < second;
    }
    return false;
}

template <int Dim>
bool KDTree<Dim>::shouldReplace(const Point<Dim>& target,
                                const Point<Dim>& currentBest,
                                const Point<Dim>& potential) const
{
  double currentDistance=0;
  double newDistance=0;
  for(int i = 0; i < Dim ; i++){
    currentDistance = currentDistance + pow((currentBest[i]-target[i]),2);
  }
  //currentDistance = pow((),0.5);
  for(int i = 0; i < Dim ; i++){
    newDistance = newDistance + pow((potential[i]-target[i]),2);
  }
  cout << currentDistance << endl;
  cout << newDistance << endl;
  currentDistance = pow(currentDistance,0.5);
  newDistance = pow(newDistance,0.5);

  if(currentDistance == newDistance){
    return (potential < currentBest);
  }
  else if(currentDistance > newDistance){
    return true;
  }
  else{
    return false;
  }

    /**
     * @todo Implement this function!
     */
     // return true if potential is closer to target
}

template <int Dim>
KDTree<Dim>::KDTree(const vector< Point<Dim> > & newPoints)
{
  points = newPoints;
  if(points.size() != 0){
      buildKDTree(0, points.size()-1, 0);
  }
    /**
     * @todo Implement this function!
     */
}

template <int Dim>
size_t KDTree<Dim>::partition(size_t left, size_t right, size_t pivotIndex, int ourDim){
  Point<Dim> pivotValue = points[pivotIndex]; // we have set the pivot value
  Point<Dim> temp = points[right] ; // temp has the value of end
  points[pivotIndex] = temp; // now we want to swap the valuaes storing value at the end to the pivotindex position
  points[right] = pivotValue; // on the right side we will store the pivotvalue tha we stored previously
  int returnIndex = left; // this is the samething as the store index from the wikpedia example, and we return this at the end;
  //returnIndex = left; // since we don't have the swap variable let's create two temporary variables that we we want to swap in the function
  for(size_t i = left; i < right ; i++){
      if(pivotValue == points[i] || smallerDimVal(points[i], pivotValue, ourDim)){
        // now we want to swap the value of returnindex's and the one that we are iterating throught
        Point<Dim> temp1 = points[returnIndex];
        points[returnIndex] = points[i];
        points[i] = temp1;
        returnIndex++;
      }
      //  after swapping all teh way till the end, we want to swap the right and store index's
  }
      Point<Dim> temp2 = points[returnIndex];
      points[returnIndex] = points[right];
      points[right] = temp2;
      return returnIndex;

}

template <int Dim>
void KDTree<Dim>::quickSelect(size_t left, size_t right, int dim, size_t middleIndex){
  if(left == right){
    return;
  }
  while(left != right){
    size_t pivotIndex = partition(left, right, middleIndex, dim); // this gives us the index after the list has been seperated
    if(pivotIndex == middleIndex){
      return; // returning the index when we find found its natural position
    }
    else if( middleIndex < pivotIndex){
      right = pivotIndex - 1; // change the value of the right
    }
    else if( middleIndex > pivotIndex){
      left = pivotIndex + 1;// change the value of the left
    }
  }
}

template <int Dim>
void KDTree<Dim>::buildKDTree(size_t left, size_t right, int dim){
  int DimMod = (dim+1) % Dim;
  if(left == right){
    return;
  }
  else if (left != right){
    size_t middleIndex = floor((left+right)/2);
    quickSelect(left, right , dim, middleIndex);
  if(left < middleIndex){
    buildKDTree(left, middleIndex-1, DimMod);
  }
  if(right > middleIndex){
    buildKDTree(middleIndex+1, right, DimMod);
  }
  else{
    return;
  }
}
}







template<int Dim>
Point<Dim> KDTree<Dim>::findNearestNeighbor(const Point<Dim> & query) const
{
    /**
     * @todo Implement this function!
     */

   if(points.empty()){
     return Point<Dim>();
   }
   else if(points.empty() == false){
     double index = (points.size()-1)/2;
     Point<Dim> x = points[index];
     return findHelper(query, x, 0, points.size()-1, 0);
   }
    return Point<Dim>();
}

//helper function for findNearestNeighbor

template<int Dim>
Point<Dim> KDTree<Dim>::findHelper(const Point<Dim> &query, const Point<Dim> &constPoint, size_t left, size_t right, int d) const{
    int dimm = (d+1)%Dim ;
    Point<Dim> championNow = constPoint;
    if(left == right){
        if(shouldReplace(query, championNow, points[left])){
            championNow = points[left];
            return championNow;
        }
        championNow = constPoint;
        return championNow;
    }

    bool leftTree = false;
    size_t mid = (left+right)/2;

    if (smallerDimVal(query, points[mid], d)){
      if(left < mid){
        championNow = findHelper(query, championNow, left, mid-1, dimm);
        leftTree = true;
      }
    }
    if (smallerDimVal(points[mid], query, d)){
      if(right > mid){
        championNow = findHelper(query, championNow, mid+1, right, dimm);
        leftTree = false;
      }
    }

    if (shouldReplace(query, championNow, points[mid]) == true){
        championNow = points[mid];
    }

    size_t steph = (points[mid][d]-query[d])*(points[mid][d]-query[d]);

    size_t curry = 0;
    for(size_t j = 0; j < Dim; j++){
        curry +=  (query[j]-championNow[j])*(query[j]-championNow[j]);
    }

    if (steph <= curry)
    {
        if (leftTree == true){
          if(mid < right){
            championNow = findHelper(query, championNow, mid+1, right, dimm);
          }
        }
        if (leftTree == false){
          if(left < mid){
            championNow = findHelper(query, championNow, left, mid-1, dimm);
          }
    }
  }
    return championNow;
}
