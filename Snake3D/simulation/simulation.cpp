#include "simulation.h"

//Move the snake.
Element move_snake(GameModel *model)
{
	//This variable stores the element to which the head of the snake moves.
	Element eaten_element;

	//Update the direction. Set the direction to the direction where player wants to go.
	model->direction = model->direction_request;

	//Move head.
	model->elements[model->head_position[0]][model->head_position[1]] = snake_part;
	if (model->direction == right)
	{
		model->head_position[1]++;
		//Go through the magic wall
		if (model->head_position[1] == model->size) {
			model->head_position[1] = 0;
		}
	}
	else if (model->direction == left)
	{
		model->head_position[1]--;
		//Go through the magic wall
		if (model->head_position[1] == -1) {
			model->head_position[1] = model->size - 1;
		}
	}
	else if (model->direction == up)
	{
		model->head_position[0]++;
		//Go through the magic wall
		if (model->head_position[0] == model->size) {
			model->head_position[0] = 0;
		}
	}
	else if (model->direction == down)
	{
		model->head_position[0]--;
		//Go through the magic wall
		if (model->head_position[0] == -1) {
			model->head_position[0] = model->size - 1;
		}
	}

	//Store an element to which the head of the snake moves.
	eaten_element = model->elements[model->head_position[0]][model->head_position[1]];

	//Set new head.
	model->elements[model->head_position[0]][model->head_position[1]] = snake_head;
	model->snake_positions_y.push_front(model->head_position[0]);
	model->snake_positions_x.push_front(model->head_position[1]);

	//Delete the tail only if snake didn't eat a fodder.
	if (eaten_element != fodder)
	{
		//Delete the tail
		model->elements[model->tail_position[0]][model->tail_position[1]] = empty;
		model->snake_positions_y.pop_back();
		model->snake_positions_x.pop_back();

		//Set new tail.
		model->tail_position[0] = model->snake_positions_y.back();
		model->tail_position[1] = model->snake_positions_x.back();
		model->elements[model->tail_position[0]][model->tail_position[1]] = snake_tail;
	}
	//Decrease the number of existing fodder if a snake ate a fodder.
	else
	{
		model->fodder--;
	}

	return eaten_element;
}


//Make random updates to the map.
void update_map(GameModel *model)
{
	//Add fodder at random place with given probability if there is not too much fodder on map.
	if (model->fodder < 10)
	{
		float probability = 0.25;
		//If success is greater than probability then we will add a fodder in a random place.
		float success = ((rand() % 100) / 100.0);

		//Add fodder.
		if (success < probability)
		{
			//Try to draw a random, but empty place on the map.
			//It is possible, that a map will be too occupied to draw a place.
			//Don't add a fodder then.
			//We implement this behaviour by drawing in for loop.
			int y, x;
			for (int i = 0; i < 10; i++)
			{
				y = rand() % model->size;
				x = rand() % model->size;
				if (model->elements[y][x] == empty)
				{
					break;
				}
			}

			//
			model->elements[y][x] = fodder;

			//Increment the number of existing fodder.
			model->fodder++;
		}
	}
}

//Procedure that simulates changes in the model.
void simulation(GameModel* model) 
{
	Element eaten_element = move_snake(model);

	//Close the game if the snake is dead.
	if (eaten_element == snake_head || eaten_element == snake_part || eaten_element == snake_tail)
	{
		printf("END");
		system("pause");
	}

	update_map(model);
}
