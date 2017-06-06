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

	ReturnCode NeedHugContext::Start()
	{
		ReturnCode returnCode = ReturnCode::Stop;
		while(true)
		{
			// Do game
			break; // Temporary test code
		}
		returnCode = ReturnCode::Stop; // Temporary test code 
		return returnCode;
	}
}