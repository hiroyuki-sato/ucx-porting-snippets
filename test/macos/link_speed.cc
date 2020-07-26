#include "gtest/gtest.h"
#include "link_speed.h"

#include <string>
using std::string;

TEST(LinkSpeed, MTU) {
    uint32_t speed;
    uint32_t mtu;
    ucs_status_t status;

    status = link_speed("en0",&speed,&mtu);

    EXPECT_EQ(UCS_OK, status);
    EXPECT_EQ(1500, mtu);
    EXPECT_EQ(304200000, speed); // TODO get interface value
}

TEST(LinkSpeed, MTUError) {
    uint32_t speed;
    uint32_t mtu;
    ucs_status_t status;

    status = link_speed("en10",&speed,&mtu);

    EXPECT_EQ(UCS_ERR_IO_ERROR, status);
}
