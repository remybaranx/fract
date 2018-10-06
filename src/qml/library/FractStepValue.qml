import QtQuick 2.9
import QtQuick.Controls 2.3
import QtQuick.Window 2.2
import QtQuick.Layouts 1.11

import "../conf/"
import "../library/"

RowLayout {
    spacing: 5

    property int    stepValue
    property string stepUnit

    FractLabel {
        text: qsTr("Value")
        Layout.fillHeight: true
        Layout.minimumWidth: 90
    }

    FractTextInput {
        id: valueControl
        text: stepValue
        Layout.fillWidth: true
        validator: IntValidator {bottom: 0; top: 9999}
    }

    FractComboBox {
        id: unitControl
        model: ["m", "km", "min", "sec"]

        Component.onCompleted: {
            var index=unitControl.find(stepUnit);
            if (index > -1) {
                unitControl.currentIndex=index;
            }
        }
    }
}
