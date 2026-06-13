// ELYRIA STORIES - Header meteo
#ifndef WEATHER_H
#define WEATHER_H

typedef enum {
    SUNNY,
    CLOUDY,
    RAINY,
    STORMY,
    FOGGY,
    WINDY,
    SNOWY,
    THUNDER,
    HURRICANE,
    CLEAR_NIGHT
} WeatherType;

typedef enum {
    MORNING,
    DAY,
    EVENING,
    NIGHT
} TimeOfDay;

typedef struct {
    WeatherType type;
    char name[32];
    float rain_intensity;
    float fog_density;
    float wind_speed;
    int is_available;
} WeatherTypeData;

typedef struct {
    WeatherType current;
    TimeOfDay time_of_day;
    int hour;
    int minute;
    int temperature;
    float wind_speed;
    float rain_intensity;
    float fog_density;
} WeatherState;

extern WeatherState weather;
extern WeatherTypeData weather_types[];
extern int total_weather_types;

void update_time(float delta_time);
void set_weather(WeatherType type);
void random_weather();
void apply_weather_effects();

#endif
