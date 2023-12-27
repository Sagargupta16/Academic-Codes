#include <bits/stdc++.h>
using namespace std;

string XOR(string s1, string s2){
	string s_xor = "";
	for (int i = 0; i < s1.length(); i++){
		if (s1[i] == s2[i]) s_xor += "0";
		else s_xor += "1";
	}
	return s_xor;
}
string getStringLeft(string fullKey){
	string left_part = "";
	for (int i = 0; i < fullKey.length() / 2; i++){
		left_part += fullKey[i];
	}
	return left_part;
}
string getStringRight(string fullKey){
	string right_part = "";
	for (int i = fullKey.length() / 2; i < fullKey.length(); i++){
		right_part += fullKey[i];
	}
	return right_part;
}
string shift_left(string key_part){
	string new_part = "";
	for (int i = 1; i < key_part.length(); i++){
		new_part += key_part[i];
	}
	new_part += key_part[0];
	return new_part;
}
string double_shift_left(string sh){
	string sh1 = "", sh2 = "";
	sh1 = shift_left(sh);
	sh2 = shift_left(sh1);
	return sh2;
}
string str2b(string k1) {
    string kb = "";
    for (int i = 0; i < k1.length(); i++){
        char c = k1[i];
        if (isdigit(c)) kb += bitset<4>(c - '0').to_string();
        else kb += bitset<4>(c - 'A' + 10).to_string();
    }
    return kb;
}
string b2hex(string bstr){
    string hexstr = "";
    for (int i = 0; i < bstr.length(); i += 4){
        string substr = bstr.substr(i, 4);
        hexstr += (substr == "0000") ? "0" :
                  (substr == "0001") ? "1" :
                  (substr == "0010") ? "2" :
                  (substr == "0011") ? "3" :
                  (substr == "0100") ? "4" :
                  (substr == "0101") ? "5" :
                  (substr == "0110") ? "6" :
                  (substr == "0111") ? "7" :
                  (substr == "1000") ? "8" :
                  (substr == "1001") ? "9" :
                  (substr == "1010") ? "A" :
                  (substr == "1011") ? "B" :
                  (substr == "1100") ? "C" :
                  (substr == "1101") ? "D" :
                  (substr == "1110") ? "E" :
                  (substr == "1111") ? "F" : "";
    }
    return hexstr;
}
string PC1(string p){
    string k = str2b(p);
    string kp = "";
    int pc1[] = {56, 48, 40, 32, 24, 16, 8, 0, 57, 49, 41, 33, 25, 17, 9, 1, 58, 50, 42, 34, 26, 18, 10, 2, 59, 51, 43, 35, 62, 54, 46, 38, 30, 22, 14, 6, 61, 53, 45, 37, 29, 21, 13, 5, 60, 52, 44, 36, 28, 20, 12, 4, 27, 19, 11, 3};
    for (int i = 0; i < 56; i++) {
        kp += k[pc1[i]];
    }
    return kp;
}
string PC2(string k) {
    string kp = "";
    int pc2[] = {13, 16, 10, 23, 0, 4, 2, 27, 14, 5, 20, 9, 22, 18, 11, 3, 25, 7, 15, 6, 26, 19, 12, 1, 40, 51, 30, 36, 46, 54, 29, 39, 50, 44, 32, 47, 43, 48, 38, 55, 33, 52, 45, 41, 49, 35, 28, 31};
    for (int i = 0; i < 48; i++) {
        kp += k[pc2[i]];
    }
    return kp;
}
string IP(string m){
    string mp = "", m_b = "";
    m_b = str2b(m);
    int ip[] = {57, 49, 41, 33, 25, 17, 9, 1, 59, 51, 43, 35, 27, 19, 11, 3, 61, 53, 45, 37, 29, 21, 13, 5, 63, 55, 47, 39, 31, 23, 15, 7, 56, 48, 40, 32, 24, 16, 8, 0, 58, 50, 42, 34, 26, 18, 10, 2, 60, 52, 44, 36, 28, 20, 12, 4, 62, 54, 46, 38, 30, 22, 14, 6};
    for (int i = 0; i < 64; i++) {
        mp += m_b[ip[i]];
    }
    return mp;
}
string P(string m){
    int p[] = {15, 6, 19, 20, 28, 11, 27, 16, 0, 14, 22, 25, 4, 17, 30, 9, 1, 7, 23, 13, 31, 26, 2, 8, 18, 12, 29, 5, 21, 10, 3, 24};
    string mp = "";
    for (int i = 0; i < 32; i++) {
        mp += m[p[i]];
    }
    return mp;
}
string IP_1(string m){
    string mp = "";
    int ip_1[] = {39, 7, 47, 15, 55, 23, 63, 31, 38, 6, 46, 14, 54, 22, 62, 30, 37, 5, 45, 13, 53, 21, 61, 29, 36, 4, 44, 12, 52, 20, 60, 28, 35, 3, 43, 11, 51, 19, 59, 27, 34, 2, 42, 10, 50, 18, 58, 26, 33, 1, 41, 9, 49, 17, 57, 25, 32, 0, 40, 8, 48, 16, 56, 24};
    for (int i = 0; i < 64; i++) {
        mp += m[ip_1[i]];
    }
    return mp;
}
string expand(string R_str){
    int e[] = {31, 0, 1, 2, 3, 4, 3, 4, 5, 6, 7, 8, 7, 8, 9, 10, 11, 12, 11, 12, 13, 14, 15, 16, 15, 16, 17, 18, 19, 20, 19, 20, 21, 22, 23, 24, 23, 24, 25, 26, 27, 28, 27, 28, 29, 30, 31, 0};
    string R_str_e = "";
    for (int i = 0; i < 48; i++) {
        R_str_e += R_str[e[i]];
    }
    return R_str_e;
}
void key_rounds(string full, string arr_pc2[]){
    string key_56 = "", left = "", right = "", arr_left[16], arr_right[16], arr_total[16];
    key_56 = PC1(full);
    left = getStringLeft(key_56);
    right = getStringRight(key_56);
    for (int i = 0; i < 16; i++) {
        arr_left[i] = (i < 2) ? shift_left(arr_left[i-1]) : ((i == 2 || i == 9 || i == 16) ? double_shift_left(arr_left[i-1]) : arr_left[i-1]);
        arr_right[i] = (i < 2) ? shift_left(arr_right[i-1]) : ((i == 2 || i == 9 || i == 16) ? double_shift_left(arr_right[i-1]) : arr_right[i-1]);
        arr_total[i] = arr_left[i] + arr_right[i];
        arr_pc2[i] += PC2(arr_total[i]);
    }
}
string sbox(string s_48){
	string sboxs[8], s_32 = "";
	for (int i = 0; i < 6; i++) sboxs[0] += s_48[i];
	if (sboxs[0] == "000000")sboxs[0] = "1110"; else if (sboxs[0] == "000001")sboxs[0] = "0000"; else if (sboxs[0] == "100000")sboxs[0] = "0100";
	else if (sboxs[0] == "100001")sboxs[0] = "1111"; else if (sboxs[0] == "000010")sboxs[0] = "0100"; else if (sboxs[0] == "000011")sboxs[0] = "1111";
	else if (sboxs[0] == "100010")sboxs[0] = "0001"; else if (sboxs[0] == "100011")sboxs[0] = "1100"; else if (sboxs[0] == "000100")sboxs[0] = "1101";
	else if (sboxs[0] == "000101")sboxs[0] = "0111"; else if (sboxs[0] == "100100")sboxs[0] = "1110"; else if (sboxs[0] == "100101")sboxs[0] = "1000";
	else if (sboxs[0] == "000110")sboxs[0] = "0001"; else if (sboxs[0] == "000111")sboxs[0] = "0100"; else if (sboxs[0] == "100110")sboxs[0] = "1000";
	else if (sboxs[0] == "100111")sboxs[0] = "0010"; else if (sboxs[0] == "001000")sboxs[0] = "0010"; else if (sboxs[0] == "001001")sboxs[0] = "1110";
	else if (sboxs[0] == "101000")sboxs[0] = "1101"; else if (sboxs[0] == "101001")sboxs[0] = "0100"; else if (sboxs[0] == "001010")sboxs[0] = "1111";
	else if (sboxs[0] == "001011")sboxs[0] = "0010"; else if (sboxs[0] == "101010")sboxs[0] = "0110"; else if (sboxs[0] == "101011")sboxs[0] = "1001";
	else if (sboxs[0] == "001100")sboxs[0] = "1011"; else if (sboxs[0] == "001101")sboxs[0] = "1101"; else if (sboxs[0] == "101100")sboxs[0] = "0010";
	else if (sboxs[0] == "101101")sboxs[0] = "0001"; else if (sboxs[0] == "001110")sboxs[0] = "1000"; else if (sboxs[0] == "001111")sboxs[0] = "0001";
	else if (sboxs[0] == "101110")sboxs[0] = "1011"; else if (sboxs[0] == "101111")sboxs[0] = "0111"; else if (sboxs[0] == "010000")sboxs[0] = "0011";
	else if (sboxs[0] == "010001")sboxs[0] = "1010"; else if (sboxs[0] == "110000")sboxs[0] = "1111"; else if (sboxs[0] == "110001")sboxs[0] = "0101";
	else if (sboxs[0] == "010010")sboxs[0] = "1010"; else if (sboxs[0] == "010011")sboxs[0] = "0110"; else if (sboxs[0] == "110010")sboxs[0] = "1100";
	else if (sboxs[0] == "110011")sboxs[0] = "1011"; else if (sboxs[0] == "010100")sboxs[0] = "0110"; else if (sboxs[0] == "010101")sboxs[0] = "1100";
	else if (sboxs[0] == "110100")sboxs[0] = "1001"; else if (sboxs[0] == "110101")sboxs[0] = "0011"; else if (sboxs[0] == "010110")sboxs[0] = "1100";
	else if (sboxs[0] == "010111")sboxs[0] = "1011"; else if (sboxs[0] == "110110")sboxs[0] = "0111"; else if (sboxs[0] == "110111")sboxs[0] = "1110";
	else if (sboxs[0] == "011000")sboxs[0] = "0101"; else if (sboxs[0] == "011001")sboxs[0] = "1001"; else if (sboxs[0] == "111000")sboxs[0] = "0011";
	else if (sboxs[0] == "111001")sboxs[0] = "1010"; else if (sboxs[0] == "011010")sboxs[0] = "1001"; else if (sboxs[0] == "011011")sboxs[0] = "0101";
	else if (sboxs[0] == "111010")sboxs[0] = "1010"; else if (sboxs[0] == "111011")sboxs[0] = "0000"; else if (sboxs[0] == "011100")sboxs[0] = "0000";
	else if (sboxs[0] == "011101")sboxs[0] = "0011"; else if (sboxs[0] == "111100")sboxs[0] = "0101"; else if (sboxs[0] == "111101")sboxs[0] = "0110";
	else if (sboxs[0] == "011110")sboxs[0] = "0111"; else if (sboxs[0] == "011111")sboxs[0] = "1000"; else if (sboxs[0] == "111110")sboxs[0] = "0000";
	else if (sboxs[0] == "111111")sboxs[0] = "1101";

    // S-box2:
	for (int i = 6; i < 12; i++) sboxs[1] += s_48[i];
	if (sboxs[1] == "000000") sboxs[1] = "1111"; else if (sboxs[1] == "000001")sboxs[1] = "0011"; else if (sboxs[1] == "100000")sboxs[1] = "0000";
	else if (sboxs[1] == "100001")sboxs[1] = "1101"; else if (sboxs[1] == "000010")sboxs[1] = "0001"; else if (sboxs[1] == "000011")sboxs[1] = "1101";
	else if (sboxs[1] == "100010")sboxs[1] = "1110"; else if (sboxs[1] == "100011")sboxs[1] = "1000"; else if (sboxs[1] == "000100")sboxs[1] = "1000";
	else if (sboxs[1] == "000101")sboxs[1] = "0100"; else if (sboxs[1] == "100100")sboxs[1] = "0111"; else if (sboxs[1] == "100101")sboxs[1] = "1010";
	else if (sboxs[1] == "000110")sboxs[1] = "1110"; else if (sboxs[1] == "000111")sboxs[1] = "0111"; else if (sboxs[1] == "100110")sboxs[1] = "1011";
	else if (sboxs[1] == "100111")sboxs[1] = "0001"; else if (sboxs[1] == "001000")sboxs[1] = "0110"; else if (sboxs[1] == "001001")sboxs[1] = "1111";
	else if (sboxs[1] == "101000")sboxs[1] = "1010"; else if (sboxs[1] == "101001")sboxs[1] = "0011"; else if (sboxs[1] == "001010")sboxs[1] = "1011";
	else if (sboxs[1] == "001011")sboxs[1] = "0010"; else if (sboxs[1] == "101010")sboxs[1] = "0100"; else if (sboxs[1] == "101011")sboxs[1] = "1111";
	else if (sboxs[1] == "001100")sboxs[1] = "0011"; else if (sboxs[1] == "001101")sboxs[1] = "1000"; else if (sboxs[1] == "101100")sboxs[1] = "1101";
	else if (sboxs[1] == "101101")sboxs[1] = "0100"; else if (sboxs[1] == "001110")sboxs[1] = "0100"; else if (sboxs[1] == "001111")sboxs[1] = "1110";
	else if (sboxs[1] == "101110")sboxs[1] = "0001"; else if (sboxs[1] == "101111")sboxs[1] = "0010"; else if (sboxs[1] == "010000")sboxs[1] = "1001";
	else if (sboxs[1] == "010001")sboxs[1] = "1100"; else if (sboxs[1] == "110000")sboxs[1] = "0101"; else if (sboxs[1] == "110001")sboxs[1] = "1011";
	else if (sboxs[1] == "010010")sboxs[1] = "0111"; else if (sboxs[1] == "010011")sboxs[1] = "0000"; else if (sboxs[1] == "110010")sboxs[1] = "1000";
	else if (sboxs[1] == "110011")sboxs[1] = "0110"; else if (sboxs[1] == "010100")sboxs[1] = "0010"; else if (sboxs[1] == "010101")sboxs[1] = "0001";
	else if (sboxs[1] == "110100")sboxs[1] = "1100"; else if (sboxs[1] == "110101")sboxs[1] = "0111"; else if (sboxs[1] == "010110")sboxs[1] = "1101";
	else if (sboxs[1] == "010111")sboxs[1] = "1010"; else if (sboxs[1] == "110110")sboxs[1] = "0110"; else if (sboxs[1] == "110111")sboxs[1] = "1100";
	else if (sboxs[1] == "011000")sboxs[1] = "1100"; else if (sboxs[1] == "011001")sboxs[1] = "0110"; else if (sboxs[1] == "111000")sboxs[1] = "1001";
	else if (sboxs[1] == "111001")sboxs[1] = "0000"; else if (sboxs[1] == "011010")sboxs[1] = "0000"; else if (sboxs[1] == "011011")sboxs[1] = "1001";
	else if (sboxs[1] == "111010")sboxs[1] = "0011"; else if (sboxs[1] == "111011")sboxs[1] = "0101"; else if (sboxs[1] == "011100")sboxs[1] = "0101";
	else if (sboxs[1] == "011101")sboxs[1] = "1011"; else if (sboxs[1] == "111100")sboxs[1] = "0010"; else if (sboxs[1] == "111101")sboxs[1] = "1110";
	else if (sboxs[1] == "011110")sboxs[1] = "1010"; else if (sboxs[1] == "011111")sboxs[1] = "0101"; else if (sboxs[1] == "111110")sboxs[1] = "1111";
	else if (sboxs[1] == "111111")sboxs[1] = "1001";


	// S-box3:
	for (int i = 12; i < 18; i++) sboxs[2] += s_48[i];
	if (sboxs[2] == "000000")sboxs[2] = "1010"; else if (sboxs[2] == "000001")sboxs[2] = "1101"; else if (sboxs[2] == "100000")sboxs[2] = "1101";
	else if (sboxs[2] == "100001")sboxs[2] = "0001"; else if (sboxs[2] == "000010")sboxs[2] = "0000"; else if (sboxs[2] == "000011")sboxs[2] = "0111";
	else if (sboxs[2] == "100010")sboxs[2] = "0110"; else if (sboxs[2] == "100011")sboxs[2] = "1010"; else if (sboxs[2] == "000100")sboxs[2] = "1001";
	else if (sboxs[2] == "000101")sboxs[2] = "0000"; else if (sboxs[2] == "100100")sboxs[2] = "0100"; else if (sboxs[2] == "100101")sboxs[2] = "1101";
	else if (sboxs[2] == "000110")sboxs[2] = "1110"; else if (sboxs[2] == "000111")sboxs[2] = "1001"; else if (sboxs[2] == "100110")sboxs[2] = "1001";
	else if (sboxs[2] == "100111")sboxs[2] = "0000"; else if (sboxs[2] == "001000")sboxs[2] = "0110"; else if (sboxs[2] == "001001")sboxs[2] = "0011";
	else if (sboxs[2] == "101000")sboxs[2] = "1000"; else if (sboxs[2] == "101001")sboxs[2] = "0110"; else if (sboxs[2] == "001010")sboxs[2] = "0011";
	else if (sboxs[2] == "001011")sboxs[2] = "0100"; else if (sboxs[2] == "101010")sboxs[2] = "1111"; else if (sboxs[2] == "101011")sboxs[2] = "1001";
	else if (sboxs[2] == "001100")sboxs[2] = "1111"; else if (sboxs[2] == "001101")sboxs[2] = "0110"; else if (sboxs[2] == "101100")sboxs[2] = "0011";
	else if (sboxs[2] == "101101")sboxs[2] = "1000"; else if (sboxs[2] == "001110")sboxs[2] = "0101"; else if (sboxs[2] == "001111")sboxs[2] = "1010";
	else if (sboxs[2] == "101110")sboxs[2] = "0000"; else if (sboxs[2] == "101111")sboxs[2] = "0111"; else if (sboxs[2] == "010000")sboxs[2] = "0001";
	else if (sboxs[2] == "010001")sboxs[2] = "0010"; else if (sboxs[2] == "110000")sboxs[2] = "1011"; else if (sboxs[2] == "110001")sboxs[2] = "0100";
	else if (sboxs[2] == "010010")sboxs[2] = "1101"; else if (sboxs[2] == "010011")sboxs[2] = "1000"; else if (sboxs[2] == "110010")sboxs[2] = "0001";
	else if (sboxs[2] == "110011")sboxs[2] = "1111"; else if (sboxs[2] == "010100")sboxs[2] = "1100"; else if (sboxs[2] == "010101")sboxs[2] = "0101";
	else if (sboxs[2] == "110100")sboxs[2] = "0010"; else if (sboxs[2] == "110101")sboxs[2] = "1110"; else if (sboxs[2] == "010110")sboxs[2] = "0111";
	else if (sboxs[2] == "010111")sboxs[2] = "1110"; else if (sboxs[2] == "110110")sboxs[2] = "1100"; else if (sboxs[2] == "110111")sboxs[2] = "0011";
	else if (sboxs[2] == "011000")sboxs[2] = "1011"; else if (sboxs[2] == "011001")sboxs[2] = "1100"; else if (sboxs[2] == "111000")sboxs[2] = "0101";
	else if (sboxs[2] == "111001")sboxs[2] = "1011"; else if (sboxs[2] == "011010")sboxs[2] = "0100"; else if (sboxs[2] == "011011")sboxs[2] = "1011";
	else if (sboxs[2] == "111010")sboxs[2] = "1010"; else if (sboxs[2] == "111011")sboxs[2] = "0101"; else if (sboxs[2] == "011100")sboxs[2] = "0010";
	else if (sboxs[2] == "011101")sboxs[2] = "1111"; else if (sboxs[2] == "111100")sboxs[2] = "1110"; else if (sboxs[2] == "111101")sboxs[2] = "0010";
	else if (sboxs[2] == "011110")sboxs[2] = "1000"; else if (sboxs[2] == "011111")sboxs[2] = "0001"; else if (sboxs[2] == "111110")sboxs[2] = "0111";
	else if (sboxs[2] == "111111")sboxs[2] = "1100";

	// S-box4:
	for (int i = 18; i < 24; i++) sboxs[3] += s_48[i];
	if (sboxs[3] == "000000")sboxs[3] = "0111"; else if (sboxs[3] == "000001")sboxs[3] = "1101"; else if (sboxs[3] == "100000")sboxs[3] = "1010";
	else if (sboxs[3] == "100001")sboxs[3] = "0011"; else if (sboxs[3] == "000010")sboxs[3] = "1101"; else if (sboxs[3] == "000011")sboxs[3] = "1000";
	else if (sboxs[3] == "100010")sboxs[3] = "0110"; else if (sboxs[3] == "100011")sboxs[3] = "1111"; else if (sboxs[3] == "000100")sboxs[3] = "1110";
	else if (sboxs[3] == "000101")sboxs[3] = "1011"; else if (sboxs[3] == "100100")sboxs[3] = "1001"; else if (sboxs[3] == "100101")sboxs[3] = "0000";
	else if (sboxs[3] == "000110")sboxs[3] = "0011"; else if (sboxs[3] == "000111")sboxs[3] = "0101"; else if (sboxs[3] == "100110")sboxs[3] = "0000";
	else if (sboxs[3] == "100111")sboxs[3] = "0110"; else if (sboxs[3] == "001000")sboxs[3] = "0000"; else if (sboxs[3] == "001001")sboxs[3] = "0110";
	else if (sboxs[3] == "101000")sboxs[3] = "1100"; else if (sboxs[3] == "101001")sboxs[3] = "1010"; else if (sboxs[3] == "001010")sboxs[3] = "0110";
	else if (sboxs[3] == "001011")sboxs[3] = "1111"; else if (sboxs[3] == "101010")sboxs[3] = "1011"; else if (sboxs[3] == "101011")sboxs[3] = "0001";
	else if (sboxs[3] == "001100")sboxs[3] = "1001"; else if (sboxs[3] == "001101")sboxs[3] = "0000"; else if (sboxs[3] == "101100")sboxs[3] = "0111";
	else if (sboxs[3] == "101101")sboxs[3] = "1101"; else if (sboxs[3] == "001110")sboxs[3] = "1010"; else if (sboxs[3] == "001111")sboxs[3] = "0011";
	else if (sboxs[3] == "101110")sboxs[3] = "1101"; else if (sboxs[3] == "101111")sboxs[3] = "1000"; else if (sboxs[3] == "010000")sboxs[3] = "0001";
	else if (sboxs[3] == "010001")sboxs[3] = "0100"; else if (sboxs[3] == "110000")sboxs[3] = "1111"; else if (sboxs[3] == "110001")sboxs[3] = "1001";
	else if (sboxs[3] == "010010")sboxs[3] = "0010"; else if (sboxs[3] == "010011")sboxs[3] = "0111"; else if (sboxs[3] == "110010")sboxs[3] = "0001";
	else if (sboxs[3] == "110011")sboxs[3] = "0100"; else if (sboxs[3] == "010100")sboxs[3] = "1000"; else if (sboxs[3] == "010101")sboxs[3] = "0010";
	else if (sboxs[3] == "110100")sboxs[3] = "0011"; else if (sboxs[3] == "110101")sboxs[3] = "0101"; else if (sboxs[3] == "010110")sboxs[3] = "0101";
	else if (sboxs[3] == "010111")sboxs[3] = "1100"; else if (sboxs[3] == "110110")sboxs[3] = "1110"; else if (sboxs[3] == "110111")sboxs[3] = "1011";
	else if (sboxs[3] == "011000")sboxs[3] = "1011"; else if (sboxs[3] == "011001")sboxs[3] = "0001"; else if (sboxs[3] == "111000")sboxs[3] = "0101";
	else if (sboxs[3] == "111001")sboxs[3] = "1100"; else if (sboxs[3] == "011010")sboxs[3] = "1100"; else if (sboxs[3] == "011011")sboxs[3] = "1010";
	else if (sboxs[3] == "111010")sboxs[3] = "0010"; else if (sboxs[3] == "111011")sboxs[3] = "0111"; else if (sboxs[3] == "011100")sboxs[3] = "0100";
	else if (sboxs[3] == "011101")sboxs[3] = "1110"; else if (sboxs[3] == "111100")sboxs[3] = "1000"; else if (sboxs[3] == "111101")sboxs[3] = "0010";
	else if (sboxs[3] == "011110")sboxs[3] = "1111"; else if (sboxs[3] == "011111")sboxs[3] = "1001"; else if (sboxs[3] == "111110")sboxs[3] = "0100";
	else if (sboxs[3] == "111111")sboxs[3] = "1110";

	// S-box5:
	for (int i = 24; i < 30; i++) sboxs[4] += s_48[i];
	if (sboxs[4] == "000000")sboxs[4] = "0010"; else if (sboxs[4] == "000001")sboxs[4] = "1110"; else if (sboxs[4] == "100000")sboxs[4] = "0100";
	else if (sboxs[4] == "100001")sboxs[4] = "1011"; else if (sboxs[4] == "000010")sboxs[4] = "1100"; else if (sboxs[4] == "000011")sboxs[4] = "1011";
	else if (sboxs[4] == "100010")sboxs[4] = "0010"; else if (sboxs[4] == "100011")sboxs[4] = "1000"; else if (sboxs[4] == "000100")sboxs[4] = "0100";
	else if (sboxs[4] == "000101")sboxs[4] = "0010"; else if (sboxs[4] == "100100")sboxs[4] = "0001"; else if (sboxs[4] == "100101")sboxs[4] = "1100";
	else if (sboxs[4] == "000110")sboxs[4] = "0001"; else if (sboxs[4] == "000111")sboxs[4] = "1100"; else if (sboxs[4] == "100110")sboxs[4] = "1011";
	else if (sboxs[4] == "100111")sboxs[4] = "0111"; else if (sboxs[4] == "001000")sboxs[4] = "0111"; else if (sboxs[4] == "001001")sboxs[4] = "0100";
	else if (sboxs[4] == "101000")sboxs[4] = "1010"; else if (sboxs[4] == "101001")sboxs[4] = "0001"; else if (sboxs[4] == "001010")sboxs[4] = "1010";
	else if (sboxs[4] == "001011")sboxs[4] = "0111"; else if (sboxs[4] == "101010")sboxs[4] = "1101"; else if (sboxs[4] == "101011")sboxs[4] = "1110";
	else if (sboxs[4] == "001100")sboxs[4] = "1011"; else if (sboxs[4] == "001101")sboxs[4] = "1101"; else if (sboxs[4] == "101100")sboxs[4] = "0111";
	else if (sboxs[4] == "101101")sboxs[4] = "0010"; else if (sboxs[4] == "001110")sboxs[4] = "0110"; else if (sboxs[4] == "001111")sboxs[4] = "0001";
	else if (sboxs[4] == "101110")sboxs[4] = "1000"; else if (sboxs[4] == "101111")sboxs[4] = "1101"; else if (sboxs[4] == "010000")sboxs[4] = "1000";
	else if (sboxs[4] == "010001")sboxs[4] = "0101"; else if (sboxs[4] == "110000")sboxs[4] = "1111"; else if (sboxs[4] == "110001")sboxs[4] = "0110";
	else if (sboxs[4] == "010010")sboxs[4] = "0101"; else if (sboxs[4] == "010011")sboxs[4] = "0000"; else if (sboxs[4] == "110010")sboxs[4] = "1001";
	else if (sboxs[4] == "110011")sboxs[4] = "1111"; else if (sboxs[4] == "010100")sboxs[4] = "0011"; else if (sboxs[4] == "010101")sboxs[4] = "1111";
	else if (sboxs[4] == "110100")sboxs[4] = "1100"; else if (sboxs[4] == "110101")sboxs[4] = "0000"; else if (sboxs[4] == "010110")sboxs[4] = "1111";
	else if (sboxs[4] == "010111")sboxs[4] = "1010"; else if (sboxs[4] == "110110")sboxs[4] = "0101"; else if (sboxs[4] == "110111")sboxs[4] = "1001";
	else if (sboxs[4] == "011000")sboxs[4] = "1101"; else if (sboxs[4] == "011001")sboxs[4] = "0011"; else if (sboxs[4] == "111000")sboxs[4] = "0110";
	else if (sboxs[4] == "111001")sboxs[4] = "1010"; else if (sboxs[4] == "011010")sboxs[4] = "0000"; else if (sboxs[4] == "011011")sboxs[4] = "1001";
	else if (sboxs[4] == "111010")sboxs[4] = "0011"; else if (sboxs[4] == "111011")sboxs[4] = "0100"; else if (sboxs[4] == "011100")sboxs[4] = "1110";
	else if (sboxs[4] == "011101")sboxs[4] = "1000"; else if (sboxs[4] == "111100")sboxs[4] = "0000"; else if (sboxs[4] == "111101")sboxs[4] = "0101";
	else if (sboxs[4] == "011110")sboxs[4] = "1001"; else if (sboxs[4] == "011111")sboxs[4] = "0110"; else if (sboxs[4] == "111110")sboxs[4] = "1110";
	else if (sboxs[4] == "111111")sboxs[4] = "0011";

	// S-box6:
	for (int i = 30; i < 36; i++) sboxs[5] += s_48[i];
	if (sboxs[5] == "000000")sboxs[5] = "1100"; else if (sboxs[5] == "000001")sboxs[5] = "1010"; else if (sboxs[5] == "100000")sboxs[5] = "1001";
	else if (sboxs[5] == "100001")sboxs[5] = "0100"; else if (sboxs[5] == "000010")sboxs[5] = "0001"; else if (sboxs[5] == "000011")sboxs[5] = "1111";
	else if (sboxs[5] == "100010")sboxs[5] = "1110"; else if (sboxs[5] == "100011")sboxs[5] = "0011"; else if (sboxs[5] == "000100")sboxs[5] = "1010";
	else if (sboxs[5] == "000101")sboxs[5] = "0100"; else if (sboxs[5] == "100100")sboxs[5] = "1111"; else if (sboxs[5] == "100101")sboxs[5] = "0010";
	else if (sboxs[5] == "000110")sboxs[5] = "1111"; else if (sboxs[5] == "000111")sboxs[5] = "0010"; else if (sboxs[5] == "100110")sboxs[5] = "0101";
	else if (sboxs[5] == "100111")sboxs[5] = "1100"; else if (sboxs[5] == "001000")sboxs[5] = "1001"; else if (sboxs[5] == "001001")sboxs[5] = "0111";
	else if (sboxs[5] == "101000")sboxs[5] = "0010"; else if (sboxs[5] == "101001")sboxs[5] = "1001"; else if (sboxs[5] == "001010")sboxs[5] = "0010";
	else if (sboxs[5] == "001011")sboxs[5] = "1100"; else if (sboxs[5] == "101010")sboxs[5] = "1000"; else if (sboxs[5] == "101011")sboxs[5] = "0101";
	else if (sboxs[5] == "001100")sboxs[5] = "0110"; else if (sboxs[5] == "001101")sboxs[5] = "1001"; else if (sboxs[5] == "101100")sboxs[5] = "1100";
	else if (sboxs[5] == "101101")sboxs[5] = "1111"; else if (sboxs[5] == "001110")sboxs[5] = "1000"; else if (sboxs[5] == "001111")sboxs[5] = "0101";
	else if (sboxs[5] == "101110")sboxs[5] = "0011"; else if (sboxs[5] == "101111")sboxs[5] = "1010"; else if (sboxs[5] == "010000")sboxs[5] = "0000";
	else if (sboxs[5] == "010001")sboxs[5] = "0110"; else if (sboxs[5] == "110000")sboxs[5] = "0111"; else if (sboxs[5] == "110001")sboxs[5] = "1011";
	else if (sboxs[5] == "010010")sboxs[5] = "1101"; else if (sboxs[5] == "010011")sboxs[5] = "0001"; else if (sboxs[5] == "110010")sboxs[5] = "0000";
	else if (sboxs[5] == "110011")sboxs[5] = "1110"; else if (sboxs[5] == "010100")sboxs[5] = "0011"; else if (sboxs[5] == "010101")sboxs[5] = "1101";
	else if (sboxs[5] == "110100")sboxs[5] = "0100"; else if (sboxs[5] == "110101")sboxs[5] = "0001"; else if (sboxs[5] == "010110")sboxs[5] = "0100";
	else if (sboxs[5] == "010111")sboxs[5] = "1110"; else if (sboxs[5] == "110110")sboxs[5] = "1010"; else if (sboxs[5] == "110111")sboxs[5] = "0111";
	else if (sboxs[5] == "011000")sboxs[5] = "1110"; else if (sboxs[5] == "011001")sboxs[5] = "0000"; else if (sboxs[5] == "111000")sboxs[5] = "0001";
	else if (sboxs[5] == "111001")sboxs[5] = "0110"; else if (sboxs[5] == "011010")sboxs[5] = "0111"; else if (sboxs[5] == "011011")sboxs[5] = "1011";
	else if (sboxs[5] == "111010")sboxs[5] = "1101"; else if (sboxs[5] == "111011")sboxs[5] = "0000"; else if (sboxs[5] == "011100")sboxs[5] = "0101";
	else if (sboxs[5] == "011101")sboxs[5] = "0011"; else if (sboxs[5] == "111100")sboxs[5] = "1011"; else if (sboxs[5] == "111101")sboxs[5] = "1000";
	else if (sboxs[5] == "011110")sboxs[5] = "1011"; else if (sboxs[5] == "011111")sboxs[5] = "1000"; else if (sboxs[5] == "111110")sboxs[5] = "0110";
	else if (sboxs[5] == "111111")sboxs[5] = "1101";

	// S-box7:
	for (int i = 36; i < 42; i++) sboxs[6] += s_48[i];
	if (sboxs[6] == "000000")sboxs[6] = "0100"; else if (sboxs[6] == "000001")sboxs[6] = "1101"; else if (sboxs[6] == "100000")sboxs[6] = "0001";
	else if (sboxs[6] == "100001")sboxs[6] = "0110"; else if (sboxs[6] == "000010")sboxs[6] = "1011"; else if (sboxs[6] == "000011")sboxs[6] = "0000";
	else if (sboxs[6] == "100010")sboxs[6] = "0100"; else if (sboxs[6] == "100011")sboxs[6] = "1011"; else if (sboxs[6] == "000100")sboxs[6] = "0010";
	else if (sboxs[6] == "000101")sboxs[6] = "1011"; else if (sboxs[6] == "100100")sboxs[6] = "1011"; else if (sboxs[6] == "100101")sboxs[6] = "1101";
	else if (sboxs[6] == "000110")sboxs[6] = "1110"; else if (sboxs[6] == "000111")sboxs[6] = "0111"; else if (sboxs[6] == "100110")sboxs[6] = "1101";
	else if (sboxs[6] == "100111")sboxs[6] = "1000"; else if (sboxs[6] == "001000")sboxs[6] = "1111"; else if (sboxs[6] == "001001")sboxs[6] = "0100";
	else if (sboxs[6] == "101000")sboxs[6] = "1100"; else if (sboxs[6] == "101001")sboxs[6] = "0001"; else if (sboxs[6] == "001010")sboxs[6] = "0000";
	else if (sboxs[6] == "001011")sboxs[6] = "1001"; else if (sboxs[6] == "101010")sboxs[6] = "0011"; else if (sboxs[6] == "101011")sboxs[6] = "0100";
	else if (sboxs[6] == "001100")sboxs[6] = "1000"; else if (sboxs[6] == "001101")sboxs[6] = "0001"; else if (sboxs[6] == "101100")sboxs[6] = "0111";
	else if (sboxs[6] == "101101")sboxs[6] = "1010"; else if (sboxs[6] == "001110")sboxs[6] = "1101"; else if (sboxs[6] == "001111")sboxs[6] = "1010";
	else if (sboxs[6] == "101110")sboxs[6] = "1110"; else if (sboxs[6] == "101111")sboxs[6] = "0111"; else if (sboxs[6] == "010000")sboxs[6] = "0011";
	else if (sboxs[6] == "010001")sboxs[6] = "1110"; else if (sboxs[6] == "110000")sboxs[6] = "1010"; else if (sboxs[6] == "110001")sboxs[6] = "1001";
	else if (sboxs[6] == "010010")sboxs[6] = "1100"; else if (sboxs[6] == "010011")sboxs[6] = "0011"; else if (sboxs[6] == "110010")sboxs[6] = "1111";
	else if (sboxs[6] == "110011")sboxs[6] = "0101"; else if (sboxs[6] == "010100")sboxs[6] = "1001"; else if (sboxs[6] == "010101")sboxs[6] = "0101";
	else if (sboxs[6] == "110100")sboxs[6] = "0110"; else if (sboxs[6] == "110101")sboxs[6] = "0000"; else if (sboxs[6] == "010110")sboxs[6] = "0111";
	else if (sboxs[6] == "010111")sboxs[6] = "1100"; else if (sboxs[6] == "110110")sboxs[6] = "1000"; else if (sboxs[6] == "110111")sboxs[6] = "1111";
	else if (sboxs[6] == "011000")sboxs[6] = "0101"; else if (sboxs[6] == "011001")sboxs[6] = "0010"; else if (sboxs[6] == "111000")sboxs[6] = "0000";
	else if (sboxs[6] == "111001")sboxs[6] = "1110"; else if (sboxs[6] == "011010")sboxs[6] = "1010"; else if (sboxs[6] == "011011")sboxs[6] = "1111";
	else if (sboxs[6] == "111010")sboxs[6] = "0101"; else if (sboxs[6] == "111011")sboxs[6] = "0010"; else if (sboxs[6] == "011100")sboxs[6] = "0110";
	else if (sboxs[6] == "011101")sboxs[6] = "1000"; else if (sboxs[6] == "111100")sboxs[6] = "1001"; else if (sboxs[6] == "111101")sboxs[6] = "0011";
	else if (sboxs[6] == "011110")sboxs[6] = "0001"; else if (sboxs[6] == "011111")sboxs[6] = "0110"; else if (sboxs[6] == "111110")sboxs[6] = "0010";
	else if (sboxs[6] == "111111")sboxs[6] = "1100";

	// S-box8:
	for (int i = 42; i < 48; i++) sboxs[7] += s_48[i];
	if (sboxs[7] == "000000")sboxs[7] = "1101"; else if (sboxs[7] == "000001")sboxs[7] = "0001"; else if (sboxs[7] == "100000")sboxs[7] = "0111";
	else if (sboxs[7] == "100001")sboxs[7] = "0010"; else if (sboxs[7] == "000010")sboxs[7] = "0010"; else if (sboxs[7] == "000011")sboxs[7] = "1111";
	else if (sboxs[7] == "100010")sboxs[7] = "1011"; else if (sboxs[7] == "100011")sboxs[7] = "0001"; else if (sboxs[7] == "000100")sboxs[7] = "1000";
	else if (sboxs[7] == "000101")sboxs[7] = "1101"; else if (sboxs[7] == "100100")sboxs[7] = "0100"; else if (sboxs[7] == "100101")sboxs[7] = "1110";
	else if (sboxs[7] == "000110")sboxs[7] = "0100"; else if (sboxs[7] == "000111")sboxs[7] = "1000"; else if (sboxs[7] == "100110")sboxs[7] = "0001";
	else if (sboxs[7] == "100111")sboxs[7] = "0111"; else if (sboxs[7] == "001000")sboxs[7] = "0110"; else if (sboxs[7] == "001001")sboxs[7] = "1010";
	else if (sboxs[7] == "101000")sboxs[7] = "1001"; else if (sboxs[7] == "101001")sboxs[7] = "0100"; else if (sboxs[7] == "001010")sboxs[7] = "1111";
	else if (sboxs[7] == "001011")sboxs[7] = "0011"; else if (sboxs[7] == "101010")sboxs[7] = "1100"; else if (sboxs[7] == "101011")sboxs[7] = "1010";
	else if (sboxs[7] == "001100")sboxs[7] = "1011"; else if (sboxs[7] == "001101")sboxs[7] = "0111"; else if (sboxs[7] == "101100")sboxs[7] = "1110";
	else if (sboxs[7] == "101101")sboxs[7] = "1000"; else if (sboxs[7] == "001110")sboxs[7] = "0001"; else if (sboxs[7] == "001111")sboxs[7] = "0100";
	else if (sboxs[7] == "101110")sboxs[7] = "0010"; else if (sboxs[7] == "101111")sboxs[7] = "1101"; else if (sboxs[7] == "010000")sboxs[7] = "1010";
	else if (sboxs[7] == "010001")sboxs[7] = "1100"; else if (sboxs[7] == "110000")sboxs[7] = "0000"; else if (sboxs[7] == "110001")sboxs[7] = "1111";
	else if (sboxs[7] == "010010")sboxs[7] = "1001"; else if (sboxs[7] == "010011")sboxs[7] = "0101"; else if (sboxs[7] == "110010")sboxs[7] = "0110";
	else if (sboxs[7] == "110011")sboxs[7] = "1100"; else if (sboxs[7] == "010100")sboxs[7] = "0011"; else if (sboxs[7] == "010101")sboxs[7] = "0110";
	else if (sboxs[7] == "110100")sboxs[7] = "1010"; else if (sboxs[7] == "110101")sboxs[7] = "1001"; else if (sboxs[7] == "010110")sboxs[7] = "1110";
	else if (sboxs[7] == "010111")sboxs[7] = "1011"; else if (sboxs[7] == "110110")sboxs[7] = "1101"; else if (sboxs[7] == "110111")sboxs[7] = "0000";
	else if (sboxs[7] == "011000")sboxs[7] = "0101"; else if (sboxs[7] == "011001")sboxs[7] = "0000"; else if (sboxs[7] == "111000")sboxs[7] = "1111";
	else if (sboxs[7] == "111001")sboxs[7] = "0011"; else if (sboxs[7] == "011010")sboxs[7] = "0000"; else if (sboxs[7] == "011011")sboxs[7] = "1110";
	else if (sboxs[7] == "111010")sboxs[7] = "0011"; else if (sboxs[7] == "111011")sboxs[7] = "0101"; else if (sboxs[7] == "011100")sboxs[7] = "1100";
	else if (sboxs[7] == "011101")sboxs[7] = "1001"; else if (sboxs[7] == "111100")sboxs[7] = "0101"; else if (sboxs[7] == "111101")sboxs[7] = "0110";
	else if (sboxs[7] == "011110")sboxs[7] = "0111"; else if (sboxs[7] == "011111")sboxs[7] = "0010"; else if (sboxs[7] == "111110")sboxs[7] = "1000";
	else if (sboxs[7] == "111111")sboxs[7] = "1011";

	for (int i = 0; i < 8; i++) s_32 += sboxs[i];
	return s_32;
}
string des_round(string Ri, string Kn){
	string des = "", des2 = "";
	string r = expand(Ri);
	des = XOR(r, Kn);
	des2 = sbox(des);
	return P(des2);
}
string encrypt(string full_msg, string original_key){
    string msg = "", l_msg = "", r_msg = "", msg_left[16], msg_right[16], concat_key[16],swapped = "";
    for (int i = 0; i < 16; i++) concat_key[i] = "";
    key_rounds(original_key, concat_key);
    msg = IP(full_msg);
    l_msg = getStringLeft(msg);
    r_msg = getStringRight(msg);
    msg_left[0] = r_msg;
    msg_right[0] = XOR(l_msg, des_round(r_msg, concat_key[0]));
    for (int i = 1; i < 16; i++) {
        msg_left[i] = msg_right[i-1];
        msg_right[i] = XOR(msg_left[i-1], des_round(msg_right[i-1], concat_key[i]));
    }
    swapped = msg_right[15]+msg_left[15];
    return b2hex(IP_1(swapped));
}
string decrypt(string full_msg, string original_key){
    string msg = "", l_msg = "", r_msg = "", msg_left[16], msg_right[16], concat_key[16],swapped = "";
    for (int i = 0; i < 16; i++) concat_key[i] = "";
    key_rounds(original_key, concat_key);
    msg = IP(full_msg);
    l_msg = getStringLeft(msg);
    r_msg = getStringRight(msg);
    for (int i = 0; i < 16; i++) {
        msg_left[i] = r_msg;
        msg_right[i] = XOR(l_msg, des_round(r_msg, concat_key[15-i]));
        l_msg = msg_left[i];
        r_msg = msg_right[i];
    }
    swapped = msg_right[15];
    swapped += msg_left[15];
	return b2hex(IP_1(swapped));
}

void encryptDycrypt(string text, string key){

	cout << "Text: " << text << endl;
	cout << "Key: " << key << endl;

	string encrypted_text = encrypt(text, key);
	cout << "Encrypted text: " << encrypted_text << endl;
	string decrypted_text = decrypt(encrypted_text, key);
	cout << "Decrypted text: " << decrypted_text << endl;
	if (decrypted_text == text) {
		cout << "Decryption successful!" << endl;
	} else {
		cout << "Decryption failed." << endl;
	}
}

int main(){
	string key="16102000ABCDEF12", text="1234567890ABCDEF";

	cout<<endl;
	encryptDycrypt(text, key);

	cout<<endl;
	key="1234567890ABCDEF", text="16102000ABCDEF12";
	encryptDycrypt(text, key);

	cout<<endl;

	return 0;
}