import QtQuick 2.9
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.11

import "../conf/"

/**
 * activity viewer
 */
Item {
    id: root

    property real lineWidth: 20          // width of the line
    property string colorCircle: Style.controlBgColor

    Canvas {
        id: canvas
        anchors.fill: parent

        onPaint: {
            var ctx = getContext("2d")
            var x = width / 2
            var y = height / 2
            var start = 0
            var end = 2 * Math.PI
            ctx.reset()

            ctx.beginPath();
            ctx.arc(x, y, (width / 2) - parent.lineWidth / 2, start, end, false)
            ctx.lineWidth = root.lineWidth
            ctx.strokeStyle = root.colorCircle
            ctx.stroke()
        }
    }

    ColumnLayout {
        anchors.centerIn: parent

        FractLabel {
            text: "CURRENT / OBJECTIF"
            font.pointSize: 16
            horizontalAlignment: Text.AlignHCenter
            Layout.fillWidth: true
        }
        FractLabel {
            text: "8.6"
            font.pointSize: 32
            horizontalAlignment: Text.AlignHCenter
            Layout.fillWidth: true
        }
        FractLabel {
            text: "Next: 100m"
            font.pointSize: 16
            horizontalAlignment: Text.AlignHCenter
            Layout.fillWidth: true
        }
    }
}
