import QtQuick 2.9
import QtQuick.Controls 2.4
import QtQuick.Window 2.2
import QtQuick.Layouts 1.11

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

            InfoEditor {
                id: infoEditor
            }

            FractPrePostSessionEditor {
                id: warmUp
                text: "Warm up"
            }

            FractPrePostSessionEditor {
                id: coolDown
                text: "Cool down"
            }

            SessionEditor {
                id: sessionEditor
            }

            RowLayout {
                spacing: 0

                FractButton {
                    id: cancelButton
                    text: "Cancel"
                    Layout.preferredWidth: 80
                    Layout.margins: 10

                    onClicked: stackView.pop()
                }

                Item {
                    Layout.fillWidth: true
                }

                FractButton {
                    id: saveButton
                    text: "Save"
                    Layout.preferredWidth: 80
                    Layout.margins: 10

                    onClicked: {
                        if (sessionIndex >= 0) {
                            sessionModel[sessionIndex]=session
                        }
                        else {
                            sessionModel.addSession(session)
                        }
                    }
                }
            }
        }
    }
}
