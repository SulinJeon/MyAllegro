#pragma once

#include <allegro5/allegro.h>
#include <vector>
#include <string>

#include "FloatRect.h"
#include "SpriteSheetAnimation.h"

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

	//��װ� protected�� ������ ���߿� Get,Set�� �����ؼ� �� �ǵ鿩�� �ϴµ� �׳� public�� �ߴ�
	//�ȱ׷��� tileŬ�������� �浹���趧 Get�� �ʹ� ���� ����Ѵ�
	FloatRect *rect, *prevRect;
	float position[2], prevPosition[2];
	bool activateGravity;
	//�� ����
	bool isJumping;
	Animation animation;
	//���Ǵ� ���� ����ؼ� �ּ� �ް� ����... �̰� ����
	enum Direction { DOWN, LEFT, RIGHT, UP }direction;

	int tileID;

	protected:
	ALLEGRO_BITMAP *image;
	float velocity[2];
	float gravity;
	float moveSpeed;
	int range;
	//����� �ִϸ��̼� Ŭ���� ����ҷ��� �ִϸ��̼��̶� ��������Ʈ�� Ŭ���� ����(2015.04.12 ��ƼƼŬ������ �� �̵�)
	SpriteSheetAnimation ssAnimation;
};

