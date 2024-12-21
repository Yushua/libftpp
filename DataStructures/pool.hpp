#ifndef POOL_HPP
#define POOL_HPP

#include <vector>
#include <memory>
#include <stdexcept>
#include <utility>

/**
    Manages a collection of reusable templated TType objects,
    provided to the user via a Pool::Object class. This class
    handles the acquirable pointer, and releases it back to the pool
    when needed, calling the destructor of the TType object but
    without deallocating the memory.
 */
template <typename TType>
class Pool {
public:
    class Object {
    public:
        explicit Object(TType* ptr, Pool* pool)
            : m_ptr(ptr), m_pool(pool), m_active(true) {}

        Object(const Object&) = delete;
        Object& operator=(const Object&) = delete;

        Object(Object&& other) noexcept
            : m_ptr(other.m_ptr), m_pool(other.m_pool), m_active(other.m_active) {
            other.m_ptr = nullptr;
            other.m_pool = nullptr;
            other.m_active = false;
        }

        Object& operator=(Object&& other) noexcept {
            if (this != &other) {
                release();
                m_ptr = other.m_ptr;
                m_pool = other.m_pool;
                m_active = other.m_active;

                other.m_ptr = nullptr;
                other.m_pool = nullptr;
                other.m_active = false;
            }
            return *this;
        }

        ~Object() { release(); }

        TType* operator->() const {
            if (!m_active) {
                throw std::runtime_error("Accessing a released object!");
            }
            return m_ptr;
        }

        TType& operator*() const {
            if (!m_active) {
                throw std::runtime_error("Accessing a released object!");
            }
            return *m_ptr;
        }

    private:
        void release() {
            if (m_active && m_pool) {
                m_pool->releaseObject(m_ptr);
                m_active = false;
            }
        }

        TType* m_ptr;
        Pool* m_pool;
        bool m_active;
    };

    Pool() = default;

    /**
         Allocates a certain number of TType objects withing the Pool.
     */
    void resize(const size_t& numberOfObjects) {
        m_objects.clear();
        m_availableObjects.clear();
        for (size_t i = 0; i < numberOfObjects; ++i) {
            m_objects.push_back(std::make_unique<TType>());
            m_availableObjects.push_back(m_objects.back().get());
        }
    }

    /**
        Creates a Pool::Object containing
        a pre-allocated object, using the constructor with parameters
        as defined by TArgs definition.
    */
    template <typename... TArgs>
    Object acquire(TArgs&&... args) {
        if (m_availableObjects.empty()) {
            throw std::runtime_error("No available objects in the pool!");
        }

        TType* obj = m_availableObjects.back();
        m_availableObjects.pop_back();

        new (obj) TType(std::forward<TArgs>(args)...);

        return Object(obj, this);
    }

private:
    /**
        Returns the pointer stored withing
        the Pool::Object.
    */
    void releaseObject(TType* obj) {
        obj->~TType();
        m_availableObjects.push_back(obj);
    }

    std::vector<std::unique_ptr<TType>> m_objects;
    std::vector<TType*> m_availableObjects;
};

#endif // POOL_HPP