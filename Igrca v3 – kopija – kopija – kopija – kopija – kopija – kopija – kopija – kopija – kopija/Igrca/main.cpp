#include "Game.h"
#include "SDL.h"
#include "Timer.h"
#include <ctime>
#include <cstdlib>

int main(int argc, char* argv[]) {
	srand(time(NULL));
	Game::GetInstance()->Init(1,6,5);

	while (Game::GetInstance()->IsRunning() == 1) {
		Game::GetInstance()->Events();
		Game::GetInstance()->Update(6);
		Game::GetInstance()->Render();
	}
	Game::GetInstance()->Clean();
	if(Game::GetInstance()->IsRunning() != 0)
		Game::GetInstance()->Init(2, 6, 8);
	while (Game::GetInstance()->IsRunning() == 2) {

		Game::GetInstance()->Events();
		Game::GetInstance()->Update(6);
		Game::GetInstance()->Render();
	}
		

	Game::GetInstance()->Clean();
		
	return 0;
}