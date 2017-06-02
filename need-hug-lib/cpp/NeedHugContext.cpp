#include <NeedHugContext.hpp>
#include <iostream>

namespace NeedHug
{
	NeedHugContext::NeedHugContext()
	{
		std::cout << "GAME STARTED! WHOO!" << std::endl;
	}

	NeedHugContext::~NeedHugContext()
	{
		std::cout << "GAME STOPPED! WHOO!" << std::endl;
	}

	int NeedHugContext::Start()
	{
		int returnCode = 1;
		while(returnCode == 1)
		{
			// Do game
			returnCode = 0;
		}
		return returnCode;
	}
}