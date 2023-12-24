/*  ----------------------------------------------------------------------------
    File: platform.c

    Description:
    This source file contains the code entry point for the Trilobite Stdlib project.
    It demonstrates the usage of various utilities and functions provided by the
    Trilobite Stdlib to enhance software development.

    Author: Michael Gene Brockus (Dreamer)
    Email: michaelbrockus@gmail.com
    Website: [Trilobite Coder Blog](https://trilobite.home.blog)

    Project: Trilobite Stdlib

    License: Apache License 2.0
    SPDX Identifier: Apache-2.0

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0.

    Unless required by applicable law or agreed to in writing, software distributed under the License
    is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express
    or implied. See the License for the specific language governing permissions and limitations
    under the License.

    Please review the full text of the Apache License 2.0 for the complete terms and conditions.

    (Apache License 2.0: http://www.apache.org/licenses/LICENSE-2.0)
    ----------------------------------------------------------------------------
*/
#include "trilobite/xutil/platform.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#if defined(_WIN32)
    #include <windows.h>
#elif defined(__APPLE__) && defined(__MACH__)
    #include <sys/sysctl.h>
    #include <machine/endian.h>
#elif defined(__linux__)
    #include <stdio.h>
    #include <string.h>
    #include <endian.h>
#elif defined(__FreeBSD__)
    #include <sys/sysctl.h>
    #include <machine/endian.h>
#endif

// Function to get information about the operating system
cos_info tscl_platform_get_os_info(void) {
    cos_info info;

    #if defined(_WIN32)
        info.name = "Windows";

        // Additional code to get Windows version
        OSVERSIONINFOEX osvi;
        ZeroMemory(&osvi, sizeof(OSVERSIONINFOEX));
        osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);

        if (GetVersionEx((OSVERSIONINFO*)&osvi)) {
            if (osvi.dwMajorVersion == 10) {
                sprintf(info.version, "10.%lu", osvi.dwBuildNumber);
            } else if (osvi.dwMajorVersion == 6 && osvi.dwMinorVersion == 3) {
                sprintf(info.version, "8.1");
            } else if (osvi.dwMajorVersion == 6 && osvi.dwMinorVersion == 2) {
                sprintf(info.version, "8");
            } else if (osvi.dwMajorVersion == 6 && osvi.dwMinorVersion == 1) {
                sprintf(info.version, "7");
            } else if (osvi.dwMajorVersion == 6 && osvi.dwMinorVersion == 0) {
                sprintf(info.version, "Vista");
            } else if (osvi.dwMajorVersion == 5 && osvi.dwMinorVersion == 2) {
                if (GetSystemMetrics(SM_SERVERR2)) {
                    sprintf(info.version, "Server 2003 R2");
                } else {
                    sprintf(info.version, "Server 2003");
                }
            } else if (osvi.dwMajorVersion == 5 && osvi.dwMinorVersion == 1) {
                sprintf(info.version, "XP");
            } else if (osvi.dwMajorVersion == 5 && osvi.dwMinorVersion == 0) {
                sprintf(info.version, "2000");
            } else {
                sprintf(info.version, "Unknown");
            }
        }

    #elif defined(__APPLE__) && defined(__MACH__)
        info.name = "macOS";

        // Additional code to get macOS version
        int mib[2];
        size_t len;
        char version[256];

        mib[0] = CTL_KERN;
        mib[1] = KERN_OSRELEASE;
        len = sizeof(version);

        if (sysctl(mib, 2, version, &len, NULL, 0) == 0) {
            version[len] = '\0';
            sprintf(info.version, "%s", version);
        } else {
            sprintf(info.version, "Unknown");
        }

    #elif defined(__linux__)
        info.name = "Linux";

        // Additional code to get Linux version
        FILE* file = fopen("/etc/os-release", "r");
        if (file) {
            char line[256];
            while (fgets(line, sizeof(line), file)) {
                if (strncmp(line, "VERSION_ID", 10) == 0) {
                    char* version_str = strchr(line, '=');
                    if (version_str) {
                        sscanf(version_str + 1, "%[^\n]", info.version);
                        break;
                    }
                }
            }
            fclose(file);
        } else {
            sprintf(info.version, "Unknown");
        }

    #elif defined(__FreeBSD__)
        info.name = "FreeBSD";

        // Additional code to get FreeBSD version
        int mib[2];
        size_t len;
        char version[256];

        mib[0] = CTL_KERN;
        mib[1] = KERN_VERSION;
        len = sizeof(version);

        if (sysctl(mib, 2, version, &len, NULL, 0) == 0) {
            version[len] = '\0';
            sprintf(info.version, "%s", version);
        } else {
            sprintf(info.version, "Unknown");
        }

    #elif defined(__arm__)
        info.name = "ARM";

        // Additional code to get ARM version
        // (Note: Specifics may vary based on the ARM platform)
        sprintf(info.version, "N/A");

    #else
        info.name = "Unknown";
        sprintf(info.version, "N/A");
    #endif

    return info;
}

// Function to get information about the CPU architecture
carch_info tscl_platform_get_architecture_info(void) {
    carch_info info;

    #if defined(__i386__)
        info.architecture = "x86";
    #elif defined(__x86_64__)
        info.architecture = "x86_64";
    #elif defined(__arm__)
        info.architecture = "ARM";
    #elif defined(__aarch64__)
        info.architecture = "ARM64";
    #else
        info.architecture = "Unknown";
    #endif

    // Additional information about the CPU can be obtained here
    info.name = "Generic CPU";  // Replace with actual CPU name if available

    return info;
}

// Function to check if the system is little-endian
int tscl_platform_is_little_endian(void) {
    uint16_t num = 1;
    return *((uint8_t*)&num) == 1;
}

// Function to check if the system is big-endian
int tscl_platform_is_big_endian(void) {
    return !tscl_platform_is_little_endian();
}

// Function to swap the endianness of a 16-bit integer
uint16_t tscl_platform_swap_endian_16(uint16_t value) {
    return (value >> 8) | (value << 8);
}

// Function to swap the endianness of a 32-bit integer
uint32_t tscl_platform_swap_endian_32(uint32_t value) {
    return ((value >> 24) & 0xFF) | ((value >> 8) & 0xFF00) | ((value << 8) & 0xFF0000) | ((value << 24) & 0xFF000000);
}

// Function to swap the endianness of a 64-bit integer
uint64_t tscl_platform_swap_endian_64(uint64_t value) {
    return ((value >> 56) & 0xFF) | ((value >> 48) & 0xFF00) | ((value >> 40) & 0xFF0000) | ((value >> 32) & 0xFF000000) |
           ((value >> 24) & 0xFF00000000) | ((value >> 16) & 0xFF0000000000) | ((value >> 8) & 0xFF000000000000) | ((value << 56) & 0xFF00000000000000);
}
