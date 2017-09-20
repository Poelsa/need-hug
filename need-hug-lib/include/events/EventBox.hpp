#ifndef EVENTBOX_HPP
#define EVENTBOX_HPP

#include <vector>
#include <memory>
#include <need-hug-lib/include/events/EventProcessor.hpp>

namespace NeedHug
{
	template<typename U>
	class EventBox
	{
	public:
		EventBox() = default;
		virtual ~EventBox() = default;

		void AddEvent(U&& event) { events.push_back(std::move(event)); }
		void RegisterReceiver(EventProcessor<U>& receiver) { receivers.push_back(receiver); }

	protected:
		void SendEvents();

	private:
		std::vector<U> events;
		std::vector<EventProcessor<U>*> receivers;
	};
}
#endif

