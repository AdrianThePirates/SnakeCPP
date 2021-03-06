/*
 * @file: GameManager.h
 * @author: Stig M. Halvorsen <halsti@nith.no>
 * @version: 1.0.0 <11.02.2013>
 *
 * @description: A singleton class to control all gameplay.
 */

#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "SDL/SDLManager.h"
#include "GameInfo.h"
#include "SDL/SDLBmp.h"
#include "InputManager.h"
#include "Timer.h"
#include "GameInfo.h"

class GameManager
{
public:
	/* Meyer's singleton style instance call */
	static GameManager& Instance()
	{
		static GameManager g;
		return g;
	}

	/* Kicks off/is the the gameloop */
	void play();
private:
	GameManager();								// Hidden constructor
	GameManager(const GameManager&);			// Hidden copy constructor
	GameManager& operator=(const GameManager&); // Hidden assign operator

	~GameManager() {
		free(m_gameInfo);
	}

	void changeDirection(int *direction);
	void render();
	bool checkBorderCollision(SDLBmp *player, GameInfo *gameInfo);
	
	GameInfo *m_gameInfo;
	unsigned int m_window; // pointer to main window
	float m_lastRender; // Time in seconds since last render
};

#endif