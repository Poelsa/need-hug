#include <NeedHugGame.hpp>
#include <Context/NeedHugContext.hpp>
#include <iostream>


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

		Component<Transform>* a = CreateComponent<Transform>();

		std::vector<Component<Transform>*> hej = GetComponents<Transform>();

		returnCode = ReturnCode::Stop; // Temporary test code 
		return returnCode;
	}
}