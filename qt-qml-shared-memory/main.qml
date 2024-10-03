import QtQuick 2.12
import QtQuick.Window 2.12
import SharedMemory 1.0
import QtQuick.Controls 2.12

Window {
    visible: true
    width: 440
    height: 280
    title: qsTr("Shared Memory Example")

    SharedMemoryManager {
        id: sharedMemoryManager
    }

    Column {
        anchors.centerIn: parent
        spacing: 10

        TextField  {
            id: inputField
            width: 400
            placeholderText:"Enter message to write to shared memory"
        }
        Button
        {
            text: "Write to Shared Memory"
            onClicked: {
                sharedMemoryManager.writeToSharedMemory(inputField.text)
                inputField.text = ""
            }
        }
        Button {
            text: "Read from Shared Memory"
            onClicked: {
                let message = sharedMemoryManager.readFromSharedMemory()
                console.log("Read from shared memory: " + message)
                sharedMemoryLabel.text = message
            }
        }
        Label {
            id: sharedMemoryLabel
            text: "Shared memory content will appear here"
            width: 400
        }
    }

}
