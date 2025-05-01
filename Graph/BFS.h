#pragma once
#include <vector>
#include <queue>

// BFS는 DFS에서 stack이 queue로 바뀐 것 외에 차이가 없다.
std::vector<int> BFS_Stack(const std::vector<std::vector<int>>& _Graph, int _Start)
{
	std::vector<bool> Visited(_Graph.size(), false);
	std::vector<int> VisitOrder;
	std::queue<int> Queue;
	Queue.push(_Start);

	while (true != Queue.empty())
	{
		int CurNode = Queue.back();
		Queue.pop();

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
				Queue.push(AdjNode);
			}
		}
	}

	return VisitOrder;
}