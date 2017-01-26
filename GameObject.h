#ifndef __GameObject__
#define __GameObject__

#include "TextureManager.h"

class GameObject
{

public:

	void load(int , int , int , int, std::string);


	void draw(SDL_Renderer*);
	void update();
	void clean();
protected:
	std::string m_textureID;

	int m_currentFrame;
	int m_currentRow;

	int m_x;
	int m_y;

	int m_width;
	int m_height;
};

class Player : public GameObject
{
public:
	void draw()
	{
		GameObject::draw();
		std::cout << "draw player";
	}

	void update();

	void clean()
	{
		GameObject::clean();
		std::cout << "clean player";
	}
}

#endif