#include <iostream>
#include <queue>

template<typename T>
void PrintQueue(T _Queue)
{
	while (true != _Queue.empty())
	{
		std::cout << _Queue.top() << ", ";
		_Queue.pop();
	}
	std::cout << std::endl;
}

int main()
{
    std::vector<int> Vector = { 4, 2, 5, 1, 3 };
    std::priority_queue<int> PriorityQueue(Vector.begin(), Vector.end());
	PrintQueue(PriorityQueue);
    
	std::priority_queue<int, std::vector<int>, std::greater<>> GreaterPriorityQueue(Vector.begin(), Vector.end());
	PrintQueue(GreaterPriorityQueue);
}

