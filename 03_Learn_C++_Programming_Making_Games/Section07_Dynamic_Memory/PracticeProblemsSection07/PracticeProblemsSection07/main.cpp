#include <iostream>
#include <assert.h>
using namespace std;

class String
{
private:
    char* mChar = nullptr;
    size_t mLength = 0;

public:
    String() : String("Hello") {}
    String(const char* string);
    ~String() { delete[] mChar; }

    String(const String& copiedString);

    bool Init(size_t length);
    friend std::ostream& operator<<(std::ostream& consoleOut, const String& char1);

    inline size_t getLength() const { return mLength; }
    char getChar(size_t index) const { return mChar[index]; }

    bool operator==(const String& otherString)const;
    String& operator=(String& string);
    String& operator=(const char* character);
    String operator+(String& appendedString);
    String operator+(const char appendedChar);

    const char* returnConstChar() const { return mChar; }
    String concatenateStrings(String& otherString) { return *this + otherString; }
    size_t subString(const String& subString) const;
    String returnSubString(const size_t& startPos, const size_t& stringLength) const;
    void equalString(const String& compareString) const;
};

String::String(const char* string)
{
    mLength = strlen(string);
    if (mLength == 0)
        mChar = nullptr;
    else
    {
        bool result = Init(mLength);
        assert(mChar && "Couldn't allocate memory");

        strcpy_s(mChar, mLength + 1, string);
    }
}

String::String(const String& copiedString)
{
    bool result = Init(strlen(copiedString.mChar));
    assert(result && "In Copy constructor: Couldn't allocate memory");

    strcpy_s(mChar, mLength + 1, copiedString.mChar);
}

bool String::Init(size_t length)
{
    if (length == 0)
        return false;

    mLength = length;
    if (mChar != nullptr)
        delete[] mChar;

    mChar = new char[mLength + 1]; // Plus 1 due to slot for termination character
    if (!mChar)
    {
        assert(mChar && "In Init malfunction");
        return false;
    }

    mChar[mLength] = 0;		// Null Termination of a char-array
    return true;
}

bool String::operator==(const String& otherString)const
{
    if (mLength != otherString.mLength)
        return false;

    for (size_t i = 0; i < mLength; i++)
    {
        if (mChar[i] != otherString.mChar[i])
            return false;
    }
    return true;
}

String& String::operator=(String& string)
{
    if (this != &string)
    {
        bool result = Init(strlen(string.mChar));

        if (!result)
            assert(mChar && "In = Operator Overload of Class");

        strcpy_s(mChar, mLength + 1, string.mChar);
    }

    return *this;
}

String& String::operator=(const char* cString)
{
    if (mChar != cString)
    {
        Init(strlen(cString));
        strcpy_s(mChar, mLength + 1, cString);

        return *this;
    }
    else
        return *this;
}


String String::operator+(String& appendedString)
{
    String plusString = *this;

    bool result = Init(mLength + appendedString.mLength);
    if (!result)
        assert(result && "Error in + operater overload");

    strcpy_s(mChar, plusString.mLength + 1, plusString.mChar);

    int j = 0;
    for (size_t i = plusString.mLength; i < mLength; i++)
    {
        mChar[i] = appendedString.mChar[j];
        j++;
    }

    return *this;
}

String String::operator+(const char appendedChar)
{
    String storage = *this;
    Init(mLength + 1);

    strcpy_s(mChar, storage.mLength + 1, storage.mChar);

    mChar[mLength - 1] = appendedChar;

    return *this;
}

size_t String::subString(const String& subString) const
{
    if (subString.mLength > mLength)
        return 199;

    size_t index = 0;
    char* buffer = new char[subString.mLength + 1];

    int j = 0;
    for (int i = 0; i < mLength; ++i)
    {
        if (mChar[i] == subString.mChar[j] && j < subString.mLength)
        {
            buffer[j] = subString.mChar[j];
            index = i + 1;
            j++;
        }

    }
    index -= j;
    j = 1;

    for (size_t i = 0; i < subString.mLength; ++i)
    {
        if (buffer[i] == subString.mChar[i])
        {
            if (j == subString.mLength)
            {
                delete[] buffer;
                return index;
            }
            j++;
        }
    }

    delete[] buffer;
    return 9999;
}

String String::returnSubString(const size_t& startPos, const size_t& stringLength) const
{
    String subString;
    subString.Init(stringLength);

    if (stringLength > mLength)
        return subString = "Substring too long";

    for (size_t i = startPos, j = 0; j < stringLength; i++, j++)
        subString.mChar[j] = mChar[i];

    return subString;
}

std::ostream& operator<<(std::ostream& consoleOut, const String& char1)
{
    consoleOut << char1.mChar;
    return consoleOut;
}

int main()
{
    String firstString("Bye");
    String secondString("Second String");
    String thirdString = "Ei3Wortfasdf!";
    String newString = "New String";
    String copy = firstString;

    copy = "Copied String"; //Editing the copied String without changing the origin String

    cout << endl << firstString << endl;
    cout << endl << secondString << endl;
    cout << endl << thirdString << endl;
    cout << endl << copy << endl;

    cout << endl << "Length of firstString: " << firstString.getLength() << endl;
    cout << endl << "Get Character at Index 4 of secondString: " << secondString.getChar(4) << endl;

    cout << endl << "Appended the first and third String: " << firstString + thirdString << endl;
    cout << endl << "Appended a char to the first String: " << firstString + '!' << endl;

    cout << endl << "Concatenated Strings by method: " << firstString.concatenateStrings(firstString) << endl;

    cout << endl << "Found substring at index: " << thirdString.subString("E") << endl;

    cout << endl << "Return a substring at index and length: " << thirdString.returnSubString(0, 5) << endl;

    if (firstString == secondString)
        cout << endl << "Strings are equal" << endl;
    else
        cout << endl << "Strings are not equal" << endl;

    cin.get();
}