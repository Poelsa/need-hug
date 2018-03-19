#ifndef NEEDHUG_STRINGTOSFMLKEY_HPP
#define NEEDHUG_STRINGTOSFMLKEY_HPP

#include <SFML/Window/Keyboard.hpp>
#include <unordered_map>
#include <stdexcept>

namespace NeedHug
{
	static sf::Keyboard::Key ToKey(const std::string& text)
	{
		if (text == "A") { return sf::Keyboard::Key::A; }
		else if (text == "B") { return sf::Keyboard::Key::B; }
		else if (text == "C") { return sf::Keyboard::Key::C; }
		else if (text == "D") { return sf::Keyboard::Key::D; }
		else if (text == "E") { return sf::Keyboard::Key::E; }
		else if (text == "F") { return sf::Keyboard::Key::F; }
		else if (text == "G") { return sf::Keyboard::Key::G; }
		else if (text == "H") { return sf::Keyboard::Key::H; }
		else if (text == "I") { return sf::Keyboard::Key::I; }
		else if (text == "J") { return sf::Keyboard::Key::J; }
		else if (text == "K") { return sf::Keyboard::Key::K; }
		else if (text == "L") { return sf::Keyboard::Key::L; }
		else if (text == "M") { return sf::Keyboard::Key::M; }
		else if (text == "N") { return sf::Keyboard::Key::N; }
		else if (text == "O") { return sf::Keyboard::Key::O; }
		else if (text == "P") { return sf::Keyboard::Key::P; }
		else if (text == "Q") { return sf::Keyboard::Key::Q; }
		else if (text == "R") { return sf::Keyboard::Key::R; }
		else if (text == "S") { return sf::Keyboard::Key::S; }
		else if (text == "T") { return sf::Keyboard::Key::T; }
		else if (text == "U") { return sf::Keyboard::Key::U; }
		else if (text == "V") { return sf::Keyboard::Key::V; }
		else if (text == "W") { return sf::Keyboard::Key::W; }
		else if (text == "X") { return sf::Keyboard::Key::X; }
		else if (text == "Y") { return sf::Keyboard::Key::Y; }
		else if (text == "Z") { return sf::Keyboard::Key::Z; }
		else if (text == "Num0") { return sf::Keyboard::Key::Num0; }
		else if (text == "Num1") { return sf::Keyboard::Key::Num1; }
		else if (text == "Num2") { return sf::Keyboard::Key::Num2; }
		else if (text == "Num3") { return sf::Keyboard::Key::Num3; }
		else if (text == "Num4") { return sf::Keyboard::Key::Num4; }
		else if (text == "Num5") { return sf::Keyboard::Key::Num5; }
		else if (text == "Num6") { return sf::Keyboard::Key::Num6; }
		else if (text == "Num7") { return sf::Keyboard::Key::Num7; }
		else if (text == "Num8") { return sf::Keyboard::Key::Num8; }
		else if (text == "Num9") { return sf::Keyboard::Key::Num9; }
		else if (text == "Escape") { return sf::Keyboard::Key::Escape; }
		else if (text == "LControl") { return sf::Keyboard::Key::LControl; }
		else if (text == "LShift") { return sf::Keyboard::Key::LShift; }
		else if (text == "LAlt") { return sf::Keyboard::Key::LAlt; }
		else if (text == "LSystem") { return sf::Keyboard::Key::LSystem; }
		else if (text == "RControl") { return sf::Keyboard::Key::RControl; }
		else if (text == "RShift") { return sf::Keyboard::Key::RShift; }
		else if (text == "RAlt") { return sf::Keyboard::Key::RAlt; }
		else if (text == "RSystem") { return sf::Keyboard::Key::RSystem; }
		else if (text == "Menu") { return sf::Keyboard::Key::Menu; }
		else if (text == "LBracket") { return sf::Keyboard::Key::LBracket; }
		else if (text == "RBracket") { return sf::Keyboard::Key::RBracket; }
		else if (text == "SemiColon") { return sf::Keyboard::Key::SemiColon; }
		else if (text == "Comma") { return sf::Keyboard::Key::Comma; }
		else if (text == "Period") { return sf::Keyboard::Key::Period; }
		else if (text == "Quote") { return sf::Keyboard::Key::Quote; }
		else if (text == "Slash") { return sf::Keyboard::Key::Slash; }
		else if (text == "BackSlash") { return sf::Keyboard::Key::BackSlash; }
		else if (text == "Tilde") { return sf::Keyboard::Key::Tilde; }
		else if (text == "Equal") { return sf::Keyboard::Key::Equal; }
		else if (text == "Dash") { return sf::Keyboard::Key::Dash; }
		else if (text == "Space") { return sf::Keyboard::Key::Space; }
		else if (text == "Return") { return sf::Keyboard::Key::Return; }
		else if (text == "BackSpace") { return sf::Keyboard::Key::BackSpace; }
		else if (text == "Tab") { return sf::Keyboard::Key::Tab; }
		else if (text == "PageUp") { return sf::Keyboard::Key::PageUp; }
		else if (text == "PageDown") { return sf::Keyboard::Key::PageDown; }
		else if (text == "End") { return sf::Keyboard::Key::End; }
		else if (text == "Home") { return sf::Keyboard::Key::Home; }
		else if (text == "Insert") { return sf::Keyboard::Key::Insert; }
		else if (text == "Delete") { return sf::Keyboard::Key::Delete; }
		else if (text == "Add") { return sf::Keyboard::Key::Add; }
		else if (text == "Subtract") { return sf::Keyboard::Key::Subtract; }
		else if (text == "Multiply") { return sf::Keyboard::Key::Multiply; }
		else if (text == "Divide") { return sf::Keyboard::Key::Divide; }
		else if (text == "Left") { return sf::Keyboard::Key::Left; }
		else if (text == "Right") { return sf::Keyboard::Key::Right; }
		else if (text == "Up") { return sf::Keyboard::Key::Up; }
		else if (text == "Down") { return sf::Keyboard::Key::Down; }
		else if (text == "Numpad0") { return sf::Keyboard::Key::Numpad0; }
		else if (text == "Numpad1") { return sf::Keyboard::Key::Numpad1; }
		else if (text == "Numpad2") { return sf::Keyboard::Key::Numpad2; }
		else if (text == "Numpad3") { return sf::Keyboard::Key::Numpad3; }
		else if (text == "Numpad4") { return sf::Keyboard::Key::Numpad4; }
		else if (text == "Numpad5") { return sf::Keyboard::Key::Numpad5; }
		else if (text == "Numpad6") { return sf::Keyboard::Key::Numpad6; }
		else if (text == "Numpad7") { return sf::Keyboard::Key::Numpad7; }
		else if (text == "Numpad8") { return sf::Keyboard::Key::Numpad8; }
		else if (text == "Numpad9") { return sf::Keyboard::Key::Numpad9; }
		else if (text == "F1") { return sf::Keyboard::Key::F1; }
		else if (text == "F2") { return sf::Keyboard::Key::F2; }
		else if (text == "F3") { return sf::Keyboard::Key::F3; }
		else if (text == "F4") { return sf::Keyboard::Key::F4; }
		else if (text == "F5") { return sf::Keyboard::Key::F5; }
		else if (text == "F6") { return sf::Keyboard::Key::F6; }
		else if (text == "F7") { return sf::Keyboard::Key::F7; }
		else if (text == "F8") { return sf::Keyboard::Key::F8; }
		else if (text == "F9") { return sf::Keyboard::Key::F9; }
		else if (text == "F10") { return sf::Keyboard::Key::F10; }
		else if (text == "F11") { return sf::Keyboard::Key::F11; }
		else if (text == "F12") { return sf::Keyboard::Key::F12; }
		else if (text == "F13") { return sf::Keyboard::Key::F13; }
		else if (text == "F14") { return sf::Keyboard::Key::F14; }
		else if (text == "F15") { return sf::Keyboard::Key::F15; }
		else if (text == "Pause") { return sf::Keyboard::Key::Pause; }
		throw std::invalid_argument("Invalid argument: " + text);
	}
}

#endif