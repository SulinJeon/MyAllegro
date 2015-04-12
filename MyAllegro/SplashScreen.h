#pragma once

#include "ScreenManager.h"
#include "FileManager.h"
#include "FadeAnimation.h"

class SplashScreen : public GameScreen
{
	private:
	int imageNumber;

	//Splash에 사용할 이미지들
	std::vector<ALLEGRO_BITMAP*> images;
	/*Splash에 사용할 애니메이션들... 
	원한다면 Fade말고 Animation으로 해서 다른 애니메이션을 써도 된다
	2015.04.09범용 애니메이션 쓸수있게 수정함*/
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

