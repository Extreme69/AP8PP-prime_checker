/**
 * @file PrimeChecker.h
 * @brief Header file for the PrimeChecker class.
 */

#ifndef PRIMECHECKER_H
#define PRIMECHECKER_H

#include <QObject>
#include <QTimer>

/**
 * @class PrimeChecker
 * @brief A class that checks whether a given number is prime.
 *
 * This class uses an asynchronous approach to check the primality of a number
 * by iterating over possible divisors and updating the progress.
 */
class PrimeChecker : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief Constructor for PrimeChecker.
     * @param parent The parent QObject.
     */
    explicit PrimeChecker(QObject *parent = nullptr);

    /**
     * @brief Starts checking if a given number is prime.
     * @param number The number to check.
     */
    Q_INVOKABLE void startChecking(qint64 number);

    /**
     * @brief Resumes checking from where it was paused.
     */
    Q_INVOKABLE void resumeChecking();

    /**
     * @brief Stops the checking process completely.
     */
    Q_INVOKABLE void stopChecking();

    /**
     * @brief Pauses the checking process.
     */
    Q_INVOKABLE void pauseChecking();

    /**
     * @brief Gets the progress percentage of the checking process.
     * @return The progress as a percentage.
     */
    Q_INVOKABLE double getProgress() const;

    /**
     * @brief The maximum number that can be checked.
     */
    static const qint64 MAX_NUMBER = 10000000000000000;

    /**
     * @brief Number of divisor iterations per timer cycle.
     */
    static const qint64 stepsPerCycle = 100;

signals:
    /**
     * @brief Emitted when the progress of the checking process is updated.
     * @param progress The current progress percentage.
     */
    void progressUpdated(double progress);

    /**
     * @brief Emitted when the checking process is complete.
     * @param isPrime True if the number is prime, false otherwise.
     */
    void resultReady(bool isPrime);

    /**
     * @brief Emitted when an error occurs.
     * @param message The error message.
     */
    void errorMessage(QString message);

private slots:
    /**
     * @brief Processes the next set of steps in checking for primality.
     */
    void processNextStep();

private:
    /**
     * @brief Checks if a number is prime.
     * @param number The number to check.
     * @return True if the number is prime, false otherwise.
     */
    bool isPrime(qint64 number);

    qint64 currentNumber; ///< The number being checked.
    qint64 divisor; ///< The current divisor being tested.
    bool running; ///< Whether the checking process is running.
    QTimer idleTimer; ///< Timer to control the checking process.
};

#endif // PRIMECHECKER_H
