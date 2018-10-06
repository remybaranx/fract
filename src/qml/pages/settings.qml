import QtQuick 2.9
import QtQuick.Controls 2.3
import QtQuick.Window 2.2
import QtQuick.Layouts 1.11

import "../library/"
import "../conf/"

Item {
    id: root

    FractCircleButton {
        radius : 10
        text   : "+"
        font.pointSize: 10
        bgColor: Style.bgColor
        textColor: Style.textColor
        borderWidth: 1
        borderColor: Style.lineColor
    }
}
