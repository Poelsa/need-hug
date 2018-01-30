#include <input/button/SFMLButton.hpp>
#include <stdexcept>

namespace NeedHug
{
	sf::Keyboard::Key ConvertStringToSFKey(const std::string& key)
	{
		if (key == "space")
		{
			return sf::Keyboard::Space;
		}
		throw std::runtime_error("Here wrong");
	}

	SFMLButton::SFMLButton(const ButtonActionDefinition& definition)
		: definition(definition), sfKey(ConvertStringToSFKey(definition.key))
	{
	}

	bool SFMLButton::IsValid()
	{
		wasPressed = isPressed;
		isPressed = sf::Keyboard::isKeyPressed(sfKey);
		return false; // TODO
		// return ConstraintSolver(isPressed, wasPressed);
	}

	bool SFMLButton::DoStuff()
	{
		definition.dispatchAction();
		return false; // TODO
	}
}