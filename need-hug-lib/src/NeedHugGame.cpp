#include <NeedHugGame.hpp>
#include <iostream>
#include <window/Window.hpp>
#include <context/NeedHugContext.hpp>
#include <context/TimeHandler.hpp>

#include <event/EventManager.hpp>

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

        NeedHugContext::GetContext().GetEventManager()->Subscribe<TestEvent>([](BaseEvent* pl) { std::cout << dynamic_cast<TestEvent*>(pl)->a << std::endl; });

		while (gameStatus == ReturnCode::Running)
		{
			gameStatus = NeedHugContext::GetContext().GetWindow()->Update();
		}

		gameStatus = ReturnCode::Stop_End; // Temporary test code 
		return gameStatus;
	}
    
	void NeedHugGame::GameLogicLoop()
	{
        TestEvent* hej = new TestEvent();
		while (gameStatus == ReturnCode::Running)
		{
			// Do game
			NeedHugContext::GetContext().GetTimeHandler()->Update();
            hej->a = static_cast<int>(NeedHugContext::GetContext().GetTimeHandler()->GetTotalTime());
            if(hej->a > 1)
                NeedHugContext::GetContext().GetEventManager()->Notify<TestEvent>(hej);
		}
	}
}