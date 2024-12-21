#ifndef MEMENTO_HPP
#define MEMENTO_HPP

#include <sstream>
#include <string>

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

    virtual Snapshot save() const {
        Snapshot snapshot;
        _saveToSnapshot(snapshot);
        return snapshot;
    }

    virtual void load(const Snapshot& snapshot) {
        _loadFromSnapshot(const_cast<Snapshot&>(snapshot));
    }

protected:
    virtual void _saveToSnapshot(Snapshot& snapshot) const = 0;
    virtual void _loadFromSnapshot(Snapshot& snapshot) = 0;
};

#endif