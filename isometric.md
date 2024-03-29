#Code for isometric tiling

    ```//load tiles
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
				Color color = x % 2 == 0 ? RED : GREEN;
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
	UnloadTexture(levelTiles[2]);```
