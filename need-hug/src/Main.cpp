#include <NeedHugGame.hpp>
#include <return_code/ReturnCodeConverter.hpp>

#include <iostream>

int main(int argc, char** argv)
{
	using namespace NeedHug;
	ReturnCode returnCode = ReturnCode::Continue;
	while (returnCode == NeedHug::ReturnCode::Continue)
	{
		// When the code reaches here, nothing should be allocated any longer in order to avoid memoryleaks.
		NeedHugGame needHugGame;
		try
		{
			returnCode = needHugGame.Start();
		}
		catch (...)
		{
			std::cout << "Game crashed unexpectedly" << std::endl;
			returnCode = ReturnCode::Unknown;
		}
	}

	std::cout << "The game returned the following stopCode '" << ReturnCodeConverter().Convert(returnCode).info << "'." << std::endl;
	int returnCodeValue = 1;

	if (returnCode == ReturnCode::Stop)
	{
		returnCodeValue = 0;
	}

#ifdef _WIN32
	std::getchar();
#endif
	return returnCodeValue;
}
