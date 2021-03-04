//
// Created by uddeepk on 3/2/21.
//

#include "SmartArray.hpp"
#include "catch.hpp"

void foo(SmartArray) {

}
TEST_CASE("Check smart array intitialized") {
SmartArray sa{10};
sa[0] = 13;
REQUIRE(sa.size() == 10);
REQUIRE(sa[0] == 13);
const SmartArray csa(sa);
REQUIRE(csa[0] == 13);
SmartArray sa2(30);
sa2 = sa;
REQUIRE(sa2[0] == 13);
sa2 = sa2;
REQUIRE(sa2[0] == 13);
//foo(13);// doesn;t work when implicit conversions are disabled
}