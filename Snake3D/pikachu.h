// This is a .c file for the model: pikachu



const int pikachuVertices = 144;

const float pikachuPositions[432] = 
{
-6.76273, 13.9177, 1.40154, 
2.29295, 9.42826, -0.417366, 
-0.89955, 8.94397, -0.771264, 
-6.52812, 10.8158, 0.09405, 
-6.76273, 13.9177, 1.40154, 
-0.89955, 8.94397, -0.771264, 
-0.89955, 8.94397, -0.771264, 
2.29295, 9.42826, -0.417366, 
0.893376, 7.64691, -1.09786, 
-0.89955, 8.94397, -0.771264, 
0.893376, 7.64691, -1.09786, 
-2.09403, 7.34502, -1.50961, 
0.893376, 7.64691, -1.09786, 
3.3982, 5.68769, -1.15758, 
0.444114, 5.46246, -1.73039, 
-2.09403, 7.34502, -1.50961, 
0.893376, 7.64691, -1.09786, 
0.444114, 5.46246, -1.73039, 
1.96816, 4.0242, -1.43133, 
-1.17825, 3.63159, -2.04109, 
0.444114, 5.46246, -1.73039, 
3.3982, 5.68769, -1.15758, 
1.96816, 4.0242, -1.43133, 
0.444114, 5.46246, -1.73039, 
1.96816, 4.0242, -1.43133, 
6.76273, 1.3008, 0.42282, 
1.42829, 2.29767, -1.53218, 
-1.17825, 3.63159, -2.04109, 
1.96816, 4.0242, -1.43133, 
1.42829, 2.29767, -1.53218, 
6.35844, 0, 0.547803, 
0.871119, 1.14253, -1.63768, 
1.42829, 2.29767, -1.53218, 
6.76273, 1.3008, 0.42282, 
6.35844, 0, 0.547803, 
1.42829, 2.29767, -1.53218, 
-6.51929, 10.5729, 0.733599, 
-0.945891, 8.74239, -0.11754, 
-6.7539, 13.6748, 2.04109, 
-0.945891, 8.74239, -0.11754, 
0.792405, 7.5216, -0.42813, 
2.24661, 9.22669, 0.236367, 
-2.195, 7.2197, -0.83988, 
0.792405, 7.5216, -0.42813, 
-0.945891, 8.74239, -0.11754, 
0.249786, 5.46332, -0.975033, 
3.20387, 5.68854, -0.40221, 
0.792405, 7.5216, -0.42813, 
-2.195, 7.2197, -0.83988, 
0.249786, 5.46332, -0.975033, 
0.792405, 7.5216, -0.42813, 
1.77382, 4.02505, -0.675972, 
0.249786, 5.46332, -0.975033, 
-1.37259, 3.63244, -1.28573, 
0.249786, 5.46332, -0.975033, 
1.77382, 4.02505, -0.675972, 
3.20387, 5.68854, -0.40221, 
1.23396, 2.29853, -0.776817, 
6.76273, 1.3008, 0.42282, 
1.77382, 4.02505, -0.675972, 
-1.37259, 3.63244, -1.28573, 
1.23396, 2.29853, -0.776817, 
1.77382, 4.02505, -0.675972, 
6.35844, 0, 0.547803, 
1.23396, 2.29853, -0.776817, 
0.676782, 1.14339, -0.882315, 
1.23396, 2.29853, -0.776817, 
6.35844, 0, 0.547803, 
6.76273, 1.3008, 0.42282, 
-0.945891, 8.74239, -0.11754, 
2.24661, 9.22669, 0.236367, 
-6.7539, 13.6748, 2.04109, 
-6.52812, 10.8158, 0.09405, 
-6.51929, 10.5729, 0.733599, 
-6.76273, 13.9177, 1.40154, 
-6.52812, 10.8158, 0.09405, 
-0.945891, 8.74239, -0.11754, 
-6.51929, 10.5729, 0.733599, 
-0.89955, 8.94397, -0.771264, 
-0.945891, 8.74239, -0.11754, 
-6.52812, 10.8158, 0.09405, 
-2.195, 7.2197, -0.83988, 
-0.945891, 8.74239, -0.11754, 
-0.89955, 8.94397, -0.771264, 
-2.09403, 7.34502, -1.50961, 
-2.195, 7.2197, -0.83988, 
-0.89955, 8.94397, -0.771264, 
-2.09403, 7.34502, -1.50961, 
0.249786, 5.46332, -0.975033, 
-2.195, 7.2197, -0.83988, 
0.444114, 5.46246, -1.73039, 
0.249786, 5.46332, -0.975033, 
-2.09403, 7.34502, -1.50961, 
-1.37259, 3.63244, -1.28573, 
0.249786, 5.46332, -0.975033, 
0.444114, 5.46246, -1.73039, 
-1.17825, 3.63159, -2.04109, 
-1.37259, 3.63244, -1.28573, 
0.444114, 5.46246, -1.73039, 
-1.17825, 3.63159, -2.04109, 
1.23396, 2.29853, -0.776817, 
-1.37259, 3.63244, -1.28573, 
1.42829, 2.29767, -1.53218, 
1.23396, 2.29853, -0.776817, 
-1.17825, 3.63159, -2.04109, 
0.676782, 1.14339, -0.882315, 
1.23396, 2.29853, -0.776817, 
1.42829, 2.29767, -1.53218, 
0.871119, 1.14253, -1.63768, 
0.676782, 1.14339, -0.882315, 
1.42829, 2.29767, -1.53218, 
0.871119, 1.14253, -1.63768, 
6.35844, 0, 0.547803, 
0.676782, 1.14339, -0.882315, 
-6.76273, 13.9177, 1.40154, 
-6.51929, 10.5729, 0.733599, 
-6.7539, 13.6748, 2.04109, 
1.96816, 4.0242, -1.43133, 
3.3982, 5.68769, -1.15758, 
1.77382, 4.02505, -0.675972, 
3.20387, 5.68854, -0.40221, 
1.77382, 4.02505, -0.675972, 
3.3982, 5.68769, -1.15758, 
3.20387, 5.68854, -0.40221, 
3.3982, 5.68769, -1.15758, 
0.893376, 7.64691, -1.09786, 
0.792405, 7.5216, -0.42813, 
3.20387, 5.68854, -0.40221, 
0.893376, 7.64691, -1.09786, 
0.893376, 7.64691, -1.09786, 
2.29295, 9.42826, -0.417366, 
0.792405, 7.5216, -0.42813, 
2.24661, 9.22669, 0.236367, 
0.792405, 7.5216, -0.42813, 
2.29295, 9.42826, -0.417366, 
2.24661, 9.22669, 0.236367, 
2.29295, 9.42826, -0.417366, 
-6.76273, 13.9177, 1.40154, 
-6.7539, 13.6748, 2.04109, 
2.24661, 9.22669, 0.236367, 
-6.76273, 13.9177, 1.40154, 
1.77382, 4.02505, -0.675972, 
6.76273, 1.3008, 0.42282, 
1.96816, 4.0242, -1.43133, 
};

