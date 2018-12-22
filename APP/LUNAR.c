#include "sys.h"
#include "lunar.h"
#include "show.h"
	
#include "bit.h"

extern _lunar_obj moon;	//�����ṹ��
u8 _cror_(u8 temp, u8 i)
{
	u8 temp1;
	u8 temp2;
	temp1 = temp;
	temp2 = temp;
	temp1 = temp1 >> i;
	temp1 = temp1 << i;
	temp2 = temp2 << (8 - i);
	temp2 = temp2 >> (8 - i);
	return temp1 + temp2;
}
u8 _crol_(u8 temp, u8 i)
{
	temp = temp << i;
	return temp;
}
/*-------------------------------------?????----------------------------------------*/
static unsigned char  day_code1[9]={0x0,0x1f,0x3b,0x5a,0x78,0x97,0xb5,0xd4,0xf3};
static unsigned short day_code2[3]={0x111,0x130,0x14e};
/*---------------------------------����ת������������ݱ�--------------------------------*/

static unsigned char year_code[] = {
	0x04,0xAe,0x53, //1901 0
	0x0A,0x57,0x48, //1902 3
	0x55,0x26,0xBd, //1903 6
	0x0d,0x26,0x50, //1904 9
	0x0d,0x95,0x44, //1905 12
	0x46,0xAA,0xB9, //1906 15
	0x05,0x6A,0x4d, //1907 18
	0x09,0xAd,0x42, //1908 21
	0x24,0xAe,0xB6, //1909
	0x04,0xAe,0x4A, //1910
	0x6A,0x4d,0xBe, //1911
	0x0A,0x4d,0x52, //1912
	0x0d,0x25,0x46, //1913
	0x5d,0x52,0xBA, //1914
	0x0B,0x54,0x4e, //1915
	0x0d,0x6A,0x43, //1916
	0x29,0x6d,0x37, //1917
	0x09,0x5B,0x4B, //1918
	0x74,0x9B,0xC1, //1919
	0x04,0x97,0x54, //1920
	0x0A,0x4B,0x48, //1921
	0x5B,0x25,0xBC, //1922
	0x06,0xA5,0x50, //1923
	0x06,0xd4,0x45, //1924
	0x4A,0xdA,0xB8, //1925
	0x02,0xB6,0x4d, //1926
	0x09,0x57,0x42, //1927
	0x24,0x97,0xB7, //1928
	0x04,0x97,0x4A, //1929
	0x66,0x4B,0x3e, //1930
	0x0d,0x4A,0x51, //1931
	0x0e,0xA5,0x46, //1932
	0x56,0xd4,0xBA, //1933
	0x05,0xAd,0x4e, //1934
	0x02,0xB6,0x44, //1935
	0x39,0x37,0x38, //1936
	0x09,0x2e,0x4B, //1937
	0x7C,0x96,0xBf, //1938
	0x0C,0x95,0x53, //1939
	0x0d,0x4A,0x48, //1940
	0x6d,0xA5,0x3B, //1941
	0x0B,0x55,0x4f, //1942
	0x05,0x6A,0x45, //1943
	0x4A,0xAd,0xB9, //1944
	0x02,0x5d,0x4d, //1945
	0x09,0x2d,0x42, //1946
	0x2C,0x95,0xB6, //1947
	0x0A,0x95,0x4A, //1948
	0x7B,0x4A,0xBd, //1949
	0x06,0xCA,0x51, //1950
	0x0B,0x55,0x46, //1951
	0x55,0x5A,0xBB, //1952
	0x04,0xdA,0x4e, //1953
	0x0A,0x5B,0x43, //1954
	0x35,0x2B,0xB8, //1955
	0x05,0x2B,0x4C, //1956
	0x8A,0x95,0x3f, //1957
	0x0e,0x95,0x52, //1958
	0x06,0xAA,0x48, //1959
	0x7A,0xd5,0x3C, //1960
	0x0A,0xB5,0x4f, //1961
	0x04,0xB6,0x45, //1962
	0x4A,0x57,0x39, //1963
	0x0A,0x57,0x4d, //1964
	0x05,0x26,0x42, //1965
	0x3e,0x93,0x35, //1966
	0x0d,0x95,0x49, //1967
	0x75,0xAA,0xBe, //1968
	0x05,0x6A,0x51, //1969
	0x09,0x6d,0x46, //1970
	0x54,0xAe,0xBB, //1971
	0x04,0xAd,0x4f, //1972
	0x0A,0x4d,0x43, //1973
	0x4d,0x26,0xB7, //1974
	0x0d,0x25,0x4B, //1975
	0x8d,0x52,0xBf, //1976
	0x0B,0x54,0x52, //1977
	0x0B,0x6A,0x47, //1978
	0x69,0x6d,0x3C, //1979
	0x09,0x5B,0x50, //1980
	0x04,0x9B,0x45, //1981
	0x4A,0x4B,0xB9, //1982
	0x0A,0x4B,0x4d, //1983
	0xAB,0x25,0xC2, //1984
	0x06,0xA5,0x54, //1985
	0x06,0xd4,0x49, //1986
	0x6A,0xdA,0x3d, //1987
	0x0A,0xB6,0x51, //1988
	0x09,0x37,0x46, //1989
	0x54,0x97,0xBB, //1990
	0x04,0x97,0x4f, //1991
	0x06,0x4B,0x44, //1992
	0x36,0xA5,0x37, //1993
	0x0e,0xA5,0x4A, //1994
	0x86,0xB2,0xBf, //1995
	0x05,0xAC,0x53, //1996
	0x0A,0xB6,0x47, //1997
	0x59,0x36,0xBC, //1998
	0x09,0x2e,0x50, //1999 294
	0x0C,0x96,0x45, //2000 297
	0x4d,0x4A,0xB8, //2001
	0x0d,0x4A,0x4C, //2002
	0x0d,0xA5,0x41, //2003
	0x25,0xAA,0xB6, //2004
	0x05,0x6A,0x49, //2005
	0x7A,0xAd,0xBd, //2006
	0x02,0x5d,0x52, //2007
	0x09,0x2d,0x47, //2008
	0x5C,0x95,0xBA, //2009
	0x0A,0x95,0x4e, //2010
	0x0B,0x4A,0x43, //2011
	0x4B,0x55,0x37, //2012
	0x0A,0xd5,0x4A, //2013
	0x95,0x5A,0xBf, //2014
	0x04,0xBA,0x53, //2015
	0x0A,0x5B,0x48, //2016
	0x65,0x2B,0xBC, //2017
	0x05,0x2B,0x50, //2018
	0x0A,0x93,0x45, //2019
	0x47,0x4A,0xB9, //2020
	0x06,0xAA,0x4C, //2021
	0x0A,0xd5,0x41, //2022
	0x24,0xdA,0xB6, //2023
	0x04,0xB6,0x4A, //2024
	0x69,0x57,0x3d, //2025
	0x0A,0x4e,0x51, //2026
	0x0d,0x26,0x46, //2027
	0x5e,0x93,0x3A, //2028
	0x0d,0x53,0x4d, //2029
	0x05,0xAA,0x43, //2030
	0x36,0xB5,0x37, //2031
	0x09,0x6d,0x4B, //2032
	0xB4,0xAe,0xBf, //2033
	0x04,0xAd,0x53, //2034
	0x0A,0x4d,0x48, //2035
	0x6d,0x25,0xBC, //2036
	0x0d,0x25,0x4f, //2037
	0x0d,0x52,0x44, //2038
	0x5d,0xAA,0x38, //2039
	0x0B,0x5A,0x4C, //2040
	0x05,0x6d,0x41, //2041
	0x24,0xAd,0xB6, //2042
	0x04,0x9B,0x4A, //2043
	0x7A,0x4B,0xBe, //2044
	0x0A,0x4B,0x51, //2045
	0x0A,0xA5,0x46, //2046
	0x5B,0x52,0xBA, //2047
	0x06,0xd2,0x4e, //2048
	0x0A,0xdA,0x42, //2049
	0x35,0x5B,0x37, //2050
	0x09,0x37,0x4B, //2051
	0x84,0x97,0xC1, //2052
	0x04,0x97,0x53, //2053
	0x06,0x4B,0x48, //2054
	0x66,0xA5,0x3C, //2055
	0x0e,0xA5,0x4f, //2056
	0x06,0xB2,0x44, //2057
	0x4A,0xB6,0x38, //2058
	0x0A,0xAe,0x4C, //2059
	0x09,0x2e,0x42, //2060
	0x3C,0x97,0x35, //2061
	0x0C,0x96,0x49, //2062
	0x7d,0x4A,0xBd, //2063
	0x0d,0x4A,0x51, //2064
	0x0d,0xA5,0x45, //2065
	0x55,0xAA,0xBA, //2066
	0x05,0x6A,0x4e, //2067
	0x0A,0x6d,0x43, //2068
	0x45,0x2e,0xB7, //2069
	0x05,0x2d,0x4B, //2070
	0x8A,0x95,0xBf, //2071
	0x0A,0x95,0x53, //2072
	0x0B,0x4A,0x47, //2073
	0x6B,0x55,0x3B, //2074
	0x0A,0xd5,0x4f, //2075
	0x05,0x5A,0x45, //2076
	0x4A,0x5d,0x38, //2077
	0x0A,0x5B,0x4C, //2078
	0x05,0x2B,0x42, //2079
	0x3A,0x93,0xB6, //2080
	0x06,0x93,0x49, //2081
	0x77,0x29,0xBd, //2082
	0x06,0xAA,0x51, //2083
	0x0A,0xd5,0x46, //2084
	0x54,0xdA,0xBA, //2085
	0x04,0xB6,0x4e, //2086
	0x0A,0x57,0x43, //2087
	0x45,0x27,0x38, //2088
	0x0d,0x26,0x4A, //2089
	0x8e,0x93,0x3e, //2090
	0x0d,0x52,0x52, //2091
	0x0d,0xAA,0x47, //2092
	0x66,0xB5,0x3B, //2093
	0x05,0x6d,0x4f, //2094
	0x04,0xAe,0x45, //2095
	0x4A,0x4e,0xB9, //2096
	0x0A,0x4d,0x4C, //2097
	0x0d,0x15,0x41, //2098
	0x2d,0x92,0xB5, //2099
};


