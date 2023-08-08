#include "../src/utils/md5.h"
#include <string>
#include <iostream>
#include <unordered_set>

int main() {
    int num = 1;
    std::cout << md5(std::to_string(num)) << std::endl;
}