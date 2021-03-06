#include <window/Window.hpp>

#include <context/NeedHugContext.hpp>
#include <context/TimeHandler.hpp>

#include <cmath>

namespace NeedHug
{
	Window::~Window() = default;

	void Window::SetupWindow(const std::uint32_t windowWidth, const std::uint32_t windowHeigth)
	{
		window = std::make_unique<sf::RenderWindow>(sf::VideoMode(windowWidth, windowHeigth), "SFML works!");
	}

	ReturnCode Window::Update()
	{
		ReturnCode returnCode {ReturnCode::Running};
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
            	returnCode = ReturnCode::Stop_End;
                window->close();
            }
        }

        window->clear();
		sf::CircleShape shape(100.f);
		shape.setFillColor(sf::Color::Green);
		shape.setPosition(std::sin((NeedHugContext::GetContext().GetTimeHandler()->GetTotalTime()))*100.0f, 0.0f);
        window->draw(shape);
        window->display();
        return returnCode;
	}
}