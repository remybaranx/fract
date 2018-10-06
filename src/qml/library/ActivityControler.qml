import QtQuick 2.9
import QtQuick.Controls 2.3

/**
 * activity controler
 */
Item {
    id: root

    signal startClicked()
    signal pauseClicked()
    signal stopClicked()

    Row {
        id: layout

        Button {
            id: startPauseButton
            text: "start"
            onClicked: {
                if (startPauseButton.state == "pause") {
                    startPauseButton.state = "";
                    startClicked();
                }
                else {
                    startPauseButton.state = "pause";
                    pauseClicked();
                }
            }

            states: [
                State {
                    name: "pause"
                    PropertyChanges {
                        target: startPauseButton
                        text: "pause"
                    }
                }
            ]
        }

        Button {
            id: stopButton
            text: stop
            onClicked: stopClicked()
        }
    }
}
