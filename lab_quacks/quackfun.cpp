/**
 * @file quackfun.cpp
 * This is where you will implement the required functions for the
 *  stacks and queues portion of the lab.
 */

namespace QuackFun {

/**
 * Sums items in a stack.
 * @param s A stack holding values to sum.
 * @return The sum of all the elements in the stack, leaving the original
 *  stack in the same state (unchanged).
 *
 * @note You may modify the stack as long as you restore it to its original
 *  values.
 * @note You may use only two local variables of type T in your function.
 *  Note that this function is templatized on the stack's type, so stacks of
 *  objects overloading the + operator can be summed.
 * @note We are using the Standard Template Library (STL) stack in this
 *  problem. Its pop function works a bit differently from the stack we
 *  built. Try searching for "stl stack" to learn how to use it.
 * @hint Think recursively!
 */
template <typename T>
T sum(stack<T>& s){
  if(s.empty() == 1){
      return 0 ;
    }
    else{
      T temp = s.top(); // we are going to store our values before we are popping and push it back to the spot later
      s.pop(); 
      T sumQuack = temp + sum(s);
      s.push(temp); // pushing it back on the top of the stack
      return sumQuack;
    }
}

/**
 * Reverses even sized blocks of items in the queue. Blocks start at size
 * one and increase for each subsequent block.
 * @param q A queue of items to be scrambled
 *
 * @note Any "leftover" numbers should be handled as if their block was
 *  complete.
 * @note We are using the Standard Template Library (STL) queue in this
 *  problem. Its pop function works a bit differently from the stack we
 *  built. Try searching for "stl stack" to learn how to use it.
 * @hint You'll want to make a local stack variable.
 */
template <typename T>
void scramble(queue<T>& q)
{
 	int a=1,b=1,c=1; // initializing our variable a b and c
    stack<T> s;
    // queue<T> q; is optional
    int currSize = q.size(); // size of our stack
       for ( int count=currSize; count>0 ; a++)
	{
		c=a;	   
		b=a;
	   
		if (count-a<0){ 
		   c=count;
		   b=count;
	}		

	if (a % 2 ==0 ){			
	   for (; b > 0 ; b--){
		s.push(q.front() );				
		   q.pop();
		     count--;
		}
	for ( ; c > 0 ; c--){
	    q.push (s.top() );
		s.pop();
		  }	
	}

	if (a % 2 !=0)
	{
	for (; b > 0 ; b--)
	{
	q.push(q.front () );
	q.pop();				
	count--;
	}
	}
	}
		
}

/**
 * @return true if the parameter stack and queue contain only elements of
 *  exactly the same values in exactly the same order; false, otherwise.
 *
 * @note You may assume the stack and queue contain the same number of items!
 * @note There are restrictions for writing this function.
 * - Your function may not use any loops
 * - In your function you may only declare ONE local boolean variable to use in
 *   your return statement, and you may only declare TWO local variables of
 *   parametrized type T to use however you wish.
 * - No other local variables can be used.
 * - After execution of verifySame, the stack and queue must be unchanged. Be
 *   sure to comment your code VERY well.
 */
template <typename T>
bool verifySame(stack<T>& s, queue<T>& q)
{
  if(s.empty())
    return true;
  else{
      T temp1;
      temp1 = s.top();
      s.pop();
      T temp2;
      bool checkvalue = verifySame(s,q);
      temp2 = q.front();
      q.pop();
      q.push(temp2);
      s.push(temp1);
  return (temp1 == temp2)&&checkvalue;
  }
}


}
