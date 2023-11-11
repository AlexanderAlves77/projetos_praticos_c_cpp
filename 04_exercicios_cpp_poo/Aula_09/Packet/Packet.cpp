#include "Packet.h"
#include <iostream>
using std::cout;
using std::endl;

Packet::Packet()
{
	data = { 0,0,0,0 };
	index = 0;
}

void Packet::begin()
{
    index = 0;
}

void Packet::end()
{
    index = 0;
}
