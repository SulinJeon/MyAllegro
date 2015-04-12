#include "FileManager.h"


FileManager::FileManager()
{
	identifierFound = false;
}


FileManager::~FileManager()
{
}

void FileManager::LoadContent(const char *filename, std::vector<std::vector<std::string>> &category, std::vector<std::vector<std::string>> &contents)
{
	//���� �ӽö���
	std::string line, tempLine;
	//������ ����
	std::ifstream openfile(filename);
	//������ ���ȴٸ�
	if(openfile.is_open())
	{
		//������ ���������� while
		while(!openfile.eof())
		{
			/*���پ� �о ��Ʈ����Ʈ���� �ְ�
			��Ʈ����Ʈ������ �ٽ� delimiter���� �о tempLine�� ����*/
			std::stringstream str;
			std::getline(openfile, line);

			//ī�װ��̸� "Load=" �� �����ش�
			if(line.find("Load=") != std::string::npos)
			{
				type = LoadType::CATEGORY;
				line = line.erase(0, line.find("=") + 1);
				tempCategory.clear();
			}
			//�������� ���
			else
			{
				type = LoadType::CONTENT;
				tempContents.clear();
			}

			str << line;
			while(std::getline(str, tempLine, ']'))
			{
				/*'['�̰� ã�Ƽ� �����ֱ�*/
				tempLine.erase(std::remove(tempLine.begin(), tempLine.end(), '['), tempLine.end());
				//���� ��ĭ�̳� �� ������� ���� ��������
				std::string erase = " \t\n\r";
				tempLine.erase(tempLine.find_last_not_of(erase) + 1);

				/*LoadType�� ���� temp�� �־��ش�
				�׳� ���Ϳ� �� �ְ� temp�� �־ ���� ���Ϳ� �ִ� ������
				Category�� �ϳ� �̻� ������ ������ �ֱ⶧���� string�� ������ ���͸� ���Ϳ� �����Ѵ�*/
				if(type == LoadType::CATEGORY)
					tempCategory.push_back(tempLine);
				else if(type == LoadType::CONTENT)
					tempContents.push_back(tempLine);

				std::cout << tempLine << std::endl;
			}
			if(type == LoadType::CONTENT && tempContents.size() > 0)
			{
				category.push_back(tempCategory);
				contents.push_back(tempContents);
			}
		}
	}
	else
	{
	}
}

void FileManager::LoadContent(const char *filename, std::vector<std::vector<std::string>> &category, std::vector<std::vector<std::string>> &contents, std::string identifier)
{
	//���� �ӽö���
	std::string line, tempLine;
	//������ ����
	std::ifstream openfile(filename);
	//������ ���ȴٸ�
	if(openfile.is_open())
	{
		//������ ���������� while
		while(!openfile.eof())
		{
			/*���پ� �о ��Ʈ����Ʈ���� �ְ�
			��Ʈ����Ʈ������ �ٽ� delimiter���� �о tempLine�� ����*/
			std::stringstream str;
			std::getline(openfile, line);

			/*EndIdentifier�� ���� �;��ϴ� ������ EndIdentifier������ Identifier�� �־ �׻� ���� ������ �ȴ�
			�׷��� EndIdentifier�� ���� �˻��ؾ���*/
			if(line.find("EndIdentifier=") != std::string::npos && line.find(identifier) != std::string::npos)
			{
				identifierFound = false;
				break;
			}
			//"Identifier=" '��'��α��� ���� �ϴ� ������ ���丮�� �ʿ��� �ܾ �������� �����ϱ� '='���� �����
			else if(line.find("Identifier=") != std::string::npos && line.find(identifier) != std::string::npos)
			{
				identifierFound = true;
				continue;
			}

			if(identifierFound)
			{
				//ī�װ��̸� "Load=" �� �����ش�
				if(line.find("Load=") != std::string::npos)
				{
					type = LoadType::CATEGORY;
					line = line.erase(0, line.find("=") + 1);
					tempCategory.clear();
				}
				//�������� ���
				else
				{
					type = LoadType::CONTENT;
					tempContents.clear();
				}

				str << line;
				while(std::getline(str, tempLine, ']'))
				{
					/*'['�̰� ã�Ƽ� �����ֱ�*/
					tempLine.erase(std::remove(tempLine.begin(), tempLine.end(), '['), tempLine.end());
					//���� ��ĭ�̳� �� ������� ���� ��������
					std::string erase = " \t\n\r";
					tempLine.erase(tempLine.find_last_not_of(erase) + 1);

					/*LoadType�� ���� temp�� �־��ش�
					�׳� ���Ϳ� �� �ְ� temp�� �־ ���� ���Ϳ� �ִ� ������
					Category�� �ϳ� �̻� ������ ������ �ֱ⶧���� string�� ������ ���͸� ���Ϳ� �����Ѵ�*/
					if(type == LoadType::CATEGORY)
						tempCategory.push_back(tempLine);
					else if(type == LoadType::CONTENT)
						tempContents.push_back(tempLine);

					std::cout << tempLine << std::endl;
				}
				if(type == LoadType::CONTENT && tempContents.size() > 0)
				{
					category.push_back(tempCategory);
					contents.push_back(tempContents);
				}
			}
		}
	}
	else
	{
	}
}
