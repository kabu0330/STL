#include <iostream>
#include <vector>

int Fibo(int _Number)
{
	if (_Number < 2)
	{
		return _Number;
	}
	return Fibo(_Number - 2) + Fibo(_Number - 1);
}

// 하향식(Top-down) 접근 방법
std::vector<int> Memo(100, -1);
int Fibo_Topdown(int _Number)
{
	if (_Number < 2)
	{
		return _Number;
	}

	if (Memo[_Number] != -1) // 이미 계산된 적이 있으면
	{
		return Memo[_Number];
	}

	Memo[_Number] = Fibo_Topdown(_Number - 2) + Fibo_Topdown(_Number - 1);
	return Memo[_Number];
}

int Fibo_Bottomup(int _Number)
{
	std::vector<int> Dp(_Number + 1, 0); // 사용할만큼 모두 0으로 초기화하고 하나씩 값을 채운다.
	Dp[1] = 1; // 기저 조건

	for (int i = 2; i < _Number; i++)
	{
		Dp[i] = Dp[i - 2] + Dp[i - 1];
	}
	return Dp[_Number];
}

int main()
{
	// 0 1 1 2 3 5 8 13 21 34 ...
	std::cout << Fibo(7) << std::endl;
	std::cout << Fibo_Topdown(7) << std::endl;
	std::cout << Fibo_Bottomup(7) << std::endl;
}

