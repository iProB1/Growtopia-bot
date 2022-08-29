

#include "Utils.h"

#include <chrono>
#include <tchar.h>

// Utils

std::vector<std::string> Utils::Split(const std::string &str,const std::string &delimiter) {
	std::vector<std::string> arr;
	int strleng = str.length();
	int delleng = delimiter.length();
	if (delleng == 0) return arr;
	int i = 0;
	int k = 0;
	while (i < strleng) {
		int j = 0;
		while (i + j < strleng && j < delleng && str[i+j] == delimiter[j]) j++;
		if (j == delleng) {
			arr.push_back(str.substr(k,i-k));
			i += delleng;
			k = i;
		} else i++;
	}
	arr.push_back(str.substr(k, i - k));
	return arr;
}

std::string random_str = "0123456789ABCDEF";

std::string Utils::Random(int len) {
	std::string m_ret = "";
	for (int i = 0; i < len; i++)
		m_ret += random_str[rand() % random_str.length()];
	return m_ret;
}

std::string Utils::GenerateMac() {
	std::string m_ret = "";
	for (int i = 0; i < 6; i++) {
		if (i > 0)
			m_ret += ":";
		m_ret += random_str[rand() % random_str.length()];
		m_ret += random_str[rand() % random_str.length()];
	}
	return m_ret;
}

bool Utils::Replace(std::string& str, const std::string& from, const std::string& to) {
	size_t start_pos = str.find(from);
	if (start_pos == std::string::npos)
		return false;
	str.replace(start_pos, from.length(), to);
	return true;
}

bool Utils::HandleDelay(uint64_t& alpha, int beta) {
	if (alpha < GetTime()) {
		alpha = GetTime() + beta;
		return true;
	} else
		return false;
}

uint64_t Utils::GetTime() {
	return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

bool Utils::is_number(const std::string& s) {
	return !s.empty() && std::find_if(s.begin() + (*s.data() == '-' ? 1 : 0), s.end(), [](char c) { return !std::isdigit(c); }) == s.end();
}

