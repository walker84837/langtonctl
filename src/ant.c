#include "shared_defs.h"

void initialize()
{
	num_cells_h = 80;
	num_cells_v = num_cells_h;
	rect_side = (float)GetScreenWidth() / num_cells_h;

	cell_states = (cell_state_t **)malloc(num_cells_h * sizeof(cell_state_t *));
	for (int i = 0; i < num_cells_h; i++) {
		cell_states[i] = (cell_state_t *)malloc(num_cells_v * sizeof(cell_state_t));
		for (int j = 0; j < num_cells_v; j++) {
			cell_states[i][j] = CELL_WHITE;
		}
	}

	ant.x = num_cells_h / 2;
	ant.y = num_cells_v / 2;
	ant.direction = (Vector2){0, -1};
}

void update_ant(ant_t *ant)
{
	int ant_x = ant->x;
	int ant_y = ant->y;
	cell_state_t state = cell_states[ant_x][ant_y];

	if (state == CELL_WHITE) {
		float temp = ant->direction.x;
		ant->direction.x = ant->direction.y;
		ant->direction.y = -temp;
	} else {
		float temp = ant->direction.x;
		ant->direction.x = -ant->direction.y;
		ant->direction.y = temp;
	}

	cell_states[ant_x][ant_y] = (cell_states[ant_x][ant_y] == CELL_WHITE) ? CELL_BLACK : CELL_WHITE;

	ant->x = (ant->x + (int)ant->direction.x + num_cells_h) % num_cells_h;
	ant->y = (ant->y + (int)ant->direction.y + num_cells_v) % num_cells_v;
}

void draw_ant(ant_t ant)
{
	Vector2 center = {ant.x * rect_side + rect_side / 2, ant.y * rect_side + rect_side / 2};
	Vector2 points[3] = {
		{center.x + rect_side / 4, center.y},
		{center.x - rect_side / 4, center.y + rect_side / 4},
		{center.x - rect_side / 4, center.y - rect_side / 4}
	};
	float angle = atan2(ant.direction.y, ant.direction.x);
	for (int i = 0; i < 3; i++) {
		float x = points[i].x - center.x;
		float y = points[i].y - center.y;
		points[i].x = center.x + x * cos(angle) - y * sin(angle);
		points[i].y = center.y + x * sin(angle) + y * cos(angle);
	}
	DrawTriangle(points[0], points[1], points[2], RED);
}
