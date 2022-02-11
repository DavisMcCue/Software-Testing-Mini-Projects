/*
  Customer.cpp

  Definition file for Customer class
*/

#include "Customer.hpp"
#include "Movie.hpp"
#include "Rental.hpp"

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

// constructor
Customer::Customer(const std::string& name)
    : name(name)
{ }

// add a rental to this customer
void Customer::addRental(const Rental& rental) {

    rentals.push_back(rental);
}

// customer name
std::string Customer::getName() const {

    return name;
}

// customer rental statement
std::string Customer::statement() const 
{

    double totalAmount = 0;
    int frequentRenterPoints = 0;
    std::string result = "Rental Record for " + getName() + "\n";
    for(std::vector<Rental>::const_iterator it = rentals.begin(); it != rentals.end(); ++it) 
    {
        double thisAmount = 0;
        Rental each = (Rental) *it;

	thisAmount = each.getCharge();
        frequentRenterPoints+=each.getFrequentRenterPoints();

        // show figures for this rental
        result += "\t" + each.getMovie().getTitle()+ "\t";
        std::ostringstream amount_stream;
        amount_stream << each.getCharge();
        result +=  amount_stream.str();
        result += "\n";
        totalAmount += each.getCharge();

    }

    // add footer lines
    // total amount owed
    result += "Amount owed is: ";
    std::ostringstream owed_stream;
    owed_stream << getTotalCharge();  // <- getTotalCharge here
    result += owed_stream.str();
    result += "\n";

    // frequent renter points earned
    result += "You earned: ";
    std::ostringstream frequent_stream;
    frequent_stream << getTotalFrequentRenterPoints();// <- getTotalFrequentRenterPoints here
    result += frequent_stream.str();
    result += " frequent renter points\n";

    return result;
   }

double Customer::getTotalCharge()const
{
    double totalAmount = 0;
    for(std::vector<Rental>::const_iterator it = rentals.begin(); it != rentals.end(); ++it) 
    {
        Rental each = (Rental) *it;
        totalAmount += each.getCharge();
    }
   return totalAmount;
}
int Customer::getTotalFrequentRenterPoints()const
{       
    int frequentRenterPoints = 0;
    for(std::vector<Rental>::const_iterator it = rentals.begin(); it != rentals.end(); ++it) 
    {
        Rental each = (Rental) *it;
        frequentRenterPoints+=each.getFrequentRenterPoints();
    }
   return frequentRenterPoints;
}
