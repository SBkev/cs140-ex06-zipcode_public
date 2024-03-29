// Copyright 2018, Allan Knight.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//     * Neither the name of Allan Knight nor the names of other
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

// A unit tester for EX01-HelloWorld in CS140 at Santa Barbara City College.
//
// Author: ahknight@pipeline.sbcc.edu (Allan Knight)


// Includes for google test and the unit under test.

#include <climits>
#include <sstream>

#include "zipcode.h"
#include "gtest/gtest.h"
namespace {

// Tests edu::sbcc:cs140::Zipcode.

    using edu::sbcc::cs140::Zipcode;

    using std::istringstream;
    using std::ostringstream;
    using std::string;

    using namespace ::testing_internal;

    typedef uint64_t uint;

    class ZipcodeTest : public ::testing::Test {
    protected:
        static const uint MAX_TESTED_SCORE = 20;
        static const uint MAX_OVERALL_SCORE = 25;
        static uint _testScore;

    protected:
        static void TearDownTestCase() {
            if (_testScore == MAX_TESTED_SCORE) {
                std::cout << std::endl << "Your unit test score is "
                          << _testScore << " out of "
                          << MAX_TESTED_SCORE << std::endl;
            } else {
                std::cout << "Your unit test score is "
                          << _testScore << " out of "
                          << MAX_TESTED_SCORE << " ("<< (int)(_testScore - MAX_TESTED_SCORE)
                          << ")" << std::endl;
            }

            std::cout << "The assignment is worth a total of " << MAX_OVERALL_SCORE
                      << " where the remaining points" << std::endl;
            std::cout << "comes from grading related to documentation, algorithms, and other"
                      << std::endl;
            std::cout << "criteria." << std::endl << std::endl;
        }
    };

    uint ZipcodeTest::_testScore = 0;

    TEST_F(ZipcodeTest, Constructors) {
        // This test is named "Identity", it checks that the basic identity
        // complex number, i, has the correct values for real and imaginary
        // parts.
        Zipcode zc(93111);

        ASSERT_EQ(93111, zc.getZipcode());
        ASSERT_EQ("110100001100001100011000111", zc.getBarcode());

        Zipcode zcbc("110100001100001100011000111");

        ASSERT_EQ(93111, zc.getZipcode());
        ASSERT_EQ("110100001100001100011000111", zc.getBarcode());

        _testScore += 10;
    }

    TEST_F(ZipcodeTest, EndsWithZero) {
        Zipcode endsWithZero(93110);

        ASSERT_EQ(93110, endsWithZero.getZipcode());
        ASSERT_EQ("110100001100001100011110001", endsWithZero.getBarcode());

        _testScore += 5;
    }

    TEST_F(ZipcodeTest, AllZeroes) {
        Zipcode allZeroesBc("111000110001100011000110001");

        EXPECT_EQ(0, allZeroesBc.getZipcode());
        EXPECT_EQ("111000110001100011000110001", allZeroesBc.getBarcode());

        if (!HasFailure()) {
            _testScore += 1;
        }

        // Extra credit if you can read the zipcode 00000 and produce the correct
        // barcode.
        Zipcode allZeroes(0);

        ASSERT_EQ(0, allZeroes.getZipcode());
        ASSERT_EQ("111000110001100011000110001", allZeroes.getBarcode());

        _testScore += 1;
    }

    TEST_F(ZipcodeTest, EmptyBarcodeFormat) {
        Zipcode badEmptyString("");

        ASSERT_EQ(0, badEmptyString.getZipcode());
        ASSERT_TRUE("111111111111111111111111111" == badEmptyString.getBarcode() ||
                    "111000110001100011000110001" == badEmptyString.getBarcode());

        _testScore += 1;
    }

    TEST_F(ZipcodeTest, UnderflowFormat) {
        Zipcode badEmptyString("1100011000110001100011000");

        ASSERT_EQ(0, badEmptyString.getZipcode());
        ASSERT_TRUE("111111111111111111111111111" == badEmptyString.getBarcode() ||
                    "111000110001100011000110001" == badEmptyString.getBarcode());

        _testScore += 1;
    }

    TEST_F(ZipcodeTest, OnesNotAtStartAndEndFormat) {
        Zipcode badEmptyString("010100001100001100011000110");

        ASSERT_EQ(0, badEmptyString.getZipcode());
        ASSERT_TRUE("111111111111111111111111111" == badEmptyString.getBarcode() ||
                    "111000110001100011000110001" == badEmptyString.getBarcode());

        _testScore += 1;
    }
}
