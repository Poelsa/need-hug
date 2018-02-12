#ifndef NEEDHUG_SYSTEMMANAGER_HPP
#define NEEDHUG_SYSTEMMANAGER_HPP

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
