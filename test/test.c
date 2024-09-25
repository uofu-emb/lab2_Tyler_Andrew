#include <stdio.h>
#include <pico/stdlib.h>
#include <stdint.h>
#include <unity.h>
#include "unity_config.h"
#include "function.c"

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
//this checks to see if ten values are upper case including lower case and a sybmol
void test_upper_case(void){
    
}
//tests to see if everything is working together
void test_work_together(void){
    
    
}

int main (void){
stdio_init_all();
//hard_assert(cyw43_arch_init() == PICO_OK);
//begins the tests
UNITY_BEGIN();

    while(1){
        
        sleep_ms(5000); // Give time for TTY to attach.
        // starts tests
        printf("Start tests\n");
        //begins the tests
        RUN_TEST(test_variable_assignment);
        //does the mutip test
        RUN_TEST(test_multiplication);
        sleep_ms(5000);
        //gives a delay
    }
UNITY_END();
    return 0;
}
