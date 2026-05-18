#ifndef QUERY_ENGINE_H
#define QUERY_ENGINE_H

#include <string>
#include "../models/models.h"


// 1. CÁC CHỨC NĂNG GIỮA KỲ (MIDTERM QUERIES)


/**
 * @brief Chức năng 1: Liệt kê hành trình truy xuất Device -> App -> Resource của 1 User
 * trong khoảng thời gian cho trước.
 * @param userTable Bảng băm tra cứu theo User ID
 * @param user_id Mã định danh người dùng cần tra cứu 
 * @param start_time Thời gian bắt đầu khoảng tìm kiếm (epoch time) 
 * @param end_time Thời gian kết thúc khoảng tìm kiếm (epoch time) 
 */
void printUserJourney(const HashTable& userTable, 
                      const std::string& user_id, 
                      long long start_time, 
                      long long end_time);

/**
 * @brief Chức năng 2: Liệt kê hành trình truy xuất User -> Device -> App của 1 Resource
 * trong khoảng thời gian cho trước.
 * @param resourceTable Bảng băm tra cứu theo Resource ID
 * @param resource_id Mã định danh tài nguyên cần tra cứu 
 * @param start_time Thời gian bắt đầu khoảng tìm kiếm (epoch time) 
 * @param end_time Thời gian kết thúc khoảng tìm kiếm (epoch time) 
 */
void printResourceJourney(const HashTable& resourceTable, 
                          const std::string& resource_id, 
                          long long start_time, 
                          long long end_time);

/**
 * @brief Chức năng 3: Thống kê top 10 tài nguyên được truy xuất nhiều nhất trong khoảng thời gian.
 * @param resourceTable Bảng băm chứa tất cả tài nguyên
 * @param start_time Thời gian bắt đầu khoảng thống kê (epoch time) 
 * @param end_time Thời gian kết thúc khoảng thống kê (epoch time) 
 */
void printTop10Resources(const HashTable& resourceTable, 
                         long long start_time, 
                         long long end_time);



// 2.FINAL TERM - ANOMALY DETECTION


/*
// Phát hiện bất thường dựa trên ngưỡng [cite: 48]
void detectSpamLogin(const HashTable& userTable, int max_devices, long long time_window); // [cite: 49]
void detectBruteForce(const HashTable& userTable, int max_failed_attempts); // [cite: 50]
void detectDeviceSpamResource(const HashTable& deviceTable, int max_resources); // [cite: 51]
void detectOutsideWorkingHours(const LinkedList& rawLogList); // [cite: 52]

// Phát hiện bất thường dựa trên hành vi & phiên làm việc [cite: 53, 56]
void detectImpossibleTravel(const HashTable& userTable); // [cite: 54, 55]
void detectSuspiciousAdminActions(const HashTable& userTable); // [cite: 60, 61]
*/

#endif // QUERY_ENGINE_H