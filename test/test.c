#include <stdio.h>
#include <pico/stdlib.h>
#include <stdint.h>
#include <unity.h>
#include "unity_config.h"
#include "../src/function.c"

void setUp(void) {}

void tearDown(void) {}


//this checks to see if ten values are upper case including lower case and a sybmol
void test_upper_case(void){
    TEST_ASSERT_TRUE_MESSAGE(upper_case('a') == 'A', "This was upper case");
    TEST_ASSERT_TRUE_MESSAGE(upper_case('B') == 'b', "This was upper case");

}

//Here are testing if the input is within a valid range
void test_HEX_valid_input(void){
   TEST_ASSERT_HEX_WITHIN(0x5A,0x00,upper_case('y'));
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
        RUN_TEST(test_HEX_valid_input);
        RUN_TEST(test_upper_case);
        sleep_ms(5000);
        //gives a delay
    }
UNITY_END();
    return 0;
}
