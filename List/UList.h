#pragma once
#include <assert.h>
#include <string>
#include <Windows.h>
#define MSGASSERT(VALUE) std::string ErrorText = VALUE; MessageBoxA(nullptr, ErrorText.c_str(), "ġ���� ����", MB_OK); assert(false);

using DataType = int;

//template<typename DataType>
class UList
{
	// UList�� Head, Tail �����͸� ������ �ְ�
	// UListNode�� Data�� Prev, Next ��� �����͸� ������ �ִ�.
	// iterator�� UListNode* �� �ϳ��� ������ �ְ�, �����ڸ� ���� Next�� �̵��ϰų� Data�� ������ �� �ִ�.
public:
	class UListNode
	{
		friend UList;
		friend class iterator;
	public:
		void Release()
		{
			if (nullptr != Next)
			{
				Next->Release(); // ���⼭ ��Ͱ� �ɸ���
			}

			// �� ���� nullptr�� �����ϴ� ���� ������ ��� ������ �� �ڿ������� ���ŵȴ�.
			delete this; 
		}

		bool operator==(const UListNode& _Other)
		{
			return *this == _Other;
		}
	private:
		UListNode* Prev = nullptr;
		UListNode* Next = nullptr;
		DataType Data;
	};

	class iterator
	{
		//friend UListNode;
		friend UList;
	public:
		iterator() {}
		
		bool operator!=(const iterator& _Other)
		{
			return CurNode != _Other.CurNode;
		}

		DataType& operator*()
		{
			return CurNode->Data;
		}
		
		iterator& operator++()
		{
			if (nullptr == CurNode)
			{
				MSGASSERT("cannot decrement null iterator");
			}

			CurNode = CurNode->Next;
			if (nullptr == CurNode)
			{
				MSGASSERT("cannot increment end list iterator");
			}
			return *this;
		}

		iterator& operator--()
		{
			if (nullptr == CurNode)
			{
				MSGASSERT("cannot decrement null iterator");
			}

			CurNode = CurNode->Prev;
			if (nullptr == CurNode)
			{
				MSGASSERT("decremented before head node");
			}
			return *this;
		}

	private:
		iterator(UListNode* _Node)
			:CurNode(_Node)
		{

		}

	private:
		UListNode* CurNode = nullptr;
	};

public:
	UList()
	{
		HeadNode = new UListNode();
		TailNode = new UListNode();

		HeadNode->Next = TailNode;
		TailNode->Prev = HeadNode;

		// Debug
		HeadNode->Data = -1;
		TailNode->Data = -1;
	}

	~UList()
	{
		HeadNode->Release(); // ���
	}

	void push_back(const DataType& _Data)
	{
		UListNode* NewNode = new UListNode();
		NewNode->Data = _Data;

		// ������ �н��� �����ϸ� �������� �����͸� �ٲ��ش�.
		NewNode->Next = TailNode;
		NewNode->Prev = TailNode->Prev;

		TailNode->Prev->Next = NewNode;
		TailNode->Prev = NewNode;
	}

	void push_front(const DataType& _Data)
	{
		UListNode* NewNode = new UListNode();
		NewNode->Data = _Data;
		
		NewNode->Prev = HeadNode;
		NewNode->Next = HeadNode->Next;

		HeadNode->Next->Prev = NewNode;
		HeadNode->Next = NewNode;
	}

	void pop_back()
	{
		UListNode* Node = TailNode->Prev;
		if (HeadNode == Node) // ��尡 �ϳ��� ���ٸ�
		{
			MSGASSERT("pop_back called on empty list");
			return;
		}

		Node->Prev->Next = TailNode;
		TailNode->Prev = Node->Prev;

		delete Node;
		Node = nullptr;
	}
	
	void pop_front()
	{
		UListNode* Node = HeadNode->Next;
		if (TailNode == Node) // ��尡 �ϳ��� ���ٸ�
		{
			MSGASSERT("pop_front called on empty list");
			return;
		}
		
		Node->Next->Prev = HeadNode;
		HeadNode->Next = Node->Next;

		delete Node;
		Node = nullptr;
	}

	void clear()
	{
		UListNode* CurNode = HeadNode->Next;
		while (CurNode != TailNode)
		{
			UListNode* NextNode = CurNode->Next;

			delete CurNode;
			CurNode = nullptr;

			CurNode = NextNode;
		}
	}

	// _Pos �ٷ� �տ� ����
	iterator insert(iterator _Pos, DataType _Data)
	{
		UListNode* TargetNode = _Pos.CurNode;
		UListNode* NewNode = new UListNode();
		NewNode->Data = _Data;

		NewNode->Prev = TargetNode->Prev;
		NewNode->Next = TargetNode;

		TargetNode->Prev->Next = NewNode;
		TargetNode->Prev = NewNode;

		return iterator(NewNode);
	}

	iterator begin()
	{
		return iterator(HeadNode->Next);
	}
	iterator end()
	{
		return iterator(TailNode);
	}

	iterator erase(iterator& _Data)
	{
		UListNode* CurNode = _Data.CurNode;
		if (nullptr == CurNode)
		{
			MSGASSERT("_Insert_after is nullptr // ����� ��尡 �����ϴ�.");
			return iterator();
		} 
		if (CurNode == HeadNode)
		{
			MSGASSERT("������ �� ���� ����� ��");
			return iterator();
		}
		if (CurNode == TailNode)
		{
			MSGASSERT("_Insert_after is nullptr // TailNode�� ������ �� �����ϴ�.");
			return iterator();
		}

		UListNode* ReturnNode = CurNode->Next;
		ReturnNode->Prev = CurNode->Prev;
		CurNode->Prev->Next = ReturnNode;

		delete CurNode;
		CurNode = nullptr;

		return iterator(ReturnNode);
	}

	size_t size()
	{
		size_t Count = 0;
		UListNode* CurNode = HeadNode->Next;
		while (CurNode != TailNode)
		{
			CurNode = CurNode->Next;
			++Count;
		}
		return Count;
	}

private:
	UListNode* HeadNode = nullptr;
	UListNode* TailNode = nullptr;
};

