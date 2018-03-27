#ifndef NEEDHUG_NEEDHUGCONTEXT_HPP
#define NEEDHUG_NEEDHUGCONTEXT_HPP

#include <memory> // std::shred_ptr

namespace NeedHug
{
	class ComponentManager;
	class Window;
	class TimeHandler;
    class ConfigurationManager;

	class NeedHugContext final
	{
	public:
		//// Singleton functions
		NeedHugContext(const NeedHugContext& needHugContext) = delete;
		NeedHugContext(NeedHugContext&& needHugContext) = delete;
		NeedHugContext& operator=(const NeedHugContext& needHugContext) = delete;
		NeedHugContext& operator=(NeedHugContext&& needHugContext) = delete;
		static void Create();
		static void Destroy();
		static NeedHugContext& GetContext();
		
		//// Get functions

		// TODO docs
		std::shared_ptr<Window> GetWindow() const { return window; }

		// TODO docs
		std::shared_ptr<ComponentManager> GetComponentManager() const { return componentManager; }

		// TODO docs
		std::shared_ptr<TimeHandler> GetTimeHandler() const { return timeHandler; }

        // TODO docs
        std::shared_ptr<ConfigurationManager> GetConfigurationManager() const { return configurationManager; }

	private:
		NeedHugContext();
		~NeedHugContext();
		static NeedHugContext* context;

	private:
		std::shared_ptr<ComponentManager> componentManager;
		std::shared_ptr<Window> window;
		std::shared_ptr<TimeHandler> timeHandler;
        std::shared_ptr<ConfigurationManager> configurationManager;
	};
}

#endif