#include "TitleScreen.h"


TitleScreen::TitleScreen()
{
}


TitleScreen::~TitleScreen()
{
}

void TitleScreen::LoadContent()
{
	titleImage = al_load_bitmap("Load/Title.png");
	menu.LoadContent("Title");
}

void TitleScreen::UnloadContent()
{
	al_destroy_bitmap(titleImage);
	menu.UnloadContent();
}

void TitleScreen::Update(ALLEGRO_EVENT ev)
{
	if(input.IsKeyPressed(ev, ALLEGRO_KEY_ENTER))
	{
		ScreenManager::GetInstance().AddScreen(menu.GetMenuLink());
	}
	menu.Update(ev);
}

void TitleScreen::Draw(ALLEGRO_DISPLAY *display)
{
	al_draw_bitmap(titleImage, 0, 0, NULL);
	menu.Draw(display);
}
