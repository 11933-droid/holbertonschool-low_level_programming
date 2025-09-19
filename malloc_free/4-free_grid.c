#include "main.h"

/**
 * free_grid - free memory previus
 * @grid: pointer to teh
 * @height: number of row
 */

void free_grid(int **grid, int height)
{
	int i;

	for (i = 0; i < height; i++)
		free(grid[i]);
	free(grid);
}
