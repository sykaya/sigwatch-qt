#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAudioSource>
#include <QAudioDevice>
#include <QMediaDevices>
#include <QAudioFormat>
#include <QIODevice>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QChart>
#include <QVector>
#include <QLabel>
#include <QTimer>
#include <QComboBox>


#define BUFFER_SIZE 1024

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE



    class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void startRecording();
    void stopRecording();
    void processAudio();
    void updateSpectrum();
    void onDeviceChanged(int index);

private:
    void computeFFT(const QVector<double> &samples, QVector<double> &magnitude);
    void loadAudioDevices();
    void updateStatusBar(const QString &message);

    Ui::MainWindow *ui;

    // audio
    QAudioSource *m_audioSource = nullptr;
    QIODevice *m_audioDevice = nullptr;
    QAudioFormat m_format;
    bool m_isRecording = false;
    int m_selectedDeviceIndex = 0;

    QChartView *m_chartView = nullptr;
    QLineSeries *m_series = nullptr;
    QChart *m_chart = nullptr;

    // ui stuff etc
    QLabel *m_statusLabel = nullptr;
    QLabel *m_dataLabel = nullptr;
    QComboBox *m_deviceCombo = nullptr;

    // buffer and Timer
    QVector<double> m_audioBuffer;
    QTimer *m_updateTimer = nullptr;
    QVector<QAudioDevice> m_devices;
};

#endif // MAINWINDOW_H
