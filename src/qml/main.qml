import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.4

import "conf/"
import "library/"

Window {
    id: root
    title: Conf.appName
    visible: true
    width : 350
    height: 600

    StackView {
        id: stackView
        anchors.fill: parent
        initialItem: {
            Qt.resolvedUrl("qrc:/pages/showsessions.qml")
        }
    }
}
