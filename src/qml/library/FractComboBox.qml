import QtQuick 2.9
import QtQuick.Controls 2.3

import "../conf/"

ComboBox {
    id  : root
    font: Style.controlFont
    spacing: 5 // space between text and indicator (triangle)

    delegate: ItemDelegate {
        width: root.width

        contentItem: Text {
            text: modelData
            color: Style.textColor
            font: root.font
            elide: Text.ElideRight
            verticalAlignment: Text.AlignVCenter
        }

        background: Rectangle {
            color: "transparent"
        }

        highlighted: root.highlightedIndex === index
    }

    indicator: Canvas {
        id: canvas
        x: root.width - width - root.rightPadding/2
        y: root.topPadding + (root.availableHeight - height) / 2
        width: 12
        height: 8
        contextType: "2d"

        Connections {
            target: root
            onPressedChanged: canvas.requestPaint()
        }

        onPaint: {
            context.reset();
            context.moveTo(0, 0);
            context.lineTo(width, 0);
            context.lineTo(width / 2, height);
            context.closePath();
            context.fillStyle = Style.lineColor
            context.fill();
        }
    }

    contentItem: Text {
        leftPadding: 10
        rightPadding: root.indicator.width + root.spacing
        topPadding: 5
        bottomPadding: 5

        text: root.displayText
        font: root.font
        color: Style.textColor
        verticalAlignment: Text.AlignVCenter
        elide: Text.ElideRight
    }

    background: Rectangle {
        border.color: Style.lineColor
        border.width: root.visualFocus ? 2 : 1
        color: Style.bgColor
        radius: 2
    }

    popup: Popup {
        y: root.height - 1
        width: root.width
        implicitHeight: contentItem.implicitHeight
        padding: 1

        contentItem: ListView {
            clip: true
            implicitHeight: contentHeight
            model: root.popup.visible ? root.delegateModel : null
            currentIndex: root.highlightedIndex

            ScrollIndicator.vertical: ScrollIndicator { }
        }

        background: Rectangle {
            color: Style.bgColor
            border.color: Style.lineColor
            radius: 2
        }
    }
}
