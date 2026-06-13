// ELYRIA STORIES - Systeme audio et musique

#include "audio.h"

// Stations de radio
RadioStation stations[] = {
    {
        .name = "Elyria Funk FM",
        .genre = FUNK,
        .volume = 80,
        .is_playing = 0,
        .songs = {
            "James Brown - Get Up",
            "Parliament - Flash Light",
            "Sly Stone - Family Affair",
            "Curtis Mayfield - Superfly",
            "Kool and the Gang - Jungle Boogie",
            "Earth Wind Fire - September",
            "George Clinton - Atomic Dog",
            "Rick James - Super Freak",
            "Chic - Le Freak",
            "Gap Band - You Dropped A Bomb"
        },
        .total_songs = 10
    },
    {
        .name = "Liberty Hip Hop",
        .genre = HIP_HOP,
        .volume = 80,
        .is_playing = 0,
        .songs = {
            "Dr Dre - Still DRE",
            "Tupac - California Love",
            "Biggie - Hypnotize",
            "Jay Z - Hard Knock Life",
            "Snoop Dogg - Drop It Like Its Hot",
            "Kendrick Lamar - HUMBLE",
            "Ice Cube - It Was A Good Day",
            "NWA - Straight Outta Compton",
            "DMX - Party Up",
            "Eminem - Lose Yourself"
        },
        .total_songs = 10
    },
    {
        .name = "Elyria RnB",
        .genre = RNB,
        .volume = 80,
        .is_playing = 0,
        .songs = {
            "Michael Jackson - Billie Jean",
            "Prince - Purple Rain",
            "Marvin Gaye - Sexual Healing",
            "Whitney Houston - I Will Always Love You",
            "Stevie Wonder - Superstition",
            "Al Green - Lets Stay Together",
            "Barry White - Cant Get Enough",
            "Lionel Richie - All Night Long",
            "Teddy Pendergrass - Turn Off The Lights",
            "Luther Vandross - Never Too Much"
        },
        .total_songs = 10
    },
    {
        .name = "USA Classic Rock",
        .genre = ROCK,
        .volume = 80,
        .is_playing = 0,
        .songs = {
            "AC DC - Highway To Hell",
            "Led Zeppelin - Kashmir",
            "Guns N Roses - Paradise City",
            "Aerosmith - Walk This Way",
            "Rolling Stones - Paint It Black",
            "Jimi Hendrix - Purple Haze",
            "The Doors - Riders On The Storm",
            "Lynyrd Skynyrd - Sweet Home Alabama",
            "Eagles - Hotel California",
            "Fleetwood Mac - Go Your Own Way"
        },
        .total_songs = 10
    },
    {
        .name = "Elyria Jazz Lounge",
        .genre = JAZZ,
        .volume = 70,
        .is_playing = 0,
        .songs = {
            "Miles Davis - Kind Of Blue",
            "John Coltrane - A Love Supreme",
            "Louis Armstrong - What A Wonderful World",
            "Duke Ellington - Take The A Train",
            "Thelonious Monk - Round Midnight",
            "Charlie Parker - Ornithology",
            "Dave Brubeck - Take Five",
            "Herbie Hancock - Watermelon Man",
            "Chet Baker - My Funny Valentine",
            "Bill Evans - Waltz For Debby"
        },
        .total_songs = 10
    },
    {
        .name = "Liberty Pop Radio",
        .genre = POP,
        .volume = 80,
        .is_playing = 0,
        .songs = {
            "Michael Jackson - Thriller",
            "Madonna - Like A Prayer",
            "Prince - Kiss",
            "David Bowie - Heroes",
            "Queen - Bohemian Rhapsody",
            "Elton John - Crocodile Rock",
            "Billy Joel - Piano Man",
            "Bruce Springsteen - Born To Run",
            "The Police - Every Breath You Take",
            "Tina Turner - Simply The Best"
        },
        .total_songs = 10
    },
};

int total_stations = 6;
int current_station = 0;

// Changer de station
void change_station(int index) {
    stations[current_station].is_playing = 0;
    current_station = index % total_stations;
    stations[current_station].is_playing = 1;
}

// Monter volume
void volume_up() {
    if (stations[current_station].volume < 100)
        stations[current_station].volume += 10;
}

// Baisser volume
void volume_down() {
    if (stations[current_station].volume > 0)
        stations[current_station].volume -= 10;
}

// Musique de mission
void play_mission_music(MissionMood mood) {
    switch(mood) {
        case TENSE:
            // Musique tendue pour mission
            break;
        case ACTION:
            // Musique action pour fusillade
            break;
        case STEALTH:
            // Musique discrete pour infiltration
            break;
        case VICTORY:
            // Musique victoire fin mission
            break;
        case FAIL:
            // Musique echec mission
            break;
    }
}
