#ifndef BOARD_H

#include "common.h"
#include "vertex.h"

class Board {
public:
	int boardSize;
	int numOfVerticesInBoard;	// How many vertices were already added to the board.
	Vertex** boardVertices;

	Board(int boardSize);
	void addVertex(Vertex* ver);
};

/*
*	A simple board like a hive / table / triangle
*/
class SimpleBoard : public Board {
public:
	int numOfEdges;
	int edgeSize;

	SimpleBoard(int edgeSize, int numOfEdges);
};

SimpleBoard& GenerateSimpleBoard(int** simpleBoardArr, int numOfEdges, int edgeSize);
void PrintBoard(SimpleBoard& board);


#endif // !BOARD_H


