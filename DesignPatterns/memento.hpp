#ifndef MEMENTO_HPP
#define MEMENTO_HPP

#include <sstream>
#include <string>

/**
    Stores the current state of an object. Must be inherited by the "saveable" class.
 */
class Memento {
public:

    class Snapshot {
    private:
        std::stringstream stream;

    public:
        template<typename T>
        Snapshot& operator<<(const T& data) {
            stream << data << " ";
            return *this;
        }

        template<typename T>
        Snapshot& operator>>(T& data) {
            stream >> data;
            return *this;
        }
    };
    /**
        Save the current state of the object.
     */
    virtual Snapshot save() const {
        Snapshot snapshot;
        _saveToSnapshot(snapshot);
        return snapshot;
    }

    /**
        Loads the provided state.
    */
    virtual void load(const Snapshot& snapshot) {
        _loadFromSnapshot(const_cast<Snapshot&>(snapshot));
    }

protected:
    /**
        Saves the desired data into the snapshot.
    */
    virtual void _saveToSnapshot(Snapshot& snapshot) const = 0;
    /**
        Loads data from the snapshot.
    */
    virtual void _loadFromSnapshot(Snapshot& snapshot) = 0;
};

#endif