#ifndef gamemodel_H
#define gamemodel_H
#include <list>

#define SIZE 20
enum Direction { up, right, down, left };
enum Element { snake_head, snake_tail, snake_part, fodder, empty };
struct A {
	int array[2];
};

class GameModel {
public:
	//Size of a map.
	int size;
	//A time which passes before a snake moves from one place to another (in seconds?).
	float timeout = 0.1;
	//A direction in which the snake currently moves.
	Direction direction;
	//A direction in which player wants to go.
	Direction direction_request;
	//A maximal number of fodder elements.
	int fodder = 0;
	//A map with all of the elements in the game.
	Element elements[SIZE][SIZE];

	//Positions of the body of the snake.
	//At index 0 we have the position of the head, at last position - of the tail.
	std::list<int> snake_positions_y;
	std::list<int> snake_positions_x;
	int head_position[2];
	int tail_position[2];

	GameModel();
};

#endif
