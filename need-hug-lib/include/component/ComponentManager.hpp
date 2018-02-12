#ifndef NEEDHUG_COMPONENTMANAGER_HPP
#define NEEDHUG_COMPONENTMANAGER_HPP

#include <assert.h>
#include <map>
#include <algorithm>
#include <cstddef>
#include <memory>
#include <vector>

#include <components/BaseComponent.hpp>
#include <components/Component.hpp>

namespace NeedHug
{
	class ComponentManager
	{
	public:
		template <typename T>
		Component<T>* CreateComponent()
		{
			Component<T>* newComp = new Component<T>();
			int id = Component<T>::typeId;
			auto& compIt = components.find(id);
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
			assert(compIt != components.end());

			if (compIt->second.size() == 0)
			{
				return std::make_unique<std::vector<Component<T>*>>(std::vector<Component<T>*>());
			}
			std::vector<Component<T>*> specificCompVec(compIt->second.size());
			std::transform(compIt->second.begin(), compIt->second.end(), specificCompVec.begin(), vectorTarget<T>());
			return std::make_unique<std::vector<Component<T>*>>(specificCompVec);
		}

	private:
		std::map<std::size_t, std::vector<BaseComponent*> > components;
	};
}

#endif