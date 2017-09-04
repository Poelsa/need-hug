#ifndef NEEDHUGCONTEXT_HPP
#define NEEDHUGCONTEXT_HPP

#include <memory>

namespace NeedHug
{
	class ComponentManager;
	class Window;

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

	private:
		NeedHugContext();
		~NeedHugContext();
		static NeedHugContext* context;

	private:
		std::shared_ptr<ComponentManager> componentManager;
		std::shared_ptr<Window> window;
	};
}

#endif