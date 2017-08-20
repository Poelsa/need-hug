#include <gtest/gtest.h>
#include <memory>
#include <need-hug-lib/include/context/NeedHugContext.hpp>
#include <need-hug-lib/include/window/Window.hpp>

using namespace NeedHug;

TEST(contextTest, createFetchDestroy)
{
	NeedHugContext::Create();
	NeedHugContext& context = NeedHugContext::GetContext();
	ASSERT_TRUE(&context != nullptr);
	NeedHugContext::Destroy();
}

TEST(contextTest, getWindow)
{
	NeedHugContext::Create();
	std::shared_ptr<Window> window = NeedHugContext::GetContext().GetWindow();
	ASSERT_TRUE(window != nullptr);
	NeedHugContext::Destroy();
}