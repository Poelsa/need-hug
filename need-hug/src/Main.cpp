#include <need-hug-lib/include/NeedHugGame.hpp>
#include <need-hug-lib/include/ReturnCode/ReturnCodeConverter.hpp>

#include <iostream>

int main(int argc, char** argv)
{
	using namespace NeedHug;
	ReturnCode returnCode = ReturnCode::Continue;
	while(returnCode == NeedHug::ReturnCode::Continue)
	{
		// When the code reaches here, nothing should be allocated any longer in order to avoid memoryleaks.
		NeedHugGame needHugGame;
		try
		{
			returnCode = needHugGame.Start();
		}
		catch(...)
		{
			std::cout << "Game crashed unexpectedly" << std::endl;
			returnCode = ReturnCode::Unknown;
		}
	}
	
	std::cout << "The game returned the following stopCode '" << ReturnCodeConverter().Convert(returnCode).info << "'." << std::endl;
	int returnCodeValue = 1;

	if(returnCode == ReturnCode::Stop)
	{
		returnCodeValue = 0;
	}

	return returnCodeValue;
}
