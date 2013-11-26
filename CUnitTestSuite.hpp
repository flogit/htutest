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

namespace htutest
{
    ////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////
    CUnitTestSuite::CUnitTestSuite(const std::initializer_list<CUnitTestBase*>& in_list) :
        m_test_list(in_list)
    {
    }

    ////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////
    CUnitTestSuite::CUnitTestSuite(CUnitTestBase* in_test) :
        m_test_list({in_test})
    {
    }

    ////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////
    CUnitTestSuite::~CUnitTestSuite()
    {
        for(auto test : m_test_list)
        {
            delete test;
        }
        m_test_list.clear();
    }

    ////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////
    int
    CUnitTestSuite::run(int in_argc, char** in_argv)
    {
        bool global_result = true;

        std::map<std::string, std::unordered_set<std::string>> test_map_from_parsing;
        bool list_available_test = false;
        parse_args(in_argc, in_argv, test_map_from_parsing, list_available_test);

        if (list_available_test)
        {
            for(auto test : m_test_list)
            {
                HTUTEST_PRINT(test->get_name());
            }
        }
        else
        {
            bool at_least_one_test_launched = false;
            for(auto test : m_test_list)
            {
                auto found_iter = test_map_from_parsing.find(test->get_name());

                if (found_iter != test_map_from_parsing.cend())
                {
                    at_least_one_test_launched = true;

                    HTUTEST_PRINT(" Start the test ", HTUTEST_COLOR_ORANGE, test->get_name(), HTUTEST_COLOR_END);
                    HTUTEST_PRINT("/-------------------------------");

                    bool result = test->run_test(found_iter->second);

                    HTUTEST_PRINT("\\-------------------------------");
                    HTUTEST_PRINT(" End of the test ", HTUTEST_COLOR_ORANGE, test->get_name(), HTUTEST_COLOR_END, " (", result ? HTUTEST_COLOR_GREEN "OK" HTUTEST_COLOR_END : HTUTEST_COLOR_RED "FAIL" HTUTEST_COLOR_END, ")");
                    HTUTEST_PRINT();

                    global_result &= result;
                }
            }

            if (at_least_one_test_launched)
            {
                HTUTEST_PRINT("Global result of the test : ", global_result ? HTUTEST_COLOR_GREEN "OK" HTUTEST_COLOR_END : HTUTEST_COLOR_RED "FAIL" HTUTEST_COLOR_END);
            }
            else
            {
                HTUTEST_PRINT("No test launched");
            }
        }

        return global_result ? 0 : 1;
    }

    ////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////
    void
    CUnitTestSuite::parse_args(int in_argc,
                               char** in_argv,
                               std::map<std::string, std::unordered_set<std::string>>& out_test_list_from_parsing,
                               bool& out_list_available_test)
    {
        out_list_available_test = false;

        for (unsigned int arg_idx = 1; arg_idx < (unsigned int) in_argc; ++arg_idx)
        {
            std::string arg(in_argv[arg_idx]);

            if (arg == "-l")
            {
                out_list_available_test = true;
            }

            size_t separator = arg.find_first_of("/");
            if (separator != std::string::npos)
            {
                std::string test_name   = arg.substr(0, separator);
                std::string test_method = arg.substr(separator + 1);
                out_test_list_from_parsing[test_name].insert(test_method);
            }
            else
            {
                const std::string& test_name = arg;
                out_test_list_from_parsing[test_name].insert("*");
            }
        }

        if (out_test_list_from_parsing.empty())
        {
            for(auto test : m_test_list)
            {
                out_test_list_from_parsing[test->get_name()].insert("*");
            }
        }
    }
}