const float pikachuTexels[288] = 
{
0.9492, 0.01955, 
0.89842, 0.53516, 
0.6953, 0.42286, 
0.58007, 0.11622, 
0.9492, 0.01955, 
0.6953, 0.42286, 
0.6953, 0.42286, 
0.89842, 0.53516, 
0.57616, 0.51954, 
0.6953, 0.42286, 
0.57616, 0.51954, 
0.37499, 0.44434, 
0.57616, 0.51954, 
0.53319, 0.66602, 
0.33788, 0.56934, 
0.37499, 0.44434, 
0.57616, 0.51954, 
0.33788, 0.56934, 
0.2539, 0.65919, 
0.02734, 0.56544, 
0.33788, 0.56934, 
0.53319, 0.66602, 
0.2539, 0.65919, 
0.33788, 0.56934, 
0.2539, 0.65919, 
0.25781, 0.96875, 
0.06445, 0.70215, 
0.02734, 0.56544, 
0.2539, 0.65919, 
0.06445, 0.70215, 
0.10351, 0.99805, 
-0.12109, 0.70801, 
0.06445, 0.70215, 
0.25781, 0.96875, 
0.10351, 0.99805, 
0.06445, 0.70215, 
0.58007, 0.11622, 
0.6953, 0.42286, 
0.9492, 0.01955, 
0.6953, 0.42286, 
0.57616, 0.51954, 
0.89842, 0.53516, 
0.37499, 0.44434, 
0.57616, 0.51954, 
0.6953, 0.42286, 
0.33788, 0.56934, 
0.53319, 0.66602, 
0.57616, 0.51954, 
0.37499, 0.44434, 
0.33788, 0.56934, 
0.57616, 0.51954, 
0.2539, 0.65919, 
0.33788, 0.56934, 
0.02734, 0.56544, 
0.33788, 0.56934, 
0.2539, 0.65919, 
0.53319, 0.66602, 
0.06445, 0.70215, 
0.25781, 0.96875, 
0.2539, 0.65919, 
0.02734, 0.56544, 
0.06445, 0.70215, 
0.2539, 0.65919, 
0.10351, 0.99805, 
0.06445, 0.70215, 
-0.12109, 0.70801, 
0.06445, 0.70215, 
0.10351, 0.99805, 
0.25781, 0.96875, 
0.6953, 0.42286, 
0.89842, 0.53516, 
0.9492, 0.01955, 
0.58007, 0.11622, 
0.58007, 0.11622, 
0.9492, 0.01955, 
0.58007, 0.11622, 
0.6953, 0.42286, 
0.58007, 0.11622, 
0.6953, 0.42286, 
0.6953, 0.42286, 
0.58007, 0.11622, 
0.37499, 0.44434, 
0.6953, 0.42286, 
0.6953, 0.42286, 
0.37499, 0.44434, 
0.37499, 0.44434, 
0.6953, 0.42286, 
0.37499, 0.44434, 
0.33788, 0.56934, 
0.37499, 0.44434, 
0.33788, 0.56934, 
0.33788, 0.56934, 
0.37499, 0.44434, 
0.02734, 0.56544, 
0.33788, 0.56934, 
0.33788, 0.56934, 
0.02734, 0.56544, 
0.02734, 0.56544, 
0.33788, 0.56934, 
0.02734, 0.56544, 
0.06445, 0.70215, 
0.02734, 0.56544, 
0.06445, 0.70215, 
0.06445, 0.70215, 
0.02734, 0.56544, 
-0.12109, 0.70801, 
0.06445, 0.70215, 
0.06445, 0.70215, 
-0.12109, 0.70801, 
-0.12109, 0.70801, 
0.06445, 0.70215, 
-0.12109, 0.70801, 
0.10351, 0.99805, 
-0.12109, 0.70801, 
0.9492, 0.01955, 
0.58007, 0.11622, 
0.9492, 0.01955, 
0.2539, 0.65919, 
0.53319, 0.66602, 
0.2539, 0.65919, 
0.53319, 0.66602, 
0.2539, 0.65919, 
0.53319, 0.66602, 
0.53319, 0.66602, 
0.53319, 0.66602, 
0.57616, 0.51954, 
0.57616, 0.51954, 
0.53319, 0.66602, 
0.57616, 0.51954, 
0.57616, 0.51954, 
0.89842, 0.53516, 
0.57616, 0.51954, 
0.89842, 0.53516, 
0.57616, 0.51954, 
0.89842, 0.53516, 
0.89842, 0.53516, 
0.89842, 0.53516, 
0.9492, 0.01955, 
0.9492, 0.01955, 
0.89842, 0.53516, 
0.9492, 0.01955, 
0.2539, 0.65919, 
0.25781, 0.96875, 
0.2539, 0.65919, 
};

