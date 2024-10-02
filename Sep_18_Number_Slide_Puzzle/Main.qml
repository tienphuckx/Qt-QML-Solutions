import QtQuick 2.15
import QtQuick.Controls 2.15

Window {
    width: 400
    height: 530
    visible: true
    title: qsTr("Number Slide Puzzle")

    property int _GRID_SIZE: 3 // 3x3 grid
    property string statusBanner_Color: ""
    property string _MSG_SUCCESS: "YOU ARE WIN"
    property string _MSG_LOSE: "YOU ARE LOSE"
    property string statusMessage: ""
    property int _MAX_STEP: 50

    property string _COLOR_WHITE: "white"
    property string _COLOR_RED: "red"
    property string _COLOR_BLACK: "black"
    property string _COLOR_GRAY: "gray"
    property string _COLOR_YELLOW: "yellow"
    property string _COLOR_ORANGE: "orange"

    property string _EMPTY_STRING: ""
    property int stepCntValue: 49
    property string statusColor: ""

    property var puzzleArray: [
        [1, 2, 3],
        [4, 5, 6],
        [7, 0, 8]
    ]

    Text {
        id: nameGame
        text: qsTr("Number Slide Puzzle")
        color: "black"
        font.pixelSize: 24
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 5
    }

    // Display step counting
    Text {
        id: stepCnt
        text: qsTr("Step: ") + stepCntValue.toString() + qsTr(" / ") + _MAX_STEP
        color: "black"
        font.pixelSize: 15
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.topMargin: 5
        anchors.bottomMargin: 5
        Rectangle {
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: -40
            width: 165
            height: 35
            color: _COLOR_BLACK
            Text {
                text: qsTr("Donate to Re-Play")
                font.pixelSize: 17
                anchors.centerIn: parent
                anchors.topMargin: 5
                anchors.bottomMargin: 5
                color: _COLOR_WHITE
            }

            MouseArea {
                anchors.fill: parent  // Ensure the MouseArea covers the entire rectangle
                onClicked: display_donate_qr() // Omit the parentheses when calling the function
            }
        }
    }

    // BANNER for TEXT WIN or LOSE
    Rectangle {
        id: statusBanner
        width: 350
        height: 350
        opacity: 0.7
        color: statusBanner_Color
        anchors.centerIn: parent
        z: 0
    }


    // BANNER for DANATE
    Rectangle {
        id: donateBanner
        width: 350
        height: 350
        color: _COLOR_BLACK
        anchors.centerIn: parent
        visible: false
        z:-1

        Image {  // QR IMAGE
            id: donateQR
            width: 350
            height: 310
            source: "qrc:/img/phucnt38"
            fillMode: Image.PreserveAspectFit
            anchors.centerIn: parent
            z:-2
            visible: false
        }

        Rectangle {  // CLOSE QR BUTTON
            width: 33
            height: 33
            radius: width
            border.color: _COLOR_BLACK
            border.width: 3
            color: _COLOR_WHITE
            x: parent.width - 55
            y: 3
            z: 102
            Text {  // X
                id: closeDonateQR
                text: qsTr("X")
                anchors.centerIn: parent
                color: _COLOR_BLACK
                font.pixelSize: 17

                MouseArea {
                    anchors.fill: parent
                    onClicked: hide_donate_qr()
                }
            }
        }
    }

    //TEXT WIN or LOSE
    Text {
        id: statusText // announce to user Win or Lose
        text: statusMessage
        anchors.centerIn: parent
        opacity: 1
        font.pixelSize: 30
        color: statusColor
        z: 0
    }

    Rectangle {
        width: 300
        height: 300
        color: _COLOR_BLACK
        anchors.centerIn: parent
        z:10

        Grid {
            id: puzzleGrid
            columns: _GRID_SIZE
            rows: _GRID_SIZE
            spacing: 7
            anchors.centerIn: parent

            Repeater {
                model: _GRID_SIZE * _GRID_SIZE

                Rectangle {
                    id: tile
                    width: 100
                    height: 100
                    color: getColor(index)

                    Text {
                        anchors.centerIn: parent
                        text: getText(index)
                        color: _COLOR_WHITE
                        font.pixelSize: 24
                    }

                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            var row = Math.floor(index / _GRID_SIZE);
                            var col = index % _GRID_SIZE;
                            var tileValue = puzzleArray[row][col];

                            var emptyTilePos = findEmptyTile();

                            if (isAdjacent(row, col, emptyTilePos[0], emptyTilePos[1])) {
                                swapWithEmptyTile(row, col, emptyTilePos[0], emptyTilePos[1]);

                                verify();

                                check_for_success();
                            } else {
                                log_not_adjacent(tileValue);
                            }
                        }
                    }
                }
            }
        }
    }


    function display_donate_qr() {
        wlog("Display donate QR")
        donateBanner.visible = true
        donateBanner.z = 100
        donateQR.visible = true
        donateQR.z = 101
    }

    function hide_donate_qr() {
        wlog("Hide donate QR")
        donateBanner.visible = false
        donateBanner.z = -1
        donateQR.visible = false
        donateQR.z = -2
    }

    function verify() {
        if(check_for_success() && stepCntValue <= _MAX_STEP){
            announce_win();
            return;
        }else if(!check_for_success()) {
            if(stepCntValue < _MAX_STEP) {
                increase_step_count();
            }else{
                announce_lose();
            }
        }
    }

    function findEmptyTile() {
        for (var row = 0; row < _GRID_SIZE; row++) {
            for (var col = 0; col < _GRID_SIZE; col++) {
                if (puzzleArray[row][col] === 0) {
                    return [row, col];
                }
            }
        }
        return [-1, -1];
    }

    function isAdjacent(row1, col1, row2, col2) {
        return (row1 === row2 && Math.abs(col1 - col2) === 1) ||
                (col1 === col2 && Math.abs(row1 - row2) === 1);
    }

    function swapWithEmptyTile(clickedRow, clickedCol, emptyRow, emptyCol) {
        var temp = puzzleArray[clickedRow][clickedCol];
        puzzleArray[clickedRow][clickedCol] = puzzleArray[emptyRow][emptyCol];
        puzzleArray[emptyRow][emptyCol] = temp;
        puzzleArray = puzzleArray;
    }

    function check_for_success() {
        var expected = 1;
        for (var row = 0; row < _GRID_SIZE; row++) {
            for (var col = 0; col < _GRID_SIZE; col++) {
                if (row === _GRID_SIZE - 1 && col === _GRID_SIZE - 1) {
                    if (puzzleArray[row][col] === 0) {
                        return true
                    }
                } else if (puzzleArray[row][col] !== expected) {
                    return false;
                }
                expected++;
            }
        }
    }

    function getColor(index) {
        var value = getValue(index);
        return value === 0 ? _COLOR_BLACK : _COLOR_RED;
    }

    function getText(index) {
        var value = getValue(index);
        return value !== 0 ? value.toString() : _EMPTY_STRING;
    }

    function getValue(index) {
        return puzzleArray[Math.floor(index / _GRID_SIZE)][index % _GRID_SIZE];
    }

    function increase_step_count() {
        wlog("stepCntValue++")
        stepCntValue++;
        if(stepCntValue == _MAX_STEP)
            announce_lose();
    }

    function announce_win() {
        wlog("SUCCESSS");
        statusBanner.z = 20
        statusText.z = 30
        statusMessage = _MSG_SUCCESS
        statusColor = _COLOR_WHITE
        statusBanner_Color = _COLOR_BLACK
    }

    function announce_lose() {
        wlog("LOSE");
        statusBanner.z = 20
        statusText.z = 30
        statusMessage = _MSG_LOSE
        statusColor = _COLOR_ORANGE
        statusBanner_Color = _COLOR_BLACK
    }

    function log_not_adjacent(index) {
        console.log("Tile " + index + " is NOT adjacent to the empty tile.");
    }

    function wlog(content) {
        console.debug("--> " + content + " !!!");
    }
}

