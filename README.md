<div align="center">

# SigWatch - Audio Frequency Listener

[![License](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE)
[![Stars](https://img.shields.io/github/stars/sykaya/sigwatch-qt)](https://github.com/sykaya/sigwatch-qt/stargazers)
[![Forks](https://img.shields.io/github/forks/sykaya/sigwatch-qt)](https://github.com/sykaya/sigwatch-qt/network)
[![Issues](https://img.shields.io/github/issues/sykaya/sigwatch-qt)](https://github.com/sykaya/sigwatch-qt/issues)
[![Last Commit](https://img.shields.io/github/last-commit/sykaya/sigwatch-qt)](https://github.com/sykaya/sigwatch-qt/commits/main)
[![Repo Size](https://img.shields.io/github/repo-size/sykaya/sigwatch-qt)](https://github.com/sykaya/sigwatch-qt)
[![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20Linux%20%7C%20macOS-blue)](https://github.com/sykaya/sigwatch-qt)
[![C++](https://img.shields.io/badge/C++-17-blue?logo=cplusplus)](https://isocpp.org/)
[![Qt](https://img.shields.io/badge/Qt-6.10-blue?logo=qt)](https://www.qt.io/)
[![CMake](https://img.shields.io/badge/CMake-3.16+-blue?logo=cmake)](https://cmake.org/)

**Real-time audio frequency spectrum listener and visualizer.**

</div>

---

## Screenshots

### Main Window - Active Spectrum Display

![Main Window](Screenshot/image1.jpg)

*Live spectrum visualization with peak detection.*

### Spectrum Analysis View

![Spectrum View](Screenshot/image2.jpg)

*FFT-based frequency spectrum analysis in real-time.*

---

## About

SigWatch is a lightweight desktop application that captures live audio from your microphone and displays its frequency spectrum in real-time. Built with C++17 and Qt6.

It provides a simple and intuitive interface for:

- Live audio capture from any input device
- FFT-based frequency analysis
- Real-time spectrum visualization
- Peak detection and tracking

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
| Audio Capture | Qt Multimedia (QAudioSource) |

---

## Getting Started

### Prerequisites

| Requirement | Version |
|-------------|---------|
| Qt | 6.4 or later |
| CMake | 3.16 or later |
| C++ Compiler | C++17 compatible (GCC, Clang, MSVC) |
| OS | Windows 10/11, Ubuntu 20.04+, macOS 12+ |

### Build Instructions

#### Clone the repository

```bash
git clone https://github.com/sykaya/sigwatch-qt.git
cd sigwatch-qt
