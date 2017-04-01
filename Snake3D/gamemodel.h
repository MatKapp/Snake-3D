#ifndef gamemodel_H
#define gamemodel_H

#define SIZE 40
enum Direction { up, right, down, left };
enum Element { snake_head, snake_tail, snake_part, fodder, empty };

class GameModel {
public:
	int size;
	Direction direction;
	Element elements[SIZE][SIZE];
	int head_position[2];
	int tail_position[2];

	GameModel();
};

#endif
