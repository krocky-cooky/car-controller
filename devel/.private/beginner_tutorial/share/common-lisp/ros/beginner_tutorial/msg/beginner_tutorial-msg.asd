
(cl:in-package :asdf)

(defsystem "beginner_tutorial-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "carPosition" :depends-on ("_package_carPosition"))
    (:file "_package_carPosition" :depends-on ("_package"))
    (:file "steerAndVelocity" :depends-on ("_package_steerAndVelocity"))
    (:file "_package_steerAndVelocity" :depends-on ("_package"))
  ))