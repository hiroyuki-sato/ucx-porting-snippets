#include "link_speed.h"

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <net/if_dl.h>
#include <net/if.h>
#include <ifaddrs.h>
#include <string.h>
#include <stdlib.h>

ucs_status_t link_speed(const char *if_name,
                        uint32_t *speed_bps, uint32_t *mtu) {
    struct ifaddrs *ifap, *ifaptr;
    unsigned char *ptr;
    struct if_data *data;
    uint32_t speed;
    ucs_status_t status = UCS_ERR_IO_ERROR;

    if (getifaddrs(&ifap) == 0) {
        for(ifaptr = ifap; ifaptr != NULL; ifaptr = (ifaptr)->ifa_next) {
            if ((((ifaptr)->ifa_addr)->sa_family == AF_LINK) &&
                !strncmp((ifaptr)->ifa_name, if_name ,strlen(if_name))) {
                data = (struct if_data *)ifaptr->ifa_data;
                *speed_bps = data->ifi_baudrate; /* bps */
                *mtu = data->ifi_mtu;
                status = UCS_OK;
                break;
            }
        }
        freeifaddrs(ifap);
        return status;
    } else {
        return status;
    }
}
