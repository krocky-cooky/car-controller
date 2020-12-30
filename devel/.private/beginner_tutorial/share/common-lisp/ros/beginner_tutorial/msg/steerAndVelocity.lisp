; Auto-generated. Do not edit!


(cl:in-package beginner_tutorial-msg)


;//! \htmlinclude steerAndVelocity.msg.html

(cl:defclass <steerAndVelocity> (roslisp-msg-protocol:ros-message)
  ((velocity
    :reader velocity
    :initarg :velocity
    :type cl:float
    :initform 0.0)
   (steer
    :reader steer
    :initarg :steer
    :type cl:float
    :initform 0.0))
)

(cl:defclass steerAndVelocity (<steerAndVelocity>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <steerAndVelocity>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'steerAndVelocity)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name beginner_tutorial-msg:<steerAndVelocity> is deprecated: use beginner_tutorial-msg:steerAndVelocity instead.")))

(cl:ensure-generic-function 'velocity-val :lambda-list '(m))
(cl:defmethod velocity-val ((m <steerAndVelocity>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader beginner_tutorial-msg:velocity-val is deprecated.  Use beginner_tutorial-msg:velocity instead.")
  (velocity m))

(cl:ensure-generic-function 'steer-val :lambda-list '(m))
(cl:defmethod steer-val ((m <steerAndVelocity>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader beginner_tutorial-msg:steer-val is deprecated.  Use beginner_tutorial-msg:steer instead.")
  (steer m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <steerAndVelocity>) ostream)
  "Serializes a message object of type '<steerAndVelocity>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'velocity))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'steer))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <steerAndVelocity>) istream)
  "Deserializes a message object of type '<steerAndVelocity>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'velocity) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'steer) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<steerAndVelocity>)))
  "Returns string type for a message object of type '<steerAndVelocity>"
  "beginner_tutorial/steerAndVelocity")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'steerAndVelocity)))
  "Returns string type for a message object of type 'steerAndVelocity"
  "beginner_tutorial/steerAndVelocity")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<steerAndVelocity>)))
  "Returns md5sum for a message object of type '<steerAndVelocity>"
  "338cc52c049aa1a1e2dc54d48cdda24b")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'steerAndVelocity)))
  "Returns md5sum for a message object of type 'steerAndVelocity"
  "338cc52c049aa1a1e2dc54d48cdda24b")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<steerAndVelocity>)))
  "Returns full string definition for message of type '<steerAndVelocity>"
  (cl:format cl:nil "float32 velocity~%float32 steer~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'steerAndVelocity)))
  "Returns full string definition for message of type 'steerAndVelocity"
  (cl:format cl:nil "float32 velocity~%float32 steer~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <steerAndVelocity>))
  (cl:+ 0
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <steerAndVelocity>))
  "Converts a ROS message object to a list"
  (cl:list 'steerAndVelocity
    (cl:cons ':velocity (velocity msg))
    (cl:cons ':steer (steer msg))
))
