// Generated by gencpp from file shooter/JoyValues.msg
// DO NOT EDIT!


#ifndef SHOOTER_MESSAGE_JOYVALUES_H
#define SHOOTER_MESSAGE_JOYVALUES_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace shooter
{
template <class ContainerAllocator>
struct JoyValues_
{
  typedef JoyValues_<ContainerAllocator> Type;

  JoyValues_()
    : axis_vals()  {
      axis_vals.assign(0.0);
  }
  JoyValues_(const ContainerAllocator& _alloc)
    : axis_vals()  {
  (void)_alloc;
      axis_vals.assign(0.0);
  }



   typedef boost::array<float, 2>  _axis_vals_type;
  _axis_vals_type axis_vals;




  typedef boost::shared_ptr< ::shooter::JoyValues_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::shooter::JoyValues_<ContainerAllocator> const> ConstPtr;

}; // struct JoyValues_

typedef ::shooter::JoyValues_<std::allocator<void> > JoyValues;

typedef boost::shared_ptr< ::shooter::JoyValues > JoyValuesPtr;
typedef boost::shared_ptr< ::shooter::JoyValues const> JoyValuesConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::shooter::JoyValues_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::shooter::JoyValues_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace shooter

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'shooter': ['/home/ubuntu/shooter_ws/src/shooter/msg'], 'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::shooter::JoyValues_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::shooter::JoyValues_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::shooter::JoyValues_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::shooter::JoyValues_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::shooter::JoyValues_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::shooter::JoyValues_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::shooter::JoyValues_<ContainerAllocator> >
{
  static const char* value()
  {
    return "0e690cc92bcfca43c513ed996fe91f2c";
  }

  static const char* value(const ::shooter::JoyValues_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x0e690cc92bcfca43ULL;
  static const uint64_t static_value2 = 0xc513ed996fe91f2cULL;
};

template<class ContainerAllocator>
struct DataType< ::shooter::JoyValues_<ContainerAllocator> >
{
  static const char* value()
  {
    return "shooter/JoyValues";
  }

  static const char* value(const ::shooter::JoyValues_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::shooter::JoyValues_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float32[2] axis_vals\n\
";
  }

  static const char* value(const ::shooter::JoyValues_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::shooter::JoyValues_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.axis_vals);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct JoyValues_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::shooter::JoyValues_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::shooter::JoyValues_<ContainerAllocator>& v)
  {
    s << indent << "axis_vals[]" << std::endl;
    for (size_t i = 0; i < v.axis_vals.size(); ++i)
    {
      s << indent << "  axis_vals[" << i << "]: ";
      Printer<float>::stream(s, indent + "  ", v.axis_vals[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // SHOOTER_MESSAGE_JOYVALUES_H
