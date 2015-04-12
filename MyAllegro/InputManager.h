#pragma once

#include <allegro5/allegro.h>
#include <allegro5/keyboard.h>
#include <vector>

class InputManager
{
	private:
	//Ű ���� Ű������Ʈ �ϳ� �������
	ALLEGRO_KEYBOARD_STATE keyState;

	public:
	InputManager();
	~InputManager();

	void Update();

	/*Ű�� �������� ������ Ű���� �������� ������*/
	bool IsKeyPressed(ALLEGRO_EVENT ev, int key);
	bool IsKeyPressed(ALLEGRO_EVENT ev, std::vector<int> keys);
	bool IsKeyReleased(ALLEGRO_EVENT ev, int key);
	bool IsKeyReleased(ALLEGRO_EVENT ev, std::vector<int> keys);

	bool IsKeyDown(int key);
};

