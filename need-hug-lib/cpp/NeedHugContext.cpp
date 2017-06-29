#include <Context/NeedHugContext.hpp>

namespace NeedHug
{
	NeedHugContext* NeedHugContext::context = nullptr; // Needed to be able to have a static pointer

	NeedHugContext::~NeedHugContext()
	{
	}

}