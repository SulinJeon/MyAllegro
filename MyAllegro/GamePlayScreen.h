#pragma once

#include "ScreenManager.h"
#include "GameScreen.h"
#include "EntityManager.h"
#include "Map.h"

class GamePlayScreen : public GameScreen
{
	private:
	ALLEGRO_BITMAP *background;
	int stageNumber;
	EntityManager player, enemies;
	Map map;
	public:
	GamePlayScreen();
	~GamePlayScreen();

	void LoadContent();
	void UnloadContent();
	void Update(ALLEGRO_EVENT ev);
	void Draw(ALLEGRO_DISPLAY *display);
};

