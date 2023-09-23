#include "common.h"

int calculateBoardSize(int edgeSize, int numOfEdges = 6)
{
	switch (numOfEdges)
	{
	case 3:
		return static_cast<int>(pow(edgeSize, 2));
		break;
	case 4:
		return static_cast<int>(pow(edgeSize, 2));
		break;
	case 6:
		return 3 * edgeSize * (edgeSize - 1) + 1;
		break;
	default:
		assert(false);
	}
	return 0;
}