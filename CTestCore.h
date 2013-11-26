 //  HTutest - Header only and trivial library for unit tests
 //  Copyright (C) 2013
 //
 //  This library is free software; you can redistribute it and/or
 //  modify it under the terms of the GNU Lesser General Public
 //  License as published by the Free Software Foundation; either
 //  version 2.1 of the License, or (at your option) any later version.
 //
 //  This library is distributed in the hope that it will be useful,
 //  but WITHOUT ANY WARRANTY; without even the implied warranty of
 //  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 //  Lesser General Public License for more details.
 //
 //  You should have received a copy of the GNU Lesser General Public
 //  License along with this library; if not, write to the Free Software
 //  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

#pragma once

namespace htutest
{
    template <typename T>
    class CTestCore
    {
        public: // methods

            inline static CTestCore<T>& get_instance();

            inline void fail_if(bool in_condition,
                                const std::string& in_message,
                                const std::string& in_expression,
                                const std::string& in_file,
                                unsigned int in_line);

            template<typename... Args>
            inline void print(const Args&... in_other) const;

            inline void start_function();
            inline bool get_function_state() const;
            inline void end_function();

        private: // methods

            template<typename Arg0, typename... Args>
            inline void rec_print(const Arg0& in_arg0, const Args&... in_other) const;

            inline void rec_print() const;

            inline CTestCore();

        private: // members

            bool m_function_state;

            unsigned int m_indentation;

            static CTestCore* m_p_instance;
    };

    template <typename T>
     CTestCore<T>* CTestCore<T>::m_p_instance = 0;
}

#include "CTestCore.hpp"
