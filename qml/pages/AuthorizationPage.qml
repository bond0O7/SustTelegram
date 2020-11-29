import QtQuick 2.0
import Felgo 3.0
import QtQuick.Layouts 1.12
import QtQuick.Controls 1.4
Page {
    backgroundColor: Theme.backgroundColor
    title: qsTr("Login")
    AppTextField{
        id: phoneNumberEdit
        placeholderText: "Enter your phone number"
        placeholderColor: Theme.textColor
        anchors.centerIn: parent
        width: parent.width / 1.5
    }
    ColumnLayout{
        anchors.top: phoneNumberEdit.bottom
        anchors.margins: 10
        anchors.horizontalCenter: parent.horizontalCenter
        AppText{
            text: "Select your verfication method"
        }

        ExclusiveGroup{
            id: methodsGroups
        }
        RadioButton{
            id: telegramCodeMethod
            text: qsTr("Telegram Code")
            exclusiveGroup: methodsGroups
            checked: true
        }
        RadioButton{
            id: smsCodeMethod
            exclusiveGroup: methodsGroups
            text: qsTr("SMS Code")
        }
        RadioButton{
            id: phoneCallMethod
            exclusiveGroup: methodsGroups
            text: qsTr("Phone Call")
        }
        RadioButton{
            id: flashPhoneCallMethod
            exclusiveGroup: methodsGroups
            text: qsTr("Flash Phone Call")
        }
    }
    AppButton{
        backgroundColor: Theme.appButton.backgroundColor
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        text: qsTr("Get your code")
        textColor: Theme.appButton.textColor
    }
}
