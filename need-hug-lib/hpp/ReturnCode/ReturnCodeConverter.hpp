#ifndef RETURNCODECONVERTER_HPP
#define RETURNCODECONVERTER_HPP

#include <need-hug-lib/hpp/ReturnCode/ReturnCode.hpp>
#include <need-hug-lib/hpp/ReturnCode/ReturnCodeInfo.hpp>

namespace NeedHug
{
    class ReturnCodeConverter
    {
    public:
		ReturnCodeInfo Convert(const ReturnCode& p_returnCode);
    };  
}

#endif