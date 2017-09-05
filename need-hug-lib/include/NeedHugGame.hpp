#ifndef NEEDHUGGAME_HPP
#define NEEDHUGGAME_HPP

#include <thread>

#include <need-hug-lib/include/return_code/ReturnCode.hpp>

namespace NeedHug
{
	class NeedHugGame
	{
public:
	NeedHugGame();
	virtual ~NeedHugGame();

	ReturnCode Start();
private:
	void GameLogicLoop();

	ReturnCode gameStatus;
	std::thread logicThread;
	};
}

#endif