#include <NeedHugGame.hpp>
#include <Context/NeedHugContext.hpp>

namespace NeedHug
{
	NeedHugGame::NeedHugGame()
	{
		NeedHugContext::Create();
	}

	NeedHugGame::~NeedHugGame()
	{
		NeedHugContext::Destroy();
	}

	ReturnCode NeedHugGame::Start()
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