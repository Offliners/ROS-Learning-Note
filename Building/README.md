# Building ROS Work Space

## 建立 Work Space
啟動ROS
```shell
roscore
```

要使用ROS時要確認roscore是開啟的

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

![roscd](https://github.com/Offliners/ROS_Learning_Note/blob/main/Building/roscd.PNG)

## 使用 ROSCPP 撰寫 Publisher
安裝`sublime text 3`來撰寫ROSCPP
```shell
sudo add-apt-repository ppa:webupd8team/sublime-text-3
sudo apt-get update
sudo apt-get install sublime-text-installer
```

接著前往`test/scr`中來撰寫程式
* roscpp_publisher.cpp
```shell
#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include <iostream>

int main(int argc, char **argv)
{
	ros::init(argc, argv, "demo_topic_publisher");
	ros::NodeHandle node_obj;
	ros::Publisher number_publisher = node_obj.advertise<std_msgs::Int32>("/number", 10);
	ros::Rate loop_rate(10);

	int count = 0;
	while(ros::ok())
	{
		std_msgs::Int32 msg;
		msg.data = count;

		ROS_INFO("%d", msg.data);
		number_publisher.publish(msg);
		ros::spinOnce();
		loop_rate.sleep();
		count++;
	}

	return 0;
}
```
[code](roscpp_publisher.cpp)
