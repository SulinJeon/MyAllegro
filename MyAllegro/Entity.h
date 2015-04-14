#pragma once

#include <allegro5/allegro.h>
#include <vector>
#include <string>

#include "FloatRect.h"
#include "SpriteSheetAnimation.h"

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

	//얘네가 protected에 들어오면 나중에 Get,Set을 구현해서 또 건들여야 하는데 그냥 public에 했다
	//안그러면 tile클래스에서 충돌시험때 Get을 너무 많이 써야한다
	FloatRect *rect, *prevRect;
	float position[2], prevPosition[2];
	bool activateGravity;
	//불 점핑
	bool isJumping;
	Animation animation;
	//거의다 이제 비슷해서 주석 달게 없음... 이건 방향
	enum Direction { DOWN, LEFT, RIGHT, UP }direction;

	int tileID;

	protected:
	ALLEGRO_BITMAP *image;
	float velocity[2];
	float gravity;
	float moveSpeed;
	int range;
	//변경된 애니매이션 클래스 사용할려고 애니매이션이랑 스프라이트쉿 클래스 생성(2015.04.12 엔티티클래스로 다 이동)
	SpriteSheetAnimation ssAnimation;
};

