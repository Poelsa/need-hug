#ifndef ENTITY_HPP
#define ENTITY_HPP

// #include <need-hug-lib/hpp/ECS/Transform.hpp>

namespace NeedHug
{
	class Component;
	class Transform;

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

	//	Transform& GetTransform() const { return transform; }

	private:
		// Transform transform;
	};
}

#endif