import QtQuick 2.9
import QtQuick.Controls 2.3
import QtQuick.Window 2.2
import QtQuick.Layouts 1.11

import "../conf/"
import "../library/"

ColumnLayout {
    id: root
    spacing: 5

    property alias text: title.text

    FractEditorTitle {
        id: title
    }

    RowLayout {
        spacing: 5

        FractLabel {
            text: {itemSwitch.checked ? qsTr("Disable") : qsTr("Enable"); }
            Layout.fillHeight: true
            Layout.minimumWidth: 90
        }
        FractSwitch {
            id: itemSwitch
            radius: 10
            Layout.fillWidth: true
            onCheckedChanged: {stepValueControl.visible = itemSwitch.checked;}
        }
    }

    FractStepValue {
        id: stepValueControl
    }
}
