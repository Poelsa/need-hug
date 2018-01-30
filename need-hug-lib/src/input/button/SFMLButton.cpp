#include <input/button/SFMLButton.hpp>
#include <input/ConstraintSolver.hpp>

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
        return ResolveConstraint(isPressed, wasPressed, definition.constraint);
	}

	bool SFMLButton::DoStuff()
	{
		definition.dispatchAction();
		return false; // TODO
	}
}