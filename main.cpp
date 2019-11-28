#include <iostream>
#include "BigNumber.h"
int main() {
    BigNumber bn(5121,0);
    bn=-bn;
    std::cout << bn<< std::endl;
    return 0;
}