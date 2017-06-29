#ifndef NEEDHUGGAME_HPP
#define NEEDHUGGAME_HPP

#include <need-hug-lib/hpp/ReturnCode/ReturnCode.hpp>

namespace NeedHug
{
	class NeedHugGame
	{
public:
	NeedHugGame();
	virtual ~NeedHugGame();

	ReturnCode Start();
private:
	};
}

#endif