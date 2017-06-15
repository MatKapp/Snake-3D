// This is a .c file for the model: walec2


const int walecVertices = 372;

const float walecPositions[1116] = 
{
0, 0.5, 0.5, 
0.097545, 0.490393, -0.5, 
0, 0.5, -0.5, 
0.097545, 0.490393, 0.5, 
0.191342, 0.46194, -0.5, 
0.097545, 0.490393, -0.5, 
0.191342, 0.46194, 0.5, 
0.277785, 0.415735, -0.5, 
0.191342, 0.46194, -0.5, 
0.277785, 0.415735, 0.5, 
0.353553, 0.353553, -0.5, 
0.277785, 0.415735, -0.5, 
0.353553, 0.353553, 0.5, 
0.415735, 0.277785, -0.5, 
0.353553, 0.353553, -0.5, 
0.415735, 0.277785, 0.5, 
0.46194, 0.191342, -0.5, 
0.415735, 0.277785, -0.5, 
0.46194, 0.191342, 0.5, 
0.490393, 0.097545, -0.5, 
0.46194, 0.191342, -0.5, 
0.490393, 0.097545, 0.5, 
0.5, 0, -0.5, 
0.490393, 0.097545, -0.5, 
0.5, 0, 0.5, 
0.490393, -0.097545, -0.5, 
0.5, 0, -0.5, 
0.490393, -0.097545, 0.5, 
0.46194, -0.191342, -0.5, 
0.490393, -0.097545, -0.5, 
0.46194, -0.191342, 0.5, 
0.415735, -0.277785, -0.5, 
0.46194, -0.191342, -0.5, 
0.415735, -0.277785, -0.5, 
0.353553, -0.353553, 0.5, 
0.353553, -0.353553, -0.5, 
0.353553, -0.353553, 0.5, 
0.277785, -0.415735, -0.5, 
0.353553, -0.353553, -0.5, 
0.277785, -0.415735, 0.5, 
0.191342, -0.46194, -0.5, 
0.277785, -0.415735, -0.5, 
0.191342, -0.46194, 0.5, 
0.097545, -0.490393, -0.5, 
0.191342, -0.46194, -0.5, 
0.097545, -0.490393, 0.5, 
-0, -0.5, -0.5, 
0.097545, -0.490393, -0.5, 
-0, -0.5, 0.5, 
-0.097545, -0.490393, -0.5, 
-0, -0.5, -0.5, 
-0.097545, -0.490393, 0.5, 
-0.191342, -0.46194, -0.5, 
-0.097545, -0.490393, -0.5, 
-0.191342, -0.46194, 0.5, 
-0.277785, -0.415735, -0.5, 
-0.191342, -0.46194, -0.5, 
-0.277785, -0.415735, 0.5, 
-0.353554, -0.353553, -0.5, 
-0.277785, -0.415735, -0.5, 
-0.353554, -0.353553, 0.5, 
-0.415735, -0.277785, -0.5, 
-0.353554, -0.353553, -0.5, 
-0.415735, -0.277785, 0.5, 
-0.46194, -0.191341, -0.5, 
-0.415735, -0.277785, -0.5, 
-0.46194, -0.191341, 0.5, 
-0.490393, -0.097545, -0.5, 
-0.46194, -0.191341, -0.5, 
-0.490393, -0.097545, 0.5, 
-0.5, 1e-006, -0.5, 
-0.490393, -0.097545, -0.5, 
-0.5, 0, 0.5, 
-0.490393, 0.097546, -0.5, 
-0.5, 1e-006, -0.5, 
-0.490393, 0.097546, 0.5, 
-0.46194, 0.191342, -0.5, 
-0.490393, 0.097546, -0.5, 
-0.46194, 0.191342, 0.5, 
-0.415734, 0.277786, -0.5, 
-0.46194, 0.191342, -0.5, 
-0.415734, 0.277786, 0.5, 
-0.353553, 0.353554, -0.5, 
-0.415734, 0.277786, -0.5, 
-0.353553, 0.353554, 0.5, 
-0.277785, 0.415735, -0.5, 
-0.353553, 0.353554, -0.5, 
-0.277785, 0.415735, 0.5, 
-0.191341, 0.46194, -0.5, 
-0.277785, 0.415735, -0.5, 
-0.191342, -0.46194, 0.5, 
0.46194, -0.191342, 0.5, 
-0.46194, 0.191342, 0.5, 
-0.191341, 0.46194, 0.5, 
-0.097544, 0.490393, -0.5, 
-0.191341, 0.46194, -0.5, 
-0.097544, 0.490393, 0.5, 
0, 0.5, -0.5, 
-0.097544, 0.490393, -0.5, 
0.097545, -0.490393, -0.5, 
-0.490393, -0.097545, -0.5, 
0.490393, 0.097545, -0.5, 
0, 0.5, 0.5, 
0.097545, 0.490393, 0.5, 
0.097545, 0.490393, -0.5, 
0.097545, 0.490393, 0.5, 
0.191342, 0.46194, 0.5, 
0.191342, 0.46194, -0.5, 
0.191342, 0.46194, 0.5, 
0.277785, 0.415735, 0.5, 
0.277785, 0.415735, -0.5, 
0.277785, 0.415735, 0.5, 
0.353553, 0.353553, 0.5, 
0.353553, 0.353553, -0.5, 
0.353553, 0.353553, 0.5, 
0.415735, 0.277785, 0.5, 
0.415735, 0.277785, -0.5, 
0.415735, 0.277785, 0.5, 
0.46194, 0.191342, 0.5, 
0.46194, 0.191342, -0.5, 
0.46194, 0.191342, 0.5, 
0.490393, 0.097545, 0.5, 
0.490393, 0.097545, -0.5, 
0.490393, 0.097545, 0.5, 
0.5, 0, 0.5, 
0.5, 0, -0.5, 
0.5, 0, 0.5, 
0.490393, -0.097545, 0.5, 
0.490393, -0.097545, -0.5, 
0.490393, -0.097545, 0.5, 
0.46194, -0.191342, 0.5, 
0.46194, -0.191342, -0.5, 
0.46194, -0.191342, 0.5, 
0.415735, -0.277785, 0.5, 
0.415735, -0.277785, -0.5, 
0.415735, -0.277785, -0.5, 
0.415735, -0.277785, 0.5, 
0.353553, -0.353553, 0.5, 
0.353553, -0.353553, 0.5, 
0.277785, -0.415735, 0.5, 
0.277785, -0.415735, -0.5, 
0.277785, -0.415735, 0.5, 
0.191342, -0.46194, 0.5, 
0.191342, -0.46194, -0.5, 
0.191342, -0.46194, 0.5, 
0.097545, -0.490393, 0.5, 
0.097545, -0.490393, -0.5, 
0.097545, -0.490393, 0.5, 
-0, -0.5, 0.5, 
-0, -0.5, -0.5, 
-0, -0.5, 0.5, 
-0.097545, -0.490393, 0.5, 
-0.097545, -0.490393, -0.5, 
-0.097545, -0.490393, 0.5, 
-0.191342, -0.46194, 0.5, 
-0.191342, -0.46194, -0.5, 
-0.191342, -0.46194, 0.5, 
-0.277785, -0.415735, 0.5, 
-0.277785, -0.415735, -0.5, 
-0.277785, -0.415735, 0.5, 
-0.353554, -0.353553, 0.5, 
-0.353554, -0.353553, -0.5, 
-0.353554, -0.353553, 0.5, 
-0.415735, -0.277785, 0.5, 
-0.415735, -0.277785, -0.5, 
-0.415735, -0.277785, 0.5, 
-0.46194, -0.191341, 0.5, 
-0.46194, -0.191341, -0.5, 
-0.46194, -0.191341, 0.5, 
-0.490393, -0.097545, 0.5, 
-0.490393, -0.097545, -0.5, 
-0.490393, -0.097545, 0.5, 
-0.5, 0, 0.5, 
-0.5, 1e-006, -0.5, 
-0.5, 0, 0.5, 
-0.490393, 0.097546, 0.5, 
-0.490393, 0.097546, -0.5, 
-0.490393, 0.097546, 0.5, 
-0.46194, 0.191342, 0.5, 
-0.46194, 0.191342, -0.5, 
-0.46194, 0.191342, 0.5, 
-0.415734, 0.277786, 0.5, 
-0.415734, 0.277786, -0.5, 
-0.415734, 0.277786, 0.5, 
-0.353553, 0.353554, 0.5, 
-0.353553, 0.353554, -0.5, 
-0.353553, 0.353554, 0.5, 
-0.277785, 0.415735, 0.5, 
-0.277785, 0.415735, -0.5, 
-0.277785, 0.415735, 0.5, 
-0.191341, 0.46194, 0.5, 
-0.191341, 0.46194, -0.5, 
0.191342, 0.46194, 0.5, 
0.097545, 0.490393, 0.5, 
0, 0.5, 0.5, 
0, 0.5, 0.5, 
-0.097544, 0.490393, 0.5, 
0.191342, 0.46194, 0.5, 
-0.191341, 0.46194, 0.5, 
-0.277785, 0.415735, 0.5, 
-0.353553, 0.353554, 0.5, 
-0.353553, 0.353554, 0.5, 
-0.415734, 0.277786, 0.5, 
-0.46194, 0.191342, 0.5, 
-0.46194, 0.191342, 0.5, 
-0.490393, 0.097546, 0.5, 
-0.5, 0, 0.5, 
-0.5, 0, 0.5, 
-0.490393, -0.097545, 0.5, 
-0.46194, 0.191342, 0.5, 
-0.46194, -0.191341, 0.5, 
-0.415735, -0.277785, 0.5, 
-0.353554, -0.353553, 0.5, 
-0.353554, -0.353553, 0.5, 
-0.277785, -0.415735, 0.5, 
-0.191342, -0.46194, 0.5, 
-0.191342, -0.46194, 0.5, 
-0.097545, -0.490393, 0.5, 
-0, -0.5, 0.5, 
-0, -0.5, 0.5, 
0.097545, -0.490393, 0.5, 
0.191342, -0.46194, 0.5, 
0.191342, -0.46194, 0.5, 
0.277785, -0.415735, 0.5, 
0.353553, -0.353553, 0.5, 
0.353553, -0.353553, 0.5, 
0.415735, -0.277785, 0.5, 
0.46194, -0.191342, 0.5, 
0.46194, -0.191342, 0.5, 
0.490393, -0.097545, 0.5, 
0.5, 0, 0.5, 
0.5, 0, 0.5, 
0.490393, 0.097545, 0.5, 
0.46194, -0.191342, 0.5, 
0.46194, 0.191342, 0.5, 
0.415735, 0.277785, 0.5, 
0.353553, 0.353553, 0.5, 
0.353553, 0.353553, 0.5, 
0.277785, 0.415735, 0.5, 
0.191342, 0.46194, 0.5, 
0.191342, 0.46194, 0.5, 
-0.097544, 0.490393, 0.5, 
-0.191341, 0.46194, 0.5, 
-0.191341, 0.46194, 0.5, 
-0.353553, 0.353554, 0.5, 
-0.46194, 0.191342, 0.5, 
-0.46194, 0.191342, 0.5, 
-0.490393, -0.097545, 0.5, 
-0.46194, -0.191341, 0.5, 
-0.46194, -0.191341, 0.5, 
-0.353554, -0.353553, 0.5, 
-0.191342, -0.46194, 0.5, 
-0.191342, -0.46194, 0.5, 
-0, -0.5, 0.5, 
0.46194, -0.191342, 0.5, 
0.191342, -0.46194, 0.5, 
0.353553, -0.353553, 0.5, 
0.46194, -0.191342, 0.5, 
0.46194, -0.191342, 0.5, 
0.490393, 0.097545, 0.5, 
0.46194, 0.191342, 0.5, 
0.46194, 0.191342, 0.5, 
0.353553, 0.353553, 0.5, 
0.191342, 0.46194, 0.5, 
0.191342, 0.46194, 0.5, 
-0.191341, 0.46194, 0.5, 
-0.46194, 0.191342, 0.5, 
-0.46194, 0.191342, 0.5, 
-0.46194, -0.191341, 0.5, 
-0.191342, -0.46194, 0.5, 
-0, -0.5, 0.5, 
0.191342, -0.46194, 0.5, 
0.46194, -0.191342, 0.5, 
0.46194, -0.191342, 0.5, 
0.46194, 0.191342, 0.5, 
0.191342, 0.46194, 0.5, 
0.191342, 0.46194, 0.5, 
-0.46194, 0.191342, 0.5, 
0.46194, -0.191342, 0.5, 
-0.191341, 0.46194, 0.5, 
-0.097544, 0.490393, 0.5, 
-0.097544, 0.490393, -0.5, 
-0.097544, 0.490393, 0.5, 
0, 0.5, 0.5, 
0, 0.5, -0.5, 
-0.097544, 0.490393, -0.5, 
0, 0.5, -0.5, 
0.097545, 0.490393, -0.5, 
0.097545, 0.490393, -0.5, 
0.191342, 0.46194, -0.5, 
0.277785, 0.415735, -0.5, 
0.277785, 0.415735, -0.5, 
0.353553, 0.353553, -0.5, 
0.415735, 0.277785, -0.5, 
0.415735, 0.277785, -0.5, 
0.46194, 0.191342, -0.5, 
0.277785, 0.415735, -0.5, 
0.490393, 0.097545, -0.5, 
0.5, 0, -0.5, 
0.490393, -0.097545, -0.5, 
0.490393, -0.097545, -0.5, 
0.46194, -0.191342, -0.5, 
0.490393, 0.097545, -0.5, 
0.415735, -0.277785, -0.5, 
0.353553, -0.353553, -0.5, 
0.097545, -0.490393, -0.5, 
0.277785, -0.415735, -0.5, 
0.191342, -0.46194, -0.5, 
0.097545, -0.490393, -0.5, 
0.097545, -0.490393, -0.5, 
-0, -0.5, -0.5, 
-0.097545, -0.490393, -0.5, 
-0.097545, -0.490393, -0.5, 
-0.191342, -0.46194, -0.5, 
-0.277785, -0.415735, -0.5, 
-0.277785, -0.415735, -0.5, 
-0.353554, -0.353553, -0.5, 
-0.415735, -0.277785, -0.5, 
-0.415735, -0.277785, -0.5, 
-0.46194, -0.191341, -0.5, 
-0.490393, -0.097545, -0.5, 
-0.490393, -0.097545, -0.5, 
-0.5, 1e-006, -0.5, 
-0.490393, 0.097546, -0.5, 
-0.490393, 0.097546, -0.5, 
-0.46194, 0.191342, -0.5, 
-0.415734, 0.277786, -0.5, 
-0.415734, 0.277786, -0.5, 
-0.353553, 0.353554, -0.5, 
-0.097544, 0.490393, -0.5, 
-0.277785, 0.415735, -0.5, 
-0.191341, 0.46194, -0.5, 
-0.097544, 0.490393, -0.5, 
-0.097544, 0.490393, -0.5, 
0.097545, 0.490393, -0.5, 
0.490393, 0.097545, -0.5, 
0.277785, 0.415735, -0.5, 
0.46194, 0.191342, -0.5, 
0.490393, 0.097545, -0.5, 
0.490393, 0.097545, -0.5, 
0.46194, -0.191342, -0.5, 
0.415735, -0.277785, -0.5, 
0.353553, -0.353553, -0.5, 
0.277785, -0.415735, -0.5, 
0.097545, -0.490393, -0.5, 
0.097545, -0.490393, -0.5, 
-0.097545, -0.490393, -0.5, 
-0.490393, -0.097545, -0.5, 
-0.277785, -0.415735, -0.5, 
-0.415735, -0.277785, -0.5, 
-0.490393, -0.097545, -0.5, 
-0.490393, -0.097545, -0.5, 
-0.490393, 0.097546, -0.5, 
-0.097544, 0.490393, -0.5, 
-0.353553, 0.353554, -0.5, 
-0.277785, 0.415735, -0.5, 
-0.097544, 0.490393, -0.5, 
0.097545, 0.490393, -0.5, 
0.277785, 0.415735, -0.5, 
0.490393, 0.097545, -0.5, 
0.490393, 0.097545, -0.5, 
0.415735, -0.277785, -0.5, 
0.097545, -0.490393, -0.5, 
-0.097545, -0.490393, -0.5, 
-0.277785, -0.415735, -0.5, 
-0.490393, -0.097545, -0.5, 
-0.490393, 0.097546, -0.5, 
-0.415734, 0.277786, -0.5, 
-0.097544, 0.490393, -0.5, 
-0.097544, 0.490393, -0.5, 
0.490393, 0.097545, -0.5, 
-0.490393, -0.097545, -0.5, 
};

