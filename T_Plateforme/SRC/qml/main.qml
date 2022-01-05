import QtQuick 2.0
import QtQuick 2.2
import QtQuick 2.7
import QtQuick 2.9
import QtQuick.Window 2.0
import QtQuick.Window 2.2
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.1
import QtQuick.Controls 2.2
import QtQuick.Controls.Material 2.2
import QtGamepad 1.14
import QtSensors 5.0
import QtQml 2.3
/*Qt3D*/
//import Qt3D.Core 2.0
//import Qt3D.Render 2.0
//import Qt3D.Input 2.0
//import Qt3D.Extras 2.0

ApplicationWindow
{
    id: applicationWindow1
    visible: true
    width: 800
    height: 600
    title: qsTr("QtGamepad Example")
    color: "#363330"

    Connections
    {
        target:communication
        onChangeCpp:
        {
            printCpp.text = text;
        }
    }

    Button
    {
        id: button1
        x:256; y:193
        text: qsTr("Acces cpp")
        onClicked:
        {
            communication.toStringCpp();
        }
    }
    Text
    {
        id: printCpp
        x: 277; y: 245
        text: qsTr("text")
        color: "#ffffff"
        font.pixelSize: 12
    }

    Browser
    {
        z:2
        visible: true
        id: browser
    }

    Item {
        id: background
        anchors.fill: parent

        ColumnLayout {
            anchors.fill: parent
            anchors.margins: 8
            RowLayout {
                id: topRow
                width: parent.width
                ColumnLayout {
                    id: buttonL2Item
                    Layout.alignment: Qt.AlignLeft
                    ButtonImage {
                        id: leftTrigger
                        Layout.alignment: Qt.AlignCenter
                        source: "../xboxController/xboxControllerLeftTrigger.png"
                        active:
                        {
                            communication.toLIIbtnCpp(gamepad.buttonL2);
                            gamepad.buttonL2 != 0;
                        }
                    }
                    ProgressBar {
                        id: buttonL2Value
                        width: leftTrigger.width
                        value: gamepad.buttonL2
                    }
                }

                Item {
                    id: centerButtons
                    Layout.alignment: Qt.AlignCenter
                    Layout.fillWidth: true
                    height: guideButton.height
                    width: guideButton.width + 16 + backButton.width + startButton.width
                    ButtonImage {
                        id: backButton
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.right: guideButton.left
                        anchors.rightMargin: 8
                        source: "../xboxController/xboxControllerBack.png"
                        active:
                        {
                            communication.toSelectbtnCpp(gamepad.buttonSelect);
                            gamepad.buttonSelect;
                        }
                    }
                    ButtonImage {
                        id: guideButton
                        anchors.centerIn: parent
                        source: "xboxControllerButtonGuide.png"
                        active: gamepad.buttonGuide
                        //{
                            //gamepad.buttonGuide;
                            //communication.toGuidebtnCpp(gamepad.buttonGuide);
                        //}
                    }
                    ButtonImage {
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.left: guideButton.right
                        anchors.leftMargin: 8
                        id: startButton
                        source: "../xboxController/xboxControllerStart.png"
                        active:
                        {
                            communication.toStartbtnCpp(gamepad.buttonStart);
                            gamepad.buttonStart;
                        }
                    }
                }


                ColumnLayout {
                    id: buttonR2Item
                    Layout.alignment: Qt.AlignRight
                    ButtonImage {
                        id: rightTrigger
                        Layout.alignment: Qt.AlignCenter
                        source: "../xboxController/xboxControllerRightTrigger.png"
                        active:
                        {
                            communication.toRIIbtnCpp(gamepad.buttonR2);
                            gamepad.buttonR2 != 0;
                        }
                    }

                    ProgressBar {
                        id: buttonR2Value
                        width: rightTrigger.width
                        value: gamepad.buttonR2
                    }
                }
            }

            RowLayout {
                id: middleRow
                ButtonImage {
                    id: buttonL1
                    source: "../xboxController/xboxControllerLeftShoulder.png"
                    active:
                    {
                        communication.toLIbtnCpp(gamepad.buttonL1);
                        gamepad.buttonL1;
                    }
                }
                Item {
                    id: spacer1
                    Layout.fillWidth: true
                }

                ButtonImage {
                    id: buttonR1
                    source: "../xboxController/xboxControllerRightShoulder.png"
                    active:
                    {
                        communication.toRIbtnCpp(gamepad.buttonR1);
                        gamepad.buttonR1;
                    }
                }
            }

            RowLayout {
                id: bottomRow
                width: parent.width
                DPad {
                    id: dPad
                    Layout.alignment: Qt.AlignLeft
                    gamepad: gamepad
                }

                LeftThumbstick {
                    id: leftThumbstick
                    Layout.alignment: Qt.AlignLeft
                    gamepad: gamepad
                }

                Item {
                    id: spacer2
                    Layout.fillWidth: true
                }

                RightThumbstick {
                    id: rightThumbstick
                    Layout.alignment: Qt.AlignRight
                    gamepad: gamepad
                }

                Item {
                    width: 200
                    height: 200
                    Layout.alignment: Qt.AlignRight
                    ButtonImage {
                        id: buttonA
                        anchors.bottom: parent.bottom
                        anchors.horizontalCenter: parent.horizontalCenter
                        source: "../xboxController/xboxControllerButtonA.png";
                        active:
                        {
                            communication.toAbtnCpp(gamepad.buttonA);
                            gamepad.buttonA;
                        }
                    }
                    ButtonImage {
                        id: buttonB
                        anchors.right: parent.right
                        anchors.verticalCenter: parent.verticalCenter
                        source: "../xboxController/xboxControllerButtonB.png";
                        active:
                        {
                            communication.toBbtnCpp(gamepad.buttonB);
                            gamepad.buttonB;
                        }
                    }
                    ButtonImage {
                        id: buttonX
                        anchors.left: parent.left
                        anchors.verticalCenter: parent.verticalCenter
                        source: "../xboxController/xboxControllerButtonX.png";
                        active:
                        {
                            communication.toXbtnCpp(gamepad.buttonX);
                            gamepad.buttonX;
                        }
                    }
                    ButtonImage {
                        id: buttonY
                        anchors.top: parent.top
                        anchors.horizontalCenter: parent.horizontalCenter
                        source: "../xboxController/xboxControllerButtonY.png";
                        active:
                        {
                            communication.toYbtnCpp(gamepad.buttonY);
                            gamepad.buttonY;
                        }
                    }
                }
            }
        }
    }

    Connections {
        target: GamepadManager
        onGamepadConnected: gamepad.deviceId = deviceId
    }

    Gamepad {
        id: gamepad
        deviceId: GamepadManager.connectedGamepads.length > 0 ? GamepadManager.connectedGamepads[0] : -1
    }
}
