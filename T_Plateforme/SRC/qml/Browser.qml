//Page d'accueil de l'application

import QtQuick 2.2

Item {
    id: browser
    visible: true
    x: parent.x
    y: parent.y
    width: parent.width
    height: parent.height
    //antialiasing: true
    opacity: 1
    clip: false

    Authentifier
    {
        id: authZone
        //text: "Authentifier"
        x: parent.x; y: parent.y
        width: parent.width / 2; height: parent.height / 2
    }
    Item
    {
        id: menu
        z: 3
        visible: true
        opacity: 1
        clip: false
        x: parent.x; y: (parent.y + parent.height / 2) / 2
        width: parent.width / 2; height: parent.height / 2

        Rectangle
        {
            //AutoBtn
            //ReservBtn
            //UserBtn
            //ProfilBtn
        }
    }

    states: //get laucher invisible when the button play is clicked
    [
        State
        {
            name: "playClicked"
            when: mousePlay.pressed == true
            PropertyChanges { target: laucher; visible: false; restoreEntryValues: false }
        }
    ]



}
