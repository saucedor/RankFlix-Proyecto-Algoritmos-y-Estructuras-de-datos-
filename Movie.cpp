#include "Movie.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>

// Constructor
Movie::Movie(std::string title, double rating, int popularity)
    : title(title), rating(rating), popularity(popularity) {}

// Getters
std::string Movie::getTitle() const { return title; }
double Movie::getRating() const { return rating; }
int Movie::getPopularity() const { return popularity; }

// Comparators
bool Movie::compareByRating(const Movie &a, const Movie &b) {
    return a.getRating() > b.getRating(); // Higher rating first
}

bool Movie::compareByPopularity(const Movie &a, const Movie &b) {
    return a.getPopularity() > b.getPopularity(); // Higher popularity first
}

// Sorting functions
void sortMoviesByRating(std::vector<Movie> &movies) {
    

    std::sort(movies.begin(), movies.end(), Movie::compareByRating);
}

void sortMoviesByPopularity(std::vector<Movie> &movies) {
    std::sort(movies.begin(), movies.end(), Movie::compareByPopularity);
}

// Function to load movies data from a file
std::vector<Movie> loadMovies() {
    std::vector<Movie> movies;
    std::ifstream file("movies.txt");
    std::string line, title;
    double rating;
    int popularity;

    if (!file.is_open()) {
        std::cerr << "Could not open the file!" << std::endl;
        return movies;
    }

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::getline(ss, title, '|');
        ss >> rating;
        ss.ignore();  // Skip the '|'
        ss >> popularity;
        movies.emplace_back(title, rating, popularity);
    }

    file.close();
    return movies;
}
