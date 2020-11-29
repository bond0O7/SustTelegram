import QtQuick 2.0
import Felgo 3.0

Page {
    title: "Your Phone"
    AppTextField{
        id: phoneNumberEdit
        placeholderText: "Enter your phone number"
        placeholderColor: Theme.placeholderTextColor
        backgroundColor: Theme.backgroundColor
        textColor: Theme.textColor
        anchors.centerIn: parent
    }
    FloatingActionButton{
        id: registerBtn
        visible: true
        icon: IconType.longarrowright
    }
}
