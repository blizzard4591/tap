/**
Copyright (c) 2015 Harold Bruintjes

This software is provided 'as-is', without any express or implied
warranty. In no event will the authors be held liable for any damages
arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must not
   claim that you wrote the original software. If you use this software
   in a product, an acknowledgement in the product documentation would be
   appreciated but is not required.
2. Altered source versions must be plainly marked as such, and must not be
   misrepresented as being the original software.
3. This notice may not be removed or altered from any source distribution.
*/

#pragma once

namespace TAP {

template<typename char_t>
inline argument_error<char_t>::argument_error(const Argument<char_t>& arg) :
    exception(std::string("Argument ") + arg.usage()),
    m_arg(new Argument<char_t>(arg)) {
}

template<typename char_t>
inline argument_error<char_t>::argument_error(const Argument<char_t>& arg, const std::string& reason) :
    exception(std::string("Argument ") + arg.usage() + " " + reason),
    m_arg(new Argument<char_t>(arg)) {
}

template<typename char_t>
inline constraint_error<char_t>::constraint_error(const std::string& reason, const std::vector<const BaseArgument<char_t>*>& args) : exception() {
    m_what = reason;
    bool first = true;
    for(auto arg: args) {
        if (!first) {
            m_what += " ";
        } else {
            first = false;
        }
        m_what += arg->usage();
    }
}

}
