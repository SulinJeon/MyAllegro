#pragma once

#include "Entity.h"
#include "SpriteSheetAnimation.h"

class Player :public Entity
{
	private:
	InputManager input;
	
	//플레이어 이미지 속도
	ALLEGRO_BITMAP* playerImage;
	float moveSpeed;

	//거의다 이제 비슷해서 주석 달게 없음... 이건 방향
	enum Direction { DOWN, LEFT, RIGHT, UP }direction;

	//변경된 애니매이션 클래스 사용할려고 애니매이션이랑 스프라이트쉿 클래스 생성(2015.04.12 엔티티클래스로 다 이동)
	SpriteSheetAnimation ssAnimation;

	public:
	Player();
	~Player();

	void LoadContent(std::vector<std::string> category, std::vector<std::string> contents);
	void UnloadContent();
	void Update(ALLEGRO_EVENT ev);
	void Draw(ALLEGRO_DISPLAY *display);
};

