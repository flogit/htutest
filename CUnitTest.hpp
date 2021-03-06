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

namespace htutest
{
    ////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////
    template <class T>
    void CUnitTest<T>::add(const std::string& in_function_name, bool(T::*in_p_function)())
    {
        m_function_list.push_back(SFunction{in_function_name, std::mem_fun(in_p_function)});
    }

    ////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////
    template <class T>
    bool CUnitTest<T>::run_functions(const std::unordered_set<std::string>& in_function_list)
    {
        if (m_function_list.empty())
        {
            add("main", &T::main);
        }

        bool global_result = true;

        for (SFunction& function : m_function_list)
        {
            if (in_function_list.empty() || in_function_list.count("*") || in_function_list.count(function.m_name))
            {
                CTestCore<void>::get_instance().start_function();
                {
                    set_up();
                    {
                        bool result = function.m_fun(static_cast<T*>(this));

                        HTUTEST_PRINT("Test ", function.m_name, "... ", result ? HTUTEST_COLOR_GREEN "OK" HTUTEST_COLOR_END : HTUTEST_COLOR_RED "FAILED" HTUTEST_COLOR_END);

                        global_result &= result;
                    }
                    tear_down();
                }
                CTestCore<void>::get_instance().end_function();
            }
        }

        return global_result;
    }

    ////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////
    template <class T>
    void CUnitTest<T>::list_functions() const
    {
        for (const SFunction& function : m_function_list)
        {
            HTUTEST_PRINT(std::string(" - ") + function.m_name);
        }
    }
}
