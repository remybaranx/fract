pragma Singleton
import QtQuick 2.0

/**
 * Hardcoded configuration of the application
 */

QtObject {
    property string   appName: qsTr("Fract")
    property variant  units: ["m", "km", "min", "sec"]
}
