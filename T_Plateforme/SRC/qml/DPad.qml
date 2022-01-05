/****************************************************************************
**
** Copyright (C) 2017 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Gamepad module
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

import QtQuick 2.0
import QtGamepad 1.0

Item {
    property Gamepad gamepad

    width: dpadImage.sourceSize.width
    height: dpadImage.sourceSize.height
    Image {
        id: dpadImage
        anchors.fill: parent
        source: "../xboxController/xboxControllerDPad.png"
    }

    Rectangle {
        id: upArea
        visible:
        {
            communication.toUpbtnCpp(gamepad.buttonUp);
            gamepad.buttonUp;
        }
        color: "#3814abff"
        radius: 5
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        width: parent.width * 0.3
        height: parent.height * 0.3
        anchors.topMargin: parent.height * 0.05
    }
    Rectangle {
        id: downArea
        visible:
        {
            communication.toDownbtnCpp(gamepad.buttonDown);
            gamepad.buttonDown;
        }
        color: "#3814abff"
        radius: 5
        width: parent.width * 0.3
        height: parent.height * 0.3
        anchors.bottom: parent.bottom
        anchors.bottomMargin: parent.height * 0.05
        anchors.horizontalCenter: parent.horizontalCenter
    }
    Rectangle {
        id: leftArea
        visible:
        {
            communication.toLeftbtnCpp(gamepad.buttonLeft);
            gamepad.buttonLeft;
        }
        color: "#3814abff"
        radius: 5
        width: parent.width * 0.3
        height: parent.height * 0.3
        anchors.left: parent.left
        anchors.leftMargin: parent.width * 0.05
        anchors.verticalCenter: parent.verticalCenter
    }

    Rectangle {
        id: rightArea
        visible:
        {
            communication.toRightbtnCpp(gamepad.buttonRight);
            gamepad.buttonRight;
        }
        color: "#3814abff"
        radius: 5
        width: parent.width * 0.3
        height: parent.height * 0.3
        anchors.right: parent.right
        anchors.rightMargin: parent.width * 0.05
        anchors.verticalCenter: parent.verticalCenter
    }
}
