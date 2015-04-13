#pragma once
#include "Entity.h"
class Enemy : public Entity
{
	public:
	Enemy();
	~Enemy();

	void LoadContent(std::vector<std::string> category, std::vector<std::string> contents);
	void UnloadContent();
	void Update(ALLEGRO_EVENT ev);
	void Draw(ALLEGRO_DISPLAY *display);

	private:
	int counter;
};

