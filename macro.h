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

#include "CTestCore.h" // macro header can not be used without include of CTestCore

#define UTEST_ASSERT(condition)                  (utest::CTestCore<void>::getInstance().failIf(!(condition), "assertion failed", "Expression: " #condition, __FILE__, __LINE__))
#define UTEST_ASSERT_MESSAGE(condition, message) (utest::CTestCore<void>::getInstance().failIf(!(condition), (message),          "Expression: " #condition, __FILE__, __LINE__))

#define UTEST_ASSERT_EQUAL(value1, value2)                  (utest::CTestCore<void>::getInstance().failIf(!((value1) == (value2)), "assertion failed", "Expression: " #value1 " == " #value2, __FILE__, __LINE__))
#define UTEST_ASSERT_EQUAL_MESSAGE(value1, value2, message) (utest::CTestCore<void>::getInstance().failIf(!((value1) == (value2)), (message),          "Expression: " #value1 " == " #value2, __FILE__, __LINE__))

#define UTEST_ASSERT_MSG       UTEST_ASSERT_MESSAGE
#define UTEST_ASSERT_EQUAL_MSG UTEST_ASSERT_EQUAL_MESSAGE

#define UTEST_RETURN return (int)(utest::CTestCore<void>::getInstance().getFunctionState());

#define PRINT(...) utest::CTestCore<void>::getInstance().print(__VA_ARGS__)

#define COLOR_RED    "\33[0;31m"
#define COLOR_GREEN  "\33[0;32m"
#define COLOR_ORANGE "\33[0;33m"
#define COLOR_BLUE   "\33[0;36m"
#define COLOR_END    "\33[m"