/*�Ӻ���,���ڶ�ȡ���ݱ���ũ���µĴ��»�С��,�������Ϊ�󷵻�1,ΪС����0------------------*/
static unsigned char GetMoonDay(unsigned char month_p, unsigned short table_addr)
{
	switch (month_p)
	{
	case 1:
		if ((year_code[table_addr] & 0x08) == 0)		return(0);
		else 									return(1);
	case 2:
		if ((year_code[table_addr] & 0x04) == 0)		return(0);
		else 									return(1);
	case 3:
		if ((year_code[table_addr] & 0x02) == 0)		return(0);
		else 									return(1);
	case 4:
		if ((year_code[table_addr] & 0x01) == 0)		return(0);
		else 								    return(1);
	case 5:
		if ((year_code[table_addr + 1] & 0x80) == 0)	return(0);
		else 									return(1);
	case 6:
		if ((year_code[table_addr + 1] & 0x40) == 0)	return(0);
		else 									return(1);
	case 7:
		if ((year_code[table_addr + 1] & 0x20) == 0)	return(0);
		else 									return(1);
	case 8:
		if ((year_code[table_addr + 1] & 0x10) == 0)	return(0);
		else 									return(1);
	case 9:
		if ((year_code[table_addr + 1] & 0x08) == 0)	return(0);
		else 									return(1);
	case 10:
		if ((year_code[table_addr + 1] & 0x04) == 0)	return(0);
		else 									return(1);
	case 11:
		if ((year_code[table_addr + 1] & 0x02) == 0)	return(0);
		else 									return(1);
	case 12:
		if ((year_code[table_addr + 1] & 0x01) == 0)	return(0);
		else 									return(1);
	case 13:
		if ((year_code[table_addr + 2] & 0x80) == 0)	return(0);
		else 									return(1);
	}
	return(0);
}

