#include "Levels.h"

#include <dirent.h>

void LoadTextures()
{
	struct dirent *dir;
	DIR *dr = opendir("./assets/tiles");
	closedir(dr);
	return;
}
