#ifndef SYSTEMMANAGER_HPP
#define SYSTEMMANAGER_HPP

#include "vector"
#include <ecs/System.hpp>

namespace NeedHug
{
	class SystemManager final
	{
	public:
		SystemManager();
		virtual ~SystemManager();

		void Update();
		void Initialize();
		void Teardown();

	private:
		std::vector<System> systems;
	};
}
#endif
