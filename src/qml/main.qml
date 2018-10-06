import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.3

import "conf/"
import "library/"

Window {
    id: root
    visible: true
    visibility: {Screen.width >= 800 ? Window.Windowed : Window.FullScreen; }
    width: 350
    height: 600
    title: Conf.appName

    StackView {
        id: stackView
        anchors.fill: parent
        initialItem: {
            Qt.resolvedUrl("qrc:/pages/showsessions.qml")
        }
    }
}
