#include <iostream>

#include "Date.h"
#include "NumberUtil.h"

int main() {
    //NumberUtil::Operation();
    Date d1{12,2,2019};
    Date d2{11,2,2019};
    std::cout << d1-d2 << std::endl;
    return 0;
}
