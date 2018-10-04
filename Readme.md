# SunLight

 This class library gives you varios sunrise and sunset values depening on your date and longiture and latitude.
 It bases its implementation on the NOAA Solar Calculator.


### Credits:
    This is strongly influenced by the javascript library solar-calc
    https://github.com/jonhester/solar-calc
    
### Reference:
    https://www.esrl.noaa.gov/gmd/grad/solcalc/index.html


### Sample:

```cpp
    double latitude  = 59.370272;
    double longitude = 18.000767;
    time_t now       = time(NULL);

    SunLight sunLight(Date(now), latitude, longitude);

    time_t sunrise  = sunLight.sunrise();
    time_t sunset   = sunLight.sunset();

    std::cout << "sunrise: " << asctime( gmtime(&sunrise)) << std::endl;
    std::cout << "sunset:  " << asctime( gmtime(&sunrise)) << std::endl;
```