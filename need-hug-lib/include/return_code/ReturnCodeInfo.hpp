#ifndef NEEDHUG_RETURNCODEINFO_HPP
#define NEEDHUG_RETURNCODEINFO_HPP

#include <string>
#include <utility>

namespace NeedHug
{
	struct ReturnCodeInfo
	{
		ReturnCodeInfo(std::string p_info) : info(std::move(p_info))
		{

		}
		std::string info;
	};
}

#endif
