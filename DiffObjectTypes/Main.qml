import QtQuick
import DiffObjectTypes

Window {
    property point2D windowPos: "Polar"
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    x: windowPos.coordinate1
        y: windowPos.coordinate2

        Text {
            id: mainText

            anchors.centerIn: parent
        }

        Component.onCompleted: {
            //place the window in the bottom right corner
            windowPos.coordinate1 = Screen.width - width
            windowPos.coordinate2 = Screen.height - height
            mainText.text = "Window's initial position: %1".arg(windowPos.positionInfo())
        }
}
