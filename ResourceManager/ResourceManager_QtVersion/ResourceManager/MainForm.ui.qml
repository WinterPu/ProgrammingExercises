import QtQuick 2.6
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.1

Rectangle {
    id: rectangle1

    width: 500
    height: 700
    property alias btnOutputPath: btnOutputPath
    property alias textFieldOutputPath: textFieldOutputPath
    property alias btnUpdate: btnUpdate
    property alias btnSave: btnSave
    property alias tableViewNodeList: tableViewNodeList
    property alias btnInsert: btnInsert
    property alias textFieldMaterial: textFieldMaterial
    property alias textFieldDerivative: textFieldDerivative
    property alias textFieldDelete: textFieldDelete
    property alias btnDelete: btnDelete
    property alias graphArea: graphArea
    property alias textFileContent: textFileContent
    property alias buttonInputFile: buttonInputFile
    property alias textFieldInputPath: textFieldInputPath

    property alias sourceModel: sourceModel

    Rectangle {
        id: rectangle
        height: 50
        color: "#000000"
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0
    }

    GroupBox {
        id: viewArea
        y: 63
        height: 500
        width: 480
        anchors.right: parent.right
        anchors.rightMargin: 10
        anchors.left: parent.left
        anchors.leftMargin: 10
        title: qsTr("")

        TextArea {
            id: textFileContent
            width: 210
            anchors.left: parent.left
            anchors.leftMargin: 10
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 100
            anchors.top: parent.top
            anchors.topMargin: 10
        }

        TableView {
            id: tableViewNodeList
            x: 234
            y: 243
            width: 220
            height: 142
            highlightOnFocus: true
            sortIndicatorVisible: true
            currentRow: 1
            anchors.right: parent.right
            anchors.rightMargin: 10
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 100
            TableViewColumn {
                id:nameColumn
                title:"Item Name"
                role: "item_name"
                width: tableViewNodeList.viewport.width - useableColumn.width
            }
            TableViewColumn {
                id:useableColumn
                title:"Useable"
                role: "useable"
                width: tableViewNodeList.viewport.width / 3
            }
           model: ListModel{
                id: sourceModel
            }
        }

        GroupBox {
            id: operation
            height: 80
            anchors.right: parent.right
            anchors.rightMargin: 10
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 10
            anchors.left: parent.left
            anchors.leftMargin: 10
            title: qsTr("")

            ColumnLayout {
                id: columnLayout1
                anchors.fill: parent

                RowLayout {
                    id: rowLayout1
                    width: 100
                    height: 100
                    spacing: 10

                    Label {
                        id: label1
                        text: qsTr("Insert")
                    }

                    TextField {
                        id: textFieldDerivative
                        placeholderText: qsTr("Text Field")
                    }

                    TextField {
                        id: textFieldMaterial
                        placeholderText: qsTr("Text Field")
                    }

                    Button {
                        id: btnInsert
                        text: qsTr("Insert")
                        Layout.preferredWidth: 60
                        Layout.preferredHeight: 20
                        Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
                    }
                }

                RowLayout {
                    id: rowLayout2
                    width: 100
                    height: 100
                    spacing: 10

                    Label {
                        id: label2
                        text: qsTr("Delete")
                    }

                    TextField {
                        id: textFieldDelete
                        placeholderText: qsTr("Text Field")
                    }

                    Button {
                        id: btnDelete
                        text: qsTr("Delete")
                        Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
                    }
                }
            }
        }

        TextArea {
            id: graphArea
            width: 220
            height: 222
            readOnly: true
            anchors.top: parent.top
            anchors.topMargin: 10
            anchors.right: parent.right
            anchors.rightMargin: 10
        }


    }

    GroupBox {
        id: fileArea
        y: 577
        height: 107
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 30
        anchors.right: parent.right
        anchors.rightMargin: 10
        anchors.left: parent.left
        anchors.leftMargin: 10
        title: qsTr("")

        ColumnLayout {
            id: columnLayout
            anchors.fill: parent

            RowLayout {
                id: rowLayout
                width: 100
                height: 100

                Label {
                    id: label
                    text: qsTr("Resource File")
                }

                TextField {
                    id: textFieldInputPath
                    Layout.preferredHeight: 20
                    Layout.preferredWidth: 300
                    placeholderText: qsTr("Text Field")
                }

                Button {
                    id: buttonInputFile
                    text: qsTr("...")
                    Layout.preferredWidth: 50
                }
            }

            RowLayout {
                id: rowLayout4
                width: 100
                height: 100

                Label {
                    id: label3
                    text: qsTr("Output")
                    horizontalAlignment: Text.AlignHCenter
                }

                TextField {
                    id: textFieldOutputPath
                    width: 350
                    Layout.preferredWidth: 340
                    placeholderText: qsTr("Text Field")
                }

                Button {
                    id: btnOutputPath
                    width: 50
                    height: 20
                    text: qsTr("...")
                    Layout.preferredWidth: 50
                }
            }

            RowLayout {
                id: rowLayout3
                width: 100
                height: 100


                Button {
                    id: btnUpdate
                    text: qsTr("Update")
                    Layout.fillWidth: true
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                }
                Button {
                    id: btnSave
                    text: qsTr("Save ")
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                    Layout.fillWidth: true
                }
            }



        }
    }
}
