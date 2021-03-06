#pragma once

#include "Entity.h"
#include "FileManager.h"
#include "Player.h"
#include "Enemy.h"

class EntityManager
{
	public:
	EntityManager();
	~EntityManager();

	void LoadContent(std::string filename, std::string id, std::string type);
	void UnloadContent();
	void Update(ALLEGRO_EVENT ev);
	void EntityCollision(EntityManager e2);
	void Draw(ALLEGRO_DISPLAY *display);

	std::vector<Entity*> GetEntities();
	//std::vector<Entity*> entities;

	private:
	std::vector<Entity*> entities;
};

