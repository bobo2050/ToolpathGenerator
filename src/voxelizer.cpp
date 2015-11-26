#include <iostream>
#include <cvmlcpp/base/Matrix>
#include <cvmlcpp/volume/Geometry>
#include <cvmlcpp/volume/VolumeIO>
#include <cvmlcpp/volume/Voxelizer>

using namespace cvmlcpp;

int main(int argc, char *argv[])
{
	
	Matrix<int, 3u> voxels;
	Geometry<float> geometry;

	std::cerr<<"\n";
	std::cerr<<"\nReading File...";
	readSTL(geometry, argv[1]);
	geometry.scaleTo(300);
	
	voxelize(geometry, voxels);
	
	std::cerr<<"\nWriting to file...";
	writeVoxels(voxels, "voxels.txt", false);
	
	std::tr1::array<std::size_t, 3>::const_iterator i = voxels.extents();
	int xMax = (*i);
	i++;
	int yMax = (*i);
	i++;
	int zMax = (*i);
	
	int l=0;
	std::cout<<xMax<<" "<<yMax<<" "<<zMax;
	for(Matrix<int,3u>::iterator iter = voxels.begin(); iter != voxels.end();l++){
				std::cout<<"\n\n\n";
				for(int m =0; m<yMax; m++){
						std::cout<<"\n";
						for(int n = 0; n<zMax; n++){
								std::cerr<<"\nWriting voxel no. "<<l<<" of "<<(xMax)*(yMax)*(zMax);
								l++;
								std::cout<<(*iter);
								iter++;
						}
				}
		
	}
	return 0;
}
