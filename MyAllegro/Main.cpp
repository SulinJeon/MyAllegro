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

	//Init 확인
	if(!al_init())
	{
		al_show_native_message_box(NULL, "Error", "Error", "Cannot initialize Allegro", NULL, NULL);
		return -1;
	}

	display = al_create_display(ScreenWidth, ScreenHeight);

	//Display 확인
	if(!display)
	{
		al_show_native_message_box(display, "Error", "Error", "Cannot create display", NULL, NULL);
		return -1;
	}

	//키보드 마우스 활성
	al_install_keyboard();
	al_install_mouse();

	//아코덱 이미지 애드온 활성
	//al_init_acodec_addon();
	al_init_image_addon();

	//폰트랑 ttf를 쓰게해주는 애드온
	al_init_font_addon();
	al_init_ttf_addon();

	//타이머와 이벤트큐 설정
	ALLEGRO_TIMER *timer = al_create_timer(1.0f / FPS);
	ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();

	//이벤트 큐에 들어갈 이벤트들을 등록
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_display_event_source(display));

	//게임 상태 boolean
	bool done = false;
	//InputManager 객체
	InputManager input;

	//ScreenManage Init, Load
	ScreenManager::GetInstance().Initialize();
	ScreenManager::GetInstance().LoadContent();

	/*타이머를 시작한다 처음에 이것때문에 고생했는데 타이머가 시작해야 이벤트가 발생한다 그래서 키를 눌러야 화면이 뜨더라 기억하도록*/
	al_start_timer(timer);

	//게임 loop
	while(!done)
	{
		//이벤트 하나 만들고 이벤트가 일어나면 이벤트 큐에 넣기
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

		//화면을 출력
		al_flip_display();
		al_clear_to_color(al_map_rgb(0, 0, 0));
	}

	//겜을 종료하면 메모리를 해제한다
	ScreenManager::GetInstance().UnloadContent();

	//다쓴거 정리
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);
	al_destroy_timer(timer);

	return 0;
}