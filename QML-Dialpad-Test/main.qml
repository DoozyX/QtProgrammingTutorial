import QtQuick 2.9
import QtQuick.Window 2.3
import QtQuick.Controls 2.2

Window {
    visible: true
    width: 400
    height: 400


    Image {
        source: "qrc:/resources/bgd_roster_gradient.png"
        anchors.fill: parent
        rotation: 180
    }

    Image {
        source: "qrc:/resources/bgd_bubbles.png"
        anchors.fill: parent
    }

    Column {
        anchors.fill: parent;
        anchors.margins: 10
        spacing: 5

        //First Row Credits
        Rectangle {
            id: credits
            width: parent.width
            height: 50
            color: "transparent"

            Text {
                id: text1
                width: 46
                text: qsTr("Credit:")
                clip: false
                font.pixelSize: 19
            }

            Text {
                id: text2
                x: 71
                width: 46
                color: "#329aec"
                text: qsTr("$0.00")
                clip: false
                font.pixelSize: 19
            }

            Text {
                id: text3
                x: parent.width - 100
                width: 87
                color: "#329aec"
                text: qsTr("Buy credit")
                horizontalAlignment: Text.AlignRight
                clip: false
                font.pixelSize: 19
            }
        }

        //Phone Input
        Rectangle {
            id: phone
            width: parent.width
            height: 50
            color: "transparent"


            Rectangle {
                id: phoneInput
                width: btnCountry.width + textField.width
                height: 50
                border.width: 1
                Rectangle {
                    id: btnCountry
                    anchors.left: parent.left + 5
                    width: 40
                    height: 50
                    Image {
                        id: flagImg
                        source: "qrc:/resources/countries/flags/1.jpg"
                        width: 30
                        height: 20
                        y: 15
                    }
                    Image {
                        id: arrowImg
                        anchors.left: flagImg.right
                        source: "qrc:/resources/combo_arrow.png"
                        width: 10
                        height: 10
                        y: 20
                    }
                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            console.info("image clicked!")
                        }
                    }
                }

                TextField {
                    id: textField
                    width: parent.width - btnCountry - btnSend.width - 30
                    anchors.left: btnCountry.right
                    x: 50
                    text: qsTr("number")
                }
            }

            Button {
                id: btnSend
                x: parent.width - btnSend.width - 8
                text: qsTr("Send")
            }
        }

        //Message box
        Rectangle {
            id: message
            width: parent.width
            height: parent.height - credits.height - phone.height - 100
            border.width: 1

            TextArea {
                id: messagetext
                anchors.fill: parent
            }
        }

        //Message Count
        Rectangle {
            width: parent.width
            height: 50
            color: "transparent"

            Row {
                anchors.right: parent.right
                Text {
                    id: messageLetters
                    text: qsTr("160")
                    clip: false
                    font.pixelSize: 19
                }

                Text {
                    id: text11
                    color: "grey"
                    text: qsTr("/")
                    clip: false
                    font.pixelSize: 19
                }

                Text {
                    id: messagesCount
                    color: "grey"
                    text: qsTr("1")
                    clip: false
                    font.pixelSize: 19
                }
            }
        }

        //Calls
        Rectangle {
            width: parent.width
            height: 50
            color: "transparent"

            Text {
                id: callText
                x: 50
                color: "white"
                text: qsTr("Call")
                clip: false
                font.pixelSize: 19
            }

            Text {
                id: seeRates
                anchors.right: parent.right
                color: "#329aec"
                text: qsTr("See Rates")
                clip: false
                font.pixelSize: 19
            }


        }

    }

    Popup {
        id: countrySelect
        x: 10
        y: 60
        width: parent.width - 20
        height: parent.height - 150
        modal: true
        focus: true

        ListView {
            id: listView
            anchors.fill: parent
            contentWidth: parent.width

            //contentWidth: headerItem.width
            //flickableDirection: Flickable.HorizontalAndVerticalFlick
            model: myModel

            delegate: Rectangle {
                id: root
                width: parent.width
                height: 30

                //                        Image {
                //                            id: image

                //                            source: decoration
                //                            fillMode: Image.PreserveAspectFit
                //                            height: parent.height
                //                        }

                Text {
                    //text: nameRole
                    text: display
                    //verticalAlignment: Text.AlignVCenter
                    //anchors.verticalCenter: image.verticalCenter
                }

                //                        MouseArea {
                //                            anchors.fill: parent

                //                            onClicked: {

                //                                console.log("current index is " + index );

                //                                root.ListView.view.currentIndex = index
                //                                root.forceActiveFocus()
                //                            }
                //                        }
            }
            //ScrollIndicator.horizontal: ScrollIndicator { }
            ScrollIndicator.vertical: ScrollIndicator { }
        }
    }
}
