#ifndef PRIMECHECKER_H
#define PRIMECHECKER_H

#include <QObject>
#include <QTimer>

class PrimeChecker : public QObject
{
    Q_OBJECT
public:
    explicit PrimeChecker(QObject *parent = nullptr);
    Q_INVOKABLE void startChecking(qint64 number);
    Q_INVOKABLE void stopChecking();
    Q_INVOKABLE void pauseChecking();
    Q_INVOKABLE double getProgress() const;

    static const qint64 MAX_NUMBER = 10000000000000;

signals:
    void progressUpdated(double progress);
    void resultReady(bool isPrime);
    void errorMessage(QString message);

private slots:
    void processNextStep();

private:
    bool isPrime(qint64 number);
    qint64 currentNumber;
    qint64 divisor;
    bool running;
    QTimer idleTimer;
};

#endif // PRIMECHECKER_H
