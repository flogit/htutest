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

#include <string>
#include <unordered_set>
#include <list>

namespace htutest
{
    class CUnitTestBase
    {
        public:
            virtual ~CUnitTestBase() {}

            virtual bool run_functions(const std::unordered_set<std::string>& in_function_list) = 0;
            virtual void list_functions() const = 0;

            const std::string& get_name() const { return m_name; }

        protected:
            CUnitTestBase(const std::string &in_name = "anonymous") : m_name(in_name) {};

        protected:
            std::string m_name;
    };

    template <class T>
    class CUnitTest : public CUnitTestBase
    {
        public: // methods
            CUnitTest(const std::string &in_name = "anonymous") : CUnitTestBase(in_name) {}
            virtual ~CUnitTest() {};

            inline void add(const std::string& in_function_name, bool(T::* in_p_function)());
            inline bool run_functions(const std::unordered_set<std::string> &in_function_list);

            inline void list_functions() const;

            virtual void set_up   ()   {}
            virtual void tear_down()   {}

            virtual bool main() { return true; };

        private: // type declarations
            struct SFunction
            {
                std::string m_name;
                std::mem_fun_t<bool, T> m_fun;
            };

        private: // members
            std::list<SFunction> m_function_list;
    };
}

#include "CUnitTest.hpp"

// Add others include to minimize the number of include in user-space
#include "CUnitTestSuite.h"
#include "macro.h"
