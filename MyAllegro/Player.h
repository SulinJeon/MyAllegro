#pragma once

#include "Entity.h"


class Player :public Entity
{
	private:
	//�÷��̾� �̹���
	ALLEGRO_BITMAP* playerImage;
	InputManager input;
	float jumpSpeed;

	public:
	Player();
	~Player();

	void LoadContent(std::vector<std::string> category, std::vector<std::string> contents);
	void UnloadContent();
	void Update(ALLEGRO_EVENT ev);
	void Draw(ALLEGRO_DISPLAY *display);
};

