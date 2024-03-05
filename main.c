#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
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
	//load tiles
	Texture2D levelTiles[3] = {
		LoadTexture("assets/tiles/stone_E.png"),
		LoadTexture("assets/tiles/black.png"),
		LoadTexture("assets/tiles/dirt_E.png")
	};
	Rectangle frameRec = { 0.0f, 364.0f, 256, 148 };
	//Vector2 position = {GetScreenWidth() / 2 - 64, 0.0f};
	int background[ROWS][COLS] = {
		{2,1,2,0,0,0,0,1,0,0,0,0},
		{1,2,0,0,0,0,1,0,0,0,0,0},
		{2,0,0,0,0,1,0,0,0,0,0,0},
		{0,0,0,0,1,0,0,0,0,0,0,0},
		{0,0,0,1,0,0,0,0,0,0,0,0},
		{0,0,1,0,0,0,0,0,0,0,0,0},
		{0,1,0,0,0,0,0,0,0,0,0,0},
		{1,0,0,0,0,0,0,0,0,0,0,0}
	};
	int debug = 0;
	while(!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(DARKGRAY);
		for (int y = 0; y < ROWS; y++)
		{
			for (int x = 0; x < COLS; x++)
			{
				Vector2 orthoCoords = {x, y};
				Vector2 isoCoords = Ortho2Iso(orthoCoords);
				Rectangle dest = {isoCoords.x, isoCoords.y, 128, 74};
				Vector2 origin = {0.0f, 0.0f};
				Color color = x % 1 == 0 ? RED : GREEN;
				DrawTexturePro(levelTiles[background[y][x]], frameRec, dest,origin, 0.0f, color);
				if(debug == 0) printf("texture height : (%f, %f)\n", isoCoords.x, isoCoords.y);
			}
		}
		debug = 1;
		EndDrawing();
	}

	//unload textures
	UnloadTexture(levelTiles[0]);
	UnloadTexture(levelTiles[1]);
	UnloadTexture(levelTiles[2]);

	CloseWindow();
	return 0;
}
