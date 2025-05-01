#pragma once
#include <iostream>
#include <vector>


class UMaxHeap
{
private:
	std::vector<int> Heap = std::vector<int>(1);
public:
	// 힙의 원소 삽입
	// 1. 힙의 맨 마지막에 새로운 노드를 추가
	void Push(int _Value)
	{
		Heap.push_back(_Value);
		HeapifyUp(Heap.size() - 1);
	}
private:
	void HeapifyUp(int _Index)
	{
		// 2. 새 노드와 부모 노드를 서로 비교하여 힙 속성(MaxHeap)에 맞지 않으면 스왑 반복
		int ParentIndex = Parent(_Index);
		int ParentValue = Heap[ParentIndex];
		int CurValue = Heap[_Index];
		// 루트 외의 값이 존재하고, 힙 속성(큰 값이 부모) 기준에 부합하지 않으면
		if (1 < _Index && CurValue > ParentValue) 
		{
			std::swap(Heap[_Index], Heap[ParentIndex]); // 스왑하고
			HeapifyUp(ParentIndex); // 다시 부모와 비교
		}
	}
public:
	// Max == Root를 제거한다.
	// 1. 마지막 노드 값을 루트 값으로 복사
	// 2. 마지막 노드 삭제
	// 3. 자식을 돌며 최댓값과 스왑 반복
	void Pop()
	{
		if (Heap.size() > 1)
		{
			Heap[1] = Heap.back();
			Heap.pop_back();
			HeapifyDown(1);
		}
	}
private:
	void HeapifyDown(int _Index)
	{
		int Largest = _Index;
		int LeftIndex = LeftChild(Largest);
		int RightIndex = LeftChild(Largest);

		// 왼쪽 값이 부모보다 크면
		if (LeftIndex < Heap.size() && Heap[LeftIndex] > Heap[Largest])
		{
			Largest = LeftIndex;
		}
		// 오른쪽 값이 부모 또는 왼쪽보다 크면
		if (RightIndex < Heap.size() && Heap[RightIndex > Heap[Largest]])
		{
			Largest = RightIndex;
		}

		// 인덱스가 바뀌어야 하면 값을 스왑하고 다시 재귀
		if (Largest != _Index)
		{
			std::swap(Heap[_Index], Heap[Largest]);
			HeapifyDown(Largest);
		}
	}

public:
	// Index
	// 루트		  : 항상 1
	// 부모		  : m / 2
	// 왼쪽 자식   : m * 2
	// 오른쪽 자식 : m * 2 + 1
	int Parent(int _Index)
	{
		return _Index / 2; // 소수점은 버림처리
	}
	int LeftChild(int _ParentIndex)
	{
		return _ParentIndex * 2;
	}
	int RightChild(int _ParentChild)
	{
		return _ParentChild * 2 + 1;
	}

	int Size()
	{
		return Heap.size() - 1;
	}
	int Top()
	{
		if (1 < Size())
		{
			return Heap[1];
		}
	}
	bool Empty()
	{
		return Heap.size() == 1;
	}

public:
	void PreOrder()
	{
		PreOrderRecusive(1);
		std::cout << std::endl;
	}
private:
	void PreOrderRecusive(int _Index)
	{
		if (1 <= _Index && _Index < Heap.size())
		{
			std::cout << Heap[_Index] << ", ";
			PreOrderRecusive(_Index * 2);
			PreOrderRecusive(_Index * 2 + 1);
		}
	}
public:
	void PrintArr()
	{
		std::cout << std::endl;
		std::cout << "배열 인덱스 순서" << std::endl;
		for (size_t i = 1; i < Heap.size(); i++)
		{
			std::cout << Heap[i] << ", ";
		}
	}
};