import QtQuick 2.9
import QtQuick.Controls 2.3

ToolButton {
    id: root

    property color  color
    property color  textColor

    /** set the button background to the global color */
    background: Rectangle {
        id: backgroundComponent
        color: root.color
    }

    /** set the button text color to the global text color */
    contentItem: Text {
        id: textComponent
        text            : root.text
        color           : root.textColor
        font            : root.font

        horizontalAlignment : Text.AlignHCenter
        verticalAlignment   : Text.AlignVCenter
        elide               : Text.ElideRight
    }

    /** hide the button when its text is empty */
    onTextChanged: {
        text==""?visible=false:visible=true
    }
}
