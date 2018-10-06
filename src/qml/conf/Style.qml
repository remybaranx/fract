pragma Singleton
import QtQuick 2.0

QtObject {
    property color bgColor: 'dimgray'
    property color lightBgColor: 'gray'
    property color textColor: 'lightgrey'
    property color lineColor: 'lightgrey'

    property color controlBgColor: 'cornflowerblue'
    property color buttonBgColor : 'tomato'
    property color disabledControlBgColor: 'lightslategray'
    property color controlTextColor: 'white'

    property color  toolbarBgColor     : controlBgColor
    property color  toolbarTextColor   : controlTextColor
    property font   toolbarFont        : Qt.font({
        pointSize: 14,
        family: 'Arial'
    })

    property font controlFont          : Qt.font({
         pointSize: 10,
         family: 'Arial'
     })
}
