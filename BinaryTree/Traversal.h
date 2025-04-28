#pragma once
#include <iostream>

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
void InOrder(UNode* _Node)
{
    if (nullptr != _Node)
    {
        InOrder(_Node->Left);
        std::cout << _Node->Data << ", ";
        InOrder(_Node->Right);
    }
}

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