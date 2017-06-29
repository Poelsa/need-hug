#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <need-hug-lib/hpp/components/Transform.hpp>

namespace NeedHug
{
	class Entity
	{
	public:
		Entity();
		virtual ~Entity();

		/*
		template<typename T>
		//typename std::enable_if<std::is_base_of<Component, T>::value, void>::type
		T GetComponent() {
			return null;
		}*/

		Transform& GetTransform() { return transform; }

	private:
		Transform transform;
	};
}

#endif