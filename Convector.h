#include <iostream>
#include <string>
#include <string.h>
#include <map>

class Convector
{
private:
    std::string m_str;
public:
    Convector() = default;
    std::string toBinary(int num);
    std::string toOctal(int num);
    std::string toHex(int num);
    ~Convector()=default;
    
};

#ifdef __cplusplus
extern "C" {
#endif

    Convector *Convector_new();
    void Convector_del(Convector *convector);
    char* toBinary_int(Convector *convector, int num);
    char* toOctal_int(Convector *convector, int num);
    char* toHex_int(Convector *convector, int num);

#ifdef __cplusplus
}
#endif

