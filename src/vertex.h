#include "common.h"

class Board;

class Vertex {
public:
    bool numFound;
    int num;
    int numOfEdges;

    /*
    * Holds an array of vertex neighbors.
    * 1. An empty neighbor (an edge of the board) shall be a null pointer.
    * 2. Order of neigbors is from the neighbor above clockwise.
    */ 
    Vertex** neighbors;
    Board* board;

    Vertex(int numOfEdges, int num);
    void CreateNeighbors(Vertex* neighbor, int neighborIdx, int myIdxForNeighbor);
};