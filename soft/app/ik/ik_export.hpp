namespace ik_export {
  namespace armatures {
    struct armature {
      static constexpr bool VARIABLE = false;
      struct body_left_front {
        static constexpr bool VARIABLE = false;
        using parent = void;
        using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Rational<298,1024>,CAS::General<double, double>::Const::Rational<-461,1024>,CAS::General<double, double>::Const::Rational<864,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-859,1024>,CAS::General<double, double>::Const::Rational<-557,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<470,1024>,CAS::General<double, double>::Const::Rational<-725,1024>,CAS::General<double, double>::Const::Rational<-549,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
      };
      struct shoulder_left_front {
        static constexpr bool VARIABLE = false;
        using parent = body_left_front;
        using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Rational<-298,1024>,CAS::General<double, double>::Const::Rational<859,1024>,CAS::General<double, double>::Const::Rational<470,1024>,CAS::General<double, double>::Const::Rational<20730,1024>,CAS::General<double, double>::Const::Rational<461,1024>,CAS::General<double, double>::Const::Rational<557,1024>,CAS::General<double, double>::Const::Rational<-724,1024>,CAS::General<double, double>::Const::Rational<66009,1024>,CAS::General<double, double>::Const::Rational<-864,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-549,1024>,CAS::General<double, double>::Const::Rational<-69239,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
      };
      struct arm_left_front {
        static constexpr bool VARIABLE = false;
        using parent = shoulder_left_front;
        using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<8,1024>,CAS::General<double, double>::Const::Rational<1023,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-1023,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<33700,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-1023,1024>,CAS::General<double, double>::Const::Rational<8,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
      };
      struct forearm_left_front {
        static constexpr bool VARIABLE = false;
        using parent = arm_left_front;
        using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<-1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<1023,1024>,CAS::General<double, double>::Const::Rational<-8,1024>,CAS::General<double, double>::Const::Rational<92039,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-8,1024>,CAS::General<double, double>::Const::Rational<-1023,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
      };
      struct body_right_front {
        static constexpr bool VARIABLE = false;
        using parent = void;
        using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Rational<-299,1024>,CAS::General<double, double>::Const::Rational<-859,1024>,CAS::General<double, double>::Const::Rational<-469,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-461,1024>,CAS::General<double, double>::Const::Rational<557,1024>,CAS::General<double, double>::Const::Rational<-725,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<863,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-550,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
      };
      struct shoulder_right_front {
        static constexpr bool VARIABLE = false;
        using parent = body_right_front;
        using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Rational<-863,1024>,CAS::General<double, double>::Const::Rational<-461,1024>,CAS::General<double, double>::Const::Rational<-299,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<557,1024>,CAS::General<double, double>::Const::Rational<-859,1024>,CAS::General<double, double>::Const::Rational<97883,1024>,CAS::General<double, double>::Const::Rational<550,1024>,CAS::General<double, double>::Const::Rational<-725,1024>,CAS::General<double, double>::Const::Rational<-469,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
      };
      struct arm_right_front {
        static constexpr bool VARIABLE = false;
        using parent = shoulder_right_front;
        using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<1023,1024>,CAS::General<double, double>::Const::Rational<-7,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<33700,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-7,1024>,CAS::General<double, double>::Const::Rational<-1023,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
      };
      struct forearm_right_front {
        static constexpr bool VARIABLE = false;
        using parent = arm_right_front;
        using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<-1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<1023,1024>,CAS::General<double, double>::Const::Rational<-8,1024>,CAS::General<double, double>::Const::Rational<92039,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-8,1024>,CAS::General<double, double>::Const::Rational<-1023,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
      };
      struct body_left_back {
        static constexpr bool VARIABLE = false;
        using parent = void;
        using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Rational<249,1024>,CAS::General<double, double>::Const::Rational<912,1024>,CAS::General<double, double>::Const::Rational<393,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<486,1024>,CAS::General<double, double>::Const::Rational<-465,1024>,CAS::General<double, double>::Const::Rational<771,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<865,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-546,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
      };
      struct shoulder_left_back {
        static constexpr bool VARIABLE = false;
        using parent = body_left_back;
        using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Rational<-249,1024>,CAS::General<double, double>::Const::Rational<-486,1024>,CAS::General<double, double>::Const::Rational<865,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-912,1024>,CAS::General<double, double>::Const::Rational<465,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<117119,1024>,CAS::General<double, double>::Const::Rational<-393,1024>,CAS::General<double, double>::Const::Rational<-771,1024>,CAS::General<double, double>::Const::Rational<-546,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
      };
      struct arm_left_back {
        static constexpr bool VARIABLE = false;
        using parent = shoulder_left_back;
        using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-7,1024>,CAS::General<double, double>::Const::Rational<1023,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<-1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<33700,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-1023,1024>,CAS::General<double, double>::Const::Rational<-7,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
      };
      struct forearm_left_back {
        static constexpr bool VARIABLE = false;
        using parent = arm_left_back;
        using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<-1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<1023,1024>,CAS::General<double, double>::Const::Rational<8,1024>,CAS::General<double, double>::Const::Rational<92039,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<8,1024>,CAS::General<double, double>::Const::Rational<-1023,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
      };
      struct body_right_back {
        static constexpr bool VARIABLE = false;
        using parent = void;
        using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Rational<-250,1024>,CAS::General<double, double>::Const::Rational<912,1024>,CAS::General<double, double>::Const::Rational<-392,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<492,1024>,CAS::General<double, double>::Const::Rational<465,1024>,CAS::General<double, double>::Const::Rational<767,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<862,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-552,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
      };
      struct shoulder_right_back {
        static constexpr bool VARIABLE = false;
        using parent = body_right_back;
        using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Rational<-862,1024>,CAS::General<double, double>::Const::Rational<492,1024>,CAS::General<double, double>::Const::Rational<-250,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<465,1024>,CAS::General<double, double>::Const::Rational<912,1024>,CAS::General<double, double>::Const::Rational<117119,1024>,CAS::General<double, double>::Const::Rational<552,1024>,CAS::General<double, double>::Const::Rational<767,1024>,CAS::General<double, double>::Const::Rational<-392,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
      };
      struct arm_right_back {
        static constexpr bool VARIABLE = false;
        using parent = shoulder_right_back;
        using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<1023,1024>,CAS::General<double, double>::Const::Rational<8,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<33700,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<8,1024>,CAS::General<double, double>::Const::Rational<-1023,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
      };
      struct forearm_right_back {
        static constexpr bool VARIABLE = false;
        using parent = arm_right_back;
        using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<-1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<1023,1024>,CAS::General<double, double>::Const::Rational<8,1024>,CAS::General<double, double>::Const::Rational<92039,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<8,1024>,CAS::General<double, double>::Const::Rational<-1023,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
      };
    };
  }
  namespace objects {
    struct armature {
      static constexpr bool VARIABLE = false;
      using parent = void;
      using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<-1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<-1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
      struct bones {
        struct body_left_front : public armatures::armature::body_left_front {
          static constexpr bool VARIABLE = false;
          using parent = armature;
          using last = body_left_front;
          struct endpoint {
            static constexpr bool VARIABLE = false;
            using parent = last;
            using matrix = CAS::General<double, double>::Space3D::Translation<CAS::General<double, double>::Const::Rational<20730,1024>,CAS::General<double, double>::Const::Rational<66009,1024>,CAS::General<double, double>::Const::Rational<-69239,1024>>;
          };
        };
        struct shoulder_left_front : public armatures::armature::shoulder_left_front {
          static constexpr bool VARIABLE = false;
          using parent = body_left_front::last;
          struct ry {
            static constexpr bool VARIABLE = true;
            using parent = shoulder_left_front;
            using matrix = CAS::General<double, double>::Space3D::RotationY;
          };
          using last = ry;
          struct endpoint {
            static constexpr bool VARIABLE = false;
            using parent = last;
            using matrix = CAS::General<double, double>::Space3D::Translation<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<33700,1024>,CAS::General<double, double>::Const::Integer<0>>;
          };
        };
        struct arm_left_front : public armatures::armature::arm_left_front {
          static constexpr bool VARIABLE = false;
          using parent = shoulder_left_front::last;
          struct rz {
            static constexpr bool VARIABLE = true;
            using parent = arm_left_front;
            using matrix = CAS::General<double, double>::Space3D::RotationZ;
          };
          using last = rz;
          struct endpoint {
            static constexpr bool VARIABLE = false;
            using parent = last;
            using matrix = CAS::General<double, double>::Space3D::Translation<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<92039,1024>,CAS::General<double, double>::Const::Integer<0>>;
          };
        };
        struct forearm_left_front : public armatures::armature::forearm_left_front {
          static constexpr bool VARIABLE = false;
          using parent = arm_left_front::last;
          struct rx {
            static constexpr bool VARIABLE = true;
            using parent = forearm_left_front;
            using matrix = CAS::General<double, double>::Space3D::RotationX;
          };
          using last = rx;
          struct endpoint {
            static constexpr bool VARIABLE = false;
            using parent = last;
            using matrix = CAS::General<double, double>::Space3D::Translation<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<117449,1024>,CAS::General<double, double>::Const::Integer<0>>;
          };
        };
        struct body_right_front : public armatures::armature::body_right_front {
          static constexpr bool VARIABLE = false;
          using parent = armature;
          using last = body_right_front;
          struct endpoint {
            static constexpr bool VARIABLE = false;
            using parent = last;
            using matrix = CAS::General<double, double>::Space3D::Translation<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<97883,1024>,CAS::General<double, double>::Const::Integer<0>>;
          };
        };
        struct shoulder_right_front : public armatures::armature::shoulder_right_front {
          static constexpr bool VARIABLE = false;
          using parent = body_right_front::last;
          struct ry {
            static constexpr bool VARIABLE = true;
            using parent = shoulder_right_front;
            using matrix = CAS::General<double, double>::Space3D::RotationY;
          };
          using last = ry;
          struct endpoint {
            static constexpr bool VARIABLE = false;
            using parent = last;
            using matrix = CAS::General<double, double>::Space3D::Translation<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<33700,1024>,CAS::General<double, double>::Const::Integer<0>>;
          };
        };
        struct arm_right_front : public armatures::armature::arm_right_front {
          static constexpr bool VARIABLE = false;
          using parent = shoulder_right_front::last;
          struct rz {
            static constexpr bool VARIABLE = true;
            using parent = arm_right_front;
            using matrix = CAS::General<double, double>::Space3D::RotationZ;
          };
          using last = rz;
          struct endpoint {
            static constexpr bool VARIABLE = false;
            using parent = last;
            using matrix = CAS::General<double, double>::Space3D::Translation<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<92039,1024>,CAS::General<double, double>::Const::Integer<0>>;
          };
        };
        struct forearm_right_front : public armatures::armature::forearm_right_front {
          static constexpr bool VARIABLE = false;
          using parent = arm_right_front::last;
          struct rx {
            static constexpr bool VARIABLE = true;
            using parent = forearm_right_front;
            using matrix = CAS::General<double, double>::Space3D::RotationX;
          };
          using last = rx;
          struct endpoint {
            static constexpr bool VARIABLE = false;
            using parent = last;
            using matrix = CAS::General<double, double>::Space3D::Translation<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<117449,1024>,CAS::General<double, double>::Const::Integer<0>>;
          };
        };
        struct body_left_back : public armatures::armature::body_left_back {
          static constexpr bool VARIABLE = false;
          using parent = armature;
          using last = body_left_back;
          struct endpoint {
            static constexpr bool VARIABLE = false;
            using parent = last;
            using matrix = CAS::General<double, double>::Space3D::Translation<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<117119,1024>,CAS::General<double, double>::Const::Integer<0>>;
          };
        };
        struct shoulder_left_back : public armatures::armature::shoulder_left_back {
          static constexpr bool VARIABLE = false;
          using parent = body_left_back::last;
          struct ry {
            static constexpr bool VARIABLE = true;
            using parent = shoulder_left_back;
            using matrix = CAS::General<double, double>::Space3D::RotationY;
          };
          using last = ry;
          struct endpoint {
            static constexpr bool VARIABLE = false;
            using parent = last;
            using matrix = CAS::General<double, double>::Space3D::Translation<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<33700,1024>,CAS::General<double, double>::Const::Integer<0>>;
          };
        };
        struct arm_left_back : public armatures::armature::arm_left_back {
          static constexpr bool VARIABLE = false;
          using parent = shoulder_left_back::last;
          struct rz {
            static constexpr bool VARIABLE = true;
            using parent = arm_left_back;
            using matrix = CAS::General<double, double>::Space3D::RotationZ;
          };
          using last = rz;
          struct endpoint {
            static constexpr bool VARIABLE = false;
            using parent = last;
            using matrix = CAS::General<double, double>::Space3D::Translation<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<92039,1024>,CAS::General<double, double>::Const::Integer<0>>;
          };
        };
        struct forearm_left_back : public armatures::armature::forearm_left_back {
          static constexpr bool VARIABLE = false;
          using parent = arm_left_back::last;
          struct rx {
            static constexpr bool VARIABLE = true;
            using parent = forearm_left_back;
            using matrix = CAS::General<double, double>::Space3D::RotationX;
          };
          using last = rx;
          struct endpoint {
            static constexpr bool VARIABLE = false;
            using parent = last;
            using matrix = CAS::General<double, double>::Space3D::Translation<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<117449,1024>,CAS::General<double, double>::Const::Integer<0>>;
          };
        };
        struct body_right_back : public armatures::armature::body_right_back {
          static constexpr bool VARIABLE = false;
          using parent = armature;
          using last = body_right_back;
          struct endpoint {
            static constexpr bool VARIABLE = false;
            using parent = last;
            using matrix = CAS::General<double, double>::Space3D::Translation<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<117119,1024>,CAS::General<double, double>::Const::Integer<0>>;
          };
        };
        struct shoulder_right_back : public armatures::armature::shoulder_right_back {
          static constexpr bool VARIABLE = false;
          using parent = body_right_back::last;
          struct ry {
            static constexpr bool VARIABLE = true;
            using parent = shoulder_right_back;
            using matrix = CAS::General<double, double>::Space3D::RotationY;
          };
          using last = ry;
          struct endpoint {
            static constexpr bool VARIABLE = false;
            using parent = last;
            using matrix = CAS::General<double, double>::Space3D::Translation<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<33700,1024>,CAS::General<double, double>::Const::Integer<0>>;
          };
        };
        struct arm_right_back : public armatures::armature::arm_right_back {
          static constexpr bool VARIABLE = false;
          using parent = shoulder_right_back::last;
          struct rz {
            static constexpr bool VARIABLE = true;
            using parent = arm_right_back;
            using matrix = CAS::General<double, double>::Space3D::RotationZ;
          };
          using last = rz;
          struct endpoint {
            static constexpr bool VARIABLE = false;
            using parent = last;
            using matrix = CAS::General<double, double>::Space3D::Translation<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<92039,1024>,CAS::General<double, double>::Const::Integer<0>>;
          };
        };
        struct forearm_right_back : public armatures::armature::forearm_right_back {
          static constexpr bool VARIABLE = false;
          using parent = arm_right_back::last;
          struct rx {
            static constexpr bool VARIABLE = true;
            using parent = forearm_right_back;
            using matrix = CAS::General<double, double>::Space3D::RotationX;
          };
          using last = rx;
          struct endpoint {
            static constexpr bool VARIABLE = false;
            using parent = last;
            using matrix = CAS::General<double, double>::Space3D::Translation<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<117449,1024>,CAS::General<double, double>::Const::Integer<0>>;
          };
        };
      };
    };
    struct Camera {
      static constexpr bool VARIABLE = false;
      using parent = void;
      using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Rational<702,1024>,CAS::General<double, double>::Const::Rational<-324,1024>,CAS::General<double, double>::Const::Rational<670,1024>,CAS::General<double, double>::Const::Rational<7660,1024>,CAS::General<double, double>::Const::Rational<745,1024>,CAS::General<double, double>::Const::Rational<319,1024>,CAS::General<double, double>::Const::Rational<-625,1024>,CAS::General<double, double>::Const::Rational<-6663,1024>,CAS::General<double, double>::Const::Rational<-11,1024>,CAS::General<double, double>::Const::Rational<916,1024>,CAS::General<double, double>::Const::Rational<455,1024>,CAS::General<double, double>::Const::Rational<5471,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
    };
    struct forearm_u_left_back {
      static constexpr bool VARIABLE = false;
      using parent = armatures::armature::forearm_left_back;
      using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-1023,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-86961,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-1023,1024>,CAS::General<double, double>::Const::Rational<-209553,1024>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-105035,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
    };
    struct forearm_u_left_front {
      static constexpr bool VARIABLE = false;
      using parent = armatures::armature::forearm_left_front;
      using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-1023,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-87043,1024>,CAS::General<double, double>::Const::Rational<19,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-1023,1024>,CAS::General<double, double>::Const::Rational<-207939,1024>,CAS::General<double, double>::Const::Rational<1023,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<19,1024>,CAS::General<double, double>::Const::Rational<86018,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
    };
    struct forearm_u_right_back {
      static constexpr bool VARIABLE = false;
      using parent = armatures::armature::forearm_right_back;
      using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-1023,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<86957,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<-1>,CAS::General<double, double>::Const::Rational<-209552,1024>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-105039,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
    };
    struct forearm_u_right_front {
      static constexpr bool VARIABLE = false;
      using parent = armatures::armature::forearm_right_front;
      using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-1023,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<86961,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-1023,1024>,CAS::General<double, double>::Const::Rational<-209552,1024>,CAS::General<double, double>::Const::Rational<1023,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<82854,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
    };
    struct Lamp {
      static constexpr bool VARIABLE = false;
      using parent = void;
      using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Rational<-297,1024>,CAS::General<double, double>::Const::Rational<-789,1024>,CAS::General<double, double>::Const::Rational<579,1024>,CAS::General<double, double>::Const::Rational<4174,1024>,CAS::General<double, double>::Const::Rational<978,1024>,CAS::General<double, double>::Const::Rational<-204,1024>,CAS::General<double, double>::Const::Rational<223,1024>,CAS::General<double, double>::Const::Rational<1029,1024>,CAS::General<double, double>::Const::Rational<-56,1024>,CAS::General<double, double>::Const::Rational<619,1024>,CAS::General<double, double>::Const::Rational<813,1024>,CAS::General<double, double>::Const::Rational<6045,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
    };
    struct servo_shouder2_left_front {
      static constexpr bool VARIABLE = false;
      using parent = armatures::armature::arm_left_front;
      using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<86963,1024>,CAS::General<double, double>::Const::Rational<-26,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-1023,1024>,CAS::General<double, double>::Const::Rational<-94290,1024>,CAS::General<double, double>::Const::Rational<-1023,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<26,1024>,CAS::General<double, double>::Const::Rational<-81890,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
    };
    struct servo_shoulder2_left_back {
      static constexpr bool VARIABLE = false;
      using parent = armatures::armature::arm_left_back;
      using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<1023,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<86944,1024>,CAS::General<double, double>::Const::Rational<8,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-1023,1024>,CAS::General<double, double>::Const::Rational<-92936,1024>,CAS::General<double, double>::Const::Rational<-1023,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-8,1024>,CAS::General<double, double>::Const::Rational<104313,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
    };
    struct servo_shoulder2_right_back {
      static constexpr bool VARIABLE = false;
      using parent = armatures::armature::arm_right_back;
      using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<1023,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-86947,1024>,CAS::General<double, double>::Const::Rational<8,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-1023,1024>,CAS::General<double, double>::Const::Rational<-92936,1024>,CAS::General<double, double>::Const::Rational<-1023,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-8,1024>,CAS::General<double, double>::Const::Rational<104311,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
    };
    struct servo_shoulder2_right_front {
      static constexpr bool VARIABLE = false;
      using parent = armatures::armature::arm_right_front;
      using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<1023,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-86944,1024>,CAS::General<double, double>::Const::Rational<-8,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-1023,1024>,CAS::General<double, double>::Const::Rational<-92762,1024>,CAS::General<double, double>::Const::Rational<-1023,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<8,1024>,CAS::General<double, double>::Const::Rational<-82132,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
    };
    struct shoulder_u_left_back {
      static constexpr bool VARIABLE = false;
      using parent = armatures::armature::shoulder_left_back;
      using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<-1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<104316,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-1023,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-86945,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Rational<93,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
    };
    struct shoulder_u_left_front {
      static constexpr bool VARIABLE = false;
      using parent = armatures::armature::shoulder_left_front;
      using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Rational<-1023,1024>,CAS::General<double, double>::Const::Rational<8,1024>,CAS::General<double, double>::Const::Rational<1,1024>,CAS::General<double, double>::Const::Rational<-81217,1024>,CAS::General<double, double>::Const::Rational<-8,1024>,CAS::General<double, double>::Const::Rational<-1023,1024>,CAS::General<double, double>::Const::Rational<5,1024>,CAS::General<double, double>::Const::Rational<-87615,1024>,CAS::General<double, double>::Const::Rational<1,1024>,CAS::General<double, double>::Const::Rational<5,1024>,CAS::General<double, double>::Const::Rational<1023,1024>,CAS::General<double, double>::Const::Rational<600,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
    };
    struct shoulder_u_right_back {
      static constexpr bool VARIABLE = false;
      using parent = armatures::armature::shoulder_right_back;
      using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-1023,1024>,CAS::General<double, double>::Const::Rational<-66,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<1023,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-86945,1024>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-104316,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
    };
    struct shoulder_u_right_front {
      static constexpr bool VARIABLE = false;
      using parent = armatures::armature::shoulder_right_front;
      using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<-1>,CAS::General<double, double>::Const::Rational<-90,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<1023,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<-86945,1024>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<82134,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
    };
    struct spine {
      static constexpr bool VARIABLE = false;
      using parent = armature;
      using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
    };
    struct arm_left_back {
      static constexpr bool VARIABLE = false;
      using parent = servo_shoulder2_left_back;
      using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
    };
    struct arm_left_front {
      static constexpr bool VARIABLE = false;
      using parent = servo_shouder2_left_front;
      using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<1023,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
    };
    struct arm_right_back {
      static constexpr bool VARIABLE = false;
      using parent = servo_shoulder2_right_back;
      using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
    };
    struct arm_right_front {
      static constexpr bool VARIABLE = false;
      using parent = servo_shoulder2_right_front;
      using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
    };
    struct forearm_left_back {
      static constexpr bool VARIABLE = false;
      using parent = forearm_u_left_back;
      using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
    };
    struct forearm_left_front {
      static constexpr bool VARIABLE = false;
      using parent = forearm_u_left_front;
      using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<1023,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
    };
    struct forearm_right_back {
      static constexpr bool VARIABLE = false;
      using parent = forearm_u_right_back;
      using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
    };
    struct forearm_right_front {
      static constexpr bool VARIABLE = false;
      using parent = forearm_u_right_front;
      using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
    };
    struct optoforce_hub_base {
      static constexpr bool VARIABLE = false;
      using parent = spine;
      using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
    };
    struct power_battery_base {
      static constexpr bool VARIABLE = false;
      using parent = spine;
      using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
    };
    struct servo_arm_left_back {
      static constexpr bool VARIABLE = false;
      using parent = arm_left_back;
      using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
    };
    struct servo_arm_left_front {
      static constexpr bool VARIABLE = false;
      using parent = arm_left_front;
      using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<1023,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
    };
    struct servo_arm_right_back {
      static constexpr bool VARIABLE = false;
      using parent = arm_right_back;
      using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
    };
    struct servo_arm_right_front {
      static constexpr bool VARIABLE = false;
      using parent = arm_right_front;
      using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
    };
    struct shoulder_left_back {
      static constexpr bool VARIABLE = false;
      using parent = spine;
      using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
    };
    struct shoulder_left_front {
      static constexpr bool VARIABLE = false;
      using parent = spine;
      using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
    };
    struct shoulder_right_back {
      static constexpr bool VARIABLE = false;
      using parent = spine;
      using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
    };
    struct shoulder_right_front {
      static constexpr bool VARIABLE = false;
      using parent = spine;
      using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
    };
    struct foot_left_back {
      static constexpr bool VARIABLE = false;
      using parent = forearm_left_back;
      using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
    };
    struct foot_left_front {
      static constexpr bool VARIABLE = false;
      using parent = forearm_left_front;
      using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<1023,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
    };
    struct foot_right_back {
      static constexpr bool VARIABLE = false;
      using parent = forearm_right_back;
      using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
    };
    struct foot_right_front {
      static constexpr bool VARIABLE = false;
      using parent = forearm_right_front;
      using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
    };
    struct optoforce_base_left_back {
      static constexpr bool VARIABLE = false;
      using parent = foot_left_back;
      using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
    };
    struct optoforce_base_left_front {
      static constexpr bool VARIABLE = false;
      using parent = foot_left_front;
      using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<1023,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
    };
    struct optoforce_base_right_back {
      static constexpr bool VARIABLE = false;
      using parent = foot_right_back;
      using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
    };
    struct optoforce_base_right_front {
      static constexpr bool VARIABLE = false;
      using parent = foot_right_front;
      using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
    };
    struct optoforce_hub {
      static constexpr bool VARIABLE = false;
      using parent = optoforce_hub_base;
      using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
    };
    struct optoforce_left_back {
      static constexpr bool VARIABLE = false;
      using parent = optoforce_base_left_back;
      using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
    };
    struct optoforce_left_front {
      static constexpr bool VARIABLE = false;
      using parent = optoforce_base_left_front;
      using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Rational<1023,1024>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
    };
    struct optoforce_right_back {
      static constexpr bool VARIABLE = false;
      using parent = optoforce_base_right_back;
      using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
    };
    struct optoforce_right_front {
      static constexpr bool VARIABLE = false;
      using parent = optoforce_base_right_front;
      using matrix = CAS::General<double, double>::Matrix<4,4>::Any<CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<0>,CAS::General<double, double>::Const::Integer<1>>;
    };
  }
}