const float walecTexels[744] = 
{
0.5955, 0.3344, 
0.5547, 0, 
0.5955, 0, 
0.5547, 0.3344, 
0.5147, 0, 
0.5547, 0, 
0.5147, 0.3344, 
0.477, 0, 
0.5147, 0, 
0.477, 0.3344, 
0.4431, 0, 
0.477, 0, 
0.4431, 0.3344, 
0.4142, 0, 
0.4431, 0, 
0.264, 1, 
0.2301, 0.6656, 
0.264, 0.6656, 
0.2301, 1, 
0.1924, 0.6656, 
0.2301, 0.6656, 
0.1924, 1, 
0.1524, 0.6656, 
0.1924, 0.6656, 
0.1524, 1, 
0.1116, 0.6656, 
0.1524, 0.6656, 
0.1116, 1, 
0.0716, 0.6656, 
0.1116, 0.6656, 
0.0716, 1, 
0.0339, 0.6656, 
0.0716, 0.6656, 
0.0339, 0.6656, 
0, 1, 
0, 0.6656, 
0.4142, 0.3344, 
0.4481, 0.6688, 
0.4142, 0.6688, 
0.4481, 0.3344, 
0.4858, 0.6688, 
0.4481, 0.6688, 
0.4858, 0.3344, 
0.5258, 0.6688, 
0.4858, 0.6688, 
0.5258, 0.3344, 
0.5666, 0.6688, 
0.5258, 0.6688, 
0.5666, 0.3344, 
0.6066, 0.6688, 
0.5666, 0.6688, 
0.6066, 0.3344, 
0.6443, 0.6688, 
0.6066, 0.6688, 
0.6443, 0.3344, 
0.6783, 0.6688, 
0.6443, 0.6688, 
0.6783, 0.3344, 
0.7071, 0.6688, 
0.6783, 0.6688, 
0.7071, 0.3344, 
0.741, 0.6688, 
0.7071, 0.6688, 
0.741, 0.3344, 
0.7787, 0.6688, 
0.741, 0.6688, 
0.7787, 0.3344, 
0.8187, 0.6688, 
0.7787, 0.6688, 
0.8187, 0.3344, 
0.8595, 0.6688, 
0.8187, 0.6688, 
0.8595, 0.3344, 
0.8995, 0.6688, 
0.8595, 0.6688, 
0.8995, 0.3344, 
0.9372, 0.6688, 
0.8995, 0.6688, 
0.9372, 0.3344, 
0.9712, 0.6688, 
0.9372, 0.6688, 
0.9712, 0.3344, 
1, 0.6688, 
0.9712, 0.6688, 
0.736, 0.3344, 
0.7071, 0, 
0.736, 0, 
0.7071, 0.3344, 
0.6732, 0, 
0.7071, 0, 
0.1867, 0.3328, 
0.4142, 0.4828, 
0, 0.5156, 
0.6732, 0.3344, 
0.6355, 0, 
0.6732, 0, 
0.6355, 0.3344, 
0.5955, 0, 
0.6355, 0, 
0.4063, 0.1179, 
0.2675, 0.3264, 
0.1467, 0.0064, 
0.5955, 0.3344, 
0.5547, 0.3344, 
0.5547, 0, 
0.5547, 0.3344, 
0.5147, 0.3344, 
0.5147, 0, 
0.5147, 0.3344, 
0.477, 0.3344, 
0.477, 0, 
0.477, 0.3344, 
0.4431, 0.3344, 
0.4431, 0, 
0.4431, 0.3344, 
0.4142, 0.3344, 
0.4142, 0, 
0.264, 1, 
0.2301, 1, 
0.2301, 0.6656, 
0.2301, 1, 
0.1924, 1, 
0.1924, 0.6656, 
0.1924, 1, 
0.1524, 1, 
0.1524, 0.6656, 
0.1524, 1, 
0.1116, 1, 
0.1116, 0.6656, 
0.1116, 1, 
0.0716, 1, 
0.0716, 0.6656, 
0.0716, 1, 
0.0339, 1, 
0.0339, 0.6656, 
0.0339, 0.6656, 
0.0339, 1, 
0, 1, 
0.4142, 0.3344, 
0.4481, 0.3344, 
0.4481, 0.6688, 
0.4481, 0.3344, 
0.4858, 0.3344, 
0.4858, 0.6688, 
0.4858, 0.3344, 
0.5258, 0.3344, 
0.5258, 0.6688, 
0.5258, 0.3344, 
0.5666, 0.3344, 
0.5666, 0.6688, 
0.5666, 0.3344, 
0.6066, 0.3344, 
0.6066, 0.6688, 
0.6066, 0.3344, 
0.6443, 0.3344, 
0.6443, 0.6688, 
0.6443, 0.3344, 
0.6783, 0.3344, 
0.6783, 0.6688, 
0.6783, 0.3344, 
0.7071, 0.3344, 
0.7071, 0.6688, 
0.7071, 0.3344, 
0.741, 0.3344, 
0.741, 0.6688, 
0.741, 0.3344, 
0.7787, 0.3344, 
0.7787, 0.6688, 
0.7787, 0.3344, 
0.8187, 0.3344, 
0.8187, 0.6688, 
0.8187, 0.3344, 
0.8595, 0.3344, 
0.8595, 0.6688, 
0.8595, 0.3344, 
0.8995, 0.3344, 
0.8995, 0.6688, 
0.8995, 0.3344, 
0.9372, 0.3344, 
0.9372, 0.6688, 
0.9372, 0.3344, 
0.9712, 0.3344, 
0.9712, 0.6688, 
0.9712, 0.3344, 
1, 0.3344, 
1, 0.6688, 
0.736, 0.3344, 
0.7071, 0.3344, 
0.7071, 0, 
0.7071, 0.3344, 
0.6732, 0.3344, 
0.6732, 0, 
0.2275, 0.6656, 
0.1867, 0.6656, 
0.1467, 0.6592, 
0.1467, 0.6592, 
0.109, 0.6467, 
0.2275, 0.6656, 
0.0751, 0.6284, 
0.0462, 0.6053, 
0.0236, 0.578, 
0.0236, 0.578, 
0.008, 0.5477, 
0, 0.5156, 
0, 0.5156, 
0, 0.4828, 
0.008, 0.4507, 
0.008, 0.4507, 
0.0236, 0.4204, 
0, 0.5156, 
0.0462, 0.3931, 
0.0751, 0.3699, 
0.109, 0.3517, 
0.109, 0.3517, 
0.1467, 0.3392, 
0.1867, 0.3328, 
0.1867, 0.3328, 
0.2275, 0.3328, 
0.2675, 0.3392, 
0.2675, 0.3392, 
0.3052, 0.3517, 
0.3391, 0.3699, 
0.3391, 0.3699, 
0.368, 0.3931, 
0.3906, 0.4204, 
0.3906, 0.4204, 
0.4063, 0.4507, 
0.4142, 0.4828, 
0.4142, 0.4828, 
0.4142, 0.5156, 
0.4063, 0.5477, 
0.4063, 0.5477, 
0.3906, 0.578, 
0.4142, 0.4828, 
0.368, 0.6053, 
0.3391, 0.6284, 
0.3052, 0.6467, 
0.3052, 0.6467, 
0.2675, 0.6592, 
0.2275, 0.6656, 
0.2275, 0.6656, 
0.109, 0.6467, 
0.0751, 0.6284, 
0.0751, 0.6284, 
0.0236, 0.578, 
0, 0.5156, 
0, 0.5156, 
0.0236, 0.4204, 
0.0462, 0.3931, 
0.0462, 0.3931, 
0.109, 0.3517, 
0.1867, 0.3328, 
0.1867, 0.3328, 
0.2675, 0.3392, 
0.4142, 0.4828, 
0.3391, 0.3699, 
0.3906, 0.4204, 
0.4142, 0.4828, 
0.4142, 0.4828, 
0.3906, 0.578, 
0.368, 0.6053, 
0.368, 0.6053, 
0.3052, 0.6467, 
0.2275, 0.6656, 
0.2275, 0.6656, 
0.0751, 0.6284, 
0, 0.5156, 
0, 0.5156, 
0.0462, 0.3931, 
0.1867, 0.3328, 
0.2675, 0.3392, 
0.3391, 0.3699, 
0.4142, 0.4828, 
0.4142, 0.4828, 
0.368, 0.6053, 
0.2275, 0.6656, 
0.2275, 0.6656, 
0, 0.5156, 
0.4142, 0.4828, 
0.6732, 0.3344, 
0.6355, 0.3344, 
0.6355, 0, 
0.6355, 0.3344, 
0.5955, 0.3344, 
0.5955, 0, 
0.008, 0.2149, 
0, 0.1828, 
0, 0.15, 
0, 0.15, 
0.008, 0.1179, 
0.0236, 0.0876, 
0.0236, 0.0876, 
0.0462, 0.0603, 
0.0751, 0.0371, 
0.0751, 0.0371, 
0.109, 0.0189, 
0.0236, 0.0876, 
0.1467, 0.0064, 
0.1867, 0, 
0.2275, 0, 
0.2275, 0, 
0.2675, 0.0064, 
0.1467, 0.0064, 
0.3052, 0.0189, 
0.3391, 0.0371, 
0.4063, 0.1179, 
0.368, 0.0603, 
0.3906, 0.0876, 
0.4063, 0.1179, 
0.4063, 0.1179, 
0.4142, 0.15, 
0.4142, 0.1828, 
0.4142, 0.1828, 
0.4063, 0.2149, 
0.3906, 0.2452, 
0.3906, 0.2452, 
0.368, 0.2725, 
0.3391, 0.2956, 
0.3391, 0.2956, 
0.3052, 0.3139, 
0.2675, 0.3264, 
0.2675, 0.3264, 
0.2275, 0.3328, 
0.1867, 0.3328, 
0.1867, 0.3328, 
0.1467, 0.3264, 
0.109, 0.3139, 
0.109, 0.3139, 
0.0751, 0.2956, 
0.008, 0.2149, 
0.0462, 0.2725, 
0.0236, 0.2452, 
0.008, 0.2149, 
0.008, 0.2149, 
0, 0.15, 
0.1467, 0.0064, 
0.0236, 0.0876, 
0.109, 0.0189, 
0.1467, 0.0064, 
0.1467, 0.0064, 
0.2675, 0.0064, 
0.3052, 0.0189, 
0.3391, 0.0371, 
0.368, 0.0603, 
0.4063, 0.1179, 
0.4063, 0.1179, 
0.4142, 0.1828, 
0.2675, 0.3264, 
0.3906, 0.2452, 
0.3391, 0.2956, 
0.2675, 0.3264, 
0.2675, 0.3264, 
0.1867, 0.3328, 
0.008, 0.2149, 
0.0751, 0.2956, 
0.0462, 0.2725, 
0.008, 0.2149, 
0, 0.15, 
0.0236, 0.0876, 
0.1467, 0.0064, 
0.1467, 0.0064, 
0.3052, 0.0189, 
0.4063, 0.1179, 
0.4142, 0.1828, 
0.3906, 0.2452, 
0.2675, 0.3264, 
0.1867, 0.3328, 
0.109, 0.3139, 
0.008, 0.2149, 
0.008, 0.2149, 
0.1467, 0.0064, 
0.2675, 0.3264, 
};

