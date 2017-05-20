#ifndef gamemodel_H
#define gamemodel_H
#include <list>

#define SIZE 35
enum Direction { up=0, right=1, down=2, left=3 };
enum Element { snake_head, snake_tail, snake_part, fodder, empty };
struct A {
	int array[2];
};

class GameModel {
public:
	//Size of a map.
	int size;
	//A time which passes before a snake moves from one place to another (in seconds?).
	float timeout;
	//A direction in which the snake currently moves.
	Direction direction;
	//A direction in which the snake moved last time.
	Direction direction_old;
	//A direction in which player wants to go.
	Direction direction_request;
	//A current number of fodder elements.
	int fodder;
	//Maximum number of fodder elements
	int max_fodder;
	//A map with all of the elements in the game.
	Element elements[SIZE][SIZE];
	//Location of a camera
	Direction camera_location;

	//Positions of the body of the snake.
	//At index 0 we have the position of the head, at last position - of the tail.
	std::list<int> snake_positions_y;
	std::list<int> snake_positions_x;
	int head_position[2];
	int tail_position[2];

	//Positions of head and tail from last round
	int head_old_position[2];
	int tail_old_position[2];

	//Positions of head and tail from last round
	float head_visible_position[2];
	float tail_visible_position[2];

	GameModel();
};

#endif
