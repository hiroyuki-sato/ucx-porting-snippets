#include "gtest/gtest.h"
#include "link_speed.h"

#include <string>
using std::string;

TEST(LinkSpeed, MTU) {
    uint32_t speed;
    uint32_t mtu;

    link_speed("en0",&speed,&mtu);

    EXPECT_EQ(1500, mtu);
    EXPECT_EQ(304200000, speed); // TODO get interface value
}
