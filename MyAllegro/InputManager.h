#pragma once

#include <allegro5/allegro.h>
#include <allegro5/keyboard.h>
#include <vector>

class InputManager
{
	private:
	//키 받을 키스테이트 하나 만들어줌
	ALLEGRO_KEYBOARD_STATE keyState;

	public:
	InputManager();
	~InputManager();

	void Update();

	/*키가 눌러졌나 때졌나 키들이 눌러졌나 때졌나*/
	bool IsKeyPressed(ALLEGRO_EVENT ev, int key);
	bool IsKeyPressed(ALLEGRO_EVENT ev, std::vector<int> keys);
	bool IsKeyReleased(ALLEGRO_EVENT ev, int key);
	bool IsKeyReleased(ALLEGRO_EVENT ev, std::vector<int> keys);

	bool IsKeyDown(int key);
};

