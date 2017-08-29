#ifndef NEEDHUGCONTEXT_HPP
#define NEEDHUGCONTEXT_HPP

#include <vector>
#include <memory>
#include <ecs/Entity.hpp>
#include <component/ComponentManager.hpp>

namespace NeedHug
{
	class Window;

	class NeedHugContext
	{
	public:
		static void Create();

		static void Destroy();

		static NeedHugContext& GetContext();

		std::shared_ptr<Window> GetWindow() const { return window; }
		
		std::shared_ptr<ComponentManager> GetComponentManager() const { return componentManager; }

	private:
		NeedHugContext();
		~NeedHugContext();

		static NeedHugContext* context;

		// --- Game engine stuff ---
		std::vector<Entity> entities;

	private:
		std::shared_ptr<Window> window;
		std::shared_ptr<ComponentManager> componentManager;
	};
}

#endif