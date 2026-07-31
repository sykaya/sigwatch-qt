<!-- ============================================================
     BADGES
     ============================================================ -->
<div align="center">

# 📡 SigWatch - Audio Frequency Listener

[![GitHub license](https://img.shields.io/github/license/sykaya/sigwatch-qt)](https://github.com/sykaya/sigwatch-qt/blob/main/LICENSE)
[![GitHub stars](https://img.shields.io/github/stars/sykaya/sigwatch-qt)](https://github.com/sykaya/sigwatch-qt/stargazers)
[![GitHub forks](https://img.shields.io/github/forks/sykaya/sigwatch-qt)](https://github.com/sykaya/sigwatch-qt/network/members)
[![GitHub issues](https://img.shields.io/github/issues/sykaya/sigwatch-qt)](https://github.com/sykaya/sigwatch-qt/issues)
[![GitHub last commit](https://img.shields.io/github/last-commit/sykaya/sigwatch-qt)](https://github.com/sykaya/sigwatch-qt/commits/main)
[![GitHub repo size](https://img.shields.io/github/repo-size/sykaya/sigwatch-qt)](https://github.com/sykaya/sigwatch-qt)
[![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20Linux%20%7C%20macOS-blue)](https://github.com/sykaya/sigwatch-qt)
[![C++](https://img.shields.io/badge/C++-17-blue?logo=cplusplus)](https://isocpp.org/)
[![Qt](https://img.shields.io/badge/Qt-6.10-blue?logo=qt)](https://www.qt.io/)
[![CMake](https://img.shields.io/badge/CMake-3.16+-blue?logo=cmake)](https://cmake.org/)

**Real-time audio frequency spectrum listener and visualizer.**

</div>

---

## 📌 About

**SigWatch** is a lightweight desktop application that captures live audio from your microphone and displays its frequency spectrum in real-time. Built with **C++17** and **Qt6**.

It provides a simple and intuitive interface for:
- Live audio capture from any input device
- FFT-based frequency analysis
- Real-time spectrum visualization
- Peak detection and tracking

---

## ✨ Features

| Feature | Description |
|---------|-------------|
| 🎤 **Live Audio Capture** | Capture audio from microphone or line-in in real-time |
| 📊 **FFT Analysis** | Fast Fourier Transform for frequency domain analysis |
| 🟢 **Spectrum Visualization** | Real-time spectrum display with QtCharts |
| 🔵 **Peak Detection** | Automatic detection of peak frequency and amplitude |
| 🎚️ **Device Selection** | Choose from available input devices |
| 🎨 **Modern UI** | Clean, professional interface with light theme |

---

## 📷 Screenshots

### Main Window
![Main Window](screenshots/main.png)

*Coming soon.*

### Spectrum View
![Spectrum View](screenshots/spectrum.png)

*Coming soon.*

---

## 🛠️ Tech Stack

| Component | Technology |
|-----------|------------|
| **Language** | C++17 |
| **Framework** | Qt6 (Widgets, Multimedia, Charts) |
| **Signal Processing** | Custom FFT implementation |
| **Visualization** | QtCharts |
| **Build System** | CMake 3.16+ |
| **Audio Capture** | Qt Multimedia (QAudioSource) |

---

## 🚀 Getting Started

### Prerequisites

| Requirement | Version |
|-------------|---------|
| **Qt** | 6.4 or later |
| **CMake** | 3.16 or later |
| **C++ Compiler** | C++17 compatible (GCC, Clang, MSVC) |
| **OS** | Windows 10/11, Ubuntu 20.04+, macOS 12+ |

### Build Instructions

#### 1. Clone the repository

```bash
git clone https://github.com/sykaya/sigwatch-qt.git
cd sigwatch-qt
