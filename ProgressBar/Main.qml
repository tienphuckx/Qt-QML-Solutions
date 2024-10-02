import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

Window {
    width: 640
    height: 380
    visible: true
    title: qsTr("Progress bar")

    Column
    {
        spacing: 20
        anchors.centerIn: parent
        width: 640

        Slider
        {
            id: mySlider
            width: parent.width * 0.8
            from: 0
            to: 1000
            stepSize: 1
            anchors.centerIn: parent

            onValueChanged:
            {
                console.log("Progress bar value : " , value);
            }

            background: Rectangle
            {
                x: mySlider.leftPadding
                y: mySlider.topPadding + mySlider.availableHeight / 2 - height / 2
                implicitWidth: 200
                implicitHeight: 20
                width: mySlider.availableWidth
                height: implicitHeight
                radius: height / 2
                color: "#0abde3"

                Rectangle
                {
                    width: mySlider.visualPosition == 0 ? 0 : mySlider.handle.x  + mySlider.handle.width / 2
                    height: parent.height
                    color: "black"
                    radius: height / 2
                }
            }

            handle: Rectangle
            {
                x: mySlider.leftPadding + mySlider.visualPosition * (mySlider.availableWidth - width)
                y: mySlider.topPadding + mySlider.availableHeight / 2 - height/ 2
                implicitHeight: 45
                implicitWidth: 45
                radius: implicitWidth / 2
                color: mySlider.pressed ? "#ffffff" : "#ffffff"
                border.color: "#0abde3"
                border.width: 4
            }
        }

        Text
        {
            id: mySliderText
            text : "Progress bar Value : " + mySlider.value
            anchors.top: mySlider.bottom
            anchors.horizontalCenter: mySlider.horizontalCenter
        }
    }
}
