import QtQuick 2.9
import QtQuick.Controls 2.3
import QtQuick.Window 2.2
import QtQuick.Layouts 1.11

Item {
    id: root

    FractEditorTitle {
        id: title
        anchors.top: root.top
        anchors.left: root.left
        anchors.right: root.right

        text: qsTr("Steps")
    }

    ListView {
        id: stepsView
        height: 300
        anchors.top: title.bottom
        anchors.left: root.left
        anchors.right: root.right
        anchors.topMargin: 5
        spacing: 5
        clip: true

        model: ListModel {
            ListElement {
                kind   : "Group"
                series : 5
            }

            ListElement {
                kind  : "Simple"
                value : 100
                unit  : 'm'
                info   : "100% VMA"
            }

            ListElement {
                kind  : "Simple"
                value : 30
                unit  : 'sec'
                info   : "70% VMA"
            }
        }

        delegate: Component {
            Loader {
                source: Qt.resolvedUrl("qrc:/library/Fract" + kind + "Step.qml")
            }
        }
    }


}
