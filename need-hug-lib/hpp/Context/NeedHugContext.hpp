#ifndef NEEDHUGCONTEXT_HPP
#define NEEDHUGCONTEXT_HPP

//#include <need-hug-lib/hpp/ReturnCode/ReturnCode.hpp>

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
	private:
		NeedHugContext() {}
		virtual ~NeedHugContext();

		static NeedHugContext* context;
	};
}

#endif