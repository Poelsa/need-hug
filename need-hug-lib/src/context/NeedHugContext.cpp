#include <context/NeedHugContext.hpp>
#include <component/ComponentManager.hpp>
#include <window/Window.hpp>
#include <context/TimeHandler.hpp>
#include <cassert>
#include <need-hug-lib/include/event/MailBox.hpp>

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
		mailbox = std::make_shared<MailBox>();
	}

	NeedHugContext::~NeedHugContext()
	{
	}
}