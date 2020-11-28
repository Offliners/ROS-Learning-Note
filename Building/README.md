# Building ROS Work Space

## 建立 Work Space
```shell
mkdir -p ~/catkin_ws/src          // 建立Work Space中的src資料夾
cd ~/catkin_ws/                   // 前往Work Space資料夾
catkin_make                       // 編譯此Work Space
source devel/setup.bash           // 選擇ROS要執行的Work Space
```

每次執行ROS要選擇Work Space很麻煩，所以將常用的寫入`.bashrc`
```shell
sudo nano ~/.bashrc
```

將`source ~/catkin_ws/devel/setup.bash`貼在上去後`ctrl + o`並enter確定存檔後`ctrl + x`退出

![bashrc](https://github.com/Offliners/ROS_Learning_Note/blob/main/Building/bashrc.PNG)

## 在Work Space建立要執行的資料夾
```shell
cd src                                                                // 在此Work Space中前往src資料夾
catkin_create_pkg test roscpp std_msgs actionlib actionlib_msgs       // 建立test資料夾並使用roscpp與加入需使用的函式庫
cd ..                                                                 // 回上一層
catkin_make                                                           // 重新編譯Work Space讓環境知道新增加test資料夾
. ~/catkin_ws/devel/setup.bash                                        // 再次選擇要執行的Work Space
```

![roscpp](https://github.com/Offliners/ROS_Learning_Note/blob/main/Building/roscpp.PNG)

若成功建立，則開新的terminal輸入
```
roscd test/
```
就可直接到此資料夾中

## 使用 ROSCPP 撰寫 P
