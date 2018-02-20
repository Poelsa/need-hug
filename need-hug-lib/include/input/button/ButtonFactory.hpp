#ifndef NEEDHUG_BUTTONFACTORY_HPP
#define NEEDHUG_BUTTONFACTORY_HPP

#include <vector>
#include <memory>

#include <input/button/Button.hpp>

namespace NeedHug
{
    static std::vector<std::unique_ptr<Button>> GetSFMLButtons();
}

#endif