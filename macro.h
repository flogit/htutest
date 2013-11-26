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

#define HTUTEST_ASSERT(condition)                  (htutest::CTestCore<void>::get_instance().fail_if(!(condition), "assertion failed", "Expression: " #condition, __FILE__, __LINE__))
#define HTUTEST_ASSERT_MESSAGE(condition, message) (htutest::CTestCore<void>::get_instance().fail_if(!(condition), (message),          "Expression: " #condition, __FILE__, __LINE__))

#define HTUTEST_ASSERT_EQUAL(value1, value2)                  (htutest::CTestCore<void>::get_instance().fail_if(!((value1) == (value2)), "assertion failed", "Expression: " #value1 " == " #value2, __FILE__, __LINE__))
#define HTUTEST_ASSERT_EQUAL_MESSAGE(value1, value2, message) (htutest::CTestCore<void>::get_instance().fail_if(!((value1) == (value2)), (message),          "Expression: " #value1 " == " #value2, __FILE__, __LINE__))

#define HTUTEST_ASSERT_MSG       UTEST_ASSERT_MESSAGE
#define HTUTEST_ASSERT_EQUAL_MSG UTEST_ASSERT_EQUAL_MESSAGE

#define HTUTEST_RETURN return (int)(htutest::CTestCore<void>::get_instance().get_function_state());

#define HTUTEST_PRINT(...) htutest::CTestCore<void>::get_instance().print(__VA_ARGS__)

#define HTUTEST_COLOR_RED    "\33[0;31m"
#define HTUTEST_COLOR_GREEN  "\33[0;32m"
#define HTUTEST_COLOR_ORANGE "\33[0;33m"
#define HTUTEST_COLOR_BLUE   "\33[0;36m"
#define HTUTEST_COLOR_END    "\33[m"
