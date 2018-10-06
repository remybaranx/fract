import QtQuick 2.9
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.11

import "../conf"

Label {
    id: root

    font: Style.controlFont
    color: Style.textColor

    verticalAlignment: Text.AlignVCenter
    horizontalAlignment: Text.AlignLeft

    background: Rectangle {
        color: "transparent"
    }
}
