#include"Convector.h"

std::string Convector::Get_val()
{
    return m_str;
}

void Convector::toBinary(int num) {
    if (num == 0) {
        m_str = "0";
    }
    std::string binary;
    while (num > 0) {
        binary = std::to_string(num % 2) + binary;
        num /= 2;
    }
    m_str = binary;
}

Convector *Convector_new() {
    return new Convector();
}

void Convector_del(Convector *convector) {
    delete convector;
}

char* Get_val_str(Convector *convector) {
    std::string str = convector->Get_val();

    char *ret = new char[str.length() + 1];
    strcpy(ret, str.c_str());

    return ret;
}

void toBinary_int(Convector *convector, int num){
    return convector->toBinary(num);
}