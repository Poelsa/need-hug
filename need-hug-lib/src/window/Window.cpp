#include <window/Window.hpp>

namespace NeedHug
{
	Window::Window()
	{

	}

	Window::~Window()
	{

	}

	void Window::SetupWindow(std::uint32_t windowWidth, std::uint32_t windowHeigth)
	{
		window = std::make_unique<sf::RenderWindow>(sf::VideoMode(windowWidth, windowHeigth), "SFML works!");
		sf::CircleShape shape(100.f);
	    shape.setFillColor(sf::Color::Green);

	    while (window->isOpen())
	    {
	        sf::Event event;
	        while (window->pollEvent(event))
	        {
	            if (event.type == sf::Event::Closed)
	                window->close();
	        }

	        window->clear();
	        window->draw(shape);
	        window->display();
	    }
	}
}