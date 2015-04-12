#pragma once

#include "Entity.h"
#include "SpriteSheetAnimation.h"

class Player :public Entity
{
	private:
	InputManager input;
	
	//�÷��̾� �̹��� �ӵ�
	ALLEGRO_BITMAP* playerImage;
	float moveSpeed;

	//���Ǵ� ���� ����ؼ� �ּ� �ް� ����... �̰� ����
	enum Direction { DOWN, LEFT, RIGHT, UP }direction;

	//����� �ִϸ��̼� Ŭ���� ����ҷ��� �ִϸ��̼��̶� ��������Ʈ�� Ŭ���� ����(2015.04.12 ��ƼƼŬ������ �� �̵�)
	SpriteSheetAnimation ssAnimation;

	public:
	Player();
	~Player();

	void LoadContent(std::vector<std::string> category, std::vector<std::string> contents);
	void UnloadContent();
	void Update(ALLEGRO_EVENT ev);
	void Draw(ALLEGRO_DISPLAY *display);
};

