
(cl:in-package :asdf)

(defsystem "shooter-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "Controls" :depends-on ("_package_Controls"))
    (:file "_package_Controls" :depends-on ("_package"))
    (:file "Sensors" :depends-on ("_package_Sensors"))
    (:file "_package_Sensors" :depends-on ("_package"))
  ))