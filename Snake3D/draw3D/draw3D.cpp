#include "draw3D.h"
#include <cmath>
#include <iostream>
#include <iterator>
#include <vector>
#include "../apple2.h"
#include "../MyCube.h"
#include "../pikachu2.h"
#include "../bomb.h"
#include "../sphere.h"
#include "../lodepng.h"
#include "../mySnail.h"
#include "../cone.h"
#include "../walec.h"
#include "../bend.h"


using namespace glm;
float scale_value = 1.0f;
float scale_value2 = 1.0f;

GLuint bomb_tex;
GLuint grass_tex;
GLuint pikachu_tex;
GLuint my_snail_tex;
GLuint blur_tex;
GLuint sand_tex;
GLuint apple_tex; //Globalnie
void lode_png_to_memory(char* path, GLuint* tex) {
	//Wczytanie do pami�ci komputera
	std::vector<unsigned char> image;   //Alokuj wektor do wczytania obrazka
	unsigned width, height;   //Zmienne do kt�rych wczytamy wymiary obrazka
							  //Wczytaj obrazek
	unsigned error = lodepng::decode(image, width, height, path);

	//Import do pami�ci karty graficznej
	glGenTextures(1, tex); //Zainicjuj jeden uchwyt
	glBindTexture(GL_TEXTURE_2D, *tex); //Uaktywnij uchwyt
									   //Wczytaj obrazek do pami�ci KG skojarzonej z uchwytem
	glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0,GL_RGBA, GL_UNSIGNED_BYTE, (unsigned char*)image.data());


}




GLuint readTexture(char* filename) {
	GLuint tex;
	glActiveTexture(GL_TEXTURE0);

	//Wczytanie do pami�ci komputera
	std::vector<unsigned char> image;   //Alokuj wektor do wczytania obrazka
	unsigned width, height;   //Zmienne do kt�rych wczytamy wymiary obrazka
							  //Wczytaj obrazek
	unsigned error = lodepng::decode(image, width, height, filename);

	//Import do pami�ci karty graficznej
	glGenTextures(1, &tex); //Zainicjuj jeden uchwyt
	glBindTexture(GL_TEXTURE_2D, tex); //Uaktywnij uchwyt
									   //Wczytaj obrazek do pami�ci KG skojarzonej z uchwytem
	glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0,
		GL_RGBA, GL_UNSIGNED_BYTE, (unsigned char*)image.data());

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	return tex;
}







mat4 change_camera(GameModel* model, float passed_time) {
	mat4 V;
	float shift_value = 15;
	float camera_height = 10;
	float y_shift = 0;
	float x_shift = 0;
	float cosinus = cos((PI / 2) * (passed_time / model->timeout));
	float sinus = sin((PI / 2) * (passed_time / model->timeout));
	int model_size = model->size;
	auto elements = model->elements;

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
		vec3(x_shift +  model_size - model->head_visible_position[1], camera_height, y_shift + model->head_visible_position[0]),
		vec3(-x_shift +  model_size - model->head_visible_position[1], 1.0f, -y_shift + model->head_visible_position[0]),
		vec3(0.0f, 1.0f, 0.0f));

	return V;
}

void init_3D_drawing()
{
	pikachu_tex = readTexture("5187abc5.png");
	apple_tex = readTexture("skin.png");
	bomb_tex = readTexture("bomb.png");
	grass_tex = readTexture("grass.png");
	my_snail_tex = readTexture("snail.png");
	blur_tex = readTexture("blur.png");
	sand_tex = readTexture("sand.png");
}
	
void drawSnail()
{
	glBindTexture(GL_TEXTURE_2D, my_snail_tex);

	glVertexPointer(3, GL_FLOAT, 0, mySnailPositions);
	glNormalPointer(GL_FLOAT, 0, mySnailNormals);
	glTexCoordPointer(2, GL_FLOAT, 0, mySnailTexels);
	glDrawArrays(GL_TRIANGLES, 0, mySnailVertices);
}

