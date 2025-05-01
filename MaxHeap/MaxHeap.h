#pragma once
#include <iostream>
#include <vector>


class UMaxHeap
{
private:
	std::vector<int> Heap = std::vector<int>(1);
public:
	// ���� ���� ����
	// 1. ���� �� �������� ���ο� ��带 �߰�
	void Push(int _Value)
	{
		Heap.push_back(_Value);
		HeapifyUp(Heap.size() - 1);
	}
private:
	void HeapifyUp(int _Index)
	{
		// 2. �� ���� �θ� ��带 ���� ���Ͽ� �� �Ӽ�(MaxHeap)�� ���� ������ ���� �ݺ�
		int ParentIndex = Parent(_Index);
		int ParentValue = Heap[ParentIndex];
		int CurValue = Heap[_Index];
		// ��Ʈ ���� ���� �����ϰ�, �� �Ӽ�(ū ���� �θ�) ���ؿ� �������� ������
		if (1 < _Index && CurValue > ParentValue) 
		{
			std::swap(Heap[_Index], Heap[ParentIndex]); // �����ϰ�
			HeapifyUp(ParentIndex); // �ٽ� �θ�� ��
		}
	}
public:
	// Max == Root�� �����Ѵ�.
	// 1. ������ ��� ���� ��Ʈ ������ ����
	// 2. ������ ��� ����
	// 3. �ڽ��� ���� �ִ񰪰� ���� �ݺ�
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

		// ���� ���� �θ𺸴� ũ��
		if (LeftIndex < Heap.size() && Heap[LeftIndex] > Heap[Largest])
		{
			Largest = LeftIndex;
		}
		// ������ ���� �θ� �Ǵ� ���ʺ��� ũ��
		if (RightIndex < Heap.size() && Heap[RightIndex > Heap[Largest]])
		{
			Largest = RightIndex;
		}

		// �ε����� �ٲ��� �ϸ� ���� �����ϰ� �ٽ� ���
		if (Largest != _Index)
		{
			std::swap(Heap[_Index], Heap[Largest]);
			HeapifyDown(Largest);
		}
	}

public:
	// Index
	// ��Ʈ		  : �׻� 1
	// �θ�		  : m / 2
	// ���� �ڽ�   : m * 2
	// ������ �ڽ� : m * 2 + 1
	int Parent(int _Index)
	{
		return _Index / 2; // �Ҽ����� ����ó��
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
		std::cout << "�迭 �ε��� ����" << std::endl;
		for (size_t i = 1; i < Heap.size(); i++)
		{
			std::cout << Heap[i] << ", ";
		}
	}
};