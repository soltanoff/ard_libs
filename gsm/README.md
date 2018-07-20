# GSM module: for any device supporting the command.

I'm use for testing A6 GSM.
A6 GSM  is introduced by the makers of ESP8266 , AI-THINKER.

The module is much cheaper than SIM900 & connections are quite simple.In this post we shall see how to connect with Arduino to make a call & send SMS.

A mobile adapter is enough to power up the A6 GSM module.The Vcc pin of GSM must be looped with PWR_KEY pin.This acts as a chip enable.You can leave this connected or remove after a moment.The module just requires a HIGH trigger at PWR_KEY pin while started.

A valid SIM is used at the back side of the module.The SIM slot provided is for a Micro SIM.If you ‘ve a Nano SIM you need to use a converter to fit the slot.

The RxD pin of A6 GSM is connected to Tx of Arduino

The TxD pin of A6 goes to Rx of Arduino.

GND pin of A6 to GND of Arduino.
