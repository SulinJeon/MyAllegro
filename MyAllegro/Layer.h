#pragma once

#include "FileManager.h"
#include "Tile.h"
#include <map>

class Layer
{
	private:
	//�ε��Ҷ� �ʿ��� �ֵ�... ��ǻ� �ε�ȿ� ���������� ���� �ȴ�...
	FileManager fileManager;
	std::vector<std::vector<std::string>> category;
	std::vector<std::vector<std::string>> contents;
	//SolidŸ�� ������ ����
	std::vector<std::pair<int, int>> solidTiles;
	//MotionŸ�� ����
	std::map<std::pair<int, int>, std::string> motion;
	//Ÿ��Ŭ������ ����
	std::vector<Tile> tiles;
	//�ؽ�Ʈ���Ͽ��� float������ ��ȯ����
	std::pair<int, int> SetTiles(std::string tileString);

	ALLEGRO_BITMAP *tileSheet;

	public:
	Layer();
	~Layer();

	void LoadContent(std::string layerID);
	void UnloadContent();
	void Update(ALLEGRO_EVENT ev, Entity &e);
	void Draw(ALLEGRO_DISPLAY *display);
};

