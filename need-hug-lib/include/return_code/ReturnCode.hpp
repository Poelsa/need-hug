#ifndef RETURNCODE_HPP
#define RETURNCODE_HPP

#include <cstdint>

namespace NeedHug
{
	enum class ReturnCode : std::uint8_t
	{
		Unknown,
		Running,
		Stop_Restart,
		Stop_End
	};
}

#endif
