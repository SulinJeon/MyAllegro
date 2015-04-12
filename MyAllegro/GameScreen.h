#pragma once

#include "InputManager.h"
#include "FileManager.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

class GameScreen
{
	protected:
	//Input�̶� font�� �������� ���ϱ� ����մϴ�
	InputManager input;
	ALLEGRO_FONT *font;
	//FileManager�� ��κ� ���Դϴ�
	FileManager file;
	//FileManager�� category, contents, identifier ��� ����մϴ�.
	std::vector<std::vector<std::string>> category;
	std::vector<std::vector<std::string>> contents;
	std::string identifier;

	public:
	GameScreen();
	~GameScreen();

	//�ʿ��� �ڷ���� Load
	virtual void LoadContent();
	//�پ� �ڷ���� Unload
	virtual void UnloadContent();
	//������Ʈ ��ο�
	virtual void Update(ALLEGRO_EVENT ev);
	virtual void Draw(ALLEGRO_DISPLAY *display);

	InputManager GetInput();
};

