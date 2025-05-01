#pragma once
#include <vector>
#include <stack>

const int Num = 6;
bool bIsVisited[Num] = {};

// 배열로 처리하는 방법
void DFS_Recursion(const std::vector<std::vector<int>>& _Graph, int _Start)
{
	if (true == bIsVisited[_Start])
	{
		return;
	}

	bIsVisited[_Start] = true;
	std::cout << _Start << ", ";
	for (int Value : _Graph[_Start])
	{
		DFS_Recursion(_Graph, Value);
	}
}

// 스택으로 처리하는 방법
std::vector<int> DFS_Stack(const std::vector<std::vector<int>>& _Graph, int _Start)
{
	std::vector<bool> Visited(_Graph.size(), false);
	std::vector<int> VisitOrder;
	std::stack<int> Stack;
	Stack.push(_Start);

	while (true != Stack.empty())
	{
		int CurNode = Stack.top();
		Stack.pop();

		if (true == Visited[CurNode])
		{
			continue;
		}

		Visited[CurNode] = true;
		VisitOrder.push_back(CurNode);

		for (int AdjNode : _Graph[CurNode])
		{
			if (false == Visited[AdjNode])
			{
				Stack.push(AdjNode);
			}
		}
	}

	return VisitOrder;
}