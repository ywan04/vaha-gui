#ifndef VAHA_HPP
#define VAHA_HPP

#include <cstdint>
#include <modbus.h>

class Vaha
{
public:
    Vaha();
    ~Vaha();
    int32_t get_weight();
    void calibrate();
private:
    modbus_t *m_ctx;
    uint16_t m_inp_reg[2];
};

#endif // VAHA_HPP
