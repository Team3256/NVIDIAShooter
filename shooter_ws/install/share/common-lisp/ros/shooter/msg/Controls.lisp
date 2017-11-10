; Auto-generated. Do not edit!


(cl:in-package shooter-msg)


;//! \htmlinclude Controls.msg.html

(cl:defclass <Controls> (roslisp-msg-protocol:ros-message)
  ((drive
    :reader drive
    :initarg :drive
    :type (cl:vector cl:float)
   :initform (cl:make-array 2 :element-type 'cl:float :initial-element 0.0))
   (shoot
    :reader shoot
    :initarg :shoot
    :type (cl:vector cl:boolean)
   :initform (cl:make-array 2 :element-type 'cl:boolean :initial-element cl:nil))
   (reload
    :reader reload
    :initarg :reload
    :type (cl:vector cl:boolean)
   :initform (cl:make-array 2 :element-type 'cl:boolean :initial-element cl:nil))
   (pivot
    :reader pivot
    :initarg :pivot
    :type cl:float
    :initform 0.0))
)

(cl:defclass Controls (<Controls>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Controls>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Controls)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name shooter-msg:<Controls> is deprecated: use shooter-msg:Controls instead.")))

(cl:ensure-generic-function 'drive-val :lambda-list '(m))
(cl:defmethod drive-val ((m <Controls>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader shooter-msg:drive-val is deprecated.  Use shooter-msg:drive instead.")
  (drive m))

(cl:ensure-generic-function 'shoot-val :lambda-list '(m))
(cl:defmethod shoot-val ((m <Controls>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader shooter-msg:shoot-val is deprecated.  Use shooter-msg:shoot instead.")
  (shoot m))

(cl:ensure-generic-function 'reload-val :lambda-list '(m))
(cl:defmethod reload-val ((m <Controls>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader shooter-msg:reload-val is deprecated.  Use shooter-msg:reload instead.")
  (reload m))

(cl:ensure-generic-function 'pivot-val :lambda-list '(m))
(cl:defmethod pivot-val ((m <Controls>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader shooter-msg:pivot-val is deprecated.  Use shooter-msg:pivot instead.")
  (pivot m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Controls>) ostream)
  "Serializes a message object of type '<Controls>"
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-single-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)))
   (cl:slot-value msg 'drive))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if ele 1 0)) ostream))
   (cl:slot-value msg 'shoot))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if ele 1 0)) ostream))
   (cl:slot-value msg 'reload))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'pivot))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Controls>) istream)
  "Deserializes a message object of type '<Controls>"
  (cl:setf (cl:slot-value msg 'drive) (cl:make-array 2))
  (cl:let ((vals (cl:slot-value msg 'drive)))
    (cl:dotimes (i 2)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-single-float-bits bits)))))
  (cl:setf (cl:slot-value msg 'shoot) (cl:make-array 2))
  (cl:let ((vals (cl:slot-value msg 'shoot)))
    (cl:dotimes (i 2)
    (cl:setf (cl:aref vals i) (cl:not (cl:zerop (cl:read-byte istream))))))
  (cl:setf (cl:slot-value msg 'reload) (cl:make-array 2))
  (cl:let ((vals (cl:slot-value msg 'reload)))
    (cl:dotimes (i 2)
    (cl:setf (cl:aref vals i) (cl:not (cl:zerop (cl:read-byte istream))))))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'pivot) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Controls>)))
  "Returns string type for a message object of type '<Controls>"
  "shooter/Controls")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Controls)))
  "Returns string type for a message object of type 'Controls"
  "shooter/Controls")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Controls>)))
  "Returns md5sum for a message object of type '<Controls>"
  "ad06e20480b263726a89fb1db30326ca")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Controls)))
  "Returns md5sum for a message object of type 'Controls"
  "ad06e20480b263726a89fb1db30326ca")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Controls>)))
  "Returns full string definition for message of type '<Controls>"
  (cl:format cl:nil "float32[2] drive~%bool[2] shoot~%bool[2] reload~%float32 pivot~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Controls)))
  "Returns full string definition for message of type 'Controls"
  (cl:format cl:nil "float32[2] drive~%bool[2] shoot~%bool[2] reload~%float32 pivot~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Controls>))
  (cl:+ 0
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'drive) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'shoot) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 1)))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'reload) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 1)))
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Controls>))
  "Converts a ROS message object to a list"
  (cl:list 'Controls
    (cl:cons ':drive (drive msg))
    (cl:cons ':shoot (shoot msg))
    (cl:cons ':reload (reload msg))
    (cl:cons ':pivot (pivot msg))
))
