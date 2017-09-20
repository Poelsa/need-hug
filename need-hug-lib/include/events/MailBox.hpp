#ifndef MAILBOX_HPP
#define MAILBOX_HPP


namespace NeedHug
{
	class MailBox
	{
	public:
		MailBox() = default;
		virtual ~MailBox() = default;

		void SendEvents();
	};
}

#endif
