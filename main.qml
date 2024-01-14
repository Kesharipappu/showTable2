import QtQuick 2.15
import QtQuick.Controls 1.5

ApplicationWindow {
    visible: true
    width: 800
    height: 600
    title: "Student Data Display"

    TableView {
        width: parent.width
        height: parent.height

        TableViewColumn {
            role: "name"
            title: "Name"
            width: 150
        }

        TableViewColumn {
            role: "fatherName"
            title: "Father's Name"
            width: 150
        }

        TableViewColumn {
            role: "motherName"
            title: "Mother's Name"
            width: 150
        }

        model: studentModel
    }
}
