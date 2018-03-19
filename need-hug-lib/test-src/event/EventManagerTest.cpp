#include <gtest/gtest.h>
#include <event/EventManager.hpp>
#include <memory>

using NeedHug::EventManager;

bool func1(const float& param)
{
	static int counter = 0;
	cout << "func1: " << param << " counter " << ++counter << endl;
	return false;
}

bool func2(const float& param)
{
	cout << param * 2 << endl;
	return false;
}

struct A
{
	bool m1(const float& param)
	{
		cout << param << endl;
		return false;
	}
};

bool funcSharedPointer1(const std::shared_ptr<float>& param)
{
	static int counter = 0;
	cout << "funcSharedPointer1: " << *param.get() << " counter " << ++counter << endl;
	return false;
}

TEST(EventManagerTest, SubscribeAndNotify)
{
    EventManager<float>::Setup();
    auto& eventMangerFloat = EventManager<float>::GetInstance();
    eventMangerFloat.Subscribe(std::bind(func1, std::placeholders::_1));
    eventMangerFloat.Subscribe(func1, std::placeholders::_1);
    eventMangerFloat.Subscribe(func1);

    eventMangerFloat.QueueEvent(34.7f);
    eventMangerFloat.ProcessEvents();
    EventManager<float>::Teardown();
}

TEST(EventManagerTest, SubscribeAndNotify2)
{
    EventManager<std::shared_ptr<float>>::Setup();
    auto& eventMangerFloat = EventManager<std::shared_ptr<float>>::GetInstance();
	eventMangerFloat.Subscribe(std::bind(funcSharedPointer1, std::placeholders::_1));

    eventMangerFloat.QueueEvent(std::make_shared<float>(1.0f));

    auto payload = std::make_shared<float>(2.0f);
    eventMangerFloat.QueueEvent(payload);

    eventMangerFloat.ProcessEvents();
    EventManager<std::shared_ptr<float>>::Teardown();
}
