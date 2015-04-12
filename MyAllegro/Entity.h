#pragma once

#include <allegro5/allegro.h>
#include <vector>
#include <string>

#include "Animation.h"
#include "FloatRect.h"

class Entity
{
	//��ƼƼ Ŭ������ �߻� Ŭ������ ����� ���� ��Ӹ� ��ų���ϱ�
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

