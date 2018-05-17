#ifndef ctransform_h__
#define ctransform_h__

#include <cstring>
#include <cstdlib>
#include <cassert>

// 	unsigned char buffer[4] = { 0 };
// 	memcpy(buffer, pchAnswer, sizeof(int));
// 	uint32_t retVal = buffer[3];
// 	retVal += buffer[2] << 8;
// 	retVal += buffer[1] << 16;
// 	retVal += buffer[0] << 24;



template <typename T>
T transformA2I(const unsigned char* buf, const int len)
{
	T value_ = 0;
	for (int i = 0; i < len; i++)
	{
		T x_ = buf[i];
		if (x_ == 0) continue;
		if (i != len - 1) {
			for (int j = 0; j < 2 * (len - i - 1); j++) {
				x_ *= 16;
			}
		}
		value_ += x_;
	}

	return value_;
}

unsigned char*  transformReverse(unsigned char * buf, int len)
{
	unsigned char *buf_tmp = new unsigned char[len];
	for (int i = 0; i < len; i++)
		buf_tmp[i] = buf[len - i - 1];
	memset(buf, 0, 8);
	memcpy(buf, buf_tmp, 8);
	delete[] buf_tmp;

	return buf;
}

template <typename T>
T transformA2F(const unsigned char * buf, int len)
{
	T value_ = .0f;
	unsigned char *ptr_ = (unsigned char*)&value_;

	for (int i = 0; i < len; i++)
		ptr_[i] = buf[i];

	return value_;
}

#endif // ctransform_h__