const float walecNormals[1116] = 
{
0.098, 0.9952, 0, 
0.098, 0.9952, 0, 
0.098, 0.9952, 0, 
0.2903, 0.9569, 0, 
0.2903, 0.9569, 0, 
0.2903, 0.9569, 0, 
0.4714, 0.8819, 0, 
0.4714, 0.8819, 0, 
0.4714, 0.8819, 0, 
0.6344, 0.773, 0, 
0.6344, 0.773, 0, 
0.6344, 0.773, 0, 
0.773, 0.6344, 0, 
0.773, 0.6344, 0, 
0.773, 0.6344, 0, 
0.8819, 0.4714, 0, 
0.8819, 0.4714, 0, 
0.8819, 0.4714, 0, 
0.9569, 0.2903, 0, 
0.9569, 0.2903, 0, 
0.9569, 0.2903, 0, 
0.9952, 0.098, 0, 
0.9952, 0.098, 0, 
0.9952, 0.098, 0, 
0.9952, -0.098, -0, 
0.9952, -0.098, -0, 
0.9952, -0.098, -0, 
0.9569, -0.2903, -0, 
0.9569, -0.2903, -0, 
0.9569, -0.2903, -0, 
0.8819, -0.4714, 0, 
0.8819, -0.4714, 0, 
0.8819, -0.4714, 0, 
0.773, -0.6344, -0, 
0.773, -0.6344, -0, 
0.773, -0.6344, -0, 
0.6344, -0.773, 0, 
0.6344, -0.773, 0, 
0.6344, -0.773, 0, 
0.4714, -0.8819, 0, 
0.4714, -0.8819, 0, 
0.4714, -0.8819, 0, 
0.2903, -0.9569, -0, 
0.2903, -0.9569, -0, 
0.2903, -0.9569, -0, 
0.098, -0.9952, -0, 
0.098, -0.9952, -0, 
0.098, -0.9952, -0, 
-0.098, -0.9952, 0, 
-0.098, -0.9952, 0, 
-0.098, -0.9952, 0, 
-0.2903, -0.9569, -0, 
-0.2903, -0.9569, -0, 
-0.2903, -0.9569, -0, 
-0.4714, -0.8819, -0, 
-0.4714, -0.8819, -0, 
-0.4714, -0.8819, -0, 
-0.6344, -0.773, -0, 
-0.6344, -0.773, -0, 
-0.6344, -0.773, -0, 
-0.773, -0.6344, -0, 
-0.773, -0.6344, -0, 
-0.773, -0.6344, -0, 
-0.8819, -0.4714, -0, 
-0.8819, -0.4714, -0, 
-0.8819, -0.4714, -0, 
-0.9569, -0.2903, -0, 
-0.9569, -0.2903, -0, 
-0.9569, -0.2903, -0, 
-0.9952, -0.098, -0, 
-0.9952, -0.098, -0, 
-0.9952, -0.098, -0, 
-0.9952, 0.098, 0, 
-0.9952, 0.098, 0, 
-0.9952, 0.098, 0, 
-0.9569, 0.2903, 0, 
-0.9569, 0.2903, 0, 
-0.9569, 0.2903, 0, 
-0.8819, 0.4714, 0, 
-0.8819, 0.4714, 0, 
-0.8819, 0.4714, 0, 
-0.773, 0.6344, 0, 
-0.773, 0.6344, 0, 
-0.773, 0.6344, 0, 
-0.6344, 0.773, 0, 
-0.6344, 0.773, 0, 
-0.6344, 0.773, 0, 
-0.4714, 0.8819, 0, 
-0.4714, 0.8819, 0, 
-0.4714, 0.8819, 0, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
-0.2903, 0.9569, 0, 
-0.2903, 0.9569, 0, 
-0.2903, 0.9569, 0, 
-0.098, 0.9952, 0, 
-0.098, 0.9952, 0, 
-0.098, 0.9952, 0, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0.098, 0.9952, 0, 
0.098, 0.9952, 0, 
0.098, 0.9952, 0, 
0.2903, 0.9569, 0, 
0.2903, 0.9569, 0, 
0.2903, 0.9569, 0, 
0.4714, 0.8819, 0, 
0.4714, 0.8819, 0, 
0.4714, 0.8819, 0, 
0.6344, 0.773, 0, 
0.6344, 0.773, 0, 
0.6344, 0.773, 0, 
0.773, 0.6344, 0, 
0.773, 0.6344, 0, 
0.773, 0.6344, 0, 
0.8819, 0.4714, 0, 
0.8819, 0.4714, 0, 
0.8819, 0.4714, 0, 
0.9569, 0.2903, 0, 
0.9569, 0.2903, 0, 
0.9569, 0.2903, 0, 
0.9952, 0.098, 0, 
0.9952, 0.098, 0, 
0.9952, 0.098, 0, 
0.9952, -0.098, -0, 
0.9952, -0.098, -0, 
0.9952, -0.098, -0, 
0.9569, -0.2903, -0, 
0.9569, -0.2903, -0, 
0.9569, -0.2903, -0, 
0.8819, -0.4714, 0, 
0.8819, -0.4714, 0, 
0.8819, -0.4714, 0, 
0.773, -0.6344, -0, 
0.773, -0.6344, -0, 
0.773, -0.6344, -0, 
0.6344, -0.773, 0, 
0.6344, -0.773, 0, 
0.6344, -0.773, 0, 
0.4714, -0.8819, 0, 
0.4714, -0.8819, 0, 
0.4714, -0.8819, 0, 
0.2903, -0.9569, -0, 
0.2903, -0.9569, -0, 
0.2903, -0.9569, -0, 
0.098, -0.9952, -0, 
0.098, -0.9952, -0, 
0.098, -0.9952, -0, 
-0.098, -0.9952, 0, 
-0.098, -0.9952, 0, 
-0.098, -0.9952, 0, 
-0.2903, -0.9569, -0, 
-0.2903, -0.9569, -0, 
-0.2903, -0.9569, -0, 
-0.4714, -0.8819, -0, 
-0.4714, -0.8819, -0, 
-0.4714, -0.8819, -0, 
-0.6344, -0.773, -0, 
-0.6344, -0.773, -0, 
-0.6344, -0.773, -0, 
-0.773, -0.6344, -0, 
-0.773, -0.6344, -0, 
-0.773, -0.6344, -0, 
-0.8819, -0.4714, -0, 
-0.8819, -0.4714, -0, 
-0.8819, -0.4714, -0, 
-0.9569, -0.2903, -0, 
-0.9569, -0.2903, -0, 
-0.9569, -0.2903, -0, 
-0.9952, -0.098, -0, 
-0.9952, -0.098, -0, 
-0.9952, -0.098, -0, 
-0.9952, 0.098, 0, 
-0.9952, 0.098, 0, 
-0.9952, 0.098, 0, 
-0.9569, 0.2903, 0, 
-0.9569, 0.2903, 0, 
-0.9569, 0.2903, 0, 
-0.8819, 0.4714, 0, 
-0.8819, 0.4714, 0, 
-0.8819, 0.4714, 0, 
-0.773, 0.6344, 0, 
-0.773, 0.6344, 0, 
-0.773, 0.6344, 0, 
-0.6344, 0.773, 0, 
-0.6344, 0.773, 0, 
-0.6344, 0.773, 0, 
-0.4714, 0.8819, 0, 
-0.4714, 0.8819, 0, 
-0.4714, 0.8819, 0, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
0, -0, 1, 
-0.2903, 0.9569, 0, 
-0.2903, 0.9569, 0, 
-0.2903, 0.9569, 0, 
-0.098, 0.9952, 0, 
-0.098, 0.9952, 0, 
-0.098, 0.9952, 0, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
0, 0, -1, 
};
