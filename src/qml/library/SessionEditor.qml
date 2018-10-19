import QtQuick 2.9
import QtQuick.Controls 2.3
import QtQuick.Window 2.2
import QtQuick.Layouts 1.11

import "../conf/"

ColumnLayout {
    id: root
    spacing: Style.spacing

    property alias model: stepsView.model

    FractEditorTitle {
        id: title
        text: qsTr("Steps")
    }
    Repeater {
        id: stepsView
        clip: true

        delegate: RowLayout {

            FractStepValue {
                stepUnit  : modelData.unit
                stepValue : modelData.value
                stepInfo  : modelData.info
            }

            FractButton {
                text: "-"
//                onClicked: stepsModel.remove(index)
            }
        }
    }

    FractButton {
        text: qsTr("add")
        Layout.fillWidth: true
        Layout.leftMargin: 30
        Layout.rightMargin: 30
/*
        onClicked: {
            stepsModel.append({
              value : 0,
              unit  : 'sec',
              info   : ""
            })
        }
*/
    }
}
