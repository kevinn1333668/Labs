#include <iostream>
#define N_MAX 1000


class BigInt {
    char m_value[N_MAX];
    short m_size = 0;

    public:
        BigInt() = default; 

        BigInt(const std::string& value) {
            size_t len = value.length();
            for(int i=0 ; i < len ; i++)
            {
                m_value[i] = value[len-i-1] - '0';
            }
            for(int i=len ; i<N_MAX ; i++)
            {
                m_value[i] = 0;
            }
            m_size = len;
        }


        BigInt& operator+=(const BigInt& other)
        {
            short size = std::max(m_size, other.m_size);
            for(int i=0 ; i<size ; i++)
            {
                m_value[i] += other.m_value[i];
                if (m_value[i] > 9)
                {
                    m_value[i] -= 10;
                    m_value[i+1]++;
                }
            }
            m_size = size;

            return *this;
        }

        BigInt operator+(const BigInt& other)
        {
            BigInt result(*this);
            result += other;
            return result;
        }

    BigInt& operator*=(const BigInt& other) {
        char result[N_MAX] = {0};
        int newSize = m_size + other.m_size;

        for (int i = 0; i < m_size; i++)
            for (int j = 0; j < other.m_size; j++)
                result[i + j] += m_value[i] * other.m_value[j];

        for (int i = 0; i < newSize - 1; i++) {
            result[i + 1] += result[i] / 10;
            result[i] %= 10;
        }

        while (newSize > 1 && result[newSize - 1] == 0) 
            newSize--;

        std::copy(result, result + newSize, m_value);
        m_size = newSize;

        return *this;
    }
    BigInt operator*(const BigInt& other)
    {
        BigInt result(*this);
        result *= other;
        return result;
    }

    bool operator<(const BigInt& other)
    {
        if(m_size < other.m_size)
            return true;
        else if(m_size > other.m_size)
            return false;
        for(int i=m_size-1 ; i>=0 ; i--)
        {
            if(m_value[i] < other.m_value[i])
                return true;
            else if(m_value[i] > other.m_value[i])
                return false;
        }
        return false;
    }

    bool operator>(const BigInt& other)
    {
        if(m_size > other.m_size)
            return true;
        else if(m_size < other.m_size)
            return false;
        for(int i=m_size-1 ; i>=0 ; i--)
        {
            if(m_value[i] > other.m_value[i])
                return true;
            else if(m_value[i] < other.m_value[i])
                return false;
        }
        return false;        
    }

    bool operator>=(const BigInt& other)
    {
        return !(*this < other);
    }

    bool operator<=(const BigInt& other)
    {
        return !(*this > other);
    }

    bool operator==(const BigInt& other)
    {
        return *this <= other && *this >= other;
    }    

    friend std::ostream& operator<<(std::ostream& out, const BigInt& other);

        
};

std::istream& operator>>(std::istream& in, BigInt& other)
    {
        std::string s;
        in >> s;
        other = BigInt(s);
        return in;        
    }

std::ostream& operator<<(std::ostream& out, const BigInt& other)
    {
        for(int i=0 ; i < other.m_size ; i++)
        {
            out << static_cast<short>(other.m_value[other.m_size - i - 1]);
        }
        return out;        
    }


int main() {
    BigInt x("51");
    BigInt y("51");
    BigInt z = x * y;
    bool q = x == y;
    std::cout << q << std::endl;

}