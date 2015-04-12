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
	//�޴��� �̹����� ���� �׳� �ؽ�Ʈ�� ���� �����ؼ� �Ѵ� ����
	std::vector<std::string> menuItems;
	std::vector<ALLEGRO_BITMAP*> menuImages;

	//������ fade���� ������ ���߿� �ٸ� �ִϸ��̼� ������ �����ϱ� Animation Ÿ��
	//std::vector<std::vector<std::shared_ptr<Animation>>> menuAnim;
	//�ִϸ��̼� ����� temp
	//std::vector<std::shared_ptr<Animation>> tempAnimation;

	//2015.04.10 ���� �ִϸ��̼����� ��ȯ
	std::vector<Animation> animation;
	FadeAnimation fadeAnimation;
	
	//�޴���ũ�� ��Ʈ��
	std::vector<std::string> menuLinks;

	int itemNumber;
	InputManager input;

	//FileManager�� category, contents, identifier ��� ����մϴ�.
	std::vector<std::vector<std::string>> category;
	std::vector<std::vector<std::string>> contents;
	std::string identifier;

	std::vector<std::string> animationTypes;

	//�̹��� ��ǥ
	float position[2];
	//1�̸� ���� 2�̸� ���η� ������
	int axis;
	std::string align;

	ALLEGRO_FONT *font;

	FileManager fileManager;
	//�̹����� ���� �ؽ�Ʈ�� ���� �Ѵ� ���� ���ؼ� ������ �����س���
	void SetMenuItems();
	//�ִϸ��̼� ����
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

