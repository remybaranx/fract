import QtQuick 2.9
import QtQuick.Controls 2.3
import QtQuick.Window 2.2
import QtQuick.Layouts 1.11

import "../conf/"
import "../library/"

RowLayout {
    spacing: Style.spacing

    property alias   stepValue : valueControl.text
    property string  stepUnit
    property alias   stepInfo  : infoControl.text

    FractTextInput {
        id: valueControl
        text: stepValue
        placeholderText: "Value"
        validator: IntValidator {bottom: 0; top: 9999}
        Layout.preferredWidth: 60
    }

    FractComboBox {
        id: unitControl
        model: Conf.units

        Component.onCompleted: {
            var index=unitControl.find(stepUnit);
            if (index > -1) {
                unitControl.currentIndex=index;
            }
        }

        Layout.preferredWidth: 80

        onCurrentTextChanged: {
            stepUnit=currentText
        }
    }

    FractTextInput {
        id: infoControl
        placeholderText: "Description"
        text: stepInfo
        Layout.fillWidth: true
    }
}
