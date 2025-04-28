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

// ���� ��ȸ
// 1. ���� ���
// 2. ���� ����Ʈ��
// 3. ������ ����Ʈ��
void PreOrder(UNode* _Node)
{
    if (nullptr != _Node)
    {
        std::cout << _Node->Data << ", ";
        PreOrder(_Node->Left);
        PreOrder(_Node->Right);
    }
}

// ���� ��ȸ
// 1. ���� ����Ʈ��
// 2. ���� ���
// 3. ������ ����Ʈ��
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