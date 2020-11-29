import QtQuick 2.0
import Felgo 3.0
/*

// EXAMPLE USAGE:
// add the following piece of code inside your App { } to display the List Page

ChatPage {

}

*/

ListPage {
    id: messages

    title: qsTr("Contact Name")
    Rectangle{
        height: parent.height / 9
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        AppTextEdit{
            id: messageEdit
            anchors.left: parent.left
            anchors.right: sendBtn.left
            placeholderText: "Write a message..."
            placeholderColor: "grey"
            wrapMode: AppTextInput.WrapAtWordBoundaryOrAnywhere
            cursorInView: true
            cursorColor: "steelblue"
        }
        IconButton{
            id: sendBtn
            icon: IconType.send
            color: "steelblue"
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            width: parent.width / 5
            onClicked: {
                //TODO: Receives messages from the core code
            }
        }
    }

    model: []//TODO: Implement when the user send and recieves messages
}
