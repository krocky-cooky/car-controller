;; Auto-generated. Do not edit!


(when (boundp 'beginner_tutorial::steerAndVelocity)
  (if (not (find-package "BEGINNER_TUTORIAL"))
    (make-package "BEGINNER_TUTORIAL"))
  (shadow 'steerAndVelocity (find-package "BEGINNER_TUTORIAL")))
(unless (find-package "BEGINNER_TUTORIAL::STEERANDVELOCITY")
  (make-package "BEGINNER_TUTORIAL::STEERANDVELOCITY"))

(in-package "ROS")
;;//! \htmlinclude steerAndVelocity.msg.html


(defclass beginner_tutorial::steerAndVelocity
  :super ros::object
  :slots (_velocity _steer ))

(defmethod beginner_tutorial::steerAndVelocity
  (:init
   (&key
    ((:velocity __velocity) 0.0)
    ((:steer __steer) 0.0)
    )
   (send-super :init)
   (setq _velocity (float __velocity))
   (setq _steer (float __steer))
   self)
  (:velocity
   (&optional __velocity)
   (if __velocity (setq _velocity __velocity)) _velocity)
  (:steer
   (&optional __steer)
   (if __steer (setq _steer __steer)) _steer)
  (:serialization-length
   ()
   (+
    ;; float32 _velocity
    4
    ;; float32 _steer
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _velocity
       (sys::poke _velocity (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _steer
       (sys::poke _steer (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _velocity
     (setq _velocity (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _steer
     (setq _steer (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get beginner_tutorial::steerAndVelocity :md5sum-) "338cc52c049aa1a1e2dc54d48cdda24b")
(setf (get beginner_tutorial::steerAndVelocity :datatype-) "beginner_tutorial/steerAndVelocity")
(setf (get beginner_tutorial::steerAndVelocity :definition-)
      "float32 velocity
float32 steer

")



(provide :beginner_tutorial/steerAndVelocity "338cc52c049aa1a1e2dc54d48cdda24b")


