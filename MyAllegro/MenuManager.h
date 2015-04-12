#pragma once

#include <allegro5/allegro.h>
//#include "ScreenManager.h"
#include "FileManager.h"
#include "Animation.h"
#include "FadeAnimation.h"
#include "InputManager.h"
#include <memory>
#include <vector>

class MenuManager
{
	private:
	//메뉴를 이미지를 쓸지 그냥 텍스트로 할지 못정해서 둘다 정의
	std::vector<std::string> menuItems;
	std::vector<ALLEGRO_BITMAP*> menuImages;

	//지금은 fade뿐이 없지만 나중에 다른 애니매이션 쓸수도 있으니까 Animation 타입
	//std::vector<std::vector<std::shared_ptr<Animation>>> menuAnim;
	//애니메이션 저장용 temp
	//std::vector<std::shared_ptr<Animation>> tempAnimation;

	//2015.04.10 범용 애니매이션으로 전환
	std::vector<Animation> animation;
	FadeAnimation fadeAnimation;
	
	//메뉴링크용 스트링
	std::vector<std::string> menuLinks;

	int itemNumber;
	InputManager input;

	//FileManager용 category, contents, identifier 모두 상속합니다.
	std::vector<std::vector<std::string>> category;
	std::vector<std::vector<std::string>> contents;
	std::string identifier;

	std::vector<std::string> animationTypes;

	//이미지 좌표
	float position[2];
	//1이면 세로 2이면 가로로 생각중
	int axis;
	std::string align;

	ALLEGRO_FONT *font;

	FileManager fileManager;
	//이미지를 쓰든 텍스트를 쓰든 둘다 쓰기 위해서 없더라도 세팅해놓게
	void SetMenuItems();
	//애니매이션 세팅
	void SetAnimation();
	public:
	MenuManager();
	~MenuManager();

	void LoadContent(std::string id);
	void UnloadContent();
	void Update(ALLEGRO_EVENT ev);
	void Draw(ALLEGRO_DISPLAY *display);

	std::string GetMenuLink();
};

