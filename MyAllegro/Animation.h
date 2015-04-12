#pragma once

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <string>
#include "InputManager.h"

class Animation
{
	private:
	//비트맵 변수
	ALLEGRO_BITMAP *image, *sourceRect;
	//혹시모를 폰트와 텍스트
	ALLEGRO_FONT *font;
	std::string text;
	//x,y좌표 pair를 쓸까?
	float position[2];
	//alpha
	float alpha;
	//애니매이션 실핼 할까 말까
	bool isActive;
	//총 프레임 갯수
	std::pair<int, int> amountOfFrames;
	//현재 프레임
	std::pair<int, int> currentFrame;

	public:
	Animation();
	~Animation();

	void LoadContent(ALLEGRO_BITMAP *image, std::string text, float position[2]);
	void UnloadContent();
	virtual void Update(ALLEGRO_EVENT ev);
	void Draw(ALLEGRO_DISPLAY *display);

	float &Alpha();
	bool &IsActive();

	std::pair<int, int> &AmountOfFrames();
	std::pair<int, int> &CurrentFrame();
	std::pair<int, int> GetFrameDimensions();

	void Position(float posx, float posy);

	ALLEGRO_BITMAP* Image();
	ALLEGRO_BITMAP*& SourceRect();
};

