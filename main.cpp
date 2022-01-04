#include <iostream>
#include "nlohmann/json.hpp"
#include <string>
#include <map>
#include <fstream>

class Cinema
{
public:
    std::string title;
    std::string creation_date;
    std::string studio;
    std::string country;
    std::string director;
    std::string written;
    std::string producer;
    std::map<std::string,std::string> cast;
};

int main() {

    Cinema spider;

    spider.title = "Spider-man:No way home";
    spider.country = "USA";
    spider.studio = "Marvel";
    spider.creation_date = "2021";
    spider.director = "Jon Watts";
    spider.producer = "Victoria Alonso";
    spider.written = "Stan Lee";
    spider.cast = {{"Tom Holland","Peter Parker"},
                   {"Zendaya","MJ"},
                   {"Willem Dafoe","Norman Osborn"},
                   {"Benedict Cumberbatch","Doctor Strange"}};

    Cinema avengers;

    avengers.title = "The Avengers";
    avengers.country = "USA";
    avengers.studio = "Marvel";
    avengers.creation_date = "2012";
    avengers.director = "Joss Whedon";
    avengers.producer = "Kevin Feige";
    avengers.written = "Stan Lee";
    avengers.cast = {{"Robert Downey Jr.","Iron Man"},
                   {"Chris Evans","Captain America"},
                   {"Chris Hemsworth","Thor"},
                   {"Scarlett Johansson","Black Widow"}};

    Cinema jojo;

    jojo.title = "Jojo Rabbit";
    jojo.country = "New Zeland";
    jojo.studio = "Fox";
    jojo.creation_date = "2019";
    jojo.director = "Taika Waititi";
    jojo.producer = "Carthew Neal";
    jojo.written = "Taika Waititi";
    jojo.cast = {{"Roman Griffin Davis","Jojo"},
                 {"Thomasin McKenzie","Elsa"},
                 {"Scarlett Johansson","Rosie"},
                 {"Taika Waititi","Adolf"},
                 {"Sam Rockwell","Captain Klenzendorf"}};

    std::map<std::string,Cinema&> movies = {{spider.title,spider},{avengers.title,avengers},{jojo.title,jojo}};

    nlohmann::json dict;
    nlohmann::json base;
    std::fstream data("Cinema.json", std::ios::in | std::ios::out);

    for(auto it = movies.begin();it != movies.end();++it)
    {
        dict = {
                 {"country", it->second.country},
                 {"studio", it->second.studio},
                 {"cast", it->second.cast},
                 {"creation_date", it->second.creation_date},
                 {"director", it->second.director},
                 {"written", it->second.written},
                 {"producer", it->second.producer}
                };
        base[it->first] = dict;
    }

    data << base;

    std::string actor;
    std::cout << "Enter the name of the actor to search the database:";
    std::getline(std::cin,actor);

    for (auto itbase = base.begin(); itbase != base.end(); ++itbase)
    {
        dict = itbase.value();
        for (auto itdict = dict.begin(); itdict != dict.end(); ++itdict)
        {
            if (itdict.key() == "cast")
            {
                for(auto itcast = itdict.value().begin();itcast != itdict.value().end();++itcast)
                {
                    if (itcast.key() == actor)
                        std::cout << "Actor: " << itcast.key() << " Movie: " << itbase.key() << " Role: " << itcast.value() << std::endl;
                }
            }
        }
    }
    return 0;
}
