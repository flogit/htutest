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

#include "../CUnitTest.h"

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
class CMyMinimalTest : public htutest::CUnitTest<CMyMinimalTest>
{
    public : // methods

        bool main()
        {
            HTUTEST_ASSERT(1 == 1);
            HTUTEST_ASSERT(1 == 0);

            HTUTEST_ASSERT_MESSAGE(2 == 2, "Of course");
            HTUTEST_ASSERT_MESSAGE(2 == 1, "Strange result");

            HTUTEST_ASSERT_EQUAL(3, 3);
            HTUTEST_ASSERT_EQUAL(3, 2);

            HTUTEST_ASSERT_EQUAL_MESSAGE(3, 3, "Of course");
            HTUTEST_ASSERT_EQUAL_MESSAGE(3, 2, "Strange result");

            HTUTEST_RETURN;
        }
};

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
int main(int, char**)
{
    return htutest::CUnitTestSuite(new CMyMinimalTest).run();
}
