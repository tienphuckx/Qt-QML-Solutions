import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

ApplicationWindow {
    visible: true
    width: 600
    height: 400  // Adjusted the height to make it smaller

    GridLayout {
        columns: 2
        rowSpacing: 20
        columnSpacing: 20
        anchors.fill: parent
        anchors.margins: 20

        // Left Column: Input Form
        ColumnLayout {
            Layout.alignment: Qt.AlignTop
            Layout.preferredWidth: parent.width * 0.4

            // Input field for name
            TextField {
                id: inputName
                placeholderText: "Enter name"
                Layout.fillWidth: true
                font.pixelSize: 15
            }

            // Gender selection using radio buttons
            GroupBox {
                title: "Gender"
                Layout.fillWidth: true
                RowLayout {
                    RadioButton {
                        id: maleRadio
                        text: "Female"
                        checked: true  // Default selected
                    }
                    RadioButton {
                        id: femaleRadio
                        text: "Male"
                    }
                }
            }

            // Position selection using checkboxes
            GroupBox {
                title: "Position"
                Layout.fillWidth: true
                ColumnLayout {
                    CheckBox {
                        id: fresherCheckbox
                        text: "Fresher"
                    }
                    CheckBox {
                        id: juniorCheckbox
                        text: "Junior"
                    }
                    CheckBox {
                        id: seniorCheckbox
                        text: "Senior"
                    }
                }
            }

            // Button to add the item
            Button {
                text: "Add Item"
                Layout.fillWidth: true
                onClicked: {
                    // Determine the selected gender
                    var gender = maleRadio.checked ? "Male" : "Female"

                    // Build the position string from checkboxes
                    var position = ""
                    if (fresherCheckbox.checked) position += "Fresher "
                    if (juniorCheckbox.checked) position += "Junior "
                    if (seniorCheckbox.checked) position += "Senior "

                    // Trim the trailing space if necessary
                    position = position.trim()

                    if (inputName.text.length > 0 && position.length > 0) {
                        // Call addItem function in C++
                        itemList.addItem(inputName.text, gender, position)
                        inputName.text = "" // Clear the text after adding
                        fresherCheckbox.checked = false
                        juniorCheckbox.checked = false
                        seniorCheckbox.checked = false
                    } else {
                        console.log("Please enter a name and select a position.")
                    }
                }
            }
        }

        // Right Column: Display List
        ColumnLayout {
            Layout.alignment: Qt.AlignTop
            Layout.preferredWidth: parent.width * 0.6
            spacing: 10

            // ListView to display the added items
            ListView {
                width: 280
                height: 280
                model: itemList.items

                delegate: ItemDelegate {
                    width: parent.width
                    text: modelData.name + ", " + modelData.gender + ", " + modelData.position
                }

                // Display a message if there are no items
                Text {
                    anchors.centerIn: parent
                    text: itemList.items.length === 0 ? "No items in the list" : ""
                }
            }
        }
    }
}
