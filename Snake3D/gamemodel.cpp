
#include "gamemodel.h"

GameModel::GameModel()
{
	stopped = false;
	size = SIZE;
	direction = left;
	direction_old = left;
	direction_request = left;

	//Current and max numbers of elements
	fodder = 0;
	max_fodder = 10;
	fodder_probability = 0.25;
	traps = 0;
	max_traps = 8;
	trap_probability = 0.02;
	speed_boosts = 0;
	max_speed_boosts = 1;
	speed_boost_probability = 0.05;
	slow_boosts = 0;
	max_slow_boosts = 1;
	slow_boost_probability = 0.05;

	timeout = 0.2;

	//Create the initial table.
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			elements[i][j] = empty;
		}
	}

	//Determine the initial position of snake.
	snake_positions_y.push_back(4);
	snake_positions_y.push_back(4);
	snake_positions_y.push_back(4);
	snake_positions_x.push_back(4);
	snake_positions_x.push_back(5);
	snake_positions_x.push_back(6);

	elements[4][4] = snake_head;
	elements[4][5] = snake_part;
	elements[4][6] = snake_tail;
	head_position[0] = 4;
	head_position[1] = 4;
	tail_position[0] = 4;
	tail_position[1] = 6;

	head_old_position[0] = 4;
	head_old_position[1] = 4;
	tail_old_position[0] = 4;
	tail_old_position[1] = 6;

	head_visible_position[0] = 4;
	head_visible_position[1] = 4;
	tail_visible_position[0] = 4;
	tail_visible_position[1] = 6;
}