#pragma once

#include "Entity.h"
#include <iostream>


class Player :public Entity
{
	private:
	//ī�޶� �����Ϸ��� �ʿ��ϴ�
	ALLEGRO_TRANSFORM camera;
	//�÷��̾� �̹���
	ALLEGRO_BITMAP* playerImage;
	InputManager input;
	float jumpSpeed;
	std::pair<float, float> cameraPosition;

	public:
	Player();
	~Player();
	
	void LoadContent(std::vector<std::string> category, std::vector<std::string> contents);
	void UnloadContent();
	void Update(ALLEGRO_EVENT ev);
	void Draw(ALLEGRO_DISPLAY *display);
	void SetPos(float x, float y);
	//ī�޶� ��ǥ�� ����
	void CameraUpdate(std::pair<float, float> &cameraPosition, float position[], int width, int height);
};

