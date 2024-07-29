#include "shared_defs.h"

const Color colors[2] = {
    {255, 255, 255, 255}, // White
    {0, 0, 0, 255}        // Black
};

int main(int argc, char **argv)
{

	int num_cells_h;
	int num_cells_v;
	cell_state_t **cell_states;
	ant_t ant;
	int speed = 10000;
	float rect_side;
	bool is_paused = false;

	config_t config = {1.0, 800, 800};
	parse_arguments(argc, argv, &config);

	InitWindow(config.width, config.height, "LangtonCtl");
	SetTargetFPS((int)(config.speed * 3.6));
	initialize();

	while (!WindowShouldClose()) {
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) is_paused = !is_paused;

		if (!is_paused) {
			for (int iter = 0; iter < speed; iter++) {
				update_ant(&ant);
			}
		}

		BeginDrawing();
		ClearBackground(BLACK);
		for (int x = 0; x < num_cells_h; x++) {
			for (int y = 0; y < num_cells_v; y++) {
				DrawRectangle(x * rect_side, y * rect_side, rect_side, rect_side, colors[cell_states[x][y]]);
			}
		}
		draw_ant(ant);
		EndDrawing();
	}

	for (int i = 0; i < num_cells_h; i++) {
		free(cell_states[i]);
	}
	free(cell_states);

	CloseWindow();
	return 0;
}
