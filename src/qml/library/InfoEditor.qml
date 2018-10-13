import QtQuick 2.9
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.3

import "../library/"
import "../conf/"

ColumnLayout {
    spacing: Style.spacing

    property alias sessionName: sessionName.text
    property alias sessionDescription: sessionDescription.text

    FractEditorTitle {
        id: title
        text: qsTr("General Info")
    }

    RowLayout {
        spacing: Style.spacing

        FractLabel {
            text: qsTr("Name")
            Layout.fillHeight: true
            Layout.minimumWidth: Style.labelMinWidth
        }
        FractTextInput {
            id: sessionName
            placeholderText: qsTr("Enter the session name")
            Layout.fillWidth: true
        }
    }

    RowLayout {
        spacing: Style.spacing

        FractLabel {
            text: qsTr("Description")
            Layout.fillHeight: true
            Layout.minimumWidth: Style.labelMinWidth
        }
        FractTextInput {
            id: sessionDescription
            placeholderText: qsTr("Enter the session description")
            Layout.fillWidth: true
        }
    }
}
