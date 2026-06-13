// ELYRIA STORIES - Meteo
#include "weather.h"

WeatherState weather = {
    .current = SUNNY,
    .hour = 12,
    .minute = 0,
    .temperature = 25
};

void update_time(float delta_time) {
    weather.minute += 1;
    if (weather.minute >= 60) {
        weather.minute = 0;
        weather.hour++;
    }
    if (weather.hour >= 24) weather.hour = 0;
}

void set_weather(int type) {
    weather.current = type;
}
