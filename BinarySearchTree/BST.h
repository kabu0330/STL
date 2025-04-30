#pragma once

struct Node
{
	int Data;
	Node* Left = nullptr;
	Node* Right = nullptr;

	Node(int _Data)
	{
		Data = _Data;
	}
};

class BinarySearchTree
{
private:
	Node* Root = nullptr;

public:
	void Insert(int _Data)
	{
		if (nullptr == Root)
		{
			Root = new Node(_Data);
		}
		else
		{
			Insert_Impl(Root, _Data);
		}
	}
private:
	void Insert_Impl(Node* _CurNode, int _Data)
	{
		int RootData = _CurNode->Data;
		if (_Data < RootData) // ��Ʈ���� ������ ��������
		{
			if (nullptr == _CurNode->Left) // ��尡 ������� ����!
			{
				_CurNode->Left = new Node(_Data);
			}
			else // �� ��带 ã�� ������ ���
			{
				Insert_Impl(_CurNode->Left, _Data);
			}
		}
		else // ��Ʈ���� ũ�� ������
		{
			if (nullptr == _CurNode->Right)
			{
				_CurNode->Right = new Node(_Data);
			}
			else
			{
				Insert_Impl(_CurNode->Right, _Data);
			}
		}
	}

public:
	Node* Find(int _Data)
	{
		return Find_Impl(Root, _Data);
	}
private:
	Node* Find_Impl(Node* _CurNode, int _Data)
	{
		if (nullptr == _CurNode)
		{
			return nullptr;
		}

		int CurValue = _CurNode->Data;
		if (_Data == CurValue)
		{
			return _CurNode;
		}
		else
		{
			if (_Data < CurValue)
			{
				return Find_Impl(_CurNode->Left, _Data);
			}
			else
			{
				return Find_Impl(_CurNode->Right, _Data);
			}
		}
	}

public:
	void Release()
	{
		ReleaseRecursive(Root);
		if (nullptr != this)
		{
			delete this;
		}
	}

private:
	void ReleaseRecursive(Node* _Node)
	{
		if (nullptr != _Node)
		{
			ReleaseRecursive(_Node->Left);
			ReleaseRecursive(_Node->Right);
			delete _Node;
		}
	}
};