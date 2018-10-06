import QtQuick 2.9
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.3

import "../library/"
import "../conf/"

ColumnLayout {
    spacing: 5
    id: root

    FractEditorTitle {
        id: title
        text: qsTr("General Info")
    }

    RowLayout {
        spacing: 5

        FractLabel {
            text: qsTr("Name")
            Layout.fillHeight: true
            Layout.minimumWidth: 90
        }
        FractTextInput {
            placeholderText: qsTr("Enter the session name")
            Layout.fillWidth: true
        }
    }

    RowLayout {
        spacing: 5

        FractLabel {
            text: qsTr("Description")
            Layout.fillHeight: true
            Layout.minimumWidth: 90
        }
        FractTextInput {
            placeholderText: qsTr("Enter the session description")
            Layout.fillWidth: true
        }
    }
}
