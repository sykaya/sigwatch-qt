<div align="center">

# 📡 SigWatch
### Real-Time Frequency Spectrum Listener

[![C++](https://img.shields.io/badge/Standard-C%2B%2B17-blue?logo=cplusplus)](https://isocpp.org/)
[![Qt](https://img.shields.io/badge/Framework-Qt_6.10-green?logo=qt)](https://www.qt.io/)
[![Build](https://img.shields.io/badge/Build-CMake_3.16+-blue?logo=cmake)](https://cmake.org/)
[![Platform](https://img.shields.io/badge/Platform-Windows_10%20%7C%2011-lightgrey)](https://github.com/sykaya/sigwatch-qt)
[![License](https://img.shields.io/badge/License-MIT-yellow)](LICENSE)
[![Status](https://img.shields.io/badge/Status-Stable-brightgreen)](https://github.com/sykaya/sigwatch-qt)

</div>

---

## 📌 Overview

**SigWatch** is a lightweight, real-time audio frequency spectrum analyzer built with C++17 and Qt6. Designed for signal analysis, audio engineering, and educational purposes.

| | |
|---|---|
| **Language** | C++17 |
| **Framework** | Qt 6.10 |
| **Build System** | CMake 3.16+ |
| **Platform** | Windows 10 / 11, Linux, macOS |
| **License** | MIT |
| **Status** | Stable |

---

## 🖥️ Screenshots

### Main Interface

![Main Window](Screenshot/image1.jpg)

### Spectrum Analysis

![Spectrum View](Screenshot/image2.png)

---

## 🚀 Features

| Feature | Description |
|---------|-------------|
| **Live Capture** | Real-time audio input from microphone or line-in |
| **FFT Analysis** | Fast Fourier Transform for frequency domain processing |
| **Spectrum Display** | Real-time visualization with QtCharts |
| **Peak Detection** | Automatic frequency and amplitude peak tracking |
| **Device Selection** | Multiple audio input device support |
| **Lightweight** | Minimal resource usage, fast performance |

---

## 📡 Future Expansion

> **RTL-SDR Support**  
> Future versions will support RTL-SDR and other SDR platforms for radio frequency (RF) signal analysis. This will enable spectrum monitoring of FM radio, amateur radio, air traffic, and other RF communications.

---

## 📦 Installation

### Prerequisites

- Qt 6.4 or higher
- CMake 3.16 or higher
- C++17 compatible compiler

### Build from Source

```bash
git clone https://github.com/sykaya/sigwatch-qt.git
cd sigwatch-qt
mkdir build && cd build
cmake ..
make
./sigwatch-qt
