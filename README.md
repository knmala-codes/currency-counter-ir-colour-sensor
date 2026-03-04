# Currency Counter using IR and Colour Sensor

Sensor‑based currency counter using an IR sensor and a colour sensor with an Arduino and 16x2 LCD. Notes are detected as they pass, their denomination is identified from colour patterns, and the running total is shown on the display.

---

## Overview

Manual counting is slow and error‑prone. This project builds a small, low‑cost prototype that:

- Uses an **IR sensor** to detect each incoming note.
- Uses a **colour sensor** (TCS3200/TCS34725) to measure RGB values.
- Classifies the note as ₹10/₹20/₹50/₹100/₹200/₹500 based on calibrated RGB ranges.
- Updates a **16x2 LCD** with the detected denomination and total value.

In testing under stable lighting, it achieved about **98% detection accuracy** and about **95% denomination accuracy** after calibration.

---

## Hardware

Main components:

- Arduino Uno (or compatible)
- IR sensor (presence detection)
- Colour sensor: TCS3200 or TCS34725
- 16x2 LCD (I2C or parallel)
- 5 V supply (USB / adapter)
- Breadboard + jumper wires

All modules share a common GND. The IR sensor is placed along the note path; the colour sensor is placed close to the note surface.

---

## How it works

1. **Detection** – The IR sensor output changes when a note passes; Arduino treats this as a trigger.  
2. **Colour read** – Arduino reads RGB from the colour sensor via frequency (TCS3200) or I2C (TCS34725).  
3. **Classification** – RGB values are compared to predefined ranges for each denomination.  
4. **Display** – The LCD briefly shows e.g. `"50 Rupees!!!"` and then the updated `"Total Bal"` with the running sum.

The Arduino sketch (`src/currency_counter.ino`) includes helper functions `red()`, `green()`, and `blue()` that select the appropriate colour filter and measure output frequency using `pulseIn`. These values are used in `if` conditions to check which denomination range the note belongs to.

---

## Running the project

1. Build the circuit as in your report (IR at note slot; colour sensor close to the note; LCD wired to Arduino).  
2. Open `src/currency_counter.ino` in Arduino IDE, select Arduino Uno, upload.  
3. Open Serial Monitor to see RGB readings if you want to recalibrate.  
4. Pass notes one by one through the sensor region and confirm the LCD shows correct denomination and total.

If misclassifications occur, adjust the RGB threshold ranges for each note type based on real readings.

---

## Results and limitations

- Works reliably at moderate speeds with reasonably clean notes.  
- Strongly affected by lighting; big changes in ambient light can shift RGB values and cause mis‑identification.  
- Designed as a learning prototype, not a commercial‑grade machine.

Potential improvements: better mechanical feeding, shielding from light, extra sensors (UV/magnetic), or ML‑based classification instead of hardcoded ranges.

