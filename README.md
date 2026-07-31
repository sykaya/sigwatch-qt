# SigWatch - Audio Frequency Listener

[![C++](https://img.shields.io/badge/C++-17-blue?logo=cplusplus)](https://isocpp.org/)
[![Qt](https://img.shields.io/badge/Qt-6.10-green?logo=qt)](https://www.qt.io/)
[![CMake](https://img.shields.io/badge/CMake-3.16+-blue?logo=cmake)](https://cmake.org/)
[![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20Linux-lightgrey)](https://github.com/sykaya/sigwatch-qt)
[![License](https://img.shields.io/badge/License-MIT-yellow)](LICENSE)
[![GitHub](https://img.shields.io/badge/GitHub-sykaya%2Fsigwatch--qt-181717?logo=github)](https://github.com/sykaya/sigwatch-qt)

**Real-time audio frequency spectrum listener and visualizer.**

---

## Screenshots

### Main Window

![Main Window](Screenshot/image1.jpg)

### Spectrum View

![Spectrum View](Screenshot/image2.png)

---

## About

SigWatch is a lightweight desktop application that captures live audio from your microphone and displays its frequency spectrum in real-time. Built with C++17 and Qt6.

---

## Features

| Feature | Description |
|---------|-------------|
| Live Audio Capture | Capture audio from microphone or line-in in real-time |
| FFT Analysis | Fast Fourier Transform for frequency domain analysis |
| Spectrum Visualization | Real-time spectrum display with QtCharts |
| Peak Detection | Automatic detection of peak frequency and amplitude |
| Device Selection | Choose from available input devices |
| Modern UI | Clean, professional interface with light theme |

---

## Tech Stack

| Component | Technology |
|-----------|------------|
| Language | C++17 |
| Framework | Qt6 (Widgets, Multimedia, Charts) |
| Signal Processing | Custom FFT implementation |
| Visualization | QtCharts |
| Build System | CMake 3.16+ |
| Audio Capture | Qt Multimedia |

---

## Getting Started

### Prerequisites

- Qt 6.4 or later
- CMake 3.16 or later
- C++17 compatible compiler

### Build

```bash
git clone https://github.com/sykaya/sigwatch-qt.git
cd sigwatch-qt
mkdir build && cd build
cmake ..
make
./sigwatch-qt
