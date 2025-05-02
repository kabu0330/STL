#include <iostream>
#include <vector>

int solution(const std::vector<std::vector<int>>& _Path)
{
    int Rows = static_cast<int>(_Path.size());
    int Cols = static_cast<int>(_Path[0].size());

    std::vector<std::vector<int>> Matrix(Rows, std::vector<int>(Cols, 0));
    
    for (int y = 0; y < Rows; y++)
    {
        for (int x = 0; x < Cols; x++)
        {
            if (0 == x && 0 == y) // 시작점 (0, 0)이면
            {
                Matrix[y][x] = _Path[y][x];
            }
            else if (0 == x)
            {
                Matrix[y][x] = Matrix[y - 1][x] + _Path[y][x];
            }
            else if (0 == y)
            {
                Matrix[y][x] = Matrix[y][x - 1] + _Path[y][x];
            }
            else
            {
                Matrix[y][x] = std::min(Matrix[y - 1][x], Matrix[y][x - 1]) + _Path[y][x];
            }
        }
    }
    return Matrix[Rows - 1][Cols - 1];
}

int main()
{
    std::vector<std::vector<int>> Path =
    {
        {2, 7, 5, 4},
        {5, 3, 6, 8},
        {7, 8, 7, 4},
        {8, 1, 9, 5}
    };
    /*  2  9 14 18
    *   7 10 16 24
    *  14 18 23 28
    *  22 19 28 33
    */ 
    

    std::cout << solution(Path) << std::endl;
}
