import QtQuick
import QtQuick.Dialogs
import QtQuick.Controls.Basic
import Ellipse

ApplicationWindow {
    width: 640
    height: 480
    visible: true
    title: qsTr("QML Integrations Basics")

    footer: Button {
        text: qsTr("Call Q_INVOKABLE method to reset ellipse's properties")
        onClicked: {
            slider.value = 30
            ellipse.setProperties(slider.value, "green")
        }
    }

    header: Column {
        width: parent.width

        Button {
            width: parent.width
            text: qsTr("Select ellipse's new color")
            onClicked: { colorDialog.open() }
        }

        Label {
            width: parent.width
            text: qsTr("Resize ellipse's border")
        }

        Slider {
            id: slider

            width: parent.width
            value: 25
            from: 0
            to: Math.min(ellipse.width, ellipse.height) / 2
        }
    }

    EllipseObj {
        id: ellipse

        anchors.centerIn: parent
        width: 200
        height: 200
        color: "blue"
        border: slider.value

        onColorChanged: { ellipseInfo() }
    }

    ColorDialog {
        id: colorDialog

        selectedColor: ellipse.color
        onAccepted: { ellipse.color = selectedColor }
    }
}
