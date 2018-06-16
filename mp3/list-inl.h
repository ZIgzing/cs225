#include <iostream>
#include <cstdlib>
#include "list.h"


using namespace std;


/**
 * Destroys the current List. This function should ensure that
 * memory does not leak on destruction of a list.
 */
template <class T>
List<T>::~List() {
  clear();
  /// @todo Graded in MP3.1
}



/**
 * Destroys all dynamically allocated memory associated with the current
 * List class.
 */
template <class T>
void List<T>::clear() {
  if (this->head_ != NULL) {
    ListNode* curr = this->head_;
    while (curr != NULL) {
      ListNode* temp = curr->next;
      delete curr;
      curr = temp;
    }
    this->head_ = NULL;
    this->tail_ = NULL;
    this->length_ = 0;
  }
  /// @todo Graded in MP3.1
}

/**
 * Inserts a new node at the front of the List.
 * This function *SHOULD* create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <class T>
void List<T>::insertFront(T const& ndata) {
	ListNode* newNode = new ListNode(ndata);
	if(length_ == 0){
			newNode->next = NULL;
			newNode->prev = NULL;
			head_ = newNode;
			tail_ = newNode;
	}
	else{
	newNode->prev = NULL;
	newNode->next = head_;
	head_->prev = newNode;
	head_ = newNode;
  }//delete newNode;
  length_++;
  newNode = NULL;
}

/**
 * Inserts a new node at the back of the List.
 * This function *SHOULD* create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <class T>
void List<T>::insertBack(const T& ndata) {
ListNode* newNode = new ListNode(ndata);
  if(length_ == 0){
			 newNode->next = NULL;
			 newNode->prev = NULL;
			 head_ = newNode;
			 tail_ = newNode;
	 }
	else{
	newNode->prev = tail_;
  tail_->next = newNode;
	tail_ = newNode;
  }
  newNode = NULL;
 	 length_+=1 ;
}

/**
 * Reverses the current List.
 */
template <class T>
void List<T>::reverse() {
  reverse(head_, tail_);
}

/**
 * Helper function to reverse a sequence of linked memory inside a List,
 * starting at startPoint and ending at endPoint. You are responsible for
 * updating startPoint and endPoint to point to the new starting and ending
 * points of the rearranged sequence of linked memory in question.
 *
 * @param startPoint A pointer reference to the first node in the sequence
 *  to be reversed.
 * @param endPoint A pointer reference to the last node in the sequence to
 *  be reversed.
 */
template <class T>
void List<T>::reverse(ListNode*& startPoint, ListNode*& endPoint) {
	ListNode* temp = startPoint; // pointer called temp points to the same location as startPoint
	ListNode* ostp = startPoint; // original startpoint
	ListNode* ept = endPoint; // original endpoint
	ListNode* before = endPoint->next; // hold the position of the orginal endpoint's next node
	ListNode* after = startPoint->prev; // holding the position of the original startpoint's previous node
	//	cout << " Debugging!! " << endl;
		while(temp != endPoint && temp->next != NULL){
					//cout << " Debugging!! " << endl;
					ListNode* temp2 = temp->next; // ***temp is null***
					temp->next = temp->prev;
					temp->prev = temp2;
					temp = temp2; // traversing
					}
					ListNode* temp3 ;
					temp3 = temp->next;
					temp->next = temp->prev;
					temp->prev = temp3;
					temp = temp3;

					startPoint = ept;
					endPoint = ostp;
					startPoint->prev = after;
					endPoint->next = before;
					//cout << " Debugging " << endl;

					if(after != NULL){
						after->next = startPoint;
					}
          else{
            head_ = startPoint;
          }
					if(before != NULL){
						before->prev = endPoint;
					}
          else{
            tail_ = endPoint;
          }
					temp = NULL;
					ostp = NULL;
					ept = NULL;
					before = NULL;
					after = NULL;
					temp3 = NULL;

		}

