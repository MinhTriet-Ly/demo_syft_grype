#include <iostream>
#include <zlib.h>

int main() {
    std::cout << "Using zlib " << zlibVersion() << std::endl;
    return 0;
}
