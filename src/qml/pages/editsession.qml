import QtQuick          2.9
import QtQuick.Controls 2.4
import QtQuick.Window   2.2
import QtQuick.Layouts  1.11

import "../library/"
import "../conf/"

/**
 * A view to edit or create a session
 */
Item {
    id: root

    property int sessionIndex: -1

    FractToolbar {
        id: toolbar
        pageText: qsTr("New session")
    }

    /* a rectangle to fill the view with the background color */
    Rectangle {
        id: backgroundControl
        anchors.top: toolbar.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        color: Style.bgColor
    }

    /* a Flickable to be able to scroll on all components */
    Flickable {
        flickableDirection: Flickable.VerticalFlick

        anchors.fill: backgroundControl

        contentWidth: backgroundControl.width
        contentHeight: contentItem.childrenRect.height
        clip: true

        ColumnLayout {
            spacing: 5

            // general info editor
            InfoEditor {
                id: infoEditor
            }

            // warm up editor
            FractPrePostSessionEditor {
                id: warmUp
                text: "Warm up"
            }

            // cool down editor
            FractPrePostSessionEditor {
                id: coolDown
                text: "Cool down"
            }

            // steps editor
            SessionEditor {
                id: sessionEditor
            }

            // commands
            RowLayout {
                spacing: 0

                FractButton {
                    id: cancelButton
                    text: "Cancel"
                    Layout.preferredWidth: 80
                    Layout.margins: 10

                    onClicked: stackView.pop()
                }
/*
                Item {
                    Layout.fillWidth: true
                }
*/
                FractButton {
                    id: removeButton
                    text: "Remove"
                    Layout.preferredWidth: 80
                    Layout.margins: 10

                    onClicked: {
                        if (sessionIndex >= 0) {
                            appData.removeSession(sessionIndex)
                        }
                        stackView.pop()
                    }
                }

                FractButton {
                    id: saveButton
                    text: "Save"
                    Layout.preferredWidth: 80
                    Layout.margins: 10

                    onClicked: {
                        var currentSession

                        if (sessionIndex >= 0) {
                            currentSession = appData.sessions[sessionIndex]
                        }
                        else {
                            currentSession = appData.createSession()
                        }

                        currentSession.name        = infoEditor.sessionName
                        currentSession.description = infoEditor.sessionDescription
                        currentSession.hasWarmUp   = warmUp.enabled
                        currentSession.hasCoolDown = coolDown.enabled

                        if (warmUp.enabled) {
                            currentSession.warmUp.unit  = warmUp.stepUnit
                            currentSession.warmUp.value = warmUp.stepValue
                            currentSession.warmUp.info  = warmUp.stepInfo
                        }

                        if (coolDown.enabled) {
                            currentSession.coolDown.unit  = coolDown.stepUnit
                            currentSession.coolDown.value = coolDown.stepValue
                            currentSession.coolDown.info  = coolDown.stepInfo
                        }

                        // TODO: steps

                        if (sessionIndex < 0) {
                            appData.addSession(currentSession)
                        }

                        appData.saveSessions()

                        stackView.pop()
                    }
                }
            }
        }
    }

    Component.onCompleted: {
        if (sessionIndex >= 0) {
            var currentSession = appData.sessions[sessionIndex]

            // set general info
            toolbar.title                 = "Edit " + currentSession.name
            infoEditor.sessionName        = currentSession.name
            infoEditor.sessionDescription = currentSession.description

            // set warm up
            warmUp.enabled = currentSession.hasWarmUp

            if (currentSession.hasWarmUp) {
                warmUp.stepUnit  = currentSession.warmUp.unit
                warmUp.stepInfo  = currentSession.warmUp.info
                warmUp.stepValue = currentSession.warmUp.value
            }

            // set cool down
            coolDown.enabled = currentSession.hasCoolDown

            if (currentSession.hasCoolDown) {
                coolDown.stepUnit  = currentSession.coolDown.unit
                coolDown.stepInfo  = currentSession.coolDown.info
                coolDown.stepValue = currentSession.coolDown.value
            }

            // set steps
            sessionEditor.model = currentSession.steps
        }
    }
}
