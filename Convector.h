#include <iostream>
#include <string>
#include <string.h>

class Convector
{
private:
    std::string m_str;
public:
    Convector() = default;
    std::string Get_val();
    void toBinary(int num);
    ~Convector()=default;
    
};

#ifdef __cplusplus
extern "C" {
#endif

    Convector *Convector_new();
    void Convector_del(Convector *convector);
    char* Get_val_str(Convector *convector);
    void toBinary_int(Convector *convector, int num);

#ifdef __cplusplus
}
#endif

