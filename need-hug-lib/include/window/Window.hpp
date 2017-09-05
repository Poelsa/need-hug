#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <return_code/ReturnCode.hpp>

#include <SFML/Graphics.hpp>
#include <cstdint>
#include <memory>

namespace NeedHug
{
	class Window
	{
	public:
		Window();
		virtual ~Window();

		void SetupWindow(std::uint32_t windowWidth, std::uint32_t windowHeigth);

		ReturnCode Update();

	private:
		std::unique_ptr<sf::RenderWindow> window;
	};
}
#endif