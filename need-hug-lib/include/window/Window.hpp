#ifndef NEEDHUG_WINDOW_HPP
#define NEEDHUG_WINDOW_HPP

#include <cstdint> // std::uint32_t
#include <memory> // std::unique_ptr

#include <SFML/Graphics.hpp>

#include <return_code/ReturnCode.hpp>

namespace NeedHug
{
	class Window
	{
	public:
		Window() = default;
		virtual ~Window();

		void SetupWindow(const std::uint32_t windowWidth, const std::uint32_t windowHeigth);

		ReturnCode Update();

	private:
		std::unique_ptr<sf::RenderWindow> window;
	};
}
#endif