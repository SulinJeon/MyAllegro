#pragma once

#include "Entity.h"
#include <iostream>


class Player :public Entity
{
	private:
	//카메라를 움직일려면 필요하다
	ALLEGRO_TRANSFORM camera;
	//플레이어 이미지
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
	//카메라 좌표를 업뎃
	void CameraUpdate(std::pair<float, float> &cameraPosition, float position[], int width, int height);
};

