#include "Movie.h"
#include <iostream>
#include <vector>

void displayMovies(const std::vector<Movie> &movies) {
    for (const auto &movie : movies) {
        std::cout << "Title: " << movie.getTitle() << ", Rating: " 
                  << movie.getRating() << ", Popularity: " 
                  << movie.getPopularity() << std::endl;
    }
}

int main() {
    // Load movie data
    std::vector<Movie> movies = loadMovies();

    int choice;
    bool running = true;

    while (running) {
        std::cout << "\nMovie Sorting System\n";
        std::cout << "1. Display movies by rating\n";
        std::cout << "2. Display movies by popularity\n";
        std::cout << "3. Exit\n";
        std::cout << "Choose an option: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                sortMoviesByRating(movies);
                std::cout << "\nMovies sorted by rating:\n";
                displayMovies(movies);
                break;

            case 2:
                sortMoviesByPopularity(movies);
                std::cout << "\nMovies sorted by popularity:\n";
                displayMovies(movies);
                break;

            case 3:
                running = false;
                break;

            default:
                std::cout << "Invalid option. Please try again.\n";
                break;
        }
    }

    return 0;
}
