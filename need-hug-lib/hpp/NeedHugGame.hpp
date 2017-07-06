#ifndef NEEDHUGGAME_HPP
#define NEEDHUGGAME_HPP

#include <need-hug-lib/hpp/ReturnCode/ReturnCode.hpp>
#include <vector>
#include <map>
#include <algorithm>
#include <need-hug-lib/hpp/components/Transform.hpp>
#include <need-hug-lib/hpp/components/Component.hpp>

namespace NeedHug
{
	class NeedHugGame
	{
public:
	NeedHugGame();
	virtual ~NeedHugGame();

	ReturnCode Start();

	template<typename T>
	Component<T>* CreateComponent()
	{
		Component<T>* a = new Component<T>();
		int id = Component<T>::typeId;
		auto hej = components.find(id);
		if (hej != components.end())
		{
			hej->second.push_back(a);
		}
		else
		{
			components.emplace(id, std::vector<BaseComponent*> {a});
		}
		return a;
	}
	std::map<int, std::vector<BaseComponent*> > components;

	template <typename T>
	struct vectorTarget { T* operator ()( BaseComponent* value ) const { return dynamic_cast<T*>(value); } };

	template<typename T>
	std::vector<Component<T>*> GetComponents()
	{
		int id = Component<T>::typeId;
		auto it = components.find(id);
		
		if (it != components.end())
		{
			std::vector<Component<T>*> ny;
			std::transform(it->second.begin(), it->second.end(), ny.begin(), vectorTarget<T>() );
			return ny;
		}
		else
		{
			throw 1;
		}
	}
private:
	};
}

#endif