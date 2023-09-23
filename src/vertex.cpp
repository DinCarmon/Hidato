#include "vertex.h"

Vertex::Vertex(int numOfEdges = 6, int num = -1) {
	this->numOfEdges = numOfEdges;
	this->neighbors = new Vertex* [numOfEdges] ();
	this->numFound = true;
	if (num == -1) {
		this->numFound = false;
	}
	this->num = num;
}

void Vertex::CreateNeighbors(Vertex* neighbor, int neighborIdx, int myIdxForNeighbor)
{
	assert(neighborIdx >= 0 && neighborIdx < this->numOfEdges);
	assert(myIdxForNeighbor >= 0 && myIdxForNeighbor < neighbor->numOfEdges);
	this->neighbors[neighborIdx] = neighbor;
	neighbor->neighbors[myIdxForNeighbor] = this;
}