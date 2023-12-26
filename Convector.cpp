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

std::string Convector::toOctal(int num) {
    if (num == 0) {
        return "0";
    }
    std::string octal;
    while (num > 0) {
        octal = std::to_string(num % 8) + octal;
        num /= 8;
    }
    return octal;
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

char* toOctal_int(Convector *convector, int num){
    std::string str = convector->toOctal(num);

    char *ret = new char[str.length() + 1];
    strcpy(ret, str.c_str());

    return ret;
}