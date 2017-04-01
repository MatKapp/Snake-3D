#include "simulation.h"


//Procedure that simulates changes in the model.
void simulation(GameModel* model) {
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
	model->elements[model->head_position[0]][model->head_position[1]] = snake_head;

	//Move tail

}