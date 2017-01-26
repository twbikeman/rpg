#ifndef __TextureManager__
#define __TextureManager__


#include <map>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


class TextureManager
{
public:
	static TextureManager* Instance();


	bool load(std::string, std::string, SDL_Renderer*);
	void draw(std::string , int  , int , int , int , SDL_Renderer* , SDL_RendererFlip = SDL_FLIP_NONE);
	void drawFrame(std::string , int , int , int , int , int , int , SDL_Renderer* , SDL_RendererFlip = SDL_FLIP_NONE);



private:
	TextureManager(){}
	static TextureManager* s_pInstance;

	std::map <std::string, SDL_Texture*> m_textureMap;
};


typedef TextureManager TheTextureManager;

#endif