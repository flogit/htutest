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

#include <iostream>

#include "CTestCore.h"

namespace htutest
{
    ////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////
    template <typename T>
    CTestCore<T>::CTestCore() :
        m_function_state(false),
        m_indentation(0)
    {
    }

    ////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////
    template <typename T>
    CTestCore<T>& CTestCore<T>::get_instance()
    {
        if (!m_p_instance)
        {
            m_p_instance = new CTestCore();
        }
        return *m_p_instance;
    }

    ////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////
    template<typename T>
    void CTestCore<T>::rec_print() const
    {
        // terminal recursion for printing method
        std::cout << std::endl;
    }

    ////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////
    template<typename T>
    template<typename Arg0, typename... Args>
    void CTestCore<T>::rec_print(const Arg0& in_arg0, const Args&... in_other) const
    {
        std::cout << in_arg0;
        rec_print(in_other...);
    }

    ////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////
    template<typename T>
    template<typename... Args>
    void CTestCore<T>::print(const Args&... in_other) const
    {
        for (unsigned int i = 0; i < m_indentation; ++i)
        {
            std::cout << "| ";
        }
        rec_print(in_other...);
    }

    ////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////
    template <typename T>
    void CTestCore<T>::fail_if(bool in_condition,
                               const std::string& in_message,
                               const std::string& in_expression,
                               const std::string& in_file,
                               unsigned int in_line)
    {
        if (in_condition)
        {
            m_function_state = false;

            print("> ", in_message);
            print("> ", in_expression);
            print("> ", "In file ", in_file, " at line ", in_line);
        }
    }

    ////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////
    template <typename T>
    void CTestCore<T>::start_function()
    {
        m_function_state = true;
        ++m_indentation;
    }

    ////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////
    template <typename T>
    void CTestCore<T>::end_function()
    {
        --m_indentation;
    }

    ////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////
    template <typename T>
    bool CTestCore<T>::get_function_state() const
    {
        return m_function_state;
    }
}
