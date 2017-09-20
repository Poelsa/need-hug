#include <need-hug-lib/include/events/EventBox.hpp>

template<typename U>
void NeedHug::EventBox<U>::SendEvents()
{
	for (auto& receiver : receivers)
	{
		receiver.ReceiveEvents(events);
	}
	events.clear();
}
