import QtQuick 2.2

Item {
    id: authentifier
    visible: true
    z:1
    x: parent.x
    y: parent.y
    width: parent.width
    height: parent.height
    opacity: 1
    clip: false
    //property alias text: textItem.text
    //property alias isEnabled: button.enabled
    signal clicked(string text)

    //LOGIN INPUT
    //PSW INPUT
    //BUTTON LOGIN
    //BUTTON EXIT
}
