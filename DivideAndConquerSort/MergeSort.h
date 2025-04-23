#pragma once

#include <iostream>
#include <vector>

std::vector<int> Merge(const std::vector<int>& _Left, const std::vector<int>& _Right)
{
	std::vector<int> Result;
	int i = 0;
	int j = 0;
	
	// 두 배열의 크기를 넘지 않는 인덱스까지 반복
	while (i < _Left.size() && j < _Right.size())
	{
		// 두 값을 비교해서 더 작은 값을 Result에 넣는다.
		if (_Left[i] < _Right[j])
		{
			Result.push_back(_Left[i]);
			++i;
		}
		else
		{
			Result.push_back(_Right[j]);
			++j;
		}
	}

	// 남은 한 쪽의 값을 마저 다 넣는다.

	while (i < _Left.size())
	{
		Result.push_back(_Left[i]); 
		++i;
	}

	while (j < _Right.size()) 
	{
		Result.push_back(_Right[j]);
		++j;
	}

	return Result;
}

std::vector<int> MergeSort(const std::vector<int>& _Arr)
{
	// 배열에 하나가 남을때까지 쪼갠다. 
	// 재귀에서는 return 트리거가 매우 중요하다.
	if (_Arr.size() <= 1)
	{
		return _Arr;
	}

	int Mid = _Arr.size() / 2;

	std::vector<int> Left(_Arr.begin(), _Arr.begin() + Mid);
	std::vector<int> Right(_Arr.begin() + Mid, _Arr.end());

	// 좌우 MergeSort가 모두 리턴될 때까지 계속 재귀하여 분할하고 이후 Merge로 병합한다.
	return Merge(MergeSort(Left), MergeSort(Right));
}
