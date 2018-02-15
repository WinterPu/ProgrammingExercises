import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2


import ResourceManager 1.0
import MyKits 1.0

Window {
    visible: true
    width: 500
    height: 700
    title: qsTr("Resource Manager")



    MainForm {
        id: mainForm
        anchors.fill: parent

        buttonInputFile.onClicked: fileDialogInput.open();
        btnOutputPath.onClicked: fileDialogOutput.open();

        btnDelete.onClicked: {
            manager.deleteNode(textFieldDelete.text);
            mainForm.graphArea.text = manager.showGraph();
            display_node_list();
            mainForm.textFileContent.text =  manager.getTextDataFromNodeList();
        }
        btnInsert.onClicked: {
            manager.insert(textFieldDerivative.text,textFieldMaterial.text);
            mainForm.graphArea.text = manager.showGraph();
            display_node_list();
            mainForm.textFileContent.text =  manager.getTextDataFromNodeList();
        }

        btnUpdate.onClicked: {
            manager.readFromQStringContext(mainForm.textFileContent.text);
            mainForm.graphArea.text = manager.showGraph();
            display_node_list();
            mainForm.textFileContent.text =  manager.getTextDataFromNodeList();
        }


        btnSave.onClicked: {
            manager.saveGraph(mainForm.textFieldOutputPath.text);
        }

    FileDialog{
        id:fileDialogInput
        onAccepted: {
            var path = fileUrl.toString();
            var head = "file:///";

            path = path.substring(head.length,path.length);
            mainForm.textFieldInputPath.text = path;
            mainForm.textFileContent.text = kits.readFromFile(path); // use [QString] rather than [std::string]

            manager.readFromQStringContext(mainForm.textFileContent.text);
            mainForm.graphArea.text = manager.showGraph();

            display_node_list();
        }
    }



    FileDialog{
        id:fileDialogOutput
        selectExisting: false
        onAccepted: {
            var path = fileUrl.toString();
            var head = "file:///";

            path = path.substring(head.length,path.length);
            mainForm.textFieldOutputPath.text = path;
        }
    }

  }



    ResourceManager{
       id:manager
    }

    Kits{
        id:kits
    }


    function display_node_list(){

        mainForm.sourceModel.clear();
        var node_list = manager.displayNodelist();
        for(var i =0; i<node_list.length;i+=2){
             mainForm.sourceModel.append({"item_name":node_list[i] , "useable":node_list[i+1]});
        }
    }

}
