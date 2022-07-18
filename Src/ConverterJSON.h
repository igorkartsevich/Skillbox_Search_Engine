#pragma once

#include <vector>

#include "SearchServer.h"

// EXCEPTIONS
class ConfigFileEmpty_Exception : public std::exception {
public:
	const char* what() const noexcept override {
		return "ERROR! Config file is empty.";
	}
};
class ConfigFileMissing_Exception : std::exception {
public:
	const char* what() const noexcept override {
		return "ERROR! Config file is missing.";
	}
};
class ConfigFileVersionEmpty_Exception : public std::exception {
public:
	const char* what() const noexcept override {
		return "ERROR! Config file version is empty.";
	}
};
class ConfigFileVersionIncorrect_Exception : public std::exception {
public:
	const char* what() const noexcept override {
		return "ERROR! Config file has incorrect file version.";
	}
};
class RequestsFileEmpty_Exception : public std::exception {
public:
	const char* what() const noexcept override {
		return "ERROR! Requests file is empty.";
	}
};
class RequestsFileMissing_Exception : std::exception {
public:
	const char* what() const noexcept override {
		return "ERROR! Requests file is missing.";
	}
};
class MoreThen1000WordsText_Ecxeption : public std::exception {
public:
	const char* what() const noexcept override {
		return "ERROR! Text file contains more than 1.000 words.";
	}
};
class MoreThen100CharsWord_Exception : std::exception {
public:
	const char* what() const noexcept override {
		return "ERROR! Word from text file contains more than 100 chars.";
	}
};
class MoreThen1000Requests_Ecxeption : public std::exception {
public:
	const char* what() const noexcept override {
		return "ERROR! Requests file contains more than 1.000 requests.";
	}
};
class MoreThen10WordsRequests_Exception : std::exception {
public:
	const char* what() const noexcept override {
		return "ERROR! Request from requests file contains more than 10 words.";
	}
};

class ConverterJSON {
public:

	ConverterJSON() = default;

	std::vector<std::string> GetTextDocuments();
	int GetResponsesLimit();
	std::vector<std::string> GetRequests();
	void PutAnswers(std::vector<std::vector<struct RelativeIndex>> answers);
};