#ifndef NEEDHUG_EVENTPROCESSOR_HPP
#define NEEDHUG_EVENTPROCESSOR_HPP

#include <vector>
#include <memory>
#include <need-hug-lib/include/context/NeedHugContext.hpp>

namespace NeedHug
{
	template <typename T>
	class EventProcessor
	{

		public:
			EventProcessor() { NeedHugContext::GetContext().GetMailBox().RegisterReceiver(this) }
			virtual ~EventProcessor() = default;

			virtual void ReceiveEvents(std::shared_ptr<std::vector<T>>);

	};
}

#endif