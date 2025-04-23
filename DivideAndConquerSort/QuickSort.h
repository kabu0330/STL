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

	while (LeftIndex <= RightIndex) // ������ �ε����� �� ũ��
	{
		// �ǹ����� ū ���� ã�� ������ ���������� �̵�
		while (LeftIndex <= _Right && _Arr[LeftIndex] <= Pivot)
		{
			++LeftIndex;
		}

		// �ǹ����� ���� ���� ã�� ������ �������� �̵�
		while (RightIndex > _Left && _Arr[RightIndex] >= Pivot)
		{
			--RightIndex;
		}

		// �ε����� �������� �ʾҴٸ�, �� �ε����� ���� ����
		if (LeftIndex < RightIndex)
		{
			std::swap(_Arr[LeftIndex], _Arr[RightIndex]);
		}
	}

	// �ǹ��� RightIndex�� ����
	std::swap(_Arr[_Left], _Arr[RightIndex]);

	QuickSort(_Arr, _Left, RightIndex - 1);
	QuickSort(_Arr, RightIndex + 1, _Right);

}