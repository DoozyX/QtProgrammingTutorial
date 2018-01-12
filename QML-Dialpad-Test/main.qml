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

            Row {
                width: parent.width
                height: parent.height
                spacing: 5
                Rectangle {
                    id: phoneInput
                    width: parent.width - 90//btnSend.width
                    height: parent.height
                    BorderImage {
                        id: phoneInputImage
                        source: "qrc:/resources/field_normal.png"
                        anchors.fill: parent
                    }

                    Row {
                        width: parent.width
                        height: parent.height
                        spacing: 10


                        Rectangle {
                            id: btnCountry
                            width: 40
                            height: parent.height

                            color: "transparent"

                            Image {
                                id: flagImg
                                source: "qrc:/resources/countries/flags/1.jpg"
                                x: 5
                                y: parent.width/2.5
                                width: 30
                                height: 20
                            }
                            Image {
                                id: arrowImg
                                anchors.left: flagImg.right
                                y: parent.width/2
                                source: "qrc:/resources/combo_arrow.png"
                                width: 10
                                height: 10
                            }
                            MouseArea {
                                anchors.fill: parent
                                onClicked: {
                                    popupCountrySelect.open()
                                }
                            }

                        }

                        Rectangle {
                            id: inputPhone
                            width: parent.width - btnCountry.width
                            height: parent.height
                            color: "transparent"

                            TextInput {
                                id: textField
                                y: parent.height / 5
                                text: qsTr("number")
                                font.pixelSize: 19

                                inputMask: "+00000000000"
                                maximumLength: 11

                                onTextChanged: {
                                    flagImg.source = myModel.getFlagURLfromPhone(qsTr(text))
                                }

                                onFocusChanged: {
                                    if (textField.focus) {
                                        phoneInputImage.source = "qrc:/resources/field_focus.png"
                                    } else {
                                        phoneInputImage.source = "qrc:/resources/field_normal.png"
                                    }


                                }
                            }
                        }

                    }
                }
                Rectangle {
                    id: btnSend
                    width: 80
                    height: 50

                    BorderImage {
                        id: btnSendImage
                        source: "qrc:/resources/btn_white_normal.png"
                        anchors.fill: parent
                    }

                    Text {
                        id: a1233
                        anchors.centerIn: parent
                        font.pixelSize: 19
                        color: "white"
                        text: qsTr("Send")
                    }

                    MouseArea {
                        anchors.fill: parent
                        hoverEnabled: true
                        onEntered: {
                            console.log("Entered")
                            btnSendImage.source = "qrc:/resources/btn_white_hover.png"
                        }
                        onExited: {
                            console.log("Exited")
                            btnSendImage.source = "qrc:/resources/btn_white_normal.png"
                        }
                        onPressed: {
                            console.log("Pressed")
                            btnSendImage.source = "qrc:/resources/btn_white_down.png"
                        }

                        onReleased: {
                            console.log("Released")
                            btnSendImage.source = "qrc:/resources/btn_white_hover.png"
                        }
                    }

                }

            }
        }

        //Message box
        Rectangle {
            id: message
            width: parent.width
            height: parent.height - credits.height - phone.height - 100
            border.width: 1
            ScrollView {
                id: view
                anchors.fill: parent

                TextArea {
                    id: messageText
                    wrapMode: TextArea.Wrap
                    onTextChanged: {
                        var n = messageText.length
                        messagesCount.text =  parseInt(n / 160 + 1)
                        messageLetters.text = 160 - (n % 160)
                    }
                }
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
        id: popupCountrySelect
        x: 10
        y: 60
        width: parent.width - 20
        height: parent.height - 150
        modal: true
        focus: true


        Component {
            id: listRow
            Item {
                id: ads
                width: popupCountrySelect.width
                height: 20
                Row {
                    id: countryRow
                    width: popupCountrySelect.width
                    clip: true
                    spacing: 5
                    Rectangle {
                        id: boxCountryFlag
                        width:25
                        height:20
                        color: "transparent"
                        Image {
                            anchors.fill: parent
                            source: flagURL
                        }
                    }

                    Rectangle {
                        id: boxCountryName
                        width:countryRow.width - boxCountryCode.width - boxCountryFlag.width - 20
                        height:20
                        color: "transparent"
                        property alias text: txtCountryName.text
                        Text {
                            id: txtCountryName
                            anchors.fill: parent
                            text: countryName
                        }
                    }
                    Rectangle {
                        id: boxCountryCode
                        width:50
                        height:20
                        color: "transparent"

                        Text {
                            anchors.fill: parent
                            text: countryCode
                        }
                    }
                }
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        flagImg.source = myModel.getFlagURLfromIndex(index)
                        textField.text = myModel.getPhoneFromIndex(index)
                        lvCountries.currentIndex = index
                        popupCountrySelect.close()
                    }
                }
            }
        }


        ListView {
            id: lvCountries
            model: myModel
            delegate: listRow
            anchors.fill: parent
            interactive: true
            clip: true
            highlight: Rectangle {
                color: '#cccccc'
            }
            focus: true
            ScrollBar.vertical: ScrollBar {}
            //onCurrentItemChanged: console.log(lvCountries.currentIndex + ' selected')
        }
    }
}
