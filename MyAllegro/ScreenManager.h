#pragma once

#include <iostream>
#include "GameScreen.h"
#include "SplashScreen.h"
#include "TitleScreen.h"
#include "GamePlayScreen.h"
#include "FadeAnimation.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <map>


class ScreenManager
{
	/*ScreenManager Ŭ������ �̱��������� �̿��� ��� ��ũ���� �����Ѵ�
	�����ڵ�� ���Կ����ڸ� private�� ���� ������ �����Ѵ�
	���� ��� �Լ� GetInstance�� public���� �����ϰ�
	ScreenManager�� ���۷����� ��ȯ�ϰ� ��ü���� ��� �Ѵ�*/
	private:
	ScreenManager();
	ScreenManager(ScreenManager const&);
	void operator=(ScreenManager const&);

	//��ũ�� ������
	GameScreen* currentScreen;
	GameScreen* newScreen;
	//���ϸ��̼� Ŭ����(������ ���̵� �ϳ�)
	Animation transition;
	FadeAnimation fade;
	//����Ʈ ���ϸ��̼ǿ� �� ���� �̹���
	ALLEGRO_BITMAP *transitionImage;
	//�̹��� ��ǥ
	float position[2];
	bool startTransition;

	std::map<std::string, GameScreen*> screenName;

	//���ϸ��̼����� �� �Լ�
	void Transition(ALLEGRO_EVENT ev);

	public:
	~ScreenManager();
	static ScreenManager& GetInstance();
	//AddScreen���� ȭ�� ��ȯ
	void AddScreen(std::string screen);
	void Initialize();
	void LoadContent();
	void UnloadContent();
	void Update(ALLEGRO_EVENT ev);
	void Draw(ALLEGRO_DISPLAY *display);
};

