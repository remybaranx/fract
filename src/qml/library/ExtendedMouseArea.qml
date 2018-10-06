import QtQuick 2.9

MouseArea {
    id: root
    anchors.fill: parent

    signal shortClicked()
    signal longClicked()

    onClicked: shortClicked()
    onPressAndHold: longClicked()
}
