#include "SplashScreen.h"


SplashScreen::SplashScreen()
{
}


SplashScreen::~SplashScreen()
{
}

void SplashScreen::LoadContent()
{
	imageNumber = 0;
	identifier = "Splash";
	font = al_load_font("NanumGothic.ttf", 30, NULL);
	file.LoadContent("test.txt", category, contents, identifier);
	//fileManager.LoadContent("test.txt", category, contents);

	/*�ؽ�Ʈ ���Ͽ��� �ҷ����� �ڷ��
	�̹����� �ҷ����� �ִϸ��̼� �������ֱ�*/
	for(int i = 0; i < category.size(); i++)
	{
		for(int j = 0; j < category[i].size(); j++)
		{
			if(category[i][j] == "Image")
			{
				Animation a;
				float position[2] = { 0, 0 };
				images.push_back(al_load_bitmap(contents[i][j].c_str()));
				fade.push_back(a);
				fade[fade.size() - 1].LoadContent(images[fade.size() - 1], "", position);
				fade[fade.size() - 1].IsActive() = true;
				std::cout << "do??" << std::endl;
			}
		}
	}
}

void SplashScreen::UnloadContent()
{
	GameScreen::UnloadContent();
	al_destroy_font(font);
	for(int i = 0; i < fade.size(); i++)
	{
		al_destroy_bitmap(images[i]);
		std::cout << "do?" << std::endl;
	}
	images.clear();
	fade.clear();
}

void SplashScreen::Update(ALLEGRO_EVENT ev)
{
	//������Ʈ
	fadeAnimation.Update(fade[imageNumber]);
	//���İ� 0�̵Ǹ� �ѹ�++
	if(fade[imageNumber].Alpha() == 0)
		imageNumber++;
	//�̹��� �� ���ų� �߰��� ����Ű ������ Ÿ��Ʋ ȭ������
	if(imageNumber >= fade.size() - 1 || input.IsKeyPressed(ev, ALLEGRO_KEY_ENTER))
	{
		ScreenManager::GetInstance().AddScreen("TitleScreen");
	}
}

void SplashScreen::Draw(ALLEGRO_DISPLAY *display)
{
	//al_draw_text(font, al_map_rgb(0, 0, 255), 100, 100, NULL, "SplashScreen");
	fade[imageNumber].Draw(display);
}