/*--------------------------------����תũ������-----------------------------------------*/

void Conversion(u8 c, unsigned char year, unsigned char month, unsigned char day)
{   //c=0 Ϊ21����,c=1 Ϊ19���� ����������ݾ�ΪBCD����                      
	unsigned char temp1, temp2, temp3, month_p;
	unsigned int temp4, table_addr;
	u8 flag2, flag_y;
	temp1 = year / 16; //BCD->hex �Ȱ�����ת��Ϊʮ������ 
	temp2 = year % 16;
	year = temp1 * 10 + temp2;
	temp1 = month / 16;
	temp2 = month % 16;
	month = temp1 * 10 + temp2;
	temp1 = day / 16;
	temp2 = day % 16;
	day = temp1 * 10 + temp2;
	//��λ���ݱ���ַ
	if (c == 0) { table_addr = (year + 0x64 - 1) * 0x3; }	//0x64 = 100
	else { table_addr = (year - 1) * 0x3; }
	//ȡ���괺�����ڵĹ����·�
	temp1 = year_code[table_addr + 2] & 0x60; 			//
	temp1 = _cror_(temp1, 5);
	//ȡ���괺�����ڵĹ�����
	temp2 = year_code[table_addr + 2] & 0x1f;  //0x1f = 31
	//ȡ���괺�����ڵĹ�������� 
	//���㵱�괺���뵱��Ԫ��������,����ֻ���ڹ���1�»�2�� 
	if (temp1 == 0x1) { temp3 = temp2 - 1; }
	else { temp3 = temp2 + 0x1f - 1; }

	// ���㵱�괺���뵱��Ԫ����������� 
	//���㹫�����뵱��Ԫ��������,Ϊ�˼�������,���������� 
	//day_code1[9],day_code2[3] 
	//����������ھ��»�ǰ,����������0xff,�ñ�day_code1[9], 
	//�ھ��º�,��������0xff,�ñ�day_code2[3] 
	//�����빫����Ϊ8��10��,��������Ԫ������Ϊday_code1[8-1]+10-1 
	//�����빫����Ϊ11��10��,��������Ԫ������Ϊday_code2[11-10]+10-1 
	if (month < 10) { temp4 = day_code1[month - 1] + day - 1; }
	else { temp4 = day_code2[month - 10] + day - 1; }
	if ((month > 0x2) && (year % 0x4 == 0))
		temp4 += 1; //��������´���2�²��Ҹ����2��Ϊ����,������1
	//���㹫�����뵱��Ԫ����������� 

	//�жϹ������ڴ���ǰ���Ǵ��ں�
	if (temp4 >= temp3)
	{
		temp4 -= temp3; month = 0x1;
		month_p = 0x1;  //month_pΪ�·�ָ��,�������ڴ���ǰ����Ǵ��ڵ���month_pָ������
		flag2 = GetMoonDay(month_p, table_addr); //����ũ����Ϊ��С����С��,���·���1,С�·���0
		flag_y = 0;
		if (flag2 == 0)temp1 = 0x1d;   //С��29��
		else    temp1 = 0x1e;    //����30��
		temp2 = year_code[table_addr] & 0xf0;
		temp2 = _cror_(temp2, 4);  //�����ݱ���ȡ����������·�,��Ϊ0�����������
		while (temp4 >= temp1)
		{
			temp4 -= temp1; month_p += 1;
			if (month == temp2)
			{
				flag_y = ~flag_y;
				if (flag_y == 0)month += 1;
			}
			else month += 1;
			flag2 = GetMoonDay(month_p, table_addr);
			if (flag2 == 0)temp1 = 0x1d;
			else    temp1 = 0x1e;
		}
		day = temp4 + 1;
	}
	else
	{
		temp3 -= temp4;
		if (year == 0x0) { year = 0x63; c = 1; }
		else	year -= 1;
		table_addr -= 0x3;
		month = 0xc;
		temp2 = year_code[table_addr] & 0xf0;
		temp2 = _cror_(temp2, 4);
		if (temp2 == 0)month_p = 0xc;
		else	month_p = 0xd;
		flag_y = 0;
		flag2 = GetMoonDay(month_p, table_addr);
		if (flag2 == 0)temp1 = 0x1d;
		else	temp1 = 0x1e;
		while (temp3 > temp1)
		{
			temp3 -= temp1;
			month_p -= 1;
			if (flag_y == 0)month -= 1;
			if (month == temp2)flag_y = ~flag_y;
			flag2 = GetMoonDay(month_p, table_addr);
			if (flag2 == 0)temp1 = 0x1d;
			else	temp1 = 0x1e;
		}
		day = temp1 - temp3 + 1;
	}
	moon.c_moon = c;
	temp1 = year / 10;
	temp1 = _crol_(temp1, 4);
	temp2 = year % 10;
	moon.year_moon = temp1 | temp2; 	//ũ����
	moon.month_moon = month;			//ũ����
	moon.day_moon = day;				//ũ����
}

