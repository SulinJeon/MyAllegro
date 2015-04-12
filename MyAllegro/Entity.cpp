#include "Entity.h"


Entity::Entity()
{
}


Entity::~Entity()
{
}

void Entity::LoadContent(std::vector<std::string> category, std::vector<std::string> contents)
{
	for(int i = 0; i < category.size(); i++)
	{
		if(category[i] == "Image")
			image = al_load_bitmap(contents[i].c_str());
		else if(category[i] == "Position")
		{
			std::string tempString = contents[i];
			position[0] = atof(tempString.substr(0, tempString.find(',')).c_str());
			position[1] = atof(tempString.substr(tempString.find(',') + 1).c_str());
		}
	}
	animation.LoadContent(image, "", position);

	//시작할때 보이지않는 colllision box를 씌워준다
	rect = new FloatRect(position[0], position[1], 32, 32);
	prevRect = new FloatRect(prevPosition[0], prevPosition[1], 32, 32);
}

void Entity::UnloadContent()
{
	al_destroy_bitmap(image);
}

void Entity::Update(ALLEGRO_EVENT ev)
{
	prevPosition[0] = position[0];
	prevPosition[1] = position[1];
}

void Entity::Draw(ALLEGRO_DISPLAY *display)
{
	animation.Draw(display);
}