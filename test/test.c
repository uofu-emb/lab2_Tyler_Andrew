#include <stdio.h>
#include <pico/stdlib.h>
#include <stdint.h>
#include <unity.h>
#include "unity_config.h"

void setUp(void) {}

void tearDown(void) {}

//checks that a vairble is 
void test_variable_assignment()
{
    int x = 1;
    TEST_ASSERT_TRUE_MESSAGE(x == 1,"Variable assignment failed.");
}
//checks mutiply
void test_multiplication(void)
{
    int x = 30;
    int y = 6;
    int z = x / y;
    TEST_ASSERT_TRUE_MESSAGE(z == 5, "Multiplication of two integers returned incorrect value.");
}

int main (void)
{
	// init all 
    stdio_init_all();
    sleep_ms(5000); // Give time for TTY to attach.
	// starts tests
    printf("Start tests\n");
	//begins the tests
    UNITY_BEGIN();
	//runs the tests 
    RUN_TEST(test_variable_assignment);
	//does the mutip test
    RUN_TEST(test_multiplication);
    sleep_ms(5000);
	//gives a delay
    return UNITY_END();
	//ends all of the subjects
}
