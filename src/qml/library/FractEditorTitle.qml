import QtQuick 2.9
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.3

import "../conf/"

Label {
    id: title

    font.pointSize: Style.controlFont.pointSize
    font.family: Style.controlFont.family
    font.bold: true

    color: Style.controlBgColor

    verticalAlignment: Text.AlignVCenter
    horizontalAlignment: Text.AlignLeft

    Layout.fillWidth: true

    topPadding: 5
    bottomPadding: 5

    Rectangle {
        color: parent.color
        height: 1
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
    }
}
