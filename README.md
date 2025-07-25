Simple terminal reminder utility for Linux. Set a quick timer to remind yourself with a message via terminal output, desktop notification, or spoken alert.

---

## Features

- Set timers in seconds or minutes
- Display custom reminder messages
- Show desktop notifications via `notify-send`
- Speak the message aloud using `espeak`

---

## Installation

### Dependencies

- C++17 compiler (`g++`, `clang++`, etc.)
- Optional (for extra features):
  - `notify-send` (usually provided by `libnotify-bin`)
  - `espeak` (for voice reminders)

## Compile and Install

- make
- sudo make install

## Usage

remindme <duration> [message] [--notify] [--speak]

## Example

remindme 15m "Join the meeting" --notify --speak
