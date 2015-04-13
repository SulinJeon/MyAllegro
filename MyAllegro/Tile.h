#pragma once

#include <allegro5/allegro.h>
#include "Animation.h"
#include "Player.h"

class Tile
{
	public:
	Tile();
	~Tile();

	//타일 state를 정한다
	static enum State { SOLID, PASSIVE };
		
	void SetContent(int id, ALLEGRO_BITMAP *image, State state, float position[]);
	void UnloadContent();
	void Update(ALLEGRO_EVENT ev, Entity &e);
	void Draw(ALLEGRO_DISPLAY *display);

	private:
	Animation tileAnimation;
	State state;
	ALLEGRO_BITMAP *tileImage;
	float position[2];
	bool containsEntity;
	int id;
};

