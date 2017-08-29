#include <NeedHugGame.hpp>
#include <iostream>
#include <context/NeedHugContext.hpp>
#include <window/Window.hpp>

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
		NeedHugContext::GetContext().GetWindow()->SetupWindow(200, 200);
		ReturnCode returnCode = ReturnCode::Stop;
		while (true)
		{
			// Do game
			break; // Temporary test code
		}

		returnCode = ReturnCode::Stop; // Temporary test code 
		return returnCode;
	}
}