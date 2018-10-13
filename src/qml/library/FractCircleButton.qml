import QtQuick 2.9
import QtQuick.Controls 2.3

import "../conf/"

RoundButton {
    id: root

    property color bgColor: Style.buttonBgColor
    property color textColor: Style.controlTextColor
    property int   borderWidth: 0
    property color borderColor

    font: Style.controlFont

    width  : root.radius * 2
    height : root.radius * 2

    contentItem: Text {
        text  : root.text
        color : textColor
        font  : root.font
        horizontalAlignment : Text.AlignHCenter
        verticalAlignment   : Text.AlignVCenter
    }

    background: Rectangle {
        color  : root.bgColor
        radius : root.radius
        width  : root.width
        height : root.height
        border.width: borderWidth
        border.color: borderColor
    }
}
