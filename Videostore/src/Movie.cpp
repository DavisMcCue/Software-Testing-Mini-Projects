/*
  Movie.cpp

  Definition file for Movie class
*/

#include "Movie.hpp"

// constructor
Movie::Movie(const std::string& title, int price_code)
    : title(title)
{setPriceCode(price_code);}

// movie price code
int Movie::getPriceCode() const {

    return price_code;
}

// set movie price code
void Movie::setPriceCode(int new_price_code) {

    price_code = new_price_code;
}

// movie title
const std::string& Movie::getTitle() const 
{

    return title;
}

double Movie::getCharge(int days_of_rent) const
{
       //determine amounts for each line
        double totalAmount = 0;
        switch (getPriceCode())
        {
            case Movie::REGULAR:
                totalAmount += 2;
                if (days_of_rent > 2)
                    totalAmount += (days_of_rent - 2) * 1.5;
                break;
            case Movie::NEW_RELEASE:
                totalAmount += days_of_rent * 3;
                break;
            case Movie::CHILDRENS:
                totalAmount += 1.5;
                if (days_of_rent > 3)
                    totalAmount += (days_of_rent - 3) * 1.5;
                break;
        }
   return totalAmount; 
}
int Movie::getFrequentRenterPoints(int days_of_rent) const
{
       // add frequent renter points
        int frequentRenterPoints = 0;
        ++frequentRenterPoints;
        // add bonus for a two day new release rental
        if ((getPriceCode() == Movie::NEW_RELEASE) && days_of_rent > 1) 
        {
            frequentRenterPoints++;
        }
    return frequentRenterPoints++;
}

