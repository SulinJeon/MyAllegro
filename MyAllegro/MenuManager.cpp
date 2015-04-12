#include "MenuManager.h"


MenuManager::MenuManager()
{
}


MenuManager::~MenuManager()
{
}

void MenuManager::SetMenuItems()
{
	/*예를들어 텍스트가 있는데 이미지가 없는경우
	텍스트메뉴 수 만큼 이미지도 NULL로 채워줘야 하기때문에(우리 LoadContent가 매개변수로 필요함)*/
	for(int i = 0; i < menuImages.size(); i++)
	{
		if(menuItems.size() == i)
			menuItems.push_back(NULL);
	}
	for(int i = 0; i < menuItems.size(); i++)
	{
		if(menuImages.size() == i)
			menuImages.push_back(NULL);
	}
}

void MenuManager::SetAnimation()
{
	//로드해서 세팅하기
	//2015.04.10 범용으로 전환
	float *pos = position;
	/*for(int i = 0; i < menuItems.size(); i++)
	{
		for(int j = 0; j < animationTypes.size(); j++)
		{
			if(animationTypes[j] == "Fade")
				tempAnimation.push_back(std::shared_ptr<Animation>(new Animation));
			tempAnimation[tempAnimation.size() - 1]->LoadContent(menuImages[i], menuItems[i], position);
		}
		menuAnim.push_back(tempAnimation);
		/*for(int j = 0; j < tempAnimation.size(); j++)
		{
			delete tempAnimation[j];
		}
		tempAnimation.clear();
	}*/
	for(int i = 0; i < menuItems.size(); i++)
	{
		Animation a;
		animation.push_back(a);
		animation[i].LoadContent(menuImages[i], menuItems[i], position);

		*(pos + 1) += 30;
	}
}

void MenuManager::LoadContent(std::string id)
{
	fileManager.LoadContent("test.txt", category, contents, id);
	position[0] = 0;
	position[1] = 0;
	//itemNumber = 0;

	for(int i = 0; i < category.size(); i++)
	{
		for(int j = 0; j < category[i].size(); j++)
		{
			if(category[i][j] == "MenuItem")
			{
				menuItems.push_back(contents[i][j]);
			}
			else if(category[i][j] == "MenuImage")
			{
				menuImages.push_back(al_load_bitmap(contents[i][j].c_str()));
			}
			else if(category[i][j] == "Animation")
			{
				animationTypes.push_back(contents[i][j]);
			}
			else if(category[i][j] == "MenuLink")
			{
				menuLinks.push_back(contents[i][j]);
			}
			else if(category[i][j] == "Font")
			{
				font = al_load_font(contents[i][j].c_str(), 30, NULL);
			}
			else if(category[i][j] == "Align")
			{
				align == contents[i][j];
			}
			else if(category[i][j] == "Position")
			{
				std::stringstream str;
				str << contents[i][j];

				std::string tempLine;
				int counter = 0;

				while(std::getline(str, tempLine, ' '))
				{
					position[counter] = atof(tempLine.c_str());
					counter++;
				}
			}
		}
	}
	SetMenuItems();
	SetAnimation();
}

void MenuManager::UnloadContent()
{
	al_destroy_font(font);
	for(int i = 0; i < menuImages.size(); i++)
	{
		al_destroy_bitmap(menuImages[i]);
	}
	menuImages.clear();
	/*for(int i = 0; i < menuAnim.size(); i++)
	{
		for(int j = 0; j < menuAnim[i].size(); j++)
		{
			//delete menuAnim[i][j];
		}
	}*/
	menuItems.clear();
	animationTypes.clear();
	category.clear();
	contents.clear();
}

void MenuManager::Update(ALLEGRO_EVENT ev)
{
	/*if(itemNumber < 0) itemNumber = menuItems.size() - 1;
	else if(itemNumber > menuItems.size() - 1) itemNumber = 0;

	if(input.IsKeyPressed(ev, ALLEGRO_KEY_DOWN))
		itemNumber++;
	else if(input.IsKeyPressed(ev, ALLEGRO_KEY_UP))
		itemNumber--;*/

	if(itemNumber < 0) itemNumber = menuItems.size() - 1;
	else if(itemNumber > menuItems.size() - 1) itemNumber = 0;

	if(input.IsKeyPressed(ev, ALLEGRO_KEY_DOWN))
		itemNumber++;
	else if(input.IsKeyPressed(ev, ALLEGRO_KEY_UP))
		itemNumber--;


	for(int i = 0; i < animation.size(); i++)
	{
		for(int j = 0; j < animationTypes.size(); j++)
		{
			if(itemNumber == i)
			{
				animation[i].IsActive() = true;
				//animation[i].Green() = 230;
			}
			else
			{
				animation[i].IsActive() = false;
				//animation[i].Green() = 117;
			}
			if(animationTypes[j] == "Fade")
				fadeAnimation.Update(animation[i]);
		}
	}
}

void MenuManager::Draw(ALLEGRO_DISPLAY *display)
{
	for(int i = 0; i < animation.size(); i++)
	{
		animation[i].Draw(display);
	}
}

std::string MenuManager::GetMenuLink()
{
	return menuLinks[itemNumber];
}
