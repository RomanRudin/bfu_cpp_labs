#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class DataReader {
protected:
    ifstream m_in;
    string m_filename;
    vector<float> m_data;
    int m_n;

public:
    DataReader(const string& filename) : m_filename(filename), m_n(0) {}
    virtual ~DataReader() {}

    virtual bool Open() = 0;
    void Close() { m_in.close(); }

    virtual void Read() = 0;
    virtual void Write() = 0;

    void GetData(vector<float>& buf, int& n) {
        n = m_n;
        buf = m_data;
    }
};

class TxtReader : public DataReader {
public:
    TxtReader(const string& filename) : DataReader(filename) {}
    virtual ~TxtReader() {}

    bool Open() override {
        m_in.open(m_filename);
        if (!m_in.is_open()) return false;
        return true;
    }

    void Read() override {
        int tmp;
        m_in >> tmp;
        m_n = tmp;
        m_data.resize(m_n);
        for (int i = 0; i < m_n; i++) {
            int tmp;
            m_in >> tmp;
            m_data[i] = tmp;
        }
    }

    void Write() override {}
};

class BinReader : public DataReader {
public:
    BinReader(const string& filename) : DataReader(filename) {}
    virtual ~BinReader() {}

    bool Open() override {
        m_in.open(m_filename, ios::binary);
        if (!m_in.is_open()) return false;
        return true;
    }

    void Read() override {
        m_in.read((char*)&m_n, sizeof(m_n));
        m_data.resize(m_n);
        m_in.read((char*)m_data.data(), sizeof(float) * m_n);
    }

    void Write() override {}
};

class BinfReader : public DataReader {
public:
    BinfReader(const string& filename) : DataReader(filename) {}
    virtual ~BinfReader() {}

    bool Open() override {
        m_in.open(m_filename, ios::binary);
        if (!m_in.is_open()) return false;
        return true;
    }

    void Read() override {
        uint32_t size;
        m_in.read((char*)&size, sizeof(size));
        m_n = size / sizeof(float);
        m_data.resize(m_n);
        m_in.read((char*)m_data.data(), sizeof(float) * m_n);
    }

    void Write() override {}
};

DataReader* Factory(const string& filename) {
    string extension = filename.substr(filename.find_last_of('.') + 1);

    if (extension == "txt")
        return new TxtReader(filename);
    else if (extension == "bin")
        return new BinReader(filename);
    else if (extension == "binf")
        return new BinfReader(filename);
    return nullptr;
}

int main() {
    vector<float> data;
    int n;

    DataReader* reader = Factory("input2.binf");
    if (reader == nullptr) return -1;
    reader->Open();
    reader->Read();
    reader->GetData(data, n);

    for (int i = 0; i < n; i++) {
        cout << data[i] << endl;
    }

    delete reader;

    return 0;
}
