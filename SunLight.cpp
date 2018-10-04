#include <stdio.h>
#include <string.h>
#include <iostream>
#include <sys/time.h>

#include "SunLight.h"

SunLight::SunLight(Date date, double latitude, double longitude)
{
    _date = date;
    _latitude = latitude;
    _longitude = longitude;

    _sun = new SunCalc(date, latitude, longitude);
}

/// \brief When the upper edge of the Sun appears over the eastern horizon in the morning (0.833 degrees)
time_t SunLight::sunrise()
{
    return _sun->timeAtAngle(SunCalc::sunrise, true);
}

/// \brief When the upper edge of the Sun disappears below the horizon
time_t SunLight::sunset()
{
    return _sun->timeAtAngle(SunCalc::sunrise, false);
}

/// \brief
time_t SunLight::sunriseEnd()
{
    return _sun->timeAtAngle(SunCalc::sunriseEnd, true);
}

/// \brief
time_t SunLight::sunsetStart()
{
    return _sun->timeAtAngle(SunCalc::sunriseEnd, false);
}

/// \brief Aka civild Dawn.
time_t SunLight::dawn() 
{
    return civilDawn();
}

/// \brief Aka civild dusk.
time_t SunLight::dusk() 
{
    return civilDusk();
}

/// \brief When there is enough light for objects to be distinguishable. This occurs when the sun is 6 degrees below the horizon in the morning
time_t SunLight::civilDawn()
{
    return _sun->timeAtAngle(SunCalc::twilight, true);
}

/// \brief When the sun is 6 degrees below the horizon in the evening. At this time objects are distinguishable and some stars and planets are
///        visible to the naked eye.
time_t SunLight::civilDusk()
{
    return _sun->timeAtAngle(SunCalc::twilight, false);
}

/// \brief When there is enough sunlight for the horizon and some objects to be distinguishable. This occurs when the Sun is 12 degrees below
//         the horizon in the morning
time_t SunLight::nauticalDawn()
{
    return _sun->timeAtAngle(SunCalc::nauticalTwilight, true);
}

/// \brief When the sun is 12 degrees below the horizon in the evening. At this time, objects are no longer distinguishable, and the horizon is
///        no longer visible to the naked eye
time_t SunLight::nauticalDusk()
{
    return _sun->timeAtAngle(SunCalc::nauticalTwilight, false);
}

/// \brief Astronomical dusk is the moment when the geometric center of the Sun is 18 degrees below the horizon in the evening.
time_t SunLight::astronomicalDusk()
{
    return _sun->timeAtAngle(SunCalc::night, false);
}

/// \brief When the sky is no longer completely dark. This occurs when the Sun is 18 degrees below the horizon in the morning
time_t SunLight::astronomicalDawn()
{
    return _sun->timeAtAngle(SunCalc::night, true);
}

/// \brief When the Sun is close to the horizon on a sunny day, its light appears warmer and softer.
time_t SunLight::goldenHourStart()
{
    return _sun->timeAtAngle(SunCalc::goldenHour, false);
}

/// \brief When the Sun is close to the horizon on a sunny day, its light appears warmer and softer.
time_t SunLight::goldenHourEnd()
{
    return _sun->timeAtAngle(SunCalc::goldenHour, true);
}

/*
int main(int argc, char *argv[])
{
    tzset();
    Date d;
    d.year = 2015;
    d.month = 3;
    d.day = 8;
    SunLight s(d, 35.78L, -78.649999L);
    time_t expt = 1425814530;
    time_t x = s.sunrise();    
    if( x !=  expt )
    {
        std::cout << "Failed" << std::endl;
    }

    struct tm *ptm2 = gmtime(&x);
    char buf[1024];
    memset(buf, 0, sizeof(buf));
    strftime(buf, sizeof(buf), "%Y %m %d %H:%M:%SZ", ptm2);
    std::cout << buf << std::endl;
    
    expt = 1425856548;
    x = s.sunset();
    if( x != expt )
    {
        std::cout << "Failed" << std::endl;
    }

    // London
    SunLight london(d, 51.508530L, -0.076132L);
    expt = 1425796261;
    x = london.sunrise();
    if( x != expt )
    {
        std::cout << "Failed" << std::endl;
    }
    ptm2 = gmtime(&x);
    memset(buf, 0, sizeof(buf));
    strftime(buf, sizeof(buf), "%Y %m %d %H:%M:%SZ", ptm2);
    std::cout << buf << std::endl;
    return 0;
}*/