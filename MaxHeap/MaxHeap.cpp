#include <iostream>
#include "MaxHeap.h"

int main()
{
	/*			 15
	*	    10        14
	*	 8     7    5    9
	*  3
	*/
	UMaxHeap MaxHeap;
	MaxHeap.Push(7);
	MaxHeap.Push(10);
	MaxHeap.Push(5);
	MaxHeap.Push(3);
	MaxHeap.Push(14);
	MaxHeap.Push(15);
	MaxHeap.Push(9);
	MaxHeap.Push(8);

	MaxHeap.PreOrder();
	MaxHeap.PrintArr();
	                        
	MaxHeap.Pop();
	MaxHeap.PrintArr();
}
