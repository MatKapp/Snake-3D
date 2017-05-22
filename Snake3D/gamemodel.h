#ifndef gamemodel_H
#define gamemodel_H
#include <list>

#define SIZE 70
enum Direction { up=0, right=1, down=2, left=3 };
enum Element { snake_head, snake_tail, snake_part, fodder, empty, trap, speed_boost, slow_boost};
struct A {
	int array[2];
};

class GameModel {
public:
	//If true, the game is stopped(or finished). If false, the game is on
	bool stopped;
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
	//Probability, that the new fodder will appear
	float fodder_probability;
	//A current number of trap elements.
	int traps;
	//Maximum number of trap elements
	int max_traps;
	//Probability, that the new trap will appear
	float trap_probability;
	//A current number of speed boost elements.
	int speed_boosts;
	//Maximum number of speed boost elements
	int max_speed_boosts;
	//Probability, that the new speed boost will appear
	float speed_boost_probability;
	//A current number of slow boost elements.
	int slow_boosts;
	//Maximum number of slow boost elements
	int max_slow_boosts;
	//Probability, that the new slow boost will appear
	float slow_boost_probability;

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