const float pikachuNormals[432] = 
{
-0.362445, 0.822138, -0.439003, 
0.776827, 0.128748, -0.616412, 
-0.381998, 0.389276, -0.838178, 
-0.621131, -0.533754, -0.573849, 
-0.362445, 0.822138, -0.439003, 
-0.381998, 0.389276, -0.838178, 
-0.381998, 0.389276, -0.838178, 
0.776827, 0.128748, -0.616412, 
0.515312, 0.451848, -0.728208, 
-0.381998, 0.389276, -0.838178, 
0.515312, 0.451848, -0.728208, 
-0.609071, -0.121334, -0.78378, 
0.515312, 0.451848, -0.728208, 
0.860604, -0.106171, -0.498084, 
-0.291988, 0.220826, -0.93058, 
-0.609071, -0.121334, -0.78378, 
0.515312, 0.451848, -0.728208, 
-0.291988, 0.220826, -0.93058, 
0.504069, 0.040413, -0.862717, 
-0.418681, -0.388405, -0.820882, 
-0.291988, 0.220826, -0.93058, 
0.860604, -0.106171, -0.498084, 
0.504069, 0.040413, -0.862717, 
-0.291988, 0.220826, -0.93058, 
0.504069, 0.040413, -0.862717, 
0.64794, 0.74113, 0.175782, 
-0.221008, -0.075207, -0.972368, 
-0.418681, -0.388405, -0.820882, 
0.504069, 0.040413, -0.862717, 
-0.221008, -0.075207, -0.972368, 
0.048628, -0.998417, 0.028251, 
-0.459754, -0.410511, -0.787469, 
-0.221008, -0.075207, -0.972368, 
0.64794, 0.74113, 0.175782, 
0.048628, -0.998417, 0.028251, 
-0.221008, -0.075207, -0.972368, 
-0.83691, -0.507828, 0.204189, 
-0.36681, -0.59902, 0.711776, 
-0.250291, -0.029471, 0.967722, 
-0.36681, -0.59902, 0.711776, 
0.378769, -0.347138, 0.857922, 
0.573613, 0.103063, 0.812617, 
-0.798483, -0.061632, 0.598855, 
0.378769, -0.347138, 0.857922, 
-0.36681, -0.59902, 0.711776, 
-0.580858, -0.303795, 0.75519, 
0.513897, 0.224841, 0.827863, 
0.378769, -0.347138, 0.857922, 
-0.798483, -0.061632, 0.598855, 
-0.580858, -0.303795, 0.75519, 
0.378769, -0.347138, 0.857922, 
0.247383, -0.091319, 0.964605, 
-0.580858, -0.303795, 0.75519, 
-0.824626, 0.164299, 0.541293, 
-0.580858, -0.303795, 0.75519, 
0.247383, -0.091319, 0.964605, 
0.513897, 0.224841, 0.827863, 
-0.575465, -0.260043, 0.775382, 
0.64794, 0.74113, 0.175782, 
0.247383, -0.091319, 0.964605, 
-0.824626, 0.164299, 0.541293, 
-0.575465, -0.260043, 0.775382, 
0.247383, -0.091319, 0.964605, 
0.048628, -0.998417, 0.028251, 
-0.575465, -0.260043, 0.775382, 
-0.976134, -0.033843, 0.214515, 
-0.575465, -0.260043, 0.775382, 
0.048628, -0.998417, 0.028251, 
0.64794, 0.74113, 0.175782, 
-0.36681, -0.59902, 0.711776, 
0.573613, 0.103063, 0.812617, 
-0.250291, -0.029471, 0.967722, 
-0.621131, -0.533754, -0.573849, 
-0.83691, -0.507828, 0.204189, 
-0.362445, 0.822138, -0.439003, 
-0.621131, -0.533754, -0.573849, 
-0.36681, -0.59902, 0.711776, 
-0.83691, -0.507828, 0.204189, 
-0.381998, 0.389276, -0.838178, 
-0.36681, -0.59902, 0.711776, 
-0.621131, -0.533754, -0.573849, 
-0.798483, -0.061632, 0.598855, 
-0.36681, -0.59902, 0.711776, 
-0.381998, 0.389276, -0.838178, 
-0.609071, -0.121334, -0.78378, 
-0.798483, -0.061632, 0.598855, 
-0.381998, 0.389276, -0.838178, 
-0.609071, -0.121334, -0.78378, 
-0.580858, -0.303795, 0.75519, 
-0.798483, -0.061632, 0.598855, 
-0.291988, 0.220826, -0.93058, 
-0.580858, -0.303795, 0.75519, 
-0.609071, -0.121334, -0.78378, 
-0.824626, 0.164299, 0.541293, 
-0.580858, -0.303795, 0.75519, 
-0.291988, 0.220826, -0.93058, 
-0.418681, -0.388405, -0.820882, 
-0.824626, 0.164299, 0.541293, 
-0.291988, 0.220826, -0.93058, 
-0.418681, -0.388405, -0.820882, 
-0.575465, -0.260043, 0.775382, 
-0.824626, 0.164299, 0.541293, 
-0.221008, -0.075207, -0.972368, 
-0.575465, -0.260043, 0.775382, 
-0.418681, -0.388405, -0.820882, 
-0.976134, -0.033843, 0.214515, 
-0.575465, -0.260043, 0.775382, 
-0.221008, -0.075207, -0.972368, 
-0.459754, -0.410511, -0.787469, 
-0.976134, -0.033843, 0.214515, 
-0.221008, -0.075207, -0.972368, 
-0.459754, -0.410511, -0.787469, 
0.048628, -0.998417, 0.028251, 
-0.976134, -0.033843, 0.214515, 
-0.362445, 0.822138, -0.439003, 
-0.83691, -0.507828, 0.204189, 
-0.250291, -0.029471, 0.967722, 
0.504069, 0.040413, -0.862717, 
0.860604, -0.106171, -0.498084, 
0.247383, -0.091319, 0.964605, 
0.513897, 0.224841, 0.827863, 
0.247383, -0.091319, 0.964605, 
0.860604, -0.106171, -0.498084, 
0.513897, 0.224841, 0.827863, 
0.860604, -0.106171, -0.498084, 
0.515312, 0.451848, -0.728208, 
0.378769, -0.347138, 0.857922, 
0.513897, 0.224841, 0.827863, 
0.515312, 0.451848, -0.728208, 
0.515312, 0.451848, -0.728208, 
0.776827, 0.128748, -0.616412, 
0.378769, -0.347138, 0.857922, 
0.573613, 0.103063, 0.812617, 
0.378769, -0.347138, 0.857922, 
0.776827, 0.128748, -0.616412, 
0.573613, 0.103063, 0.812617, 
0.776827, 0.128748, -0.616412, 
-0.362445, 0.822138, -0.439003, 
-0.250291, -0.029471, 0.967722, 
0.573613, 0.103063, 0.812617, 
-0.362445, 0.822138, -0.439003, 
0.247383, -0.091319, 0.964605, 
0.64794, 0.74113, 0.175782, 
0.504069, 0.040413, -0.862717, 
};
