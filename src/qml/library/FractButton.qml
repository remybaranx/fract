import QtQuick 2.9
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.11

import "../conf"

Button {
    id: root
	font: Style.controlFont

    background: Rectangle {
        color: Style.controlBgColor
    }

    contentItem: Text {
        text: parent.text
        color: Style.controlTextColor
        font: root.font
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
    }
}
