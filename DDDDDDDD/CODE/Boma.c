#include "Boma.h"

void Boma_init(void)
{
  gpio_init(P33_12, GPI, 0, PULLUP);
  gpio_init(P33_13, GPI, 0, PULLUP);
  gpio_init(P33_4, GPI, 0, PULLUP);
  gpio_init(P33_5, GPI, 0, PULLUP);
}

