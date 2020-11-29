import QtQuick 2.0
import Felgo 3.0

/*

// EXAMPLE USAGE:
// add the following piece of code inside your App { } to display the List Page

MainPage {

}

*/

ListPage {
    title: "Sust Telegram"
    SimpleRow{
        id: announcements
        AppText{
            text: qsTr("Announcements")
            fontSize: 16
            anchors.centerIn: parent
        }
        z: 1
        anchors.bottom: parent.bottom
        height: parent.height / 9
    }
    model: []//Todo: fill it with the upcomming updates from the core code
    AppDrawer{
        Rectangle{
            id: background
            anchors.fill: parent
            color: Theme.backgroundColor

            Rectangle{
                color: "steelblue"
                anchors.top: parent.top
                anchors.right: parent.right
                anchors.left: parent.left
                height: parent.height / 4
                RoundedImage{
                    anchors.left: parent.left
                    anchors.bottom: parent.bottom
                }
            }
        }
    }
}
