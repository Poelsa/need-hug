#include <NeedHugGame.hpp>
#include <iostream>
#include <context/NeedHugContext.hpp>
#include <window/Window.hpp>
#include <context/TimeHandler.hpp>

namespace NeedHug
{
	NeedHugGame::NeedHugGame() : gameStatus(ReturnCode::Running)
	{
		NeedHugContext::Create();
		logicThread = std::thread(std::bind(&NeedHugGame::GameLogicLoop, this));
	}

	NeedHugGame::~NeedHugGame()
	{
		NeedHugContext::Destroy();
		logicThread.join(); // TODO warning, if this thread stops, then the shutdown freezes.
	}

	ReturnCode NeedHugGame::Start()
	{
		gameStatus = ReturnCode::Running;
		NeedHugContext::GetContext().GetWindow()->SetupWindow(200, 200);

		while (gameStatus == ReturnCode::Running)
		{
			gameStatus = NeedHugContext::GetContext().GetWindow()->Update();
		}

		gameStatus = ReturnCode::Stop_End; // Temporary test code 
		return gameStatus;
	}

	void NeedHugGame::GameLogicLoop()
	{
		while (gameStatus == ReturnCode::Running)
		{
			// Do game
			NeedHugContext::GetContext().GetTimeHandler()->Update();
		}
	}
}