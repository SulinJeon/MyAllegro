#include <iostream>
#include "ScreenManager.h"
#include "InputManager.h"
#include <allegro5/allegro_native_dialog.h>

int main()
{
	const int ScreenWidth = 800;
	const int ScreenHeight = 600;
	const float FPS = 60.0f;

	ALLEGRO_DISPLAY *display;

	//Init Ȯ��
	if(!al_init())
	{
		al_show_native_message_box(NULL, "Error", "Error", "Cannot initialize Allegro", NULL, NULL);
		return -1;
	}

	display = al_create_display(ScreenWidth, ScreenHeight);

	//Display Ȯ��
	if(!display)
	{
		al_show_native_message_box(display, "Error", "Error", "Cannot create display", NULL, NULL);
		return -1;
	}

	//Ű���� ���콺 Ȱ��
	al_install_keyboard();
	al_install_mouse();

	//���ڵ� �̹��� �ֵ�� Ȱ��
	//al_init_acodec_addon();
	al_init_image_addon();

	//��Ʈ�� ttf�� �������ִ� �ֵ��
	al_init_font_addon();
	al_init_ttf_addon();

	//Ÿ�̸ӿ� �̺�Ʈť ����
	ALLEGRO_TIMER *timer = al_create_timer(1.0f / FPS);
	ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();

	//�̺�Ʈ ť�� �� �̺�Ʈ���� ���
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_display_event_source(display));

	//���� ���� boolean
	bool done = false;
	//InputManager ��ü
	InputManager input;

	//ScreenManage Init, Load
	ScreenManager::GetInstance().Initialize();
	ScreenManager::GetInstance().LoadContent();

	/*Ÿ�̸Ӹ� �����Ѵ� ó���� �̰Ͷ����� ����ߴµ� Ÿ�̸Ӱ� �����ؾ� �̺�Ʈ�� �߻��Ѵ� �׷��� Ű�� ������ ȭ���� �ߴ��� ����ϵ���*/
	al_start_timer(timer);

	//���� loop
	while(!done)
	{
		//�̺�Ʈ �ϳ� ����� �̺�Ʈ�� �Ͼ�� �̺�Ʈ ť�� �ֱ�
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		//al_get_keyboard_state(&keyState);
		if(input.IsKeyPressed(ev, ALLEGRO_KEY_ESCAPE))
			done = true;

		if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
			done = true;

		//Update, Draw
		ScreenManager::GetInstance().Update(ev);
		ScreenManager::GetInstance().Draw(display);

		//ȭ���� ���
		al_flip_display();
		al_clear_to_color(al_map_rgb(0, 0, 0));
	}

	//���� �����ϸ� �޸𸮸� �����Ѵ�
	ScreenManager::GetInstance().UnloadContent();

	//�پ��� ����
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);
	al_destroy_timer(timer);

	return 0;
}