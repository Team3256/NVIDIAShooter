
(cl:in-package :asdf)

(defsystem "shooter-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "driveShootVals" :depends-on ("_package_driveShootVals"))
    (:file "_package_driveShootVals" :depends-on ("_package"))
    (:file "JoyValues" :depends-on ("_package_JoyValues"))
    (:file "_package_JoyValues" :depends-on ("_package"))
  ))