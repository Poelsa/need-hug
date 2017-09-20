#ifndef BASE_COMPONENT_HPP
#define BASE_COMPONENT_HPP

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