#ifndef WIFI_DRIVER_H
#define WIFI_DRIVER_H

#include <stdbool.h>

void WiFiDriver_Init(void);

bool WiFiDriver_IsConnected(void);

#endif /* WIFI_DRIVER_H */