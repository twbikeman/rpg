#include "Game.h"
#include <iostream>

Game::Game(){}

void Game::update()
{
	m_sourceRectangle.x = 128 * ((SDL_GetTicks() / 100) % 6 );
}

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{

	int flags = 0;
	if (fullscreen == true)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}




	if((SDL_INIT_EVERYTHING) != 0)
	{	
		std::cout << "SDL init success\n";

		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		if (m_pWindow !=0)
		{
			std::cout << "Window create success\n";

			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

			if (m_pRenderer != 0)
			{
				std::cout << "Renderer success \n";
			}
			else
			{
				std::cout <<"Renderer  fail\n";
				return false;
			}

		}
		else
		{
			std::cout << "windows create fail\n";
			return false;
		}


	}
	else
	{
		std::cout << "SDL init fail\n";
		return false;

	}

	std::cout << "init success\n";
	


	//SDL_Surface* pTempSurface = IMG_Load("assets/animate-alpha.png");
	SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);
	//m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
	//SDL_FreeSurface(pTempSurface);


	if(TheTextureManager::Instance()->load("assets/animate-alpha.png", "animate",m_pRenderer))
	{
		std::cout << "load success\n";
	}
	


	// SDL_QueryTexture(m_pTexture, NULL, NULL, &m_sourceRectangle.w, &m_sourceRectangle.h);

	
	//m_destinationRectangle.x = m_sourceRectangle.x = 0;
	//m_destinationRectangle.y = m_sourceRectangle.y = 0;
	//m_destinationRectangle.w = m_sourceRectangle.w = 128;
	//m_destinationRectangle.h = m_sourceRectangle.h = 82;






	m_bRunning = true;
	return true;

}

void Game::render()
{
	SDL_RenderClear(m_pRenderer);
	TheTextureManager::Instance()->draw("animate", 0, 0, 128, 82, m_pRenderer, SDL_FLIP_NONE);

	//SDL_RenderCopyEx(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle, 0, 0 , SDL_FLIP_NONE);


	SDL_RenderPresent(m_pRenderer);

}

void Game::clean()
{

	std::cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

void Game::handleEvents()
{

	SDL_Event event;
	if(SDL_PollEvent(&event))
	{
		switch(event.type)
		{
			case SDL_QUIT:
				m_bRunning = false;
			break;

			default:
			break;

		}
	}
}

