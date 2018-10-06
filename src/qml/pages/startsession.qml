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
        pageText: "start"
    }

    Rectangle {
        anchors.left: root.left
        anchors.right: root.right
        anchors.top: toolbar.bottom
        anchors.bottom: root.bottom

        color: Style.bgColor

        ColumnLayout {
            anchors.fill: parent
            anchors.topMargin: 20

            FractLabel {
                text: "SESSION_NAME"
                font.pointSize: 16
                horizontalAlignment: Text.AlignHCenter
                Layout.fillWidth: true
            }

            FractLabel {
                text: "[SESSION_DESCRIPTION]"
                font.pointSize: 12
                horizontalAlignment: Text.AlignHCenter
                Layout.fillWidth: true
            }

            ActivityViewer {
                Layout.fillHeight: true
                Layout.fillWidth: true
                Layout.margins: 10
            }

            RowLayout {
                Layout.fillWidth: true

                FractCircleButton {
                    radius: 48
                    text: "G"
                    bgColor   : Style.buttonBgColor
                    textColor : Style.controlTextColor
                    font      : Style.controlFont
                }

                FractCircleButton {
                    radius: 48
                    text: "S"
                    bgColor   : Style.buttonBgColor
                    textColor : Style.controlTextColor
                    font      : Style.controlFont
                }
            }
        }
    }
}
