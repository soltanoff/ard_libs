// =========================================================================
#include "utils.h"
// =========================================================================
// Функция, возвращающая количество свободного ОЗУ (RAM)
int memoryFree() {
   int freeValue;
   if ((int)__brkval == 0)
      freeValue = ((int) &freeValue) - ((int) &__bss_end);
   else
      freeValue = ((int) &freeValue) - ((int) __brkval);
   return freeValue;
}
// =========================================================================
void viewFreeMemory() {
	Serial.print(F("Free RAM: "));
	Serial.println(memoryFree());
}
// =========================================================================
