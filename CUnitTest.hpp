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

#include "CTestCore.h"
#include "macro.h"

namespace utest
{
    ////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////
    template <class T>
    void CUnitTest<T>::add(const std::string& inName, bool(T::*inFct)())
    {
        m_testList.push_back(STest{inName, std::mem_fun(inFct)});
    }

    ////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////
    template <class T>
    bool CUnitTest<T>::runTest(const std::unordered_set<std::string>& inList)
    {
        if (m_testList.empty())
        {
            add("main", &T::main);
        }

        bool globalResult = true;

        for (STest& test : m_testList)
        {
            if (inList.empty() || inList.count("*") || inList.count(test.m_name))
            {
                CTestCore<void>::getInstance().startFunction();
                {
                    setUp();
                    {
                        bool result = test.m_fun(static_cast<T*>(this));

                        PRINT("Test ", test.m_name, "... ", result ? COLOR_GREEN "OK" COLOR_END : COLOR_RED "FAILED" COLOR_END);

                        globalResult &= result;
                    }
                    tearDown();
                }
                CTestCore<void>::getInstance().endFunction();
            }
        }

        return globalResult;
    }
}
