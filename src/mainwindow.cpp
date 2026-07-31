// ============================================================
//  AUTHOR:       sykaya
//  DATE:         2026-07-31
//  DESCRIPTION:
//  Real-time spectrum analysis and signal surveillance tool

//  KEY FEATURES:
//  • Live audio/signal capture from multiple input sources
//  • FFT-based frequency domain analysis
//  • Real-time spectrum visualization and monitoring
//  • Automatic signal detection and peak tracking
//  • Configurable frequency band surveillance
//
//  NOTE:
//  Current version supports audio input (microphone/line-in).
//  Future versions will support RTL-SDR and other SDR
//  platforms for radio signals and
//  RF signal intelligence (SIGINT) applications.
//
//  LAST MODIFIED: 2026-07-31
// ============================================================


#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <cmath>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_isRecording(false)
    , m_selectedDeviceIndex(0)
{
    ui->setupUi(this);

    // light style
    this->setStyleSheet(
        "QMainWindow { background-color: #f0f2f5; }"
        "QLabel { color: #2c3e50; font-family: 'Segoe UI'; }"
        "QLabel#statusLabel { "
        "   background-color: #ffffff; "
        "   color: #1a5276; "
        "   font-weight: bold; "
        "   padding: 4px 14px; "
        "   border: 1px solid #d5d8dc; "
        "   border-radius: 4px; "
        "}"
        "QLabel#freqLabel { "
        "   color: #1a5276; "
        "   font-weight: bold; "
        "   padding: 3px 10px; "
        "   background-color: #ebf5fb; "
        "   border: 1px solid #d6eaf8; "
        "   border-radius: 3px; "
        "}"
        "QLabel#dbLabel { "
        "   color: #922b21; "
        "   font-weight: bold; "
        "   padding: 3px 10px; "
        "   background-color: #fdedec; "
        "   border: 1px solid #fadbd8; "
        "   border-radius: 3px; "
        "}"
        "QLabel#dataLabel { "
        "   color: #5d6d7e; "
        "   font-size: 12px; "
        "   font-weight: 600; "
        "}"
        "QComboBox { "
        "   background-color: #ffffff; "
        "   color: #2c3e50; "
        "   border: 1px solid #d5d8dc; "
        "   border-radius: 4px; "
        "   padding: 5px 12px; "
        "   min-height: 30px; "
        "}"
        "QComboBox:hover { border-color: #d4af37; }"
        "QComboBox::drop-down { border: none; width: 20px; }"
        "QComboBox::down-arrow { "
        "   border-left: 5px solid transparent; "
        "   border-right: 5px solid transparent; "
        "   border-top: 5px solid #2c3e50; "
        "   margin-right: 6px; "
        "}"
        "QComboBox QAbstractItemView { "
        "   background-color: #ffffff; "
        "   color: #2c3e50; "
        "   border: 1px solid #d5d8dc; "
        "   selection-background-color: #d4af37; "
        "   selection-color: #ffffff; "
        "}"
        "QPushButton { "
        "   font-weight: bold; "
        "   padding: 8px 28px; "
        "   border: none; "
        "   border-radius: 4px; "
        "   min-height: 34px; "
        "   font-family: 'Segoe UI'; "
        "}"
        "QPushButton#startBtn { "
        "   background-color: #1a5276; "
        "   color: #ffffff; "
        "}"
        "QPushButton#startBtn:hover { background-color: #1f618d; }"
        "QPushButton#startBtn:disabled { "
        "   background-color: #d5d8dc; "
        "   color: #aab7b8; "
        "}"
        "QPushButton#stopBtn { "
        "   background-color: #922b21; "
        "   color: #ffffff; "
        "}"
        "QPushButton#stopBtn:hover { background-color: #a93226; }"
        "QPushButton#stopBtn:disabled { "
        "   background-color: #d5d8dc; "
        "   color: #aab7b8; "
        "}"
        "QChartView { "
        "   background-color: #ffffff; "
        "   border: 1px solid #e5e8eb; "
        "   border-radius: 6px; "
        "}"
        );

    // --------------------------
    // Graph settngs

    m_chart = new QChart();
    m_series = new QLineSeries();
    m_chart->addSeries(m_series);
    m_chart->createDefaultAxes();
    m_chart->setTitle("SPECTRUM ANALYZER");
    m_chart->setTitleBrush(QBrush(QColor(26, 44, 58)));
    m_chart->setBackgroundBrush(QBrush(QColor(255, 255, 255)));
    m_chart->setAnimationOptions(QChart::NoAnimation);

    auto axisX = m_chart->axes(Qt::Horizontal).first();
    axisX->setTitleText("Frequency (kHz)");
    axisX->setTitleBrush(QBrush(QColor(93, 109, 126)));
    axisX->setLabelsColor(QColor(93, 109, 126));
    axisX->setGridLineColor(QColor(229, 232, 235));

    auto axisY = m_chart->axes(Qt::Vertical).first();
    axisY->setTitleText("Amplitude (dB)");
    axisY->setTitleBrush(QBrush(QColor(93, 109, 126)));
    axisY->setLabelsColor(QColor(93, 109, 126));
    axisY->setGridLineColor(QColor(229, 232, 235));

    axisX->setRange(0.02, 20);
    axisY->setRange(-100, 0);

    QPen pen(QColor(26, 44, 58));
    pen.setWidth(2);
    m_series->setPen(pen);

    ui->chartView->setChart(m_chart);
    ui->chartView->setRenderHint(QPainter::Antialiasing);

    // Sound Format

    m_format.setSampleRate(44100);
    m_format.setChannelCount(1);
    m_format.setSampleFormat(QAudioFormat::Int16);


    // cihaz listesi

    loadAudioDevices();



    connect(ui->startBtn, &QPushButton::clicked, this, &MainWindow::startRecording);
    connect(ui->stopBtn, &QPushButton::clicked, this, &MainWindow::stopRecording);
    connect(ui->deviceCombo, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &MainWindow::onDeviceChanged);

    // TİMER
    m_updateTimer = new QTimer(this);
    connect(m_updateTimer, &QTimer::timeout, this, &MainWindow::updateSpectrum);
    m_updateTimer->start(50);


    ui->stopBtn->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadAudioDevices()
{
    m_devices = QMediaDevices::audioInputs().toVector();

    if (m_devices.isEmpty()) {
        ui->statusLabel->setText("NO DEVICE");
        return;
    }

    ui->deviceCombo->clear();
    for (const QAudioDevice &device : m_devices) {
        QString label = device.description();
        if (device.isDefault()) {
            label += " (DEFAULT)";
        }
        ui->deviceCombo->addItem(label);
    }

    for (int i = 0; i < m_devices.size(); ++i) {
        if (m_devices[i].isDefault()) {
            ui->deviceCombo->setCurrentIndex(i);
            m_selectedDeviceIndex = i;
            break;
        }
    }
}

void MainWindow::onDeviceChanged(int index)
{
    if (index < 0 || index >= m_devices.size()) return;
    m_selectedDeviceIndex = index;
    qDebug() << "Selected:" << m_devices[index].description();

    if (m_isRecording) {
        stopRecording();
        startRecording();
    }
}

void MainWindow::startRecording()
{
    if (m_isRecording) return;

    if (m_devices.isEmpty()) {
        ui->statusLabel->setText("NO DEVICE");
        return;
    }

    QAudioDevice info = m_devices[m_selectedDeviceIndex];
    if (info.isNull()) {
        ui->statusLabel->setText("INVALID");
        return;
    }

    qDebug() << "Using:" << info.description();
    ui->statusLabel->setText("ACQUIRING...");

    m_audioSource = new QAudioSource(info, m_format, this);
    if (!m_audioSource) {
        ui->statusLabel->setText("FAILED");
        return;
    }

    m_audioDevice = m_audioSource->start();

    if (!m_audioDevice) {
        ui->statusLabel->setText("FAILED");
        return;
    }

    connect(m_audioDevice, &QIODevice::readyRead, this, &MainWindow::processAudio);
    m_isRecording = true;

    ui->startBtn->setEnabled(false);
    ui->stopBtn->setEnabled(true);
    ui->statusLabel->setText("ACTIVE");
    qDebug() << "Recording started!";
}

void MainWindow::stopRecording()
{
    if (!m_isRecording || !m_audioSource) return;

    m_audioSource->stop();
    m_isRecording = false;

    ui->startBtn->setEnabled(true);
    ui->stopBtn->setEnabled(false);
    ui->statusLabel->setText("RELEASED");
    qDebug() << "Recording stopped!";
}

void MainWindow::processAudio()
{
    if (!m_audioDevice) return;

    QByteArray data = m_audioDevice->readAll();
    if (data.isEmpty()) return;

    int N = data.size() / sizeof(short);
    if (N == 0) return;

    short* raw = (short*)data.data();
    for (int i = 0; i < N; ++i) {
        m_audioBuffer.append(raw[i] / 32768.0);
    }

    if (m_audioBuffer.size() > BUFFER_SIZE * 2) {
        m_audioBuffer.remove(0, m_audioBuffer.size() - BUFFER_SIZE);
    }

    ui->dataLabel->setText(QString("DATA: %1 SAMPLES").arg(m_audioBuffer.size()));
}

void MainWindow::updateSpectrum()
{
    if (m_audioBuffer.size() < 512) return;

    int takeCount = qMin(m_audioBuffer.size(), BUFFER_SIZE);
    QVector<double> samples = m_audioBuffer.mid(m_audioBuffer.size() - takeCount, takeCount);

    QVector<double> magnitude;
    computeFFT(samples, magnitude);

    if (magnitude.isEmpty()) return;

    m_series->clear();
    for (int i = 0; i < magnitude.size(); ++i) {
        double freq = (i * 44100.0) / takeCount;
        m_series->append(freq / 1000.0, magnitude[i]);
    }

    // Peak bul
    double peak = -100;
    int peakIndex = 0;
    for (int i = 0; i < magnitude.size(); ++i) {
        if (magnitude[i] > peak) {
            peak = magnitude[i];
            peakIndex = i;
        }
    }
    double peakFreq = (peakIndex * 44100.0) / (takeCount * 1000.0);

    ui->freqLabel->setText(QString("PEAK: %1 kHz").arg(peakFreq, 0, 'f', 2));
    ui->dbLabel->setText(QString("PEAK: %1 dB").arg(peak, 0, 'f', 1));

    m_chart->axes(Qt::Horizontal).first()->setRange(0.02, 20);
    m_chart->axes(Qt::Vertical).first()->setRange(-100, 0);
}

void MainWindow::computeFFT(const QVector<double> &samples, QVector<double> &magnitude)
{
    int N = samples.size();
    if (N < 2) {
        magnitude.clear();
        return;
    }

    magnitude.resize(N / 2);
    for (int k = 0; k < N / 2; ++k) {
        double real = 0.0;
        double imag = 0.0;
        for (int n = 0; n < N; ++n) {
            double angle = 2.0 * M_PI * k * n / N;
            real += samples[n] * cos(angle);
            imag += samples[n] * sin(angle);
        }
        magnitude[k] = 20.0 * log10(sqrt(real*real + imag*imag) / N + 1e-10);
    }
}
