import QtQuick 2.9
import QtQuick.Controls 2.3
import QtQuick.Window 2.2
import QtQuick.Layouts 1.11

import "../library/"
import "../conf/"

Item {
    id: root

    FractToolbar {
        id: toolbar
        pageText: qsTr("New session")
    }

    Rectangle {
        anchors.left: root.left
        anchors.right: root.right
        anchors.top: toolbar.bottom
        anchors.bottom: root.bottom

        color: Style.bgColor

        ColumnLayout {
            id: intro
            spacing: 5
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.margins: 10

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
        }

        SessionEditor {
            id: sessionEditor
            anchors.top: intro.bottom
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.margins: 10
        }

        RowLayout {
            spacing: 0
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            anchors.leftMargin: 10
            anchors.rightMargin: 10

            FractButton {
                id: cancelButton
                Layout.preferredWidth: 120
                text: "Cancel"
                onClicked: stackView.pop()
                Layout.margins: 10
            }

            Item {
                Layout.fillWidth: true
            }

            FractButton {
                id: saveButton
                Layout.preferredWidth: 120
                text: "Save"
                Layout.margins: 10
            }
        }
    }
}
