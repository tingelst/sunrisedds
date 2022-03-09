uint8 SMART_SERVO_JOINT_POSITION = 0
uint8 SMART_SERVO_JOINT_POSITION_VELOCITY = 1
uint8 SMART_SERVO_CARTESIAN_POSE = 2
uint8 type 

JointQuantity joint_position 
JointQuantity joint_velocity 
geometry_msgs/Pose cartesian_pose 

JointQuantity joint_velocity_rel # Maximum value of the axis velocity in the machine data
JointQuantity joint_acceleration_rel # Maximum value of the axis acceleration in the machine data
