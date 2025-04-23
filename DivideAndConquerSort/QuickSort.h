#pragma once
#include <vector>
#include <algorithm>

void QuickSort(std::vector<int>& _Arr, int _Left, int _Right)
{
	if (_Left >= _Right)
	{
		return;
	}

	int Pivot = _Arr[_Left];
	int LeftIndex = _Left + 1;
	int RightIndex = _Right;

	while (LeftIndex <= RightIndex) // 오른쪽 인덱스가 더 크면
	{
		// 피벗보다 큰 값을 찾을 때까지 오른쪽으로 이동
		while (LeftIndex <= _Right && _Arr[LeftIndex] <= Pivot)
		{
			++LeftIndex;
		}

		// 피벗보다 작은 값을 찾을 때까지 왼쪽으로 이동
		while (RightIndex > _Left && _Arr[RightIndex] >= Pivot)
		{
			--RightIndex;
		}

		// 인덱스가 교차하지 않았다면, 두 인덱스의 값을 스왑
		if (LeftIndex < RightIndex)
		{
			std::swap(_Arr[LeftIndex], _Arr[RightIndex]);
		}
	}

	// 피벗과 RightIndex를 스왑
	std::swap(_Arr[_Left], _Arr[RightIndex]);

	QuickSort(_Arr, _Left, RightIndex - 1);
	QuickSort(_Arr, RightIndex + 1, _Right);

}