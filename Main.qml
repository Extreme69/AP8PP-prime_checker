import QtQuick 2.15
import QtQuick.Controls 2.15

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Prime Number Checker")

    Column {
        spacing: 10
        anchors.centerIn: parent

        TextField {
            id: numberInput
            placeholderText: "Enter a number"
            width: parent.width
        }

        Button {
            text: "Start Checking"
            onClicked: {
                progressBar.value = 0
                errorText.text = ""
                primeChecker.startChecking(parseInt(numberInput.text))
                result.text = "Checking..."
                pauseButton.text = "Pause"
            }
        }

        Button {
            id: pauseButton
            text: "Pause"
            onClicked: {
                if (pauseButton.text === "Pause") {
                    primeChecker.pauseChecking()
                    pauseButton.text = "Resume"  // Change button text to "Resume" when paused
                } else {
                    primeChecker.startChecking(parseInt(numberInput.text))  // Continue from the last paused state
                    pauseButton.text = "Pause"  // Change back to "Pause" when resumed
                }
            }
        }

        Button {
            text: "Stop"
            onClicked: {
                primeChecker.stopChecking()
                pauseButton.text = "Pause"  // Reset button to "Pause" when stopped
            }
        }

        ProgressBar {
            id: progressBar
            width: parent.width
            value: progressBar.value
            from: 0
            to: 100
            visible: true
        }

        Text {
            id: result
            text: "Result."
            font.pixelSize: 20
            width: parent.width
            wrapMode: Text.Wrap
        }

        Text {
            id: errorText
            text: ""
            font.pixelSize: 18
            width: parent.width
            color: "red"
        }

        Connections {
            target: primeChecker

            function onProgressUpdated(progress) {
                progressBar.value = progress;
            }

            function onResultReady(isPrime) {
                result.text = isPrime ? "Prime!" : "Not prime";
            }

            function onErrorMessage(message) {
                errorText.text = message;  // Zobraziť chybovú správu
            }
        }
    }
}
