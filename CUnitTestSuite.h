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

namespace utest
{
    class CUnitTestBase;

    class CUnitTestSuite
    {
        public: // methods
            inline CUnitTestSuite(const std::initializer_list<CUnitTestBase*>& inList);
            inline CUnitTestSuite(CUnitTestBase* inTest);
            inline virtual ~CUnitTestSuite();

            ///@return Error code of a main function (0 : OK, 1 : at least one test has failed)
            inline int run(int argc = 0, char** argv = 0);

        private: // methods
            CUnitTestSuite(){}
            inline void parse_args(int argc, char** argv, std::map<std::string, std::unordered_set<std::string>>& outTestListFromParsing);

        protected: // members
            std::list<CUnitTestBase*> m_testList;
    };
}

#include "CUnitTestSuite.hpp"
