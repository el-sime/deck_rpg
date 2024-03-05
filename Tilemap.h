#ifndef TILEMAP_H
#define TILEMAP_H
#include "raylib.h"

typedef enum ObjectTypes {BACKGROUND, FOREGROUND, ITEM} ObjectType;

typedef struct Tilemaps {
    int Background[120][120];
    int Foreground[120][120];
    int Items[120][120];
} Tilemap;

void DrawObject(Vector2 position, ObjectType type);
void DrawTile(Vector2 position);

#endif
