#pragma once
#include <assert.h>
#include <string>
#include <Windows.h>
#define MSGASSERT(VALUE) std::string ErrorText = VALUE; MessageBoxA(nullptr, ErrorText.c_str(), "치명적 에러", MB_OK); assert(false);

using DataType = int;

//template<typename DataType>
class UList
{
	// UList는 Head, Tail 포인터만 가지고 있고
	// UListNode는 Data와 Prev, Next 노드 포인터를 가지고 있다.
	// iterator는 UListNode* 를 하나만 가지고 있고, 연산자를 통해 Next로 이동하거나 Data를 내어줄 수 있다.
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
				Next->Release(); // 여기서 재귀가 걸리고
			}

			// 맨 끝의 nullptr을 마주하는 순간 스택의 모든 노드들이 맨 뒤에서부터 제거된다.
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
		HeadNode->Release(); // 재귀
	}

	void push_back(const DataType& _Data)
	{
		UListNode* NewNode = new UListNode();
		NewNode->Data = _Data;

		// 포인터 분실을 조심하며 논리적으로 포인터를 바꿔준다.
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
		if (HeadNode == Node) // 노드가 하나도 없다면
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
		if (TailNode == Node) // 노드가 하나도 없다면
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

	// _Pos 바로 앞에 삽입
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
			MSGASSERT("_Insert_after is nullptr // 연결된 노드가 없습니다.");
			return iterator();
		} 
		if (CurNode == HeadNode)
		{
			MSGASSERT("존재할 수 없는 경우의 수");
			return iterator();
		}
		if (CurNode == TailNode)
		{
			MSGASSERT("_Insert_after is nullptr // TailNode를 삭제할 수 없습니다.");
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

