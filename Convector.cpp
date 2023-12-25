#include"Convector.h"

std::string Convector::toBinary(int num) {
    if (num == 0) {
        return "0";
    }
    std::string binary;
    while (num > 0) {
        binary = std::to_string(num % 2) + binary;
        num /= 2;
    }
    return binary;
}

Convector *Convector_new() {
    return new Convector();
}

void Convector_del(Convector *convector) {
    delete convector;
}


char* toBinary_int(Convector *convector, int num){
    std::string str = convector->toBinary(num);

    char *ret = new char[str.length() + 1];
    strcpy(ret, str.c_str());

    return ret;
}