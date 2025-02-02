#include <iostream>
#include "Date.h"

int main() {
    Date date{2, 2, 2025};
    try {
        date.printDayOfWeek();
    }
    catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}