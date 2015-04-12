#include "TitleScreen.h"


TitleScreen::TitleScreen()
{
}


TitleScreen::~TitleScreen()
{
}

void TitleScreen::LoadContent()
{
	font = al_load_font("NanumGothic.ttf", 30, NULL);
	menu.LoadContent("Title");
}

void TitleScreen::UnloadContent()
{
	al_destroy_font(font);
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
	//al_draw_text(font, al_map_rgb(255, 0, 0), 100, 100, NULL, "TitleScreen");
	menu.Draw(display);
}
