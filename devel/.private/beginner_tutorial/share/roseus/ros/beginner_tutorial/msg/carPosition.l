;; Auto-generated. Do not edit!


(when (boundp 'beginner_tutorial::carPosition)
  (if (not (find-package "BEGINNER_TUTORIAL"))
    (make-package "BEGINNER_TUTORIAL"))
  (shadow 'carPosition (find-package "BEGINNER_TUTORIAL")))
(unless (find-package "BEGINNER_TUTORIAL::CARPOSITION")
  (make-package "BEGINNER_TUTORIAL::CARPOSITION"))

(in-package "ROS")
;;//! \htmlinclude carPosition.msg.html


(defclass beginner_tutorial::carPosition
  :super ros::object
  :slots (_x _y _yaw ))

(defmethod beginner_tutorial::carPosition
  (:init
   (&key
    ((:x __x) 0.0)
    ((:y __y) 0.0)
    ((:yaw __yaw) 0.0)
    )
   (send-super :init)
   (setq _x (float __x))
   (setq _y (float __y))
   (setq _yaw (float __yaw))
   self)
  (:x
   (&optional __x)
   (if __x (setq _x __x)) _x)
  (:y
   (&optional __y)
   (if __y (setq _y __y)) _y)
  (:yaw
   (&optional __yaw)
   (if __yaw (setq _yaw __yaw)) _yaw)
  (:serialization-length
   ()
   (+
    ;; float32 _x
    4
    ;; float32 _y
    4
    ;; float32 _yaw
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _x
       (sys::poke _x (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _y
       (sys::poke _y (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _yaw
       (sys::poke _yaw (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _x
     (setq _x (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _y
     (setq _y (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _yaw
     (setq _yaw (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get beginner_tutorial::carPosition :md5sum-) "47802147045815b06859cca542c21d31")
(setf (get beginner_tutorial::carPosition :datatype-) "beginner_tutorial/carPosition")
(setf (get beginner_tutorial::carPosition :definition-)
      "float32 x
float32 y
float32 yaw

")



(provide :beginner_tutorial/carPosition "47802147045815b06859cca542c21d31")