void drawTrap()
{

}

void drawFodder() 
{

}

void speedBoost()
{

}

void drawGame(GLFWwindow* window, GameModel *model, float passed_time) {
	unsigned int myCubeVertexCount = 36;
	int model_size = model->size;
	auto elements = model->elements;
	//Tablica wsp�rz�dnych wierzcho�k�w
	float smallQuadVertices[] = {
		0.5, 0, 0.5,
		-0.5, 0, -0.5,
		-0.5, 0, 0.5,
		0.5, 0, 0.5,
		0.5, 0, -0.5,
		-0.5, 0, -0.5,
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
	float smallQuadNormals[] =
	{
		0, 1, 0,
		0, 1, 0,
		0, 1, 0,
		0, 1, 0,
		0, 1, 0,
		0, 1, 0,
	};
	float smallQuadTexels[] =
	{
		1, 1,
		0, 0,
		1, 0,
		1, 1,
		0, 1,
		0, 0,
	};

	float smallQuadColorsGrass[] = {
		0.196f, 0.804f, 0.196f,
		0.196f, 0.804f, 0.196f,
		0.196f, 0.804f, 0.196f,
		0.196f, 0.804f, 0.196f,
		0.196f, 0.804f, 0.196f,
		0.196f, 0.804f, 0.196f,
	};

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //Wyczy�� bufor kolor�w (czyli przygotuj "p��tno" do rysowania)

														//***Przygotowanie do rysowania****
	mat4 P = perspective(50.0f*PI / 180.0f, 1.0f, 1.0f, 200.0f); //Wylicz macierz rzutowania P
	glMatrixMode(GL_PROJECTION); //W��cz tryb modyfikacji macierzy rzutowania
	glLoadMatrixf(value_ptr(P)); //Za�aduj macierz rzutowania
	glMatrixMode(GL_MODELVIEW);  //W��cz tryb modyfikacji macierzy model-widok
								 //***Rysowanie modelu***
								 //1. Wyliczenie i za�adowanie macierzy model-widok



	//Update visible coordinates of the snake
	//Calculate visible position
	float head_old_value_0 = (abs(model->head_old_position[0] - model->head_position[0]) > 1) ?  model_size - 1 - model->head_old_position[0] : model->head_old_position[0];
	float head_old_value_1 = (abs(model->head_old_position[1] - model->head_position[1]) > 1) ?  model_size - 1 - model->head_old_position[1] : model->head_old_position[1];
	float tail_old_value_0 = (abs(model->tail_old_position[0] - model->tail_position[0]) > 1) ?  model_size - 1 - model->tail_old_position[0] : model->tail_old_position[0];
	float tail_old_value_1 = (abs(model->tail_old_position[1] - model->tail_position[1]) > 1) ?  model_size - 1 - model->tail_old_position[1] : model->tail_old_position[1];
	model->head_visible_position[0] = head_old_value_0 + (model->head_position[0] - head_old_value_0) * passed_time / model->timeout;
	model->head_visible_position[1] = head_old_value_1 + (model->head_position[1] - head_old_value_1) * passed_time / model->timeout;
	model->tail_visible_position[0] = tail_old_value_0 + (model->tail_position[0] - tail_old_value_0) * passed_time / model->timeout;
	model->tail_visible_position[1] = tail_old_value_1 + (model->tail_position[1] - tail_old_value_1) * passed_time / model->timeout;


	// Draw the scene in 3D. 
	mat4 M, M2;
	mat4 V;

	V = change_camera(model, passed_time);

	//Draw floor and walls
	glEnable(GL_TEXTURE_2D);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glBindTexture(GL_TEXTURE_2D, sand_tex);

	//Draw the floor
	float model_size_bigger = 2 * model_size;
	M = mat4(scale_value);
	float tr = 0.5 * (float)( model_size + 1);//
	M = translate(M, vec3(tr, -0.5f, tr - 1.0f));
	M = scale(M, vec3( model_size_bigger, 1.0f,  model_size_bigger));
	glLoadMatrixf(value_ptr(V*M));
	glVertexPointer(3, GL_FLOAT, 0, smallQuadVertices); //Ustaw tablic� smallQuadVertices jako tablic� wierzcho�k�w
	glNormalPointer(GL_FLOAT, 0, smallQuadNormals);
	glTexCoordPointer(2, GL_FLOAT, 0, smallQuadTexels);
	glDrawArrays(GL_TRIANGLES, 0, 6);

	//Draw the walls
	float h = model_size_bigger;
	glBindTexture(GL_TEXTURE_2D, blur_tex);
	if (model->direction != up) {
		//Down
		M = mat4(scale_value);
		M = translate(M, vec3(tr, 0.0f, -0.5f));
		M = rotate(M, PI / 2, vec3(1, 0, 0));
		M = scale(M, vec3(model_size_bigger, h, model_size_bigger));
		glLoadMatrixf(value_ptr(V*M));
		glDrawArrays(GL_TRIANGLES, 0, 6);
	}
	if (model->direction != down) {
		//Up
		M = mat4(scale_value);
		M = translate(M, vec3(tr, -0.0f, 2 * tr - 1.5));
		M = rotate(M, -PI/2, vec3(1, 0, 0));
		M = scale(M, vec3(model_size_bigger, h, model_size_bigger));
		glLoadMatrixf(value_ptr(V*M));
		glDrawArrays(GL_TRIANGLES, 0, 6);
	}
	if (model->direction != right) {
		//Left
		M = mat4(scale_value);
		M = translate(M, vec3(2*tr - 0.5, 0.0f, tr));
		M = rotate(M, PI / 2, vec3(0, 0, 1));
		M = scale(M, vec3(model_size_bigger, h, model_size_bigger));
		glLoadMatrixf(value_ptr(V*M));
		glDrawArrays(GL_TRIANGLES, 0, 6);
	}
	if (model->direction != left) {
		//Right
		M = mat4(scale_value);
		M = translate(M, vec3(0.0f + 0.5, 0.0f, tr));
		M = rotate(M, -PI/2, vec3(0, 0, 1));
		M = scale(M, vec3(model_size_bigger, h, model_size_bigger));
		glLoadMatrixf(value_ptr(V*M));
		glDrawArrays(GL_TRIANGLES, 0, 6);
	}


	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisable(GL_TEXTURE_2D);

	//Don't draw the snake's head and tail.They will be drawn in another place, to anable the animation.
	
	for (int y = 0; y < model_size; y++)
	{
		for (int x = 0; x < model_size; x++)
		{
			if (elements[y][x] == empty || elements[y][x] == snake_head) {
				//We don't have to draw anything, so skip this step of the loop due to optimisation
				continue;
			}
			else {
				//Compute and load model matrix
				M = mat4(scale_value);
				M = translate(M, vec3( model_size *scale_value - x*scale_value, 0.0f, y*scale_value));
				glLoadMatrixf(value_ptr(V*M));

				//Draw elements (exept for snake's head and tail)
				glEnable(GL_TEXTURE_2D);
				glEnableClientState(GL_TEXTURE_COORD_ARRAY);
				glEnableClientState(GL_VERTEX_ARRAY);
				glEnableClientState(GL_NORMAL_ARRAY);

				if (elements[y][x] == fodder) {
					glBindTexture(GL_TEXTURE_2D, apple_tex);
					
					M2 = mat4(1.0f);
					M2 = translate(M2, vec3(-0.75, -0.5, 0.0));
					M2 = translate(M2, vec3(model_size *scale_value - x*scale_value, 0.0f, y*scale_value));
					M2 = scale(M2, vec3(0.0125, 0.0250, 0.0125));
					glLoadMatrixf(value_ptr(V*M2));

					glTexCoordPointer(2, GL_FLOAT, 0, apple2Texels);
					glVertexPointer(3, GL_FLOAT, 0, apple2Positions);
					glNormalPointer(GL_FLOAT, 0, apple2Normals);
					glDrawArrays(GL_TRIANGLES, 0, apple2Vertices);
				}
				else if (elements[y][x] == trap) {
					glBindTexture(GL_TEXTURE_2D, bomb_tex);
					
					M2 = mat4(1.0f);
					M2 = translate(M2, vec3(1.25, 0.0, 0.0));
					M2 = translate(M2, vec3(model_size *scale_value - x*scale_value, 0.0f, y*scale_value));
					M2 = scale(M2, vec3(0.6666, 0.33333, 1.0f));
					glLoadMatrixf(value_ptr(V*M2));

					glNormalPointer(GL_FLOAT, 0, bombNormals);
					glVertexPointer(3, GL_FLOAT, 0, bombPositions);
					glTexCoordPointer(2, GL_FLOAT, 0, bombTexels);

					glDrawArrays(GL_TRIANGLES, 0, bombVertices);
				}
				else if (elements[y][x] == speed_boost) {
					glBindTexture(GL_TEXTURE_2D, pikachu_tex);
								
					M2 = mat4(1.0f);
					M2 = translate(M2, vec3(model_size *scale_value - x*scale_value, 0.0f, y*scale_value));
					M2 = scale(M2, vec3(0.0714, 0.0714, 0.25));
					glLoadMatrixf(value_ptr(V*M2));
					
					glVertexPointer(3, GL_FLOAT, 0, pikachu2Positions);
					glNormalPointer(GL_FLOAT, 0, pikachu2Normals);					
					glTexCoordPointer(2, GL_FLOAT, 0, pikachu2Texels);

					glDrawArrays(GL_TRIANGLES, 0, pikachu2Vertices);
				}
				else if (elements[y][x] == slow_boost) {
					drawSnail();
				}
				//else if (elements[y][x] == snake_part || elements[y][x] == snake_tail) {
				//	glBindTexture(GL_TEXTURE_2D, sand_tex);

				//	M2 = scale(M, vec3(0.5, 0.5, 1));
				//	glLoadMatrixf(value_ptr(V*M2));

				//	glVertexPointer(3, GL_FLOAT, 0, walecPositions);
				//	glTexCoordPointer(3, GL_FLOAT, 0, walecTexels);
				//	glNormalPointer(GL_FLOAT, 0, walecNormals);
				//	glDrawArrays(GL_TRIANGLES, 0, walecVertices);
				//}

				glDisableClientState(GL_VERTEX_ARRAY);
				glDisableClientState(GL_NORMAL_ARRAY);
				glDisable(GL_TEXTURE_2D);
				glDisableClientState(GL_TEXTURE_COORD_ARRAY);
			}
		}
	}

	
	//Draw snake
	// snake_positions_x has the same length as snake_positions_y
	int size = model->snake_positions_x.size();
	for (int i = 0; i < size; i++) {
		int x = model->snake_positions_x[i];
		int y = model->snake_positions_y[i];
		glEnable(GL_TEXTURE_2D);
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_NORMAL_ARRAY);
		if (i == 0) {
			//Draw snake's head

			glBindTexture(GL_TEXTURE_2D, pikachu_tex);

			M = mat4(scale_value);
			M = translate(M, vec3(model_size *scale_value - model->head_visible_position[1] * scale_value, 0.0f, model->head_visible_position[0] * scale_value));
			M = scale(M, vec3(1.5, 1.5, 1.5));
			glLoadMatrixf(value_ptr(V*M));

			glVertexPointer(3, GL_FLOAT, 0, spherePositions);
			glNormalPointer(GL_FLOAT, 0, sphereNormals);
			glTexCoordPointer(2, GL_FLOAT, 0, sphereTexels);
			glDrawArrays(GL_TRIANGLES, 0, sphereVertices);
		}
		else if (i == size - 1) {
			//Draw snake's tail
			M = mat4(scale_value);
			M = translate(M, vec3(model_size *scale_value - model->tail_visible_position[1] * scale_value, 0.0f, model->tail_visible_position[0] * scale_value));
			glLoadMatrixf(value_ptr(V*M));

			glVertexPointer(3, GL_FLOAT, 0, myCubeVertices);
			glColorPointer(3, GL_FLOAT, 0, myCubeColors2);
			glNormalPointer(GL_FLOAT, 0, myCubeNormals);
			glDrawArrays(GL_TRIANGLES, 0, myCubeVertexCount);
		}
		if (i > 0) {
			//Draw body even on the place of the tail
			//Horizontal or vertical
			if ((model->snake_positions_x[i - 1] != x && model->snake_positions_x[i + 1] != x)
					|| (model->snake_positions_y[i - 1] != y && model->snake_positions_y[i + 1] != y)){
				M = mat4(scale_value);
				M = translate(M, vec3(model_size *scale_value - x*scale_value, 0.0f, y*scale_value));

				//Rotate by 90 degrees if horizontal
				if (model->snake_positions_x[i - 1] != x && model->snake_positions_x[i + 1] != x) {
					M = rotate(M, PI / 2, vec3(0, 1, 0));
				}
				M = scale(M, vec3(1, 1, 1.1));	//Lengthen the body a bit
				glLoadMatrixf(value_ptr(V*M));

				glBindTexture(GL_TEXTURE_2D, sand_tex);

				glVertexPointer(3, GL_FLOAT, 0, walecPositions);
				glTexCoordPointer(2, GL_FLOAT, 0, walecTexels);
				glNormalPointer(GL_FLOAT, 0, walecNormals);
				glDrawArrays(GL_TRIANGLES, 0, walecVertices);
			}
			//Corner
			else {
				M = mat4(scale_value);
				M = translate(M, vec3(model_size *scale_value - x*scale_value, 0.0f, y*scale_value));

				//Rotate
				if (model->snake_positions_x[i + 1] < x && model->snake_positions_y[i - 1] < y) {
					//M = rotate(M, 0, vec3(0, 1, 0));
				}
				else if (model->snake_positions_x[i + 1] < x && model->snake_positions_y[i - 1] > y) {
					M = rotate(M, 3*PI/2, vec3(0, 1, 0));
				}
				else if (model->snake_positions_x[i + 1] > x && model->snake_positions_y[i - 1] < y) {
					M = rotate(M, PI/2, vec3(0, 1, 0));
				}
				else if (model->snake_positions_x[i + 1] > x && model->snake_positions_y[i - 1] > y) {
					M = rotate(M, PI, vec3(0, 1, 0));
				}
				else if (model->snake_positions_y[i + 1] < y && model->snake_positions_x[i - 1] < x) {
					//M = rotate(M, 3*PI/2, vec3(0, 1, 0));
				}
				else if (model->snake_positions_y[i + 1] < y && model->snake_positions_x[i - 1] > x) {
					M = rotate(M, PI/2, vec3(0, 1, 0));
				}
				else if (model->snake_positions_y[i + 1] > y && model->snake_positions_x[i - 1] < x) {
					M = rotate(M, 3*PI/2, vec3(0, 1, 0));
				}
				else if (model->snake_positions_y[i + 1] > y && model->snake_positions_x[i - 1] > x) {
					M = rotate(M, PI, vec3(0, 1, 0));
				}
				//M = scale(M, vec3(0.5, 0.5, 1));

				glLoadMatrixf(value_ptr(V*M));

				glBindTexture(GL_TEXTURE_2D, sand_tex);

				glVertexPointer(3, GL_FLOAT, 0, bendPositions);
				glTexCoordPointer(2, GL_FLOAT, 0, bendTexels);
				glNormalPointer(GL_FLOAT, 0, bendNormals);
				glDrawArrays(GL_TRIANGLES, 0, bendVertices);
			}
		}
		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_NORMAL_ARRAY);
		glDisable(GL_TEXTURE_2D);
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	}
};

	