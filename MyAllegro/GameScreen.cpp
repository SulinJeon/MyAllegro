#include "GameScreen.h"


GameScreen::GameScreen()
{
}


GameScreen::~GameScreen()
{
}

void GameScreen::LoadContent()
{
}

void GameScreen::UnloadContent()
{
	category.clear();
	contents.clear();
}

void GameScreen::Update(ALLEGRO_EVENT ev)
{
}

void GameScreen::Draw(ALLEGRO_DISPLAY *display)
{
}

InputManager GameScreen::GetInput()
{
	return input;
}