#include <context/NeedHugContext.hpp>
#include <component/ComponentManager.hpp>
#include <window/Window.hpp>
#include <context/TimeHandler.hpp>
#include <event/EventManager.hpp>
#include <configuration/ConfigurationManager.hpp>

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
		timeHandler = std::make_shared<TimeHandler>(true);
        configurationManager = std::make_shared<ConfigurationManager>();
	}

	NeedHugContext::~NeedHugContext()
	{
	}
}