#ifndef EVENTBOX_HPP
#define EVENTBOX_HPP

#include <vector>
#include <memory>
#include <need-hug-lib/include/events/EventProcessor.hpp>

namespace NeedHug
{
	template<typename T>
	class EventBox
	{
	public:
		EventBox() : events(std::make_shared<std::vector<T>>(new std::vector<T>())) {};
		virtual ~EventBox() = default;

		void AddEvent(T&& event) { events.push_back(std::move(event)); }
		void RegisterReceiver(EventProcessor<T>& receiver) { receivers.push_back(receiver); }

	protected:
		void SendEvents();

	private:
		std::shared_ptr<std::vector<T>> events;
		std::vector<EventProcessor<T>*> receivers;
	};
}
#endif

