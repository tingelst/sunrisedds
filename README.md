# SunriseDDS
CycloneDDS on KUKA Sunrise.OS for integration with ROS2


### Build CycloneDDS on Windows 7 32 Bit

1. Download and start a Windows 7 32 bit VM (e.g. VirtualBox) from: https://developer.microsoft.com/en-us/microsoft-edge/tools/vms/. The following steps should be performed in the VM.

2. Download and install Visual Studio 2019 Community Edition from: https://visualstudio.microsoft.com. Select 'Desktop development with C++'.

3. Download and install the latest CMake release from: https://cmake.org/download. Select 'Windows i386 Installer'.

4. Download and unzip the latest winflexbison release from: https://github.com/lexxmark/winflexbison/releases. Tested with version 2.5.24 (bison 3.7.4,, flex 2.6.4).

5. Download and unzip Eclipse Cyclone DDS from: https://github.com/eclipse-cyclonedds/cyclonedds/archive/refs/heads/master.zip. 

6. Open CMake and configure Cyclone DDS: Select the advanced option, set `BISON_EXECUTABLE` to the `win_bison.exe` in the unzipped winflexbison folder, and disable the use of OpenSSL by unselecting `ENABLE_SSL `. Press `Configure`, `Generate`. Open the generated Visual Studio project by pressing `Open Project`.

7. In Visual Studio 2019, open the file: `src/ddsrt/src/time/windows/time.c` and add the following preprocessor definitions
    ```c++
    #if defined(_WIN32_WINNT) && _WIN32_WINNT != 0x0601
    #undef _WIN32_WINNT
    #define _WIN32_WINNT 0x0601
    #endif
    ```
    above the block:
    ```c++
    /* GetSystemTimePreciseAsFileTime was introduced with Windows 8, so
    starting from _WIN32_WINNET = 0x0602.  When building for an older
    version we can still check dynamically. */
    #if defined(_WIN32_WINNT) && _WIN32_WINNT >= 0x0602
    #define UseGetSystemTimePreciseAsFileTime
    #else
    typedef void (WINAPI *GetSystemTimeAsFileTimeFunc_t)(LPFILETIME);
    static GetSystemTimeAsFileTimeFunc_t GetSystemTimeAsFileTimeFunc = GetSystemTimeAsFileTime;
    static HANDLE Kernel32ModuleHandle;
    #endif
    ```
    This is to enable a Windows 7 build as Visual Studio 2019 by default targets Windows 10.

8. Build the solution (ALL_BUILD ). Ensure that the configuration is set to Release and that the platform is set to Win32.

9. Install the solution (INSTALL). The default install directory is `C:\Program Files\CycloneDDS`.

















