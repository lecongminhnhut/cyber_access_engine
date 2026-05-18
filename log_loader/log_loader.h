#ifndef LOG_LOADER_H
#define LOG_LOADER_H

#include <string>
#include "../models/models.h"

// ============================================================================
// 1. CÁC HÀM BỔ TRỢ TÁCH CHUỖI (PARSING UTILITIES)
// ============================================================================
/**
 * @brief Tách một dòng log thô từ CSV thành các thuộc tính của LogRecord.
 * @param line Chuỗi thô đọc từ 1 dòng trong file CSV
 * @param record Con trỏ trỏ đến struct LogRecord cần điền dữ liệu
 * @return true nếu dòng dữ liệu hợp lệ và parse thành công, false nếu dòng lỗi/thiếu cột
 */
bool parseCSVLine(const std::string& line, LogRecord* record);


// ============================================================================
// 2. HÀM ĐỌC VÀ ĐỔ DỮ LIỆU VÀO HỆ THỐNG (CORE LOADER)
// ============================================================================
/**
 * @brief Đọc file log CSV và phân phối dữ liệu vào các cấu trúc quản lý trên bộ nhớ.
 * @param filename Đường dẫn tới file log .csv
 * @param rawLogList Danh sách liên kết lớn (hoặc mảng động) quản lý vùng nhớ gốc của toàn bộ LogRecord
 * @param userTable Bảng băm quản lý theo User ID
 * @param resourceTable Bảng băm quản lý theo Resource ID
 * @param maxLines Giới hạn số dòng đọc (Giữa kỳ: tối đa 10000; Cuối kỳ: tăng lên 1000000 hoặc hơn)
 * @return Số lượng dòng dữ liệu hợp lệ đã đọc thành công vào bộ nhớ
 */
int loadLogFile(const std::string& filename, 
                LinkedList& rawLogList, 
                HashTable& userTable, 
                HashTable& resourceTable, 
                int maxLines);

#endif // LOG_LOADER_H