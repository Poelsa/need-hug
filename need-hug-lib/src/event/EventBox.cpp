#include <need-hug-lib/include/event/EventBox.hpp>

template<typename T>
void NeedHug::EventBox<T>::SendEvents()
{
	for (auto& receiver : receivers)
	{
		receiver.ReceiveEvents(events);
	}
	events = std::make_shared<std::vector<T>>();
}
