#include <iostream>
#include "BigNumber.h"
int main() {
    BigNumber bn(5121);
    BigNumber bn1(255);
    std::cout << bn+bn1<< std::endl;
    return 0;
}