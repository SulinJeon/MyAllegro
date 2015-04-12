#include "GamePlayScreen.h"


GamePlayScreen::GamePlayScreen()
{
}


GamePlayScreen::~GamePlayScreen()
{
}

void GamePlayScreen::LoadContent()
{
	map.LoadContent();
	player.LoadContent("Load/Player.txt", "", "Player");
}

void GamePlayScreen::UnloadContent()
{
	GameScreen::UnloadContent();
	map.UnloadContent();
	player.UnloadContent();
}

void GamePlayScreen::Update(ALLEGRO_EVENT ev)
{
	player.Update(ev);
	for(int i = 0; i < player.GetEntities().size(); i++)
		map.Update(ev, *player.GetEntities()[i]);
}

void GamePlayScreen::Draw(ALLEGRO_DISPLAY *display)
{
	map.Draw(display);
	player.Draw(display);
}