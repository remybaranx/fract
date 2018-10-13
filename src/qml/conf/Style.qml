pragma Singleton
import QtQuick 2.0

/**
 * Style of the application (colors, fonts, spacing, ...)
 */
QtObject {

    /**< background color for application pages */
    property color bgColor: 'dimgray'

    /**< lighter background color for application pages or controls */
    property color lightBgColor: 'gray'

    /**< background color for controls */
    property color controlBgColor: 'cornflowerblue'

    /**< background color for buttons */
    property color buttonBgColor : 'tomato'

    /**< text color for application pages */
    property color textColor: 'lightgrey'

    /**< color for borders of some components */
    property color lineColor: 'lightgrey'

    /**< text color for controls */
    property color controlTextColor: 'white'

    /**< a font dedicated to the toolbar */
    property font toolbarFont : Qt.font({
        pointSize: 18,
        family: 'Arial'
    })

    /**< a font dedicated to controls */
    property font controlFont : Qt.font({
         pointSize: 12,
         family: 'Arial'
     })

    /**< */
    property int labelMinWidth : 120

    /**< global spacing between elements in a layout */
    property int spacing : 5
}