/*****************************************************************************************************
�������ܣ� ��ʮ�Ľ������ݿ�	��
��ڲ����� unsigned char(yy,mo,dd) ��Ӧ ������
���ڲ����� unsigned char(0-24) 1-24��Ӧ��ʮ�Ľ���
����    �� TOTOP
��ʮ�Ľ������ݿ⣨1901--2050�� 
���ݸ�ʽ˵��:   
��1901��Ľ���Ϊ   
     1��    2��     3��     4��       5��      6��     7��     8��      9��    10��     11��      12��   
[ 6,21] [ 4,19]  [ 6,21]  [ 5,21]   [ 6,22]  [ 6,22] [ 8,23] [ 8,24]  [ 8,24] [ 8,24] [ 8,23]   [ 8,22]   
[ 9, 6] [11, 4]  [ 9, 6]  [10, 6]   [ 9, 7]  [ 9, 7] [ 7, 8] [ 7, 9]  [ 7, 9] [ 7, 9] [ 7, 8]   [ 7,15]   
�����һ������Ϊÿ�½�����Ӧ��������,15��ȥÿ�µ�һ������,ÿ�µڶ���������ȥ15�õڶ�
�У�����ÿ������������Ӧ���ݶ�С��16,ÿ����һ���ֽڴ��,��λ��ŵ�һ����������,��λ��
�ŵڶ�������������,�ɵ��±�   
******************************************************************************************************/
u8 jieqi_code[]=
{
       0x96,0xB4,0x96,0xA6,0x97,0x97,0x78,0x79,0x79,0x69,0x78,0x77,     //1901   
       0x96,0xA4,0x96,0x96,0x97,0x87,0x79,0x79,0x79,0x69,0x78,0x78,     //1902   
       0x96,0xA5,0x87,0x96,0x87,0x87,0x79,0x69,0x69,0x69,0x78,0x78,     //1903   
       0x86,0xA5,0x96,0xA5,0x96,0x97,0x88,0x78,0x78,0x79,0x78,0x87,     //1904   
       0x96,0xB4,0x96,0xA6,0x97,0x97,0x78,0x79,0x79,0x69,0x78,0x77,     //1905   
       0x96,0xA4,0x96,0x96,0x97,0x97,0x79,0x79,0x79,0x69,0x78,0x78,     //1906   
       0x96,0xA5,0x87,0x96,0x87,0x87,0x79,0x69,0x69,0x69,0x78,0x78,     //1907   
       0x86,0xA5,0x96,0xA5,0x96,0x97,0x88,0x78,0x78,0x69,0x78,0x87,     //1908   
       0x96,0xB4,0x96,0xA6,0x97,0x97,0x78,0x79,0x79,0x69,0x78,0x77,     //1909   
       0x96,0xA4,0x96,0x96,0x97,0x97,0x79,0x79,0x79,0x69,0x78,0x78,     //1910   
       0x96,0xA5,0x87,0x96,0x87,0x87,0x79,0x69,0x69,0x69,0x78,0x78,     //1911   
       0x86,0xA5,0x96,0xA5,0x96,0x97,0x88,0x78,0x78,0x69,0x78,0x87,     //1912   
       0x95,0xB4,0x96,0xA6,0x97,0x97,0x78,0x79,0x79,0x69,0x78,0x77,     //1913   
       0x96,0xB4,0x96,0xA6,0x97,0x97,0x79,0x79,0x79,0x69,0x78,0x78,     //1914   
       0x96,0xA5,0x97,0x96,0x97,0x87,0x79,0x79,0x69,0x69,0x78,0x78,     //1915   
       0x96,0xA5,0x96,0xA5,0x96,0x97,0x88,0x78,0x78,0x79,0x77,0x87,     //1916   
       0x95,0xB4,0x96,0xA6,0x96,0x97,0x78,0x79,0x78,0x69,0x78,0x87,     //1917   
       0x96,0xB4,0x96,0xA6,0x97,0x97,0x79,0x79,0x79,0x69,0x78,0x77,     //1918   
       0x96,0xA5,0x97,0x96,0x97,0x87,0x79,0x79,0x69,0x69,0x78,0x78,     //1919   
       0x96,0xA5,0x96,0xA5,0x96,0x97,0x88,0x78,0x78,0x79,0x77,0x87,     //1920   
       0x95,0xB4,0x96,0xA5,0x96,0x97,0x78,0x79,0x78,0x69,0x78,0x87,     //1921   
       0x96,0xB4,0x96,0xA6,0x97,0x97,0x79,0x79,0x79,0x69,0x78,0x77,     //1922   
       0x96,0xA4,0x96,0x96,0x97,0x87,0x79,0x79,0x69,0x69,0x78,0x78,     //1923   
       0x96,0xA5,0x96,0xA5,0x96,0x97,0x88,0x78,0x78,0x79,0x77,0x87,     //1924   
       0x95,0xB4,0x96,0xA5,0x96,0x97,0x78,0x79,0x78,0x69,0x78,0x87,     //1925   
       0x96,0xB4,0x96,0xA6,0x97,0x97,0x78,0x79,0x79,0x69,0x78,0x77,     //1926   
       0x96,0xA4,0x96,0x96,0x97,0x87,0x79,0x79,0x79,0x69,0x78,0x78,     //1927   
       0x96,0xA5,0x96,0xA5,0x96,0x96,0x88,0x78,0x78,0x78,0x87,0x87,     //1928   
       0x95,0xB4,0x96,0xA5,0x96,0x97,0x88,0x78,0x78,0x79,0x77,0x87,     //1929   
       0x96,0xB4,0x96,0xA6,0x97,0x97,0x78,0x79,0x79,0x69,0x78,0x77,     //1930   
       0x96,0xA4,0x96,0x96,0x97,0x87,0x79,0x79,0x79,0x69,0x78,0x78,     //1931   
       0x96,0xA5,0x96,0xA5,0x96,0x96,0x88,0x78,0x78,0x78,0x87,0x87,     //1932   
       0x95,0xB4,0x96,0xA5,0x96,0x97,0x88,0x78,0x78,0x69,0x78,0x87,     //1933   
       0x96,0xB4,0x96,0xA6,0x97,0x97,0x78,0x79,0x79,0x69,0x78,0x77,     //1934   
       0x96,0xA4,0x96,0x96,0x97,0x97,0x79,0x79,0x79,0x69,0x78,0x78,     //1935   
       0x96,0xA5,0x96,0xA5,0x96,0x96,0x88,0x78,0x78,0x78,0x87,0x87,     //1936   
       0x95,0xB4,0x96,0xA5,0x96,0x97,0x88,0x78,0x78,0x69,0x78,0x87,     //1937   
       0x96,0xB4,0x96,0xA6,0x97,0x97,0x78,0x79,0x79,0x69,0x78,0x77,     //1938   
       0x96,0xA4,0x96,0x96,0x97,0x97,0x79,0x79,0x79,0x69,0x78,0x78,     //1939   
       0x96,0xA5,0x96,0xA5,0x96,0x96,0x88,0x78,0x78,0x78,0x87,0x87,     //1940   
       0x95,0xB4,0x96,0xA5,0x96,0x97,0x88,0x78,0x78,0x69,0x78,0x87,     //1941   
       0x96,0xB4,0x96,0xA6,0x97,0x97,0x78,0x79,0x79,0x69,0x78,0x77,     //1942   
       0x96,0xA4,0x96,0x96,0x97,0x97,0x79,0x79,0x79,0x69,0x78,0x78,     //1943   
       0x96,0xA5,0x96,0xA5,0xA6,0x96,0x88,0x78,0x78,0x78,0x87,0x87,     //1944   
       0x95,0xB4,0x96,0xA5,0x96,0x97,0x88,0x78,0x78,0x79,0x77,0x87,     //1945   
       0x95,0xB4,0x96,0xA6,0x97,0x97,0x78,0x79,0x78,0x69,0x78,0x77,     //1946   
       0x96,0xB4,0x96,0xA6,0x97,0x97,0x79,0x79,0x79,0x69,0x78,0x78,     //1947   
       0x96,0xA5,0xA6,0xA5,0xA6,0x96,0x88,0x88,0x78,0x78,0x87,0x87,     //1948   
       0xA5,0xB4,0x96,0xA5,0x96,0x97,0x88,0x79,0x78,0x79,0x77,0x87,     //1949   
       0x95,0xB4,0x96,0xA5,0x96,0x97,0x78,0x79,0x78,0x69,0x78,0x77,     //1950   
       0x96,0xB4,0x96,0xA6,0x97,0x97,0x79,0x79,0x79,0x69,0x78,0x78,     //1951   
       0x96,0xA5,0xA6,0xA5,0xA6,0x96,0x88,0x88,0x78,0x78,0x87,0x87,     //1952   
       0xA5,0xB4,0x96,0xA5,0x96,0x97,0x88,0x78,0x78,0x79,0x77,0x87,     //1953   
       0x95,0xB4,0x96,0xA5,0x96,0x97,0x78,0x79,0x78,0x68,0x78,0x87,     //1954   
       0x96,0xB4,0x96,0xA6,0x97,0x97,0x78,0x79,0x79,0x69,0x78,0x77,     //1955   
       0x96,0xA5,0xA5,0xA5,0xA6,0x96,0x88,0x88,0x78,0x78,0x87,0x87,     //1956   
       0xA5,0xB4,0x96,0xA5,0x96,0x97,0x88,0x78,0x78,0x79,0x77,0x87,     //1957   
       0x95,0xB4,0x96,0xA5,0x96,0x97,0x88,0x78,0x78,0x69,0x78,0x87,     //1958   
       0x96,0xB4,0x96,0xA6,0x97,0x97,0x78,0x79,0x79,0x69,0x78,0x77,     //1959   
       0x96,0xA4,0xA5,0xA5,0xA6,0x96,0x88,0x88,0x88,0x78,0x87,0x87,     //1960   
       0xA5,0xB4,0x96,0xA5,0x96,0x96,0x88,0x78,0x78,0x78,0x87,0x87,     //1961   
       0x96,0xB4,0x96,0xA5,0x96,0x97,0x88,0x78,0x78,0x69,0x78,0x87,     //1962   
       0x96,0xB4,0x96,0xA6,0x97,0x97,0x78,0x79,0x79,0x69,0x78,0x77,     //1963   
       0x96,0xA4,0xA5,0xA5,0xA6,0x96,0x88,0x88,0x88,0x78,0x87,0x87,     //1964   
       0xA5,0xB4,0x96,0xA5,0x96,0x96,0x88,0x78,0x78,0x78,0x87,0x87,     //1965   
       0x95,0xB4,0x96,0xA5,0x96,0x97,0x88,0x78,0x78,0x69,0x78,0x87,     //1966   
       0x96,0xB4,0x96,0xA6,0x97,0x97,0x78,0x79,0x79,0x69,0x78,0x77,     //1967   
       0x96,0xA4,0xA5,0xA5,0xA6,0xA6,0x88,0x88,0x88,0x78,0x87,0x87,     //1968   
       0xA5,0xB4,0x96,0xA5,0x96,0x96,0x88,0x78,0x78,0x78,0x87,0x87,     //1969   
       0x95,0xB4,0x96,0xA5,0x96,0x97,0x88,0x78,0x78,0x69,0x78,0x87,     //1970   
       0x96,0xB4,0x96,0xA6,0x97,0x97,0x78,0x79,0x79,0x69,0x78,0x77,     //1971   
       0x96,0xA4,0xA5,0xA5,0xA6,0xA6,0x88,0x88,0x88,0x78,0x87,0x87,     //1972   
       0xA5,0xB5,0x96,0xA5,0xA6,0x96,0x88,0x78,0x78,0x78,0x87,0x87,     //1973   
       0x95,0xB4,0x96,0xA5,0x96,0x97,0x88,0x78,0x78,0x69,0x78,0x87,     //1974   
       0x96,0xB4,0x96,0xA6,0x97,0x97,0x78,0x79,0x78,0x69,0x78,0x77,     //1975   
       0x96,0xA4,0xA5,0xB5,0xA6,0xA6,0x88,0x89,0x88,0x78,0x87,0x87,     //1976   
       0xA5,0xB4,0x96,0xA5,0x96,0x96,0x88,0x88,0x78,0x78,0x87,0x87,     //1977   
       0x95,0xB4,0x96,0xA5,0x96,0x97,0x88,0x78,0x78,0x79,0x78,0x87,     //1978   
       0x96,0xB4,0x96,0xA6,0x96,0x97,0x78,0x79,0x78,0x69,0x78,0x77,     //1979   
       0x96,0xA4,0xA5,0xB5,0xA6,0xA6,0x88,0x88,0x88,0x78,0x87,0x87,     //1980   
       0xA5,0xB4,0x96,0xA5,0xA6,0x96,0x88,0x88,0x78,0x78,0x77,0x87,     //1981   
       0x95,0xB4,0x96,0xA5,0x96,0x97,0x88,0x78,0x78,0x79,0x77,0x87,     //1982   
       0x95,0xB4,0x96,0xA5,0x96,0x97,0x78,0x79,0x78,0x69,0x78,0x77,     //1983   
       0x96,0xB4,0xA5,0xB5,0xA6,0xA6,0x87,0x88,0x88,0x78,0x87,0x87,     //1984   
       0xA5,0xB4,0xA6,0xA5,0xA6,0x96,0x88,0x88,0x78,0x78,0x87,0x87,     //1985   
       0xA5,0xB4,0x96,0xA5,0x96,0x97,0x88,0x78,0x78,0x79,0x77,0x87,     //1986   
       0x95,0xB4,0x96,0xA5,0x96,0x97,0x88,0x79,0x78,0x69,0x78,0x87,     //1987   
       0x96,0xB4,0xA5,0xB5,0xA6,0xA6,0x87,0x88,0x88,0x78,0x87,0x86,     //1988   
       0xA5,0xB4,0xA5,0xA5,0xA6,0x96,0x88,0x88,0x88,0x78,0x87,0x87,     //1989   
       0xA5,0xB4,0x96,0xA5,0x96,0x96,0x88,0x78,0x78,0x79,0x77,0x87,     //1990   
       0x95,0xB4,0x96,0xA5,0x86,0x97,0x88,0x78,0x78,0x69,0x78,0x87,     //1991   
       0x96,0xB4,0xA5,0xB5,0xA6,0xA6,0x87,0x88,0x88,0x78,0x87,0x86,     //1992   
       0xA5,0xB3,0xA5,0xA5,0xA6,0x96,0x88,0x88,0x88,0x78,0x87,0x87,     //1993   
       0xA5,0xB4,0x96,0xA5,0x96,0x96,0x88,0x78,0x78,0x78,0x87,0x87,     //1994   
       0x95,0xB4,0x96,0xA5,0x96,0x97,0x88,0x76,0x78,0x69,0x78,0x87,     //1995   
       0x96,0xB4,0xA5,0xB5,0xA6,0xA6,0x87,0x88,0x88,0x78,0x87,0x86,     //1996   
       0xA5,0xB3,0xA5,0xA5,0xA6,0xA6,0x88,0x88,0x88,0x78,0x87,0x87,     //1997   
       0xA5,0xB4,0x96,0xA5,0x96,0x96,0x88,0x78,0x78,0x78,0x87,0x87,     //1998   
       0x95,0xB4,0x96,0xA5,0x96,0x97,0x88,0x78,0x78,0x69,0x78,0x87,     //1999 
       0x96,0xB4,0xA5,0xB5,0xA6,0xA6,0x87,0x88,0x88,0x78,0x87,0x86,     //2000   
       0xA5,0xB3,0xA5,0xA5,0xA6,0xA6,0x88,0x88,0x88,0x78,0x87,0x87,     //2001   
       0xA5,0xB4,0x96,0xA5,0x96,0x96,0x88,0x78,0x78,0x78,0x87,0x87,     //2002   
       0x95,0xB4,0x96,0xA5,0x96,0x97,0x88,0x78,0x78,0x69,0x78,0x87,     //2003   
       0x96,0xB4,0xA5,0xB5,0xA6,0xA6,0x87,0x88,0x88,0x78,0x87,0x86,     //2004   
       0xA5,0xB3,0xA5,0xA5,0xA6,0xA6,0x88,0x88,0x88,0x78,0x87,0x87,     //2005   
       0xA5,0xB4,0x96,0xA5,0xA6,0x96,0x88,0x88,0x78,0x78,0x87,0x87,     //2006   
       0x95,0xB4,0x96,0xA5,0x96,0x97,0x88,0x78,0x78,0x69,0x78,0x87,     //2007   
       0x96,0xB4,0xA5,0xB5,0xA6,0xA6,0x87,0x88,0x87,0x78,0x87,0x86,     //2008   
       0xA5,0xB3,0xA5,0xB5,0xA6,0xA6,0x88,0x88,0x88,0x78,0x87,0x87,     //2009   
       0xA5,0xB4,0x96,0xA5,0xA6,0x96,0x88,0x88,0x78,0x78,0x87,0x87,     //2010   
       0x95,0xB4,0x96,0xA5,0x96,0x97,0x88,0x78,0x78,0x79,0x78,0x87,     //2011   
       0x96,0xB4,0xA5,0xB5,0xA5,0xA6,0x87,0x88,0x87,0x78,0x87,0x86,     //2012   
       0xA5,0xB3,0xA5,0xB5,0xA6,0xA6,0x87,0x88,0x88,0x78,0x87,0x87,     //2013   
       0xA5,0xB4,0x96,0xA5,0xA6,0x96,0x88,0x88,0x78,0x78,0x87,0x87,     //2014   
       0x95,0xB4,0x96,0xA5,0x96,0x97,0x88,0x78,0x78,0x79,0x77,0x87,     //2015   
       0x95,0xB4,0xA5,0xB4,0xA5,0xA6,0x87,0x88,0x87,0x78,0x87,0x86,     //2016   
       0xA5,0xC3,0xA5,0xB5,0xA6,0xA6,0x87,0x88,0x88,0x78,0x87,0x87,     //2017   
       0xA5,0xB4,0xA6,0xA5,0xA6,0x96,0x88,0x88,0x78,0x78,0x87,0x87,     //2018   
       0xA5,0xB4,0x96,0xA5,0x96,0x96,0x88,0x78,0x78,0x79,0x77,0x87,     //2019   
       0x95,0xB4,0xA5,0xB4,0xA5,0xA6,0x97,0x87,0x87,0x78,0x87,0x86,     //2020   
       0xA5,0xC3,0xA5,0xB5,0xA6,0xA6,0x87,0x88,0x88,0x78,0x87,0x86,     //2021   
       0xA5,0xB4,0xA5,0xA5,0xA6,0x96,0x88,0x88,0x88,0x78,0x87,0x87,     //2022   
       0xA5,0xB4,0x96,0xA5,0x96,0x96,0x88,0x78,0x78,0x79,0x77,0x87,     //2023   
       0x95,0xB4,0xA5,0xB4,0xA5,0xA6,0x97,0x87,0x87,0x78,0x87,0x96,     //2024   
       0xA5,0xC3,0xA5,0xB5,0xA6,0xA6,0x87,0x88,0x88,0x78,0x87,0x86,     //2025   
       0xA5,0xB3,0xA5,0xA5,0xA6,0xA6,0x88,0x88,0x88,0x78,0x87,0x87,     //2026   
       0xA5,0xB4,0x96,0xA5,0x96,0x96,0x88,0x78,0x78,0x78,0x87,0x87,     //2027   
       0x95,0xB4,0xA5,0xB4,0xA5,0xA6,0x97,0x87,0x87,0x78,0x87,0x96,     //2028   
       0xA5,0xC3,0xA5,0xB5,0xA6,0xA6,0x87,0x88,0x88,0x78,0x87,0x86,     //2029   
       0xA5,0xB3,0xA5,0xA5,0xA6,0xA6,0x88,0x88,0x88,0x78,0x87,0x87,     //2030   
       0xA5,0xB4,0x96,0xA5,0x96,0x96,0x88,0x78,0x78,0x78,0x87,0x87,     //2031   
       0x95,0xB4,0xA5,0xB4,0xA5,0xA6,0x97,0x87,0x87,0x78,0x87,0x96,     //2032   
       0xA5,0xC3,0xA5,0xB5,0xA6,0xA6,0x88,0x88,0x88,0x78,0x87,0x86,     //2033   
       0xA5,0xB3,0xA5,0xA5,0xA6,0xA6,0x88,0x78,0x88,0x78,0x87,0x87,     //2034   
       0xA5,0xB4,0x96,0xA5,0xA6,0x96,0x88,0x88,0x78,0x78,0x87,0x87,     //2035   
       0x95,0xB4,0xA5,0xB4,0xA5,0xA6,0x97,0x87,0x87,0x78,0x87,0x96,     //2036   
       0xA5,0xC3,0xA5,0xB5,0xA6,0xA6,0x87,0x88,0x88,0x78,0x87,0x86,     //2037   
       0xA5,0xB3,0xA5,0xA5,0xA6,0xA6,0x88,0x88,0x88,0x78,0x87,0x87,     //2038   
       0xA5,0xB4,0x96,0xA5,0xA6,0x96,0x88,0x88,0x78,0x78,0x87,0x87,     //2039   
       0x95,0xB4,0xA5,0xB4,0xA5,0xA6,0x97,0x87,0x87,0x78,0x87,0x96,     //2040   
       0xA5,0xC3,0xA5,0xB5,0xA5,0xA6,0x87,0x88,0x87,0x78,0x87,0x86,     //2041   
       0xA5,0xB3,0xA5,0xB5,0xA6,0xA6,0x88,0x88,0x88,0x78,0x87,0x87,     //2042   
       0xA5,0xB4,0x96,0xA5,0xA6,0x96,0x88,0x88,0x78,0x78,0x87,0x87,     //2043   
       0x95,0xB4,0xA5,0xB4,0xA5,0xA6,0x97,0x87,0x87,0x88,0x87,0x96,     //2044   
       0xA5,0xC3,0xA5,0xB4,0xA5,0xA6,0x87,0x88,0x87,0x78,0x87,0x86,     //2045   
       0xA5,0xB3,0xA5,0xB5,0xA6,0xA6,0x87,0x88,0x88,0x78,0x87,0x87,     //2046   
       0xA5,0xB4,0x96,0xA5,0xA6,0x96,0x88,0x88,0x78,0x78,0x87,0x87,     //2047   
       0x95,0xB4,0xA5,0xB4,0xA5,0xA5,0x97,0x87,0x87,0x88,0x86,0x96,     //2048   
       0xA4,0xC3,0xA5,0xA5,0xA5,0xA6,0x97,0x87,0x87,0x78,0x87,0x86,     //2049   
       0xA5,0xC3,0xA5,0xB5,0xA6,0xA6,0x87,0x88,0x78,0x78,0x87,0x87,     //2050
    };

unsigned char jieqi(unsigned char y2, unsigned char m2, unsigned char d2)
{
	unsigned char temp, d, y, y1, m;
	unsigned int addr;
	d = d2 / 16 * 10 + d2 % 16;
	m = m2 / 16 * 10 + m2 % 16;
	y1 = y2 / 16 * 10 + y2 % 16 + 2000;
	y = y1 - 1901;
	addr = y * 12 + m - 1;
	if (d < 15)
	{
		temp = 15 - d;
		if ((jieqi_code[addr] >> 4) == temp) return (m * 2 - 1);
		else return (0);
	}
	if (d == 15) return (0);
	if (d > 15)
	{
		temp = d - 15;
		if ((jieqi_code[addr] & 0x0f) == temp) return (m * 2);
		else return (0);
	}
	return (0);
}

