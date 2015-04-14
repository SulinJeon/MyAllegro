#pragma once

#include "FileManager.h"
#include "Tile.h"
#include <map>

class Layer
{
	private:
	//로드할때 필요한 애들... 사실상 로드안에 지역변수로 만들어도 된다...
	FileManager fileManager;
	std::vector<std::vector<std::string>> category;
	std::vector<std::vector<std::string>> contents;
	//Solid타일 종류들 저장
	std::vector<std::pair<int, int>> solidTiles;
	//Motion타일 저장
	std::map<std::pair<int, int>, std::string> motion;
	//타일클래스형 벡터
	std::vector<Tile> tiles;
	//텍스트파일에서 float형으로 변환해줌
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

