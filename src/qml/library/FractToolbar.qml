import QtQuick 2.9
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.3
import QtQuick.Controls.Material 2.1

import "../library/"
import "../conf/"

CustomToolbar {
    property string pageText

    id: root
    title: {
        if (pageText == "") {
            return Conf.appName
        }
        else {
            return Conf.appName + " - " + pageText
        }
    }

    color          : Style.toolbarBgColor
    textColor      : Style.toolbarTextColor
    font           : Style.toolbarFont

    buttonText: "≡"
    onButtonClicked: stackView.push(Qt.resolvedUrl("qrc:/pages/settings.qml"))
}
