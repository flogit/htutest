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

namespace utest
{
    class CUnitTestBase
    {
        public:
            virtual ~CUnitTestBase() {}
            virtual bool runTest (const std::unordered_set<std::string> &inList) = 0;
            inline const std::string& getName() const {return m_name;}

        protected:
            CUnitTestBase(const std::string &inName = "anonymous"):m_name(inName){};

        protected:
            std::string m_name;
    };

    template <class T>
    class CUnitTest : public CUnitTestBase
    {
        public: // methods
            CUnitTest(const std::string &inName = "anonymous") : CUnitTestBase(inName) {}
            virtual ~CUnitTest() {};

            void add(const std::string & inName, bool(T::* inFct)());
            bool runTest (const std::unordered_set<std::string> &inList);

            virtual void setUp   ()   {};
            virtual void tearDown()   {};

            virtual bool main() { return true; };

        private: // type declarations
            struct STest
            {
                std::string m_name;
                std::mem_fun_t <bool, T> m_fun;
            };

        private: // members
            std::list<STest> m_testList;
    };
}

#include "CUnitTest.hpp"

// Add others include to minimize the number of include in user-space
#include "CUnitTestSuite.h"
#include "macro.h"
