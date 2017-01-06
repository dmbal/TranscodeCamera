#pragma once
#include <sstream>
#include <string>
#include <atlbase.h>

class DebugInfoStorage
{
public:
    DebugInfoStorage::DebugInfoStorage()
    {

    }
    DebugInfoStorage::~DebugInfoStorage()
    {

    }

    void AppendString(std::wstring info)
    {
        std::wstring strng;
        std::wstringstream strstream;
        _strstream << info;
        strng = strstream.str();
    }

    void AppendGuid(std::wstring info, GUID guid)
    {
        std::wstring strng;
        std::wstringstream strstream;
        _strstream << info << L": ";
        AppendGuidToString(_strstream, guid);
        _strstream << L"\n";
    }

    void PrintResult(void)
    {
        std::wstring strng;
        strng = _strstream.str();
        OutputDebugStringW(strng.c_str());
    }

private:
    std::wstringstream _strstream;

    void AppendGuidToString(std::wstringstream& os, REFGUID guid)
    {

        os << std::uppercase;
        os.width(8);
        os << std::hex << guid.Data1 << '-';

        os.width(4);
        os << std::hex << guid.Data2 << '-';

        os.width(4);
        os << std::hex << guid.Data3 << '-';

        os.width(2);
        os << std::hex
            << static_cast<short>(guid.Data4[0])
            << static_cast<short>(guid.Data4[1])
            << '-'
            << static_cast<short>(guid.Data4[2])
            << static_cast<short>(guid.Data4[3])
            << static_cast<short>(guid.Data4[4])
            << static_cast<short>(guid.Data4[5])
            << static_cast<short>(guid.Data4[6])
            << static_cast<short>(guid.Data4[7]);
        os << std::nouppercase;
    }
};