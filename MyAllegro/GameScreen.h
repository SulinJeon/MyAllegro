#pragma once

#include "InputManager.h"
#include "FileManager.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

class GameScreen
{
	protected:
	//Input이랑 font는 모든곳에서 쓰니까 상속합니당
	InputManager input;
	ALLEGRO_FONT *font;
	//FileManager도 대부분 쓰입니당
	FileManager file;
	//FileManager용 category, contents, identifier 모두 상속합니다.
	std::vector<std::vector<std::string>> category;
	std::vector<std::vector<std::string>> contents;
	std::string identifier;

	public:
	GameScreen();
	~GameScreen();

	//필요한 자료들을 Load
	virtual void LoadContent();
	//다쓴 자료들은 Unload
	virtual void UnloadContent();
	//업데이트 드로우
	virtual void Update(ALLEGRO_EVENT ev);
	virtual void Draw(ALLEGRO_DISPLAY *display);

	InputManager GetInput();
};

