#pragma once

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <string>
#include "InputManager.h"

class Animation
{
	private:
	//��Ʈ�� ����
	ALLEGRO_BITMAP *image, *sourceRect;
	//Ȥ�ø� ��Ʈ�� �ؽ�Ʈ
	ALLEGRO_FONT *font;
	std::string text;
	//x,y��ǥ pair�� ����?
	float position[2];
	//alpha
	float alpha;
	//�ִϸ��̼� ���� �ұ� ����
	bool isActive;
	//�� ������ ����
	std::pair<int, int> amountOfFrames;
	//���� ������
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

