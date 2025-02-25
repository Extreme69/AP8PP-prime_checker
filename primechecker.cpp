#include "PrimeChecker.h"
#include <QCoreApplication>
#include <cmath>

PrimeChecker::PrimeChecker(QObject *parent) : QObject(parent), running(false), currentNumber(0), divisor(0) {
    connect(&idleTimer, &QTimer::timeout, this, &PrimeChecker::processNextStep);
    idleTimer.setInterval(0);
}

void PrimeChecker::startChecking(qint64 number) {
    if (running) return;

    if (number > MAX_NUMBER) {
        emit errorMessage("Number is too large. Please enter a smaller number.");
        return;
    }

    // Ak je číslo platné, nastavíme ho a začneme počítať
    currentNumber = number;
    divisor = 2;
    running = true;
    idleTimer.start();
}


void PrimeChecker::stopChecking() {
    running = false;
    idleTimer.stop();
    emit progressUpdated(100);
}

void PrimeChecker::pauseChecking() {
    running = false;
    idleTimer.stop();
    emit progressUpdated(getProgress());
}

double PrimeChecker::getProgress() const {
    return (divisor / static_cast<double>(sqrt(currentNumber))) * 100.0;
}

void PrimeChecker::processNextStep() {
    if (!running) return;

    // If we found a prime number
    if (divisor * divisor > currentNumber) {
        emit resultReady(true);
        stopChecking();
        return;
    }

    // If we find a divider, the number is not a prime number
    if (currentNumber % divisor == 0) {
        emit resultReady(false);
        stopChecking();
        return;
    }

    divisor++;
    emit progressUpdated(getProgress());
    QCoreApplication::processEvents();
}

bool PrimeChecker::isPrime(qint64 number) {
    if (number < 2) return false;
    for (qint64 i = 2; i * i <= number; ++i) {
        if (number % i == 0) return false;
    }
    return true;
}
