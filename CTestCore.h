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

namespace utest
{
    template <typename T>
    class CTestCore
    {
        public: // methods

            inline static CTestCore<T>& getInstance();

            inline void failIf(bool inCondition,
                               const std::string& inMessage,
                               const std::string& inExpression,
                               const std::string& inFile,
                               unsigned int inLine);

            template<typename... Args>
            inline void print(const Args&... in_other) const;

            inline void startFunction();
            inline bool getFunctionState() const;
            inline void endFunction();

        private: // methods

            template<typename Arg0, typename... Args>
            inline void recPrint(const Arg0& in_arg0, const Args&... in_other) const;

            inline void recPrint() const;

            inline CTestCore();

        private: // members

            bool m_functionState;

            unsigned int m_indentation;

            static CTestCore* m_pInstance;
    };

    template <typename T>
     CTestCore<T>* CTestCore<T>::m_pInstance = 0;
}

#include "CTestCore.hpp"
