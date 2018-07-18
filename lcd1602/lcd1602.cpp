// =========================================================================
#include "lcd1602.h"
// =========================================================================
SoftwareLCD::SoftwareLCD(uint8_t rs, uint8_t enable,
		uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3,
		uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7):
    LiquidCrystal(rs, enable, d0, d1, d2, d3, d4, d5, d6, d7) {
        this->_first_row = this->_second_row = nullptr;
        this->begin(this->ROW_LENGTH, this->ROW_COUNT);
    };
SoftwareLCD::SoftwareLCD(uint8_t rs, uint8_t rw, uint8_t enable,
		uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3,
		uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7):
    LiquidCrystal(rs, rw, enable, d0, d1, d2, d3, d4, d5, d6, d7) {
        this->_first_row = this->_second_row = nullptr;
        this->begin(this->ROW_LENGTH, this->ROW_COUNT);
    };
SoftwareLCD::SoftwareLCD(uint8_t rs, uint8_t rw, uint8_t enable,
		uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3):
    LiquidCrystal(rs, rw, enable, d0, d1, d2, d3) {
        this->_first_row = this->_second_row = nullptr;
        this->begin(this->ROW_LENGTH, this->ROW_COUNT);
    };
SoftwareLCD::SoftwareLCD(uint8_t rs, uint8_t enable,
		uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3):
    LiquidCrystal(rs, enable, d0, d1, d2, d3) {
        this->_first_row = this->_second_row = nullptr;
        this->begin(this->ROW_LENGTH, this->ROW_COUNT);
    };
// =========================================================================
void SoftwareLCD::setFirstRowHeader(const char *header) {
    this->_setHeader(&this->_first_row, header);
}
// =========================================================================
const char *SoftwareLCD::getFirstRowHeader() const {
    return this->_first_row != nullptr ? this->_first_row->c_str(): "";
}
// =========================================================================
void SoftwareLCD::setSecondRowHeader(const char *header) {
    this->_setHeader(&this->_second_row, header);
}
// =========================================================================
const char *SoftwareLCD::getSecondRowHeader() const {
    return this->_second_row != nullptr ? this->_second_row->c_str(): "";
}
// =========================================================================
void SoftwareLCD::printTwoLine(const char *data) {
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
// =========================================================================
void SoftwareLCD::printToFirstRow(const char *data) {
    this->_printRowTitle(this->_first_row, 0);
    this->print(data);
}
// =========================================================================
void SoftwareLCD::printToSecondRow(const char *data) {
    this->_printRowTitle(this->_second_row, 1);
    this->print(data);
}
// =========================================================================
void SoftwareLCD::printTemplate(const char *first_row, const char *second_row) {
    this->clear();
    this->printToFirstRow(first_row);
    this->printToSecondRow(second_row);
}
// =========================================================================
void SoftwareLCD::_printRowTitle(String *title, uint8_t row) {
    if (title != nullptr) {
        this->setCursor(0, row);
        this->print(title->c_str());
    }
    else
        this->setCursor(0, row);
}
// =========================================================================
void SoftwareLCD::_setHeader(String **header_row, const char *header) {
    if (*header_row != nullptr) {
        delete header_row;
        *header_row = nullptr;
    }
    *header_row = new String(header);
}
// =========================================================================
