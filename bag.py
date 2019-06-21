import rosbag
bag = rosbag.Bag('2019-06-09-01-38-30.bag')
for topic, msg, t in bag.read_messages():
	print msg
bag.close()

