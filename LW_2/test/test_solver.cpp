#include <gtest/gtest.h>
#include "../include/solver.h"

TEST(test_01, basic_test_set) 
{
    Seven num1("12345");
    Seven num2("543");
    
    num1 += num2;

    std::string result = num1.toString();
    ASSERT_TRUE(result == "13221");
} 

TEST(test_02, basic_test_set) 
{ 
    Seven num1("12345");
    Seven num2("12345");

    num1 -= num2;

    std::string result = num1.toString();
    ASSERT_TRUE(result == "0");
} 

TEST(test_03, basic_test_set) 
{ 
    Seven num1("12345");
    Seven num2("543");

    bool result = (num1 == num2);
    ASSERT_TRUE(result == false);
} 

TEST(test_04, basic_test_set) 
{ 
    Seven num1("543");
    Seven num2("12345");

    bool result = (num1 < num2);
    ASSERT_TRUE(result == true);
} 

TEST(test_05, basic_test_set) 
{ 
    Seven num1("12345");
    Seven num2("543");

    bool result = (num1 > num2);
    ASSERT_TRUE(result == true);
} 

TEST(test_06, basic_test_set) 
{ 
    Seven num1("12345");
    Seven numZero("0");

    num1 += numZero;

    std::string result = num1.toString();
    ASSERT_TRUE(result == "12345");
} 

TEST(test_07, invalid_input_subtraction_test) 
{ 
    try {
        Seven numInvalid("9999999");
        Seven numValid("123456");

        numValid -= numInvalid;
        FAIL() << "Expected invalid_argument exception";
    } catch (const std::invalid_argument& e) {
        ASSERT_STREQ(e.what(), "Неверный символ для семеричного числа");
    } catch (...) {
        FAIL() << "Expected invalid_argument exception of specific type";
    }
}

TEST(test_08, invalid_input_addition_test) 
{ 
    try {
        Seven num1("123456");
        Seven numInvalid("987654");

        num1 += numInvalid;
        FAIL() << "Expected invalid_argument exception";
    } catch (const std::invalid_argument& e) {
        ASSERT_STREQ(e.what(), "Неверный символ для семеричного числа");
    } catch (...) {
        FAIL() << "Expected invalid_argument exception of specific type";
    }
}

int main(int argc, char **argv) { 
    testing::InitGoogleTest(&argc, argv); 
    return RUN_ALL_TESTS(); 
}
