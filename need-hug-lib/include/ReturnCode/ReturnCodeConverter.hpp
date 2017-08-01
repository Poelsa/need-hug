#ifndef RETURNCODECONVERTER_HPP
#define RETURNCODECONVERTER_HPP

#include <need-hug-lib/include/ReturnCode/ReturnCode.hpp>
#include <need-hug-lib/include/ReturnCode/ReturnCodeInfo.hpp>

namespace NeedHug
{
    class ReturnCodeConverter
    {
    public:
		ReturnCodeInfo Convert(const ReturnCode& p_returnCode);
    };  
}

#endif