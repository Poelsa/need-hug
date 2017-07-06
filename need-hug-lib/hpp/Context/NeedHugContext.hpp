#ifndef NEEDHUGCONTEXT_HPP
#define NEEDHUGCONTEXT_HPP

#include <vector>
#include <ecs/Entity.hpp>

namespace NeedHug
{
	class NeedHugContext
	{
	public:
		static void Create() 
		{
			context = new NeedHugContext();
		}
		static void Destroy()
		{
			delete context;
		}
		static NeedHugContext& GetContext()
		{
			return *context;
		}

		// --- Game stuff ---
		
		
	private:
		NeedHugContext() {}
		virtual ~NeedHugContext();

		static NeedHugContext* context;

		// --- Game engine stuff ---
		std::vector<Entity> entities;
	};
}

#endif