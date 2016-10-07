/*
 * logging_helper.h
 *
 *  Created on: Oct 6, 2016
 *      Author: rdu
 */

#ifndef CONTROL_SRC_CTRL_UTILS_LOGGING_LOGGING_HELPER_H_
#define CONTROL_SRC_CTRL_UTILS_LOGGING_LOGGING_HELPER_H_

#include <cstdint>
#include <string>
#include <vector>
#include <map>
#include <memory>
#include <atomic>

// headers for g3log
#include "g3log/g3log.hpp"
#include "g3log/logworker.hpp"
#include "g3log/std2_make_unique.hpp"

namespace smartcar {

class LoggingHelper {
public:
	LoggingHelper();
	LoggingHelper(std::string log_name_prefix, std::string log_save_path);
	~LoggingHelper();

private:
	bool head_added_;
	std::string log_name_prefix_;
	std::string log_save_path_;

	std::unique_ptr<g3::LogWorker> log_worker_;
	std::unique_ptr<g3::FileSinkHandle> file_sink_hd_;
	std::map<std::string, uint64_t> entry_indexes_;
	std::map<uint64_t, std::string> entry_names_;
	std::atomic<uint64_t> item_counter_;
	std::string log_entry_;
	std::vector<std::string> item_data_;

public:
	// basic functions
	void AddItemNameToEntryHead(std::string name);
	void AddItemDataToEntry(std::string item_name, std::string data_str);
	void AddItemDataToEntry(uint64_t item_id, std::string data_str);

	void PassEntryHeaderToLogger();
	void PassEntryDataToLogger();

	// extra helper functions
	void AddItemDataToEntry(std::string item_name, double data);
	void AddItemDataToEntry(uint64_t item_id, double data);
};

}

#endif /* CONTROL_SRC_CTRL_UTILS_LOGGING_LOGGING_HELPER_H_ */
