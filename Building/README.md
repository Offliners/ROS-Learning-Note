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

將`source ~/catkin_ws/devel/setup.bash`貼在上去

![bashrc](https://github.com/Offliners/ROS_Learning_Note/blob/main/Building/bashrc.PNG)
