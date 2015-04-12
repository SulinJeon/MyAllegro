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
	/*ScreenManager 클래스는 싱글턴패턴을 이용해 모든 스크린을 제어한다
	생성자들과 대입연산자를 private로 만들어서 접근을 제어한다
	정적 멤버 함수 GetInstance를 public으로 선언하고
	ScreenManager의 레퍼런스를 반환하고 전체적인 제어를 한다*/
	private:
	ScreenManager();
	ScreenManager(ScreenManager const&);
	void operator=(ScreenManager const&);

	//스크린 포인터
	GameScreen* currentScreen;
	GameScreen* newScreen;
	//에니메이션 클래스(지금은 페이드 하나)
	Animation transition;
	FadeAnimation fade;
	//페이트 에니메이션에 쓸 검정 이미지
	ALLEGRO_BITMAP *transitionImage;
	//이미지 좌표
	float position[2];
	bool startTransition;

	std::map<std::string, GameScreen*> screenName;

	//에니메이션으로 쓸 함수
	void Transition(ALLEGRO_EVENT ev);

	public:
	~ScreenManager();
	static ScreenManager& GetInstance();
	//AddScreen으로 화면 전환
	void AddScreen(std::string screen);
	void Initialize();
	void LoadContent();
	void UnloadContent();
	void Update(ALLEGRO_EVENT ev);
	void Draw(ALLEGRO_DISPLAY *display);
};

