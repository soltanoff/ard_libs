// =========================================================================
#ifndef LCD1602_H
#define LCD1602_H
// =========================================================================
#include <Arduino.h>
#include <LiquidCrystal.h>
// =========================================================================
class SoftwareLCD: public LiquidCrystal {
public:
    const uint8_t ROW_LENGTH = 16;
    const uint8_t ROW_COUNT = 2;

    SoftwareLCD(uint8_t rs, uint8_t enable,
  		uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3,
  		uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7);
    SoftwareLCD(uint8_t rs, uint8_t rw, uint8_t enable,
  		uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3,
  		uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7);
    SoftwareLCD(uint8_t rs, uint8_t rw, uint8_t enable,
  		uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3);
    SoftwareLCD(uint8_t rs, uint8_t enable,
  		uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3);

    void setFirstRowHeader(const char *header);
    const char *getFirstRowHeader() const;

    void setSecondRowHeader(const char *header);
    const char *getSecondRowHeader() const;

    void printTwoLine(const char *data);
    void printToFirstRow(const char *data);
    void printToSecondRow(const char *data);
    void printTemplate(const char *first_row, const char *second_row);
private:
    String *_first_row;
    String *_second_row;

    void _printRowTitle(String *title, uint8_t row);
    void _setHeader(String **header_row, const char *header);
};
// =========================================================================
#endif // LCD1602_H
// =========================================================================
