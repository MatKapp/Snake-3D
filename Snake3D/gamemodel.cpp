
#include "gamemodel.h"

GameModel::GameModel()
{
	size = SIZE;
	direction = left;

	//Create the initial table.
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			elements[i][j] = empty;
		}
	}
	elements[4][4] = snake_head;
	elements[4][5] = snake_part;
	elements[4][6] = snake_tail;
	head_position[0] = 4;
	head_position[1] = 4;
	tail_position[0] = 4;
	tail_position[0] = 6;
}