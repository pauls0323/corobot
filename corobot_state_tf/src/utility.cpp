#include "utility.h"


Utility::Utility() {}


Utility::~Utility() {}

/** This method returns the Euclidean distance between two position vectors */
const float Utility::euclideanDistance(const std::vector<float> a, const std::vector<float> b) const {

  float d_x = b.at(0) - a.at(0);
  float d_y = b.at(1) - a.at(1);
  return sqrt( pow(d_x,2) + pow(d_y,2) );
} //End euclideanDistance

/** This method returns the angle that will form a straight line from position a to position b. a and b are [x, y] vectors. */
const float Utility::findAngleFromAToB(const std::vector<float> a, const std::vector<float> b) const {
  float result;

  // Find the distances in x,y directions and Euclidean distance
  float d_x = b.at(0) - a.at(0);
  float d_y = b.at(1) - a.at(1);
  float euc_dist = sqrt( pow(d_x,2) + pow(d_y,2) );
  
  // If the positions are the same, set the result to starting angle
  if(euc_dist == 0) {
    result = 0;
  }

  // If b is in the 1st or 2nd quadrants
  else if(d_y > 0) {
    result = acos(d_x / euc_dist);
  }

  // If b is in the 3rd quadrant, d_y<0 & d_x<0
  else if(d_x < 0) {
    result = -PI - asin(d_y / euc_dist);
  }

  // If b is in the 4th quadrant, d_y<=0 & d_x>=0
  else {
    result = asin(d_y / euc_dist); 
  }

  return result;
} //End findAngleFromAToB


/** This method returns distance between orientations a1 and a2. The distance is in the range [-PI, PI]. */
const float Utility::findDistanceBetweenAngles(const float a1, const float a2) const {
  float result;

  float difference = a1 - a2;
  
  // If difference > pi, the result should be in [-PI,0] range
  if(difference > PI) {
    difference = fmodf(difference, PI);
    result = (difference == 0) ? 0 : difference - PI;
  }

  // If difference < -pi, the result should be in [0,PI] range
  else if(difference < -PI) {
    result = difference + (2*PI);
  }

  // Else, the difference is fine
  else {
    result = difference;
  }

  return result;
} //End findDistanceBetweenAngles 


// Displace angle a1 by angle a2. The result range is [-pi,pi]
const float Utility::displaceAngle(const float a1, float a2) const {

  a2 = fmodf(a2, 2*PI);

  if(a2 > PI) {
    a2 = fmodf(a2,PI) - PI;
  }

  return findDistanceBetweenAngles(a1, -a2);
} //End displaceAngle


