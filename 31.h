/**
* 31.基于多个对象的虚函数
*/

namespace thirtyOne {
    //考虑两个对象碰撞的问题
    namespace Origin {
        class GameObject {
        };

        class SpaceShip : public GameObject {
        };

        class SpaceStation : public GameObject {
        };

        class Asteroid : public GameObject {
        };

        void checkForCollision(GameObject &object1, GameObject &object2) {
            processCollision(object1, object2);
            // 当我们调用processCollision的时候,该函数取决于两个不同 对象,但是这个函数并不知道其object1和object2的真实类型
            // 这个时候就要基于多个对象设计虚函数
        }
    }
    //解决方法有很多:
    //1.使用虚函数+RTTI:
    namespace virtual_RTTI {
        class GameObject {
        public:
            virtual void collide(GameObject &otherObject) = 0;
        };

        class SpaceShip : public GameObject {
        public:
            virtual void collide(GameObject &otherObject);
        };

        void collide(GameObject &otherObject) {
            const type_info &objectType = typeid(otherObject);
            if (objectType == typeid(SpaceShip)) {
                SpaceShip &ss = static_cast<SpaceShip &>(otherObject);
            } else if (objectType == typeid(SpaceStation)) {
                SpaceStation &ss = static_cast<SpaceStation &>(otherObject);
            } else if (objectType == typeid(Asteroid)) {
                Asteroid &ss = static_cast<Asteroid &>(otherObject);
            }
        }
    }
    //2.只使用虚函数:
    namespace virtualFunction {
        class SpaceShip;

        class SpaceStation;

        class Asteroid;

        class GameObject {
            virtual void collide(GameObject &otherObject) = 0;

            virtual void collide(SpaceShip &otherObject) = 0;

            virtual void collide(SpaceStation &otherObject) = 0;

            virtual void collide(Asteroid &otherObject) = 0;
        };
    }
    //3.模拟虚函数表(对继承体系中的函数做一些修改):
    class SpaceShip : public GameObject {
    public:
        virtual void collide(GameObject &otherObject);

        virtual void hitSpaceShip(SpaceShip &otherObject);

        virtual void hitSpaceStation(SpaceStation &otherObject);

        virtual void hitAsteroid(Asteroid &otherObject);
    };

    SpaceShip::HitMap *SpaceShip::initializeCollisionMap() {
        HitMap *phm = new HitMap;
        (*phm)["SpaceShip"] = &hitSpaceShip;
        (*phm)["SpaceStation"] = &hitSpaceStation;
        (*phm)["Asteroid"] = &hitAsteroid;
        return phm;
    };


}