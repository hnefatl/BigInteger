#ifndef _BIGINTEGER_H
#define _BIGINTEGER_H

#include <iostream>
#include <vector>
#include <algorithm>

/*
Digits are stored in REVERSE order.
*/

class BigInteger
{
public:
	BigInteger()
	{
		Digits.clear();
		Digits.reserve(1);
		Digits.push_back(0);
	}
	BigInteger(std::string Number)
	{
		std::reverse(Number.begin(), Number.end());
		Digits.clear();
		Digits.reserve(Number.size());
		for(unsigned int x=0; x<Number.size(); x++)
		{
			Digits.push_back(Number[x]-'0');
		}
	}

	BigInteger operator +(BigInteger &One)
	{
		BigInteger Buffer;

		// Put shortest length out of two BigIntegers into ShortestLength
		int ShortestLength=(this->Digits.size()>One.Digits.size()?One.Digits.size():this->Digits.size());

		// Reserve required space
		Buffer.Digits.resize(ShortestLength);

		short Carry=0;
		for(int x=0; x<ShortestLength; x++)
		{
			short AddResult=One.Digits[x]+this->Digits[x];

			if(AddResult>=10) // Carry required
			{
				Carry++;
				AddResult-=10;
			}

			Buffer.Digits[x]+=AddResult;
			if(Carry!=0)
			{
				if(Buffer.Digits.size()-1==x) // If last element
				{
					Buffer.Digits.push_back(Carry);
				}
				else
				{
					Buffer.Digits[x+1]+=Carry;
				}

				Carry=0;
			}
		}

		// After search, sort out missed carries (9 carry 1 goes to 10 unchecked)

		int Mistakes=1;
		while(Mistakes>0)
		{
			Mistakes=0;
			int Carry=0;
			for(unsigned int x=0; x<Buffer.Digits.size(); x++)
			{
				// Locate any mistakes
				if(Buffer.Digits[x]>=10)
				{
					Carry++;
					Buffer.Digits[x]-=10;
					Mistakes++;
				}

				if(Carry!=0)
				{
					if(Buffer.Digits.size()-1==x) // If last element
					{
						Buffer.Digits.push_back(Carry);
					}
					else
					{
						Buffer.Digits[x+1]+=Carry;
					}

					Carry=0;
				}
			}
		}

		return Buffer;
	}
	BigInteger operator -(BigInteger &One)
	{
		BigInteger Buffer;
		
		int ShortestLength=(this->Digits.size()>One.Digits.size()?One.Digits.size():this->Digits.size());
		for(int x=0; x<ShortestLength; x++)
		{

		}
	}

	bool operator ==(BigInteger &One)
	{
		if(this->Digits.size()!=One.Digits.size())
		{
			return false;
		}

		for(unsigned int x=0; x<this->Digits.size(); x++)
		{
			if(this->Digits[x]!=One.Digits[x])
			{
				return false;
			}
		}

		return true;
	}
	bool operator !=(BigInteger &One)
	{
		return !this->operator==(One);
	}

	const char *operator <<(std::ostream Output)
	{
		return GetNumber().c_str();
	}

	std::string GetNumber()
	{
		std::string Number;

		for(int x=Digits.size()-1; x>=0; x--)
		{
			Number+=Digits[x]+'0';
		}

		return Number;
	}

private:
	std::vector<short> Digits;
};

#endif
