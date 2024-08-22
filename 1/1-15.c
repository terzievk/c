// copyright
#include <stdio.h>

#define LOWER 0    /* lower limit of temperature table */
#define UPPER 300  /* upper limit */
#define STEP  20   /* step size */

float toCelsius(float fahr);

/* print Fahrenheit-Celsius table
 for fahr = 0, 20, ..., 300; floating-point version */
int main() {
  for (float fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP) {
    printf("%3.0f %6.1f\n", fahr, toCelsius(fahr));
  }

  return 0;
}

float toCelsius(float fahr) {
  return (fahr - 32) * 5 / 9;
}
