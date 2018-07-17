// =========================================================================
#ifndef LCD1602_H
#define LCD1602_H
// =========================================================================
#include <Arduino.h>
#include <ArduinoSTL.h>
#include <Keypad.h>
#include <SoftwareSerial.h>
#include <speaker.h>
// =========================================================================
class SoftwareLCD: public LiquidCrystal {
public:
    SoftwareLCD(uint8_t rs, uint8_t enable,
  		uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3,
  		uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7):
        LiquidCrystal(rs, enable, d0, d1, d2, d3, d4, d5, d6, d7)
        { this->_first_row = this->_second_row = nullptr; };
    SoftwareLCD(uint8_t rs, uint8_t rw, uint8_t enable,
  		uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3,
  		uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7):
        LiquidCrystal(rs, rw, enable, d0, d1, d2, d3, d4, d5, d6, d7)
        { this->_first_row = this->_second_row = nullptr; };
    SoftwareLCD(uint8_t rs, uint8_t rw, uint8_t enable,
  		uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3):
        LiquidCrystal(rs, rw, enable, d0, d1, d2, d3)
        { this->_first_row = this->_second_row = nullptr; };
    SoftwareLCD(uint8_t rs, uint8_t enable,
  		uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3):
        LiquidCrystal(rs, enable, d0, d1, d2, d3)
        { this->_first_row = this->_second_row = nullptr; };

    void setFirstRowHeader(const char *header) {
        this->_setHeader(&this->_first_row, header);
    }

    const char *getFirstRowHeader() const {
        return this->_first_row != nullptr ? this->_first_row->c_str(): "";
    }

    void setSecondRowHeader(const char *header) {
        this->_setHeader(&this->_second_row, header);
    }

    const char *getSecondRowHeader() const {
        return this->_second_row != nullptr ? this->_second_row->c_str(): "";
    }

    void printTwoLine(const char *data) {
        this->clear();
        if (this->_first_row != nullptr) {
            this->setCursor(0, 0);
            this->print(this->_first_row->c_str());
            this->setCursor(0, 1);
        }
        else
            this->setCursor(0, 0);
        this->print(data);
    }

    void printToFirstRow(const char *data) {
        this->_printRowTitle(this->_first_row, 1);
        this->print(data);
    }

    void printToSecondRow(const char *data) {
        this->_printRowTitle(this->_second_row, 2);
        this->print(data);
    }

    void printTemplate(const char *first_row, const char *second_row) {
        this->clear();
        this->printToFirstRow(first_row);
        this->printToSecondRow(second_row);
    }
private:
    String *_first_row;
    String *_second_row;

    void _printRowTitle(String *title, uint8_t row) {
        if (title != nullptr) {
            this->setCursor(row, 0);
            this->print(title->c_str());
            this->setCursor(row, 1);
        }
        else
            this->setCursor(row, 0);
        this->print(title->c_str());
    }

    void _setHeader(String **header_row, const char *header) {
        if (*header_row != nullptr) {
            delete header_row;
            *header_row = nullptr;
        }
        *header_row = new String(header);
    }
};
// =========================================================================
#endif // LCD1602_H
// =========================================================================
