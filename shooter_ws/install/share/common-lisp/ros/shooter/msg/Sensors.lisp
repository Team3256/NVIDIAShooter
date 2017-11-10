; Auto-generated. Do not edit!


(cl:in-package shooter-msg)


;//! \htmlinclude Sensors.msg.html

(cl:defclass <Sensors> (roslisp-msg-protocol:ros-message)
  ((hall_effect
    :reader hall_effect
    :initarg :hall_effect
    :type cl:boolean
    :initform cl:nil)
   (encoder
    :reader encoder
    :initarg :encoder
    :type cl:float
    :initform 0.0))
)

(cl:defclass Sensors (<Sensors>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Sensors>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Sensors)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name shooter-msg:<Sensors> is deprecated: use shooter-msg:Sensors instead.")))

(cl:ensure-generic-function 'hall_effect-val :lambda-list '(m))
(cl:defmethod hall_effect-val ((m <Sensors>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader shooter-msg:hall_effect-val is deprecated.  Use shooter-msg:hall_effect instead.")
  (hall_effect m))

(cl:ensure-generic-function 'encoder-val :lambda-list '(m))
(cl:defmethod encoder-val ((m <Sensors>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader shooter-msg:encoder-val is deprecated.  Use shooter-msg:encoder instead.")
  (encoder m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Sensors>) ostream)
  "Serializes a message object of type '<Sensors>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'hall_effect) 1 0)) ostream)
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'encoder))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Sensors>) istream)
  "Deserializes a message object of type '<Sensors>"
    (cl:setf (cl:slot-value msg 'hall_effect) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'encoder) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Sensors>)))
  "Returns string type for a message object of type '<Sensors>"
  "shooter/Sensors")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Sensors)))
  "Returns string type for a message object of type 'Sensors"
  "shooter/Sensors")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Sensors>)))
  "Returns md5sum for a message object of type '<Sensors>"
  "f7cfdfbbaadd9e2973865db3746b46cc")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Sensors)))
  "Returns md5sum for a message object of type 'Sensors"
  "f7cfdfbbaadd9e2973865db3746b46cc")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Sensors>)))
  "Returns full string definition for message of type '<Sensors>"
  (cl:format cl:nil "bool hall_effect~%float32 encoder~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Sensors)))
  "Returns full string definition for message of type 'Sensors"
  (cl:format cl:nil "bool hall_effect~%float32 encoder~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Sensors>))
  (cl:+ 0
     1
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Sensors>))
  "Converts a ROS message object to a list"
  (cl:list 'Sensors
    (cl:cons ':hall_effect (hall_effect msg))
    (cl:cons ':encoder (encoder msg))
))
