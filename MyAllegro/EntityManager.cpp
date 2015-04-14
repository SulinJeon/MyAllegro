#include "EntityManager.h"


EntityManager::EntityManager()
{
}


EntityManager::~EntityManager()
{
}

std::vector<Entity*> EntityManager::GetEntities()
{
	return entities;
}

void EntityManager::LoadContent(std::string filename, std::string id, std::string type)
{
	//�̹����� ���������� ����(Ŭ���� ��������� ������ �ʿ䰡 ����)
	std::vector<std::vector<std::string>> category;
	std::vector<std::vector<std::string>> contents;
	FileManager fileManager;
	if(id == "")
		fileManager.LoadContent(filename.c_str(), category, contents);
	else
		fileManager.LoadContent(filename.c_str(), category, contents, id);

	//EntityManager���� �о �ͼ� Entity Ŭ�������� ������ �Ѱ��ְ� ������ Entity���� �ñ��
	//EntityManager���� ���δ� �������� �ҷ��� �ϴϱ� �ڵ尡 ���δ�
	for(int i = 0; i < category.size(); i++)
	{
		Entity *entity;
		if(type == "Player")
			entity = new Player();
		else if(type == "Enemy")
			entity = new Enemy();
		entities.push_back(entity);
		entities[i]->LoadContent(category[i], contents[i]);
	}
}

void EntityManager::UnloadContent()
{
	for(int i = 0; i < entities.size(); i++)
	{
		entities[i]->UnloadContent();
		delete entities[i];
	}
	entities.clear();
}

void EntityManager::Update(ALLEGRO_EVENT ev)
{
	for(int i = 0; i < entities.size(); i++)
	{
		entities[i]->Update(ev);
	}
}

void EntityManager::EntityCollision(EntityManager e2)
{
	for(int i = 0; i < entities.size(); i++)
	{
		for(int j = 0; j < e2.entities.size(); j++)
		{
			if(entities[i]->rect->IsIntersect(*e2.entities[j]->rect))
			{
				std::cout << "collision" << std::endl;
			}
		}
	}
}

void EntityManager::Draw(ALLEGRO_DISPLAY *display)
{
	for(int i = 0; i < entities.size(); i++)
	{
		entities[i]->Draw(display);
	}
}