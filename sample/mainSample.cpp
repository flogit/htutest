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
class CMyTest1 : public htutest::CUnitTest<CMyTest1>
{
    public : // methods

        CMyTest1();
        bool test_one();
        bool test_two();
        bool test_three();
};

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
CMyTest1::CMyTest1() :
    htutest::CUnitTest<CMyTest1>("CTest1")
{
    add("test_one"  , &CMyTest1::test_one);
    add("test_two"  , &CMyTest1::test_two);
    add("test_three", &CMyTest1::test_three);

}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool CMyTest1::test_one()
{
    HTUTEST_ASSERT_MESSAGE(1 == 1, "Of course");
    HTUTEST_ASSERT_MESSAGE(2 == 2, "For sure");

    HTUTEST_RETURN;
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool CMyTest1::test_two()
{
    HTUTEST_ASSERT(3 == 3);
    HTUTEST_ASSERT(4 == 4);

    HTUTEST_RETURN;
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool CMyTest1::test_three()
{
    HTUTEST_ASSERT_EQUAL_MESSAGE(5, 0, "Wow ! Strange result");
    HTUTEST_ASSERT_EQUAL_MESSAGE(6, 6, "Wow ! Strange result");

    HTUTEST_RETURN;
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
class CMyTest2 : public htutest::CUnitTest<CMyTest2>
{
    public : // methods

        CMyTest2() : htutest::CUnitTest<CMyTest2>("CTest2") {}

        void set_up() { m_pData = new int(7); }

        bool main()
        {
            HTUTEST_ASSERT_EQUAL(*m_pData * 1, 7);
            HTUTEST_ASSERT_EQUAL(*m_pData * 2, 14);
            HTUTEST_ASSERT_EQUAL(*m_pData * 3, 21);
            HTUTEST_ASSERT_EQUAL(*m_pData * 4, 28);
            HTUTEST_ASSERT_EQUAL(*m_pData * 5, 35);
            HTUTEST_RETURN;
        }

        void tear_down() { delete m_pData; }

    private:
        int* m_pData;
};

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
int main(int inArgc, char** inArgv)
{
    return htutest::CUnitTestSuite({
                                    new CMyTest1,
                                    new CMyTest2,
                                   }).run(inArgc, inArgv);
}
