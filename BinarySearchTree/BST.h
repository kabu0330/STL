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
	void Erase(int _Data)
	{
		Root = Erase_Impl(Root, _Data);
	}
private:
	Node* Erase_Impl(Node* _CurNode, int _Data)
	{
		if (nullptr == _CurNode)
		{
			return nullptr;
		}

		int CurData = _CurNode->Data;
		if (_Data < CurData) // �������� �̵�
		{
			_CurNode->Left = Erase_Impl(_CurNode->Left, _Data);
		}
		else if (_Data > CurData) // ���������� �̵�
		{
			_CurNode->Right = Erase_Impl(_CurNode->Right, _Data);
		}
		else // ������ ��带 ã������
		{
			// �ڽ� ��尡 �� �� ������
			Node* LeftChild = _CurNode->Left;
			Node* RightChild = _CurNode->Right;
			if (nullptr != LeftChild && nullptr != RightChild)
			{
				Node* Succ = Successor(_CurNode); // ���� ����� �ּҰ��� ã�´�.
				_CurNode->Data = Succ->Data; // ���� ��ü�ϰ�
				_CurNode->Right = Erase_Impl(_CurNode->Right, Succ->Data); // ������ ��¥ ���� ����� �ּҰ��� �����Ѵ�.
				// �ٽ��� �����͸� �ٲٴ°� �ƴϴ�. �����͸� ��ü�ϰ� �����͸� �������� ���� ����(Leap)�� �����ϴ� ��
			}
			else
			{
				Node* Temp = nullptr;
				if (nullptr == _CurNode->Left)
				{
					Temp = _CurNode->Right;
				}
				else
				{
					Temp = _CurNode->Left;
				}
				delete _CurNode;
				return Temp;
			}
		}
		return _CurNode;
	}
	Node* Successor(Node* _Node)
	{
		Node* CurNode = _Node->Right;
		while (nullptr != CurNode && nullptr != CurNode->Left)
		{
			CurNode = CurNode->Left;
		}
		return CurNode;
	}

public:
	void PreOrder()
	{
		PreOrderRecursive(Root);
	}

private:
	void PreOrderRecursive(Node* _Node)
	{
		if (nullptr != _Node)
		{
			std::cout << _Node->Data << ", ";
			PreOrderRecursive(_Node->Left);
			PreOrderRecursive(_Node->Right);
		}
	}

public:
	void InOrder()
	{
		InOrderRecursive(Root);
	}
private:
	void InOrderRecursive(Node* _Node)
	{
		if (nullptr != _Node)
		{
			InOrderRecursive(_Node->Left);
			std::cout << _Node->Data << ", ";
			InOrderRecursive(_Node->Right);
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