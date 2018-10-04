#include <gtest/gtest.h>

#include "SunLight.h"

SunLight* sunLight;
SunLight* sunLightExtreme;
void Setup()
{
    Date d(2015, 3, 8);
    sunLight        = new SunLight(d, 35.78L, -78.649999L);
    Date e(2015, 6, 23);
    sunLightExtreme =  new SunLight(e, 82.4508, -62.5056); //, -4, false);
}

TEST(SunLight_test, get_golden_hour_start)
{
    EXPECT_EQ(1425854506, sunLight->goldenHourStart());
}

TEST(SunLight_test, get_golden_hour_end)
{
    EXPECT_EQ(1425816570, sunLight->goldenHourEnd());
}

TEST(SunLight_test, get_nautical_dawn)
{
    EXPECT_EQ(1425811226, sunLight->nauticalDawn());
}

TEST(SunLight_test, get_dawn)
{
    EXPECT_EQ(1425813000, sunLight->dawn());
}

TEST(SunLight_test, get_sunrise)
{
    EXPECT_EQ(1425814530, sunLight->sunrise());
}

TEST(SunLight_test, get_sunriseEnd)
{
    EXPECT_EQ(1425814688, sunLight->sunriseEnd());
}

TEST(SunLight_test, get_sunsetStart)
{
    EXPECT_EQ(1425856389, sunLight->sunsetStart());
}

TEST(SunLight_test, get_sunset)
{
    EXPECT_EQ(1425856548, sunLight->sunset());
}

TEST(SunLight_test, get_dusk)
{
    EXPECT_EQ(1425858080, sunLight->dusk());
}

TEST(SunLight_test, get_nautical_dusk)
{
    EXPECT_EQ(1425859857, sunLight->nauticalDusk());
}

/*TEST(SunLight_test, should_get_moon_illuminosity)
{
    EXPECT_EQ(83, Math.round(sunLight->lunarIlluminosity * 100));
}

TEST(SunLight_test, should get moon distance)
{
    EXPECT_EQ(384758, sunLight->lunarDistance);
}*/

TEST(SunLight_test_extream, get_golden_hour_start)
{
    EXPECT_EQ(1439951815, sunLightExtreme->goldenHourStart());
}

TEST(SunLight_test_extream, get_golden_hour_end)
{
    EXPECT_EQ(1430023977, sunLightExtreme->goldenHourEnd());
}

TEST(SunLight_test_extream, get_nautical_dawn)
{
    EXPECT_EQ(1425877733, sunLightExtreme->nauticalDawn());
}
TEST(SunLight_test_extream, get_dawn)
{
    EXPECT_EQ(1427174160, sunLightExtreme->dawn());
}

TEST(SunLight_test_extream, get_sunrise)
{
    EXPECT_EQ(1428380823, sunLightExtreme->sunrise());
}

TEST(SunLight_test_extream, get_sunriseEnd)
{
    EXPECT_EQ(1428469232, sunLightExtreme->sunriseEnd());
}

TEST(SunLight_test_extream, get_sunsetStart)
{
    EXPECT_EQ(1441506692, sunLightExtreme->sunsetStart());
}

TEST(SunLight_test_extream, get_sunset)
{
    EXPECT_EQ(1441593806, sunLightExtreme->sunset());
}
TEST(SunLight_test_extream, get_dusk)
{
    EXPECT_EQ(1442802301, sunLightExtreme->dusk());
}
TEST(SunLight_test_extream, get_nautical_dusk)
{
    EXPECT_EQ(1444098841, sunLightExtreme->nauticalDusk());
}


/*
TEST(SunLight_test_extream, get_night_end)
{
    EXPECT_EQ(1424476800, sunLight->nightEnd());
}
        TEST(SunLight_test_extream, get night start){ 
            EXPECT_EQ(1445385600000, sunLight->nightStart());
        });

        TEST(SunLight_test_extream, should get moon illuminosity){ 
            EXPECT_EQ(22, Math.round(sunLight->lunarIlluminosity * 100));
        });

        TEST(SunLight_test_extream, should get moon distance){ {
            EXPECT_EQ(378178, sunLight->lunarDistance);
        });
  */

int main(int argc, char *argv[])
{
    Setup();
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}