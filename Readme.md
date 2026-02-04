# SunLight

SunLight is a C++ class library that calculates various sunrise and sunset phases based on date, latitude, and longitude. Its implementation is based on the NOAA Solar Calculator.

## Features

Calculate the exact time for:

*   **Sunrise**: When the upper edge of the Sun appears over the eastern horizon.
*   **Sunset**: When the upper edge of the Sun disappears below the horizon.
*   **Civil Dawn/Dusk**: Sun is 6 degrees below the horizon. Objects are distinguishable.
*   **Nautical Dawn/Dusk**: Sun is 12 degrees below the horizon. Horizon is visible.
*   **Astronomical Dawn/Dusk**: Sun is 18 degrees below the horizon. Sky is no longer completely dark.
*   **Golden Hour**: Soft, warm light when the sun is close to the horizon.

## Installation

### CMake

You can include SunLight in your project using CMake.

1.  Clone the repository or add it as a submodule.
2.  Add the following to your `CMakeLists.txt`:

```cmake
add_subdirectory(SunLight)
target_link_libraries(YourTarget PRIVATE SunLight)
```

## Usage

Here is a simple example of how to use the `SunLight` library:

```cpp
#include <iostream>
#include <ctime>
#include "SunLight.h"

int main() {
    // Stockholm, Sweden
    double latitude  = 59.370272;
    double longitude = 18.000767;
    time_t now       = time(NULL);

    SunLight sunLight(Date(now), latitude, longitude);

    time_t sunrise = sunLight.sunrise();
    time_t sunset  = sunLight.sunset();

    std::cout << "Sunrise: " << asctime(gmtime(&sunrise));
    std::cout << "Sunset:  " << asctime(gmtime(&sunset));

    return 0;
}
```

## Testing

### Install Google Test (GTest)

```bash
sudo apt-get install libgtest-dev
cd /usr/src/gtest
sudo cmake .
sudo make
sudo cp lib/*.a /usr/lib
```

### Running Tests

1.  Build with tests enabled:
```bash
cd build
cmake -DCMAKE_BUILD_TYPE=Release -Dmake_tests=ON ..
make
```

2.  Run the tests:
```bash
./Tests/SunLight_tests
```

## Reference

*   [NOAA Solar Calculator](https://www.esrl.noaa.gov/gmd/grad/solcalc/index.html)

## Credits

This library is strongly influenced by the JavaScript library [solar-calc](https://github.com/jonhester/solar-calc).

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.