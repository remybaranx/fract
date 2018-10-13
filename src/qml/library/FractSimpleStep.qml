import QtQuick 2.9
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.3

import "../conf/"

ColumnLayout {

    FractStepValue {
        stepValue : value
        stepUnit  : unit
    }

    RowLayout {
        FractLabel {
            text: qsTr("Info ")
            Layout.fillHeight: true
            Layout.minimumWidth: Style.labelMinWidth
        }
        FractTextInput {
            text: info
            placeholderText: qsTr("Enter a description (optional)")
            Layout.fillWidth: true
        }
    }
}
