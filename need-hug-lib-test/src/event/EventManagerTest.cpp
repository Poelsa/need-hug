#include <gtest/gtest.h>
#include <event/EventManager.hpp>

struct TestEvent : public NeedHug::BaseEvent
{
    uint32_t testInt;
};

TEST(EventManagerTest, SubscribeAndNotify)
{
    uint32_t test = 1;
    NeedHug::EventManager* em = new NeedHug::EventManager();
    uint32_t resp = 0;
    em->Subscribe<TestEvent>([&resp](NeedHug::BaseEvent* pl) {  resp = dynamic_cast<TestEvent*>(pl)->testInt; });
    ASSERT_NE(test, resp);
    TestEvent* ev = new TestEvent();
    ev->testInt = 1;
    em->Notify<TestEvent>(ev);
    ASSERT_EQ(test, resp);
}