/**
 * Reverses blocks of size n in the current List. You should use your
 * reverse( ListNode * &, ListNode * & ) helper function in this method!
 *
 * @param n The size of the blocks in the List to be reversed.
 */
 template <class T>
 void List<T>::reverseNth(int n) {

   ListNode* originalStart;
   ListNode* originalEnd;
   originalStart = head_;
   originalEnd = head_;
   if(head_ == NULL){
     return;
   }
   if(n == length_){
     reverse(head_, tail_);
     return;
   }
   while(originalEnd != NULL ){
     for(int i=1; i < n ; i++){
       if(originalEnd->next != NULL){
       originalEnd = originalEnd-> next;
     }
     }
         reverse(originalStart, originalEnd);
         originalStart = originalEnd->next;
         originalEnd = originalStart;
         //originalStart = originalEnd;
    }
}



 /**
  * Modifies the List using the waterfall algorithm.
  * Every other node (starting from the second one) is removed from the
  * List, but appended at the back, becoming the new tail. This continues
  * until the next thing to be removed is either the tail (**not necessarily
  * the original tail!**) or NULL.  You may *NOT* allocate new ListNodes.
  * Note that since the tail should be continuously updated, some nodes will
  * be moved more than once.
  */
 template <class T>
 void List<T>::waterfall() {

    if (head_ == NULL || tail_ == NULL || length_ == 0)
        return;

    ListNode * curr, *org;
    org = head_;
    curr = head_;

    while (curr->next != NULL && curr!= NULL )
    {
        curr = org->next;
        org->next = curr ->next;
        curr->next->prev = org;
        tail_->next = curr;
        curr -> next = NULL;
        curr -> prev = tail_;
        tail_ = curr;
        org = org->next;
        curr = org->next;


    }
    org = NULL;
    curr = NULL;
 }

 /**
  * Splits the given list into two parts by dividing it at the splitPoint.
  *
  * @param splitPoint Point at which the list should be split into two.
  * @return The second list created from the split.
  */
 template <class T>
 List<T> List<T>::split(int splitPoint) {
     if (splitPoint > length_)
         return List<T>();

     if (splitPoint < 0)
         splitPoint = 0;

     ListNode* secondhead = split(head_, splitPoint);

     int oldLength = length_;
     if (secondhead == head_) {
         // current list is going to be empty
         head_ = NULL;
         tail_ = NULL;
         length_ = 0;
     } else {
         // set up current list
         tail_ = head_;
         while (tail_->next != NULL)
             tail_ = tail_->next;
         length_ = splitPoint;
     }

     // set up the returned list
     List<T> ret;
     ret.head_ = secondhead;
     ret.tail_ = secondhead;
     if (ret.tail_ != NULL) {
         while (ret.tail_->next != NULL)
             ret.tail_ = ret.tail_->next;
     }
     ret.length_ = oldLength - splitPoint;
     return ret;
 }

 /**
  * Helper function to split a sequence of linked memory at the node
  * splitPoint steps *after* start. In other words, it should disconnect
  * the sequence of linked memory after the given number of nodes, and
  * return a pointer to the starting node of the new sequence of linked
  * memory.
  *
  * This function *SHOULD NOT* create *ANY* new List objects!
  *
  * @param start The node to start from.
  * @param splitPoint The number of steps to walk before splitting.
  * @return The starting node of the sequence that was split off.
  */
 template <class T>
 typename List<T>::ListNode* List<T>::split(ListNode* start, int splitPoint) {

     ListNode* temp2;
     temp2 = start;
     for(int i = 0 ; i<splitPoint; i ++){
       temp2 = temp2->next;
     }

     temp2->prev->next = NULL;
     temp2->prev = NULL;

     return temp2;



 }

 /**
  * Merges the given sorted list into the current sorted list.
  *
  * @param otherList List to be merged into the current list.
  */
 template <class T>
 void List<T>::mergeWith(List<T>& otherList) {
     // set up the current list
     head_ = merge(head_, otherList.head_);
     tail_ = head_;

     // make sure there is a node in the new list
     if (tail_ != NULL) {
         while (tail_->next != NULL)
             tail_ = tail_->next;
     }
     length_ = length_ + otherList.length_;

     // empty out the parameter list
     otherList.head_ = NULL;
     otherList.tail_ = NULL;
     otherList.length_ = 0;
 }

 /**
  * Helper function to merge two *sorted* and *independent* sequences of
  * linked memory. The result should be a single sequence that is itself
  * sorted.
  *
  * This function *SHOULD NOT* create *ANY* new List objects.
  *
  * @param first The starting node of the first sequence.
  * @param second The starting node of the second sequence.
  * @return The starting node of the resulting, sorted sequence.
  */
 template <class T>
 typename List<T>::ListNode* List<T>::merge(ListNode* first, ListNode* second) {
  ListNode* temp1;
  ListNode* temp2;
  ListNode* temp3;
  ListNode* track;
  if(first == NULL){
    return second;
  }

  if(second == NULL){
    return first;
  }

  if(second == NULL && first == NULL){
    return NULL;
  }
  if(first->data < second->data){ // first on one's value is less than second's
    temp1 = second;
    temp2 = first;
    track = first;
  }
  else{
    temp1 = first;
      temp2 = second;
      track = second;
  }
  while(temp2->next != NULL && temp1 != NULL){
    if(temp2->next->data < temp1->data){
          temp2 = temp2->next;
    }
    else{
      temp3 = temp2->next;
      temp2->next = temp1;
      temp1->prev = temp2;
      temp2 = temp1;
      temp1 = temp3;
    }
}
  temp2->next = temp1;
  temp2->prev = NULL;
  return track;
  temp1 = NULL;
  temp2 = NULL;
  temp3 = NULL;
  track = NULL;
}


 /**
  * Sorts the current list by applying the Mergesort algorithm.
  */

 template <class T>
 void List<T>::sort() {
     if (empty())
         return;
     head_ = mergesort(head_, length_);
     tail_ = head_;
     while (tail_->next != NULL)
         tail_ = tail_->next;
 }

 /**
  * Sorts a chain of linked memory given a start node and a size.
  * This is the recursive helper for the Mergesort algorithm (i.e., this is
  * the divide-and-conquer step).
  *
  * @param start Starting point of the chain.
  * @param chainLength Size of the chain to be sorted.
  * @return A pointer to the beginning of the now sorted chain.
  */
 template <class T>
 typename List<T>::ListNode* List<T>::mergesort(ListNode* start, int chainLength) {
    double postLength = chainLength/2;
    ListNode* zstore;
    ListNode* tstore;
    if (chainLength==1){
 		return start;
 	  }
    else if(chainLength!=1){
 		ListNode * h2 = split(start,postLength);
    ListNode * z = mergesort(h2,(chainLength-(postLength)));
    ListNode * t = mergesort(start,postLength);

    zstore = z;
    tstore = t;

 		return (merge(tstore,zstore));
    }
    return NULL;
}
