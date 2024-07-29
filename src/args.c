#include "shared_defs.h"

void parse_arguments(int argc, char *argv[], config_t *config)
{
	int opt;
	while ((opt = getopt(argc, argv, "s:r:")) != -1) {
		switch (opt) {
			case 's':
				config->speed = atof(optarg);
				break;
			case 'r': {
				int width, height;
				if (sscanf(optarg, "%dx%d", &width, &height) == 2) {
				        config->width = width;
				        config->height = height;
				} else {
				        fprintf(stderr, "Invalid resolution format. Use WIDTHxHEIGHT.\n");
				        exit(EXIT_FAILURE);
				}
				break;
			}
			default:
				  fprintf(stderr, "Usage: %s [-s speed] [-r resolution]\n", argv[0]);
				  exit(EXIT_FAILURE);
		}
	}
}
