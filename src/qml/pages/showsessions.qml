import QtQuick 2.9
import QtQuick.Controls 2.3
import QtQuick.Window 2.2
import QtQuick.Layouts 1.11

import "../library/"
import "../conf/"

import com.fract.model 1.0

Item {
    id: root

    FractToolbar {
        id: toolbar
        pageText: qsTr("Sessions")
    }

    Rectangle {
        color: Style.bgColor

        anchors.left: root.left
        anchors.right: root.right
        anchors.top: toolbar.bottom
        anchors.bottom: root.bottom

        ListView {
            id: sessionsListView
            anchors.fill: parent
            clip: true

//            model: sessionModel

            model : ListModel {
                ListElement {
                    name: "30/30"
                    description: "Le classique du fractionné"
                }
                ListElement {
                    name: "30/30"
                    description: "Le classique du fractionné"
                }
                ListElement {
                    name: "30/30"
                    description: "Le classique du fractionné"
                }
                ListElement {
                    name: "30/30"
                    description: "Le classique du fractionné"
                }
                ListElement {
                    name: "30/30"
                    description: "Le classique du fractionné"
                }
                ListElement {
                    name: "30/30"
                    description: "Le classique du fractionné"
                }
                ListElement {
                    name: "30/30"
                    description: "Le classique du fractionné"
                }
                ListElement {
                    name: "30/30"
                    description: "Le classique du fractionné"
                }
                ListElement {
                    name: "30/30"
                    description: "Le classique du fractionné"
                }
                ListElement {
                    name: "30/30"
                    description: "Le classique du fractionné"
                }
                ListElement {
                    name: "30/30"
                    description: "Le classique du fractionné"
                }
                ListElement {
                    name: "30/30"
                    description: "Le classique du fractionné"
                }
                ListElement {
                    name: "30/30"
                    description: "Le classique du fractionné"
                }
                ListElement {
                    name: "30/30"
                    description: "Le classique du fractionné"
                }
            }

            delegate: Rectangle {
                width: parent.width
                color: "transparent"
                height: 60

                Rectangle {
                   anchors.fill: parent
                   anchors.topMargin: 5
                   anchors.bottomMargin: 5
                   anchors.leftMargin: 10
                   anchors.rightMargin: 10
                   color: parent.color

                   ColumnLayout {
                       Text {
//                            text: modelData.name
                            text: name
                            font.pointSize: 16
                            color: Style.textColor
                        }
                        Text {
                            text: description
//                            text: modelData.description
                            font.pointSize: 12
                            color: Style.textColor
                        }
                   }
                }

                // use a rectangle to draw a line between element
                Separator {
                    anchors.left: parent.left
                    anchors.right: parent.right
                    anchors.bottom: parent.bottom
                    anchors.leftMargin: 15
                    anchors.rightMargin: 15

                    color: Style.lineColor
                }

                ExtendedMouseArea {
                    onShortClicked: stackView.push(Qt.resolvedUrl("startsession.qml"),  {session: name})
                    onLongClicked: stackView.push(Qt.resolvedUrl("editsession.qml"),  {session: name})
                }
            }
        }

        FractCircleButton {
            id: addButton
            anchors.bottom: parent.bottom
            anchors.right: parent.right
            anchors.margins: 20
            radius: 24
            bgColor: Style.buttonBgColor
            textColor: Style.controlTextColor
            font.pointSize: 14
            text: "+"
//            text: "\u9658" // play
//            text: "\u9208" // pause
//            text: "\u9609" // stop
            onClicked: stackView.push(Qt.resolvedUrl("editsession.qml"))
        }
    }
}
