#include <Arduino.h>

#include <gtest/gtest.h>

// if next line isn't commented the 2nd test will fail
// #define ShallFail

#ifdef ShallFail
    #define VALUE 1
#else
    #define VALUE 2
#endif


// always succeeds
TEST(test_suite, alwaysOK) {
    ASSERT_EQ(3, 3);
}

// only succeeds if ShallFail is not defined
TEST(test_suite, failsIfShallFailIsDefined) {
    ASSERT_EQ(2, VALUE);
}


#if defined(ESP32) || defined(ESP8266)
#ifdef ESP32
#define SPEED 921600
#else
#define SPEED 460800
#endif

void setup() {
    Serial.begin(SPEED);
    delay(1000);
    
    testing::InitGoogleTest();
    if (RUN_ALL_TESTS()) ;

}

void loop() {
    // nothing to be done here.
    delay(100);
}

#else
int main(int argc, char ** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
#endif