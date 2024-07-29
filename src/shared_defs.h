#ifndef SHARED_DEFS_H
#define SHARED_DEFS_H

#include "raylib.h"
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <stdio.h>
#include <unistd.h>

// Struct to hold the configuration
typedef struct {
	float speed;
	int width;
	int height;
} config_t;

typedef enum {
	CELL_WHITE, 
	CELL_BLACK
} cell_state_t;

typedef struct {
	int x;
	int y;
	Vector2 direction;
} ant_t;

extern int num_cells_h;
extern int num_cells_v;
extern cell_state_t **cell_states;
extern ant_t ant;
extern int speed;
extern float rect_side;
extern bool is_paused;

extern const Color colors[2];

void initialize();
void update_ant(ant_t *ant);
void draw_ant(ant_t ant);
void parse_arguments(int argc, char *argv[], config_t *config);

#endif // SHARED_DEFS_H
