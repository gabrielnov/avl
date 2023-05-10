#ifndef __TITULO_H__
#define __TITULO_H__

#include <string>
#include "stdlib.h"

class Title{
    private:
        std::string id;
        std::string title;
        std::string showType;
        std::string description;
        std::string releaseYear;
        std::string ageCertification;
        std::string runtime;
        std::string genres;
        std::string productionCountries;
        std::string seasons;
        std::string imdbId;
        std::string imdbScore;
        std::string imdbVotes;
        std::string tmdbPopularity;
        std::string tmdbScore;

    public:
        ~Title();
        Title(){};
                
        // Getter for id
        std::string getId() const {
            return id;
        }

        // Getter for title
        std::string getTitulo() const {
            return title;
        }

        // Getter for showType
        std::string getShowType() const {
            return showType;
        }

        // Getter for description
        std::string getDescription() const {
            return description;
        }

        // Getter for releaseYear
        std::string getReleaseYear() const {
            return releaseYear;
        }

        // Getter for ageCertification
        std::string getAgeCertification() const {
            return ageCertification;
        }

        // Getter for runtime
        std::string getRuntime() const {
            return runtime;
        }

        // Getter for genres
        std::string getGenres() const {
            return genres;
        }

        // Getter for productionCountries
        std::string getProductionCountries() const {
            return productionCountries;
        }

        // Getter for seasons
        std::string getSeasons() const {
            return seasons;
        }

        // Getter for imdbId
        std::string getImdbId() const {
            return imdbId;
        }

        // Getter for imdbScore
        std::string getImdbScore() const {
            return imdbScore;
        }

        // Getter for imdbVotes
        std::string getImdbVotes() const {
            return imdbVotes;
        }

        // Getter for tmdbPopularity
        std::string getTmdbPopularity() const {
            return tmdbPopularity;
        }

        // Getter for tmdbScore
        std::string getTmdbScore() const {
            return tmdbScore;
        }

        // Setter for id
        void setId(const std::string& newId) {
            id = newId;
        }

        // Setter for title
        void setTitulo(const std::string& newTitulo) {
            title = newTitulo;
        }

        // Setter for showType
        void setShowType(const std::string& newShowType) {
            showType = newShowType;
        }

        // Setter for description
        void setDescription(const std::string& newDescription) {
            description = newDescription;
        }

        // Setter for releaseYear
        void setReleaseYear(const std::string& newReleaseYear) {
            releaseYear = newReleaseYear;
        }

        // Setter for ageCertification
        void setAgeCertification(const std::string& newAgeCertification) {
            ageCertification = newAgeCertification;
        }

        // Setter for runtime
        void setRuntime(const std::string& newRuntime) {
            runtime = newRuntime;
        }

        // Setter for genres
        void setGenres(const std::string& newGenres) {
            genres = newGenres;
        }

        // Setter for productionCountries
        void setProductionCountries(const std::string& newProductionCountries) {
            productionCountries = newProductionCountries;
        }

        // Setter for seasons
        void setSeasons(const std::string& newSeasons) {
            seasons = newSeasons;
        }

        // Setter for imdbId
        void setImdbId(const std::string& newImdbId) {
            imdbId = newImdbId;
        }

        // Setter for imdbScore
        void setImdbScore(const std::string& newImdbScore) {
            imdbScore = newImdbScore;
        }

        // Setter for imdbVotes
        void setImdbVotes(const std::string& newImdbVotes) {
            imdbVotes = newImdbVotes;
        }

        // Setter for tmdbPopularity
        void setTmdbPopularity(const std::string& newTmdbPopularity) {
            tmdbPopularity = newTmdbPopularity;
        }

        // Setter for tmdbScore
        void setTmdbScore(const std::string& newTmdbScore) {
            tmdbScore = newTmdbScore;
        }

        
};


#endif
