#include "draw3D.h"
#include <cmath>
#include "apple.h"
#include "../MyCube.h"
using namespace glm;
float scale_value = 1.0f;
float scale_value2 = 1.0f;




mat4 change_camera(GameModel* model, float passed_time) {
	mat4 V;
	float shift_value = model->size;
	float y_shift = 0;
	float x_shift = 0;
	float cosinus = cos((PI / 2) * (passed_time / model->timeout));
	float sinus = sin((PI / 2) * (passed_time / model->timeout));

	//Determine the shift of camera.
	//Same direction
	if (model->direction == model->direction_old) {
		if (model->direction == up) {
			y_shift = -shift_value;
			x_shift = 0;
		}
		else if (model->direction == down) {
			y_shift = shift_value;
			x_shift = 0;
		}
		else if (model->direction == left) {
			y_shift = 0;
			x_shift = -shift_value;
		}
		else if (model->direction == right) {
			y_shift = 0;
			x_shift = shift_value;
		}
	}
	//Different directions
	else if (model->direction != model->direction_old) {
		//Part from past direction
		if (model->direction_old == up) {
			y_shift += -shift_value * cosinus;
			x_shift += 0;
		}
		else if (model->direction_old == down) {
			y_shift += shift_value * cosinus;
			x_shift += 0;
		}
		else if (model->direction_old == left) {
			y_shift += 0;
			x_shift += -shift_value * cosinus;
		}
		else if (model->direction_old == right) {
			y_shift += 0;
			x_shift += shift_value * cosinus;
		}

		//Current part
		if (model->direction == up) {
			y_shift += -shift_value * sinus;
			x_shift += 0;
		}
		else if (model->direction == down) {
			y_shift += shift_value * sinus;
			x_shift += 0;
		}
		else if (model->direction == left) {
			y_shift += 0;
			x_shift += -shift_value * sinus;
		}
		else if (model->direction == right) {
			y_shift += 0;
			x_shift += shift_value * sinus;
		}
	}
	
	V = lookAt( //Wylicz macierz widoku
		vec3(x_shift + shift_value  - model->head_visible_position[1], 0.5 * shift_value , y_shift + model->head_visible_position[0]),
		vec3(-x_shift + shift_value - model->head_visible_position[1]  , 1.0f, -y_shift + model->head_visible_position[0]),
		vec3(0.0f, 1.0f, 0.0f));

	return V;
}
	



