/**
 * @file PrimeChecker.cpp
 * @brief Implementation file for the PrimeChecker class.
 */

#include "PrimeChecker.h"
#include <QCoreApplication>
#include <cmath>

/**
 * @brief Constructs a PrimeChecker object.
 * @param parent The parent QObject.
 */
PrimeChecker::PrimeChecker(QObject *parent)
    : QObject(parent), running(false), currentNumber(0), divisor(0) {
    connect(&idleTimer, &QTimer::timeout, this, &PrimeChecker::processNextStep);
    idleTimer.setInterval(0);
}

/**
 * @brief Starts checking if the given number is prime.
 * @param number The number to check.
 */
void PrimeChecker::startChecking(qint64 number) {
    if (running) return;

    if (number > MAX_NUMBER) {
        emit errorMessage("Number is too large. Please enter a smaller number.");
        return;
    }

    // Only reset if starting fresh, not when resuming
    if (currentNumber != number) {
        currentNumber = number;
        divisor = 2;
    }

    running = true;
    idleTimer.start();
}

/**
 * @brief Resumes checking from where it was paused.
 */
void PrimeChecker::resumeChecking() {
    if (!running) {
        running = true;
        idleTimer.start();
    }
}

/**
 * @brief Stops the checking process completely.
 */
void PrimeChecker::stopChecking() {
    running = false;
    idleTimer.stop();
    emit progressUpdated(100);
}

/**
 * @brief Pauses the checking process.
 */
void PrimeChecker::pauseChecking() {
    running = false;
    idleTimer.stop();
    emit progressUpdated(getProgress());
}

/**
 * @brief Gets the progress percentage of the checking process.
 * @return The progress as a percentage.
 */
double PrimeChecker::getProgress() const {
    return (divisor / static_cast<double>(sqrt(currentNumber))) * 100.0;
}

/**
 * @brief Processes the next set of steps in checking for primality.
 */
void PrimeChecker::processNextStep() {
    if (!running) return;

    for (int i = 0; i < stepsPerCycle; ++i) {
        if (!running) return;

        if (divisor * divisor > currentNumber) {
            emit resultReady(true);
            stopChecking();
            return;
        }

        if (currentNumber % divisor == 0) {
            emit resultReady(false);
            stopChecking();
            return;
        }

        divisor++;
    }

    emit progressUpdated(getProgress());
    QCoreApplication::processEvents();
}

/**
 * @brief Checks if a given number is prime.
 * @param number The number to check.
 * @return True if the number is prime, false otherwise.
 */
bool PrimeChecker::isPrime(qint64 number) {
    if (number < 2) return false;
    for (qint64 i = 2; i * i <= number; ++i) {
        if (number % i == 0) return false;
    }
    return true;
}
