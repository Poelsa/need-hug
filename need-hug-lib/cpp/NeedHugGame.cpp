#include <NeedHugGame.hpp>
#include <iostream>
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

		Component<Transform>* transformComp = NeedHugContext::GetContext().CreateComponent<Transform>();

		std::vector<Component<Transform>*> allTransformComponents = NeedHugContext::GetContext().GetComponents<Transform>();

		returnCode = ReturnCode::Stop; // Temporary test code 
		return returnCode;
	}
}