void drawGame(GLFWwindow* window, GameModel *model, float passed_time) {
	unsigned int myCubeVertexCount = 24;

	//Tablica wsp�rz�dnych wierzcho�k�w
	float smallQuadVertices[] = {
		-0.5,0, -0.5,
		0.5,0 ,-0.5,
		0.5,0, 0.5,
		-0.5,0, 0.5,
	};
	//Tablica kolor�w wierzcho�k�w
	float smallQuadColorsRed[] = {
		1,0,0,
		1,0,0,
		1,0,0,
		1,0,0
	};

	float smallQuadColorsGreen[] = {
		0,1 ,0,
		0,1,0,
		0,1,0,
		0,1,0,
	};

	float smallQuadColorsBlue[] = {
		0,0,1,
		0,0,1,
		0,0,1,
		0,0,1,
	};

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //Wyczy�� bufor kolor�w (czyli przygotuj "p��tno" do rysowania)

														//***Przygotowanie do rysowania****
	mat4 P = perspective(50.0f*PI / 180.0f, 1.0f, 1.0f, 200.0f); //Wylicz macierz rzutowania P
	glMatrixMode(GL_PROJECTION); //W��cz tryb modyfikacji macierzy rzutowania
	glLoadMatrixf(value_ptr(P)); //Za�aduj macierz rzutowania
	glMatrixMode(GL_MODELVIEW);  //W��cz tryb modyfikacji macierzy model-widok
								 //***Rysowanie modelu***
								 //1. Wyliczenie i za�adowanie macierzy model-widok

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);


	//Update visible coordinates of the snake
	//Calculate visible position
	float head_old_value_0 = (abs(model->head_old_position[0] - model->head_position[0]) > 1) ? model->size - 1 - model->head_old_position[0] : model->head_old_position[0];
	float head_old_value_1 = (abs(model->head_old_position[1] - model->head_position[1]) > 1) ? model->size - 1 - model->head_old_position[1] : model->head_old_position[1];
	float tail_old_value_0 = (abs(model->tail_old_position[0] - model->tail_position[0]) > 1) ? model->size - 1 - model->tail_old_position[0] : model->tail_old_position[0];
	float tail_old_value_1 = (abs(model->tail_old_position[1] - model->tail_position[1]) > 1) ? model->size - 1 - model->tail_old_position[1] : model->tail_old_position[1];
	model->head_visible_position[0] = head_old_value_0 + (model->head_position[0] - head_old_value_0) * passed_time / model->timeout;
	model->head_visible_position[1] = head_old_value_1 + (model->head_position[1] - head_old_value_1) * passed_time / model->timeout;
	model->tail_visible_position[0] = tail_old_value_0 + (model->tail_position[0] - tail_old_value_0) * passed_time / model->timeout;
	model->tail_visible_position[1] = tail_old_value_1 + (model->tail_position[1] - tail_old_value_1) * passed_time / model->timeout;


	// Draw the scene in 3D. 
	mat4 M, M2;
	mat4 V;

	V = change_camera(model, passed_time);

	//Draw the floor
	M = mat4(scale_value);
	float tr = 0.5 * (float)(model->size + 1);// *(float)model->size;
	M = translate(M, vec3(tr, -0.5f, tr - 1.0f));
	M = scale(M, vec3(model->size, 1.0f, model->size));
	glLoadMatrixf(value_ptr(V*M));
	glVertexPointer(3, GL_FLOAT, 0, smallQuadVertices); //Ustaw tablic� smallQuadVertices jako tablic� wierzcho�k�w
	glColorPointer(3, GL_FLOAT, 0, smallQuadColorsRed); 	//Change color to floor color
	glDrawArrays(GL_QUADS, 0, 4);

	//Don't draw the snake's head and tail.They will be drawn in another place, to anable the animation.
	for (int y = 0; y < model->size; y++)
	{
		for (int x = 0; x < model->size; x++)
		{
			if (model->elements[y][x] == empty) {
				//We don't have to draw anything, so skip this step of the loop due to optimisation
				continue;
			}
			else {
				//Compute and load model matrix
				M = mat4(scale_value);
				M = translate(M, vec3(model->size *scale_value - x*scale_value, 0.0f, y*scale_value));
				glLoadMatrixf(value_ptr(V*M));

				//Draw elements (exept for snake's head and tail)
				if (model->elements[y][x] == fodder) {
					glDisableClientState(GL_COLOR_ARRAY);
					glEnableClientState(GL_NORMAL_ARRAY);
					
					M = scale(M, vec3(0.025f, 0.025f, 0.025f));
					//M2 = translate(M2, vec3(-0.5f, -0.5f, 0.0f));
					
					glLoadMatrixf(value_ptr(V*M));

					glNormalPointer(GL_FLOAT, 0, appleNormals);
					glVertexPointer(3, GL_FLOAT, 0, applePositions);
					glDrawArrays(GL_TRIANGLES, 0, appleVertices);
					glDisableClientState(GL_NORMAL_ARRAY);
					glEnableClientState(GL_COLOR_ARRAY);
				}
				else if (model->elements[y][x] == trap) {
					glVertexPointer(3, GL_FLOAT, 0, myCubeVertices);
					glColorPointer(3, GL_FLOAT, 0, myCubeColors4);
					glDrawArrays(GL_QUADS, 0, myCubeVertexCount);
				}
				else if (model->elements[y][x] == speed_boost) {

					glVertexPointer(3, GL_FLOAT, 0, myCubeVertices);
					glColorPointer(3, GL_FLOAT, 0, myCubeColors3);
					glDrawArrays(GL_QUADS, 0, myCubeVertexCount);
				}
				else if (model->elements[y][x] == slow_boost) {
					glVertexPointer(3, GL_FLOAT, 0, myCubeVertices);
					glColorPointer(3, GL_FLOAT, 0, myCubeColors5);
					glDrawArrays(GL_QUADS, 0, myCubeVertexCount);
				}
				else if (model->elements[y][x] == snake_part || model->elements[y][x] == snake_tail) {
					glVertexPointer(3, GL_FLOAT, 0, myCubeVertices);
					glColorPointer(3, GL_FLOAT, 0, myCubeColors5);
					glDrawArrays(GL_QUADS, 0, myCubeVertexCount);
					
				}
			}
		}
	}

	//Draw snake's head
	M = mat4(scale_value);
	
	M = translate(M, vec3(model->size *scale_value - model->head_visible_position[1] *scale_value, 0.0f, model->head_visible_position[0]*scale_value));
	glLoadMatrixf(value_ptr(V*M));

	glVertexPointer(3, GL_FLOAT, 0, myCubeVertices);
	glColorPointer(3, GL_FLOAT, 0, myCubeColors2);
	glDrawArrays(GL_QUADS, 0, myCubeVertexCount);

	//Draw snake's tail
	M = mat4(scale_value);
	M = translate(M, vec3(model->size *scale_value - model->tail_visible_position[1] * scale_value, 0.0f, model->tail_visible_position[0] * scale_value));
	glLoadMatrixf(value_ptr(V*M));
	
	glVertexPointer(3, GL_FLOAT, 0, myCubeVertices);
	glColorPointer(3, GL_FLOAT, 0, myCubeColors2);
	glDrawArrays(GL_QUADS, 0, myCubeVertexCount);
	
	
	//Cleanup
	/*
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
	*/
};

	