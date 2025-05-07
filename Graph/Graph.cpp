#include <iostream>
#include <vector>
#include "DFS.h"
#include "BFS.h"

int main()
{
    std::vector<std::vector<int>> AdjList = { {1, 3, 4}, {0, 2, 4}, {1, 5}, {0, 4}, {0, 1, 3}, {2} };
    DFS_Recursion(AdjList, 0);
    std::cout << std::endl;
    std::vector<int> BFS = BFS_Stack(AdjList, 0);
    for (size_t i = 0; i < BFS.size(); i++)
    {
        std::cout << BFS[i] << ", ";
    }
}

