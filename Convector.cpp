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

std::string Convector::toHex(int num) {
    std::map<int, std::string> hex_map{{10, "A"}, {11, "B"}, {12, "C"}, {13, "D"}, {14, "E"}, {15, "F"}};
    if (num == 0) {
        return "0";
    }
    std::string hex;
    int num_hex = 0;
    while (num > 0) {
        num_hex = num % 16;
        if (num_hex >= 0 && num_hex < 10) {
        hex = std::to_string(num % 16) + hex;
        } else if(num >= 10 && num < 16) {
            hex = hex_map[num] + hex;
        }
        else {
            hex = "bla";
        }
        num /= 16;
    }
    return hex;
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

char* toHex_int(Convector *convector, int num){
    std::string str = convector->toHex(num);

    char *ret = new char[str.length() + 1];
    strcpy(ret, str.c_str());

    return ret;
}