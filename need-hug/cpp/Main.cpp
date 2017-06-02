#include <need-hug-lib/hpp/NeedHugContext.hpp>
#include <iostream>

// TODO Move this into shared file and convert into enum class.
const int CLEAN_SHUTDOWN = 0;
const int DEFAULT_STOP_SIGNAL = 1;
const int UNEXPECTED_CRASH_SIGNAL = 2;

int RunGame()
{
	int returnCode = DEFAULT_STOP_SIGNAL;
	using namespace NeedHug;
	NeedHugContext needHugContext;
	try
	{
		returnCode = needHugContext.Start();
	}
	catch(...)
	{
		std::cout << "Game crashed unexpectedly" << std::endl;
		returnCode = UNEXPECTED_CRASH_SIGNAL;
	}
	return returnCode;
}

int main(int argc, char** argv)
{
	int returnCode = DEFAULT_STOP_SIGNAL;
	while(returnCode == DEFAULT_STOP_SIGNAL)
	{
		returnCode = RunGame();
		// When the code reaches here, nothing should be allocated anylonger in order to avoid memoryleaks.
	}

	if(returnCode != CLEAN_SHUTDOWN)
	{
		std::cout << "Stopped game with returnCode: " << returnCode << std::endl;
	}

	return returnCode;
}