// =========================================================================
#include "speaker.h"
// =========================================================================
SoftwareSpeaker::SoftwareSpeaker(byte pin) {
    this->_pin = pin;
    pinMode(this->_pin, OUTPUT);
}
// =========================================================================
void SoftwareSpeaker::speakerVoice(
    int time,
    int iteration,
    int frequency
) const {
    for(int i = 5; i <= 5 * iteration; i+=5) {
        if (frequency)
            tone(this->_pin, frequency);
        else
            tone(this->_pin, i);

        delay(time);
        noTone(this->_pin);
        delay(time);
    }
}
// =========================================================================
void SoftwareSpeaker::moduleInitional() const {
    this->speakerVoice(40, 3, 0);
}
// =========================================================================
