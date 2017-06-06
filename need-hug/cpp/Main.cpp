#include <need-hug-lib/hpp/NeedHugContext.hpp>
#include <need-hug-lib/hpp/ReturnCode/ReturnCodeConverter.hpp>
#include <iostream>

int main(int argc, char** argv)
{
	using namespace NeedHug;
	ReturnCode returnCode = ReturnCode::Continue;
	while(returnCode == NeedHug::ReturnCode::Continue)
	{
		{
			NeedHugContext needHugContext;
			try
			{
				returnCode = needHugContext.Start();
			}
			catch(...)
			{
				std::cout << "Game crashed unexpectedly" << std::endl;
			}
		}
		// When the code reaches here, nothing should be allocated anylonger in order to avoid memoryleaks.
	}

	std::cout << "The game returned the following stopCode '" << ReturnCodeConverter().Convert(returnCode).info << "'." << std::endl;
	int returnCodeValue = 1;

	if(returnCode == ReturnCode::Stop)
	{
		returnCodeValue = 0;
	}

	return returnCodeValue;
}