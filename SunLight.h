#ifndef __SUN_LIGHT_H__
#define  __SUN_LIGHT_H__

#include <time.h>
#include "Date.h"
#include "SunCalc.h"

/*
    This class gives you varios sunrise and sunset values depening on your date and longiture and latitude.
    It bases its implementation on the NOAA Solar Calculator.

    Credits: 
        This is strongly influenced by the javascript library solar-calc
        https://github.com/jonhester/solar-calc
    
    Reference:
        https://www.esrl.noaa.gov/gmd/grad/solcalc/index.html
*/

class SunLight
{
  private:
    SunCalc *_sun;
    double _latitude;
    double _longitude;
    Date _date;

  public:
    SunLight(Date date, double latitude, double longitude);

    inline void Changer(Date date) { _date = date; }

    /// \brief When the upper edge of the Sun appears over the eastern horizon in the morning (0.833 degrees)
    time_t sunrise();
    
    /// \brief When the upper edge of the Sun disappears below the horizon 
    time_t sunset();

    /// \brief 
    time_t sunriseEnd();

    /// \brief 
    time_t sunsetStart();

    /// \brief Aka civil Dawn.
    time_t dawn();

    /// \brief Aka civil Dusk.
    time_t dusk();

    /// \brief When there is enough light for objects to be distinguishable. This occurs when the sun is 6 degrees below the horizon in the morning
    time_t civilDawn();

    /// \brief When the sun is 6 degrees below the horizon in the evening. At this time objects are distinguishable and some stars and planets are 
    ///        visible to the naked eye.
    time_t civilDusk();
    
    /// \brief When there is enough sunlight for the horizon and some objects to be distinguishable. This occurs when the Sun is 12 degrees below 
    //         the horizon in the morning
    time_t nauticalDawn();

    /// \brief When the sun is 12 degrees below the horizon in the evening. At this time, objects are no longer distinguishable, and the horizon is
    ///        no longer visible to the naked eye
    time_t nauticalDusk();

    /// \brief Astronomical dusk is the moment when the geometric center of the Sun is 18 degrees below the horizon in the evening. 
    time_t astronomicalDusk();

    /// \brief When the sky is no longer completely dark. This occurs when the Sun is 18 degrees below the horizon in the morning
    time_t astronomicalDawn();

    /// \brief When the Sun is close to the horizon on a sunny day, its light appears warmer and softer.
    time_t goldenHourStart();

    /// \brief When the Sun is close to the horizon on a sunny day, its light appears warmer and softer.
    time_t goldenHourEnd();
};

#endif // __SUN_LIGHT_H__