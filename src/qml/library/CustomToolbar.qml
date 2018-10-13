import QtQuick 2.9
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.3
import QtQuick.Controls.Material 2.1

/**
 * Toolbar with a title and a right button
 */
ToolBar {
    id: root

    anchors.left  : parent.left
    anchors.right : parent.right
    anchors.top   : parent.top

    /** global background color of the toolbar (buttons and title) */
    property color color

    /** global text color of the toolbar (buttons and title) */
    property color textColor

    /** expose button signal to the external world */
    signal buttonClicked()

    /** title of the toolbar */
    property alias title: titleComponent.text

    /** expose button text to the external world */
    property alias buttonText: rightButton.text

	RowLayout {
		anchors.fill: parent
        spacing: 0

        /** the title */
		Label {
            id: titleComponent

            background: Rectangle {
                color: root.color
            }

            color           : root.textColor
            font  : root.font

            elide               : Label.ElideRight
            horizontalAlignment : Qt.AlignHCenter
            verticalAlignment   : Qt.AlignVCenter
            Layout.fillWidth    : true
            Layout.fillHeight   : true
        }

        /** the right button */
        CustomToolButton {
            id: rightButton
            font      : root.font
            color     : root.color
            textColor : root.textColor

            Layout.fillHeight: true

            /** propagate the 'clicked' signal */
            onClicked:buttonClicked()
        }
	}
}
