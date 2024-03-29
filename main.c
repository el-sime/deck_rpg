#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include "Constants.h"
//#include "screens.h"
//#include "Character.h"

#define MAX_LEVEL_COLS 256
#define MAX_LEVEL_ROWS 128

#define GRID_WIDTH 128
#define GRID_HEIGHT 64
Vector2 Ortho2Iso(Vector2 orthoCoords){
	// the first tile goes horizontal center / top
	Vector2 isoCoords;
	isoCoords.x = GetScreenWidth() / 2 - GRID_WIDTH / 2 * (orthoCoords.y + 1)   + GRID_WIDTH / 2 * orthoCoords.x;
	isoCoords.y = orthoCoords.y * GRID_HEIGHT / 2 + orthoCoords.x * GRID_HEIGHT / 2;
	return isoCoords;
}
//const int COLS = 24;
//const int ROWS = 8;
#define COLS 12
#define ROWS 8

int main(int argc, char *argv[])
{
	//Character player = CharacterFactory(1, PLAYER);
	InitWindow(1280, 800, "game");
	SetTargetFPS(60);
	SetWindowState(FLAG_WINDOW_UNDECORATED);

	while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BACKGROUND_C);
        EndDrawing();
    }

	CloseWindow();
	return 0;
}
