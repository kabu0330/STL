#include <iostream>
#include "BST.h"

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
  
    /*        10
    *     5         15
    * 1      7    13    17
    *   3       11
    */

    BinarySearchTree* BST = new BinarySearchTree();
    BST->Insert(10);
    BST->Insert(5);
    BST->Insert(15);
    BST->Insert(1);
    BST->Insert(3);
    BST->Insert(7);
    BST->Insert(13);
    BST->Insert(11);
    BST->Insert(17);

    if (nullptr != BST->Find(1))
    {
        std::cout << "1 is found" << std::endl;
    }
    else
    {
        std::cout << "1 is not found" << std::endl;
    }

    if (nullptr != BST->Find(12))
    {
        std::cout << "12 is found" << std::endl;
    }
    else
    {
        std::cout << "12 is not found" << std::endl;
    }

    BST->Release();
    int a = 0;
}
