#include "time.h"
#include "Date.h"

class SunCalc
{
public:    
    static const float sunrise          = 0.833;
    static const float sunriseEnd       = 0.3;
    static const float twilight         = 6.0;
    static const float nauticalTwilight = 12.0;
    static const float night            = 18.0;
    static const float goldenHour       = -6.0;  

private:
    static const double PI=3.141592653589793;

    double _latitude;
    double _longitude;
    Date   _date;
    double _julianDate;

public:
    SunCalc(const Date& date, double latitude, double longitude);
    inline void ChangeDate(const Date& date) { _date = date; }
    time_t ToTimeT(const Date& d, double x);

    double timeAtAngle(float angle, bool rising);

private:
    // rise = true for sunrise, false for sunset
    time_t calcSunriseSet(bool rise, float angle, double JD, Date date, double latitude, double longitude);
    double calcSunriseSetUTC(bool rise, float angle, double JD, double latitude,double longitude);
    double calcTimeJulianCent(double jd);
    double calcEquationOfTime(double t);
    double calcSunDeclination(double t);
    double calcHourAngle(float angle, double lat, double solarDec);
    double calcObliquityCorrection(double t);
    double calcGeomMeanLongSun(double t);
    double calcEccentricityEarthOrbit(double t);   
    double calcGeomMeanAnomalySun(double t);
    double radToDeg(double angleRad);
    double degToRad(double angleDeg);
    double calcSunApparentLong(double t);
    double calcMeanObliquityOfEcliptic(double t);    
    double calcSunTrueLong(double t);
    double calcSunEqOfCenter(double t);
    double calcDoyFromJD(double jd);
    double calcJDofNextPrevRiseSet(bool next, bool rise, float type, double time);
    bool   isLeapYear(int yr);
    time_t JdToDate(double jd);
};
