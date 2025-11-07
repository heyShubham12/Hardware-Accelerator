#include <cstdint>
#include <string>

extern "C" void read_section_void(long long address, void* buffer, long long size) {
    // Stub implementation - does nothing
}

extern "C" char read_symbol(const char* symbol_name, uint64_t& address, uint8_t& found) {
    // Stub implementation - symbol not found
    found = 0;
    address = 0;
    return 0;
}
