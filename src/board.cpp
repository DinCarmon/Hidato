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
	assert(this->numOfVerticesInBoard < this->boardSize);
	ver->board = this;
}

SimpleBoard::SimpleBoard(int edgeSize, int numOfEdges = 6) : Board(calculateBoardSize(edgeSize, numOfEdges))
{
	this->edgeSize = edgeSize;
	assert(numOfEdges == 6 || numOfEdges == 4 || numOfEdges == 3);
	this->numOfEdges = numOfEdges;
}