#include "vaha.hpp"
#include <iostream>
#include <unistd.h>

Vaha::Vaha()
{
    m_ctx = modbus_new_rtu("/dev/ttyUSB0", 115200, 'N', 8, 1);
    if (m_ctx == nullptr) {
        std::cerr << "error: modbus_new_rtu failed\n";
    }
    if (modbus_connect(m_ctx) != 0) {
        std::cerr << "error: modbus_connect failed\n";
    }
    if (modbus_set_slave(m_ctx, 0x20) != 0) {
        std::cerr << "error: modbus_set_slave failed\n";
    }
}

Vaha::~Vaha()
{
    modbus_close(m_ctx);
    modbus_free(m_ctx);
}

int32_t Vaha::get_weight()
{
    modbus_write_register(m_ctx, 1999, 1);
    usleep(500000);
    modbus_read_input_registers(m_ctx, 999, 2, m_inp_reg);

    return (uint32_t)m_inp_reg[0] << 16 | m_inp_reg[1];
}

void Vaha::calibrate()
{
    modbus_write_register(m_ctx, 2000, 1);
}
