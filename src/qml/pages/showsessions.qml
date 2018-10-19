import QtQuick 2.9
import QtQuick.Controls 2.4
import QtQuick.Window 2.2
import QtQuick.Layouts 1.11

import "../library/"
import "../conf/"

/**
 * This view displays all the sessions already existing in the sessions file
 */
Item {
    id: root

    FractToolbar {
        id: toolbar
        pageText: qsTr("Sessions")
    }

    /* to fill the whole view with the background color */
    Rectangle {
        color: Style.bgColor

        anchors.left: root.left
        anchors.right: root.right
        anchors.top: toolbar.bottom
        anchors.bottom: root.bottom

        /* the list view to display all the sessions */
        ListView {
            id: sessionsListView
            anchors.fill: parent
            snapMode: ListView.SnapToItem
            clip: true

            /* model imported from C++ declaration */
            model: appData.sessions

            /* delegate to display each session */
            delegate: Rectangle {
                width: parent.width
                color: "transparent"
                height: 80

               ColumnLayout {
				   id: sessionItem
                   anchors.fill: parent
                   anchors.topMargin: 5
                   anchors.bottomMargin: 5
                   anchors.leftMargin: 10
                   anchors.rightMargin: 10

                   Text {
                        text: modelData.name
                        font.pointSize: 18
                        color: Style.textColor
                    }
                    Text {
                        text: modelData.description
                        font.pointSize: 14
                        color: Style.textColor
                    }
               }

                // use a rectangle to draw a line between element
                Separator {
                    anchors.left: parent.left
                    anchors.right: parent.right
                    anchors.bottom: parent.bottom
                    anchors.leftMargin: 10
                    anchors.rightMargin: 10

                    color: Style.lineColor
                }

                /* to add short and long clicks support to the delegate */
                ExtendedMouseArea {
                    onShortClicked : stackView.push(Qt.resolvedUrl("startsession.qml"), {"sessionIndex": index})
                    onLongClicked  : stackView.push(Qt.resolvedUrl("editsession.qml"),  {"sessionIndex": index})
                }
            }
        }

        /* a button to be able to add a new session */
        FractCircleButton {
            id: addButton
            anchors.bottom: parent.bottom
            anchors.right: parent.right
            anchors.margins: 30
            radius: 30
			font.pointSize: 32
			font.weight: Font.Thin
            text: "+"
            onClicked: stackView.push(Qt.resolvedUrl("editsession.qml"))
        }
    }
}
