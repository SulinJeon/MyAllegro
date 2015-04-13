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
	enemies.LoadContent("Load/Enemy.txt", "", "Enemy");
}

void GamePlayScreen::UnloadContent()
{
	GameScreen::UnloadContent();
	map.UnloadContent();
	player.UnloadContent();
	enemies.UnloadContent();
}

void GamePlayScreen::Update(ALLEGRO_EVENT ev)
{
	player.Update(ev);
	enemies.Update(ev);
	for(int i = 0; i < player.GetEntities().size(); i++)
		map.Update(ev, *player.GetEntities()[i]);
	for(int i = 0; i < enemies.GetEntities().size(); i++)
		map.Update(ev, *enemies.GetEntities()[i]);
	player.EntityCollision(enemies);
}

void GamePlayScreen::Draw(ALLEGRO_DISPLAY *display)
{
	map.Draw(display);
	player.Draw(display);
	enemies.Draw(display);
}