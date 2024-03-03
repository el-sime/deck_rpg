#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include "screens.h"
#include "Character.h"

int main(int argc, char *argv[])
{
    Character player = CharacterFactory(1, PLAYER);
    InitWindow(800, 600, "game");
    SetTargetFPS(60);
    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
