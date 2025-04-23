#pragma once

#include <iostream>
#include <vector>

std::vector<int> Merge(const std::vector<int>& _Left, const std::vector<int>& _Right)
{
	std::vector<int> Result;
	int i = 0;
	int j = 0;
	
	// �� �迭�� ũ�⸦ ���� �ʴ� �ε������� �ݺ�
	while (i < _Left.size() && j < _Right.size())
	{
		// �� ���� ���ؼ� �� ���� ���� Result�� �ִ´�.
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

	// ���� �� ���� ���� ���� �� �ִ´�.

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
	// �迭�� �ϳ��� ���������� �ɰ���. 
	// ��Ϳ����� return Ʈ���Ű� �ſ� �߿��ϴ�.
	if (_Arr.size() <= 1)
	{
		return _Arr;
	}

	int Mid = _Arr.size() / 2;

	std::vector<int> Left(_Arr.begin(), _Arr.begin() + Mid);
	std::vector<int> Right(_Arr.begin() + Mid, _Arr.end());

	// �¿� MergeSort�� ��� ���ϵ� ������ ��� ����Ͽ� �����ϰ� ���� Merge�� �����Ѵ�.
	return Merge(MergeSort(Left), MergeSort(Right));
}
