class Log {

public:

    virtual void clear() = 0;
    virtual void writeLine(Loggable* obj) = 0;
    virtual void writeLine(string str) = 0;

};