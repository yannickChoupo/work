#include <iostream>
#include "limits.h"
#include "stdint.h"
#include "cmath"

using namespace std;
/**
 * @brief Determine the number of 1 in the given number
 *
 * @param value The input Number
 * @return An Integer representing the number of 1 ones the input
 */
int bits(unsigned long value)
{
    int result = 0;
    while (value)
    {
        if (value & 1)
        {
            result++;
        }
        value >>= 1;
    }
    return result;
}
/**
 * @brief Determine if a number is even
 *
 * @param value The input Number
 * @return true if the value is even
 * @return false if value is not even
 * @see bits()
 * @note If the Number LSB not 1 is
 * @attention gab the attention of the user
 * @warning super important message
 */
bool iseven(long value)
{
    return (!(value & 1));
}
/**
 * @brief Ausgabe einer Zahl in seiner Binär form
 * - Bestimmung des Wert der genaue eine 1 am höchswertigste Stelle der
 *   Zahl entspricht .
 * - dann immer wieder nach recht verschieben solange diese Zahl definiert ist
 * - dabei immer dann und-Verkünpfen mit dem übergebenden Wert .
 * - Ist das ergebnis der und-Verknüpfung definiert dann 1 ausgeben sonst 0.

 * @param value the Input
 */
void deztobin(unsigned long value)
{
    if (!value)
    {
        cout << "0";
        return;
    }
    unsigned long mask = 1 << static_cast<unsigned long>(log(value) / log(2));

    cout << "log(2) : " << log(2) << endl;
    cout << "log(value) : " << log(value) << endl;
    while (mask)
    {
        cout << "mask : " << mask << endl;
        if (value & mask)
        {
            cout << "1";
        }
        else
        {
            cout << "0";
        }
        mask >>= 1;
    }
}

/**
 * @brief Bestimmung der groesste 1-bit-Gruppe in der uebergenden Zahl.
 *
 * Es wird durch die Zahl iteriert und solange Bit eine 1 ist wird der zahler
 * inkrementiert sonst wird zurückgestzt und dann überprüft ob das neue
 * berechnete Maximum grösser als das zuletzt gespeicherte Maximum.
 *
 * @param value
 * @return The number of ones group in value
 */
int groupSize(unsigned long value)
{
    unsigned long mask = 1;
    int currentMax = 0;
    int result = 0;
    while (mask <= value)
    {
        if (value & mask)
        {
            currentMax++;
        }
        else
        {
            currentMax = 0;
        }
        if (currentMax > result)
        {
            result = currentMax;
        }
        mask <<= 1;
    }
    return result;
}
/**
 * @brief Invertieren des Bitmusters des übergenden Zahl
 *
 * Der übergenden Wert wird immer wieder nach recht verschoben solange er
 * definiert ist und dabei wird überprüft ob an der niederwertigste Bit eine 1
 * steht und falls das der fall ist wird das niederwertigste Bit von dem neuen
 * Wert auf 1 gestzt und sonst auf null da er auch gleichzeitig nach links
 * verschoben wird.
 * Es wird dann immer die niederwertigsten Bits angesprochen.
 * @param value
 * @return unsigned long
 */
unsigned long bitReverse(unsigned long value)
{
    unsigned long newValue = 0;
    do
    {
        newValue <<= 1;
        if (value & 1)
        {
            newValue |= 1;
        }
        value >>= 1;
    } while (value);

    return newValue;
}

unsigned long bitReverseX(unsigned long value)
{
    unsigned long newValue = 0;
    do
    {
        newValue <<= 1;
        newValue |= value & 1;
        value >>= 1;
    } while (value);
    return newValue;
}

int bitPos(uint32_t value)
{
    int Pos = 0;
    while (!(value & 1))
    {
        Pos++;
        value >>= 1;
    }
    cout << "Position : " << Pos << endl;
    return Pos;
}
