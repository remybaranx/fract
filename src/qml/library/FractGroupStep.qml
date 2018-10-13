import QtQuick 2.9
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.3

import "../conf/"

RowLayout {
    spacing: Style.spacing

    FractLabel {
        text: qsTr("Repetition ")
        Layout.fillHeight: true
        Layout.minimumWidth: Style.labelMinWidth
    }
    FractTextInput {
        text: series
        placeholderText: "Enter the number of repetition"
        Layout.fillWidth: true
    }
}
