#include "simulation.h"

//Move the snake.
Element move_snake(GameModel *model, float passed_time)
{
	//This variable stores the element to which the head of the snake moves.
	Element eaten_element;

	//Update the old direction variable.
	model->direction_old = model->direction;

	//Update the direction. Set the direction to the direction where player wants to go.
	model->direction = model->direction_request;


	//Store current head and tail positions in variables that store head and tail positions from ast round
	model->head_old_position[0] = model->head_position[0];
	model->head_old_position[1] = model->head_position[1];
	model->tail_old_position[0] = model->tail_position[0];
	model->tail_old_position[1] = model->tail_position[1];

	//Move head.
	model->elements[model->head_position[0]][model->head_position[1]] = snake_part;
	if (model->direction == right)
	{
		model->camera_location = left;
		model->head_position[1]++;
		//Go through the magic wall
		if (model->head_position[1] == model->size) {
			model->head_position[1] = 0;
		}
	}
	else if (model->direction == left)
	{
		model->camera_location = right;
		model->head_position[1]--;
		//Go through the magic wall
		if (model->head_position[1] == -1) {
			model->head_position[1] = model->size - 1;
		}
	}
	else if (model->direction == up)
	{
		model->camera_location = down;
		model->head_position[0]++;
		//Go through the magic wall
		if (model->head_position[0] == model->size) {
			model->head_position[0] = 0;
		}
	}
	else if (model->direction == down)
	{
		model->camera_location = up;
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

	model->it = model->snake_positions_y.begin();
	model->snake_positions_y.insert(model->it, model->head_position[0]);
	model->it = model->snake_positions_x.begin();
	model->snake_positions_x.insert(model->it, model->head_position[1]);

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

	//Decrease the number of existing elemets if a snake ate this element.
	if(eaten_element == fodder)
	{
		model->fodder--;
	}
	else if (eaten_element == trap) {
		model->traps--;
	}
	else if (eaten_element == speed_boost) {
		model->timeout = 0.75 * model->timeout;
		model->speed_boosts--;
	}
	else if (eaten_element == slow_boost) {
		model->timeout = 1.5 * model->timeout;
		model->slow_boosts--;
	}

	return eaten_element;
}

//Adds the fodder to a specific place on the map
void addElement(GameModel *model, Element element)
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
	model->elements[y][x] = element;
}

//Make random updates to the map.
void update_map(GameModel *model)
{
	//If success is greater than probability then we will add an element der in a random place.
	float success = ((rand() % 100) / 100.0);

	if (model->fodder < model->max_fodder) {
		//Try to add fodder.
		if (success < model->fodder_probability)
		{
			addElement(model, fodder);
			//Increment the number of existing fodder.
			model->fodder++;
		}
	}

	success = ((rand() % 100) / 100.0);
	if (model->traps < model->max_traps) {
		//Try to add a trap
		if (success < model->trap_probability)
		{
			addElement(model, trap);
			//Increment the number of existing fodder.
			model->traps++;
		}
	}

	success = ((rand() % 100) / 100.0);
	if (model->speed_boosts < model->max_speed_boosts) {
		//Try to add a speed boost
		if (success < model->speed_boost_probability)
		{
			addElement(model, speed_boost);
			//Increment the number of existing fodder.
			model->speed_boosts++;
		}
	}

	success = ((rand() % 100) / 100.0);
	if (model->slow_boosts < model->max_slow_boosts) {
		//Try to add a slow boost
		if (success < model->slow_boost_probability)
		{
			addElement(model, slow_boost);
			//Increment the number of existing fodder.
			model->slow_boosts++;
		}
	}
}

//Procedure that simulates changes in the model.
void simulation(GameModel* model, float passed_time) 
{
	Element eaten_element = move_snake(model, passed_time);
	

	//Close the game if the snake is dead.
	if (eaten_element == snake_head || eaten_element == snake_part || eaten_element == snake_tail || eaten_element == trap)
	{
		model->stopped = true;
	}

	update_map(model);
}
