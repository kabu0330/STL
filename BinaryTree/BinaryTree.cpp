#include <iostream>
#include "Traversal.h"

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    /*     A
    *   B     C
    * D   E     F
    */
    UNode* Root = new UNode('A');
    UNode* LeftChild = Root->Left = new UNode('B');
    UNode* RightChild = Root->Right = new UNode('C');
    LeftChild->Left = new UNode('D');
    LeftChild->Right = new UNode('E');
    RightChild->Right = new UNode('F');

    std::cout << "전위 순회" << std::endl;
    PreOrder(Root);
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "중위 순회" << std::endl;
    InOrder(Root);
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "후위 순회" << std::endl;
    PostOrder(Root);
    std::cout << std::endl;
    std::cout << std::endl;

    Release(Root);
}

