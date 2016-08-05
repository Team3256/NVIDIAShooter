#ifndef _ROS_geometry_msgs_Inertia_h
#define _ROS_geometry_msgs_Inertia_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Vector3.h"

namespace geometry_msgs
{

  class Inertia : public ros::Msg
  {
    public:
      float m;
      geometry_msgs::Vector3 com;
      float ixx;
      float ixy;
      float ixz;
      float iyy;
      float iyz;
      float izz;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      int32_t * val_m = (int32_t *) &(this->m);
      int32_t exp_m = (((*val_m)>>23)&255);
      if(exp_m != 0)
        exp_m += 1023-127;
      int32_t sig_m = *val_m;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_m<<5) & 0xff;
      *(outbuffer + offset++) = (sig_m>>3) & 0xff;
      *(outbuffer + offset++) = (sig_m>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_m<<4) & 0xF0) | ((sig_m>>19)&0x0F);
      *(outbuffer + offset++) = (exp_m>>4) & 0x7F;
      if(this->m < 0) *(outbuffer + offset -1) |= 0x80;
      offset += this->com.serialize(outbuffer + offset);
      int32_t * val_ixx = (int32_t *) &(this->ixx);
      int32_t exp_ixx = (((*val_ixx)>>23)&255);
      if(exp_ixx != 0)
        exp_ixx += 1023-127;
      int32_t sig_ixx = *val_ixx;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_ixx<<5) & 0xff;
      *(outbuffer + offset++) = (sig_ixx>>3) & 0xff;
      *(outbuffer + offset++) = (sig_ixx>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_ixx<<4) & 0xF0) | ((sig_ixx>>19)&0x0F);
      *(outbuffer + offset++) = (exp_ixx>>4) & 0x7F;
      if(this->ixx < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_ixy = (int32_t *) &(this->ixy);
      int32_t exp_ixy = (((*val_ixy)>>23)&255);
      if(exp_ixy != 0)
        exp_ixy += 1023-127;
      int32_t sig_ixy = *val_ixy;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_ixy<<5) & 0xff;
      *(outbuffer + offset++) = (sig_ixy>>3) & 0xff;
      *(outbuffer + offset++) = (sig_ixy>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_ixy<<4) & 0xF0) | ((sig_ixy>>19)&0x0F);
      *(outbuffer + offset++) = (exp_ixy>>4) & 0x7F;
      if(this->ixy < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_ixz = (int32_t *) &(this->ixz);
      int32_t exp_ixz = (((*val_ixz)>>23)&255);
      if(exp_ixz != 0)
        exp_ixz += 1023-127;
      int32_t sig_ixz = *val_ixz;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_ixz<<5) & 0xff;
      *(outbuffer + offset++) = (sig_ixz>>3) & 0xff;
      *(outbuffer + offset++) = (sig_ixz>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_ixz<<4) & 0xF0) | ((sig_ixz>>19)&0x0F);
      *(outbuffer + offset++) = (exp_ixz>>4) & 0x7F;
      if(this->ixz < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_iyy = (int32_t *) &(this->iyy);
      int32_t exp_iyy = (((*val_iyy)>>23)&255);
      if(exp_iyy != 0)
        exp_iyy += 1023-127;
      int32_t sig_iyy = *val_iyy;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_iyy<<5) & 0xff;
      *(outbuffer + offset++) = (sig_iyy>>3) & 0xff;
      *(outbuffer + offset++) = (sig_iyy>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_iyy<<4) & 0xF0) | ((sig_iyy>>19)&0x0F);
      *(outbuffer + offset++) = (exp_iyy>>4) & 0x7F;
      if(this->iyy < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_iyz = (int32_t *) &(this->iyz);
      int32_t exp_iyz = (((*val_iyz)>>23)&255);
      if(exp_iyz != 0)
        exp_iyz += 1023-127;
      int32_t sig_iyz = *val_iyz;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_iyz<<5) & 0xff;
      *(outbuffer + offset++) = (sig_iyz>>3) & 0xff;
      *(outbuffer + offset++) = (sig_iyz>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_iyz<<4) & 0xF0) | ((sig_iyz>>19)&0x0F);
      *(outbuffer + offset++) = (exp_iyz>>4) & 0x7F;
      if(this->iyz < 0) *(outbuffer + offset -1) |= 0x80;
      int32_t * val_izz = (int32_t *) &(this->izz);
      int32_t exp_izz = (((*val_izz)>>23)&255);
      if(exp_izz != 0)
        exp_izz += 1023-127;
      int32_t sig_izz = *val_izz;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_izz<<5) & 0xff;
      *(outbuffer + offset++) = (sig_izz>>3) & 0xff;
      *(outbuffer + offset++) = (sig_izz>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_izz<<4) & 0xF0) | ((sig_izz>>19)&0x0F);
      *(outbuffer + offset++) = (exp_izz>>4) & 0x7F;
      if(this->izz < 0) *(outbuffer + offset -1) |= 0x80;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t * val_m = (uint32_t*) &(this->m);
      offset += 3;
      *val_m = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_m |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_m |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_m |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_m = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_m |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_m !=0)
        *val_m |= ((exp_m)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->m = -this->m;
      offset += this->com.deserialize(inbuffer + offset);
      uint32_t * val_ixx = (uint32_t*) &(this->ixx);
      offset += 3;
      *val_ixx = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_ixx |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_ixx |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_ixx |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_ixx = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_ixx |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_ixx !=0)
        *val_ixx |= ((exp_ixx)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->ixx = -this->ixx;
      uint32_t * val_ixy = (uint32_t*) &(this->ixy);
      offset += 3;
      *val_ixy = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_ixy |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_ixy |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_ixy |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_ixy = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_ixy |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_ixy !=0)
        *val_ixy |= ((exp_ixy)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->ixy = -this->ixy;
      uint32_t * val_ixz = (uint32_t*) &(this->ixz);
      offset += 3;
      *val_ixz = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_ixz |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_ixz |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_ixz |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_ixz = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_ixz |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_ixz !=0)
        *val_ixz |= ((exp_ixz)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->ixz = -this->ixz;
      uint32_t * val_iyy = (uint32_t*) &(this->iyy);
      offset += 3;
      *val_iyy = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_iyy |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_iyy |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_iyy |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_iyy = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_iyy |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_iyy !=0)
        *val_iyy |= ((exp_iyy)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->iyy = -this->iyy;
      uint32_t * val_iyz = (uint32_t*) &(this->iyz);
      offset += 3;
      *val_iyz = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_iyz |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_iyz |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_iyz |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_iyz = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_iyz |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_iyz !=0)
        *val_iyz |= ((exp_iyz)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->iyz = -this->iyz;
      uint32_t * val_izz = (uint32_t*) &(this->izz);
      offset += 3;
      *val_izz = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_izz |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_izz |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_izz |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_izz = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_izz |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_izz !=0)
        *val_izz |= ((exp_izz)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->izz = -this->izz;
     return offset;
    }

    const char * getType(){ return "geometry_msgs/Inertia"; };
    const char * getMD5(){ return "1d26e4bb6c83ff141c5cf0d883c2b0fe"; };

  };

}
#endif