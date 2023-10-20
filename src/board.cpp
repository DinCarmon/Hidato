#include "board.h"

Board::Board(int boardSize) {
	this->boardSize = boardSize;
	this->numOfVerticesInBoard = 0;
	this->boardVertices = new Vertex * [boardSize] ();
}


void Board::addVertex(Vertex* ver)
{
	this->boardVertices[numOfVerticesInBoard] = ver;
	this->numOfVerticesInBoard++;
	assert(this->numOfVerticesInBoard <= this->boardSize);
	ver->board = this;
}

SimpleBoard::SimpleBoard(int edgeSize, int numOfEdges = 6) : Board(calculateBoardSize(edgeSize, numOfEdges))
{
	this->edgeSize = edgeSize;
	assert(numOfEdges == 6 || numOfEdges == 4 || numOfEdges == 3);
	this->numOfEdges = numOfEdges;
}

SimpleBoard& GenerateSimpleBoard(int** simpleBoardArr, int numOfEdges, int edgeSize)
{
	assert(numOfEdges == 6 || numOfEdges == 4 || numOfEdges == 3);
	SimpleBoard& board = *(new SimpleBoard(edgeSize, numOfEdges));
	switch (numOfEdges)
	{
		case 3:
		{
			// For now, we support only a triangle with arrow upwards.
			for (int i = 0; i < edgeSize; i++)
			{
				for (int j = 0; j < 2 * i + 1; j++)
				{
					Vertex& v = *(new Vertex(numOfEdges, simpleBoardArr[i][j]));
					board.addVertex(&v);
					if (i > 0 && j % 2 == 1)
					{
						v.CreateNeighbors(board.boardVertices[calculateBoardSize(i - 1, numOfEdges) + j / 2], 0, 1);
						v.CreateNeighbors(board.boardVertices[board.numOfVerticesInBoard - 2], 2, 0);
					}
					if (j > 0 && j % 2 == 0)
					{
						v.CreateNeighbors(board.boardVertices[board.numOfVerticesInBoard - 2], 2, 1);
					}
				}
			}
			break;
		}
		case 4:
		{
			for (int i = 0; i < edgeSize; i++)
			{
				for (int j = 0; j < edgeSize; j++)
				{
					Vertex& v = *(new Vertex(numOfEdges, simpleBoardArr[i][j]));
					board.addVertex(&v);
					if(i > 0)
						v.CreateNeighbors(board.boardVertices[(i - 1) * edgeSize + j], 0, 2);
					if (j > 0)
						v.CreateNeighbors(board.boardVertices[i * edgeSize + j - 1], 2, 1);					
				}
			}
			break;
		}
		case 6:
		{
			// Build Upper half
			for (int i = 0; i < 2 * edgeSize - 1; i++)
			{
				for (int j = 0; j < edgeSize + (edgeSize - 1 - abs(edgeSize - 1 - i)); j++)
				{
					Vertex& v = *(new Vertex(numOfEdges, simpleBoardArr[i][j]));
					board.addVertex(&v);
					if (i > 0)
					{
						if (i < edgeSize)
						{
							v.CreateNeighbors(board.boardVertices[board.numOfVerticesInBoard - (edgeSize + i + 1)], 5, 2);
							v.CreateNeighbors(board.boardVertices[board.numOfVerticesInBoard - (edgeSize + i)], 0, 3);
						}
						else
						{
							v.CreateNeighbors(board.boardVertices[board.numOfVerticesInBoard - (3 * edgeSize - i)], 5, 2);
							v.CreateNeighbors(board.boardVertices[board.numOfVerticesInBoard - (3 * edgeSize - i + 1)], 0, 3);
						}
					}
					if (j > 0)
						v.CreateNeighbors(board.boardVertices[board.numOfVerticesInBoard - 2], 4, 1);
				}
			}
			break;
		}
		default:
		{
			break;
		}
	}
	return board;
}

void PrintBoard(SimpleBoard& board)
{
	switch (board.numOfEdges)
	{
		case 3:
		{
			int idx = 0;
			for (int i = 0; i < board.edgeSize; i++)
			{
				printStr(" ", 5 * (board.edgeSize - i - 1) + 4);
				printStr("^         ", i);
				std::cout << "^" << std::endl;
				printStr(" ", 5 * (board.edgeSize - i - 1) + 3);
				printStr("/ \\       ", i);
				std::cout << "/ \\" << std::endl;
				printStr(" ", 5 * (board.edgeSize - i - 1) + 2);
				for (int j = 0; j < i; j++)
				{
					std::cout << "/ " << board.boardVertices[idx]->num << " \\  " << board.boardVertices[idx + 1]->num << "  ";
					idx += 2;
				}
				
				std::cout << "/ " << board.boardVertices[idx]->num << " \\" << std::endl;
				idx++;
				
				printStr(" ", 5 * (board.edgeSize - i - 1) + 1);
				printStr("/     \\   ", i);
				std::cout << "/     \\" << std::endl;
				printStr(" ", 5 * (board.edgeSize - i - 1));
				printStr("-", 10 * i + 9);
				std::cout << std::endl;
			}
			break;
		}
		case 4:
		{
			for (int j = 0; j < board.edgeSize; j++)
			{
				printStr("-\t-\t", board.edgeSize);
				std::cout << "-" << std::endl;
				printStr("|\t \t", board.edgeSize);
				std::cout << "|" << std::endl;

				for (int i = 0; i < board.edgeSize; i++)
				{
					std::cout << "|\t" << board.boardVertices[j * board.edgeSize + i]->num << "\t";
				}
				std::cout << "|" << std::endl;

				printStr("|\t \t", board.edgeSize);
				std::cout << "|" << std::endl;
			}
			printStr("-\t-\t", board.edgeSize);
			std::cout << "-" << std::endl;
			break;
		}
		case 6:
		{
			break;
		}
		default:
		{
			break;
		}
	}
}