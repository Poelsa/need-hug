#ifndef RETURNCODECONVERTER_HPP
#define RETURNCODECONVERTER_HPP

#include <need-hug-lib/include/return_code/ReturnCode.hpp>
#include <need-hug-lib/include/return_code/ReturnCodeInfo.hpp>

namespace NeedHug
{
    class ReturnCodeConverter
    {
    public:
		ReturnCodeInfo Convert(const ReturnCode& p_returnCode);
    };  
}

#endif