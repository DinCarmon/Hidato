#include "common.h"
#include "board.h"

int main()
{
    std::cout << "Hello World" << std::endl;

    int a1[] = {1, 2};
    int a2[] = { 4, 3 };
    int* board1Arr[] = {a1, a2};
    SimpleBoard& board1 = GenerateSimpleBoard(board1Arr, 4, 2);
    PrintBoard(board1);
    int b1[] = { 1 };
    int b2[] = { 2, 3, 4 };
    int b3[] = { 5, 6, 7, 8, 9 };
    int* board2Arr[] = { b1, b2, b3 };
    SimpleBoard& board2 = GenerateSimpleBoard(board2Arr, 3, 3);
    PrintBoard(board2);

}