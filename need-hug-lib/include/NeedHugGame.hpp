#ifndef NEEDHUGGAME_HPP
#define NEEDHUGGAME_HPP

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
	};
}

#endif