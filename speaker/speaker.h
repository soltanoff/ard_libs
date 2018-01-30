// =========================================================================
#ifndef SPEAKER_H
#define SPEAKER_H
// =========================================================================
#include <Arduino.h>
// =========================================================================
class SoftwareSpeaker {
private:
    short _pin;
public:
    SoftwareSpeaker(byte pin=2);

    void speakerVoice(int time=500, int iteration=1, int frequency=0) const;
    void moduleInitional() const;
};
// =========================================================================
#endif // SPEAKER_H
// =========================================================================
