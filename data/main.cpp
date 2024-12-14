#include <thread>
#include <pcl/io/pcd_io.h>
#include <pcl/visualization/pcl_visualizer.h>
using PointXYZRGB = pcl::PointXYZRGB;
using CloudXYZRGB = pcl::PointCloud<PointXYZRGB>;
using PCLVisualizer = pcl::visualization::PCLVisualizer;

void visualize(const CloudXYZRGB::ConstPtr cloud) {

	PCLVisualizer::Ptr vis(new PCLVisualizer);
	vis->addPointCloud(cloud);

	while (!vis->wasStopped()) {

		vis->spinOnce(100);
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
}

int main() {

	CloudXYZRGB::Ptr cloud(new CloudXYZRGB);
	pcl::io::loadPCDFile("D:/somewhere/sample_data.pcd", *cloud);

	visualize(cloud);

	return 0;
}