#include <iostream>
#include <boost/lambda/lambda.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>

using namespace boost::lambda;
using namespace boost::gregorian;

int main(void) {
    auto const today = date(2002,Feb,1);
    std::cout << today << std::endl;

    return 0;
}

