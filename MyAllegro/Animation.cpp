#include "Animation.h"


Animation::Animation()
{
}


Animation::~Animation()
{
}

void Animation::LoadContent(ALLEGRO_BITMAP *image, std::string text, float position[2])
{
	this->image = image;
	this->text = text;
	this->position[0] = position[0];
	this->position[1] = position[1];

	alpha = 255;
	font = al_load_font("NanumGothic.ttf", 30, NULL);
	sourceRect = image;
	isActive = false;

	amountOfFrames = std::pair<int, int>(3, 4);
	currentFrame = std::pair<int, int>(1, 0);

}

void Animation::UnloadContent()
{
	//ScreenManager���� ���� ����⶧���� ������� ������� �Ǵ°� ����
	//al_destroy_bitmap(image);
	//al_destroy_bitmap(sourceRect);
	al_destroy_font(font);
	alpha = NULL;
	position[0] = position[1] = NULL;
}

void Animation::Update(ALLEGRO_EVENT ev)
{
}

void Animation::Draw(ALLEGRO_DISPLAY *display)
{
	//���İ��� ���������� ���� ���� �̰� �Ⱦ��� ���İ� �������ִ°� ����
	al_set_blender(ALLEGRO_ADD, ALLEGRO_ALPHA, ALLEGRO_INVERSE_ALPHA);
	if(sourceRect)
	{
		al_draw_tinted_bitmap(sourceRect, al_map_rgba(255, 255, 255, alpha), position[0], position[1], NULL);
	}

	if(text != "")
	{
		al_draw_text(font, al_map_rgba(255, 0, 0, alpha), position[0], position[1], NULL, text.c_str());
	}
}



float &Animation::Alpha()
{
	return alpha;
}

bool &Animation::IsActive()
{
	return isActive;
}

std::pair<int, int> &Animation::AmountOfFrames()
{
	return amountOfFrames;
}

std::pair<int, int> &Animation::CurrentFrame()
{
	return currentFrame;
}

std::pair<int, int> Animation::GetFrameDimensions()
{
	std::pair<int, int> frameDimension(al_get_bitmap_width(image) / amountOfFrames.first, al_get_bitmap_height(image) / amountOfFrames.second);

	return frameDimension;
}

void Animation::Position(float posx, float posy)
{
	this->position[0] = posx;
	this->position[1] = posy;
}

ALLEGRO_BITMAP* Animation::Image()
{
	return image;
}

ALLEGRO_BITMAP*& Animation::SourceRect()
{
	return sourceRect;
}