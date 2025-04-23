#pragma once
#include <assert.h>
#include <vector>

#include <string>
#include <Windows.h>
#define MSGASSERT(VALUE) std::string ErrorText = VALUE; MessageBoxA(nullptr, ErrorText.c_str(), "치명적 에러", MB_OK); assert(false);

std::vector<int> Test;


//typedef int DataType;
template<typename DataType>
class Uvector
{
public:
	Uvector() {}

	void push_back(DataType _Data)
	{
		// 사이즈가 Capacity보다 크면 Capacity를 확장한다.
		// 얼만큼 확장하는지 정확한 로직은 모른다. 다만 딱 맞게 확장하기보단, 조금 더 여유있게 늘린다.
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

		DataType* PrevData = Datas; // 기존의 데이터는 유지하고

		Datas = new DataType[_Capacity]; // 메모리 크기 재할당하고

		Capacity = _Capacity; // 크기 늘리고

		if (nullptr != PrevData)
		{
			// 데이터 복사
			for (size_t i = 0; i < Size; i++)
			{
				Datas[i] = PrevData[i];
			}
			delete[] PrevData; // 기존 메모리 삭제
			PrevData = nullptr;
		}
	}

	DataType& operator[](size_t _Index)
	{
		if (Size <= _Index)
		{
			MSGASSERT("벡터 크기를 초과한 인덱스 접근입니다.");
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

		// 재할당이 필요해서 위험함
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

