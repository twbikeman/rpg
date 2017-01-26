#ifndef __Game__
#define __Game__
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "TextureManager.h"
class Game
{

public: 
	Game();
	~Game();

	bool init(const char* , int, int , int , int, bool);
	void update();
	void handleEvents();

	void render();
	void clean();

	bool running() {return m_bRunning;}

private:
	bool m_bRunning;
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;


	SDL_Texture* m_pTexture;
	SDL_Rect m_sourceRectangle;
	SDL_Rect m_destinationRectangle;

};


#endif