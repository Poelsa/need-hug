#include <context/NeedHugContext.hpp>
#include <component/ComponentManager.hpp>
#include <window/Window.hpp>
#include <cassert>

namespace NeedHug
{
	NeedHugContext* NeedHugContext::context = nullptr; // Needed to be able to have a static pointer

	void NeedHugContext::Create()
	{
		context = new NeedHugContext();
	}

	void NeedHugContext::Destroy()
	{
		delete context;
	}

	NeedHugContext& NeedHugContext::GetContext()
	{
		assert(context != nullptr);
		return *context;
	}

	NeedHugContext::NeedHugContext()
	{
		window = std::make_shared<Window>();
		componentManager = std::make_shared<ComponentManager>();
	}

	NeedHugContext::~NeedHugContext()
	{
	}
}