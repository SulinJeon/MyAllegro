#include "GamePlayScreen.h"


GamePlayScreen::GamePlayScreen()
{
}


GamePlayScreen::~GamePlayScreen()
{
}

void GamePlayScreen::LoadContent()
{
	stageNumber = 1;
	map.LoadContent("Layer2");
	player.LoadContent("Load/Player.txt", "", "Player");
	enemies.LoadContent("Load/Enemy.txt", "", "Enemy");
	background = al_load_bitmap("Load/GameBackground.png");
}

void GamePlayScreen::UnloadContent()
{
	al_destroy_bitmap(background);
	map.UnloadContent();
	player.UnloadContent();
	enemies.UnloadContent();
	GameScreen::UnloadContent();
}

void GamePlayScreen::Update(ALLEGRO_EVENT ev)
{
	if(input.IsKeyPressed(ev, ALLEGRO_KEY_R))
	{
		map.UnloadContent();
		player.UnloadContent();
		enemies.UnloadContent();
		map.LoadContent("Layer2");
		player.LoadContent("Load/Player.txt", "", "Player");
		enemies.LoadContent("Load/Enemy.txt", "", "Enemy");
		
		std::cout << "Reload this stage" << std::endl;
	}
	if(input.IsKeyPressed(ev, ALLEGRO_KEY_ENTER))
	{
		map.UnloadContent();
		player.UnloadContent();
		enemies.UnloadContent();
		stageNumber = 2;
		map.LoadContent("Layer1");
		player.LoadContent("Load/Player.txt", "", "Player");
		enemies.LoadContent("Load/Enemy.txt", "", "Enemy");
		std::cout << "Next Level" << std::endl;
	}
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
	al_draw_bitmap(background, 0, 0, NULL);
	map.Draw(display);
	player.Draw(display);
	enemies.Draw(display);
}