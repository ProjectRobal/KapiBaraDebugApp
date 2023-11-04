import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3
import QtQuick3D


import "qrc:/" as Components

import qml.controller 1.0


Window {
    width: 640
    height: 480

    visible: true
    title: qsTr("KapibaraViewer3D")

    Item
    {
        focus: true
        Keys.onReleased:
            event => {
                if(event.isAutoRepeat)
                {
                    return;
                }

                console.log("Relased: "+event.key)

            switch(event.key)
            {
            case Qt.Key_Q:
            case Qt.Key_A:

                control.setDirectionLeft(Controller.Stop);

            break;

            case Qt.Key_W:
            case Qt.Key_S:

                control.setDirectionRight(Controller.Stop);

            break;

            }
            }


        Keys.onPressed: event=> {
                if(event.isAutoRepeat)
                {
                    return;
                }
                console.log(event.key)

            switch(event.key)
            {
            case Qt.Key_Q:
                // Left engine forward

                control.setDirectionLeft(Controller.Forward);

            break;

            case Qt.Key_A:
                // Left engine backward

                control.setDirectionLeft(Controller.Backward);

            break;

            case Qt.Key_W:
                // Right engine forward

                control.setDirectionRight(Controller.Forward);

            break;

            case Qt.Key_S:
                // Right engine backward

                control.setDirectionRight(Controller.Backward);

            break;

            case Qt.Key_P:
                // Increase speed

                control.updateSpeed(1)

            break;

            case Qt.Key_L:
                // Decrease speed

                control.updateSpeed(-1)

            break;

            }

        }


    GridLayout {
        id: grid
        x: 0
        y: 0
        width: Window.width
        height: Window.height
        columnSpacing:20

        columns:4
        rows:5

        RowLayout {
            id: rowLayout
            Layout.columnSpan: 4
            Layout.rowSpan: 1
            Rectangle
            {

                width: 260
                height: 32
                border.width:1
                TextInput
                {
                    horizontalAlignment:TextInput.AlignHCenter
                    verticalAlignment: TextInput.AlignVCenter
                    maximumLength:32
                    text:"0.0.0.0"
                    id: ipinput
                    width: parent.width
                    height:parent.height
                }

            }

            Button
            {
                Layout.alignment: Qt.AlignLeft
                text:"Connect"
                onClicked: control.getIPandConnect(ipinput.text)
            }

            CheckBox
            {
                checked:false
               onClicked:{
                    control.setManualControl(checked)
                    control.ControlChanged()
               }
            }
            Text
            {
                text:"Manual mode"
            }

        }

        ColumnLayout
        {
            Layout.columnSpan: 2
            Layout.rowSpan: 3
        Text {
            width:parent.width
            Layout.rowSpan: 1
            id: text1
            height: 61
            text: qsTr("Sensors reading:")
            font.pixelSize: 16
            verticalAlignment: Text.AlignVCenter
        }

        ScrollView {
            width:parent.width
            Layout.rowSpan: 2
            Layout.fillHeight: true
            ScrollBar.horizontal.policy: ScrollBar.AlwaysOff
            ScrollBar.vertical.policy: ScrollBar.AlwaysOn

        TextArea {
            anchors.fill: parent
            id: sensorsReading
            text:control.SensorsText
            color:"black"
            readOnly: true

        }

            }

        }

    View3D {
        id: view

        Layout.fillWidth: true
        Layout.fillHeight: true
        Layout.columnSpan: 2
        Layout.rowSpan: 3


        environment: SceneEnvironment {
            clearColor: "skyblue"
            backgroundMode: SceneEnvironment.Color
        }

        PerspectiveCamera {
            position: Qt.vector3d(0, 200, 300)
            eulerRotation.x: -30
        }

        DirectionalLight {
            eulerRotation.x: -30
            eulerRotation.y: -70
        }

        Model {
            position: Qt.vector3d(0, -200, 0)
            source: "#Cylinder"
            scale: Qt.vector3d(5, 0.2, 2)
            materials: [ DefaultMaterial {
                    diffuseColor: "red"
                }
            ]
        }

        Components.MiniBara
        {
            id:minibara
            position: Qt.vector3d(0, 40, 0)
            scale:Qt.vector3d(4.5,4.5,4.5)
            eulerRotation:control.rotation

        }

    }


    Text {
        Layout.columnSpan: 4
        Layout.rowSpan: 1
        id: messages
        text: control.msg
    }

    }

    }

}
