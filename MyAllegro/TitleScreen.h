#pragma once

#include "ScreenManager.h"
#include "MenuManager.h"

class TitleScreen : public GameScreen
{
	private:
	MenuManager menu;
	ALLEGRO_BITMAP *titleImage;
	public:
	TitleScreen();
	~TitleScreen();

	void LoadContent();
	void UnloadContent();
	void Update(ALLEGRO_EVENT ev);
	void Draw(ALLEGRO_DISPLAY *display);
};

