//
// Created by Pavel Akhtyamov on 02.05.2020.
//

#include "WeatherTestCase.h"
#include "WeatherMock.h"

TEST(Weather, test1) {
    WeatherMock weather;
    ASSERT_NO_THROW(weather.SetApiKey("key"));
}

TEST(Weather, test2) {
    WeatherMock weather;
    cpr::Response mockResponse;
    mockResponse.status_code = 200;
    mockResponse.text = "{\"list\" : [{\"main\": {\"temp\": -13}}]}";
    EXPECT_CALL(weather, Get("Ufa")).WillOnce(testing::Return(mockResponse));

    ASSERT_EQ(weather.GetTemperature("Ufa"), -13);
}

TEST(Weather, test3) {
    WeatherMock weather;
    cpr::Response mockResponse;
    mockResponse.status_code = 404;
    EXPECT_CALL(weather, Get("cityName")).WillOnce(testing::Return(mockResponse));

    ASSERT_THROW(weather.GetResponseForCity("cityName"), std::invalid_argument);
}

TEST(Weather, test4) {
    WeatherMock weather;
    cpr::Response mockResponse;
    mockResponse.status_code = 200;
    mockResponse.text = "{\"list\" : [{\"main\": {\"temp\": -13}}]}";
    EXPECT_CALL(weather, Get("Ufa")).WillOnce(testing::Return(mockResponse));

    cpr::Response mockResponse2;
    mockResponse2.status_code = 200;
    mockResponse2.text = "{\"list\" : [{\"main\": {\"temp\": -13}}]}";
    EXPECT_CALL(weather, Get("Dolgopa")).WillOnce(testing::Return(mockResponse2));

    ASSERT_EQ(weather.GetDifferenceString("Ufa", "Dolgopa"), "Weather in Ufa is warmer than in Dolgopa by 0 degrees");
}