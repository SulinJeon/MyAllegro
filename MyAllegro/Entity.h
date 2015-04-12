#pragma once

#include <allegro5/allegro.h>
#include <vector>
#include <string>

#include "Animation.h"
#include "FloatRect.h"

class Entity
{
	//엔티티 클래스는 추상 클래스로 만든다 차피 상속만 시킬꺼니까
	public:
	Entity();
	~Entity();

	virtual void LoadContent(std::vector<std::string> category, std::vector<std::string> contents);
	virtual void UnloadContent() = 0;
	virtual void Update(ALLEGRO_EVENT ev);
	virtual void Draw(ALLEGRO_DISPLAY *display);

	bool activateGravity;
	FloatRect *rect, *prevRect;
	float position[2], prevPosition[2];

	protected:
	ALLEGRO_BITMAP *image;
	Animation animation;
	float gravity;
};

