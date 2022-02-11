/*
  Movie.hpp

  Include file for Movie class
*/

#ifndef MOVIE_H
#define MOVIE_H

#include <string>

class Movie {

public:
    static const int REGULAR      = 0;
    static const int NEW_RELEASE  = 1;
    static const int CHILDRENS    = 2;

private:
    std::string title;
    int price_code;

public:
    // constructor
    Movie(const std::string& title, int price_code);

    // movie price code
    int getPriceCode() const;

    // set movie price code
    void setPriceCode(int new_price_code);

    // movie title
    const std::string& getTitle() const;

    // Rental charge
    double getCharge(int) const;
    
    int getFrequentRenterPoints(int) const;


};

//Was trying to build inheritance for methods.
class Price 
{
  //int getPriceCode() const;
};
class ChildrensPrice: public Price
{
    /*
    int getPriceCode()
    { 
       return Movie.CHILDRENS;
    }
    */
};
class NewReleasePrice: public Price
{ 
    /*
    int getPriceCode()
    { 
       return Movie.NEW_RELEASE;
    }
    */
};
class RegularPrice: public Price
{
    /*
    int getPriceCode()
    { 
       return Movie.REGULAR;
    }
    */
};



#endif
