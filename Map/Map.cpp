#include <iostream>
#include <map>

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    std::map<int, int> Map;
    Map.insert(1, 10);
}
