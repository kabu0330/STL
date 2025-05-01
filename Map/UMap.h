#pragma once
#include <map>
#include <iostream>

#include <assert.h>
#include <string>
#include <Windows.h>
#define MSGASSERT(VALUE) std::string ErrorText = VALUE; MessageBoxA(nullptr, ErrorText.c_str(), "치명적 에러", MB_OK); assert(false);

using KeyType = int;
using ValueType = int;

class UPair
{
public:
	KeyType first;
	ValueType second;
};

UPair Umake_pair(const KeyType& _Key, const ValueType& _Value)
{
	return { _Key, _Value };
}

class less
{
public:
	bool operator()(int _Left, int _Right)
	{
		return _Left > _Right;
	}
};

class UMap
{
private:
	class UMapNode
	{
		friend UMap;
	private:
		UMapNode* Parent = nullptr;
		UMapNode* LeftChild = nullptr;
		UMapNode* RightChild = nullptr;
		UPair Pair; // Data
	public:
		void ChildRelease(UMapNode* _Node)
		{
			if (_Node == LeftChild)
			{
				LeftChild = nullptr;
				return;
			}
			if (_Node == RightChild)
			{
				RightChild = nullptr;
				return;
			}
		}

		UMapNode* OverParent(const KeyType& _Key)
		{
			if (nullptr != Parent)
			{
				if (Parent->Pair.first > _Key)
				{
					return Parent;
				}
				return Parent->OverParent(_Key);
			}

			return nullptr;
		}
	};

	UMapNode* Root = nullptr;

public:
	class iterator
	{

	};

public:
	void insert(const KeyType& _Key, const ValueType& _Value)
	{
		if (nullptr == Root)
		{
			Root = new UMapNode();
			//Root->Pair = _
		}
	}

	bool IsRotate()
	{
		return false;
	}
};
