#pragma once

#include "ScreenManager.h"
#include "FileManager.h"
#include "FadeAnimation.h"

class SplashScreen : public GameScreen
{
	private:
	int imageNumber;

	//Splash�� ����� �̹�����
	std::vector<ALLEGRO_BITMAP*> images;
	/*Splash�� ����� �ִϸ��̼ǵ�... 
	���Ѵٸ� Fade���� Animation���� �ؼ� �ٸ� �ִϸ��̼��� �ᵵ �ȴ�
	2015.04.09���� �ִϸ��̼� �����ְ� ������*/
	std::vector<Animation> fade;

	FadeAnimation fadeAnimation;

	public:
	SplashScreen();
	~SplashScreen();

	void LoadContent();
	void UnloadContent();
	void Update(ALLEGRO_EVENT ev);
	void Draw(ALLEGRO_DISPLAY *display);
};

