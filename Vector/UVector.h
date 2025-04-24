#pragma once
#include <vector>

#include <assert.h>
#include <string>
#include <Windows.h>
#define MSGASSERT(VALUE) std::string ErrorText = VALUE; MessageBoxA(nullptr, ErrorText.c_str(), "ġ���� ����", MB_OK); assert(false);

std::vector<int> Test;

//typedef int DataType;
template<typename DataType>
class UVector
{
public:
	UVector() {}
	~UVector()
	{
		if (nullptr != Datas)
		{
			delete[] Datas;
			Datas = nullptr;
		}
	}

	void push_back(DataType _Data)
	{
		// ����� Capacity���� ũ�� Capacity�� Ȯ���Ѵ�.
		// ��ŭ Ȯ���ϴ����� ��Ȯ�� �� �� ����. �ٸ� �� �°� Ȯ���ϱ⺸��, ���� �� �����ְ� �ø���.
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

		DataType* PreveData = Datas; // 1. ������ �����ʹ� �����ϰ�

		Datas = new DataType[_Capacity]; // 2. �޸� ũ�� ���Ҵ��ϰ�

		Capacity = _Capacity; // 3. ũ�� �ø���

		if (nullptr != PreveData)
		{
			// 4. ������ ����
			for (size_t i = 0; i < Size; i++)
			{
				Datas[i] = PreveData[i];
			}
			delete[] PreveData; // 5. ���� �޸� ����
			PreveData = nullptr;
		}
	}

	DataType& operator[](size_t _Index)
	{
		if (Size <= _Index)
		{
			MSGASSERT("vector subscript out of range");
			return DataType();
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
	}

	void resize(size_t _Size)
	{
		// 1. ũ�⸦ ���̴°Ÿ� 
		if (Size > _Size) 
		{
			Size = _Size;
		}

		// 2. ũ�⸦ �ø��°Ÿ� 0���� �ʱ�ȭ
		for (size_t i = 0; i < _Size; i++)
		{
			push_back(0);
		}
	}

private:
	DataType* Datas = nullptr;
	size_t Capacity = 0;
	size_t Size = 0;
};

