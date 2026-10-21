# Care Signal

An emergency and daily-needs alert device for elderly people and people with special needs, built with Arduino and a GSM module.

## How it works

- Three buttons: Food, Bathroom, and Help. Each one sends an SMS to the caregiver.
- An IR sensor sends an urgent help request on touch.
- An LDR light sensor turns on a red LED in low light.
- A green LED confirms that a message was sent.

## Components

- Arduino board
- GSM module (SIM)
- 3 push buttons, IR sensor, LDR
- Red and green LEDs

## Setup

1. Open `CareSignal.ino` in Arduino IDE.
2. Set the caregiver's phone number in `recipientNumber`.
3. Adjust `lightThreshold` after checking the values on the Serial Monitor.
4. Upload to the board.

## Documentation

See `CARE_SIGNAL.docx` for the full explanation of the components and the code.

## Related project

Care Mate, the caregiver management system: <put the Care Mate repo link here>

## Team

Nora Alowaidh, Ibtesam Alqahtani, Rimas Aldosari, Ibtehaj Alqhtani, Aryam Hakami, Ola Yasir Omer
