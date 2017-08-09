#include <return_code/ReturnCodeConverter.hpp>

#include <stdexcept>

namespace NeedHug
{
	ReturnCodeInfo ReturnCodeConverter::Convert(const ReturnCode& p_returnCode)
	{
		if(p_returnCode == ReturnCode::Unknown)
		{
			return ReturnCodeInfo("Unknown");
		}
		else if(p_returnCode == ReturnCode::Continue)
		{
			return ReturnCodeInfo("Continue");
		}
		else if(p_returnCode == ReturnCode::Stop)
		{
			return ReturnCodeInfo("Stop");
		}
		const std::string message = std::string("Given returnCode does not exist: ").append(std::to_string(static_cast<int>(p_returnCode)));
		throw std::runtime_error(message);
	}
}