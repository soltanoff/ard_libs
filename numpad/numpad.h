// =========================================================================
#ifndef NUMPAD_H
#define NUMPAD_H
// =========================================================================
#include <Arduino.h>
#include <ArduinoSTL.h>
#include <Keypad.h>
#include <SoftwareSerial.h>
#include <speaker.h>
// =========================================================================
#define KP_ROWS       4
#define KP_COLS       4
#define KP_ACCEPT    'A'
#define KP_BACKSPACE 'B'
#define KP_CLEAR     'C'
#define KP_DENIED    'D'
// =========================================================================
static const char KP_HEXKEY[KP_ROWS][KP_COLS] = {
  {'1', '2', '3', KP_ACCEPT},
  {'4', '5', '6', KP_BACKSPACE},
  {'7', '8', '9', KP_CLEAR},
  {'*', '0', '#', KP_DENIED}
};
//                                 R1  R2  R3  R4
static byte KP_ROWPINS[KP_ROWS] = {13, 12, 11, 10};
//                                 C1  C2  C3  C4
static byte KP_COLPINS[KP_COLS] = { 9,  8,  7,  6};
// =========================================================================
// TODO: soltanoff: need using interrupt
// TODO: polinacracker: set hook to main methods of cout/printf (see cgetf(), cputf())
// FIXME: soltanoff: refactor
class SoftwareNumpad {
private:
    String *_buf;
    Keypad *_keypad;
    SoftwareSpeaker *_speaker;
    SoftwareSerial *_receiver;

    void _receive();

    void _createBuf();
    void _removeBuf();
    void _clearBuf();
    void _popBackBuf();
    void _pushBackBuf(const char key);

    void _singSimpleSong() const;
    void _singSpecialSong() const;
public:
    SoftwareNumpad(
        SoftwareSpeaker *speaker,
        SoftwareSerial *receiver=nullptr
    );
    void getKeyToSerial();
    const char *getBuf() const;
};
// =========================================================================
#endif // NUMPAD_H
// =========================================================================
