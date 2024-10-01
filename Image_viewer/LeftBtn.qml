import QtQuick

Item {
    id: root
    property color _bg_color: "red"
    property color _hover_color: "blue"
    property color _text_color: "white"
    property color _text_hover: "black"

    property alias _btnName: btnName
    property alias _btnMouseArea: btnMouseArea

    Rectangle {
        height: root.height
        width: root.width
        color: root._bg_color
        clip: true

        Text {
            id: btnName
            text: qsTr("text")
            anchors.centerIn: parent
            color: root._text_color
            font.bold: true
        }

        MouseArea {
            id: btnMouseArea
        }
    }
}
