# SignalWatcher - Audio Frequency Listener

**Real-time audio frequency spectrum visualizer.**

A lightweight desktop application that captures live audio from your microphone and displays its frequency spectrum in real-time. Built with C++ and Qt6.

## Features

- 🎤 Real-time audio capture from microphone/line-in
- 📊 FFT-based frequency spectrum analysis
- 🟢 Live spectrum visualization
- 🔵 Peak frequency and amplitude detection
- 🎚️ Input device selection (microphone/line-in)

## Tech Stack

- **Language:** C++17
- **Framework:** Qt6
- **Signal Processing:** Custom FFT implementation
- **Visualization:** QtCharts

## Getting Started

### Prerequisites

- Qt6 (6.4 or later)
- CMake (3.16 or later)
- C++17 compatible compiler

### Build Instructions

```bash
# Clone the repository
git clone https://github.com/yourusername/SignalWatcher.git
cd SignalWatcher

# Create build directory
mkdir build && cd build

# Configure and build
cmake ..
make

# Run
./SignalWatcher
