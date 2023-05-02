#include "patterns.h"

namespace Patterns
{
    uintptr_t Scan(const char* sig)
    {
        const HMODULE module_handle = GetModuleHandleA("xgog release_x64.exe");

        if (!module_handle)
            LOG("What the foil") \
            return (uintptr_t)nullptr;

        PIMAGE_DOS_HEADER dos_header = reinterpret_cast<PIMAGE_DOS_HEADER>(module_handle);
        PIMAGE_NT_HEADERS nt_headers =
            reinterpret_cast<PIMAGE_NT_HEADERS>(reinterpret_cast<std::uint8_t*>(module_handle) + dos_header->e_lfanew);

        DWORD size_of_image = nt_headers->OptionalHeader.SizeOfImage;
        std::vector<int> pattern_bytes = PatternToByte(sig);
        uint8_t* scan_bytes = reinterpret_cast<std::uint8_t*>(module_handle);

        auto s = pattern_bytes.size();
        auto d = pattern_bytes.data();

        for (auto i = 0ul; i < size_of_image - s; ++i) {
            bool found = true;

            for (auto j = 0ul; j < s; ++j) {
                if (scan_bytes[i + j] != d[j] && d[j] != -1) {
                    found = false;
                    break;
                }
            }
            if (found)
                return (uintptr_t)&scan_bytes[i];
        }

        return (uintptr_t)nullptr;
    }

    inline std::vector<int> PatternToByte(const char* sig)
    {
        auto bytes = std::vector<int>{};
        auto start = const_cast<char*>(sig);
        auto end = const_cast<char*>(sig) + std::strlen(sig);

        for (auto current = start; current < end; ++current) {
            if (*current == '?') {
                ++current;

                if (*current == '?')
                    ++current;

                bytes.push_back(-1);
            }
            else {
                bytes.push_back(std::strtoul(current, &current, 16));
            }
        }
        return bytes;
    }
};