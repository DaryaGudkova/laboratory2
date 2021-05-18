#include <gtest/gtest.h>
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
}