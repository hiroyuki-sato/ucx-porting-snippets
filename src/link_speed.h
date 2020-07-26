#ifndef LINK_SPEED_H
#define LINK_SPEED_H

#include <ucx.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <net/if_dl.h>
#include <net/if.h>
#include <ifaddrs.h>
#include <string.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

ucs_status_t link_speed(const char *if_name,
                        uint32_t *speed_bps, uint32_t *mtu);

#ifdef __cplusplus
}
#endif

#endif
