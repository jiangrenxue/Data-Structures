typedef unsigned int Index;

Index Hash(const char* Key, int TableSize)
{
	unsigned int HashVal = 0;
	while (*Key != '\0')
	{
		HashVal += *Key++;
	}
	return HashVal % TableSize;
}

Index Hash(const char* Key, int TableSize)
{
	return (Key[0] + 27 * Key[1] + 729 * Key[2]) % TableSize;
}

Index Hash(const char* Key, int TableSize)
{
	unsigned int HashVal = 0;
	while (*Key != '\0')
	{
		HashVal = (HashVal << 5) + *Key++;

		return HashVal % TableSize;
	}
}

