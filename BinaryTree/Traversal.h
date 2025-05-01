#pragma once
#include <iostream>
#include <queue>

void Release(class UNode* _Node);

class UNode
{
public:
    char Data;
    UNode* Left = nullptr;
    UNode* Right = nullptr;

    UNode(char _Data)
    {
        Data = _Data;
    }
    //~UNode()
    //{
    //    Release(this);
    //}
};

// 전위 순회
// 1. 현재 노드
// 2. 왼쪽 서브트리
// 3. 오른쪽 서브트리
// 트리 복사
void PreOrder(UNode* _Node)
{
    if (nullptr != _Node)
    {
        std::cout << _Node->Data << ", ";
        PreOrder(_Node->Left);
        PreOrder(_Node->Right);
    }
}

// 중위 순회
// 1. 왼쪽 서브트리
// 2. 현재 노드
// 3. 오른쪽 서브트리
// 오름차순, 내림차순으로 구현해야 할 때
void InOrder(UNode* _Node)
{
    if (nullptr != _Node)
    {
        InOrder(_Node->Left);
        std::cout << _Node->Data << ", ";
        InOrder(_Node->Right);
    }
}

// 후위 순회
// 1. 왼쪽 서브트리
// 2. 오른쪽 서브트리
// 3. 현재 노드
// delete 방식에 적합
void PostOrder(UNode* _Node)
{
    if (nullptr != _Node)
    {
        PostOrder(_Node->Left);
        PostOrder(_Node->Right);
        std::cout << _Node->Data << ", ";
    }
}

void Release(UNode* _Node)
{
    if (nullptr != _Node)
    {
        Release(_Node->Left);
        Release(_Node->Right);
        delete _Node;
    }
}

void LevelOrder(UNode* _Node)
{
    std::cout << "레벨 순서 순회" << std::endl;
    // 시작이 항상 Root에서 왼쪽부터 push하기 때문에 오름차순으로 처리된다.
    std::queue<UNode*> Queue;
    Queue.push(_Node);
    
    while (true != Queue.empty())
    {
        UNode* CurNode = Queue.front();
        Queue.pop();

        std::cout << CurNode->Data << ", "; // 로직
        if (nullptr != CurNode->Left)
        {
            Queue.push(CurNode->Left);
        }
        if (nullptr != CurNode->Right)
        {
            Queue.push(CurNode->Right);
        }
    }
}