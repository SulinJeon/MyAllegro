#pragma once

#include <allegro5/allegro.h>
#include "Animation.h"
#include "Player.h"
#include <math.h>

class Tile
{
	public:
	Tile();
	~Tile();

	//타일 state를 정한다
	static enum State { SOLID, PASSIVE };
	static enum Motion {HORIZONTAL, VERTICAL, STATIC};
		
	void SetContent(int id, ALLEGRO_BITMAP *image, Motion motion, State state, float position[]);
	void UnloadContent();
	void Update(ALLEGRO_EVENT ev, Entity &e);
	void Draw(ALLEGRO_DISPLAY *display);

	private:
	Animation tileAnimation;
	State state;
	Motion motion;
	ALLEGRO_BITMAP *tileImage;
	FloatRect *rect, *prevRect;
	float position[2], prevPosition[2];
	float velocity[2];
	float moveSpeed, range, rangeCounter;
	int  direction;
	bool containsEntity;
	int id;
};

