#pragma once

#include "Layer.h"

class Map
{
	public:
	Map();
	~Map();

	void LoadContent(std::string stageNumber);
	void UnloadContent();
	void Update(ALLEGRO_EVENT ev, Entity &e);
	void Draw(ALLEGRO_DISPLAY *display);

	private:
	std::vector<Layer> layers;
	Layer* layer;
};

