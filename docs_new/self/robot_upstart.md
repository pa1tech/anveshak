---
title: ROS Robot Upstart

---
# All-about-Robot_Upstart-[ROS]

Assists with creating simple platform-specific jobs to start your robot’s ROS launch files when its PC powers up.

[ROS documentation](http://docs.ros.org/jade/api/robot_upstart/html/)

## Command Line Usage

* Install Script

`rosrun robot_upstart install path_to_launch_file/autorun.launch --job myrobot --setup path_to_source_file/devel/setup.bash`

Additional arguments like ROS master URI can also be given - [check here](http://docs.ros.org/jade/api/robot_upstart/html/install.html)

* Uninstall command

`rosrun robot_upstart uninstall myrobot`

## [Python API](http://docs.ros.org/jade/api/robot_upstart/html/jobs.html) example

```python
import robot_upstart
j = robot_upstart.Job(master_uri='0.0.0.0:11311') 	# to set master_uri  
j.add(package="/path_to_ros-package_folder", filename="launch/file.launch")
j.install()
#j.unistall()	# to unistall the setup
```

