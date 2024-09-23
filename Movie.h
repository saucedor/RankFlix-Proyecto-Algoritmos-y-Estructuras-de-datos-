#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <vector>

class Movie {
private:
    std::string title;
    double rating;
    int popularity;

public:
    // Constructor
    Movie(std::string title, double rating, int popularity);

    // Getters
    std::string getTitle() const;
    double getRating() const;
    int getPopularity() const;

    // Comparators for sorting
    static bool compareByRating(const Movie &a, const Movie &b);
    static bool compareByPopularity(const Movie &a, const Movie &b);
};

// Function to load data (could be from a file)
std::vector<Movie> loadMovies();

// Sorting functions
void sortMoviesByRating(std::vector<Movie> &movies);
void sortMoviesByPopularity(std::vector<Movie> &movies);

#endif // MOVIE_H