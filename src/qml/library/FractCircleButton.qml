import QtQuick 2.9
import QtQuick.Controls 2.3

RoundButton {
    id: root

    property color bgColor
    property color textColor
    property int   borderWidth: 0
    property color borderColor

    width  : root.radius * 2
    height : root.radius * 2

    contentItem: Text {
        text  : root.text
        color : textColor
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
