#pragma once
#include <vector>

#include <assert.h>
#include <string>
#include <Windows.h>
#define MSGASSERT(VALUE) std::string ErrorText = VALUE; MessageBoxA(nullptr, ErrorText.c_str(), "치명적 에러", MB_OK); assert(false);

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
		// 사이즈가 Capacity보다 크면 Capacity를 확장한다.
		// 얼만큼 확장하는지는 정확히 알 수 없다. 다만 딱 맞게 확장하기보단, 조금 더 여유있게 늘린다.
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
			return; // 기존보다 적은 크기를 확보 요청한 경우 무시
		}

		DataType* PreveData = Datas; // 1. 기존의 데이터는 유지하고

		Datas = new DataType[_Capacity]; // 2. 메모리 크기 재할당하고

		Capacity = _Capacity; // 3. 크기 늘리고

		if (nullptr != PreveData)
		{
			// 4. 데이터 복사
			for (size_t i = 0; i < Size; i++)
			{
				Datas[i] = PreveData[i];
			}
			delete[] PreveData; // 5. 기존 메모리 삭제
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
		// capacity는 초기화 안한다.
	}

	void resize(size_t _Size)
	{
		// 1. 크기를 줄이는거면 
		if (Size > _Size) 
		{
			Size = _Size;
		}

		// 2. 크기를 늘리는거면 0으로 초기화
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

