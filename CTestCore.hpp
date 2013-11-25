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

namespace utest
{
    ////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////
    template <typename T>
    CTestCore<T>::CTestCore() :
        m_functionState(false),
        m_indentation(0)
    {
    }

    ////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////
    template <typename T>
    CTestCore<T>& CTestCore<T>::getInstance()
    {
        if (!m_pInstance)
        {
            m_pInstance = new CTestCore();
        }
        return *m_pInstance;
    }

    ////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////
    template<typename T>
    void CTestCore<T>::recPrint() const
    {
        // terminal recursion for printing method
        std::cout << std::endl;
    }

    ////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////
    template<typename T>
    template<typename Arg0, typename... Args>
    void CTestCore<T>::recPrint(const Arg0& in_arg0, const Args&... in_other) const
    {
        std::cout << in_arg0;
        recPrint(in_other...);
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
        recPrint(in_other...);
    }

    ////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////
    template <typename T>
    void CTestCore<T>::failIf(bool inCondition,
                              const std::string& inMessage,
                              const std::string& inExpression,
                              const std::string& inFile,
                              unsigned int inLine)
    {
        if (inCondition)
        {
            m_functionState = false;

            print("> ", inMessage);
            print("> ", inExpression);
            print("> ", "In file ", inFile, " at line ", inLine);
        }
    }

    ////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////
    template <typename T>
    void CTestCore<T>::startFunction()
    {
        m_functionState = true;
        ++m_indentation;
    }

    ////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////
    template <typename T>
    void CTestCore<T>::endFunction()
    {
        --m_indentation;
    }

    ////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////
    template <typename T>
    bool CTestCore<T>::getFunctionState() const
    {
        return m_functionState;
    }
}
