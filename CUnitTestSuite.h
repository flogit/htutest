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
#include <map>
#include <list>
#include <unordered_set>

namespace htutest
{
    class CUnitTestBase;

    class CUnitTestSuite
    {
        public: // methods
            inline CUnitTestSuite(const std::initializer_list<CUnitTestBase*>& in_list);
            inline CUnitTestSuite(CUnitTestBase* in_test);
            inline virtual ~CUnitTestSuite();

            ///@return Error code of a main function (0 : OK, 1 : at least one test has failed)
            inline int run(int in_argc = 0, char** in_argv = 0);

        private: // methods
            CUnitTestSuite(){}
            inline void parse_args(int in_argc,
                                   char** in_argv,
                                   std::map<std::string, std::unordered_set<std::string>>& out_test_list_from_parsing,
                                   bool& out_list_available_test);

        protected: // members
            std::list<CUnitTestBase*> m_test_list;
    };
}

#include "CUnitTestSuite.hpp"
