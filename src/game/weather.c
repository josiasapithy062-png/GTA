// ELYRIA STORIES - Meteo et cycle jour nuit

#include "weather.h"

// Etat meteo actuel
WeatherState weather = {
    .current = SUNNY,
    .time_of_day = DAY,
    .hour = 12,
    .minute = 0,
    .temperature = 25,
    .wind_speed = 10.0f,
    .rain_intensity = 0.0f,
    .fog_density = 0.0f
};

// Meteos disponibles
WeatherType weather_types[] = {
    {SUNNY,      "Ensoleille",  0.0f, 0.0f, 10.0f,  1},
    {CLOUDY,     "Nuageux",     0.0f, 0.2f, 15.0f,  1},
    {RAINY,      "Pluvieux",    0.8f, 0.1f, 20.0f,  1},
    {STORMY,     "Orageux",     1.0f, 0.3f, 40.0f,  1},
    {FOGGY,      "Brumeux",     0.0f, 0.9f, 5.0f,   1},
    {WINDY,      "Venteux",     0.0f, 0.0f, 60.0f,  1},
    {SNOWY,      "Neigeux",     0.5f, 0.4f, 8.0f,   1},
    {THUNDER,    "Tonnerre",    1.0f, 0.2f, 35.0f,  1},
    {HURRICANE,  "Ouragan",     1.0f, 0.1f, 120.0f, 0},
    {CLEAR_NIGHT,"Nuit Claire", 0.0f, 0.0f, 5.0f,   1},
};

int total_weather_types = 10;

// Mettre a jour heure
void update_time(float delta_time) {
    weather.minute += (int)(delta_time * 2);
    if (weather.minute >= 60) {
        weather.minute = 0;
        weather.hour++;
    }
    if (weather.hour >= 24) {
        weather.hour = 0;
    }

    // Mettre a jour periode
    if (weather.hour >= 6 && weather.hour < 9)
        weather.time_of_day = MORNING;
    else if (weather.hour >= 9 && weather.hour < 18)
        weather.time_of_day = DAY;
    else if (weather.hour >= 18 && weather.hour < 21)
        weather.time_of_day = EVENING;
    else
        weather.time_of_day = NIGHT;
}

// Changer meteo
void set_weather(WeatherType type) {
    weather.current = type;
}

// Meteo aleatoire
void random_weather() {
    int r = weather.hour % total_weather_types;
    weather.current = weather_types[r].type;
}

// Effets meteo sur gameplay
void apply_weather_effects() {
    switch(weather.current) {
        case RAINY:
        case STORMY:
            // Routes glissantes
            // Visibilite reduite
            break;
        case FOGGY:
            // Visibilite tres reduite
            // Police moins efficace
            break;
        case HURRICANE:
            // Vehicules emportes
            // Marcher difficile
            break;
        case SNOWY:
            // Routes tres glissantes
            // Vitesse reduite
            break;
        default:
            break;
    }
}
