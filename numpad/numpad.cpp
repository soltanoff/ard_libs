// =========================================================================
#include "numpad.h"
// =========================================================================
void SoftwareNumpad::_receive() {
    if (this->_receiver) this->_receiver->print(this->getBuf());
    Serial.println(this->getBuf());
}
// =========================================================================
void SoftwareNumpad::_createBuf() {
     this->_buf = new String();
}
// =========================================================================
void SoftwareNumpad::_removeBuf() {
    delete this->_buf;
    this->_buf = nullptr;
}
// =========================================================================
void SoftwareNumpad::_clearBuf() {
    this->_removeBuf();
    this->_createBuf();
}
// =========================================================================
void SoftwareNumpad::_popBackBuf() {
    this->_buf->remove(this->_buf->length() - 1);
}
// =========================================================================
void SoftwareNumpad::_pushBackBuf(const char key) {
    *(this->_buf) += key;
}
// =========================================================================
void SoftwareNumpad::_singSimpleSong() const {
    this->_speaker->speakerVoice(40, 1, 500);
}
// =========================================================================
void SoftwareNumpad::_singSpecialSong() const {
    this->_speaker->speakerVoice(60, 1, 10);
}
// =========================================================================
SoftwareNumpad::SoftwareNumpad(
    SoftwareSpeaker *speaker,
    SoftwareSerial *receiver
) {
    this->_speaker = speaker;
    this->_receiver = receiver;
    this->_keypad = new Keypad(
        makeKeymap(KP_HEXKEY),
        KP_ROWPINS,
        KP_COLPINS,
        KP_ROWS,
        KP_COLS
    );
    this->_createBuf();
}
// =========================================================================
void SoftwareNumpad::getKeyToSerial() {
    char key = this->_keypad->getKey();
    if (key != NO_KEY) {
        switch (key) {
            case KP_ACCEPT:
                this->_receive();
                this->_singSpecialSong();
                break;
            case KP_BACKSPACE:
                this->_popBackBuf();
                this->_singSpecialSong();
                break;
            case KP_CLEAR:
                this->_clearBuf();
                this->_singSpecialSong();
                break;
            case KP_DENIED:
                // viewFreeMemory();
                this->_singSpecialSong();
                break;
            default:  // other
                this->_pushBackBuf(key);
                this->_singSimpleSong();
                break;
        }
    }
}
// =========================================================================
const char *SoftwareNumpad::getBuf() const {
    return this->_buf->c_str();
}
// =========================================================================
