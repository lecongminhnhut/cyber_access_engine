#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "../models/models.h"
#include <string>


// 1. HÀM BĂM CHUỖI (HASH FUNCTIONS)

/**
 * @brief Hàm băm chuỗi sử dụng thuật toán FNV-1a (hoặc DJB2) để phân phối đều dữ liệu.
 * @param key Chuỗi ký tự cần băm (ví dụ: user_id, resource_id)
 * @param bucket_size Kích thước hiện tại của mảng băm
 * @return Vị trí index trong mảng băm (giá trị từ 0 đến bucket_size - 1)
 */
int hashFunction(const std::string& key, int bucket_size);



// 2. CÁC HÀM QUẢN LÝ BẢNG BĂM (LIFECYCLE MANAGEMENT)

/**
 * @brief Khởi tạo bảng băm, cấp phát mảng động cho các buckets.
 * @param ht Con trỏ trỏ đến HashTable cần khởi tạo
 * @param bucket_size Số lượng bucket muốn cấp phát (Giữa kỳ: ~20,003; Cuối kỳ: ~1,000,003)
 */
void initHashTable(HashTable& ht, int bucket_size);

/**
 * @brief Giải phóng toàn bộ các Node trong danh sách liên kết của từng bucket.
 * @note Hàm này KHÔNG delete vùng nhớ `LogRecord* data` gốc để tránh giải phóng nhầm 
 * khi một log được tham chiếu ở nhiều bảng băm khác nhau.
 * @param ht Bảng băm cần giải phóng
 */
void clearHashTable(HashTable& ht);

/**
 * @brief Thu hồi hoàn toàn mảng động buckets của bảng băm.
 * @param ht Bảng băm cần thu hồi hoàn toàn
 */
void destroyHashTable(HashTable& ht);



// 3. THAO TÁC TRÊN BẢNG BĂM (OPERATIONS)

/**
 * @brief Chèn một bản ghi LogRecord vào bảng băm dựa trên một thuộc tính khóa (Key).
 * @param ht Bảng băm cần chèn
 * @param key Chuỗi dùng làm khóa để băm (ví dụ: record->user_id hoặc record->resource_id)
 * @param record Con trỏ trỏ đến bản ghi dữ liệu thô
 */
void insertToTable(HashTable& ht, const std::string& key, LogRecord* record);

/**
 * @brief Tìm kiếm danh sách các log liên quan đến một Key cho trước.
 * @param ht Bảng băm cần tìm kiếm
 * @param key Khóa cần tìm (ví dụ: "U007" hoặc "R025")
 * @return Con trỏ trỏ đến LinkedList chứa các Node kết quả, trả về nullptr nếu không tìm thấy
 */
LinkedList* searchInTable(const HashTable& ht, const std::string& key);

#endif // HASH_TABLE_H