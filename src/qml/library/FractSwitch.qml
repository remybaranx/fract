import QtQuick 2.9
import QtQuick.Controls 2.3

import "../conf/"

SwitchDelegate {
    id: control
    checked: true

    topPadding: 5
    bottomPadding: 5
    leftPadding: 0
    rightPadding: 0

    property real radius

    indicator: Rectangle {
        implicitWidth: control.radius * 4
        implicitHeight: control.radius * 2
        x: control.width - width - control.rightPadding
        y: parent.height / 2 - height / 2
        radius: control.radius
        color: Style.bgColor
        border.color: Style.textColor

        Rectangle {
            x: control.checked ? parent.width - width : 0
            width  : control.radius * 2
            height : control.radius * 2
            radius : control.radius
            color: Style.lineColor
            border.color: Style.textColor
        }
    }

    background: Rectangle {
        visible: control.down || control.highlighted
        color: Style.bgColor
    }
}
