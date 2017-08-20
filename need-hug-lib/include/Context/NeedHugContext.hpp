#ifndef NEEDHUGCONTEXT_HPP
#define NEEDHUGCONTEXT_HPP

#include <vector>
#include <map>
#include <algorithm>
#include <memory>
#include <ecs/Entity.hpp>
#include <need-hug-lib/include/components/Transform.hpp>
#include <need-hug-lib/include/components/Component.hpp>
#include <memory>

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

		// --- Game stuff ---
		template <typename T>
		Component<T>* CreateComponent()
		{
			Component<T>* newComp = new Component<T>();
			int id = Component<T>::typeId;
			auto compIt = components.find(id);
			if (compIt != components.end())
			{
				compIt->second.push_back(newComp);
			}
			else
			{
				components.emplace(id, std::vector<BaseComponent*> {newComp});
			}
			return newComp;
		}

		template <typename T>
		struct vectorTarget
		{
			Component<T>* operator () (BaseComponent* value) const
			{
				return dynamic_cast<Component<T>*>(value);
			}
		};

		template <typename T>
		std::unique_ptr<std::vector<Component<T>*>> GetComponents()
		{
			auto compIt = components.find(Component<T>::typeId);

			if (compIt != components.end())
			{
				if (compIt->second.size() == 0)
				{
					return std::make_unique<std::vector<Component<T>*>>(std::vector<Component<T>*>());
				}
				std::vector<Component<T>*> specificCompVec(compIt->second.size());
				std::transform(compIt->second.begin(), compIt->second.end(), specificCompVec.begin(), vectorTarget<T>());
				return std::make_unique<std::vector<Component<T>*>>(specificCompVec);
			}
			else
			{
				throw 1;
			}
		}

	private:
		NeedHugContext();
		~NeedHugContext();

		static NeedHugContext* context;

		// --- Game engine stuff ---
		std::vector<Entity> entities;
		std::map<int, std::vector<BaseComponent*> > components;

	private:
		std::shared_ptr<Window> window;
	};
}

#endif