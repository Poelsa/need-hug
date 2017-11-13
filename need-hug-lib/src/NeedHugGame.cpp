#include <NeedHugGame.hpp>
#include <iostream>
#include <window/Window.hpp>
#include <context/NeedHugContext.hpp>
#include <context/TimeHandler.hpp>
#include <input/InputHandler.hpp>

#include <event/EventManager.hpp>
#include <events/BaseEvent.hpp>

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

		NeedHugContext::GetContext().GetEventManager()->Subscribe<EventJump*>([](NeedHug::BaseEvent* pl) {  std::cout << dynamic_cast<EventJump*>(pl)->player << std::endl; });

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
			NeedHugContext::GetContext().GetInputHandler()->Update();
		}
	}
}