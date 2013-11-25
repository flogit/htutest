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

#include "CUnitTest.h"
#include "macro.h"

namespace utest
{
    ////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////
    CUnitTestSuite::CUnitTestSuite(const std::initializer_list<CUnitTestBase*>& inList) :
        m_testList(inList)    
    {
    }

    ////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////
    CUnitTestSuite::CUnitTestSuite(CUnitTestBase* inTest) :
        m_testList({inTest})
    {
    }

    ////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////
    CUnitTestSuite::~CUnitTestSuite()
    {
        for(auto test : m_testList)
        {
            delete test;
        }
        m_testList.clear();
    }

    ////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////
    int
    CUnitTestSuite::run(int inArgc, char** inArgv)
    {
        bool globalResult = true;

        std::map<std::string, std::unordered_set<std::string>> testMapFromParsing;
        parse_args(inArgc, inArgv, testMapFromParsing);

        for(auto test : m_testList)
        {
            auto foundIter = testMapFromParsing.find(test->getName());

            if (foundIter != testMapFromParsing.cend())
            {
                PRINT(" Start the test ", COLOR_ORANGE, test->getName(), COLOR_END);
                PRINT("/-------------------------------");

                bool result = test->runTest(foundIter->second);

                PRINT("\\-------------------------------");
                PRINT(" End of the test ", COLOR_ORANGE, test->getName(), COLOR_END, " (", result ? COLOR_GREEN "OK" COLOR_END : COLOR_RED "FAIL" COLOR_END, ")");
                PRINT();

                globalResult &= result;
            }
        }

        PRINT("Global result of the test : ", globalResult ? COLOR_GREEN "OK" COLOR_END : COLOR_RED "FAIL" COLOR_END);

        return globalResult ? 0 : 1;
    }

    ////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////
    void
    CUnitTestSuite::parse_args(int inArgc, char** inArgv, std::map<std::string, std::unordered_set<std::string>>& outTestListFromParsing)
    {
        for (unsigned int argIdx = 1; argIdx < (unsigned int) inArgc; ++argIdx)
        {
            std::string arg(inArgv[argIdx]);

            size_t separator = arg.find_first_of("/");
            if (separator != std::string::npos)
            {
                std::string testName   = arg.substr(0, separator);
                std::string testMethod = arg.substr(separator + 1);
                outTestListFromParsing[testName].insert(testMethod);
            }
            else
            {
                const std::string& testName = arg;
                outTestListFromParsing[testName].insert("*");
            }
        }

        if (outTestListFromParsing.empty())
        {
            for(auto test : m_testList)
            {
                outTestListFromParsing[test->getName()].insert("*");
            }
        }
    }
}
