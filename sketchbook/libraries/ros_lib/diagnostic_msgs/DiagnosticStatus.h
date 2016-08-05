#ifndef _ROS_diagnostic_msgs_DiagnosticStatus_h
#define _ROS_diagnostic_msgs_DiagnosticStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "diagnostic_msgs/KeyValue.h"

namespace diagnostic_msgs
{

  class DiagnosticStatus : public ros::Msg
  {
    public:
      int8_t level;
      char * name;
      char * message;
      char * hardware_id;
      uint8_t values_length;
      diagnostic_msgs::KeyValue st_values;
      diagnostic_msgs::KeyValue * values;
      enum { OK = 0 };
      enum { WARN = 1 };
      enum { ERROR = 2 };
      enum { STALE = 3 };

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_level;
      u_level.real = this->level;
      *(outbuffer + offset + 0) = (u_level.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->level);
      uint32_t * length_name = (uint32_t *)(outbuffer + offset);
      *length_name = strlen( (const char*) this->name);
      offset += 4;
      memcpy(outbuffer + offset, this->name, *length_name);
      offset += *length_name;
      uint32_t * length_message = (uint32_t *)(outbuffer + offset);
      *length_message = strlen( (const char*) this->message);
      offset += 4;
      memcpy(outbuffer + offset, this->message, *length_message);
      offset += *length_message;
      uint32_t * length_hardware_id = (uint32_t *)(outbuffer + offset);
      *length_hardware_id = strlen( (const char*) this->hardware_id);
      offset += 4;
      memcpy(outbuffer + offset, this->hardware_id, *length_hardware_id);
      offset += *length_hardware_id;
      *(outbuffer + offset++) = values_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < values_length; i++){
      offset += this->values[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_level;
      u_level.base = 0;
      u_level.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->level = u_level.real;
      offset += sizeof(this->level);
      uint32_t length_name = *(uint32_t *)(inbuffer + offset);
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      uint32_t length_message = *(uint32_t *)(inbuffer + offset);
      offset += 4;
      for(unsigned int k= offset; k< offset+length_message; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_message-1]=0;
      this->message = (char *)(inbuffer + offset-1);
      offset += length_message;
      uint32_t length_hardware_id = *(uint32_t *)(inbuffer + offset);
      offset += 4;
      for(unsigned int k= offset; k< offset+length_hardware_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_hardware_id-1]=0;
      this->hardware_id = (char *)(inbuffer + offset-1);
      offset += length_hardware_id;
      uint8_t values_lengthT = *(inbuffer + offset++);
      if(values_lengthT > values_length)
        this->values = (diagnostic_msgs::KeyValue*)realloc(this->values, values_lengthT * sizeof(diagnostic_msgs::KeyValue));
      offset += 3;
      values_length = values_lengthT;
      for( uint8_t i = 0; i < values_length; i++){
      offset += this->st_values.deserialize(inbuffer + offset);
        memcpy( &(this->values[i]), &(this->st_values), sizeof(diagnostic_msgs::KeyValue));
      }
     return offset;
    }

    const char * getType(){ return "diagnostic_msgs/DiagnosticStatus"; };
    const char * getMD5(){ return "d0ce08bc6e5ba34c7754f563a9cabaf1"; };

  };

}
#endif