#pragma once
#include <assert.h>
#include <vector>

#include <string>
#include <Windows.h>
#define MSGASSERT(VALUE) std::string ErrorText = VALUE; MessageBoxA(nullptr, ErrorText.c_str(), "ġ���� ����", MB_OK); assert(false);

std::vector<int> Test;


//typedef int DataType;
template<typename DataType>
class Uvector
{
public:
	Uvector() {}

	void push_back(DataType _Data)
	{
		// ����� Capacity���� ũ�� Capacity�� Ȯ���Ѵ�.
		// ��ŭ Ȯ���ϴ��� ��Ȯ�� ������ �𸥴�. �ٸ� �� �°� Ȯ���ϱ⺸��, ���� �� �����ְ� �ø���.
		if (Size + 1 > Capacity)
		{
			reserve((Capacity * static_cast<size_t>(1.5)) + 1);
		}

		Datas[Size] = _Data;
		++Size;
	}

	void reserve(size_t _Capacity)
	{
		if (Capacity > _Capacity)
		{
			return; // �������� ���� ũ�⸦ Ȯ�� ��û�� ��� ����
		}

		DataType* PrevData = Datas; // ������ �����ʹ� �����ϰ�

		Datas = new DataType[_Capacity]; // �޸� ũ�� ���Ҵ��ϰ�

		Capacity = _Capacity; // ũ�� �ø���

		if (nullptr != PrevData)
		{
			// ������ ����
			for (size_t i = 0; i < Size; i++)
			{
				Datas[i] = PrevData[i];
			}
			delete[] PrevData; // ���� �޸� ����
			PrevData = nullptr;
		}
	}

	DataType& operator[](size_t _Index)
	{
		if (Size <= _Index)
		{
			MSGASSERT("���� ũ�⸦ �ʰ��� �ε��� �����Դϴ�.");
		}
		return Datas[_Index];
	}

	size_t size() const
	{
		return Size;
	}

	size_t capacity() const
	{
		return Capacity;
	}

	void clear()
	{
		Size = 0; 
		// capacity�� �ʱ�ȭ ���Ѵ�.

		// ���Ҵ��� �ʿ��ؼ� ������
		//delete[] Datas;
		//Datas = nullptr;
	}

	// constrcuter destructer
	~Uvector()
	{
		if (nullptr != Datas)
		{
			delete[] Datas;
			Datas = nullptr;
		}
	}

private:
	DataType* Datas = nullptr;
	size_t Capacity = 0;
	size_t Size = 0;

	// delete Function
	Uvector(const Uvector& _Other) = delete;
	Uvector(Uvector&& _Other) noexcept = delete;
	Uvector& operator=(const Uvector& _Other) = delete;
	Uvector& operator=(Uvector&& _Other) noexcept = delete;

};

